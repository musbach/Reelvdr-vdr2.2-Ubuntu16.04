package XXV::MODULES::USER;

use strict;

use Tools;
use File::Path;


# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'USER',
        Prereq => {
            'Net::IP::Match::Regexp qw( create_iprange_regexp match_ip )'
                => 'Efficiently match IPv4 addresses against IPv4 ranges via regexp '
            ,'Data::COW' => 'clone deep data structures copy-on-write'
            ,'Digest::MD5 qw(md5_hex)' => 'Perl interface to the MD5 Algorithm'
        },
        Description =>
gettext("This module manages the User administration.
You may set a level for the whole module with 
the 'Level' parameter in the main module
or the same parameter is set for each function."),
        Preferences => {
            active => {
                description => gettext('Enable user authentication'),
                default     => 'y',
                type        => 'confirm',
            },
            withAuth => {
                description => gettext('IP addresses with user authentification'),
                default     => '',
                type        => 'string',
                check       => sub{
                    my $value = shift || return;
                    my @ips = split(/\s*,\s*/, $value);
                    for (@ips) {
                        return undef, sprintf(gettext('Your IP number (%s) is wrong! You need an IP in range (xxx.xxx.xxx.xxx/xx)'), $_)
                            unless ($_ =~ /\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\/\d+/);
                    }
                    return $value;
                },
            },
            noAuth => {
                description => gettext('IP addresses without user authentification'),
                default     => '',
                type        => 'string',
                check       => sub{
                    my $value = shift || return;
                    my @ips = split(/\s*,\s*/, $value);
                    for (@ips) {
                        return undef, sprintf(gettext('Your IP number (%s) is wrong! You need an IP in range (xxx.xxx.xxx.xxx/xx)'), $_)
                            unless ($_ =~ /\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\/\d+/);
                    }
                    return $value;
                },
            },
            tempimages => {
                description => gettext('common directory for temporary images'),
                default     => '/var/cache/xxv/temp',
                type        => 'dir',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            unew => {
                description => gettext('Create new user account'),
                short       => 'un',
                callback    => sub{ $self->create(@_) },
                Level       => 'admin',
            },
            udelete => {
                description => gettext("Delete user account 'uid'"),
                short       => 'ud',
                callback    => sub{ $self->delete(@_) },
                Level       => 'admin',
            },
            uedit => {
                description => gettext("Edit user account 'uid'"),
                short       => 'ue',
                callback    => sub{ $self->edit(@_) },
                Level       => 'admin',
            },
            uprefs => {
                description => gettext("Change preferences"),
                short       => 'up',
                callback    => sub{ $self->userprefs(@_) },
                Level       => 'user',
            },
            ulist => {
                description => gettext("List the accounts of users"),
                short       => 'ul',
                callback    => sub{ $self->list(@_) },
                Level       => 'admin',
            },
            login => {
                hidden      => 'yes',
                short       => 'login',
                callback    => sub{ $self->login(@_) },
            },
            logout => {
                description => gettext("Log out from current session."),
                short       => 'exit',
                callback    => sub{ $self->logout(@_) },
            },
        },
    };
    return $args;
}

# ------------------
sub new {
# ------------------
	my($class, %attr) = @_;
	my $self = {};
	bless($self, $class);

    $self->{charset} = delete $attr{'-charset'};
    if($self->{charset} eq 'UTF-8'){
      eval 'use utf8';
    }

    # paths
    $self->{paths} = delete $attr{'-paths'};

	# who am I
    $self->{MOD} = $self->module;

    # all configvalues to $self without parents (important for ConfigModule)
    map {
        $self->{$_} = $attr{'-config'}->{$self->{MOD}->{Name}}->{$_};
        $self->{$_} = $self->{MOD}->{Preferences}->{$_}->{default} unless($self->{$_});
    } keys %{$self->{MOD}->{Preferences}};

    # Try to use the Requirments
    map {
        eval "use $_";
        if($@) {
          my $m = (split(/ /, $_))[0];
          return panic("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
        }
    } keys %{$self->{MOD}->{Prereq}};

    # read the DB Handle
    $self->{dbh} = delete $attr{'-dbh'};

    # The Initprocess
    my $erg = $self->_init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub _init {
# ------------------
    my $self = shift || return error('No object defined!');

    unless($self->{dbh}) {
      panic("Session to database is'nt connected");
      return 0;
    }

    my $version = main::getDBVersion();
    # don't remove old table, if updated rows => warn only
    if(!tableUpdated($self->{dbh},'USER',$version,0)) {
        return 0;
    }

    # Look for table or create this table
    my $erg = $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS USER (
          Id int(11) unsigned auto_increment NOT NULL,
          Name varchar(100) NOT NULL default '',
          Password varchar(32) NOT NULL,
          Level set('admin', 'user', 'guest' ) NOT NULL,
          Prefs text default '',
          UserPrefs text default '',
          Deny set('tlist', 'alist', 'rlist', 'mlist', 'tedit', 'aedit', 'redit', 'remote', 'stream', 'cedit', 'media'),
          MaxLifeTime tinyint(2) default '0',
          MaxPriority tinyint(2) default '0',
          PRIMARY KEY  (Id)
        ) COMMENT = '$version'
    |);

    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS SESSION (
          id int unsigned auto_increment NOT NULL,
          sid varchar(32) NOT NULL,
          uid int unsigned NOT NULL,
          source varchar(16) NOT NULL default '',
          expires datetime NOT NULL default '0000-00-00 00:00:00',
          PRIMARY KEY (id),
          UNIQUE KEY (sid) 
        ) COMMENT = '$version'
    |);


    # The Table is empty? Make a default User ...
    unless($self->{dbh}->selectrow_arrayref('SELECT SQL_CACHE count(*) from USER')->[0]) {
        $self->_insert({
            Name => 'xxv',
            Password => 'xxv',
            Level => 'admin',
        });
    }

    # Repair later Data ...
    main::after(sub{

        # Remove old data
        $self->_deleteSession();

        # Remove expires session every one hour
        Event->timer(
            interval => 60 * 60,
            prio => 6,  # -1 very hard ... 6 very low
            cb => sub{
                lg sprintf('Remove expires session.');
                $self->_deleteSession();
            },
        );
        return 1;
    }, "USER: Remove expires session ...");
}


# ------------------
# Name:  create
# Descr: Save a new User in the Usertable.
# Usage: my $ok = $self->create($console, 0, {name => 'user', ...});
# ------------------
sub create {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || 0;
    my $data    = shift || 0;

    $self->edit($console, $config, $id, $data);

}

# ------------------
sub userprefs {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift;
    my $data    = shift || 0;


    unless($console->{USER}->{Id}) {
      return $console->err(gettext("This account has'nt own preferences!"));
    }

    $id = $console->{USER}->{Id} unless($id);
    if($id ne $console->{USER}->{Id}) {
      return $console->err(gettext("You are not authorized for change external account preferences!"));
    }
    my $user;
    if($id and not ref $data) {
        my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from USER where Id = ?');
        $sth->execute($id)
            or return $console->err(sprintf(gettext("User account '%s' does not exist in the database!"),$id));
        $user = $sth->fetchrow_hashref();
    }

    my $questions = [
        'Id' => {
            typ     => 'hidden',
            def     => $user->{Id} || 0,
        },
        'Password' => {
            typ   => 'password',
            msg   => gettext("Password for this account"),
            #req   => gettext('This is required!'),
            def   => '',
            check   => sub{
                my $value = shift || return;

                return $value unless(ref $value eq 'ARRAY');

                # If no password given the
                # take the old password as default
                if($value->[0] and $value->[0] ne $value->[1]) {
                    return undef, gettext("The fields with the 1st and the 2nd password must match!");
                } else {
                    return $value->[0];
                }
            },
        },
    ];

    my $mods = main::getModules();
    my $defaultconfig = main::getModule('CONFIG')->{config};
    my $values;
    @$values = split('\n', $user->{UserPrefs}) if($user->{UserPrefs});

    foreach my $modName (sort keys %{$mods}) {
      my $prefs = $mods->{$modName}->{MOD}->{Preferences};

      my @m = split('::', $modName);
      shift(@m);#'XXV'
      shift(@m);#'MODULES'
      my $modul = join('::',@m);

      my $cfg = $defaultconfig->{$modul};

      next if(exists $mods->{$modName}->{active} and $cfg->{active} eq 'n');

      foreach my $name (sort { lc($a) cmp lc($b) } keys(%{$prefs})) {
          my $def;
          if($values) {
            foreach my $userpref (@$values) {
              my ($modname, $parameter, $value) = $userpref =~ /(\S+)::(\S+)\=(.+)/sg;
              if($modname eq $modul && $name eq $parameter) {
                $def = $value;
                last;
              }    
            }
          }
          $def = $cfg->{$name}
              if(!(defined $def) && defined $cfg->{$name} && $cfg->{$name} ne "");
          $def = $prefs->{$name}->{default} unless(defined $def);

          push(@$questions, $modul .'::'. $name,
              {
                  typ => $prefs->{$name}->{type} || 'string',
                  options => $prefs->{$name}->{options},
                  msg => sprintf("%s:\n%s", ucfirst($modul), ($prefs->{$name}->{description} || ucfirst($name) )),
                  def => $def,
                  #req => $prefs->{$name}->{required},
                  choices  => $prefs->{$name}->{choices},
                  check  => $prefs->{$name}->{check},
                  readonly  => $prefs->{$name}->{readonly} || 0,
              }
          ) if($prefs->{$name}->{level} 
                and   $self->getLevel($console->{USER}->{Level}) 
                   >= $self->getLevel($prefs->{$name}->{level}));
      }
    }
    # Ask Questions
    $data = $console->question(sprintf(gettext('Edit preferences: %s'), $console->{USER}->{Name}), $questions, $data);

    if(ref $data eq 'HASH' && $data->{Id} eq $id) {
        my $userpref;
        foreach my $item (keys(%{$data})) { 
          next unless($item =~ /::/s);
          my $value = delete $data->{$item};
          my ($modname, $parameter) = $item =~ /(\S+)::(\S+)/sg;
          my $mod = main::getModule($modname);
          unless(exists $mod->{$parameter}) {
            error sprintf(("The module '%s' does not exist!"),$mod);
            next;
          }
          unless(exists $mod->{$parameter}) {
            error sprintf(("The parameter '%s' in module '%s' does not exist!"),$parameter, $mod);
            next;
          }
          my $prefs = $mod->{MOD}->{Preferences};
          unless($prefs->{$parameter}->{level} 
                  and $self->getLevel($console->{USER}->{Level}) 
                   >= $self->getLevel($prefs->{$parameter}->{level})) {
            error sprintf(("You are not authorized for change this parameter '%s' in module '%s'!"),$parameter, $mod);
            next;
          }
          my $cfg = $defaultconfig->{$modname};
          unless($cfg->{$parameter} ne $value) {
            next;
          }

          push(@$userpref,$modname .'::'. $parameter .'='.$value);
        }
        $data->{UserPrefs} = $userpref ? join("\n", @$userpref) : undef;
        $self->_insert($data);

        $console->message(gettext('User account saved!'));
        if($console->typ eq 'HTML') {
            $console->redirect({url => '?', parent => 'top', wait => 2});
            $console->message(gettext('Please wait ... refreshing interface!'));
        }
    }
    return 1;
}


# ------------------
# Name:  edit
# Descr: Edit an existing User in the Usertable.
# Usage: my $ok = $self->edit($console, $id, [$data]);
# ------------------
sub edit {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || 0;
    my $data    = shift || 0;

    my $user;
    if($id and not ref $data) {
        my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from USER where Id = ?');
        $sth->execute($id)
            or return $console->err(sprintf(gettext("User account '%s' does not exist in the database!"),$id));
        $user = $sth->fetchrow_hashref();

        # question erwartet ein Array
        my @deny = split(/\s*,\s*/, $user->{Deny});
        $user->{Deny} = \@deny;
    }

    my %l = (
        'admin' => gettext('Administrator'),
        'user' => gettext('User'),
        'guest' => gettext('Guest')
    );

    my $questions = [
        'Id' => {
            typ     => 'hidden',
            def     => $user->{Id} || 0,
        },
        'Name' => {
            msg   => gettext("Name of user account"),
            req   => gettext('This is required!'),
            def   => $user->{Name} || '',
        },
        'Password' => {
            typ   => 'password',
            msg   => gettext("Password for this account"),
            req   => gettext('This is required!'),
            def   => '',
            check   => sub{
                my $value = shift || return;

                return $value unless(ref $value eq 'ARRAY');

                # If no password given the
                # take the old password as default
                if($value->[0] and $value->[0] ne $value->[1]) {
                    return undef, gettext("The fields with the 1st and the 2nd password must match!");
                } else {
                    return $value->[0];
                }
            },
        },
        'Level' => {
            def     => sub {
                            my $value = $user->{Level} || 'guest';
                            return $l{$value};
                          },
            msg     => gettext("Level for this account"),
            typ     => 'radio',
            req     => gettext('This is required!'),
            choices => [$l{'admin'},$l{'user'},$l{'guest'}],
            check   => sub{
                my $value = shift || return;
                my $data = shift || return error('No Data in CB');
                unless(grep($_ eq $value, @{$data->{choices}})) {
                     my $ch = join(' ', @{$data->{choices}});
                     return undef, sprintf(gettext("You can choose: %s!"),$ch);
                }
                foreach my $k (keys %l) {
                    return $k
                        if($value eq $l{$k});
                }
                my $ch = join(' ', @{$data->{choices}});
                return undef, sprintf(gettext("You can choose: %s!"),$ch);
            },
        },
        'Deny' => {
            msg   => gettext('Deny class of commands'),
            typ   => 'checkbox',
            choices   => ['tlist', 'alist', 'rlist', 'mlist', 'tedit', 'aedit', 'redit', 'remote', 'stream', 'cedit', 'media'],
            def   => $user->{Deny} || '',
            check   => sub{
                my $value = shift || '';
                my $data = shift || return error('No Data in CB');
                my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);

                foreach my $v (@vals) {
                    unless(grep($_ eq $v, @{$data->{choices}})) {
                        my $ch = join(' ', @{$data->{choices}});
                        return undef, sprintf(gettext("You can choose: %s!"),$ch);
                    }
                }
                return join(',', @vals);
            },
        },
        'UserPrefs' => {
            def     => sub {
                            my $value = $user->{UserPrefs};
                            return gettext('None own settings') unless($value);
                            my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\n/, $value);
                            return join(',', @vals);
                          },
            msg     => gettext("Preferences selected by user own settings"),
            typ     => 'string',
            readonly => '1',
        },
        'Prefs' => {
            def     => sub {
                            my $value = $user->{Prefs};
                            return '' unless($value);
                            my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\n/, $value);
                            return join(',', @vals);
                          },
            msg     => gettext("Overwrite preferences for this user: ModName::Param=value, "),
            typ     => 'string',
            check   => sub{
                my $value = shift || return;
                my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);

                foreach my $pref (@vals) {
                    my ($modname, $parameter, $value) = $pref =~ /(\S+)::(\S+)\=(.+)/sg;
                    if(my $mod = main::getModule($modname)) {
                        unless(exists $mod->{$parameter}) {
                            return undef, sprintf(gettext("The parameter '%s' in module '%s' does not exist!"),$parameter, $mod);
                        }
                    }
                }
                return join("\n", @vals);
            },
        },
        'MaxLifeTime' => {
            msg   => gettext("Maximum permitted value for lifetime with timers"),
            def   => $user->{MaxLifeTime} || '0',
            type  => 'integer',
            check   => sub{
                my $value = shift || return 0;
                unless(int($value) and int($value) > 0 and int($value) < 100) {
                    return undef, gettext("This value is not an integer or not between 0 and 100");
                }
                return $value;
            },
        },
        'MaxPriority' => {
            msg   => gettext("Maximum permitted value for priority with timers"),
            def   => $user->{MaxPriority} || '0',
            type  => 'integer',
            check   => sub{
                my $value = shift || return 0;
                unless(int($value) and int($value) > 0 and int($value) < 100) {
                    return undef, gettext("This value is not an integer or not between 0 and 100");
                }
                return $value;
            },
        },
    ];

    # Ask Questions
    $data = $console->question(($id ? gettext('Edit user account')
				    : gettext('Create new user account')), $questions, $data);

    if(ref $data eq 'HASH') {
        delete $data->{UserPrefs};
        $self->_insert($data);

        debug sprintf('%s account with name "%s" is saved%s',
            ($id ? 'Changed' : 'New'),
            $data->{Name},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $console->message(gettext('User account saved!'));
        $console->redirect({url => '?cmd=ulist', wait => 1})
            if($console->typ eq 'HTML');
    }
    return 1;
}

# ------------------
# Name:  delete
# Descr: Delete an existing User in the Usertable with Id.
# Usage: my $ok = $self->delete($console, $id);
# ------------------
sub delete {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || return $console->err(gettext("No user account defined for deletion! Please use udelete 'uid'."));

    my $sth = $self->{dbh}->prepare('delete from USER where Id = ?');
    $sth->execute($id)
        or return $console->err(sprintf(gettext("User account '%s' does not exist in the database!"),$id));
    $console->message(sprintf gettext("User account %s deleted."), $id);

    debug sprintf('Delete user account "%s"%s',
        $id,
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    $console->redirect({url => '?cmd=ulist', wait => 1})
        if($console->typ eq 'HTML');

}


# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my %f = (
        'Id' => gettext('Service'),
        'Name' => gettext('Name'),
        'Level' => gettext('Level'),
        'Prefs' => gettext('Preferences'),
        'UserPrefs' => gettext('User preferences')
    );

    my $sql = qq|
SELECT SQL_CACHE 
  Id as \'$f{Id}\', 
  Name as \'$f{Name}\', 
  Level as \'$f{Level}\', 
  Prefs as \'$f{Prefs}\', 
  UserPrefs as \'$f{UserPrefs}\' 
from 
  USER
    |;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    my %l = (
        'admin' => gettext('Administrator'),
        'user' => gettext('User'),
        'guest' => gettext('Guest')
    );

    map { 
      $_->[2] = $l{$_->[2]} || $_->[2];
    } @$erg;

    unshift(@$erg, $fields)
      unless($console->typ eq 'AJAX');

    $console->table($erg);
}

# ------------------
# Name:  login
# Descr: login an existing User
# Usage: my $ok = $self->login($console, $id, [$data]);
# ------------------
sub login {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || 0;
    my $data    = shift || 0;
    
    $console->setCall('nothing');
    if(exists $console->{USER}->{Level}) {
      $console->err(gettext('You are already authorized to use this system!'));
      return;
    } else {
      my $questions = [
          'name' => {
              msg   => gettext("Name of user account"),
              req   => gettext('This is required!'),
              def   => '',
          },
          'password' => {
              typ   => 'password',
              msg   => gettext("Password for this account"),
              req   => gettext('This is required!'),
              def   => ''
          }
      ];

      # Ask Questions
      $data = $console->question(gettext('Authorization required'), $questions, $data);
    }
    if(ref $data eq 'HASH') {
        debug sprintf('Account with name "%s" try login',
            $data->{name}
        );

        my $ip = getip($console->{handle});
        my $user = $self->_checkUser($data->{name}, $data->{password}, $ip);
        
        unless($user) {
          if($console->typ eq 'HTML') {
            $console->statusmsg(403,gettext('You are not authorized to use this system!')
                                ,gettext("Forbidden"));
          } else {
            $console->err(gettext('You are not authorized to use this system!'));
          }
          return;
        }

        if(my $level = $self->getLevel($user->{Level})) {
            $user->{value} = $level if($level);
        }

        $console->{USER} = $user;
        if($console->typ eq 'HTML') {
          my $start = $user->{config}->{'HTTPD'}->{StartPage};
          $console->statusmsg(301,$start ? sprintf('?cmd=%s',$start):'?cmd=n');
        } else {
          $console->message(gettext('Welcome to xxv!'));
        }
    }
    return 1;
}
# ------------------
# Name:  logout
# Descr: The routine for logout the user, this will clean the user temp files.
# Usage: my $ok = $self->logout();
# ------------------
sub logout {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    if($self->{active} eq 'y') {
        $console->{USER}->{sid} = '';

        $console->message(gettext("Session closed."));
        $console->redirect({url => '?', parent => 'top', wait => 2})
            if($console->typ eq 'HTML');

        my $ConsoleMod;
        my $delayed = 0;
        if($console->typ eq 'HTML' || $console->typ eq 'AJAX') {
          $ConsoleMod = main::getModule('HTTPD');
          $delayed = 1;
        } elsif ($console->typ eq 'WML') {
          $ConsoleMod = main::getModule('WAPD');
          $delayed = 1;
        } elsif ($console->typ eq 'CONSOLE') {
          $ConsoleMod = main::getModule('TELNET');
        };

        if($delayed) {
          # Close session delayed, give browser my time load depends files like style.css
          Event->timer(
              after => 1,
              prio => 6,  # -1 very hard ... 6 very low
              cb => sub{
                  $self->_logout($console,$config);
                  $ConsoleMod->{LOGOUT} = 1 if($ConsoleMod);
              },
          );
        } else  {
          $self->_logout($console,$config);
          $ConsoleMod->{LOGOUT} = 1 if($ConsoleMod);
        }
    }
}

sub _logout {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    lg sprintf('Logout called%s',
        $console->{USER}->{Name} ? sprintf(" by user %s", $console->{USER}->{Name}) : "" 
        );

    $self->_closeSession($console->{USER}->{Id});

    main::toCleanUp($console->{USER}->{Name});
    return 1;
}

# ------------------
sub _checkIp {
# ------------------
    my $self = shift || return error('No object defined!');
    my $ip = shift || return;

    if($self->{withAuth}) {
        my $regexp = create_iprange_regexp(split(/\s*,\s*/, $self->{withAuth}));
        if (match_ip($ip, $regexp)) {
           return 0;
        }
    }

    if($self->{noAuth}) {
        my $regexp = create_iprange_regexp(split(/\s*,\s*/, $self->{noAuth}));
        if (match_ip($ip, $regexp)) {
           return 1;
        }
    }
    return 0;
}

# ------------------
# Name:  check
# Descr: The loginroutine to check the User Name, Password
#        or the ClientIPAdress.
#        This will return a Userhash with the DB-Entrys.
# Usage: my $userHash = $self->check($handle);
# ------------------
sub check {
    my $self = shift || return error('No object defined!');
    my $handle = shift || return;
    my $sid = shift;

    my $ip = getip($handle);

    my $user;
    if($self->{active} ne 'y' 
        or $self->_checkIp($ip)) {
        $user->{Name} = 'su'; # we are Superuser
        $user->{Level} = 'admin';
        #$user->{MaxLifeTime} = 0; #0 - disabled
        #$user->{MaxPriority} = 0; #0 - disabled
        $user->{config} = main::getModule('CONFIG')->{config};
    } else {
        if(defined $sid) {
          $user = $self->_checkSession($sid,$ip);
        }
        unless($user) {
          my $name = shift || return;
          my $password = shift || return;
          
          $user = $self->_checkUser($name, $password, $ip);
        }
    }

    return undef 
      unless($user);

    if(my $level = $self->getLevel($user->{Level})) {
        $user->{value} = $level if($level);
    }

    return $user;
}

sub _checkUser {
    my $self = shift || return error('No object defined!');
    my $name = shift;
    my $password = shift;
    my $ip = shift;

    my $user;
    # check User
    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE USER.Id as Id,Name,Level,Prefs,UserPrefs,Deny,MaxLifeTime,MaxPriority from USER where Name = ? and Password = md5( ? )');
    $sth->execute($name, $password)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    $user = $sth->fetchrow_hashref();

    return undef 
      unless($user);

    $user->{sid} = $self->_createSession($user->{Id},$ip);

    $user->{config} = make_cow_ref(main::getModule('CONFIG')->{config});

    # Set the user settings from user
    $self->applySettings($user->{UserPrefs}, $user->{config})
      if($user->{UserPrefs});

    # Set the user settings from admin
    $self->applySettings($user->{Prefs}, $user->{config})
      if($user->{Prefs});

    return $user;
}

# Create new session 
sub _createSession {
    my $self = shift || return error('No object defined!');
    my $uid = shift;
    my $ip = shift;

    #Close all session with same uid
    #$self->_closeSession($uid);

    for(my $c = 3; $c >= 1; $c--) {
      my $random =  int( rand(4294967296) ); 
      my $sessionID = md5_hex( $ip . $random . time());
      my $sth = $self->{dbh}->prepare('INSERT INTO SESSION VALUES (0,?,?,?,TIMESTAMPADD(HOUR,4,NOW()))');
      if($sth->execute( $sessionID, $uid, $ip )) {
        return $sessionID;
      }
    }
    return undef;
}

# Update timestamp of expires sessions
sub _updateSession {
    my $self = shift || return error('No object defined!');
    my $sid = shift;

    my $sth = $self->{dbh}->prepare('UPDATE SESSION SET expires=TIMESTAMPADD(HOUR,4,NOW()) where sid=(?)');
    $sth->execute( $sid );
}

# Delete expires sessions
sub _deleteSession {
    my $self = shift || return error('No object defined!');

    my $sth = $self->{dbh}->prepare('DELETE FROM SESSION where expires < NOW()');
    $sth->execute( );
}

# Close all session with same uid
sub _closeSession {
    my $self = shift || return error('No object defined!');
    my $uid = shift;

    my $sth = $self->{dbh}->prepare('DELETE FROM SESSION where uid = (?)');
    $sth->execute($uid);
}

# Check exits session by sid and ip
sub _checkSession {
    my $self = shift || return error('No object defined!');
    my $sid = shift;
    my $ip = shift;

    chomp($sid);
  	$sid =~ s/(\r|\n)//g;

    my $user;
    # check User
    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE USER.Id as Id,Name,Level,Prefs,UserPrefs,Deny,MaxLifeTime,MaxPriority,sid from USER,SESSION where USER.Id = SESSION.uid and SESSION.sid = ( ? ) and SESSION.source = ( ? ) and SESSION.expires > NOW()');
    $sth->execute($sid, $ip)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    $user = $sth->fetchrow_hashref();

    return undef 
      unless($user);

    $self->_updateSession($user->{sid});

    $user->{config} = make_cow_ref(main::getModule('CONFIG')->{config});

    # Set the user settings from user
    $self->applySettings($user->{UserPrefs}, $user->{config})
      if($user->{UserPrefs});

    # Set the user settings from admin
    $self->applySettings($user->{Prefs}, $user->{config})
      if($user->{Prefs});

    return $user;
}
# ------------------
sub applySettings {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $newprefs = shift || return error ('No settings defined!');
    my $config = shift || return error ('No config defined!');

    foreach my $pref (split(/\n/, $newprefs)) {
        my ($modname, $parameter, $value) = $pref =~ /(\S+)::(\S+)\=(.*)/sg;
        if($modname and my $mod = main::getModule($modname) and my $cfg = main::getModule('CONFIG')->{config}) {
            if(exists $mod->{$parameter}) {
                $config->{$modname}->{$parameter} = $value;
            } else {
                error("The Parameter '$parameter' in Module '$mod' is doesn't exist!");
            }
        }
    }
}

# ------------------
sub allowCommand {

# ------------------
    my $self = shift || return error('No object defined!');
    my $modCfg = shift || return error('No modul defined!');
    my $cmdName = shift || return error('No command name defined!');
    my $user = shift || return error('No user defined!');
    my $DontdumpViolation = shift || '';

    if(
        (exists $modCfg->{Level} and $user->{value} < $self->getLevel($modCfg->{Level}))
        or
        (exists $modCfg->{Commands}->{$cmdName}->{Level} and $user->{value} < $self->getLevel($modCfg->{Commands}->{$cmdName}->{Level}))
        or
        ($user->{Deny} and exists $modCfg->{Commands}->{$cmdName}->{DenyClass} and $user->{Deny} =~ /$modCfg->{Commands}->{$cmdName}->{DenyClass}/)
    ) {
        error(sprintf('User %s with Level %s has try to call command %s without permissions!',
            $user->{Name}, $user->{Level}, $cmdName))
		if($DontdumpViolation eq '');
        return 0;
    }
    return 1;
}

# ------------------
# Name:  checkCommand
# Descr: A routine to check the commands, translate the shortcuts.
#        This will return the cmdobj and cmdname if this command ok.
#        $shorterr is set in following Errorcases:
#           'noactive'  = Plugin is not set active
#           'noperm'    = Permission denied for the called User
#           'noexists'  = Command does not exist!
#        $error is the full Errortext to diaply im Userinterface.
# Usage: my ($cmdobj, $cmdname, $shorterr, $error) = $self->checkCommand($console, $command);
# Test:
sub t_checkCommand {
    my ($cmdobj, $cmdname, $shorterr, $error, $t)
        = $_[0]->checkCommand($_[1], 'tl');
    $t = 1 if(ref $cmdobj and $cmdname eq 'tlist');
    ($cmdobj, $cmdname, $shorterr, $error)
        = $_[0]->checkCommand($_[1], 'lalalalal');
    $t = 1 if(not ref $cmdobj and not $cmdname and $shorterr and $error);
    return $t;
}
# ------------------
sub checkCommand {
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $ucmd = shift || return error('No command defined!');
    my $DontdumpViolation = shift || '';

    my $mods = main::getModules();
    my $err = 0;
    my $shorterr = 0;
    my $cmdobj = 0;
    my $cmdname = 0;
    my $cmdModule;
    my $ok = 0;

    # Checks the Commands Syntax (double shortcmds?)
    $self->checkCmdSyntax()
        unless(defined $self->{Check});

    foreach my $modName (keys %{$mods}) {
        my $modCfg = $mods->{$modName}->{MOD};
        foreach my $cmdName (sort keys %{$modCfg->{Commands}}) {
            if(lc($ucmd) eq $cmdName or (exists $modCfg->{Commands}->{$cmdName}->{short} 
					 			and lc($ucmd) eq $modCfg->{Commands}->{$cmdName}->{short})) {
                $ok++;
                $cmdobj = $modCfg->{Commands}->{$cmdName};
                $cmdname = $cmdName;
                $cmdModule = $modCfg->{Name};
                # Check on active Modul
                if(exists $mods->{$modName}->{active} 
                    and exists $console->{USER}->{config}->{$modCfg->{Name}}->{active}
                    and $console->{USER}->{config}->{$modCfg->{Name}}->{active} eq 'n') {
                    $err = sprintf(gettext("Sorry, but the module %s is inactive! Enable it with %s:Preferences:active = y"),
                        $cmdModule, $cmdModule);
                    $shorterr = 'noactive';
                }

                if($self->{active} eq 'y') {
                    # Check Userlevel and Permissions
                    unless($self->allowCommand($modCfg, $cmdName, $console->{USER},$DontdumpViolation)) {
                        $err = gettext('You are not authorized for this function!');
                        $shorterr = 'noperm';
                    }
                }
            }
        }
    }
    unless($ok) {
        $err = sprintf(gettext("Sorry, couldn't understand command '%s'!\n"), $ucmd);
        $shorterr = 'noexists';
    }

    if($shorterr) {
        return (undef, 'nothing', undef, $shorterr, $err)
    } else {
        return ($cmdobj, $cmdname, $cmdModule, undef, undef)
    }
}

# ------------------
# Name:  checkCmdSyntax
# Descr: Check the Syntax of Commands and for double Names in different Modules
# Usage: my $ok = $self->checkCmdSyntax(tlist);
# Test:
sub t_checkCmdSyntax {
    return $_[0]->checkCmdSyntax('tlist');
}
# ------------------
sub checkCmdSyntax {
    my $self     = shift || return error('No object defined!');
    my $mods    = main::getModules();

    my $shorts = {};
    foreach my $modName (keys %{$mods}) {
        my $modCfg = $mods->{$modName}->{MOD};
        foreach my $cmdName (sort keys %{$modCfg->{Commands}}) {
            my $short = $modCfg->{Commands}->{$cmdName}->{short} || $cmdName;
            if(exists $shorts->{$short} ) {
                return error sprintf("[ERROR] In %s::%s double short name %s, also in %s!",
                    $modName, $cmdName, $short, $shorts->{$short});
            } else {
                $shorts->{$short} = $modName.'::'.$cmdName;
            }
        }
    }
    $self->{Check} = 1;
    1;
}

# ------------------
# Name:  getLevel
# Descr: Translate the Levelname to an numeric level
# Usage: my $score = $self->getLevel(levelname);
# Test:
sub t_getLevel {
    return $_[0]->getLevel('user') == 5;
}
# ------------------
sub getLevel {
    my $self = shift || return error('No object defined!');
    my $name = shift || return;

    # Level Table
    $self->{LEV} = {
        admin   => 10,
        user    => 5,
        guest   => 1,
    } unless(exists $self->{LEV});

    if($self->{LEV}->{$name}) {
        return $self->{LEV}->{$name};
    } else {
        return error("Name of level '$name' does not exist!");
    }

}

# ------------------
sub _insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return;

    if(ref $data eq 'HASH') {
        my ($names, $vals, $kenn);
        map {

            if($_ eq 'Password') {
                if($data->{Password}) {
                    push(@$names, $_);
                    push(@$vals, $data->{$_});
                    push(@$kenn, 'MD5(?)');
                }
            } else {
                push(@$names, $_);
                push(@$vals, $data->{$_});
                push(@$kenn, '?');
            }

        } sort keys %$data;

        my $sql;
        if($data->{Id}) {
            my $temp = [];
            my $c = 0;
            foreach (@$names) {
                push(@$temp, sprintf("%s=%s", $names->[$c], $kenn->[$c]));
                $c++;
            }
            $sql = sprintf("UPDATE USER SET %s WHERE Id = %lu",
                    join(', ', @$temp),
                    $data->{Id},
            );
        } else {
            $sql = sprintf("REPLACE INTO USER (%s) VALUES (%s)",
                    join(', ', @$names),
                    join(', ', @$kenn),
            );
        }
        my $sth = $self->{dbh}->prepare( $sql );
        $sth->execute( @$vals );
    } else {
        my $sth = $self->{dbh}->prepare('REPLACE INTO USER VALUES (?,?,?,?)');
        $sth->execute( @$data );
    }
}

# ------------------
# Name:  userTmp
# Descr: Return a temp directory only for logged user and delete this by exit xxv.
# Usage: my $tmpdir = $self->userTmp([username]);
# ------------------
sub userTmp {
    my $self = shift  || return error('No object defined!');
    my $user = shift  || return error('No username defined!');

    # /var/cache/xxv/temp/user/$PID
    my $dir = $self->createTmpDir($user, $$);

    if($dir) {
      # Nach Logout oder beenden von xxv das temp löschen
      main::toCleanUp($user, sub{ deleteDir($dir) }, 'logout')
          unless(main::toCleanUp($user, undef, 'exists')); # ein CB registrieren
    }

    return $dir;
}


sub createTmpDir {
    my $self = shift  || return error('No object defined!');
    my $dir = shift  || return error('No user defined!');
    my $pid  = shift;

    my $path;
    if($pid) {
      # /var/cache/xxv/temp/dir/$PID
      $path = sprintf('%s/%s/%d', $self->{tempimages} , $dir, $pid);
    } else {
      # /var/cache/xxv/temp/dir
      $path = sprintf('%s/%s', $self->{tempimages} , $dir);
    }

    unless(-d $path) {
        unless(mkpath($path)) {
          error "Couldn't mkpath $path : $!";
          return undef;
        }
    }

    return $path;
}
1;

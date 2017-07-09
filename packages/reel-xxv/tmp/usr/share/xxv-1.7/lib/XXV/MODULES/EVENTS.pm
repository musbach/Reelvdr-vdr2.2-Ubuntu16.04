package XXV::MODULES::EVENTS;
use strict;

use Tools;


# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'EVENTS',
        Prereq => {
           'Date::Manip'  => 'date manipulation routines',
        },
        Description => gettext(
"This module manage the events for control and watch the xxv system.
An additional Loghandler is installed and parse every Message. If
a defined Event exists and match the keywords defined in
Module->RegEvent->SearchForEvent then call the Loghandler 'callEvent'.
This sub look in Module->RegEvent->Actions, and call this Routines.
"),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            host => {
                description => gettext('Used host of referred link inside reports.'),
                default     => main::getModule('STATUS')->name,
                type        => 'host',
            },
        },
        Commands => {
            request => {
                description => gettext("Display the actual news site 'typ'"),
                short       => 'req',
                callback    => sub{ $self->request(@_) },
                binary      => 'nocache'
            },
            elist => {
                description => gettext('Display the event list'),
                short       => 'el',
                callback    => sub{ $self->list(@_) },
                Level       => 'user',
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

    # the big Config
    $self->{CONFIG} = $attr{'-config'};

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


    my $version = 30; # Must be increment if rows of table changed
    # this tables hasen't handmade user data,
    # therefore old table could dropped if updated rows
    if(!tableUpdated($self->{dbh},'EVENTS',$version,1)) {
        return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS EVENTS (
          id int unsigned auto_increment NOT NULL,
          title text default '',
          message text default '',
          cmd text default '',
          data text default '',
          level int unsigned,
          addtime timestamp,
          PRIMARY KEY(id)
        ) COMMENT = '$version'
    |);

    # Load the NEWS Plugins ...
    my @mods = glob($self->{paths}->{NEWSMODS}.'/*.pm');

    # Try to use the news plugins
    foreach my $module (reverse @mods) {
        my $moduleName = 'XXV::OUTPUT::NEWS::'.(split('\.',(split('/', $module))[-1]))[0];
        # make an object for the module
	      eval "use $moduleName";
        if($@) {
          panic("Couldn't load news module: $moduleName");
          next;
        }

        my $mod = $moduleName->new(
            -config  => $self->{CONFIG},
            -dbh     => $self->{dbh},
            -paths   => $self->{paths},
            -host    => $self->{host},
            -charset => $self->{charset}
        );

        unless($mod) {
            error sprintf('Load news module %s failed!',$moduleName);
            next;
        }

        $self->{NEWSMODS}->{$moduleName} = $mod;

        main::addModule($moduleName, $self->{NEWSMODS}->{$moduleName});

        debug sprintf("Load news module %s %s\n",
            $moduleName,
            (ref $self->{NEWSMODS}->{$moduleName})
                ? "successful."
                : 'failed!');
    }

    main::after(sub{
        $self->{EVENTS} = $self->searchForEvents();
        # This will add a callback for log events (ignore verbose)
        $Tools::LOGCALLB = sub{
            $self->callEvent(@_);
        };

        $self->news(
            sprintf(gettext('XXVD System %s started'), main::getVersion),
            sprintf(gettext('Start time: %s'), datum()),
            undef,
            undef,
            'harmless'
        );

        return 1;
    }, "EVENTS: Look for event entrys in modules ...", 2);

    return 1;
}

# ------------------
sub searchForEvents {
# ------------------
    my $self = shift || return error('No object defined!');

    my $mods = main::getModules();
    my $events = {};
    foreach my $modname (keys %$mods) {
        if(exists $mods->{$modname}->{MOD}->{RegEvent}
            and my $re = $mods->{$modname}->{MOD}->{RegEvent}
        ) {
            foreach my $rname (keys %$re) {
                my $options = $re->{$rname};
                $options->{Grp} = (split(/::/, $modname))[-1];
                $events->{$rname} = $options;
            }
        }
    }
    return $events;
}

# ------------------
sub callEvent {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        'Mod' => shift,
        'Sub' => shift,
        'Msg' => shift,
    };
    return unless(exists $self->{EVENTS});
    return if($self->{active} ne 'y');

    foreach my $id (keys %{$self->{EVENTS}}) {
        my $entry = $self->{EVENTS}->{$id};
        my $bool = 0;

        # Search for right fields
        next unless(exists $entry->{SearchForEvent});
        for my $sType (keys %{$entry->{SearchForEvent}}) {
            my $sValue = $entry->{SearchForEvent}->{$sType};
            $bool++ if(index($args->{$sType}, $sValue) > -1);
        }
        next unless($bool >= scalar keys %{$entry->{SearchForEvent}});

        # Search for Matchtext
        my $MatchVar = {};
        if(exists $entry->{Match}) {
            $bool = 0;
            for my $mName (keys %{$entry->{Match}}) {
                my $mRegex = $entry->{Match}->{$mName};
                $MatchVar->{$mName} = $1
                    if($args->{Msg} =~ $mRegex);
                $bool = 1 if($MatchVar->{$mName});
            }
            next unless($bool);
        }

        # Call the Actions
        if(exists $entry->{Actions}) {
            for my $action (@{$entry->{Actions}}) {
                my $callback;
                my $code = sprintf('$callback = %s;', $action);
                eval($code);
                if($@) {
                    error($@);
                    next;
                }
                my $erg = &$callback($MatchVar, $entry)
                    if(ref $callback eq 'CODE');
            }
        }
    }

    return 1;
}

# ------------------
sub news {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $title = shift || return error('No title defined!');
    my $text  = shift || '';
    my $cmd   = shift || '';
    my $id    = shift || '';
    my $levname  = shift || 'harmless'; # Level for how important is this news?

    # convert Levelname to integer
    my $lev   = $self->scala($levname)
        || return error('Problem to analyze level!');

    my $hmod = main::getModule('HTTPD') or return;

    my  $url = sprintf("http://%s:%s/", $self->{host}, $hmod->{Port});
        $url = sprintf("%s?cmd=%s&data=%s", $url, $cmd, $id)
            if($cmd && $id);

    my $news = {
        AddDate => time,
        Title   => $title,
        Text    => $text,
        Cmd     => $cmd,
        Id      => $id,
        Url     => $url,
        Level   => $lev,
        LevelName => $levname,
        category => $self->translate_scala($lev)
    };
    
   #my $days =  7 * 24 * 60 * 60;
   $self->{dbh}->do("DELETE FROM EVENTS WHERE (addtime + INTERVAL 31 DAY) < NOW()"); 
   $self->_insert($news);

    # Send to all activated News modules
    foreach my $modName (sort keys %{$self->{NEWSMODS}}) {

        # Active?
        next if($self->{NEWSMODS}->{$modName}->{active} ne 'y');

        # Level correct?
        next if(exists $self->{NEWSMODS}->{$modName}->{level}
                and $self->{NEWSMODS}->{$modName}->{level} >= $lev);

        # Do to send (first push and maybe send)
        $self->{NEWSMODS}->{$modName}->push($news);
    }

}

sub _insert {
    my $self = shift  || return error('No object defined!');
    my $news = shift  || return error('No object defined!');

    my $sth = $self->{dbh}->prepare(
q|
  REPLACE INTO EVENTS 
    (title, message, cmd, data, level, addtime ) 
  VALUES (?, ?, ?, ?, ?, NOW())
|
);
    $sth->execute( 
         $news->{Title},
         $news->{Text},
         $news->{Cmd},
         $news->{Id},
         $news->{Level}
     ) or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
     return 1;
}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || 1;

    my %f = (
        'addtime' => gettext('Time'),
        'title' => gettext('Title'),
        'message' => gettext('Message')
    );

    my $sql = qq|
SELECT SQL_CACHE
  addtime as \'$f{addtime}\',
  title as \'$f{title}\',
  message as \'$f{message}\',
  '' as __url,
  level as __level,
  '' as __levelName,
  cmd as __cmd,
  data as __data
from
  EVENTS
where level >= ? 
order by
  addtime desc
LIMIT 0,50
    |;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($data)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();
    map { 
        $_->[3] = sprintf("?cmd=%s&data=%s", $_->[6], $_->[7])
            if($_->[6] && $_->[7]);

        $_->[5] = $self->translate_scala($_->[4]);
    } @$erg;
    unshift(@$erg, $fields);

    $console->table($erg);
}
   
# ------------------
sub request {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    # To this time you can set on
    # cmd=request&data=rss&ver=2 or
    # cmd=request&data=mail&__test=1
    # ...
    my $typ = shift || return $console->err(gettext("Sorry, but none type requested!"));
    my $params = shift || {};

    my ($mod) = grep(/${typ}$/i, keys %{$self->{NEWSMODS}});

    return $console->err(sprintf(gettext("Sorry, but this type '%s' does not exist on this system!"), $typ))
        unless($mod);
    my $module = $self->{NEWSMODS}->{$mod};

    return $console->err(gettext("Sorry, but this module is not active!"))
        if($module->{active} ne 'y');

    return $console->out(
        $module->req($params),
        $module->{TYP}
    );
}


# ------------------
sub scala {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $typ = shift  || return 10;

    $self->{SCALA} = {
      'all'             => 1,
      'harmless'        => 10,
      'interesting'     => 30,
      'veryinteresting' => 50,
      'important'       => 70,
      'veryimportant'   => 100,
      'none'            => 200, 
    } unless(exists $self->{SCALA});

    if($typ and exists $self->{SCALA}->{$typ}) {
        return $self->{SCALA}->{$typ};
    } else {
        return error sprintf("Level %s does not exist! Please use %s", $typ, join(',', keys %{$self->{SCALA}}));
    }
}

# ------------------
sub get_level_as_array {
# ------------------
    my $self = shift || return error('No object defined!');

    return [
            [ 1, gettext('All messages') ],        # Include all messages, dont use as category
            [ 10, gettext('Harmless') ],
            [ 30, gettext('Interesting') ],
            [ 50, gettext('Very interesting') ],
            [ 70, gettext('Important') ],
            [ 100, gettext('Very important') ],
            [ 200, gettext('None messages') ]      # Exclude all messages, dont use as category
          ];
}

sub translate_level {
    my $self = shift  || return error('No object defined!');
    my $level = shift  || 'harmless';

    my $s = $self->scala($level);
    return $self->translate_scala($s);
}    

sub translate_scala {
    my $self = shift  || return error('No object defined!');
    my $scala = shift  || 10;

    my $erg = $self->get_level_as_array();
    foreach my $w ( @$erg ) {
        return $w->[1] if($scala <= $w->[0]);
    }
    return gettext('Harmless');
}
1;

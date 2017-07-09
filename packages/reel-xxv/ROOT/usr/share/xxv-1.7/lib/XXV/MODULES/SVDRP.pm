package XXV::MODULES::SVDRP;

use Tools;
use strict;
use Encode;

$|++;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'SVDRP',
        Prereq => {
            'IO::Socket::INET'  => 'Object interface for AF_INET domain sockets ',
        },
        Description => gettext('This module module manages connection to video disk recorder.'),
        Status => sub{ $self->status(@_) },
        Preferences => {
            timeout => {
                description => gettext('Connection timeout defines after how many seconds an unrequited connection is terminated.'),
                default     => 60,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            vdrlist => {
                description => gettext("List defined video disk recorder."),
                short       => 'vl',
                callback    => sub{ $self->list(@_) },
                Level       => 'admin',
            },
            vdrnew => {
                description => gettext('Create new video disk recorder definition.'),
                short       => 'vn',
                callback    => sub{ $self->create(@_) },
                Level       => 'admin',
            },
            vdrdelete => {
                description => gettext("Delete video disk recorder definition 'id'"),
                short       => 'vd',
                callback    => sub{ $self->delete(@_) },
                Level       => 'admin',
            },
            vdredit => {
                description => gettext("Edit video disk recorder definition 'id'"),
                short       => 've',
                callback    => sub{ $self->edit(@_) },
                Level       => 'admin',
            },
            sstatus => {
                description => gettext('Status from video disk recorder.'),
                short       => 'ss',
                callback    => sub{ $self->state(@_) },
                Level       => 'user',
                DenyClass   => 'remote',
            },
            scommand => {
                description => gettext('Send a command to video disk recorder.'),
                short       => 'sc',
                callback    => sub{ $self->scommand(@_) },
                Level       => 'admin',
                DenyClass   => 'remote',
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

    # initialize modul
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
    if(!tableUpdated($self->{dbh},'RECORDER',$version,0)) {
        return 0;
    }

    # read default port from /etc/services
    $self->{defaultport} = getservbyname('svdrp', 'tcp');
    $self->{defaultport} = 2001 unless($self->{defaultport});

    # Look for table or create this table
    my $erg = $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS RECORDER (
          id int unsigned auto_increment NOT NULL,
          active enum('y', 'n') default 'y',
          master enum('y', 'n') default 'n',
          host varchar(100) NOT NULL default 'localhost',
          port smallint unsigned default $self->{defaultport},
          cards varchar(100) default '',
          videodirectory text default '',
          PRIMARY KEY (id)
        ) COMMENT = '$version'
    |);

    # The Table is empty? Make a default host ...
    my $first = $self->{dbh}->selectrow_arrayref('SELECT SQL_CACHE count(*) from RECORDER');
    unless($first && $first->[0]) {
        $self->_insert({
            active => 'y',
            master => 'y',
            host => 'localhost',
            port => $self->{defaultport},
            cards => '',
            videodirectory => '/media/reel/recordings'
        });
    }

    $self->{updated} = [];

    main::after(sub{
        my $wait = 3;
        while($wait >= 0 && ! $self->state(undef, undef, undef)) {
          debug(sprintf("Wait for primary connection (%d)", $wait));
          sleep(10);
          $wait --;
        }
        return 1;
    }, "SVDRP: check primary connection ...", 1);

    return 1;
}

# function to register callback for notify state of recorder
# ------------------
sub updated {
# ------------------
    my $self = shift || return error('No object defined!');
    my $param = shift;
    my $state = shift;

    if($param && ref $param eq 'CODE') {
        push(@{$self->{updated}}, [$param]);
    } else {
        foreach my $CB (@{$self->{updated}}) {
            next unless(ref $CB eq 'ARRAY');
            &{$CB->[0]}($param,$state)
                if(ref $CB->[0] eq 'CODE');
        }
    }
}

# ------------------
sub _insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return;

    my $sth = $self->{dbh}->prepare('REPLACE INTO RECORDER VALUES (?,?,?,?,?,?,?)');
    $sth->execute( 
         $data->{id} || 0,
         $data->{active},
         $data->{master},
         $data->{host},
         $data->{port},
         $data->{cards},
         $data->{videodirectory}
     ) or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
}

sub create {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || 0;
    my $data    = shift || 0;

    $self->edit($console, $config, $id, $data);
}

sub edit {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || 0;
    my $data    = shift || 0;

    my $default;
    if($id) {
        my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from RECORDER where id = ?');
        $sth->execute($id)
            or return $console->err(sprintf(gettext("Definition of video disk recorder '%s' does not exist in the database!"),$id));
        $default = $sth->fetchrow_hashref();
    }

    my $questions = [
        'id' => {
            typ     => 'hidden',
            def     => $default->{id} || 0,
        },
        'active' => {
            typ     => 'confirm',
            def     => $default->{active} || 'y',
            msg     => gettext('Activate this definition'),
        },
        'host' => {
            typ     => 'host',
            msg   => gettext("Host or IP address of video disk recorder"),
            req   => gettext('This is required!'),
            def   => $default->{host} || '',
        },
        'port' => {
            typ     => 'integer',
            msg   => gettext("Used Port of SVDRP"),
            req   => gettext('This is required!'),
            def   => $default->{port} || $self->{defaultport},
            check   => sub{
                my $value = int(shift);
                if($value > 0 && $value < 65536) {
                    return $value;
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'master' => {
            typ     => 'confirm',
            def     => $default->{master} || 'n',
            msg     => gettext('Use as primary video disk recorder'),
        },
        'cards' => {
            msg   => gettext("List of present source of DVB cards. (eg. S19.2E,S19.2E,T,T )"),
            def   => $default->{cards} || main::getModule('CHANNELS')->buildSourceList($id || $self->primary_hosts()),
        },
        'videodirectory' => {
            msg   => gettext("Directory where recordings are stored"),
            def   => $default->{videodirectory},
            req   => gettext('This is required!'),
            typ     => 'dir',
        },

    ];

    # Ask Questions
    $data = $console->question(($id ? gettext('Edit video disk recorder definition')
				    : gettext('Create new video disk recorder definition')), $questions, $data);

    if(ref $data eq 'HASH') {

        $data->{'videodirectory'} =~ s/\/$//;

        if($data->{'master'} eq 'y') {
          $self->{dbh}->do("UPDATE RECORDER SET master='n' WHERE master = 'y'");
        }
        $self->_insert($data);

        $self->_deletevdrdata($data->{'id'})  if($data->{'active'} ne 'y');

        delete $self->{Cache};

        # Update depends moduls
        $self->updated($data->{'id'},$data->{'active'}) 
            if(!$default || $default->{'active'} ne $data->{'active'});

        debug sprintf('%s video disk recorder definition "%s" is saved%s',
            ($id ? 'Changed' : 'New'),
            $data->{host},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $console->message(gettext('Video disk recorder definition saved!'));
        $console->redirect({url => '?cmd=vdrlist', wait => 1})
            if($console->typ eq 'HTML');
    }
    return 1;
}

sub delete {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my $id = shift || return $console->err(gettext("No definition of video disk recorder for deletion! Please use sdelete 'id'."));

    my $sth = $self->{dbh}->prepare('delete from RECORDER where id = ?');
    $sth->execute($id)
        or return $console->err(sprintf(gettext("Definition of video disk recorder '%s' does not exist in the database!"),$id));

    # Remove recorder from depends moduls
    $self->updated($id,'n'); 

    $self->_deletevdrdata($id);

    delete $self->{Cache};

    $console->message(sprintf gettext("Definition of video disk recorder are %s deleted."), $id);

    debug sprintf('Delete definition of video disk recorder "%s"%s',
        $id,
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    $console->redirect({url => '?cmd=vdrlist', wait => 1})
        if($console->typ eq 'HTML');
}

sub _deletevdrdata {
    my $self = shift || return error('No object defined!');
    my $id = shift;
    
    foreach my $table (qw/EPG OLDEPG TIMERS CHANNELS CHANNELGROUPS/) {
      my $sth = $self->{dbh}->prepare("delete from $table where vid = ?");
      $sth->execute($id)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    }
}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my %f = (
        'id' => gettext('Service'),
        'active' => gettext('Active'),
        'master' => gettext('Primary'),
        'host' => gettext('Host'),
        'cards' => gettext('Typ of Cards'),
        'videodirectory'  => gettext('Video directory')
    );

    my $sql = qq|
SELECT SQL_CACHE
  id as \'$f{id}\',
  active as \'$f{active}\',
  master as \'$f{master}\',
  host as \'$f{host}\',
  cards as \'$f{cards}\',
  videodirectory as \'$f{videodirectory}\'
from 
  RECORDER
    |;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    unshift(@$erg, $fields) 
      unless($console->typ eq 'AJAX');

    $console->table($erg);
}


sub _gethost {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    unless(exists $self->{Cache}) {
      my $sth = $self->{dbh}->prepare("SELECT * from RECORDER where active = 'y'");
      $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $self->{Cache} = $sth->fetchall_hashref('id');
    }

    unless($self->{Cache} && defined $self->{Cache}) {
      panic ("Couldn't query any defined video disk recorder.");
      return undef;
    }

    if($vdrid) {
      unless(defined $self->{Cache}->{$vdrid}) {
        error sprintf("Definition of video disk recorder with id '%s' does not exist in the database.", $vdrid);
        return undef;
      }
      return $self->{Cache}->{$vdrid};
    } else {
      foreach my $id (keys %{$self->{Cache}}) {
        my $h = $self->{Cache}->{$id};
        next unless($h->{master} eq 'y');
        return $h;
      }
    }
    my ($k, $v) = each %{$self->{Cache}};
    debug sprintf("None primary video disk recorder defined in the database, use %s",$v->{host});
    return $v;
}

sub primary_hosts {
    my $self = shift  || return error('No object defined!');
  
    unless($self->{Cache}) {
      return undef unless($self->_gethost());
    }

    foreach my $id (keys %{$self->{Cache}}) {
      my $h = $self->{Cache}->{$id};
      next unless($h->{master} eq 'y');
      return $id;
    }

    my ($k, $v) = each %{$self->{Cache}};
    return $k;
}

sub list_hosts {
    my $self = shift  || return error('No object defined!');
  
    unless($self->{Cache}) {
      return undef unless($self->_gethost());
    }

    my $hosts;
    foreach my $id (keys %{$self->{Cache}}) {
      push(@$hosts,$id);
    }

    return $hosts;
}

sub hostname {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;
  
    my $vdr = $self->_gethost($vdrid);
    return $vdr ? $vdr->{host} : undef;
}

sub cards {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;
  
    my $vdr = $self->_gethost($vdrid);
    return $vdr ? $vdr->{cards} : undef;
}

sub is_host_online {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    if($self->{Cache} 
			&& $self->{Cache}->{$vdrid}
			&& $self->{Cache}->{$vdrid}->{online}) { 
    	return $self->{Cache}->{$vdrid}->{online};
		}
  	return 'no';
}

sub vdr_version {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    if($self->{Cache} 
			&& $self->{Cache}->{$vdrid}
			&& $self->{Cache}->{$vdrid}->{version}) { 
    	return $self->{Cache}->{$vdrid}->{version};
		}
  	return 'unknown';
}

sub enum_onlinehosts {
    my $self = shift  || return error('No object defined!');
  
    unless($self->{Cache}) {
      return undef unless($self->_gethost());
      # check online state
      foreach my $vid (keys %{$self->{Cache}}) {
        $self->command('CHAN',$vid);
      }
    }

    my $hosts;
    foreach my $id (keys %{$self->{Cache}}) {

      next unless($self->{Cache}->{$id}->{online}   
                  && $self->{Cache}->{$id}->{online} eq 'yes');

      push(@$hosts,[$self->{Cache}->{$id}->{host},$id]);
    }

    return $hosts;
}

sub enum_hosts {
    my $self = shift  || return error('No object defined!');

    my $sth = $self->{dbh}->prepare("SELECT SQL_CACHE host,id FROM RECORDER");
    $sth->execute()
      or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return $sth->fetchall_arrayref();
}

sub list_unique_recording_hosts() {
    my $self = shift  || return error('No object defined!');
  
    my $sth = $self->{dbh}->prepare("SELECT SQL_CACHE id from RECORDER where active = 'y' GROUP BY videodirectory");
       $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $result = $sth->fetchall_hashref('id');
    return undef unless($result);

    my $hosts;
    foreach my $id (keys %{$result}) {
      push(@$hosts,$id);
    }

    return $hosts;
}

sub videodirectory {
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    my $sql = qq|
SELECT SQL_CACHE videodirectory FROM RECORDER WHERE id = ? 
|;
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($vdrid)
        or return error(sprintf("Video disk recorder '%s' does not exist in the database!",$vdrid));
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{videodirectory} : undef;
}

# ------------------
sub IDfromHostname {
# ------------------
    my $self = shift || return error('No object defined!');
    my $host = shift  || return error('No host defined!');

    my $sql = qq|
SELECT SQL_CACHE id FROM RECORDER WHERE host = ? 
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($host)
        or return error(sprintf("Video disk recorder '%s' does not exist in the database!",$host));
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{id} : undef;
}

# ------------------
sub queue_add {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $cmd = shift;
    my $vdrid = shift;

    return error('No command defined!') unless($cmd);

    push(@{$self->{Queue}->{$vdrid || 'master'}}, $cmd);
}

# ------------------
sub queue_count {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    my $count = 0;
    foreach my $id (keys %{$self->{Queue}}) {
      next if($vdrid && $id ne $vdrid);
      $count += scalar @{$self->{Queue}->{$id}};
    }
    return $count;
}

# ------------------
sub queue_flush {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vdrid = shift;

    my ($erg,$result,$err,$error);
    my $queue = delete $self->{Queue};
    $self->{Queue} = undef;
    foreach my $id (keys %$queue) {
      if($id eq 'master') {
        ($erg,$err) = $self->command($queue->{'master'},undef);
      } else {
        ($erg,$err) = $self->command($queue->{$id},$id);
      }
      if($erg) {
        if($result) {
          @$result = (@$result, @$erg);
        } else {
          $result = $erg;
        }
      }
      if($err) {
        if($error) {
          @$error = (@$error, @$err);
        } else {
          $error = $err;
        }
      }
    }
    return ($result,$error);
}

# ------------------
sub command {
# ------------------
    my $self = shift || return error('No object defined!');
    my $cmd = shift;
    my $vdrid = shift;

    my $error;
    my $vdr = $self->_gethost($vdrid);
    unless($vdr && defined $vdr->{host} && defined $vdr->{port}) {
      $error = gettext("None video disk recorder defined in the database.");
      return (undef, $error);
    }
    $vdrid = $vdr->{id};

    my $data;
    my $line;
    my $commands;
    push(@$commands, (ref $cmd eq 'ARRAY' ? @$cmd : $cmd));

    unless(scalar @$commands > 0) {
      $error = 'No commands defined!';
      error ($error);
      return (undef, $error);
    }
    push(@$commands, "quit");

    # Open connection
    my $so = IO::Socket::INET->new(PeerAddr => $vdr->{host}, PeerPort => $vdr->{port} , Proto => 'tcp' );
    if(!(defined $so)){
      $error = sprintf("Couldn't connect to svdrp-socket %s:%s! %s",$vdr->{host},$vdr->{port}, $!);
      $self->{Cache}->{$vdrid}->{online} = 'no';
      error($error);
      return (undef, $error);
    }
    eval {
      local $SIG{ALRM} = sub { die "Timeout expired\n"};
      alarm $self->{timeout};
      my $encoding = $self->{charset};
      #binmode $so, ":encoding(utf8)" if($self->{charset} eq 'UTF-8');
      $so->autoflush;

      # read first line 
      do {
        $line = $so->getline;
        $line =~ s/\r?\n// if($line);
        if($line) {
          push(@$data, $line);
        }
      } while($line && $line =~ /^\d\d\d\-/);

      unless($data && scalar @$data){
        $error = sprintf("Couldn't read data from svdrp-socket %s:%s! %s",$vdr->{host},$vdr->{port}, $!);
        $self->{Cache}->{$vdrid}->{online} = 'no';
        $so->close();
        alarm 0;
        error($error);
        return (undef, $error);
      }
      
      # parse header like 220 video SVDRP VideoDiskRecorder 1.7.1; Fri May 2 16:17:10 2008; ISO-8859-1
      my @header = split (/\;/, $data->[0]);

      # Store version 1.2.6 => 10206, 1.3.32 => 10332
      $self->{Cache}->{$vdrid}->{version} = int(sprintf("%02d%02d%02d",split(/\./,$1)))
        if($header[0] =~ /SVDRP\s+VideoDiskRecorder\s+(\d\.\d\.\d+)/);

      if(scalar @header > 2) {
        if($header[2] =~ /\s+ISO\-(.*)/) {
          $encoding = 'iso-' . $1;
        } elsif($header[2] =~ /\s+UTF\-(.*)/) {
          $encoding = 'utf' . $1;
        }
      }
      #my $enc = find_encoding($encoding);

      # send commando queue
      foreach my $command (@$commands) {
          $command =~ s/\r//g;
          $command =~ s/\n$//;
          #if($encoding ne $self->{charset}) {
          #  $command = $enc->encode($command);
          #}

          # send command
          if(!($so->print($command . "\n"))) {
            $error = sprintf("Couldn't send command '%s' to %s:%s! %s",$command,$vdr->{host},$vdr->{port}, $!);
            $self->{Cache}->{$vdrid}->{online} = 'no';
            $so->close();
            alarm 0;
            error($error);
            return (undef, $error);
          }

          # read response
          do {
            $line = $so->getline;
            $line =~ s/\r?\n// if($line);

            if($line) {
              #if($encoding ne $self->{charset}) {
              # $line = $enc->decode($line);
              #}

              if($line =~ /^(\d{3})\s+(.+)/ && (int($1) >= 500)) {
                my $msg = sprintf(gettext("Error at command '%s' to %s:%s! %s"), $command,$vdr->{host},$vdr->{port}, $2);
                error($msg);
                $error .= $msg . "\n";
              }
              #if( $self->{charset} eq 'UTF-8') {
              #  utf8::upgrade($line) if(!utf8::is_utf8($line));
              #}
              push(@$data, $line);
            }
          } while($line && $line =~ /^\d\d\d\-/);
      }
      alarm 0;
    };
    if ($@) {
      $error = $@;
      $self->{Cache}->{$vdrid}->{online} = 'no';
      error($error);
      return (undef, $error);
    }
    # close socket
    $so->close();

    $self->{Cache}->{$vdrid}->{online} = 'yes';

    foreach my $command (@$commands) {
      my @lines = (split(/[\r\n]/, $command));
      event(sprintf('Call command "%s" on %s %s.', $lines[0], $vdr->{host}, $error ? " failed" : "successful")) 
        if($command ne "quit");
    }
    return (\@$data, $error);
}

# ------------------
sub state {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
    my $vdrid = shift;

    my ($erg,$error) = $self->command('CHAN', $vdrid);
    $console->msg($erg, $error)
        if(ref $console);
    return 1 
      unless($error);
    return 0;
}

# ------------------
sub scommand {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text = shift || return $console->err(gettext("No command defined! Please use scommand 'cmd'."));
    my $vdrid = shift;

    my ($erg,$error) = $self->command($text,$vdrid);

    return 0
      if(!($erg) || $error);

    $console->msg($erg, $error);
  
    return 1 
      unless($error);
    return 0;
}

# ------------------
sub status {
# ------------------
    my $self = shift || return error('No object defined!');
    my $lastReportTime = shift;

    my %f = (
        'host' => gettext('Recorder'),
        'state' => gettext('State')
    );

    my $sql = qq|
SELECT SQL_CACHE
  id as __id,
  host as \'$f{host}\',
  active as \'$f{state}\'
from RECORDER WHERE active = 'y'|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    map { 
        if(defined $self->{Cache}->{$_->[0]} 
            && defined $self->{Cache}->{$_->[0]}->{online}) {
          if($self->{Cache}->{$_->[0]}->{online} eq 'yes') {
            $_->[2] = gettext("Online");
          } else {
            $_->[2] = gettext("Offline");
          }
        } else {
            $_->[2] = gettext("Unknown");
        }
    } @$erg;

    unshift(@$erg, $fields);
    return {
        message => sprintf(gettext('%d active recorder'),
                             (scalar @$erg -1)),
        table   => $erg,
    };
}


1;

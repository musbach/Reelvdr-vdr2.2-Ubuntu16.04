package XXV::MODULES::TIMERS;

use strict;
use Tools;
use POSIX ":sys_wait_h", qw(strftime mktime);

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'TIMERS',
        Prereq => {
            'Date::Manip' => 'date manipulation routines',
            'Digest::MD5 qw(md5_hex)' => 'Perl interface to the MD5 Algorithm'
        },
        Description => gettext('This module reads timers and saves it to the database.'),
        Status => sub{ $self->status(@_) },
        Preferences => {
            interval => {
                description => gettext('How often timers are to be updated (in seconds)'),
                default     => 30 * 60,
                type        => 'integer',
                required    => gettext("This is required!"),
                check       => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value > 60) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
            },
            prevminutes => {
                description => gettext('Buffer time in minutes before the scheduled start of a recording'),
                default     => 5,
                type        => 'integer',
                check       => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 0 and $value <= 1440) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
                level       => 'guest'
            },
            afterminutes => {
                description => gettext('Buffer time in minutes past the scheduled end of a recording'),
                default     => 5,
                type        => 'integer',
                check       => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 0 and $value <= 1440) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
                level       => 'guest'
            },
            Priority => {
                description => gettext('Priority of a timer for recordings when creating a new timer'),
                default     => 50,
                type        => 'integer',
                check       => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 0 and $value < 100) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
            },
            Lifetime => {
                description => gettext('The guaranteed lifetime (in days) of a recording created by this timer'),
                default     => 50,
                type        => 'integer',
                check   => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 0 and $value < 100) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
            },
            usevpstime => {
                description => gettext('Use Programme Delivery Control (PDC) to control start time'),
                default     => 'n',
                type        => 'confirm',
                level       => 'guest'
            },
            adjust => {
                description => gettext('Change timers if EPG entries change'),
                default     => 'y',
                type        => 'confirm',
            },
        },
        Commands => {
            tlist => {
                description => gettext("List timers 'tid'"),
                short       => 'tl',
                callback    => sub{ $self->list(@_) },
                DenyClass   => 'tlist',
            },
            tsearch => {
                description => gettext("Search timers 'text'"),
                short       => 'ts',
                callback    => sub{ $self->search(@_) },
                DenyClass   => 'tlist',
            },
            tupdate => {
                description => gettext("Read timers and write them to the database"),
                short       => 'tu',
                callback    => sub{ $self->readData(@_)},
                Level       => 'user',
                DenyClass   => 'tedit',
            },
            tnew => {
                description => gettext("Create timer 'eid'"),
                short       => 'tn',
                callback    => sub{ $self->newTimer(@_) },
                Level       => 'user',
                DenyClass   => 'tedit',
            },
            tedit => {
                description => gettext("Edit timer 'tid'"),
                short       => 'te',
                callback    => sub{ $self->editTimer(@_) },
                Level       => 'user',
                DenyClass   => 'tedit',
            },
            tdelete => {
                description => gettext("Delete timer 'tid'"),
                short       => 'td',
                callback    => sub{ $self->deleteTimer(@_) },
                Level       => 'user',
                DenyClass   => 'tedit',
            },
            ttoggle => {
                description => gettext("Activate/Deactive timer 'tid'"),
                short       => 'tt',
                callback    => sub{ $self->toggleTimer(@_) },
                Level       => 'user',
                DenyClass   => 'tedit',
            },
            tsuggest => {
                hidden      => 'yes',
                callback    => sub{ $self->suggest(@_) },
                DenyClass   => 'tlist',
            },
        },
        RegEvent    => {
           # Create event entries if the user has created a new timer
           'newTimerfromUser' => {
                # You have this choices (harmless is default):
                # 'harmless', 'interesting', 'veryinteresting', 'important', 'veryimportant'
                Level => 'veryinteresting',

                # Search for a spezial Event.
                # I.e.: Search for an LogEvent with match
                # "Sub=>text" = subroutine =~ /text/
                # "Msg=>text" = logmessage =~ /text/
                # "Mod=>text" = modname =~ /text/
                SearchForEvent => {
                    Msg => 'New timer',
                },
                # Search for a Match and extract the information
                # of the id
                # ...
                Match => {
                    pos => qr/New timer\s+(\d+)/s,
                    host => qr/New timer\s+\d+\s+on\s+(\S+)/s,
                },
                Actions => [
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;
                            return if($timer->{autotimerid});
                            my $title = sprintf(gettext("New timer: %s"),$timer->{file});
                            $modT->_news($title, $timer, $event->{Level});
                        }
                    |,
                ],

            },
            # Create event entries if the user has deleted a timer
            'deleteTimer' => {
                Level => 'interesting',
                SearchForEvent => {
                    Msg => 'delt',
                },
                Match => {
                    pos => qr/delt\s+(\d+)\"\s+on\s+\S+/s,
                    host => qr/delt\s+\d+\"\s+on\s+(\S+)/s,
                },
                Actions => [
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;
                            my $title = sprintf(gettext("Timer deleted: %s"),$timer->{file});
                            $modT->_news($title, $timer, $event->{Level});
                        }
                    |,
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;
                            my $modS = main::getModule('SHARE') or return;
                            $modS->sharetimer($timer);
                        }|,
                ],
            },
            # Create event entries if the user has toggled a timer.
            'toggleTimer' => {
                Level => 'interesting',
                SearchForEvent => {
                    Msg => 'modt',
                },
                Match => {
                    pos     => qr/modt\s+(\d+)\s(on|off)/s,
                    enabled => qr/modt\s+\d+\s+(on|off)/s,
                    host    => qr/modt\s+\d+\s+\S+\s+on\s+(\S+)/s,
                },
                Actions => [
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;
                            my $title;
                            if($args->{enabled} eq 'on') {
                              $title = sprintf(gettext("Timer activated: %s"),$timer->{file});
                            } else {
                              $title = sprintf(gettext("Timer deactivated: %s"),$timer->{file});
                            }
                            $modT->_news($title, $timer, $event->{Level});
                        }
                    |,
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;
                            my $modS = main::getModule('SHARE') or return;
                            $modS->sharetimer($timer);
                        }|,
                ],
            },
        },
    };
    return $args;
}

# ------------------
sub status {
# ------------------
    my $self = shift || return error('No object defined!');
    my $lastReportTime = shift || 0;

    my $total = 0;
    my $running = 0;
    {
        my $sth = $self->{dbh}->prepare("SELECT SQL_CACHE count(*) as count
                                         ,sum(NOW() between starttime and stoptime) as running 
                                         from TIMERS WHERE (flags & 1)");
        if(!$sth->execute())
        {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
        } else {
            my $erg = $sth->fetchrow_hashref();
            $total = $erg->{count} if($erg && $erg->{count});
            $running = $erg->{running} if($erg && $erg->{running});
        }
    }

    return {
        message => sprintf(gettext('%d active timer exists.'), $total)
        ,complete => $total
        ,running => $running
    };
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

    my $version = 30; # Must be increment if rows of table changed
    # this tables hasen't handmade user data,
    # therefore old table could dropped if updated rows
    if(!tableUpdated($self->{dbh},'TIMERS',$version,1)) {
        return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS TIMERS (
          id varchar(32) NOT NULL,
          vid int unsigned NOT NULL,
          pos int unsigned NOT NULL,
          flags char(1) default 1,
          channel varchar(100) NOT NULL default '',
          day varchar(20) default '-------',
          start int unsigned,
          stop int unsigned,
          priority tinyint(2),
          lifetime tinyint(2),
          file text,
          aux text default '',
          starttime datetime,
          stoptime datetime,
          collision varchar(100) default '0',
          eventid int unsigned default '0',
          eventstarttime datetime,
          eventduration int unsigned default '0',
          autotimerid int unsigned default '0',
          checked char(1) default 0,
          addtime timestamp,
          PRIMARY KEY(id)
        ) COMMENT = '$version'
    |);

    $self->{after_updated} = [];

    main::after(sub{
        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           panic ("Couldn't get modul SVDRP");
           return 0;
        }
        $self->{keywords} = main::getModule('KEYWORDS');
        unless($self->{keywords}) {
           return 0;
        }

        # import data
        $self->_readData();

        # Interval to read timers and put to DB
        Event->timer(
          interval => $self->{interval},
          prio => 6,  # -1 very hard ... 6 very low
          cb => sub{
            $self->_readData();
          }
        );
        return 1;
    }, "TIMERS: Store timers in database ...", 10);


    return 1;
}

# ------------------
sub saveTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $store = shift || 0;

    $self->_saveTimer($data);
    if($self->{svdrp}->queue_count()) {
      my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos

      if(!(exists $data->{vid})) {
          $data->{vid} = $self->{svdrp}->primary_hosts();
      }
      # Save shortly this timer in DB if this only a new timer (at)
      # Very Important for Autotimer!
      my $pos = $1 if($erg->[1] =~ /^250\s+(\d+)/);
      if($store  || !(exists $data->{pos}) and $pos) {
          $data->{pos} = $pos;
          $self->_insert($data);
      }

      event sprintf('Save timer %d on %s - %s', 
            $pos || 0, 
            $self->{svdrp}->hostname($data->{vid}),
            $data->{file});

      $self->{changedTimer} = 1;

      return ($erg,$error);
  }
  return (undef,undef);
}

# ------------------
sub _saveTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    $data->{flags}  = ($data->{active} eq 'y' ? 1 : 0);
    $data->{flags} |= ($data->{vps} eq 'y' ? 4 : 0);

    $data->{file} =~ s/(\r|\n)//sg;

    # Add Keywords to timer
    $data->{aux} = $self->{keywords}->mergexml($data->{aux},'keywords',$data->{keywords});

    my $file = $data->{file};
    $file =~ s/:/|/g;

    $self->{svdrp}->queue_add(
        sprintf("%s %s:%s:%s:%s:%s:%s:%s:%s:%s",
            $data->{pos} ? "modt $data->{pos}" : "newt",
            $data->{flags},
            $data->{channel},
            $data->{day},
            $data->{start},
            $data->{stop},
            int($data->{priority}),
            int($data->{lifetime}),
            $file,
            ($data->{aux} || '')
        ),
        $data->{vid}
    );
}

sub _newTimerdefaults {
    my $self     = shift || return error('No object defined!');
    my $config   = shift || return error('No config defined!');
    my $timer    = shift;

    $timer->{active} = 'y';
    $timer->{vps} = 'n';
    $timer->{priority} = $config->{Priority};
    $timer->{lifetime} = $config->{Lifetime};

    if($timer->{vpsstart} && $config->{usevpstime} eq 'y') { # VPS/PDC Time present and enabled by user
      my $vpstime = $self->getNextTime( $timer->{vpsday}, $timer->{vpsstart}, $timer->{vpsstop} );
      if($vpstime && $vpstime->{start} > time) { # use pdc only if data valid and if'nt event already running
        $timer->{vps} = 'y';
        $timer->{day} = $timer->{vpsday};
        $timer->{start} = $timer->{vpsstart};
        $timer->{stop} = $timer->{vpsstop};
      }
    }
}
# ------------------
sub newTimer {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $epgid   = shift || 0;
    my $epg     = shift || 0;

    my $fast = (ref $epg and exists $epg->{fast}) ? 1 : 0;
    if($epgid and ( (not ref $epg) || $fast) ) {
      my @events  = reverse sort{ $a <=> $b } split(/[^0-9]/, $epgid);
      my $sql = qq|
SELECT SQL_CACHE 
    eventid,
    channel_id as channel,
    description,
    CONCAT_WS('~', title, subtitle) as file,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(starttime) - ? ), '%Y-%m-%d') as day,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(starttime) - ? ), '%H%i') as start,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(starttime) + duration + ? ), '%H%i') as stop,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(vpstime)), '%Y-%m-%d') as vpsday,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(vpstime)), '%H%i') as vpsstart,
    DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(vpstime) + duration), '%H%i') as vpsstop
FROM
    EPG
WHERE|;
    $sql .= sprintf(" eventid in (%s)", join(',' => ('?') x @events));

      my $data;
      my $sth = $self->{dbh}->prepare($sql);
      if(!$sth->execute($config->{prevminutes} * 60, $config->{prevminutes} * 60, $config->{afterminutes} * 60, @events)
        || !($data = $sth->fetchall_hashref('eventid'))
        || (scalar keys %{$data} < 1)) {
          return $console->err(sprintf(gettext("Event '%s' does not exist in the database!"),join(',',@events)));
      }

      my $count = 1;
      foreach my $eventid (keys %{$data}) {
        $epg = $data->{$eventid};
        $self->_newTimerdefaults($config, $epg);
        $epg->{action} = 'save' if(scalar keys %{$data} > 1 || $fast );
        $self->_editTimer($console, $config, 0, $epg) if($count < scalar keys %{$data});
        $count += 1;
      }
    }
    if(not ref $epg) {
		  my $t = time;
 	    $epg = {
            channel   => '',
            file      => gettext('New timer'),
            day       => my_strftime("%Y-%m-%d",$t),
            start     => my_strftime("%H%M",$t),
            stop      => my_strftime("%H%M",$t + 3600)
    	};
      $self->_newTimerdefaults($config, $epg);
    }
    $self->editTimer($console, $config, 0, $epg);
}

# ------------------
sub _editTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || 0;   # If timerid the edittimer
    my $data    = shift || 0;  # Data for defaults

    my $default;
    if($timerid) {
        my $sth = $self->{dbh}->prepare(
qq|
SELECT SQL_CACHE 
    id, 
    vid, 
    channel, 
    file, 
    aux, 
    start, 
    stop, 
    day, 
    priority, 
    lifetime, 
    IF(flags & 1,'y','n') as active,
    IF(flags & 4,'y','n') as vps,
    NOW() between starttime and stoptime AND (flags & 1) as running,
    (SELECT description
      FROM EPG as e
      WHERE t.eventid = e.eventid
      LIMIT 1) as description
FROM
    TIMERS as t
WHERE
    id = ?
|);

      if(!$sth->execute($timerid)
        || !($default = $sth->fetchrow_hashref())
        || (scalar keys %{$default} < 1)) {
          return $console->err(sprintf(gettext("Timer '%s' does not exist in the database!"),$timerid));
      }

      if(not ref $data
          && defined $default->{aux} 
          && $self->{keywords}->{active} eq 'y') {
        $default->{aux} =~ s/(\r|\n)//sig;

        my $xml = $self->{keywords}->parsexml($default->{aux});
#       $default->{keywords} = $xml->{'autotimer'}
#         if($xml && defined $xml->{'autotimer'} );
        $default->{keywords} = $xml->{'keywords'}
          if($xml && defined $xml->{'keywords'} );
      }
    } 
    if (ref $data eq 'HASH') {
        $data->{id}  = $default->{id} || 0;
        $data->{aux} = $default->{aux} || '';
        $data->{running} = $default->{running} || 0;
        $default = $data;
    }

    my $modC = main::getModule('CHANNELS');
    my $con = $console->typ eq "CONSOLE";
    my $vlist = $self->{svdrp}->enum_onlinehosts();

    my $questions = [
        'active' => {
            typ     => 'confirm',
            def     => $default->{active},
            msg     => gettext('Enable this timer'),
        },
        'vps' => {
            typ     => 'confirm',
            def     => $default->{vps},
            msg     => gettext('Use PDC time to control timer'),
        },
        'file' => {
            msg     => gettext('Title of recording'),
            def     => $default->{file},
            req     => gettext("This is required!"),
        },
        'vid' => {
            typ     => scalar @$vlist > 1 ? 'list' : 'hidden',
            def     => $default->{vid} || $self->{svdrp}->primary_hosts(),
            choices => $vlist,
            msg     => gettext('Which video disk recorder should record'),
        },
        'channel' => {
            typ     => 'list',
            def     => $con ? $modC->ChannelToPos($default->{channel}) : $default->{channel},
            choices => $con ? $modC->ChannelArray('name') : $modC->ChannelWithGroup('c.name,c.id'),
            msg     => gettext('Which channel should recorded'),
            req     => gettext("This is required!"),
            check   => sub{
                my $value = shift;
                return undef, gettext("This is required!")
                  unless($value);

                my $ch = $modC->ToCID($value,$data->{vid});
                return undef, sprintf(gettext("Channel '%s' does not exist on video disk recorder %s!"),$value, $self->{svdrp}->hostname($data->{vid}))
                  unless($ch);
                return $ch;                
            },
        },
        'day' => {
            typ     => $con ? 'string' : 'date',
            def     => sub{
                # Convert day from VDR format to locale format
                my $value = $default->{day};
                if($value and $value =~ /^\d{4}\-\d{2}-\d{2}$/) {
                  Date_Init("Language=English");
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,gettext("%Y-%m-%d"));
                    return $t if($t);
                  }
                }
                return $value;
            },
            msg     => gettext("Enter a day or weekday in format 'MTWTFSS'."),
            req     => gettext("This is required!"),
            check   => sub{
                my $value = shift || return;
                # Convert locale format to VDR format %Y-%m-%d
                if($value and $value !~ /^\d+$/ and $value =~ /^\d+/) {
                  Date_Init(split(',',gettext("Language=English")));
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,'%Y-%m-%d');
                    return $t if($t);
                  }
                }
                if(($value =~ /^\d+$/ and int($value) <= 31 and int($value) > 0)# 13
                        or $value =~ /^\d{4}\-\d{2}-\d{2}$/sig                  # 2005-03-13
                        or $value =~ /^\S{7}\@\d{4}\-\d{2}-\d{2}$/sig           # MTWTFSS@2005-03-13
                        or $value =~ /^\S{7}\@\d{2}$/sig                        # MTWTFSS@13
                        or $value =~ /^\S{7}$/) {                               # MTWTFSS
                    return $value;
                } else {
                    return undef, gettext('The day is incorrect or was in a wrong format!');
                }
            },
        },
        'start' => {
            typ     => $con ? 'string' : 'time',
            def     => sub{
                    return fmttime($default->{start});
                },
            msg     => gettext("Start time in format 'HH:MM'"),
            check   => sub{
                my $value = shift;
                $value = fmttime($value) if($value =~ /^\d+$/sig);
                return undef, gettext('The time is incorrect!') if($value !~ /^\d+:\d+$/sig);
                my @v = split(':', $value);
                $value = sprintf('%02d%02d',$v[0],$v[1]);
                if(int($value) < 2400 and int($value) >= 0) {
                    return sprintf('%04d',$value);
                } else {
                    return undef, gettext('The time is incorrect!');
                }
            },
        },
        'stop' => {
            typ     => $con ? 'string' : 'time',
            def     => sub{
                    return fmttime($default->{stop});
                },
            msg     => gettext("End time in format 'HH:MM'"),
            check   => sub{
                my $value = shift;
                $value = fmttime($value) if($value =~ /^\d+$/sig);
                return undef, gettext('The time is incorrect!') if($value !~ /^\d+:\d+$/sig);
                my @v = split(':', $value);
                $value = sprintf('%02d%02d',$v[0],$v[1]);
                if(int($value) < 2400 and int($value) >= 0) {
                    return sprintf('%04d',$value);
                } else {
                    return undef, gettext('The time is incorrect!');
                }
            },
        },
        'priority' => {
            typ     => 'integer',
            msg     => sprintf(gettext('Priority (%d ... %d)'),0,$console->{USER}->{MaxPriority} ? $console->{USER}->{MaxPriority} : 99 ),
            def     => int($default->{priority}),
            check   => sub{
                my $value = shift || 0;
                if($value =~ /^\d+$/sig and $value >= 0 and $value < 100) {
                    if($console->{USER}->{MaxPriority} and $value > $console->{USER}->{MaxPriority}) {
                        return undef, sprintf(gettext('Sorry, but the maximum priority is limited to %d!'), $console->{USER}->{MaxPriority});
                    }
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'lifetime' => {
            typ     => 'integer',
            msg     => sprintf(gettext('Lifetime (%d ... %d)'),0,$console->{USER}->{MaxLifeTime} ? $console->{USER}->{MaxLifeTime} : 99 ),
            def     => int($default->{lifetime}),
            check   => sub{
                my $value = shift || 0;
                if($value =~ /^\d+$/sig and $value >= 0 and $value < 100) {
                    if($console->{USER}->{MaxLifeTime} and $value > $console->{USER}->{MaxLifeTime}) {
                        return undef, sprintf(gettext('Sorry, but the maximum life time is limited to %d!'), $console->{USER}->{MaxLifeTime});
                    }
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'keywords' => {
            typ     => $self->{keywords}->{active} eq 'y' ? 'string' : 'hidden',
            def     => $default->{keywords},
            msg     => gettext('Add keywords to recording'),
            check   => sub{
                my $value = shift || 0;
                $value =~ s/(\r|\n)/,/sg;
                return $value;
            }
        },
        'description' => {
            msg       =>  gettext('Description'),
            typ       => $default->{description} ? 'textfield' : 'hidden',
            def       => $default->{description} ? $default->{description} : '',
            readonly  => 1
        }
    ];

    # Ask Questions
    my $datasave = $console->question(($timerid ? gettext('Edit timer')
                                                : gettext('New timer')), $questions, $data);

    if(ref $datasave eq 'HASH') {
        my ($oldvid,$pos);
        if($timerid) {
          ($oldvid,$pos) = $self->getPos($timerid);
          if($datasave->{vid} == $oldvid) {
            $datasave->{pos} = $pos;
            $oldvid = undef;
          }
        }
        # Save timer on video disk recorder
        $self->_saveTimer($datasave);
        # Remove timer from old video disk recorder
        if($pos && $oldvid) {
          $self->{svdrp}->queue_add(sprintf("modt %d off", $pos), $oldvid)
            if($data->{running});
          $self->{svdrp}->queue_add(sprintf("delt %d", $pos), $oldvid)
        }
        return 1;
    }
    return 0;
}
# ------------------
sub editTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift;  # id of present timer, then edit this timer
    my $data    = shift;  # Data for defaults

    if($self->_editTimer($console,$config,$timerid,$data) 
        && $self->{svdrp}->queue_count()) {
          my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos

          unless($error) {
            debug sprintf('%s timer with title "%s" is saved%s',
                ($timerid ? 'Changed' : 'New'),
                $data->{file},
                ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
                );
                $console->message($erg);

          } else {
                my $msg = sprintf('%s timer with title "%s" does\'nt saved : %s',
                ($timerid ? 'Changed' : 'New'),
                $data->{file},
                $error
                );
                $console->err($msg);
          }
          $self->{changedTimer} = 1;

          if($self->_readData($console)) {
            $console->redirect({url => '?cmd=tlist', wait => 1})
              if(!$error && $console->typ eq 'HTML');
          }
    }
}

# ------------------
sub deleteTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || return $console->err(gettext("No timer defined for deletion! Please use tdelete 'tid'."));   # If timerid the edittimer
    my $answer  = shift || 0;

    my @timers  = split(/[^0-9a-f]/, $timerid);

    my $sql = sprintf(qq|
SELECT SQL_CACHE id, vid, pos, file, channel, starttime,
                 flags & 1 and NOW() between starttime and stoptime as running
FROM TIMERS where id in (%s) ORDER BY pos desc|, join(',' => ('?') x @timers)); 
    my $sth = $self->{dbh}->prepare($sql);

    $sth->execute(@timers)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $modC = main::getModule('CHANNELS') or return;

    while (my $t = $sth->fetchrow_hashref()) {

        if(ref $console and $console->{TYP} eq 'CONSOLE') {
            $console->table({
              gettext('Title')   => $t->{file},
              gettext('Channel') => $modC->ChannelToName($t->{channel}),
              gettext('Start')   => $t->{starttime},
            });
            my $confirm = $console->confirm({
                typ   => 'confirm',
                def   => 'y',
                msg   => gettext('Would you like to delete this timer?'),
            }, $answer);
            next if(!$answer eq 'y');
        }

        debug sprintf('Delete timer with title "%s"%s',
            $t->{file},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $self->{svdrp}->queue_add(sprintf("modt %d off", $t->{pos}), $t->{vid})
          if($t->{running});
        $self->{svdrp}->queue_add(sprintf("delt %d", $t->{pos}), $t->{vid});

        # Delete timer from request, if found in database
        my $i = 0;
        for my $x (@timers) {
          if ( $x eq $t->{id} ) { # Remove known MD5 from user request
            splice @timers, $i, 1;
          } else {
            $i++;
          }
        }
    }

    con_err($console,
      sprintf(gettext("Timer '%s' does not exist in the database!"), 
      join('\',\'',@timers))) 
          if(scalar @timers);

    if($self->{svdrp}->queue_count()) {
        my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos
        $console->msg($erg, $error)
            if(ref $console);

        sleep(1);

        if($self->_readData($console)) {
          $console->redirect({url => '?cmd=tlist', wait => 1})
            if(ref $console and $console->typ eq 'HTML');
        }
    } else {
        $console->err(gettext("No timer to delete!"));
    }

    return 1;
}

# ------------------
sub toggleTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || return $console->err(gettext("No timer defined to toggle! Please use ttoggle 'id'."));   # If timerid the edittimer

    my @timers  = split(/[^0-9a-f]/, $timerid);

    my $sql = sprintf('SELECT SQL_CACHE id,vid,pos,file,flags,starttime,stoptime FROM TIMERS where id in (%s) ORDER BY vid, pos desc', join(',' => ('?') x @timers)); 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute(@timers)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $ref;
    my @success;

    while (my $t = $sth->fetchrow_hashref()) {

        # Build query for all timers with possible collisions
        $ref .= " or '$t->{starttime}' between starttime and stoptime"
             .  " or '$t->{stoptime}'  between starttime and stoptime";


    	  my $status = (($t->{flags} & 1) ? 'off' : 'on');

        debug sprintf('Timer with title "%s" is %s%s',
            $t->{file},
            ($status eq 'on' ? 'activated' : 'deactivated'),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $self->{svdrp}->queue_add("modt $t->{pos} $status",$t->{vid}); # Sammeln der Kommandos

        # Delete timer from request, if found in database
        my $i = 0;
        for my $x (@timers) {
          if ( $x eq $t->{id} ) { # Remove known MD5 from user request
            splice @timers, $i, 1;
          } else {
            $i++;
          }
        }
        push(@success,$t->{id});
    }

    con_err($console,
      sprintf(gettext("Timer '%s' does not exist in the database!"), 
      join('\',\'',@timers))) 
          if(scalar @timers);

    if($self->{svdrp}->queue_count()) {
        my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos
        $console->msg($erg, $error)
            if(ref $console and $console->typ ne 'AJAX');

        if($self->_readData($console)) {
          $console->redirect({url => '?cmd=tlist', wait => 1})
            if(ref $console and $console->typ eq 'HTML');
        }

        if(ref $console and $console->typ eq 'AJAX') {
          # { "data" : [ [ ID, ON, RUN, CONFLICT ], .... ] }
          # { "data" : [ [ 5, 1, 0, 0 ], .... ] }
          my $sql = sprintf('SELECT SQL_CACHE id, flags & 1 as Active, NOW() between starttime and stoptime as Running, Collision from TIMERS where id in (%s) %s',
                             join(',' => ('?') x @success),$ref); 
          my $sth = $self->{dbh}->prepare($sql);
          $sth->execute(@success)
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
          my $erg = $sth->fetchall_arrayref();
          $console->table($erg,{state => 'success'});
        }

        return 1;
    } else {
        $console->err(gettext('No timer to toggle!'));
        return undef;
    }
}


# ------------------
sub _insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $timer = shift || return;

    # import only status which used from vdr and thereby exclude eventid from vdradmin
    $timer->{flags} &= 15;

    # change pos to channelid, because change to telnet reader
    if(index($timer->{channel}, '-') < 0) {
      $timer->{channel} = main::getModule('CHANNELS')->ToCID($timer->{channel},$timer->{vid})
        or return error(sprintf("Couldn't get channel from this timer: %d '%s'", $timer->{pos}, $timer->{channel}));
    }

    $timer->{file} =~ s/\|/\:/g;

    # NextTime
    my $nexttime = $self->getNextTime( $timer->{day}, $timer->{start}, $timer->{stop} )
        or return error(sprintf("Couldn't get time from this timer: %d '%s' '%s' '%s'", $timer->{pos}, $timer->{day}, $timer->{start}, $timer->{stop}));

    # Search for event at EPG
    my $e = $self->_getNextEpgId( {
          vid     => $timer->{vid},
          pos     => $timer->{pos},
          flags   => $timer->{flags},
          channel => $timer->{channel},
          file    => $timer->{file},
          start   => $nexttime->{start},
          stop    => $nexttime->{stop},
        });

    # Tags
    my $aid;
    my $keywords;
    my $xml = $self->{keywords}->parsexml($timer->{aux});
    $aid = int($xml->{'autotimer'})
      if($xml && defined $xml->{'autotimer'} );
    $keywords = $xml->{'keywords'}
      if($xml && defined $xml->{'keywords'} );

    my $sth = $self->{dbh}->prepare(
q|REPLACE INTO TIMERS VALUES 
  (?,?,?,?,?,?,?,?,?,?,?,?,FROM_UNIXTIME(?), FROM_UNIXTIME(?),0,?,?,?,?,0,NOW())
|);
    my $id = md5_hex($timer->{vid} . $timer->{channel} . $nexttime->{start} . $nexttime->{stop} . $timer->{file} );
    $sth->execute( 
         $id,
         $timer->{vid},
         $timer->{pos},
         $timer->{flags},
         $timer->{channel},
         $timer->{day},
         $timer->{start},
         $timer->{stop},
         $timer->{priority},
         $timer->{lifetime},
         $timer->{file},
         $timer->{aux},
         $nexttime->{start},
         $nexttime->{stop},
         $e ? $e->{eventid} : 0,
         $e ? $e->{starttime} : 0,
         $e ? $e->{duration} : 0,
         $aid
     ) or return error sprintf("Couldn't execute query: %s.",$sth->errstr);

  $self->{keywords}->insert('timer',$id,$keywords);

  return 1;
}

# Read data
# ------------------
sub _readData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;

    # Search for correct times
    $self->getCheckTimer()
      if($self->{adjust} eq 'y');

    my $oldTimers = &getDataByTable('TIMERS');

    $self->{dbh}->do('DELETE FROM TIMERS');
    $self->{keywords}->removesource('timer');

    my $c = 0;

    my $hostlist = $self->{svdrp}->list_hosts();
    # read from svdrp
    foreach my $vid (@$hostlist) {
      my ($tlist,$error) = $self->{svdrp}->command('lstt',$vid);
      unless($error) {
        foreach my $line (@$tlist) {
          next unless($line and $line =~ /^250[- ](\d+)/s);
          my $pos = $1;
          $line =~ s/^\d+[- ]+\d+\s//sig;
          my @data = split(':', $line, 9);
          if(scalar @data > 2) {
            my $timer = {
              vid     => $vid,
              pos     => $pos,
              flags   => $data[0],
              channel => $data[1],
              day     => $data[2],
              start   => $data[3],
              stop    => $data[4],
              priority=> $data[5],
              lifetime=> $data[6],
              file    => $data[7],
              aux     => $data[8]
            };
            if($self->_insert($timer)) {
              $c++;
            }
          }
        }
      }
    }
    # Search for overlapping Timers
    $self->findOverlapping();

    # Get timers by Autotimer
    my $aids = getDataByFields('AUTOTIMER', 'Id');
    $self->getTimersByAutotimer($aids);

    # Get new timers by User
    if(($oldTimers && scalar keys %$oldTimers != $c)
        or (!$oldTimers && $c)  
        or exists $self->{changedTimer}) {

        my $timers = $self->getNewTimers($oldTimers);
        foreach my $t (keys %$timers) {
            event sprintf('New timer %d on %s - "%s"', $timers->{$t}->{pos}, $self->{svdrp}->hostname($timers->{$t}->{vid}), $timers->{$t}->{file});
        }
        $self->updated() if(($timers && scalar keys %$timers) or exists $self->{changedTimer});
        delete $self->{changedTimer}  if(exists $self->{changedTimer});
    }

    # Event to signal we are finish to read
    lg(sprintf('Reread %d timers and written into database!', $c));

    $console->message(sprintf(gettext("%d timer written to database."), $c))
        if(ref $console and $console->typ ne 'AJAX');

    return 1;
}

# ------------------
sub readData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    if($self->_readData($console)) {
      $console->redirect({url => '?cmd=tlist', wait => 1})
        if(ref $console and $console->typ eq 'HTML');
    }
}

# Routine um Callbacks zu registrieren und
# diese nach dem Aktualisieren der Timer zu starten
# ------------------
sub updated {
# ------------------
    my $self = shift || return error('No object defined!');
    my $cb = shift || 0;
    my $log = shift || 0;

    if($cb) {
        push(@{$self->{after_updated}}, [$cb, $log]);
    } else {
        foreach my $CB (@{$self->{after_updated}}) {
            next unless(ref $CB eq 'ARRAY');
            lg $CB->[1]
                if($CB->[1]);
            &{$CB->[0]}()
                if(ref $CB->[0] eq 'CODE');
        }
    }
}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id    = shift;
    my $params  = shift;

	  my $term;
	  my $search;
	  if($id and $id =~ /^[0-9a-f,_ ]+$/ and length($id) >= 32 ) {
      my @timers  = split(/[^0-9a-f]/, $id);
      $search = sprintf(" AND t.id in (%s)",join(',' => ('?') x @timers));
      foreach(@timers) { push(@{$term},$_); }
	  }

    return $self->_list($console,$config,$search,$term,$params);
}

# ------------------
sub search {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text    = shift || return $self->list($console);
    my $params  = shift;

	  my $term;
	  my $search;
    my $query = buildsearch("t.file,(SELECT description FROM EPG as e WHERE t.eventid = e.eventid LIMIT 1)",$text);
    $search = sprintf('AND ( %s )', $query->{query});
    foreach(@{$query->{term}}) { push(@{$term},$_); }

    return $self->_list($console,$config,$search,$term,$params);
}

# ------------------
sub _list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
	  my $search = shift || '';
	  my $term = shift;
	  my $params = shift;
    my $tables  = shift || '';

    my %f = (
        'id' => gettext('Service'),
        'flags' => gettext('Status'),
        'day' => gettext('Day'),
        'channel' => gettext('Channel'),
        'start' => gettext('Start'),
        'stop' => gettext('Stop'),
        'title' => gettext('Title')
    );

    my $sql = qq|
SELECT SQL_CACHE 
    t.id as \'$f{'id'}\',
    t.flags as \'$f{'flags'}\',
    c.name as \'$f{'channel'}\',
    c.hash as __pos,
    UNIX_TIMESTAMP(t.starttime) as \'$f{'day'}\',
    DATE_FORMAT(t.starttime, '%H:%i') as \'$f{'start'}\',
    DATE_FORMAT(t.stoptime, '%H:%i') as \'$f{'stop'}\',
    t.file as \'$f{'title'}\',
    t.priority as __priority,
    t.collision as __collision,
    t.eventid as __eventid,
    t.autotimerid as __autotimerid,
	  UNIX_TIMESTAMP(t.stoptime) - UNIX_TIMESTAMP(t.starttime) as __duration,
    (SELECT IF(CHAR_LENGTH(e.description)>77,RPAD(LEFT(e.description,77),80,'.'),e.description)
      FROM EPG as e
      WHERE t.eventid = e.eventid
      and  t.channel = e.channel_id
      LIMIT 1) as __description,
    NOW() between starttime and stoptime AND (flags & 1) as __running,
    r.host as __host
FROM
    TIMERS as t,
    CHANNELS as c,
    RECORDER as r
    $tables
WHERE
    t.stoptime > NOW()
    AND t.channel = c.id
    AND t.vid = c.vid
    AND t.vid = r.id
    $search
ORDER BY
    t.starttime
|;

    my $rows;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $self->{dbh}->prepare($sql);
         $rsth->execute(@{$term})
          or return error sprintf("Couldn't execute query: %s.",$rsth->errstr);
      $rows = $rsth->rows;
      if($rows <= $limit) {
        $sth = $rsth;
      } else {
        # Add limit query
        if($console->{cgi}->param('start')) {
          $sql .= " LIMIT " . CORE::int($console->{cgi}->param('start'));
          $sql .= "," . $limit;
        } else {
          $sql .= " LIMIT " . $limit;
        }
      }
    }

    unless($sth) {
      $sth = $self->{dbh}->prepare($sql);
      $sth->execute(@{$term})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    my $keywords;
    my $keywordmax;
    my $keywordmin;

    unless($console->typ eq 'AJAX') {
      my $md5;
      map {
          push(@$md5,$_->[0]);
          $_->[4] = datum($_->[4],'weekday');
      } @$erg;

      ($keywords,$keywordmax,$keywordmin) = $self->{keywords}->list('timer',$md5);

      unshift(@$erg, $fields);
    }

    # More then one host defined
    my $hostlist = $self->{svdrp}->list_hosts();

    $console->setCall('tlist');
    $console->table($erg, {
		    capacity => main::getModule('RECORDS')->{CapacityFree},
        recorder => scalar @$hostlist,
        keywords => $keywords,
        keywordsmax => $keywordmax,        
        keywordsmin => $keywordmin,
        rows => $rows
    });
}

# ------------------
sub getTimerById {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $tid = shift  || return error('No tid defined!');

    my $sql = qq|
SELECT SQL_CACHE 
    t.id,
    t.flags,
    c.Name as Channel,
    c.Pos as __Pos,
    t.day as Date,
    t.start,
    t.stop,
    t.file,
    t.priority,
    UNIX_TIMESTAMP(t.starttime) as Day,
    t.collision,
    t.eventid,
    t.autotimerid
FROM
    TIMERS as t,
    CHANNELS as c
WHERE
    t.channel = c.id
    AND t.vid = c.vid
    and t.id = ?
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($tid)
        or return error(sprintf("Timer '%s' does not exist in the database!",$tid));
    return $sth->fetchrow_hashref();
}

# ------------------
sub getTimerByPos {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vid = shift  || return error('No vid defined!');
    my $pos = shift  || return error('No pos defined!');

    my $sql = qq|
SELECT SQL_CACHE 
    t.id,
    t.flags,
    c.Name as Channel,
    c.Pos as __Pos,
    t.day as Date,
    t.start,
    t.stop,
    t.file,
    t.priority,
    UNIX_TIMESTAMP(t.starttime) as Day,
    t.collision,
    t.eventid,
    t.autotimerid,
    UNIX_TIMESTAMP(t.eventstarttime) + t.eventduration as eventstoptime
FROM
    TIMERS as t,
    CHANNELS as c
WHERE
    t.channel = c.id
    AND t.vid = c.vid
    and t.vid = ?
    and t.pos = ?
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($vid, $pos)
        or return error(sprintf("Timer '%s' does not exist in the database!",sprintf("%d/%d",$vid,$pos)));
    return $sth->fetchrow_hashref();
}
# ------------------
sub getRunningTimer {
# ------------------
    my $self = shift || return error('No object defined!');
		my $rowname = shift || 'id';
    my $sql = "SELECT SQL_CACHE $rowname from TIMERS where NOW() between starttime and stoptime AND (flags & 1)";
    my $erg = $self->{dbh}->selectall_hashref($sql, $rowname);
    return $erg;
}

# ------------------
sub getNewTimers {
# ------------------
    my $self = shift || return error('No object defined!');
    my $oldTimers = shift;

    if($oldTimers) {
      my @old = keys %$oldTimers;
      return undef unless(scalar @old);

      my $sql = sprintf('SELECT SQL_CACHE * FROM TIMERS where id not in (%s)', join(',' => ('?') x @old)); 
      my $sth = $self->{dbh}->prepare($sql);
      $sth->execute(@old)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      return $sth->fetchall_hashref('id');
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * FROM TIMERS');
      $sth->execute()
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      return $sth->fetchall_hashref('id');
    }
}

# ------------------
sub getCheckTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $sql = qq|
SELECT SQL_CACHE t.id, t.vid, t.pos, t.flags, t.channel, t.priority, t.lifetime,
        t.file, t.aux, t.start as timerstart,t.stop as timerstop,

        UNIX_TIMESTAMP(e.starttime) as starttime,
        UNIX_TIMESTAMP(e.starttime) + e.duration as stoptime,
        UNIX_TIMESTAMP(e.vpstime) as vpsstart,
        UNIX_TIMESTAMP(e.vpstime) + e.duration as vpsstop,

        ABS(UNIX_TIMESTAMP(t.eventstarttime) - UNIX_TIMESTAMP(t.starttime)) as lead,
        ABS(UNIX_TIMESTAMP(t.stoptime)-(UNIX_TIMESTAMP(t.eventstarttime) + t.eventduration)) as lag

        FROM TIMERS as t, EPG as e 
        WHERE e.eventid > 0 
        AND t.eventid = e.eventid
        AND t.vid = e.vid
        AND (
                   (((t.flags & 4) = 0) AND e.starttime != t.eventstarttime) 
                OR ((t.flags & 4) AND e.vpstime != t.eventstarttime) 
                OR (e.duration != t.eventduration)
            )
        AND SUBSTRING_INDEX( t.file , '~', 1 ) LIKE CONCAT('%', e.title ,'%')
|;
    my $erg = $self->{dbh}->selectall_hashref($sql, 'id');

    foreach my $t (keys %$erg) {
        my %tt;

        # Adjust start and stop times
        my $start;
        my $stop;

        if(($erg->{$t}->{flags} & 4)  # Use PDC time if used
           and $erg->{$t}->{vpsstart} 
           and $erg->{$t}->{vpsstop}) {
            $start = $erg->{$t}->{vpsstart};
            $stop = $erg->{$t}->{vpsstop};
        } else {
            $start = $erg->{$t}->{starttime} - $erg->{$t}->{lead};
            $stop  = $erg->{$t}->{stoptime} + $erg->{$t}->{lag};
        }

        # Format parameterhash for saveTimer
        my $tt = {
            vid       => $erg->{$t}->{vid},
            pos       => $erg->{$t}->{pos},
            active    => (($erg->{$t}->{flags} & 1) ? 'y' : 'n'),
            vps       => (($erg->{$t}->{flags} & 4) ? 'y' : 'n'), 
            channel   => $erg->{$t}->{channel},
            file      => $erg->{$t}->{file},
            aux       => $erg->{$t}->{aux},
            day       => my_strftime("%Y-%m-%d",$start),
            start     => my_strftime("%H%M",$start),
            stop      => my_strftime("%H%M",$stop),
            priority  => $erg->{$t}->{priority},
            lifetime  => $erg->{$t}->{lifetime}
      	};

        # next if adjust change notthing ... (e.g. time changed only around few seconds)
        next if($erg->{$t}->{timerstart} == $tt->{start}
             && $erg->{$t}->{timerstop}  == $tt->{stop});

        # save timer 
        my $from = sprintf('%s - %s',fmttime($erg->{$t}->{timerstart}), fmttime($erg->{$t}->{timerstop}));
        my $to = sprintf('%s - %s',fmttime($tt->{start}),fmttime($tt->{stop}));
        debug sprintf("Adjust timer %d on %s at %s : from %s to %s - %s", 
                      $tt->{pos}, 
                      $self->{svdrp}->hostname($tt->{vid}), 
                      $tt->{day}, 
                      $from, $to,
                      $tt->{file});

        $self->saveTimer($tt, 'store');

        $self->news($tt->{vid},$tt->{pos}
                   ,sprintf(gettext("Adjust timer : %s"),$tt->{file})
                   ,'interesting'
                   ,sprintf(gettext("Adjust times from %s to %s"),$from, $to) . "\r\n"
              );
    }
    return $erg;
}

# ------------------
sub getPos {
# ------------------
    my $self = shift || return error('No object defined!');
    my $tid = shift  || return error('No id defined!');

    my $sql = qq|
SELECT SQL_CACHE
    vid, pos 
  from TIMERS as t
  where
    t.id = ?
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($tid)
        or return error(sprintf("Timer '%s' does not exist in the database!",$tid));
    my $erg = $sth->fetchrow_hashref();
    return $erg ? ($erg->{vid}, $erg->{pos}) : undef;
}

# ------------------
sub getEpgDesc {
# ------------------
    my $self = shift || return error('No object defined!');
    my $tid = shift  || return error('No id defined!');

    my $sql = qq|
SELECT SQL_CACHE 
    description from TIMERS as t, EPG as e
where
    e.eventid > 0 and
    t.eventid = e.eventid and
    t.id = ?
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($tid)
        or return error(sprintf("Timer '%s' does not exist in the database!",$tid));
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{description} : '';
}

# ------------------
sub findOverlapping {
# ------------------
    my $self = shift  || return error('No object defined!');

    my $CARDS;
    my $hostlist = $self->{svdrp}->list_hosts();
    # read from svdrp
    foreach my $vid (@$hostlist) {
      my $cards = $self->{svdrp}->cards($vid);
      my @DVBCARDS = split(/[,;\r\n]/,$cards);
      my $cardid = 1;
      foreach my $source (@DVBCARDS) {
        $source =~ s/^\s+//;               # no leading white space
        $source =~ s/\s+$//;               # no trailing white space

        unshift(@{$CARDS},{
            source => $source,
            tid => undef,
            stoptime => 0,
            cardID => $cardid ++,
            vid => $vid,
            #CA => ''
          }
        );
      }
    }

#   for my $ca (@{$CARDS}) {
#     dumper($ca);
#   }

    my $sql = qq|
SELECT t.id,
    UNIX_TIMESTAMP(t.starttime) as starttime,
    UNIX_TIMESTAMP(t.stoptime) as stoptime,
    t.priority,
    c.CA,
    c.vid,
    c.source,
    c.TID as tid,
    file
FROM
    TIMERS as t, CHANNELS as c
WHERE
    (t.flags & 1)
    AND t.channel = c.id
    AND t.vid = c.vid
ORDER BY
    t.starttime asc,
    t.priority desc
|;

    my $sth = $self->{dbh}->prepare($sql);
       $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $timer;
    # try to assign timer to dvb cards
    while (my $ti = $sth->fetchrow_hashref()) {
      push(@{$timer},$ti);

      my $CardOnly = 0;
      if($ti->{CA} =~ /^(\d+)$/ && $1 < 16) {
        $CardOnly = $1;
      } 
      for my $ca (@{$CARDS}) {
        my $source = $ca->{source};
        if(!($ti->{UsedCard}) # If'nt assign
            && $ca->{vid} eq $ti->{vid} # Same host
            && $ti->{source} =~ /$source/ # Same source
             && (!$CardOnly || $ca->{cardID} == $CardOnly) # if CA has DVB Card number
             && (!$ca->{tid} # Unused transponder
                || $ca->{tid} eq $ti->{tid} # or same transponder
                || $ti->{starttime} >= $ca->{stoptime})) { # or timer ended and card are free for next timer

                $ca->{tid}       = $ti->{tid};
                $ca->{stoptime}  = $ti->{stoptime};
                $ti->{UsedCard}  = $ca->{cardID};
          }
        }
    #  lg sprintf("%s use dvb card %s", $ti->{file}, $ti->{UsedCard} || '-');
    }

    # check priority and mark collisions
    my $rerun;
    do {
      $rerun = 0;
      foreach my $ti (@{$timer}) {
        unless($ti->{UsedCard}) { # used card
          my $CardOnly = 0;
          if($ti->{CA} =~ /^(\d+)$/ && $1 < 16) {
            $CardOnly = $1;
          } 
          foreach my $co (@{$timer}) {
            if($ti->{id} ne $co->{id}
                && $co->{UsedCard} # used card
                && ($co->{vid} eq $ti->{vid})      #Same Host
                && ($co->{source} eq $ti->{source}) #Same Source
                && ((($ti->{starttime} >= $co->{starttime}) # start >= start
                       && ($ti->{starttime} <= $co->{stoptime})) # start <= stop
                   || (($ti->{stoptime} >= $co->{starttime}) # stop >= stop
                       && ($ti->{stoptime} <= $co->{stoptime})) # stop <= stop
                   )
                && (!$CardOnly || $CardOnly == $co->{UsedCard})
               ) 
            {
               if($ti->{priority} == $co->{priority}) {     # Same priority
                  push(@{$ti->{Collision}},sprintf('%s:%d',$co->{id},$co->{priority}));
                  push(@{$co->{Collision}},sprintf('%s:%d',$ti->{id},$ti->{priority}));
               } elsif($ti->{priority} > $co->{priority}) { # bigger priority
                  $ti->{UsedCard} = delete $co->{UsedCard};
                  push(@{$co->{Collision}},sprintf('%s:%d',$ti->{id},$ti->{priority}));
                  # need rerun
                  $rerun = 1;
               } else {                                      # lesser priority
                  push(@{$ti->{Collision}},sprintf('%s:%d',$co->{id},$co->{priority}));
               }
            }
          }
        }
      }
    } while($rerun);

    my $uth = $self->{dbh}->prepare("UPDATE TIMERS SET collision = ? WHERE id = ?");
    foreach my $ti (@{$timer}) {
      debug sprintf("%s (none free dvb card)", $ti->{file}) unless ($ti->{UsedCard});
      if(!$ti->{UsedCard} || ($ti->{Collision} && scalar @{$ti->{Collision}})) {
          $uth->execute($ti->{Collision} ? join(',',@{$ti->{Collision}}) : 'None free dvb card',$ti->{id})
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      }
    }
}

# ------------------
sub checkOverlapping {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $data = shift  || return error('No data defined!');

    my $starttime =  $data->{starttime};
    my $stoptime  =  $data->{stoptime};
    my $transponder   =  $data->{tid};
    my $source        =  $data->{source};
    my $Priority      =  $data->{priority} || $self->{Priority};
    my $timer         =  $data->{id} || 0;
    my $vid           =  $data->{vid};

    my $sql = qq|
SELECT SQL_CACHE 
    t.id,
    t.priority,
    c.TID
FROM
    TIMERS as t, CHANNELS as c
WHERE
    ((? between t.starttime AND t.stoptime)
     OR (? between t.starttime AND t.stoptime)
     OR (t.starttime between ? AND ?)
     OR (t.stoptime between ? AND ?))
    AND t.id != ?
    AND (t.flags & 1)
    AND t.channel = c.id
    AND t.vid = c.vid
    AND c.TID != ?
    AND LEFT(c.Source,1) = ?
ORDER BY
    t.priority desc
|;
    my $sth = $self->{dbh}->prepare($sql);
        $sth->execute($starttime,$stoptime,
            $starttime,$stoptime,
            $starttime,$stoptime,
            $timer,$transponder,$source)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $result = $sth->fetchall_arrayref();

    if(scalar @{$result}) {
            my $coltext = [];
            foreach my $probant (@{$result}) {

               if(defined $probant->[0]) {

               # current timer has higher Priority
               last
                  if($Priority > $probant->[1]);


               # Store conflict line at line
               my $col = sprintf('%s:%s',
                                    $probant->[0],
                                    $probant->[1]);

               # insert double transponder, on same line
               my $n = 0;
               foreach my $trans (@{$result}) {

                    if(defined $trans->[0]
                         && $probant->[0] ne $trans->[0]
                         && $probant->[2] eq $trans->[2]) {

                        $col .= sprintf('|%s:%s',
                                    $trans->[0],
                                    $trans->[1]);

                       undef @{$result}[$n]->[0];
                    }
                    ++$n;
               }
               # Add line
               push(@$coltext,$col);
           }
        }

        my $howmany = 1;
        my $cards = $self->{svdrp}->cards($vid);
        if($cards) {
          my @DVBCARDS = split(',',$self->{svdrp}->cards($vid));
          $howmany = scalar @DVBCARDS;
        }

        if(scalar(@$coltext) > ($howmany - 1)) {
            return $coltext;
        }
    }
}

# Find EPG to selected timer
# ------------------
sub _getNextEpgId {
# ------------------
    my $self  = shift || return error('No object defined!');
    my $timer  = shift || return error('No data defined!');

    my $e;
    my @file = split('~', $timer->{file});
    my $timemode = ($timer->{flags} & 4) ? 'vpstime' : 'starttime';
    if(scalar @file >= 2) { # title and subtitle defined
        my $sth = $self->{dbh}->prepare(sprintf(qq|
            SELECT SQL_CACHE eventid,%s as starttime,duration from EPG
            WHERE
                channel_id = ? 
                AND ((UNIX_TIMESTAMP(%s) + (duration/2)) between  ?  and  ? )
                AND (title like ? or title like ? )
                AND vid = ?
            ORDER BY ABS(( ? )-UNIX_TIMESTAMP(%s)) LIMIT 1
            |,$timemode,$timemode,$timemode));
        if(!$sth->execute($timer->{channel},
                      $timer->{start},
                      $timer->{stop},
                      '%'.$file[-2].'%',
                      '%'.$file[-1].'%',
                      $timer->{vid},
                      $timer->{start})) {
            lg sprintf("Couldn't find epg event for timer with id %d - %s", $timer->{pos} , $timer->{file} );
            return 0;
        }
        $e = $sth->fetchrow_hashref();

    } else {
        my $sth = $self->{dbh}->prepare(sprintf(qq|
            SELECT SQL_CACHE eventid,%s as starttime,duration from EPG
            WHERE
                channel_id = ? 
                AND ((UNIX_TIMESTAMP(%s) + (duration/2)) between  ?  and  ? )
                AND (title like ? )
                AND vid = ?
            ORDER BY ABS(( ? )-UNIX_TIMESTAMP(%s)) LIMIT 1
            |,$timemode,$timemode,$timemode));
        if(!$sth->execute($timer->{channel},
                      $timer->{start},
                      $timer->{stop},
                      '%'.$timer->{file}.'%',
                      $timer->{vid},
                      $timer->{start})) {
            lg sprintf("Couldn't find epg event for timer with id %d - %s", $timer->{pos} , $timer->{file} );
            return 0;
        }
        $e = $sth->fetchrow_hashref();
    }


    lg sprintf("Couldn't find epg event for timer with id %d - %s", $timer->{pos} , $timer->{file} )
        if(not exists $e->{eventid});
    return $e;
}

# The following subroutines is stolen from vdradmind and vdradmin-0.97-am
# Thanks on Cooper and Thomas for this great work!
# $self->getNextTime('MDMDFSS', 1300, 1200)
# ------------------
sub getNextTime {
# ------------------
    my $self = shift || return error('No object defined!');
    my $dor = shift || return error('No day defined!');
    my $start = shift || return error('No start time defined!');
    my $stop =  shift || return error('No stop time defined!');

    $start = sprintf('%04d', $start);
    $stop = sprintf('%04d', $stop);

    my ($startsse, $stopsse);
    if(length($dor) == 7) { # repeating timer => MTWTFSS
        $startsse = my_mktime(substr($start, 2, 2), substr($start, 0, 2),
                       my_strftime("%d"), (my_strftime("%m") - 1), my_strftime("%Y"));
        $stopsse  = my_mktime(substr($stop, 2, 2), substr($stop, 0, 2),
                       my_strftime("%d"), (my_strftime("%m") - 1), my_strftime("%Y"));
        $stopsse += 86400 if($stopsse < $startsse);

        my $weekday = ((localtime(time))[6] + 6) % 7;
        my $perrec = join("", substr($dor, $weekday), substr($dor, 0, $weekday));
        $perrec =~ m/^-+/g;

        my $off = (pos $perrec || 0) * 86400;
        if($off == 0 && $stopsse < time) {
            #$weekday = ($weekday + 1) % 7;
            $perrec = join("", substr($dor, ($weekday + 1) % 7), substr($dor, 0, ($weekday + 1) % 7));
            $perrec =~ m/^-+/g;
            $off = ((pos $perrec || 0) + 1) * 86400;
        }
        $startsse += $off;
        $stopsse += $off;
    } elsif(length($dor) == 18) { # first-day timer => MTWTFSS@2005-03-13
        $dor =~ /.{7}\@(\d{4})-(\d{2})-(\d{2})/;
        $startsse = my_mktime(substr($start, 2, 2),
                substr($start, 0, 2), $3, ($2 - 1), $1);
        # 31 + 1 = ??
        $stopsse = my_mktime(substr($stop, 2, 2),
                substr($stop, 0, 2), $stop > $start ? $3 : $3 + 1,
                ($2 - 1), $1);
    } else { # regular timer
      if ($dor =~ /(\d{4})-(\d{2})-(\d{2})/) { # vdr >= 1.3.23 => 2005-03-13
        $startsse = my_mktime(substr($start, 2, 2),
                              substr($start, 0, 2), $3, ($2 - 1), $1);

        $stopsse = my_mktime(substr($stop, 2, 2),
                             substr($stop, 0, 2), $stop > $start ? $3 : $3 + 1, ($2 - 1), $1);
      }
      else { # vdr < 1.3.23 => 13
        $startsse = my_mktime(substr($start, 2, 2),
                substr($start, 0, 2), $dor, (my_strftime("%m") - 1),
                my_strftime("%Y"));

        $stopsse = my_mktime(substr($stop, 2, 2),
                substr($stop, 0, 2), $stop > $start ? $dor : $dor + 1,
                (my_strftime("%m") - 1), my_strftime("%Y"));

        # move timers which have expired one month into the future
        if(length($dor) != 7 && $stopsse < time) {
          $startsse = my_mktime(substr($start, 2, 2),
                                substr($start, 0, 2), $dor, (my_strftime("%m") % 12),
                                (my_strftime("%Y") + (my_strftime("%m") == 12 ? 1 : 0)));

          $stopsse = my_mktime(substr($stop, 2, 2),
                               substr($stop, 0, 2), $stop > $start ? $dor : $dor + 1,
                               (my_strftime("%m") % 12),
                               (my_strftime("%Y") + (my_strftime("%m") == 12 ? 1 : 0)));
        }
      }
    }

    my $ret = {
        start => $startsse,
        stop => $stopsse,
    };
    return $ret;
}

# ------------------
# Name:  getTimersByAutotimer
# Descr: Routine group Autotimer to Timers.
# Usage: $hash = $self->getTimersByAutotimer([$aid, $aid, $aid, ...]);
# ------------------
sub getTimersByAutotimer {
    my $self = shift  || return error('No object defined!');
    my $aids = shift || return $self->{AIDS};

    $self->{AIDS} = {};
    for my $aid (@$aids) {
        $self->{AIDS}->{$aid} = {
            allTimer => [],
            activeTimer => [],
            deactiveTimer => [],
        };
        my $erg = getDataBySearch('TIMERS', 'autotimerid = ?', $aid);
        map {
            my $type = ($_->[1] ? 'activeTimer' : 'deactiveTimer');
            push(@{$self->{AIDS}->{$aid}->{$type}}, $_->[0]);
            push(@{$self->{AIDS}->{$aid}->{allTimer}}, $_->[0]);
        } @$erg;
    }
    return $self->{AIDS};
}

sub my_mktime {
    my $sec  = 0;
    my $min = shift;
    my $hour = shift;
    my $mday = shift;
    my $mon  = shift;
    my $year = shift() - 1900;

    return mktime($sec, $min, $hour, $mday, $mon, $year, 0, 0, -1);
}

sub my_strftime {
    my $format = shift;
    my $time = shift || time;
    return(strftime($format, localtime($time)));
}

# ------------------
sub suggest {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $search = shift;
    my $params  = shift;

    if($search) {
        my $sql = qq|
    SELECT SQL_CACHE 
        file
    FROM
        TIMERS
    WHERE
    	( file LIKE ? )
    GROUP BY
        file
    ORDER BY
        file
    LIMIT 25
        |;
        my $sth = $self->{dbh}->prepare($sql);
        $sth->execute('%'.$search.'%')
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
        my $result = $sth->fetchall_arrayref();
        $console->table($result)
            if(ref $console && $result);
    }
}

# ------------------
sub news {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vid = shift  || return error('No vid defined!');
    my $pos = shift  || return error('No pos defined!');
    my $title = shift  || return error('No title defined!');
    my $eventlevel = shift  || return error('No eventlevel defined!');
    my $description = shift  || '';

    my $timer = $self->getTimerByPos($vid,$pos) || return undef;
    return $self->_news($title, $timer, $eventlevel, $description);
}

# ------------------
sub _news {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $title = shift  || return error('No title defined!');
    my $timer = shift  || return error('No timer defined!');
    my $eventlevel = shift  || return error('No eventlevel defined!');
    my $description = shift  || '';

    $description .= sprintf(gettext("Channel: %s"), $timer->{Channel});
    $description .= "\r\n";

    $timer->{starttime} = datum($timer->{Day});

    $description .= sprintf(gettext("On: %s to %s"),
        $timer->{starttime},
        fmttime($timer->{stop}));
    $description .= "\r\n";

    my $epgdesc = $self->getEpgDesc($timer->{id});
    $description .= $epgdesc
      if($epgdesc);

    main::getModule('EVENTS')->news($title, $description, "display", $timer->{eventid}, $eventlevel);

}

1;

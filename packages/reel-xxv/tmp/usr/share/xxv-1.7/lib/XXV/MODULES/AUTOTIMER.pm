package XXV::MODULES::AUTOTIMER;

use strict;

use Tools;

# ------------------
# Name:  module
# Descr: The standard routine to describe the Plugin
# Usage: my $modhash = $obj->module();
# ------------------
sub module {
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'AUTOTIMER',
        Prereq => {
            'Date::Manip' => 'date manipulation routines'
        },
        Description => gettext('This module searches for EPG entries with user-defined text and creates new timers.'),
        Status => sub{ $obj->status(@_) },
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            exclude => {
                description => gettext('Exclude channels from autotimer'),
                type        => 'string',
                default     => 'POS > 50',
                check   => sub{
                    my $value = shift;
                    if(index($value, ',') != -1) {
                        return 'POS > 50'; # Nur um sicher zu sein, das die alten Werte nicht übernommen werden.
                    } else {
                        return $value;
                    }
                },
            },
        },
        Commands => {
            anew => {
                description => gettext("Create new autotimer"),
                short       => 'an',
                callback    => sub{ $obj->autotimerCreate(@_) },
                Level       => 'user',
                DenyClass   => 'aedit',
            },
            adelete => {
                description => gettext("Delete a autotimer 'aid'"),
                short       => 'ad',
                callback    => sub{ $obj->autotimerDelete(@_) },
                Level       => 'user',
                DenyClass   => 'aedit',
            },
            aedit => {
                description => gettext("Edit an autotimer 'aid'"),
                short       => 'ae',
                callback    => sub{ $obj->autotimerEdit(@_) },
                Level       => 'user',
                DenyClass   => 'aedit',
            },
            asearch => {
                description => gettext("Search for autotimer with text 'aid'"),
                short       => 'ase',
                callback    => sub{ $obj->list(@_) },
                DenyClass   => 'alist',
            },
            alist => {
                description => gettext("Show autotimer 'aid'"),
                short       => 'al',
                callback    => sub{ $obj->list(@_) },
                DenyClass   => 'alist',
            },
            aupdate => {
                description => gettext("Start autotimer search."),
                short       => 'au',
                callback    => sub{ $obj->autotimer(@_) },
                Level       => 'user',
                DenyClass   => 'aedit',
            },
            atoggle => {
                description => gettext("Toggle autotimer on or off 'aid'"),
                short       => 'at',
                callback    => sub{ $obj->autotimerToggle(@_) },
                Level       => 'user',
                DenyClass   => 'aedit',
            },
            asuggest => {
                hidden      => 'yes',
                callback    => sub{ $obj->suggest(@_) },
                DenyClass   => 'alist',
            },
        },
        RegEvent    => {
             # Create event entries if an autotimer has created a new timer
            'newTimerfromAutotimer' => {

                # You have this choices (harmless is default):
                # 'harmless', 'interesting', 'veryinteresting', 'important', 'veryimportant'
                Level => 'veryinteresting',

                # Search for a spezial Event.
                # I.e.: Search for an LogEvent with match
                # "Sub=>text" = subroutine =~ /text/
                # "Msg=>text" = logmessage =~ /text/
                # "Mod=>text" = modname =~ /text/
                SearchForEvent => {
                    Mod => 'AUTOTIMER',
                    Msg => 'Save timer',
                },
                # Search for a Match and extract the information
                # of the TimerId
                # ...
                Match => {
                    pos => qr/Save timer\s+(\d+)/s,
                    host => qr/Save timer\s+\d+\s+on\s+(\S+)/s,
                },
                Actions => [
                    q|sub{  my $args = shift;
                            my $event = shift;

                            my $modT = main::getModule('TIMERS') or return;
                            my $timer  = $modT->getTimerByPos($modT->{svdrp}->IDfromHostname($args->{host}), $args->{pos}) or return;

                            my $autotimer = getDataById($timer->{autotimerid}, 'AUTOTIMER', 'Id');
                            my $title = sprintf(gettext("Autotimer '%s' found: %s"),
                                                    $autotimer->{Search}, $timer->{file});
                            $modT->_news($title, $timer, $event->{Level});
                        }
                    |,
                ],

            },
        },
    };
    return $args;
}

# ------------------
# Name:  status
# Descr: Standardsubroutine to report statistical data for Report Plugin.
# Usage: my $report = $obj->status($console);
# ------------------
sub status {
    my $obj = shift || return error('No object defined!');
    my $lastReportTime = shift || 0;

    my %f = (
        'title' => gettext('Title'),
        'day' => gettext('Day'),
        'channel' => gettext('Channel'),
        'start' => gettext('Start'),
        'stop' => gettext('Stop'),
        'priority' => gettext('Priority')
    );

    my $sql = qq|
SELECT SQL_CACHE 
    t.id as __id,
    t.file as \'$f{'title'}\',
    t.flags as __flags,
    c.Name as \'$f{'channel'}\',
    c.Pos as __Pos,
    UNIX_TIMESTAMP(t.starttime) as \'$f{'day'}\',
    t.start as \'$f{'start'}\',
    t.stop as \'$f{'stop'}\',
    t.priority as \'$f{'priority'}\',
    UNIX_TIMESTAMP(t.starttime) as __day,
    t.collision as __collision,
    t.eventid as __eventid,
    t.autotimerid as __autotimerid
FROM
    TIMERS as t,
    CHANNELS as c
WHERE
    t.channel = c.Id
    and UNIX_TIMESTAMP(t.addtime) > ?
    and t.autotimerid > 0
    AND t.vid = c.vid
ORDER BY
    t.starttime|;

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($lastReportTime)
        or return error "Couldn't execute query: $sth->errstr.";
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();
    for(@$erg) {
        $_->[5] = datum($_->[5],'weekday');
        $_->[6] = fmttime($_->[6]);
        $_->[7] = fmttime($_->[7]);
    }
    unshift(@$erg, $fields);

    return {
        message => sprintf(gettext('Autotimer has programmed %d new timer(s) since last report to %s'),
            (scalar @$erg - 1), datum($lastReportTime)),
        table   => $erg,
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
    my $erg = $self->_init or return error('Problem to initialize module');

	return $self;
}

# ------------------
sub _init {
# ------------------
    my $obj = shift || return error('No object defined!');

    unless($obj->{dbh}) {
      panic("Session to database is'nt connected");
      return 0;
    }

    my $version = main::getDBVersion();
    # don't remove old table, if updated rows => warn only
    if(!tableUpdated($obj->{dbh},'AUTOTIMER',$version,0)) {
      return 0;
    }

    # Look for table or create this table
    $obj->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS AUTOTIMER (
          Id int(11) unsigned auto_increment NOT NULL,
          Activ enum('y', 'n') default 'y',
          Done set('timer', 'recording', 'chronicle' ) NOT NULL default 'timer', 
          Search text NOT NULL default '',
          InFields set('title', 'subtitle', 'description' ) NOT NULL,
          Channels text default '',
          Start char(4) default '0000',
          Stop  char(4) default '0000',
          MinLength tinyint default NULL,
          Priority tinyint(2) default NULL,
          Lifetime tinyint(2) default NULL,
          Dir text,
          VPS enum('y', 'n') default 'n',
          prevminutes tinyint default NULL,
          afterminutes tinyint default NULL,
          Weekdays set('Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'),
          startdate datetime default NULL,
          stopdate datetime default NULL,
          count int(11) default NULL,
          keywords text,
          PRIMARY KEY  (Id)
        ) COMMENT = '$version'
    |);

    main::after(sub{
        $obj->{keywords} = main::getModule('KEYWORDS');
        unless($obj->{keywords}) {
           return 0;
        }
        my $modE = main::getModule('EPG');
        $modE->updated(
         sub{
          my $console = shift;
          my $waiter = shift;

          return 0 if($obj->{active} ne 'y');

          lg 'Start autotimer callback to find new events!';
          return $obj->_autotimerLookup($console,$waiter);

        },"AUTOTIMER: Callback to compare epg data ...");
        return 1;
    }, "AUTOTIMER: Install callback to compare epg data ...", 30);

    return 1;
}

# ------------------
# Name:  autotimer
# Descr: Routine to parse the EPG Data for users Autotimer.
#        If Autotimerid given, then will this search only
#        for this Autotimer else for all.
# Usage: $obj->autotimer([$autotimerid]);
# ------------------
sub autotimer {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $autotimerid = shift;

    my $waiter;
    if(ref $console && !$autotimerid && $console->typ eq 'HTML') {
        $waiter = $console->wait(gettext("Searching for autotimer ..."),0,1000,'no');
    }

    my ($log,$C,$M) = $obj->_autotimerLookup($console,$waiter,$autotimerid);

    # last call of waiter
    $waiter->end() if(ref $waiter);

    if(ref $console) {
        $console->start() if(ref $waiter);
        unshift(@{$log},sprintf(gettext("Autotimer process created %d timers and modified %d timers."), $C, $M));
        lg join("\n", @$log);
        $console->message($log);
        $console->link({
            text => gettext("Back to autotimer listing."),
            url => "?cmd=alist",
        }) if($console->typ eq 'HTML');
    }

    return 1;
}
sub _autotimerLookup {
    my $obj = shift || return error('No object defined!');
    my $console = shift;
    my $waiter = shift;
    my $autotimerid = shift;

    # Get Autotimer
    my $sth;
    if($autotimerid) {
        $sth = $obj->{dbh}->prepare('SELECT SQL_CACHE * from AUTOTIMER where Activ = "y" AND Id = ? order by Id');
        $sth->execute($autotimerid)
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    } else {
        $sth = $obj->{dbh}->prepare('SELECT SQL_CACHE * from AUTOTIMER where Activ = "y" order by Id');
        $sth->execute()
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    }
    my $att = $sth->fetchall_hashref('Id');

    # Adjust waiter max value now.
    $waiter->max(scalar keys %$att)
        if(ref $console && ref $waiter);

    my $l = 0; # Lines for Waiter
    my $C = 0; # Total of created and modifed timers
    my $M = 0;
    my $log;

    # Search only for event there added since last runtime.
    # and search not with TEMPEPG at manual running
    my $addtime = ((not ref $console) && ($obj->{addtime})) ? $obj->{addtime} : 0;
    $obj->{addtime} = time unless($autotimerid);

    &bench('AUTOTIMER');
    if($addtime) {

      # Remove old data
      $obj->{dbh}->do('DELETE FROM TEMPEPG');

      # Copy only new events from EPG to TEMPEPG, to speed up search
      my $sql = qq|INSERT INTO TEMPEPG SELECT e.* FROM EPG as e, CHANNELS as c
                   WHERE e.addtime >= FROM_UNIXTIME(?)|;

      # Exclude unwanted channels
      if($obj->{exclude}) {
          $sql .= sprintf(' AND ( e.channel_id = c.id AND e.vid = c.vid ) AND NOT (c.%s)', 
                  $obj->{exclude});
      }

      my $sth = $obj->{dbh}->prepare($sql)
        or return error sprintf("Couldn't prepare query: %s.",$sql);
      $sth->execute($addtime)
        or return error sprintf("Couldn't execute query: %s\r\n%s.",$sth->errstr,$sql);
    }

    my $now = time;
    # Get Timersmodule
    my $modT = main::getModule('TIMERS');
    $modT->_readData();

    foreach my $id (sort keys %$att) {
        my $a = $att->{$id};

        $waiter->next(++$l, undef, sprintf(gettext("Search for autotimer '%s'"), $a->{Search}))
          if(ref $waiter);

        if(ref $console && $autotimerid) {
            $console->message(' ') if($console->{TYP} eq 'HTML');
            $console->message(sprintf(gettext("Search for autotimer '%s'"), $a->{Search}));
        }

        # Build SQL Command and run it ....
        my $events = $obj->_eventsearch($a, $modT, $addtime ) || next;

        # Only search for one at?
        if(ref $console && $autotimerid) {
            $console->message(sprintf(gettext("Found %d entries for '%s' in EPG database."), $events ? scalar @$events : 0, $a->{Search}));
            foreach my $event (@{$events}) {

              my $output = [   [gettext("Title"),     $event->{title}] ];
              push(@$output,   [gettext("Subtitle"),  $event->{subtitle}])
                if($event->{subtitle});
              push(@$output,   [gettext("Channel"),   $event->{channelname}]);

              if($event->{vpsstart} and $a->{VPS} eq 'y' and $modT->{usevpstime} eq 'y') {
                push(@$output, [gettext("Start"),     datum($event->{vpsstart} )]);
                push(@$output, [gettext("Stop"),      datum($event->{vpsstop}  )]);
              } else {
                push(@$output, [gettext("Start"),     datum($event->{starttime})]);
                push(@$output, [gettext("Stop"),      datum($event->{stoptime} )]);
              }
              push(@$output,[gettext("Description"),  $event->{description}])
                if($event->{description});
              $console->table($output);
            };
        }

        my @done;
        @done = split(',', $a->{Done}) if($a->{Done});

        # Every found and save this as timer
        my $c = 0;
        my $m = 0;
        foreach my $event (@{$events}) {

            $event->{active} = 'y';
            $event->{priority} = $a->{Priority};
            $event->{lifetime} = $a->{Lifetime};

            if($event->{vpsstart} and $a->{VPS} eq 'y' and $modT->{usevpstime} eq 'y') {
              $event->{vps} = 'y';
 	            $event->{starttime} = $event->{vpsstart};
 	            $event->{stoptime} = $event->{vpsstop};
            } else {
              $event->{vps} = 'n';
            }

            # ignore outdated event
            next if($event->{stoptime} < $now);
            
            # remove seconds from time 12:00:30 => 12:00:00
            $event->{starttime} -= ($event->{starttime} % 60);
            $event->{stoptime}  -= ($event->{stoptime} % 60);

            my ($bsec,$bmin,$bhour,$bmday,$bmon,$byear,$bwday,$byday,$bisdst) = localtime($event->{starttime});
            my ($esec,$emin,$ehour,$emday,$emon,$eyear,$ewday,$eyday,$eisdst) = localtime($event->{stoptime});

            $event->{day} = sprintf("%04d-%02d-%02d",$byear+1900,$bmon+1,$bmday);
            $event->{start} = sprintf("%02d%02d",$bhour,$bmin);
            $event->{stop}  = sprintf("%02d%02d",$ehour,$emin);

            my $keywords;
            ($event->{file},$keywords) = $obj->_placeholder($event, $a);
            $event->{keywords} = $keywords if($keywords && $obj->{keywords}->{active} eq 'y');

            # Add anchor for reidentify timer
            my $args = {
             'autotimer' => $id,
#            'eventid' => $eventid
            };
            $event->{aux} = $obj->{keywords}->createxml($args);
            
            # Wished timer already exist with same data from autotimer ?
            next if($obj->_timerexists($event));

            # Adjust timers set by Autotimer
            my $timerID = $obj->_timerexistsfuzzy($event,$a,$modT);

            if(scalar @done) {
                my $title = lc($event->{file});
                $title =~ s/[\-\ ]//g;

                # Ignore timer if it already with same title recorded
                if(grep(/^chronicle$/, @done) && $obj->_chronicleexists($title)) {
                  lg sprintf("Don't create timer from AT(%d) '%s', because found same data on chronicle", $id, $event->{file});
                  next;
                }

                # Ignore timer if it already with same title recorded
                if(grep(/^recording$/, @done) && $obj->_recordexists($title)){
                  lg sprintf("Don't create timer from AT(%d) '%s', because found same data on recordings", $id, $event->{file});
                  next;
                }
                # Ignore timer if it already a timer with same title programmed, on other place
                if(grep(/^timer$/, @done) && $obj->_timerexiststitle($title)){
                  lg sprintf("Don't create timer from AT(%d) '%s', because found same data on other timers", $id, $event->{file});
                  next;
                }
            }

            if($timerID) {
              ($event->{vid},$event->{pos}) = $modT->getPos($timerID);
            }
            my ($erg,$error) = $modT->saveTimer($event);
            if($error) {
                $console->err(sprintf(gettext("Could not save timer for '%s' : %s"), $event->{file}, $error))
                  if(ref $console && $autotimerid);
            } else {
                if($timerID) {
                  ++$m;
                  $console->message(sprintf(gettext("Modified timer for '%s'."), $event->{file}))
                    if(ref $console && $autotimerid);
                } else {
                  ++$c;
                  $console->message(sprintf(gettext("Timer for '%s' has been created."), $event->{file}))
                    if(ref $console && $autotimerid);
                }
            }
        }
        $C += $c;
        $M += $m;
        if($c) {
            my $msg = sprintf(gettext("Created %d timer for '%s'."), $c, $a->{Search});
            if(ref $console && $autotimerid) {
                $console->message($msg);
            }
            else {
                push(@{$log},$msg);
            }
        }
        if($m) {
            my $msg = sprintf(gettext("Modified %d timer for '%s'."), $m, $a->{Search});
            if(ref $console && $autotimerid) {
                $console->message($msg);
            }
            else {
                push(@{$log},$msg);
            }
        }
    }

    &bench('AUTOTIMER');
    my $seconds = &bench()->{'AUTOTIMER'};
    lg sprintf("Runtime %s seconds", $seconds);
    

    $waiter->next(undef,undef,gettext('Read new timers into database.'))
      if(ref $waiter);

    sleep 1;

    $modT->_readData();

    return (\@{$log},$C,$M);
}
# ------------------
# Name:  autotimerCreate
# Descr: Routine to display the create form for Autotimer.
# Usage: $obj->autotimerCreate($console, [$userdata]);
# ------------------
sub autotimerCreate {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || 0;
    my $data    = shift || 0;

    $obj->autotimerEdit($console, $config, $timerid, $data);
}

# ------------------
# Name:  autotimerEdit
# Descr: Routine to display the edit form for Autotimer.
# Usage: $obj->autotimerEdit($console, [$atid], [$userdata]);
# ------------------
sub autotimerEdit {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || 0;
    my $data    = shift || 0;

    my $modC = main::getModule('CHANNELS');
    my $modT = main::getModule('TIMERS');

    my $epg;
    if($timerid and not ref $data) {
        my $sth = $obj->{dbh}->prepare("SELECT SQL_CACHE * from AUTOTIMER where Id = ?");
        $sth->execute($timerid)
            or return $console->err(sprintf(gettext("Autotimer '%s' does not exist in the database!"),$timerid));
        $epg = $sth->fetchrow_hashref();

            # Channels Ids in Namen umwandeln
            if($epg->{Channels}) {
              my @channels = split(/[\s|,]+/, $epg->{Channels});
              $epg->{Channels} = \@channels;
            }

            # question erwartet ein Array
            my @done = split(/\s*,\s*/, $epg->{Done});
            $epg->{Done} = \@done;
            my @infields = split(/\s*,\s*/, $epg->{InFields});
            $epg->{InFields} = \@infields;
            my @weekdays = split(/\s*,\s*/, $epg->{Weekdays});
            $epg->{Weekdays} = \@weekdays;

    } elsif (ref $data eq 'HASH') {
        $epg = $data;
    }

    my %wd = (
        'Mon' => gettext('Mon'),
        'Tue' => gettext('Tue'),
        'Wed' => gettext('Wed'),
        'Thu' => gettext('Thu'),
        'Fri' => gettext('Fri'),
        'Sat' => gettext('Sat'),
        'Sun' => gettext('Sun')
    );

    my %in = (
        'title' => gettext('Title'),
        'subtitle' => gettext('Subtitle'),
        'description' => gettext('Description')
    );

    my %do = (
        'timer' => gettext('Timer'),
        'recording' => gettext('Existing recording'),
        'chronicle' => gettext('Recording chronicle')
    );
    my $DoneChoices = [$do{'timer'}, $do{'recording'}];

    # Enable option "chronicle" only if activated.
    my $modCH  = main::getModule('CHRONICLE');
    push(@$DoneChoices, $do{'chronicle'})
      if($modCH and $modCH->{active} eq 'y');

    my $questions = [
        'Id' => {
            typ     => 'hidden',
            def     => $epg->{Id} || 0,
        },
        'Activ' => {
            typ     => 'confirm',
            def     => $epg->{Activ} || 'y',
            msg     => gettext('Activate this autotimer'),
        },
        'Search' => {
            msg   => 
gettext("Search terms to search for EPG entries.
You can also fine tune your search :
* by adding 'operators' to your search terms such as 'AND', 'OR', 'AND NOT' e.g. 'today AND NOT tomorrow'
* by comma-separated search terms e.g. 'today,tomorrow'
* by a hyphen to exclude search terms e.g. 'today,-tomorrow'"),
            def   => $epg->{Search} || '',
        },
        'InFields' => {
            msg   => gettext('Search in this EPG fields'),
            typ   => 'checkbox',
            choices   => [$in{'title'}, $in{'subtitle'}, $in{'description'}],
            req   => gettext('This is required!'),
            def   => sub {
                            my $value = $epg->{InFields} || ['title','subtitle'];
                            my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                            my $ret;
                            foreach my $v (@vals) {
                                push(@$ret,$in{$v});
                            }
                            return $ret;
                          },
            check   => sub{
                my $value = shift || return;
                my $data = shift || return error('No Data in CB');
                my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                my @ret;
                foreach my $v (@vals) {
                    unless(grep($_ eq $v, @{$data->{choices}})) {
                        my $ch = join(' ', @{$data->{choices}});
                        return undef, sprintf(gettext("You can choose: %s!"),$ch);
                    }
                    foreach my $k (keys %in) {
                        push(@ret,$k)
                            if($v eq $in{$k});
                    }
                }
                return join(',', @ret);
            },
        },
        'Channels' => {
            typ     => 'list',
            def     => $epg->{Channels},
            choices => $modC->ChannelWithGroup('c.name,c.id', sprintf(' NOT (c.%s)', $obj->{exclude})),
            options => 'multi',
            msg     => gettext('Limit search to these channels'),
            check   => sub{
                my $value = shift || return;
                my @vals;
                foreach my $chname ((ref $value eq 'ARRAY' ? @$value : split(/\s*,\s*/, $value))) {
                    if( my $chid = $modC->ToCID($chname)) {
                        push(@vals, $chid);
                    } else {
                        return undef, sprintf(gettext("The channel '%s' does not exist!"),$chname);
                    }
                }
                return join(',', @vals);
            },
        },
        'Done' => {
            msg   => gettext('Ignore retries with same title?'),
            typ   => 'checkbox',
            choices   => $DoneChoices,
            def   => sub {
                            my $value = $epg->{Done};
                            my $ret;
                            if($value) {
                              my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                              foreach my $v (@vals) {
                                  push(@$ret,$do{$v});
                              }
                            }
                            return $ret;
                          },
            check   => sub{
                my $value = shift || '';
                my $data = shift || return error('No Data in CB');
                my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                my @ret;
                foreach my $v (@vals) {
                    unless(grep($_ eq $v, @{$data->{choices}})) {
                        my $ch = join(' ', @{$data->{choices}});
                        return undef, sprintf(gettext("You can choose: %s!"),$ch);
                    }
                    foreach my $k (keys %do) {
                        push(@ret,$k)
                            if($v eq $do{$k});
                    }
                }
                return join(',', @ret);
            },
        },
         'Start' => {
             typ     => 'time',
             def     => sub{
		             my $value = $epg->{Start} || return "";
                     return fmttime($value);
                 },
             msg     => gettext("Start time in format 'HH:MM'"),
             check   => sub{
                 my $value = shift || 0;
                 return undef, gettext('You set a start time without an end time!')
                    if(not $data->{Stop} and $value);
        		 return "" if(not $value);
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
         'Stop' => {
             typ     => 'time',
             def     => sub{
    		         my $value = $epg->{Stop} || return "";
                     return fmttime($value);
                 },
             msg     => gettext("End time in format 'HH:MM'"),
             check   => sub{
                 my $value = shift || 0;
                 return undef, gettext('You set an end time without a start time!')
                    if(not $data->{Start} and $value);
        		 return "" if(not $value);
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
        'Weekdays' => {
            msg   => gettext('Only search these weekdays'),
            typ   => 'checkbox',
            choices   =>  [$wd{'Mon'}, $wd{'Tue'}, $wd{'Wed'}, $wd{'Thu'}, $wd{'Fri'}, $wd{'Sat'}, $wd{'Sun'}],
            def   => sub {
                            my $value = $epg->{Weekdays} || ['Mon','Tue','Wed','Thu','Fri','Sat','Sun'];
                            my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                            my $ret;
                            foreach my $v (@vals) {
                                push(@$ret,$wd{$v});
                            }
                            return $ret;
                          },
            check   => sub{
                my $value = shift || [$wd{'Mon'}, $wd{'Tue'}, $wd{'Wed'}, $wd{'Thu'}, $wd{'Fri'}, $wd{'Sat'}, $wd{'Sun'}];
                my $data = shift || return error('No Data in CB');
                my @vals = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
                my @ret;
                foreach my $v (@vals) {
                    unless(grep($_ eq $v, @{$data->{choices}})) {
                        my $ch = join(' ', @{$data->{choices}});
                        return undef, sprintf(gettext("You can choose: %s!"),$ch);
                    }
                    foreach my $k (keys %wd) {
                        push(@ret,$k)
                            if($v eq $wd{$k});
                    }
                }
                return join(',', @ret);
            },
        },
        'VPS' => {
            typ     => $modT->{usevpstime} eq 'y' ? 'confirm' : 'hidden',
            def     => $epg->{VPS} || 'n',
            msg     => gettext('Use PDC time to control created timer'),
        },
        'prevminutes' => {
            typ     => 'integer',
            msg     => gettext('Buffer time in minutes before the scheduled start of a recording'),
            def     => $epg->{prevminutes},
            check   => sub{
                my $value = shift;
                return if($value eq "");
                if($value =~ /^\d+$/sig and $value >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'afterminutes' => {
            typ     => 'integer',
            msg     => gettext('Buffer time in minutes past the scheduled end of a recording'),
            def     => $epg->{afterminutes},
            check   => sub{
                my $value = shift;
                return if($value eq "");
                if($value =~ /^\d+$/sig and $value >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'MinLength' => {
            typ     => 'integer',
            msg     => gettext('Minimum play time in minutes'),
            def     => $epg->{MinLength} || 0,
            check   => sub{
                my $value = shift || return;
                if($value =~ /^\d+$/sig and $value > 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'Priority' => {
            typ     => 'integer',
            msg     => sprintf(gettext('Priority (%d ... %d)'),0,$console->{USER}->{MaxPriority} ? $console->{USER}->{MaxPriority} : 99 ),
            def     => (defined $epg->{Priority} ? $epg->{Priority} : $modT->{Priority}),
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
        'Lifetime' => {
            typ     => 'integer',
            msg     => sprintf(gettext('Lifetime (%d ... %d)'),0,$console->{USER}->{MaxLifeTime} ? $console->{USER}->{MaxLifeTime} : 99 ),
            def     => (defined $epg->{Lifetime} ? $epg->{Lifetime} : $modT->{Lifetime}),
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
        'Dir' => {
						typ 		=> 'string',
            msg     => gettext('Group all recordings into one directory'),
            def     => $epg->{Dir}
        },
        'startdate' => {
            typ     => 'string',
            def     => sub{
                # Convert day from mysql format to locale format
                my $value = $epg->{startdate};
                if($value and $value =~ /^\d{4}\-\d{2}-\d{2}/) {
              		return "" if($value eq '0000-00-00 00:00:00');
                  Date_Init("Language=English");
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,gettext('%Y-%m-%d %H:%M:%S'));
                    return $t if($t);
                  }
                }
                return $value;
            },
            msg     => gettext("Start date as YYYY-MM-DD HH:MM:SS."),
            check   => sub{
                my $value = shift;
            		return "" if(not $value);
                # Convert locale format to mysql format %Y-%m-%d
                if($value and $value =~ /^\d+/) {
              		return "" if($value eq '0000-00-00 00:00:00');
                  Date_Init(split(',',gettext("Language=English")));
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,'%Y-%m-%d %H:%M:%S');
                    return $t if($t);
                  }
                }
                return undef, gettext('The day is incorrect or was in a wrong format!');
            },
        },
        'stopdate' => {
            typ     => 'string',
            def     => sub{
                # Convert day from mysql format to locale format
                my $value = $epg->{stopdate};
                if($value and $value =~ /^\d{4}\-\d{2}-\d{2}/) {
              		return "" if($value eq '0000-00-00 00:00:00');
                  Date_Init("Language=English");
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,gettext('%Y-%m-%d %H:%M:%S'));
                    return $t if($t);
                  }
                }
                return $value;
            },
            msg     => gettext("Stop date as YYYY-MM-DD HH:MM:SS."),
            check   => sub{
                my $value = shift;
            		return "" if(not $value);
                # Convert locale format to mysql format %Y-%m-%d
                if($value and $value =~ /^\d+/) {
                  Date_Init(split(',',gettext("Language=English")));
                  my $d = ParseDate($value);
                  if($d) {
                    my $t = UnixDate($d,'%Y-%m-%d %H:%M:%S');
                    return $t if($t);
                  }
                }
                return undef, gettext('The day is incorrect or was in a wrong format!');
            },
        },
        'keywords' => {
            typ     => $obj->{keywords}->{active} eq 'y' ? 'string' : 'hidden',
            def     => $epg->{keywords},
            msg     => gettext('Add keywords to recording'),
        },
    ];

    # Ask Questions
    $data = $console->question(($timerid ? gettext('Edit autotimer')
					 : gettext('Create new autotimer')), $questions, $data);

    if(ref $data eq 'HASH') {
        delete $data->{Channel};

    	$obj->_insert($data);

    	$data->{Id} = $obj->{dbh}->selectrow_arrayref('SELECT SQL_CACHE max(ID) FROM AUTOTIMER')->[0]
    		if(not $data->{Id});

        $console->message(gettext('Autotimer saved!'));
        debug sprintf('%s autotimer with search "%s" is saved%s',
            ($timerid ? 'Changed' : 'New'),
            $data->{Search},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );
        $obj->autotimer($console, $config, $data->{Id});
    }
    return 1;
}

# ------------------
# Name:  autotimerDelete
# Descr: Routine to display the delete form for Autotimer.
# Usage: $obj->autotimerDelete($console, $atid);
# ------------------
sub autotimerDelete {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || return $console->err(gettext("No autotimer defined for deletion! Please use adelete 'aid'!"));   # If timerid the edittimer

    my @timers  = reverse sort{ $a <=> $b } split(/[^0-9]/, $timerid);

    my $sql = sprintf('DELETE FROM AUTOTIMER where Id in (%s)', join(',' => ('?') x @timers)); 
    my $sth = $obj->{dbh}->prepare($sql);
    my $rows = $sth->execute(@timers);
    if(!$rows || $rows eq "0E0") {
        error sprintf("Couldn't execute query: %s.",$sth->errstr) unless($rows);
        $console->err(sprintf gettext("Autotimer '%s' does not exist in the database!"), join(',', @timers));
        return 0;
    }

    $console->message(sprintf gettext("Autotimer %s deleted."), join(',', @timers));
    debug sprintf('autotimer with id "%s" is deleted%s',
        join(',', @timers),
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );
    $console->redirect({url => '?cmd=alist', wait => 1})
        if($console->typ eq 'HTML');
}

# ------------------
# Name:  autotimerToggle
# Descr: Switch Autotimer on or off.
# Usage: $obj->autotimerToggle($console, $atid);
# ------------------
sub autotimerToggle {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $timerid = shift || return $console->err(gettext("No autotimer defined to toggle! Please use atoggle 'aid'!"));

    my @timers  = reverse sort{ $a <=> $b } split(/[^0-9]/, $timerid);

    my $sql = sprintf('SELECT SQL_CACHE Id,Activ FROM AUTOTIMER where Id in (%s)', join(',' => ('?') x @timers)); 
    my $sth = $obj->{dbh}->prepare($sql);
    if(!$sth->execute(@timers)) {
        error sprintf("Couldn't execute query: %s.",$sth->errstr);
        $console->err(sprintf(gettext("Autotimer '%s' does not exist in the database!"),$timerid));
        return 0;
    }
    my $data = $sth->fetchall_hashref('Id');

    my $erg;
    for my $timer (@timers) {

        unless(exists $data->{$timer}) {
            $console->err(sprintf(gettext("Autotimer '%s' does not exist in the database!"), $timer));
            next;
        }

        my $status = (($data->{$timer}->{Activ} eq 'n' ) ? 'y' : 'n');

        my $sql = "UPDATE AUTOTIMER set Activ = ? where Id = ?"; 
        my $sth = $obj->{dbh}->prepare($sql);
        if(!$sth->execute($status,$timer)) {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
            $console->err(sprintf(gettext("Couldn't update database to toggle autotimer(%d) !"),$timer));
            next;
        }

        debug sprintf('Autotimer with id "%s" is %s%s',
            $timer,
            ($status eq 'n' ? 'disabled' : 'activated'),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        if($console->typ ne 'AJAX') {
            if($status eq 'n') {
              $console->message(sprintf gettext("Autotimer %s is disabled."), $timer);
            } else {
              $console->message(sprintf gettext("Autotimer %s is activated."), $timer);
            }
        }

        # AJAX 
        push(@$erg,[$timer,($status eq 'n' ? 0 : 1),0,0]);
    }

    $console->redirect({url => '?cmd=alist', wait => 1})
        if($console->typ eq 'HTML');

    if($console->typ eq 'AJAX') {
      # { "data" : [ [ ID, ON, RUN, CONFLICT ], .... ] }
      # { "data" : [ [ 5, 1, 0, 0 ], .... ] }
      $console->table($erg);
    }

}

# ------------------
# Name:  list
# Descr: List Autotimers in a table display.
# Usage: $obj->list($console, [$atid], [$params]);
# ------------------
sub list {
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text      = shift || '';
    my $params  = shift;

	  my $term;
	  my $search = '';
	  if($text and $text =~ /^[0-9,_ ]+$/ ) {
      my @timers  = split(/[^0-9]/, $text);
      $search = sprintf(" WHERE Id in (%s)",join(',' => ('?') x @timers));
      foreach(@timers) { push(@{$term},$_); }

	  } elsif($text) {
      my $query = buildsearch("Search,Dir",$text);
      $search = sprintf('WHERE %s', $query->{query});
      foreach(@{$query->{term}}) { push(@{$term},$_); }
	  }

    my %f = (
        'Id' => gettext('Service'),
        'Active' => gettext('Active'),
        'Search' => gettext('Search'),
        'Channels' => gettext('Channels'),
        'Start' => gettext('Start time'),
        'Stop' => gettext('Stop time'),
        'Dir' => gettext('Directory'),
        'MinLength' => gettext('Minimum length'),
    );

    my $sql = qq|
    SELECT SQL_CACHE 
      Id as \'$f{'Id'}\',
      Activ as \'$f{'Active'}\',
      Search as \'$f{'Search'}\',
      Channels as \'$f{'Channels'}\',
      Dir as \'$f{'Dir'}\',
      Start as \'$f{'Start'}\',
      Stop as \'$f{'Stop'}\',
      MinLength as \'$f{'MinLength'}\'
    FROM
      AUTOTIMER
    $search
    ORDER BY
    |;

    my $sortby = "Search";
    if(exists $params->{sortby}) {
      while(my($k, $v) = each(%f)) {
        if($params->{sortby} eq $k or $params->{sortby} eq $v) {
          $sortby = $k;
          last;
        }
      }
    }
    $sql .= $sortby;
    $sql .= " desc"
        if(exists $params->{desc} && $params->{desc} == 1);

    my $rows;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $obj->{dbh}->prepare($sql);
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
      $sth = $obj->{dbh}->prepare($sql);
      $sth->execute(@{$term})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();


    my $exclude;
    if($obj->{exclude}) {
        $sql .= sprintf('NOT (%s)', $obj->{exclude});
    }
    my $channels = main::getModule('CHANNELS')->ChannelHash('id',$exclude);

    map {
        if($_->[3]) {
          my @ch;
          foreach my $c (split(',',$_->[3])) {
            my $name = $channels->{$c} ? $channels->{$c}->{'name'} : undef;
            unless($name) {
              $name = sprintf(gettext('Unknown channel : %s'),$c);
            }
            push(@ch, $name);
          }
          $_->[3] = join(',',@ch);
        }
        $_->[5] = fmttime($_->[5]);
        $_->[6] = fmttime($_->[6]);
    } @$erg;

    unless($console->typ eq 'AJAX') {
      unshift(@$erg, $fields);
    }

    my $info = {
      rows => $rows
    };
    if($console->typ eq 'HTML') {
      $info->{sortable} = '1';
      $info->{timers} = main::getModule('TIMERS')->getTimersByAutotimer();
    }

    $console->setCall('alist');
    $console->table($erg, $info );
}


# ------------------
sub _eventsearch {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $a   = shift  || return error('No data defined!');
    my $modT = shift || return error('No timer modul defined!');
    my $addtime = shift;

    my $query;
    my $search = '1';
    my $term = [];
  
    if($a->{Search}) {
      $query = buildsearch($a->{InFields}, $a->{Search});
      $search = $query->{query};
      $term = $query->{term};
    }

    $a->{startdate} = 0 if($a->{startdate} && $a->{startdate} eq '0000-00-00 00:00:00');
    $a->{stopdate} = 0  if($a->{stopdate}  && $a->{stopdate}  eq '0000-00-00 00:00:00');
    if($a->{startdate} and $a->{stopdate}) {
      $search .= "\n AND (e.starttime > ? AND e.starttime < ?)";
      push(@{$term},$a->{startdate});
      push(@{$term},$a->{stopdate});    
    } elsif($a->{startdate}) {
      $search .= "\n AND (e.starttime > ?)";
      push(@{$term},$a->{startdate});
    } elsif($a->{stopdate}) {
      $search .= "\n AND (e.starttime < ?)";
      push(@{$term},$a->{stopdate});
    }

    # Start and Stop
    if($a->{Start} and $a->{Stop}) {
        if($a->{Start} > $a->{Stop}) {
            $search .= "\n AND ((DATE_FORMAT(e.starttime, '%H%i') > ? AND DATE_FORMAT(e.starttime, '%H%i') < 2359) OR (DATE_FORMAT(e.starttime, '%H%i') >= 0 and DATE_FORMAT(e.starttime, '%H%i') < ?))";
        } else {
            $search .= "\n AND (DATE_FORMAT(e.starttime, '%H%i') > ? AND DATE_FORMAT(e.starttime, '%H%i') < ?)";
        }
        push(@{$term},$a->{Start});
        push(@{$term},$a->{Stop});    
    }

    # Min Length
    if(exists $a->{MinLength} and $a->{MinLength}) {
        $search .= " AND e.duration >= ?";
        push(@{$term},$a->{MinLength} * 60);    
    }

    # Channels
    if($a->{Channels} and my @channelids = split(',', $a->{Channels})) {
        $search .= sprintf(" AND channel_id in (%s)",join(',' => ('?') x @channelids));
        foreach(@channelids) {
          push(@{$term},$_);
        }
    }

    # Weekdays
    if($a->{Weekdays} and my @weekdays = split(',', $a->{Weekdays})) {
        if(scalar @weekdays != 7 and scalar @weekdays != 0) {
          $search .= sprintf(" AND DATE_FORMAT(e.starttime, \'%%a\') in (%s)",join(',' => ('?') x @weekdays));
          foreach(@weekdays) {
            push(@{$term},$_);
          }
        }
    }

    # Exclude channels, ifn't already lookup for channels
    if($obj->{exclude} && not $a->{Channels} && not $addtime) {
        $search .= sprintf(' AND NOT (c.%s)', $obj->{exclude});
    }

	# Custom time range
	my $after = 0;
	my $prev = 0;
#	if($a->{VPS} ne 'y') {
	  if(defined $a->{prevminutes}) {
			$prev = $a->{prevminutes} * 60;
		} else {
			$prev = $modT->{prevminutes} * 60;
		}
		if(defined $a->{afterminutes}) {
			$after = $a->{afterminutes} * 60;
		} else {
			$after = $modT->{afterminutes} * 60;
		}
#	}

    my $table = $addtime ? 'TEMPEPG' : 'EPG';

    # Search for events
    my $sql = qq|
SELECT SQL_CACHE 
    e.eventid as eventid,
    e.vid,
    e.channel_id as channel,
    c.Name as channelname,
    e.title as title,
    e.subtitle as subtitle,
    e.description as description,
    (UNIX_TIMESTAMP(e.starttime) - ? ) as starttime,
    (UNIX_TIMESTAMP(e.starttime) + e.duration + ?) as stoptime,
    UNIX_TIMESTAMP(e.vpstime) as vpsstart,
    (UNIX_TIMESTAMP(e.vpstime) + e.duration) as vpsstop
FROM
    $table as e,
    CHANNELS as c
WHERE
    ( $search )
    AND ( e.channel_id = c.id )
    AND ( e.vid = c.vid )
GROUP BY
    c.id , e.eventid
ORDER BY
    e.starttime asc,
    e.eventid desc
    |;

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($prev,$after,@{$term})
      or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $lst;
    while (my $erg = $sth->fetchrow_hashref()) {
      push(@$lst,$erg);
    }
    return $lst;
}

# ------------------
sub _timerexists {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $eventdata = shift  || return error('No data defined!');

    # Avoid Timer already defined (the timer with the same data again do not put on)
    my $sql = "SELECT SQL_CACHE count(*) as cc from TIMERS where
                channel = ?
                AND ((UNIX_TIMESTAMP(starttime) = ?
                AND UNIX_TIMESTAMP(stoptime) = ?)
                OR eventid = ?)";

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($eventdata->{channel},
                  $eventdata->{starttime},$eventdata->{stoptime},
                  $eventdata->{eventid}
                  )
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg->{cc} 
        if($erg);
    return 0;

}

# ------------------
sub _timerexistsfuzzy {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $eventdata = shift  || return error('No data defined!');
    my $a   = shift  || return error('No data defined!');
    my $modT = shift || return error('No timer modul defined!');

	  my $after = 0;
	  my $prev = 0;
    if(defined $a->{prevminutes}) {
		  $prev = $a->{prevminutes} * 60;
	  } else {
		  $prev = $modT->{prevminutes} * 60;
	  }
	  if(defined $a->{afterminutes}) {
		  $after = $a->{afterminutes} * 60;
	  } else {
		  $after = $modT->{afterminutes} * 60;
	  }

    # Adjust timers set by Autotimer, if event changed +/- five minutes. 
    my $sql = "SELECT SQL_CACHE id from TIMERS where
                channel = ?
                and ? between (UNIX_TIMESTAMP(starttime) - ?) AND (UNIX_TIMESTAMP(starttime) + ?)
                and ? between (UNIX_TIMESTAMP(stoptime)  - ?) AND (UNIX_TIMESTAMP(stoptime) + ?)
                and file like ?
                and aux like ?";

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($eventdata->{channel},
                  $eventdata->{starttime},$prev,$prev,
                  $eventdata->{stoptime},$after,$after,
                  $eventdata->{file}."%",
                  "%".$eventdata->{aux})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg->{id} 
        if($erg);
    return 0;
}

# ------------------
sub _recordexists {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $title = shift  || return error('No title defined!');

    # Ignore timer if it already with same title recorded
    my $sql = "SELECT SQL_CACHE count(*) as cc
                FROM RECORDS as r, OLDEPG as e
                WHERE e.eventid = r.EventId
                    AND LOWER(REPLACE(REPLACE(CONCAT_WS('~',e.title,IF(e.subtitle<>'',e.subtitle,NULL)),'-',''),' ','')) = ?";

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($title)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg->{cc} 
        if($erg);
    return 0;
}

# ------------------
sub _chronicleexists {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $title = shift  || return error('No title defined!');

    my $modCH  = main::getModule('CHRONICLE');
    return 0
      unless($modCH and $modCH->{active} eq 'y');

    my $sql = "SELECT SQL_CACHE count(*) as cc from CHRONICLE where LOWER(REPLACE(REPLACE(title,'-',''),' ','')) = ?";
    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($title)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg->{cc} 
        if($erg);
    return 0;
}

# ------------------
sub _timerexiststitle {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $title = shift  || return error('No title defined!');

    my $sql = "SELECT SQL_CACHE count(*) as cc from TIMERS where LOWER(REPLACE(REPLACE(file,'-',''),' ','')) = ?";

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($title)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg->{cc} 
        if($erg);
    return 0;
}


# ------------------
sub _insert {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return;

    if(ref $data eq 'HASH') {
        my ($names, $vals, $kenn);
        map {
            push(@$names, $_);
            push(@$vals, $data->{$_}),
            push(@$kenn, '?'),
        } sort keys %$data;

        my $sql = sprintf("REPLACE INTO AUTOTIMER (%s) VALUES (%s)",
                join(', ', @$names),
                join(', ', @$kenn),
        );
        my $sth = $obj->{dbh}->prepare( $sql );
        $sth->execute( @$vals );
    } else {
        my $sth = $obj->{dbh}->prepare('REPLACE INTO AUTOTIMER VALUES (?,?,?,?,?,?,?,?,?)');
        $sth->execute( @$data );
    }
}

# ------------------
# Name:  _placeholder
# Descr: Replace the placeholder with extendet EPG
# Usage: my $text = $obj->_placeholder($epgdata, $autotimerdata);
# ------------------
sub _placeholder {
    my $obj  = shift  || return error('No object defined!');
    my $data = shift  || return error('No data defined!');
    my $at   = shift  || return error('No attribute defined!');

    my $file;

    my %at_details;
    $at_details{'title'}            = $data->{title};
    $at_details{'subtitle'}         = $data->{subtitle} ? $data->{subtitle} : "";
    $at_details{'date'}             = $data->{day};
    $at_details{'regie'}            = $1 if $data->{description} =~ m/\|Director: (.*?)\|/;
    $at_details{'category'}         = $1 if $data->{description} =~ m/\|Category: (.*?)\|/;
    $at_details{'genre'}            = $1 if $data->{description} =~ m/\|Genre: (.*?)\|/;
    $at_details{'year'}             = $1 if $data->{description} =~ m/\|Year: (.*?)\|/;
    $at_details{'country'}          = $1 if $data->{description} =~ m/\|Country: (.*?)\|/;
    $at_details{'originaltitle'}    = $1 if $data->{description} =~ m/\|Originaltitle: (.*?)\|/;
    $at_details{'fsk'}              = $1 if $data->{description} =~ m/\|FSK: (.*?)\|/;
    $at_details{'episode'}          = $1 if $data->{description} =~ m/\|Episode: (.*?)\|/;
    $at_details{'rating'}           = $1 if $data->{description} =~ m/\|Rating: (.*?)\|/;
    $at_details{'cast'}             = $1 if $data->{description} =~ m/\|Cast: (.*?)\|/;

    $at_details{'abstract'}         = $1 if $data->{description} =~ m/^(.*?)[\?\.\r\n]/;
    $at_details{'abstract'} = substr($at_details{'abstract'},0,100) if($at_details{'abstract'});

    if ($at->{Dir}) {
    	my $title = $at->{Dir};
        if($title =~ /.*%.*%.*/sig) {
          $title =~ s/%([\w_-]+)%/$at_details{lc($1)}/sieg;
  				$file = $title;
        } else { # Classic mode DIR~TITLE~SUBTILE
          if($data->{subtitle}) {
            $file = sprintf('%s~%s~%s', $at->{Dir}, $data->{title},$data->{subtitle});
          } else {
            $file = sprintf('%s~%s', $at->{Dir}, $data->{title});
          }
        }
	  } elsif($data->{subtitle}) {
		  $file = sprintf('%s~%s', $data->{title},$data->{subtitle});
    } else {
		  $file = $data->{title};
    }

    my $keywords;
    if ($at->{keywords}) {
    	$keywords = $at->{keywords};
      if($keywords =~ /.*%.*%.*/sig) {
        $keywords =~ s/%([\w_-]+)%/$at_details{lc($1)}/sieg;
      }
    }

    # sind irgendweche Tags verwendet worden, die leer waren und die doppelte Verzeichnisse erzeugten?
    $file =~s#~+#~#g;
    $file =~s#^~##g;
    $file =~s#~$##g;

    return ($file,$keywords);
}

# ------------------
sub suggest {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $search = shift;
    my $params  = shift;

    if($search) {
        my $sql = qq|
    SELECT SQL_CACHE 
        Search
    FROM
        AUTOTIMER
    WHERE
    	( Search LIKE ? )
    GROUP BY
        Search
    ORDER BY
        Search
    LIMIT 25
        |;
        my $sth = $obj->{dbh}->prepare($sql);
        $sth->execute('%'.$search.'%')
            or return con_err($console, sprintf("Couldn't execute query: '%s'",$sth->errstr));
        my $result = $sth->fetchall_arrayref();
        $console->table($result)
            if(ref $console && $result);
    }
}

1;

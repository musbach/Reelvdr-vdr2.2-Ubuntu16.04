package XXV::MODULES::SHARE;
use strict;

use Tools;
use vars qw($AUTOLOAD);


$SIG{CHLD} = 'IGNORE';

# ------------------
sub AUTOLOAD {
# ------------------
    my $self = shift || return error('No object defined!');

    my $cmd = (split('::', $AUTOLOAD))[-1];
    return  if($cmd eq 'DESTROY');

    if($cmd eq 'setEventLevel') {
        # Den Hash per Hand nachpflegen
        # bis zum nächsten Refresh ...
        $self->StoreEventLevel($_[0],$_[1]);
        $_[2] += $self->{TimeOffset} if(exists $self->{TimeOffset});

        # Den Hash in Warteschlange einfügen ...
        foreach my $d (@{$self->{setEventLevelQueue}}) {
          if($d->[0] == $_[0]) {
            $d->[1] = $_[1];
            $d->[2] = $_[2];
            return 1;
          }
        }
        push(@{$self->{setEventLevelQueue}}, [$_[0],$_[1],$_[2]] );
        return 1;
    }

    if($self->{SOAP} && $self->{active} eq 'y') {
        my $erg = $self->CmdToService($self->{SOAP}, $cmd, $self->{randomid}, @_);
        return $erg;
    }
    return 0;
}


# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'SHARE',
        Prereq => {
            'SOAP::Lite' => 'Client and server side SOAP implementation.',
        },
        Description => gettext('This module send anonymized epg data from programmed timern to a common web service. And read backward a ranking list of most programmed epg events.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'n',
                type        => 'confirm',
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = shift;
                    if($value eq 'y') {
                      my $module = main::getModule('EVENTS');
                      unless($module or $module->{active} eq 'y') {
                        return undef, sprintf(gettext("Module can't activated! This module depends module %s."),'EVENTS');
                      }
                    }
                    return $value;
                },

            },
            rating => {
                description => gettext('URL to access popularity web service.'),
                default     => 'http://www.deltab.de/t10.php?wsdl',
                type        => 'string',
                required    => gettext('This is required!'),
            },
            update => {
                description => gettext('How often shared data are to be updated (in hours).'),
                default     => 24,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            randomid => {
                default     => "",
                type        => 'hidden'
            }
        },
        Commands => {
            topten => {
                description => gettext("Display the TopTen list of timers."),
                short       => 't10',
                callback    => sub{ $self->TopTen(@_) },
            }
        }
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

    # read the DB Handle
    $self->{dbh} = delete $attr{'-dbh'};

    $self->{MOD}->{Preferences}->{randomid}->{default} = $self->generateRandomID();

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

    # The Initprocess
    $self->_init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub _init {
# ------------------
    my $self = shift || return error('No object defined!');

    $self->{randomid} = $self->generateRandomID()
        unless($self->{randomid});

    my $version = 27; # Must be increment if rows of table changed
    # this tables hasen't handmade user data,
    # therefore old table could dropped if updated rows

    # remove old table, if updated version
    if(!tableUpdated($self->{dbh},'SHARE',$version,1)) {
      return 0;
    }

    $self->{dbh}->do(qq|
        CREATE TABLE IF NOT EXISTS SHARE (
            eventid int unsigned default '0',
            level float,
            quantity int unsigned default '0',
            rank float,
            addtime datetime NOT NULL default '0000-00-00 00:00:00',
            PRIMARY KEY (eventid)
          ) COMMENT = '$version'
      |);

    main::after(sub{

        $self->{SOAP} = $self->ConnectToService($self->{randomid},$self->{rating});

        unless($self->{SOAP}) {
            error sprintf("Couldn't connect to popularity web service %s!", $self->{rating});
            return 0;
        } else {
            my $servertime = $self->getServerTime();
            if($servertime) {
              my $offset = time - $servertime;
              if($offset > 60 || $offset < -60) {
                $self->{TimeOffset} = $offset;
                lg sprintf('Popularity web service has time offset %d seconds.',$offset);
              }
            }
        }

        return 1;
    }, "SHARE: Connect to popularity web service ...",3) if($self->{active} eq 'y');

    main::after(sub{
        if($self->{SOAP}) {
            $self->getSoapData();
            Event->timer(
              interval => $self->{update} * 3600,
              prio => 6,  # -1 very hard ... 6 very low
              cb => sub{ 
                $self->getSoapData();
              },
            );
            Event->timer(
              interval => ($self->{update}/12) * 1800,
              prio => 6,  # -1 very hard ... 6 very low
              cb => sub{ 
                $self->flushEventLevelQueue();
              },
            );
        }

        my $m = main::getModule('TIMERS');
        $m->updated(sub{
          return 0 if($self->{active} ne 'y');

          lg 'Start timer callback to share timer!';
          return $self->_sharetimer();
        });
        return 1;
    }, "SHARE: Update data with popularity web service ...",48) if($self->{active} eq 'y');

    return 1;
}

# ------------------
sub getSoapData {
# ------------------
    my $self = shift  || return error('No object defined!');
    return unless($self->{SOAP} and $self->{active} eq 'y');

    lg 'Start interval to get popularity top ten events!';
    my $topevents = $self->getTopTen(1000);
    my $time = time;
    foreach my $t (@$topevents) {
      my $sth = $self->{dbh}->prepare('REPLACE INTO SHARE(eventid, level, quantity, rank, addtime) VALUES (?,?,?,?,FROM_UNIXTIME(?))');
      $sth->execute(
        $t->{e}, # eventid
        $t->{l}, # level
        $t->{c}, # count
        $t->{r}, # rank
        $time
      );
    }

    my $dsth = $self->{dbh}->prepare('DELETE FROM SHARE WHERE addtime != FROM_UNIXTIME(?)');
    $dsth->execute($time);
}


# ------------------
sub generateRandomID {
# ------------------
    my $self = shift  || return error('No object defined!');

    my $randomid;
    for(my $i=0 ; $i< 16 ;)
    {
    	my $j = chr(int(rand(127)));

    	if($j =~ /[a-zA-Z0-9]/)
    	{
    		$randomid .=$j;
    		$i++;
    	}
    }
    return $randomid;
}

# ------------------
sub ConnectToService {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $sid = shift  || $self->{randomid} || return error('No session id defined!');
    my $service = shift;

    return undef
        if($self->{active} ne 'y');

    my $version = main::getVersion();

    my $client = SOAP::Lite->new;
    if($client->can('schema')) {
     my $schema = $client->schema;
     if($schema && $schema->can('useragent')) {
       my $ua = $schema->useragent;
       $ua->agent(sprintf("xxv %s",$version)) if($ua);
      }
    }

    my $webservice = eval "\$client->service(\$service)";
    if($@) {
        return error("Couldn't connect to popularity web service: $@");
    }

      
    my $usrkey;
    if($webservice) {
      $usrkey = $self->CmdToService($webservice,'getUsrKey',$self->{randomid}) 
        or error "Couldn't get user key";
      error "Response contain wrong answer" if($usrkey ne $self->{randomid});
    }

    return $webservice
       if($usrkey eq $self->{randomid});
   
    return undef;
}

# ------------------
sub getEventLevel {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $eid = shift  || return;

    my $sql = qq|
SELECT SQL_CACHE 
    level from SHARE
where
    eventid = ?
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($eid)
        or return error(sprintf("Event '%s' does not exist in the database!",$eid));
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{level} : 0;
}

# ------------------
sub StoreEventLevel {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $eid = shift  || return;
    my $level = shift  || return;

    my $sth = $self->{dbh}->prepare('REPLACE INTO SHARE(eventid, level, quantity, rank, addtime) VALUES (?,?,1,1,NOW())');
    $sth->execute(
      $eid, # eventid
      $level # level
    );
}

# ------------------
sub TopTen {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $anzahl = shift || 10;

    my %f = (
        'id' => gettext('Service'),
        'title' => gettext('Title'),
        'channel' => gettext('Channel'),
        'start' => gettext('Start'),
        'stop' => gettext('Stop'),
        'day' => gettext('Day'),
        'rank' => gettext('Rank')
    );

    my $sql = qq|
    SELECT SQL_CACHE 
        e.eventid as \'$f{'id'}\',
        e.title as \'$f{'title'}\',
        e.subtitle as __Subtitle,
        c.Name as \'$f{'channel'}\',
        c.POS as __Pos,
        DATE_FORMAT(e.starttime, '%H:%i') as \'$f{'start'}\',
        DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(e.starttime) + e.duration), '%H:%i') as \'$f{'stop'}\',
        UNIX_TIMESTAMP(e.starttime) as \'$f{'day'}\',
        e.description as __description,
        IF(e.vpstime!=0,DATE_FORMAT(e.vpstime, '%H:%i'),'') as __PDC,
        ( SELECT 
            t.id
            FROM TIMERS as t
            WHERE t.eventid = e.eventid
            LIMIT 1) as __timerid,
        ( SELECT 
            (t.flags & 1) 
            FROM TIMERS as t
            WHERE t.eventid = e.eventid
            LIMIT 1) as __timeractiv,
        ( SELECT 
            NOW() between t.starttime and t.stoptime AND (t.flags & 1) 
            FROM TIMERS as t
            WHERE t.eventid = e.eventid
            LIMIT 1) as __running,
        s.rank as \'$f{'rank'}\',
        s.level as __level,
        s.quantity as __quantity
    from
        EPG as e,
        CHANNELS as c,
        SHARE as s
    where
        e.eventid = s.eventid
        AND e.channel_id = c.Id
        AND ((UNIX_TIMESTAMP(e.starttime) + e.duration) > UNIX_TIMESTAMP())
    group by
        e.eventid
    order by
        rank desc, level desc
    |;


    my $rows;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    unless($limit) { # enforce backward 
      $limit = CORE::int($anzahl);
    }
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $self->{dbh}->prepare($sql);
         $rsth->execute()
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
      $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    unless($console->typ eq 'AJAX') {
      map {
          $_->[7] = datum($_->[7],'weekday');
      } @$erg;
      unshift(@$erg, $fields);
    }

    return $console->table($erg, {
        rows => $rows
    });
}

# ------------------
sub flushEventLevelQueue {
# ------------------
    my $self = shift  || return error('No object defined!');

    do {
      my @Queue = splice(@{$self->{setEventLevelQueue}},0,25);
      if(scalar @Queue) {
        lg(sprintf("Flush %d item from event level queue",scalar @Queue));
        my $result = $self->setEventArray(\@Queue);
        if($result != 1) {
          error(sprintf("Wrong response from soap service setEventArray(%s)", $result));
        }
      }
    } while (scalar @{$self->{setEventLevelQueue}});

}

# ------------------
sub CmdToService {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $service = shift  || return error('No service defined!');
    my $cmd = shift  || return error('No command defined!');
    my @arg = @_;

    lg(sprintf("Call %s from soap service : %s",$cmd, $arg[0]));

    my $res = eval "\$service->$cmd(\@arg)";
    $@ ? return error("SyntaxError: $@") 
       : return $res;
}

# ------------------
sub _sharetimer {
# ------------------
    my $self = shift  || return error('No object defined!');

    my $sql = 'SELECT id,flags,priority,lifetime,autotimerid,eventid,UNIX_TIMESTAMP(eventstarttime) + eventduration as eventstoptime FROM TIMERS';
    my $erg = $self->{dbh}->selectall_hashref($sql, 'id') or return;

    foreach my $t (keys %$erg) {
        my $timer = $erg->{$t};
        $self->sharetimer($timer);
    }
}
# ------------------
sub sharetimer {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $timer = shift  || return error('No timer defined!');

    my $level = 1;
    if($timer->{autotimerid} and ($timer->{flags} && $timer->{flags} & 1)) {
        $level = (($timer->{priority} <= 50 or $timer->{lifetime} < 33) ? 2 : 3);
    } elsif($timer->{flags} && $timer->{flags} & 1) {
        $level = (($timer->{priority} <= 50 or $timer->{lifetime} < 33) ? 4 : 5);
    }

    if($timer->{eventid}) {
        $self->setEventLevel($timer->{eventid}, $level, $timer->{eventstoptime});
    }
}


1;

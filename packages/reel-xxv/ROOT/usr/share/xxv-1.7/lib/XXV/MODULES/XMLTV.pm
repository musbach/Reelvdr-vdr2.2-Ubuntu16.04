package XXV::MODULES::XMLTV;

use strict;
use File::Find;
use Tools;
use Encode;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
  my $self = shift || return error('No object defined!');
  my $args = {
      Name => 'XMLTV',
      Prereq => {
            'Template'  => 'Front-end module to the Template Toolkit ',
            'Date::Manip' => 'date manipulation routines',
            'Time::Local' => 'efficiently compute time from local and GMT time',
            'XML::Simple' => 'Easy API to maintain XML (esp config files)'
      },
      Description => gettext('This module import epg data from xmltv sources.'),
      Preferences => {
          active => {
              description => gettext('Activate this service'),
              default     => 'n',
              type        => 'confirm',
              required    => gettext('This is required!'),
          },
      },
      Commands => {
          xmltv => {
              description => gettext("Manual import epg data from xmltv sources."),
              short       => 'xt',
              callback    => sub{ $self->manual(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          xmltvlist => {
              description => gettext("List rules to import epg data from xmltv sources."),
              short       => 'xl',
              callback    => sub{ $self->list(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          xmltvcreate => {
              description => gettext("Create rule to import epg data from xmltv sources."),
              short       => 'xc',
              callback    => sub{ $self->create(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          xmltvremove => {
              description => gettext("Delete rule to import epg data from xmltv sources."),
              short       => 'xd',
              callback    => sub{ $self->remove(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          xmltvedit => {
              description => gettext("Edit rule to import epg data from xmltv sources."),
              short       => 'xe',
              callback    => sub{ $self->edit(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
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

  # run as background process
  #$self->{background} = delete $attr{'-background'};

  # create Template object
  $self->{tt} = Template->new(
    START_TAG    => '\[\%',		        # Tagstyle
    END_TAG      => '\%\]',		        # Tagstyle
    INCLUDE_PATH => '',
#    INTERPOLATE  => 1,              # expand "$var" in plain text
#    PRE_CHOMP    => 0,              # cleanup whitespace
#    EVAL_PERL    => 0,              # evaluate Perl code blocks
  ) || return error("Can't create Template instance!");


  $self->{xml} = XML::Simple->new( NumericEscape => ($self->{charset} eq 'UTF-8' ? 0 : 1) )
        || return error("Can't create XML instance!");

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
    if(!tableUpdated($self->{dbh},'XMLTV',$version,0)) {
      return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS XMLTV (
          id int unsigned auto_increment NOT NULL,
          active enum('y', 'n') default 'n',
          xmltvname varchar(256) default NULL,
          vid int unsigned NOT NULL default '1',
          channel varchar(64) NOT NULL,
          template enum('y', 'n') default 'n',
          updateinterval enum('e', 'd', 'w') default 'e',
          source text NOT NULL,
          updated datetime NOT NULL default '0000-00-00 00:00:00',
          PRIMARY KEY (id),
          UNIQUE KEY (vid, channel) 
        ) COMMENT = '$version'
    |);

    main::after(sub{

        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           panic ("Couldn't get modul SVDRP");
           return 0;
        }

        my $m = main::getModule('EPG');
        $m->before_updated(
          sub{
            my $console = shift;
            my $waiter = shift;

            return 0 if($self->{active} ne 'y');
            lg 'Start callback to import xmltv epg data!';
            $self->_XMLTV($console,undef,$waiter);
            }
        );
        return 1;
    }, "XMLTV: Install callback to import xmltv epg data ...", 28);

    return 1;
}

# ------------------
sub manual {
# ------------------
  my $self = shift || return error('No object defined!');
  my $console = shift;
  my $config = shift;
  my $id = shift;

  my $waiter;
  if(ref $console && !$id && $console->typ eq 'HTML') {
      $waiter = $console->wait(gettext("Import epg data from xmltv sources ..."),0,1000,'no');
  }

  my ($msg, $error) = $self->_XMLTV($console,$config,$waiter,$id,'force');

  $waiter->end() if(ref $waiter);
  $console->start() if(ref $waiter);

  if($error) { $console->err($error); }
  elsif($msg) {
    $console->message($msg); 
    $console->redirect({url => '?cmd=xmltvlist', wait => 1})
      if($console->typ eq 'HTML');
  } 
  return 1;
}

# ------------------
sub _XMLTV {
# ------------------
  my $self = shift || return error('No object defined!');
  my $console = shift;
  my $config = shift;
  my $waiter = shift;
  my $id = shift;
  my $force = shift;

  my $sql = qq|
    select
      x.id,
      x.vid,
      x.active,
      x.xmltvname,
      x.channel,
      x.template,
      x.updateinterval,
      x.source,
      UNIX_TIMESTAMP(x.updated) as updated,
      c.Name
    from XMLTV as x, CHANNELS as c, RECORDER as r
    where 
      x.active != 'n'
      and x.channel = c.Id
      and x.vid = r.id
      and r.active != 'n'
  |;
  $sql .= qq| and x.id = ?| if($id);
  $sql .= qq| ORDER BY x.vid|;

  my $sth = $self->{dbh}->prepare($sql);
  unless($id ? $sth->execute($id) : $sth->execute()) {
      error sprintf("Couldn't execute query: %s.",$sth->errstr);
      return (undef, undef)
  }
  my $rules = $sth->fetchall_hashref('id');
  return (undef, undef) unless($rules);

  # Adjust waiter max value now.
  $waiter->max((scalar keys %$rules)+1)
      if(ref $console && ref $waiter);

	my $now = time();
  my $l = 0;
  my $output = "";
  my $vid;

  foreach my $id (sort keys %$rules) {
    my $rule = $rules->{$id};

    $waiter->next(++$l, undef, sprintf(gettext("Import epg data for channel '%s'"), $rule->{Name}))
      if(ref $waiter);

    unless($force && $id) {
      if($rule->{updateinterval} eq 'd' && ($rule->{updated} + 86400) > $now  ) {
        lg sprintf("Skip import xml data by update interval : %s (%s) id %d",$rule->{Name},$rule->{channel},$rule->{id});
        next;
      } elsif($rule->{updateinterval} eq 'w' && ($rule->{updated} + (86400 * 7)) > $now ) {
        lg sprintf("Skip import xml data by update interval : %s (%s) id %d",$rule->{Name},$rule->{channel},$rule->{id});
        next;
      }
    }

    my $file = sprintf("%s/%s",$self->{paths}->{XMLTV},$rule->{source});
    if(-r $file and my $text = load_file($file)) {
      if($rule->{template} eq 'y') {
        $text = $self->_parse_template($text,$now);
      }

      my $adjust = 0;
      debug sprintf("Import xml data at %s (%s) id %d",$rule->{Name},$rule->{channel},$rule->{id});
      my $e = $self->_ProcessXML($rule->{channel},$rule->{Name},$rule->{xmltvname},$adjust,$text);
      if($e) {
        $self->_updateTime($rule->{id});
        $output .= $e;
      }
      else {
        error sprintf("Can't process xml data at %s (%s) id %d",$rule->{Name},$rule->{channel},$rule->{id});
      }
    }
    if($vid && $vid != $rule->{vid}) {
      $self->{svdrp}->queue_add("PUTE\n" . $output . ".\n",$rule->{vid});
      $output = "";
    }
    $vid = $rule->{vid};
  }

  if($vid && $output && length $output) {
      $self->{svdrp}->queue_add("PUTE\n" . $output . ".\n",$vid);
  }
  if($self->{svdrp}->queue_count()) {
    $waiter->next(undef,undef,gettext('Transmit data.'))
      if(ref $waiter);

    my ($erg,$error) = $self->{svdrp}->queue_flush();
    unless($error) {
          debug 'Data import complete';
          return ($erg, undef);

    } else {
      error sprintf('Data does\'nt imported : %s',$error);
      return (undef, $error);
    }
  } else {
      error sprintf('None data exits to import');
      return (undef, gettext('None data exits to import'));
  }
}

# Convert XMLTV time format (YYYYMMDDmmss ZZZ) into VDR (secs since epoch)
sub xmltime2vdr {
  my $xmltime=shift;
  my $skew=shift;
  my $secs = &UnixDate($xmltime, "%s");
  return $secs + ( $skew * 60 );
}
# ------------------
sub encodeEpgId {
# ------------------
    my $self = shift || return error('No object defined!');
    my $epgid = shift || return error('No event defined!');
    my $channel = shift || return error('No channel defined!');

    # look for NID-TID-SID for unique eventids (SID 0-30000 / TID 0 - 1000 / NID 0 - 10000
    my @id = split('-', $channel);

    # Make a fix format 0xCCCCEEEE : C-Channelid (high-word), E-Eventid(low-word) => real-eventid = uniqueid & FFFF
    my $eventid = ((($id[-3] + $id[-2] + $id[-1]) & 0x3FFF) << 16) | ($epgid & 0xFFFF);

    return $eventid;
}


# ------------------
sub _ProcessXML {
# ------------------
  my $self = shift || return error('No object defined!');
  my $cid = shift;
  my $channel_name = shift;
  my $xmltvname = shift;
  my $adjust = shift;
  my $text = shift;

  my $xdata = $self->{xml}->XMLin($text);

  return error "Missing channel" unless $xdata->{channel};
  return error "Missing program data" unless $xdata->{programme};

  # Create output

  my $epgdata;


  # Find XML events
  foreach my $xml (@{$xdata->{programme}})   {
#    {
#      'stop' => '20080317200000 +0100',
#      'desc' => {
#        'lang' => 'de',
#        'content' => 'desc'
#      },
#      'title' => {
#        'lang' => 'de',
#        'content' => 'title'
#      },
#      'channel' => 'abc',
#      'start' => '20080317160000 +0100'
#    },
    next if($xmltvname && $xml->{channel} ne $xmltvname);

    my $vdrst = &xmltime2vdr($xml->{start}, $adjust);
    my $vdret = &xmltime2vdr($xml->{stop}, $adjust);
    my $vdrdur = $vdret - $vdrst;
    my $vdrid = $self->encodeEpgId($vdrst / 60,$cid); 
    my $vdrtitle = $xml->{title} && $xml->{title}->{content} ? $xml->{title}->{content} : gettext('Title not available');
    my $vdrdesc = $xml->{desc} && $xml->{desc}->{content} ? $xml->{desc}->{content} : '';
    $vdrtitle =~ s/\r\n//g;            # pipe used from vdr as linebreak
    $vdrtitle =~ s/\n//g;              # pipe used from vdr as linebreak
    $vdrdesc =~ s/\r\n/\|/g;            # pipe used from vdr as linebreak
    $vdrdesc =~ s/\n/\|/g;              # pipe used from vdr as linebreak

    $vdrtitle = encode($self->{charset},$vdrtitle);
    $vdrdesc = encode($self->{charset},$vdrdesc);

    # Send VDR Event
    $epgdata .= "E $vdrid $vdrst $vdrdur 0\n";
    $epgdata .= "T $vdrtitle\n";
    $epgdata .= "D $vdrdesc\n";
    $epgdata .= "e\n";

  }

  return unless($epgdata && length $epgdata);

  return "C $cid $channel_name\n"
         . $epgdata
         . "c\n";
}

# ------------------
sub _parse_template {
# ------------------
  my $self = shift || return error('No object defined!');
  my $text = shift || return error('No text defined!');
	my $now = shift || return error('No time defined!');

	# Get current wday
	my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($now);

  my %wd = (
      'monday' => 1,
      'tuesday' => 2,
      'wednesday' => 3,
      'thursday' => 4,
      'friday' => 5,
      'saturday' => 6,
      'sunday' => 0
  );

  my $vars = {
	  # [% date("sunday","08:00","+0100") %] => 20060119220000 +0100
      date => sub{
  			my $day = $wd{$_[0]};
		    $day += 7 if($day<$wday);
		    $day -= $wday;

		    my ($t1,$t2,$t3,$tmday,$tmon,$tyear,$t4,$t5,$t6) = localtime($now + ($day * 86400));

		    ($hour,$min,$sec) = split(':',$_[1]);
		    $min = 0 if(!defined $min);
		    $sec = 0 if(!defined $sec);
        my $tz = $_[2];
        $tz += 100 if($isdst);
        return sprintf("%04d%02d%02d%02d%02d%02d +%04d",$tyear + 1900,$tmon+1,$tmday,$hour,$min,$sec,$tz);
      },
  };
  my $output = '';
  $self->{tt}->process(\$text, $vars, \$output)
        or return error(sprintf("Can't parse xmltv template: %s", $self->{tt}->error()));
	return $output;
}


# ------------------
# Name:  create
# Descr: create rule to import epg data from xmltv sources.
# Usage: $self->create($console, [$userdata]);
# ------------------
sub create {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || 0;
    my $data    = shift || 0;

    $self->edit($console, $config, $id, $data);
}

# ------------------
# Name:  edit
# Descr: edit rule to import epg data from xmltv sources.
# Usage: $self->edit($console, [$id], [$userdata]);
# ------------------
sub edit {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || 0;
    my $data    = shift || 0;

    my $modC = main::getModule('CHANNELS');

    my $rule;
    if($id && not ref $data) {
        my $sth = $self->{dbh}->prepare("select * from XMLTV where id = ?");
        $sth->execute($id)
            or return $console->err(sprintf(gettext("Rule to import epg data from xmltv sources with ID '%s' does not exist in the database!"),$id));
        $rule = $sth->fetchrow_hashref();

    } elsif (ref $data eq 'HASH') {
        $rule = $data;
    }
    my $vlist = $self->{svdrp}->enum_hosts();

    my $con = $console->typ eq "CONSOLE";
    my $questions = [
        'id' => {
            typ     => 'hidden',
            def     => $rule->{id} || 0,
        },
        'active' => {
            typ     => 'confirm',
            def     => $rule->{active} || 'y',
            msg     => gettext('Enable this rule'),
        },
        'source' => {
            msg         => gettext('Source to import?'),
            def         => $rule->{source},
            typ         => 'list',
            required    => gettext('This is required!'),
            choices     => sub{ return $self->findfiles(); }
        },
        'xmltvname' => {
            msg => gettext('Limit import by this channel name inside xmltv source?'),
            def => $rule->{xmltvname} || '',
            typ => 'string'
        },
        'vid' => {
            typ     => scalar @$vlist > 1 ? 'list' : 'hidden',
            def     => $rule->{vid} || $self->{svdrp}->primary_hosts(),
            choices => $vlist,
            msg     => gettext('Which video disk recorder should record'),
        },
        'channel' => {
            typ     => 'list',
            def     => $con ? $modC->ChannelToPos($rule->{channel}) : $rule->{channel},
            choices => $con ? $modC->ChannelArray('name') : $modC->ChannelWithGroup('c.name,c.id'),
            msg     => gettext('Assign data to channel?'),
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
        'template' => {
            msg => gettext('Parse data as template?'),
            def => $rule->{template} || 'n',
            typ => 'list',
            choices     => sub {
                                my $erg = $self->_template_rules();
                                map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                return @$erg;
                              },
        },
        'updateinterval' => {
            msg => gettext('Interval to parse data?'),
            def => $rule->{updateinterval} || 'e',
            typ => 'list',
            choices     => sub {
                                my $erg = $self->_interval_rules();
                                map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                return @$erg;
                              },
        },
    ];

    # Ask Questions
    $data = $console->question(($id ? gettext('Edit rule to import epg data from xmltv sources')
					 : gettext('Create a new rule to import epg data from xmltv sources')), $questions, $data);

    if(ref $data eq 'HASH') {
    	$self->_insert($console, $data);

    	$data->{id} = $self->{dbh}->selectrow_arrayref('SELECT max(id)+1 FROM XMLTV')->[0]
    		if(not $data->{id});

        $console->message(gettext('Rule to import epg data from xmltv sources saved!'));
        debug sprintf('%s rule to import epg data from xmltv sources is saved%s',
            ($id ? 'Changed' : 'New'),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        my ($msg, $error) = $self->_XMLTV($console,$config,undef,$data->{id});

        if($error) { $console->err($error); }
        elsif($msg) {
          $console->message($msg); 
          $console->redirect({url => '?cmd=xmltvlist', wait => 1})

          if($console->typ eq 'HTML');
        }
    }
    return 1;
}

# ------------------
sub _insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $data = shift || return;

    my $sth;
    if(ref $data eq 'HASH') {
        my ($names, $vals, $kenn);
        map {
            push(@$names, $_);
            push(@$vals, $data->{$_}),
            push(@$kenn, '?'),
        } sort keys %$data;

        my $sql = sprintf("REPLACE INTO XMLTV (%s) VALUES (%s)",
                join(', ', @$names),
                join(', ', @$kenn),
        );
        $sth = $self->{dbh}->prepare( $sql );
        if(!$sth->execute(@$vals)) {
          error sprintf("Couldn't execute query: %s.",$sth->errstr);
          $console->err(sprintf(gettext("Couldn't insert rule to import epg data from xmltv sources in database!")));
          return 0;
        }
    } else {
        $sth = $self->{dbh}->prepare('REPLACE INTO XMLTV VALUES (?,?,?,?,?,NOW())');
        if(!$sth->execute(@$data)) {
          error sprintf("Couldn't execute query: %s.",$sth->errstr);
          $console->err(sprintf(gettext("Couldn't insert rule to import epg data from xmltv sources in database!")));
          return 0;
        }
    }
    return 1;  
}

# ------------------
sub _updateTime {
# ------------------
    my $self = shift || return error('No object defined!');
    my $id = shift || return error ('No data defined!');

    my $sth = $self->{dbh}->prepare('UPDATE XMLTV SET updated=NOW() where id=?');
    return $sth->execute($id);
}

# ------------------
# Name:  remove
# Descr: Routine to delete rule to import epg data from xmltv sources.
# Usage: $self->remove($console, $id);
# ------------------
sub remove {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || return $console->err(gettext("Missing ID to select rules for deletion! Please use xmltvremove 'id'")); 

    my @rules  = reverse sort{ $a <=> $b } split(/[^0-9]/, $id);

    my $sql = sprintf('DELETE FROM XMLTV where id in (%s)', join(',' => ('?') x @rules)); 
    my $sth = $self->{dbh}->prepare($sql);
    if(!$sth->execute(@rules)) {
        error sprintf("Couldn't execute query: %s.",$sth->errstr);
        $console->err(sprintf(gettext("Rule to import epg data from xmltv sources with ID '%s' does not exist in the database!"),$id));
        return 0;
    }

    $console->message(sprintf gettext("Rule import epg data from xmltv sources %s is deleted."), join(',', @rules));
    debug sprintf('Rule import epg data from xmltv sources with id "%s" is deleted%s',
        join(',', @rules),
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );
    $console->redirect({url => '?cmd=xmltvlist', wait => 1})
        if($console->typ eq 'HTML');
}

# ------------------
# Name:  list
# Descr: List Rules to import epg data from xmltv sources in a table display.
# Usage: $self->list($console);
# ------------------
sub list {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my %f = (
        'id' => gettext('Service'),
        'active' => gettext('Active'),
        'channel' => gettext('Channel'),
        'template' => gettext('Parse data as template'),
        'interval' => gettext('Interval to parse data'),
        'source' => gettext('source to import'),
        'host' => gettext('Video disk recorder')
    );

    my $sql = qq|
    select
      x.id as \'$f{'id'}\',
      IF(x.active!='n' and r.active!='n','y','n') as \'$f{'active'}\',
      (SELECT Name
          FROM CHANNELS as c
          WHERE x.channel = c.Id
          LIMIT 1) as \'$f{'channel'}\',
      x.template as \'$f{'template'}\',
      x.updateinterval as \'$f{'interval'}\',
      x.source as \'$f{'source'}\',
      r.host  as \'$f{'host'}\'
    from
      XMLTV as x, RECORDER as r
    where
      x.vid = r.id
    order by 
      x.id
    |;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    my %m;
    my %i;
    my $mr = $self->_template_rules();
    foreach my $mrr (@{$mr}) {
      $m{$mrr->[0]} = $mrr->[1]; 
    }

    my $ir = $self->_interval_rules();
    foreach my $irr (@{$ir}) {
      $i{$irr->[0]} = $irr->[1]; 
    }

    map { 
      $_->[3] = $m{$_->[3]};
      $_->[4] = $i{$_->[4]};
    } @$erg;

    unshift(@$erg, $fields);
    my $hostlist = $self->{svdrp}->list_hosts();
    $console->table($erg, {
        recorder => scalar @$hostlist,
    });
}

# ------------------
sub findfiles
# ------------------
{
    my $self = shift || return error('No object defined!');
    my @files;
    find({ wanted => sub{
               if($File::Find::name =~ /\.xml$/sig   # Lookup for *.xml
                 or $File::Find::name =~ /\.tpl$/sig) {  # Lookup for *.tpl
                  my $l = $_; # keep name of file without path
                  if(-r $File::Find::name) {
                    push(@files,[$_,$_]);
                  }
              }
           }
        },
        $self->{paths}->{XMLTV}
    );
    error "Couldn't find useable file at : $self->{paths}->{XMLTV}"
        unless(scalar @files);
    @files = sort { lc($a->[0]) cmp lc($b->[0]) } @files;
    return \@files;
}

# ------------------
sub _template_rules {
# ------------------
    my $self = shift || return error('No object defined!');

    return [
            [ 'y', gettext('Yes') ],
            [ 'n', gettext('No') ]
          ];
}


# ------------------
sub _interval_rules {
# ------------------
    my $self = shift || return error('No object defined!');

    return [
            [ 'e', gettext('Every EPG Data import') ],
            [ 'd', gettext('Once every day') ],
            [ 'w', gettext('Once every week') ]
          ];
}

1;

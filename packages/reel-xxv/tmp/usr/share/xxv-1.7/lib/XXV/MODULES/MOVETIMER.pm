package XXV::MODULES::MOVETIMER;

use strict;
use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
  my $self = shift || return error('No object defined!');
  my $args = {
      Name => 'MOVETIMER',
      Prereq => {
          # 'Perl::Module' => 'Description',
      },
      Description => gettext('This module move timers between channels.'),
      Preferences => {
          active => {
              description => gettext('Activate this service'),
              default     => 'n',
              type        => 'confirm',
              required    => gettext('This is required!'),
          },
      },
      Commands => {
          movetimer => {
              description => gettext("Manual move timer between channels"),
              short       => 'mt',
              callback    => sub{ $self->movetimermanual(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          movetimerlist => {
              description => gettext("List rules to move timer between channels"),
              short       => 'mtl',
              callback    => sub{ $self->movetimerlist(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          movetimercreate => {
              description => gettext("Create rule to move timer between channels"),
              short       => 'mtc',
              callback    => sub{ $self->movetimercreate(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          movetimerdelete => {
              description => gettext("Delete rule to move timer between channels"),
              short       => 'mtd',
              callback    => sub{ $self->movetimerdelete(@_) },
              Level       => 'user',
              DenyClass   => 'tedit',
          },
          movetimeredit => {
              description => gettext("Edit rule to move timer between channels"),
              short       => 'mte',
              callback    => sub{ $self->movetimeredit(@_) },
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
    if(!tableUpdated($self->{dbh},'MOVETIMER',$version,0)) {
      return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS MOVETIMER (
          id int unsigned auto_increment NOT NULL,
          sourcevid int unsigned NOT NULL default '1',
          source varchar(64) NOT NULL,
          destinationvid int unsigned NOT NULL default '1',
          destination varchar(64) NOT NULL,
          move  enum('y', 'n', 'collision') default 'collision',
          original   enum('move', 'keep', 'copy') default 'move',
          PRIMARY KEY (id),
          UNIQUE KEY (sourcevid, source) 
        ) COMMENT = '$version'
    |);

    main::after(sub{

        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           panic ("Couldn't get modul SVDRP");
           return 0;
        }

        my $m = main::getModule('TIMERS');
        $m->updated(sub{
        return 0 if($self->{active} ne 'y');

        lg 'Start timer callback to move timer!';
        return $self->_movetimer();

        });
        return 1;
    }, "MOVETIMER: Install callback at move timer ...", 95);

    return 1;
}

# ------------------
sub movetimermanual {
# ------------------
  my $self = shift || return error('No object defined!');
  my $console = shift || return error('No console defined!');
  my $config = shift || return error('No config defined!');
  my $id = shift;

  return 0 unless($self->_movetimer($console,$id));

  $console->redirect({url => '?cmd=movetimerlist', wait => 1})
    if($console->typ eq 'HTML');

  return 1;
}

# ------------------
sub _movetimer {
# ------------------
  my $self = shift || return error('No object defined!');
  my $console = shift;
  my $id = shift;

  my $modT = main::getModule('TIMERS') || return;

  my $sth = $self->{dbh}->prepare(
q|
  select
  t.id as id,
  t.vid as vid,
  t.pos as pos,
  IF(t.flags & 1,'y','n') as active,
  IF(t.flags & 4,'y','n') as vps,
  t.flags as flags,
  t.channel as channel,
  t.file as file,
  t.aux as aux,
  t.day as day,
  t.start as start,
  t.stop as stop,
  t.priority as priority,
  t.lifetime as lifetime,
  t.collision as collision,
  IF(t.flags & 1 and NOW() between t.starttime and t.stoptime,1,0) as running 
  from TIMERS as t,MOVETIMER as m 
  where 
  m.source = t.channel
  and m.sourcevid = t.vid
  and m.move != 'm'
  and t.flags & 1
|);

  if(!$sth->execute()) {
      return error sprintf("Couldn't execute query: %s.",$sth->errstr);
  }
  my $timer = $sth->fetchall_hashref('id');
  return unless($timer);

  $sth = $self->{dbh}->prepare("select * from MOVETIMER where move != 'n'");
  if(!$sth->execute()) {
        error sprintf("Couldn't execute query: %s.",$sth->errstr);
        $console->err(sprintf(gettext("Couldn't query rules to move timer from database!")))
          if($console);
  }
  my $rules = $sth->fetchall_hashref('id');
  return unless($rules);
  my $todel;
  my $bChange = 0;
  foreach my $tid (keys %$timer) {

    my $data = $timer->{$tid};

    foreach my $id (sort keys %$rules) {

      my $rule = $rules->{$id};

      if($data->{channel} eq $rule->{source}) {

        # Move timer if collision present
        if($rule->{move} eq 'collision') {
          # None Collision present
          last unless($data->{Collision});
          # Search maximum priority of collision
          my $maxPrio = 1;
          foreach my $tc (split(',', $data->{Collision})) {
            my $col = (split(':', $tc))[1];
            $maxPrio = $col
              if($col > $maxPrio);
          }
          # dont solve collision until lesser own Priority
          last if($maxPrio < $data->{priority});
        }

        debug sprintf("Move timer %d (%s) at %s : from %s to %s", 
                      $data->{pos}, 
                      $data->{file}, 
                      $data->{day}, 
                      $rule->{source},
                      $rule->{destination});

        if($rule->{original} eq 'keep' ) {

          # Keep original timer but disable him
          $data->{active} = 'n';
          $self->modifyTimer($data);

          # Create new timer
          $data->{active} = 'y';
          $data->{channel} = $rule->{destination};
          $data->{vid} = $rule->{destinationvid};
          $data->{pos} = 0;
          $self->modifyTimer($data);

        } elsif($rule->{original} eq 'copy' ) {

          # Copy to new timer
          $data->{active} = 'y';
          $data->{channel} = $rule->{destination};
          $data->{vid} = $rule->{destinationvid};
          $data->{pos} = 0;
          $self->modifyTimer($data);

        } else {

          # delete original timer
          if($data->{vid} != $rule->{destinationvid}) {
              push(@$todel,[$data->{vid},$data->{pos},$data->{running}]);
              $data->{pos} = 0;
          }
          # Edit timer direct
          $data->{channel} = $rule->{destination};
          $data->{vid} = $rule->{destinationvid};
          $self->modifyTimer($data);

        }

        last;
      }
    }
  }
  if($todel) {
    foreach my $d (reverse sort{ $a->[1] <=> $b->[1] } @$todel) {
      $self->{svdrp}->queue_add(sprintf("modt %d off", $d->[1]), $d->[0])
        if($d->[2]);
      $self->{svdrp}->queue_add(sprintf("delt %d", $d->[1]), $d->[0]);
    }
  }

  if($self->{svdrp}->queue_count()) {
      my ($erg,$error) = $self->{svdrp}->queue_flush(); # deqeue commands
      $console->msg($erg, $error)
          if(ref $console);

    $modT->readData($console)
  } else {
    $console->msg(gettext("There none timer to move."))
        if(ref $console);
  }
  return 1;
}


# ------------------
sub modifyTimer {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $flags  = ($data->{active} eq 'y' ? 1 : 0);
       $flags |= ($data->{vps} eq 'y' ? 4 : 0);

    $data->{file} =~ s/:/|/g;
    $data->{file} =~ s/(\r|\n)//sig;

    $self->{svdrp}->queue_add(
        sprintf("%s %s:%s:%s:%s:%s:%s:%s:%s:%s",
            $data->{pos} ? "modt $data->{pos}" : "newt",
            $flags,
            $data->{channel},
            $data->{day},
            $data->{start},
            $data->{stop},
            int($data->{priority}),
            int($data->{lifetime}),
            $data->{file},
           ($data->{aux} || '')
        )
      ,$data->{vid}
    );
}

# ------------------
# Name:  movetimercreate
# Descr: create rule to move timer.
# Usage: $self->movetimercreate($console, [$userdata]);
# ------------------
sub movetimercreate {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || 0;
    my $data    = shift || 0;

    $self->movetimeredit($console, $config, $id, $data);
}

# ------------------
# Name:  movetimeredit
# Descr: edit rule to move timer.
# Usage: $self->movetimeredit($console, [$id], [$userdata]);
# ------------------
sub movetimeredit {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || 0;
    my $data    = shift || 0;

    my $modC = main::getModule('CHANNELS');

    my $vlist = $self->{svdrp}->enum_onlinehosts();

    my $rule;
    if($id and not ref $data) {
        my $sth = $self->{dbh}->prepare("select * from MOVETIMER where id = ?");
        $sth->execute($id)
            or return $console->err(sprintf(gettext("Rule to move timer with ID '%s' does not exist in the database!"),$id));
        $rule = $sth->fetchrow_hashref();

    } elsif (ref $data eq 'HASH') {
        $rule = $data;
        if(scalar @$vlist <= 1) {
          $data->{sourcevid} = $self->{svdrp}->primary_hosts();
          $data->{destinationvid} = $self->{svdrp}->primary_hosts();
        }
    }

    my $con = $console->typ eq "CONSOLE";


    my $questions = [
        'id' => {
            typ     => 'hidden',
            def     => $rule->{id} || 0,
        },
        'sourcevid' => {
            typ     => scalar @$vlist > 1 ? 'list' : 'hidden',
            def     => $rule->{sourcevid} || $self->{svdrp}->primary_hosts(),
            choices => $vlist,
            msg     => gettext('Which video disk recorder should as source?'),
        },
        'source' => {
            typ     => 'list',
            def     => $con ? $modC->ChannelToPos($rule->{source}) : $rule->{source},
            choices => $con ? $modC->ChannelArray('Name') : $modC->ChannelWithGroup('c.name,c.id'),
            msg     => gettext('Which channel should used as source?'),
            req     => gettext("This is required!"),
            check   => sub{
                my $value = shift;
                return undef, gettext("This is required!")
                  unless($value);

                my $ch = $modC->ToCID($value,$data->{sourcevid});
                return undef, sprintf(gettext("Channel '%s' does not exist on video disk recorder %s!"),$value, $self->{svdrp}->hostname($data->{sourcevid}))
                  unless($ch);
                return $ch;                
            },
        },
        'destinationvid' => {
            typ     => scalar @$vlist > 1 ? 'list' : 'hidden',
            def     => $rule->{destinationvid} || $self->{svdrp}->primary_hosts(),
            choices => $vlist,
            msg     => gettext('Which video disk recorder should as destination?'),
        },
        'destination' => {
            typ     => 'list',
            def     => $con ? $modC->ChannelToPos($rule->{destination}) : $rule->{destination},
            choices => $con ? $modC->ChannelArray('Name') : $modC->ChannelWithGroup('c.name,c.id'),
            msg     => gettext('Which channel should used as destination?'),
            req     => gettext("This is required!"),
            check   => sub{
                my $value = shift;
                return undef, gettext("This is required!")
                  unless($value);

                my $ch = $modC->ToCID($value,$data->{destinationvid});
                return undef, sprintf(gettext("Channel '%s' does not exist on video disk recorder %s!"),$value, $self->{svdrp}->hostname($data->{destinationvid}))
                  unless($ch);
                return $ch;                
            },
        },
        'move' => {
            msg => gettext('When should use this rule'),
            def => $rule->{move} || 'collision',
            typ => 'list',
            choices     => sub {
                                my $erg = $self->_move_rules();
                                map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                return $erg;
                              },
        },
        'original' => {
            msg => gettext('How should timer handled, if changed'),
            def => $rule->{original} || 'move',
            typ => 'list',
            choices     => sub {
                                my $erg = $self->_original_timer_rules();
                                map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                return $erg;
                              },
        },
    ];

    # Ask Questions
    $data = $console->question(($id ? gettext('Edit rule to move timer')
					 : gettext('Create a new rule to move timer')), $questions, $data);

    if(ref $data eq 'HASH') {
    	$self->_insert($console, $data);

    	$data->{id} = $self->{dbh}->selectrow_arrayref('SELECT max(id)+1 FROM MOVETIMER')->[0]
    		if(not $data->{id});

        $console->message(gettext('Rule to move timer saved!'));
        debug sprintf('%s rule to move timer is saved%s',
            ($id ? 'Changed' : 'New'),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $self->_movetimer($console, $data->{id});

        $console->redirect({url => '?cmd=movetimerlist', wait => 1})
          if($console->typ eq 'HTML');
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

        my $sql = sprintf("REPLACE INTO MOVETIMER (%s) VALUES (%s)",
                join(', ', @$names),
                join(', ', @$kenn),
        );
        $sth = $self->{dbh}->prepare( $sql );
        if(!$sth->execute(@$vals)) {
          error sprintf("Couldn't execute query: %s.",$sth->errstr);
          $console->err(sprintf(gettext("Couldn't insert rule move timer in database!")));
          return 0;
        }
    } else {
        $sth = $self->{dbh}->prepare('REPLACE INTO MOVETIMER VALUES (?,?,?,?,?,?,?)');
        if(!$sth->execute(@$data)) {
          error sprintf("Couldn't execute query: %s.",$sth->errstr);
          $console->err(sprintf(gettext("Couldn't insert rule move timer in database!")));
          return 0;
        }
    }
    return 1;  
}

# ------------------
# Name:  movetimerdelete
# Descr: Routine to delete move timer rule.
# Usage: $self->movetimerdelete($console, $id);
# ------------------
sub movetimerdelete {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || return $console->err(gettext("Missing ID to select rules for deletion! Please use movetimerdelete 'id'")); 

    my @rules  = reverse sort{ $a <=> $b } split(/[^0-9]/, $id);

    my $sql = sprintf('DELETE FROM MOVETIMER where id in (%s)', join(',' => ('?') x @rules)); 
    my $sth = $self->{dbh}->prepare($sql);
    if(!$sth->execute(@rules)) {
        error sprintf("Couldn't execute query: %s.",$sth->errstr);
        $console->err(sprintf(gettext("Rule to move timer with ID '%s' does not exist in the database!"),$id));
        return 0;
    }

    $console->message(sprintf gettext("Rule to move timer %s is deleted."), join(',', @rules));
    debug sprintf('Rule to move timer with id "%s" is deleted%s',
        join(',', @rules),
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );
    $console->redirect({url => '?cmd=movetimerlist', wait => 1})
        if($console->typ eq 'HTML');
}

# ------------------
# Name:  movetimerlist
# Descr: List Rules to move timer in a table display.
# Usage: $self->movetimerlist($console);
# ------------------
sub movetimerlist {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my %f = (
        'id' => gettext('Service'),
        'source' => gettext('Source'),
        'destination' => gettext('Destination'),
        'move' => gettext('Move timer'),
        'original' => gettext('Change original timer'),
    );

    my $sql = qq|
    select
      id as \'$f{'id'}\',
      (SELECT Name
          FROM CHANNELS as c
          WHERE m.source = c.id
          LIMIT 1) as \'$f{'source'}\',
      (SELECT Name
          FROM CHANNELS as c
          WHERE m.destination = c.id
          LIMIT 1) as \'$f{'destination'}\',
      move as \'$f{'move'}\',
      original as \'$f{'original'}\'
    from
      MOVETIMER as m
    order by 
      id
    |;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    my %m;
    my %d;
    my $mr = $self->_move_rules();
    foreach my $mrr (@{$mr}) {
      $m{$mrr->[0]} = $mrr->[1]; 
    }

    my $dr = $self->_original_timer_rules();
    foreach my $drr (@{$dr}) {
      $d{$drr->[0]} = $drr->[1];
    }

    map { 
      $_->[3] = $m{$_->[3]};
      $_->[4] = $d{$_->[4]};
    } @$erg;

    unshift(@$erg, $fields)
      if(ref $console and $console->typ ne 'AJAX');

    $console->table($erg);
}

# ------------------
sub _move_rules {
# ------------------
    my $self = shift || return error('No object defined!');

    return [
            [ 'y', gettext('Allways') ],
            [ 'n', gettext('Newer') ],
            [ 'collision', gettext('If collision detected') ],
          ];
}

# ------------------
sub _original_timer_rules {
# ------------------
    my $self = shift || return error('No object defined!');

    return [
            [ 'move', gettext('Move timer') ],
            [ 'keep', gettext('Keep inactive original timer') ],
            [ 'copy', gettext('Copy original timer') ],
          ];
}

1;

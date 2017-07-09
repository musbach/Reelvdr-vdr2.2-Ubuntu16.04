package XXV::MODULES::CHANNELS;

use strict;

use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'CHANNELS',
        Prereq => {
#           'modul' => 'description',
        },
        Description => gettext('This module reads new channels and stores them in the database.'),
        Status => sub{ $self->status(@_) },
        Preferences => {
            interval => {
                description => gettext('How often channels are to be updated (in seconds)'),
                default     => 3 * 60 * 60,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            empty => {
                description => gettext('Insert channels with blank PID'),
                default     => 'n',
                type        => 'confirm',
            },
            filterCA => {
                description => gettext('Filter channel list, set all wanted CA (Common Access)'),
                # 0 for FTA, 1-4 for DVB Device, 32001 for AnalogPlugin
                type        => 'list',
                options     => 'multi',
                default     => '',
                choices     => sub{
                    my $knownCA;
                    foreach my $CA (@{$self->{knownCA}}) {
                        my $desc;
                        if($CA eq '0')    { $desc = gettext("Free-to-air"); }
                        elsif($CA eq '1' 
                           or $CA eq '2' 
                           or $CA eq '3'  
                           or $CA eq '4') { $desc = sprintf(gettext("DVB card %s"),$CA);}
                        else              { $desc = sprintf("CA '%s'",$CA);      }
                        push(@{$knownCA},[$desc,$CA]);
                    }
                    return $knownCA;
                },
                check   => sub{
                    my $value = shift;
                    if(ref $value eq 'ARRAY') {
                        return join(',', @$value);
                    } else {
                        return $value;
                    }
                },
            },
            stripCH => {
                description => gettext("Cleans out channel names, only the 'long' part is visible."),
    			# Format in vdr 1.2.6 (Format "" or "long"). it show also all parts
    			# Format in vdr 1.3.10 (Format "short,long")
    			# Format in vdr 1.3.12 (Format "short,long;provider")
    			# Format in vdr 1.3.?? (Format "provider;short,long")
    			# Format in vdr 1.3.18 (Format "short,long;provider")
                default     => 'short,long;provider',
                type        => 'string',
            },
        },
        Commands => {
            cupdate => {
                description => gettext('Read channels and write them to the database'),
                short       => 'cu',
                callback    => sub{ $self->readData(@_) },
                DenyClass   => 'cedit',
                Level       => 'user',
            },
            clist => {
                description => gettext("List channels from database 'cname'"),
                short       => 'cl',
                callback    => sub{ $self->list(@_) },
            },
            cnew => {
                description => gettext("Create new channel"),
                short       => 'cne',
                callback    => sub{ $self->newChannel(@_) },
                Level       => 'user',
                DenyClass   => 'cedit',
            },
            cedit => {
                description => gettext("Edits a channel 'cid'"),
                short       => 'ced',
                callback    => sub{ $self->editChannel(@_) },
                Level       => 'user',
                DenyClass   => 'cedit',
            },
            cdelete => {
                description => gettext("Deletes one or more channels 'pos'"),
                short       => 'cdl',
                callback    => sub{ $self->deleteChannel(@_) },
                Level       => 'user',
                DenyClass   => 'cedit',
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

    my $sql = "SELECT SQL_CACHE count(*) from CHANNELS";
    my $total = $self->{dbh}->selectrow_arrayref($sql)->[0];

    $sql = "SELECT SQL_CACHE count(*) from CHANNELGROUPS";
    my $groups = $self->{dbh}->selectrow_arrayref($sql)->[0];

    return {
        message => sprintf(gettext('The system has saved %d channels from %d groups'), $total, $groups),
        complete => $total
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

    $self->{knownCA} = [0,1,2,3,4];

    # The Initprocess
    my $erg = $self->_init or return error('Problem to initialize module');

    # Interval to read channels and put to DB
    Event->timer(
        interval => $self->{interval},
        prio => 6,  # -1 very hard ... 6 very low
        cb => sub{
            lg 'Start the interval reading channels to DB!';
            $self->_readData();
        },
    );

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
    if(!tableUpdated($self->{dbh},'CHANNELS',$version,1)) {
        return 0;
    }
    if(!tableUpdated($self->{dbh},'CHANNELGROUPS',$version,1)) {
        return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS CHANNELS (
          id varchar(32) NOT NULL,
          vid int unsigned NOT NULL,
          name varchar(100) NOT NULL default '',
          frequency int unsigned  NOT NULL default '0',
          parameters varchar(100) default '',
          source varchar(8),
          symbols int unsigned default 0,
          VPID varchar(100) default '',
          APID varchar(100) default '',
          TPID varchar(100) default '',
          CA varchar(100) default '',
          SID int unsigned default 0,
          NID int unsigned default 0,
          TID int unsigned default 0,
          RID int unsigned default 0,
          grp int unsigned default 0,
          pos int unsigned NOT NULL,
          hash varchar(32) NOT NULL,
          PRIMARY KEY (hash)
        ) COMMENT = '$version'
    |);

    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS CHANNELGROUPS (
          id int unsigned not NULL,
          pos int unsigned NOT NULL,
          vid int unsigned NOT NULL,
          name varchar(100) default 'unknown',
          PRIMARY KEY (id)
        ) COMMENT = '$version'
    |);

    main::after(sub{
        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           panic ("Couldn't get modul SVDRP");
           return 0;
        }

        return $self->_readData();
    }, "CHANNELS: Read and register channels ...", 5);
    return 1;
}

# ------------------
sub _prepare {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return;
    my $pos = shift || return;
    my $grp = shift || 0;
    my $vid = shift;

    foreach my $CA (split(',', $data->[8])) {
        push(@{$self->{knownCA}},$CA);
    }

    return if($self->{empty} eq 'n' and not (($data->[6] ne "0" || $data->[7] ne "0"))); # Ignore Channels with APID = 0/TPID = 0 from PID Scan
    if($self->{filterCA} ne "") {
       my $filter = $self->{filterCA};
       $filter =~ s/\,/|/g; # Transform 0,2,400 => 0|2|400
       return 0 if(not ($data->[8] =~ /(^|\,)($filter)(\,|$)/s)); # check (^|,)(0|2|400)(,|$)
    }

	# Strip short and providername from channelname e.g ch
    if($self->{stripCH}) {
		my $ch = $data->[0];
		my $filter = $self->{stripCH};
		my @p = split(';',$filter);
		if(scalar @p == 2) {
			if(($p[0] =~ /provider/i)) { # format "provider;name"
				$ch = (split(';', $ch))[-1] if($ch =~ /;/);
				$filter = $p[1];
			}
			elsif(($p[1] =~ /provider/i)) { # format "name;provider"
				$ch = (split(';', $ch))[0] if($ch =~ /;/);
				$filter = $p[0];
			}
		}
		my @c = split(',',$filter);
		if(scalar @c == 2) {
			if(($c[0] =~ /long/i)) { # format "long,short"
				$ch = (split(',', $ch))[0] if($ch =~ /,/);
			}
			elsif(($c[1] =~ /long/i)) { # format "short,long"
				$ch = (split(',', $ch))[-1] if($ch =~ /,/);
			}
		}
	    $data->[0] = $ch if($ch);
	}

    
    # Build alternative transponder ID from frequency
    my $altid = CORE::int($data->[1]);
    if ($data->[3] !~ /^S/sig) {
      while($altid > 20000) {
        $altid = CORE::int($altid / 1000);
      }
    }

    my $id;
    $data->[12] = (split(':', $data->[12]))[0];
#   if($data->[12] && $data->[12] > 0 && $data->[12] < 100) {
    # By DVB-C gabs Probleme weil die Zahl grösser 100 war
    # Siehe auch http://www.vdr-portal.de/board/thread.php?sid=&postid=364373
    if($data->[12] && $data->[12] > 0) {
        $id = sprintf('%s-%u-%u-%u-%u', $data->[3], $data->[10], ($data->[10] || $data->[11]) ? $data->[11] : $altid, $data->[9],$data->[12]);
    } else {
        $id = sprintf('%s-%u-%u-%u', $data->[3], $data->[10], ($data->[10] || $data->[11]) ? $data->[11] : $altid, $data->[9]);
    }

    my $attr = {
          id => $id,
          name => $data->[0],
          frequency => $data->[1],
          parameters => $data->[2],
          source => $data->[3],
          symbols => $data->[4],
          VPID => $data->[5],
          APID => $data->[6],
          TPID => $data->[7],
          CA => $data->[8],
          SID => $data->[9],
          NID => $data->[10],
          TID => $data->[11],
          RID => $data->[12],
          grp => $grp,
          pos => $pos,
          vid => $vid
    };
    return $attr;
}

# ------------------
sub _replace {
# ------------------
    my $self = shift || return error('No object defined!');
    my $attr = shift || return error('No data defined!');

    my $sth = $self->{dbh}->prepare('REPLACE INTO CHANNELS(id,vid,hash,name,frequency,parameters,source,symbols,VPID,APID,TPID,CA,SID,NID,TID,RID,grp,pos) VALUES (?,?,md5(concat(?,?)),?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)');
    return $sth->execute(
        $attr->{id},
        $attr->{vid},
        $attr->{id},
        $attr->{vid},
        $attr->{name},
        $attr->{frequency},
        $attr->{parameters},
        $attr->{source},
        $attr->{symbols},
        $attr->{VPID},
        $attr->{APID},
        $attr->{TPID},
        $attr->{CA},
        $attr->{SID},
        $attr->{NID},
        $attr->{TID},
        $attr->{RID},
        $attr->{grp},
        $attr->{pos}
    );
}

# ------------------
sub _insertGrp {
# ------------------
    my $self = shift || return error('No object defined!');
    my $id = shift || return;
    my $pos = shift || return;
    my $name = shift || 0;
    my $vid = shift;

    lg sprintf('Update group of channels "%s" (%d).', $name, $pos);
    my $sth = $self->{dbh}->prepare('REPLACE INTO CHANNELGROUPS SET name=?, id=?, pos=?, vid=?');
    $sth->execute($name, $id, $pos, $vid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return $pos;
}

# ------------------
sub readData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    if($self->_readData($console)) {
      $console->redirect({url => '?cmd=clist', wait => 1})
        if($console->typ eq 'HTML');
    }
}
# ------------------
sub _readData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;

    my $deleteData = 0;
    my $updatedData = 0;
    my $changedData = 0;
    my $newChannels;
    my $channelText;
    my $nGrpCnt = 0;
    # Read channels over SVDRP
    my $hostlist = $self->{svdrp}->list_hosts();
    # read from svdrp
    foreach my $vid (@$hostlist) {
      my ($lstc,$error) = $self->{svdrp}->command('lstc :groups',$vid);
      
      my $vdrData = [ grep(/^250/, @$lstc) ];

      my $grpText;

      if($error || (scalar @$vdrData) <= 0) {
          # Delete any channels from this video disk recorder
          my $csth = $self->{dbh}->prepare('DELETE FROM CHANNELS where vid = ?');
          $csth->execute($vid)
            or return error sprintf("Couldn't execute query: %s.",$csth->errstr);

          my $dsth = $self->{dbh}->prepare('DELETE FROM CHANNELGROUPS where vid = ?');
          $dsth->execute($vid)
            or return error sprintf("Couldn't execute query: %s.",$dsth->errstr);

          my $msg = [ sprintf(gettext("No channels on '%s' available!"),$self->{svdrp}->hostname($vid)), $error ];
          $console->err($msg) if(defined $console);
          next;
      }

      my $nPos = 1;
      my $grp = 0;

      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from CHANNELS where vid = ?');
      $sth->execute($vid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $db_data = $sth->fetchall_hashref('id');

      my $gsth = $self->{dbh}->prepare('SELECT SQL_CACHE * from CHANNELGROUPS where vid = ?');
      $gsth->execute($vid)
        or return error sprintf("Couldn't execute query: %s.",$gsth->errstr);
      my $grp_data = $gsth->fetchall_hashref('id');

      lg sprintf("Compare channels database with data from %s : %d / %d", $self->{svdrp}->hostname($vid), (scalar keys %$db_data) + (scalar keys %$grp_data) ,scalar @$vdrData);
    
      foreach my $line (@{$vdrData}) {

        next if($line eq "");

        # 250-0 ... it's a group delimiter
        if($line =~ /^250[\-|\s]0\s/) { 
          if($line =~ /^250[\-|\s]0\s\:\@\d+/) { # Entry to specify the number of the next channel
            ($nPos, $grpText) = $line =~ /^250[\-|\s]0\s\:\@(\d+)\s(.+)/si;
          } else {   # Entry without specify the number of the next channel
            ($grpText) = $line =~ /^250[\-|\s]0\s\:(.+)/si;
          }

          next unless($grpText); #ignore empty group delimiter like :@500
          $nGrpCnt++;
          if(exists $grp_data->{$nGrpCnt}) {
            if($grp_data->{$nGrpCnt}->{name} ne $grpText) {
              $grp = $self->_insertGrp($nGrpCnt, $nPos, $grpText, $vid);
            } else {
              $grp = $nPos;
            }
            delete $grp_data->{$nGrpCnt};
          } else {
            $grp = $self->_insertGrp($nGrpCnt, $nPos, $grpText, $vid);
          }
        # 250-x ... it's channel x
        } else {

            unless($grp) { # Insert a default group delimiter
              $nGrpCnt++;
              $grp = 1;
              if(exists $grp_data->{$nGrpCnt}) {
                $grpText = gettext("Channels");
                if($grp_data->{$nPos}->{name} ne $grpText) {
                  $self->_insertGrp($nGrpCnt, $grp, $grpText, $vid);
                }
                delete $grp_data->{$nGrpCnt};
              } else {
                $self->_insertGrp($nGrpCnt, $grp, $grpText, $vid);
              }
            }

            # parse channel line
            ($nPos, $channelText) = $line =~ /^250[\-|\s](\d+)\s(.+)/si;

            my @data = split(':', $channelText, 13);
            $data[-1] = (split(':', $data[-1]))[0];

            if(scalar @data > 4) {
              my $row = $self->_prepare(\@data, $nPos++, $nGrpCnt, $vid);
              next unless($row);

              my $id = $row->{id};

              # Exists in DB .. update
              if(exists $db_data->{$id}) {
                # Compare fields
                foreach my $field (qw/name frequency parameters source symbols VPID APID TPID CA SID NID TID RID grp pos/) {
                  next if(not exists $row->{$field} or not $row->{$field});
                  if((not exists $db_data->{$id}->{$field})
                      or (not $db_data->{$id}->{$field})
                      or ($db_data->{$id}->{$field} ne $row->{$field})) {
                    lg sprintf('Update channel "%s" - %s.', $row->{name}, $id);
                    $self->_replace($row);
                    $updatedData++;
                    last;
                  }
                }

                # delete updated rows from hash
                delete $db_data->{$id};

              } else {
                # Not exists in DB .. insert
                lg sprintf('Add new channel "%s" - %s.', $row->{name}, $id);
                $self->_replace($row);
                $changedData++;
                # Remember new channels
                $newChannels->{$id} = $row;
              }
            }
        }
      }

      # Delete unused entrys in DB 
      if(scalar keys %$db_data > 0) {
        my @todel = keys(%$db_data);
        my $sql = sprintf('DELETE FROM CHANNELS WHERE vid = ? AND id IN (%s)', join(',' => ('?') x @todel)); 
        my $sth = $self->{dbh}->prepare($sql);
        if(!$sth->execute($vid, @todel)) {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
        }
        $deleteData += scalar @todel;
      }

      # Delete unused entrys in DB 
      if(scalar keys %$grp_data > 0) {
        my @todel = keys(%$grp_data);
        my $sql = sprintf('DELETE FROM CHANNELGROUPS WHERE vid = ? AND id IN (%s)', join(',' => ('?') x @todel)); 
        my $sth = $self->{dbh}->prepare($sql);
        if(!$sth->execute($vid, @todel)) {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
        }
        #$deleteData += scalar @todel;
      }
    }
    # sort list with CA numerical
    my %CA;
    @CA{@{$self->{knownCA}}} = ();
    @{$self->{knownCA}} = sort { if(is_numeric($a) && is_numeric($b)) {
                                    $a <=> $b
                                } else {
                                    $a cmp $b } } keys %CA;

    $self->_brandNewChannels($newChannels) if($newChannels);

    con_msg($console, sprintf(gettext("There are %d channels inserted, %d channels updated, %d channels deleted into database."), $changedData, $updatedData, $deleteData));

    return 1;
}
# ------------------
sub getnum {
# ------------------
    use POSIX qw(strtod);
    my $str = shift;
    $str =~ s/^\s+//;
    $str =~ s/\s+$//;
    $! = 0;
    my($num, $unparsed) = strtod($str);
    if (($str eq '') || ($unparsed != 0) || $!) {
        return undef;
    } else {
        return $num;
    }
}
# ------------------
sub is_numeric { defined getnum($_[0]) }
# ------------------

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id      = shift || '';
    my $params = shift;

    my %f = (
        'id' => gettext('Service'),
        'name' => gettext('Name'),
        'frequency' => gettext('Transponder frequency'),
        'parameters' => gettext('Parameters'),
        'source' => gettext('Signal source'),
        'symbols' => gettext('Symbol rate'),
        'VPID' => gettext('Video PID'),
        'APID' => gettext('Audio PID'),
        'TPID' => gettext('Teletext PID'),
        'CA' => gettext('Conditional access'),
        'SID' => gettext('SID'),
        'TID' => gettext('TID'),
        'NID' => gettext('NID'),
        'RID' => gettext('RID'),
        'grp' => gettext('Channel group'),
        'pos' => gettext('Position'),
    );

    my $sql;
    if($console->{cgi} && $console->{cgi}->param('compact')) {
      $sql = qq|
      SELECT SQL_CACHE 
          c.hash as \'$f{'id'}\',
          c.id as _cid,
          c.name as \'$f{'name'}\',
          c.grp as \'$f{'grp'}\',
          c.pos as \'$f{'pos'}\',
          cg.name as __GrpName
      from
          CHANNELS as c,
          CHANNELGROUPS as cg,
          RECORDER as r
      WHERE
          c.name LIKE ?
          AND c.grp = cg.id
          AND c.vid = cg.vid
          AND r.id = c.vid
          AND r.active = 'y'
      GROUP BY
          c.id
      ORDER BY
          c.grp asc, r.id asc,
      |;
    } else {
      $sql = qq|
SELECT SQL_CACHE 
    c.hash as \'$f{'id'}\',
    c.name as \'$f{'name'}\',
    c.frequency as \'$f{'frequency'}\',
    c.parameters as \'$f{'parameters'}\',
    c.source as \'$f{'source'}\',
    c.symbols as \'$f{'symbols'}\',
    c.VPID as \'$f{'VPID'}\',
    c.APID as \'$f{'APID'}\',
    c.TPID as \'$f{'TPID'}\',
    c.CA as \'$f{'CA'}\',
    c.SID as \'$f{'SID'}\',
    c.NID as \'$f{'NID'}\',
    c.TID as \'$f{'TID'}\',
    c.RID as \'$f{'RID'}\',
    c.grp as \'$f{'grp'}\',
    c.pos as \'$f{'pos'}\',
    cg.name as __GrpName,
    r.host as __host
from
    CHANNELS as c,
    CHANNELGROUPS as cg,
    RECORDER as r
WHERE
    c.name LIKE ?
    AND c.grp = cg.id
    AND c.vid = cg.vid
    AND r.id = c.vid
    AND r.active = 'y'
ORDER BY
    r.id asc, 
|;
    }

    my $sortby = "c.pos";
    if(exists $params->{sortby}) {
      while(my($k, $v) = each(%f)) {
        if($params->{sortby} eq $k or $params->{sortby} eq $v) {
          $sortby = $k;
          last;
        }
      }
    }
    $sql .= $sortby;
    if(exists $params->{desc} && $params->{desc} == 1)
      {  $sql .= " desc"; }
    else
      {  $sql .= " asc";  }

    my $rows;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $self->{dbh}->prepare($sql);
        $rsth->execute('%'.$id.'%')
          or return error sprintf("Couldn't execute query: %s.",$rsth->errstr);
      $rows = $rsth->rows;

      # Add limit query
      if($console->{cgi}->param('start')) {
        $sql .= " LIMIT " . CORE::int($console->{cgi}->param('start'));
        $sql .= "," . $limit;
      } else {
        $sql .= " LIMIT " . $limit;
      }
    }

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute('%'.$id.'%')
        or return con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));
    $rows = $sth->rows unless($rows);

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();
    unless($console->typ eq 'AJAX') {
      unshift(@$erg, $fields);
    }

    $console->table($erg, {
        sortable => 1,
        rows => $rows
    });
}

# ------------------
sub NameToChannel {
# ------------------
    my $self = shift || return error('No object defined!');
    my $name = shift || return undef;
    my $vid = shift;
    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where vid = ? AND UPPER(name) = UPPER( ? )');
      $sth->execute($vid, $name)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where UPPER(name) = UPPER( ? )');
      $sth->execute($name)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    }
}

# ------------------
sub GetChannel {
# ------------------
    my $self = shift || return error('No object defined!');
    my $hash = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from CHANNELS where hash = ?');
    $sth->execute($hash)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg;
}

# ------------------
sub PosToName {
# ------------------
    my $self = shift || return error('No object defined!');
    my $pos = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE name from CHANNELS where pos = ?');
    $sth->execute($pos)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{name} : undef;
}

# ------------------
sub PosToChannel {
# ------------------
    my $self = shift || return error('No object defined!');
    my $pos = shift || return undef;
    my $vid = shift;
    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where vid = ? AND pos = ?');
      $sth->execute($vid,$pos)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where pos = ?');
      $sth->execute($pos)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    }
}

# ------------------
sub ChannelGroupsArray {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $where = shift || '';
    $where = sprintf('WHERE %s', $where) if($where);

    my $sql = sprintf('SELECT SQL_CACHE %s, min(id) as id from CHANNELGROUPS %s GROUP BY name ORDER BY id, vid', $field, $where);
    my $erg = $self->{dbh}->selectall_arrayref($sql);
    return $erg;
}

# ------------------
sub ChannelArray {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $where = shift || '';
    $where = sprintf('WHERE %s', $where) if($where);

    my $sql = sprintf('SELECT SQL_CACHE %s, pos from CHANNELS %s GROUP BY id order by pos', $field, $where);
    my $erg = $self->{dbh}->selectall_arrayref($sql);
    return $erg;
}

################################################################################
# Get id of any group with same group name
sub GroupsByName {
    my $self = shift || return error('No object defined!');
    my $name = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELGROUPS where name = ? order by vid, pos');
    $sth->execute($name)
      or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchall_arrayref();
    return $erg;
}

# ------------------
sub ChannelWithGroup {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $where = shift || '';
    $where = sprintf('WHERE %s', $where) if($where);

    my $sql = sprintf(q|
SELECT SQL_CACHE %s, ( SELECT g.name FROM CHANNELGROUPS as g WHERE c.grp = g.id AND c.vid = g.vid LIMIT 1) as grp 
    from CHANNELS as c,CHANNELGROUPS as g %s GROUP BY c.id order by c.pos,c.vid
|, $field, $where);

#    my $sql = sprintf(q|SELECT SQL_CACHE %s, ( SELECT 
#        g.name FROM CHANNELGROUPS as g WHERE c.grp = g.id AND c.vid = g.vid
#        LIMIT 1) as grp from CHANNELS as c %s order by c.vid, c.pos|, $field, $where);
    my $erg = $self->{dbh}->selectall_arrayref($sql);
    return $erg;
}

# ------------------
sub ChannelIDArray {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $where = shift || '';
    $where = sprintf('WHERE %s', $where) if($where);

    my $sql = sprintf('SELECT SQL_CACHE %s, id from CHANNELS %s order by pos', $field, $where);
    my $erg = $self->{dbh}->selectall_arrayref($sql);
    return $erg;
}

# ------------------
sub ChannelHash {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $where = shift || '';
    $where = sprintf('WHERE %s', $where) if($where);

    my $sql = sprintf('SELECT SQL_CACHE * from CHANNELS %s', $where);
    my $erg = $self->{dbh}->selectall_hashref($sql, $field);
    return $erg;
}

################################################################################
# Try to find channel name by given channel id
# optionally selected by id of video disk recorder
sub ChannelToName {
    my $self = shift || return error('No object defined!');
    my $id = shift || return undef;
    my $vid = shift;

    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE name from CHANNELS where vid = ? AND id = ?');
      $sth->execute($vid, $id)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{name} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE name from CHANNELS where id = ?');
      $sth->execute($id)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{name} : undef;
    }
}

################################################################################
# Try to find channel position by given channel id
sub ChannelToPos {
    my $self = shift || return error('No object defined!');
    my $id = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE pos from CHANNELS where id = ?');
    $sth->execute($id)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{pos} : undef;
}
# ------------------
sub HashToCID {
# ------------------
    my $self = shift || return error('No object defined!');
    my $hash = shift || return undef;
    my $vid = shift;

    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where vid = ? AND hash = ?');
      $sth->execute($vid,$hash)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE id from CHANNELS where hash = ?');
      $sth->execute($hash)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{id} : undef;
    }
}

################################################################################
# Try to find channel id by given position, name or channel id
# optionally selected by id of video disk recorder
sub ToCID {
  my $self = shift || return error('No object defined!');
  my $text = shift || return undef;
  my $vid = shift;

  if($text and $text =~ /^[0-9a-f]{32}$/i) {
    return $self->HashToCID($text,$vid);
  } elsif($text =~ /^\d+$/ and (my $pch = $self->PosToChannel($text,$vid) )) {
    return $pch;
  } elsif((my $nch = $self->NameToChannel($text,$vid) )) {
    return $nch;
  } elsif(my $name = $self->ChannelToName($text,$vid)) {
    return $text;
  }
  return undef;
}

################################################################################
# Try to find channel hash by given channel position
# optionally selected by id of video disk recorder
sub PosToHash {
    my $self = shift || return error('No object defined!');
    my $pos = shift || return undef;
    my $vid = shift;

    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where vid = ? AND pos = ?');
      $sth->execute($vid,$pos)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where pos = ? ORDER BY vid');
      $sth->execute($pos)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    }
}


################################################################################
# Try to find channel hash by given channel id
# optionally selected by id of video disk recorder
sub CIDToHash {
    my $self = shift || return error('No object defined!');
    my $cid = shift || return undef;
    my $vid = shift;

    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where vid = ? AND id = ?');
      $sth->execute($vid,$cid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where id = ? ORDER BY vid');
      $sth->execute($cid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    }
}

################################################################################
# Try to find channel hash by given channel name
# optionally selected by id of video disk recorder
sub NameToHash {
    my $self = shift || return error('No object defined!');
    my $cid = shift || return undef;
    my $vid = shift;

    if($vid) {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where vid = ? AND UPPER(name) = UPPER( ? )');
      $sth->execute($vid,$cid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    } else {
      my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE hash from CHANNELS where UPPER(name) = UPPER( ? ) ORDER BY vid');
      $sth->execute($cid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      my $erg = $sth->fetchrow_hashref();
      return $erg ? $erg->{hash} : undef;
    }
}

################################################################################
# Try to find channel hash by given position, name or channel id
# optionally selected by id of video disk recorder
sub ToHash {
  my $self = shift || return error('No object defined!');
  my $query = shift || return undef;
  my $vid = shift;

  if($query and $query =~ /^[0-9a-f]{32}$/i) {
    return ($query);
  }
  if($query =~ /^\d+$/ and (my $pch = $self->PosToHash($query,$vid) )) {
    return $pch;
  }
  if(index($query, '-') != -1) {
    my $hash = $self->CIDToHash($query,$vid);
    return $hash if($hash);
  } 
  return $self->NameToHash($query,$vid);
}

# ------------------
sub getChannelType {
# ------------------
    my $self = shift || return error('No object defined!');
    my $id = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE VPID,APID from CHANNELS where id = ?');
    $sth->execute($id)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    if($erg) {
        if(exists $erg->{VPID} && $erg->{VPID}) {
          return 'TV';
        } elsif(exists $erg->{APID} && $erg->{APID}) {
          return 'RADIO';
        }
    }
    error sprintf("Unknown channel! Couldn't identify type of channel with id: %s", $id);
    return 'UNKNOWN';
}

# ------------------
sub newChannel {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $console  = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id       = shift || 0;
    my $default  = shift || 0;

    $self->editChannel($console, 0, $default);
}

# ------------------
sub editChannel {
# ------------------
    my $self    = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $cid     = shift || 0;  # If channelid then edit channel
    my $data    = shift || 0;  # Data for defaults

    my $default;
    if($cid and not ref $data) {

        my $hash = $self->ToHash($cid);
        if($hash) {
          $cid = $hash;
        } else {
          return con_err($console, sprintf(gettext("Channel '%s' does not exist in the database!"),$cid));
        }

        my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE pos, vid, name, frequency, parameters, source, symbols, VPID, APID, TPID, CA, SID, NID, TID, RID from CHANNELS where hash = ?');
            $sth->execute($cid)
            or return con_err($console, sprintf(gettext("Channel '%s' does not exist in the database!"),$cid));
        $default = $sth->fetchrow_hashref();
    } elsif (ref $data eq 'HASH') {
        $default = $data;
    }

    my $vlist = $self->{svdrp}->enum_onlinehosts();
    my $questions = [
        'pos' => {
            typ     => 'hidden',
            def     => $default->{pos} || 0,
        },
        'vid' => {
            typ     => scalar @$vlist > 1 ? 'list' : 'hidden',
            def     => $default->{vid} || $self->{svdrp}->primary_hosts(),
            choices => $vlist,
            msg     => gettext('Which video disk recorder should used'),
        }
    ];

    my $newpos = [
        'NEWPOS' => {
            typ     => 'integer',
            msg     => gettext('Position'),
            def     => int($default->{pos}),
            check   => sub{
                my $value = shift;
                if(int($value) > 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        } ];
    #Change Position only on editing
    push(@{$questions},@{$newpos})
        if($cid);

    my $more = [
        'name' => {
            typ     => 'string',
            def     => $default->{name} || gettext('New channel'),
            msg     => gettext("Name"),
            check   => sub{
                my $value = shift || return;
                if($value ne '') {
                    return $value;
                } else {
                    return undef, gettext('This is required!');
                }
            },
        },
        'frequency' => {
            typ     => 'integer',
            msg     => gettext('Transponder frequency'),
            def     => int($default->{frequency}) || 0,
            check   => sub{
                my $value = shift;
                if(int($value) > 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'source' => {
            typ     => 'string',
            def     => $default->{source} || "",
            msg     => gettext("Signal source"),
            check   => sub{
                my $value = shift || return;
                if($value ne '') {
                    return $value;
                } else {
                    return undef, gettext('This is required!');
                }
            },
        },
        'parameters' => {
            typ     => 'string',
            def     => $default->{parameters} || "",
            msg     => gettext("Various parameters, depending on signal source"),
            check   => sub{
                my $value = shift || return;
                if($value ne '') {
                    return $value;
                } else {
                    return undef, gettext('This is required!');
                }
            },
        },
        'symbols' => {
            typ     => 'integer',
            msg     => gettext('Symbol rate'),
            def     => int($default->{symbols}) || 27500,
            check   => sub{
                my $value = shift;
                if(int($value) > 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'VPID' => {
            typ     => 'integer',
            msg     => gettext('Video PID (VPID)'),
            def     => int($default->{VPID}) || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'APID' => {
            typ     => 'string',
            def     => $default->{APID} || 0,
            msg     => gettext("Audio PID (APID)"),
            check   => sub{
                my $value = shift || return;
                if($value ne '') {
                    return $value;
                } else {
                    return undef, gettext('This is required!');
                }
            },
        },
        'TPID' => {
            typ     => 'integer',
            msg     => gettext('Teletext PID (TPID)'),
            def     => int($default->{TPID}) || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'CA' => {
            typ     => 'string',
            def     => $default->{CA} || 0,
            msg     => gettext("Conditional access (CA)"),
            check   => sub{
                my $value = shift || return;
                if($value ne '') {
                    return $value;
                } else {
                    return undef, gettext('This is required!');
                }
            },
        },
        'SID' => {
            typ     => 'integer',
            msg     => gettext('Service ID (SID)'),
            def     => int($default->{SID}) || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'NID' => {
            typ     => 'integer',
            msg     => gettext('Network ID (NID)'),
            def     => int($default->{NID})  || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'TID' => {
            typ     => 'integer',
            msg     => gettext('Transport stream ID (TID)'),
            def     => int($default->{TID})  || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
        'RID' => {
            typ     => 'integer',
            msg     => gettext('Radio ID (RID)'),
            def     => int($default->{RID})  || 0,
            check   => sub{
                my $value = shift;
                if(int($value) >= 0) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
        },
    ];
    push(@{$questions},@{$more});

    # Ask Questions
    my $datasave = $console->question(($cid ? gettext('Edit channel')
                                            : gettext('New channel')), $questions, $data);

    if(ref $datasave eq 'HASH') {
        my ($erg,$error) = $self->saveChannel($datasave, $datasave->{pos});

        unless($error) {
            debug sprintf('%s channel with name "%s" is saved%s',
                ($cid ? 'Changed' : 'New'),
                $data->{name},
                ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
                );
                $console->message($erg);
        } else {
            my $msg = sprintf('%s channel with name "%s" does\'nt saved : %s',
                ($cid ? 'Changed' : 'New'),
                $data->{Name},
                $error
                );
                $console->err($msg);
        }
        sleep(1);
        $self->_readData($console);

        $console->redirect({url => '?cmd=clist', wait => 1})
            if($console->typ eq 'HTML');
    }
}

# ------------------
sub saveChannel {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $pos = shift || 0;

    my ($erg,$error);

    if($pos
       && defined $data->{NEWPOS}
       && $pos != $data->{NEWPOS} ) {
       ($erg,$error) = $self->{svdrp}->command(
            sprintf("movc %s %s",
            $pos,
            $data->{NEWPOS}
       ));
       $pos = $data->{NEWPOS};
       return ($erg,$error) if($error);
    }

    ($erg,$error) = $self->{svdrp}->command(
        sprintf("%s %s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s",
            $pos ? "modc $pos" : "newc",
            $data->{name},
            int($data->{frequency}),
            $data->{parameters},
            $data->{source},
            int($data->{symbols}),
            int($data->{VPID}),
            $data->{APID},
            int($data->{TPID}),
            $data->{CA} ? $data->{CA} : '0',
            int($data->{SID}),
            int($data->{NID}),
            int($data->{TID}),
            int($data->{RID})
        )
    );
    return ($erg,$error);
}

# ------------------
sub deleteChannel {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $channelid = shift || return con_err($console, gettext("No channel defined for deletion! Please use cdelete 'pos'!"));
    my $answer  = shift || 0;

    my @ch  = split(/[^0-9a-f]/, $channelid);
    map {
      my $hash = $self->ToHash($_);
      $_ = $hash if($hash);
    } @ch;

    my $sql = sprintf('SELECT SQL_CACHE vid,pos,name,hash from CHANNELS where hash in (%s) ORDER BY pos desc', join(',' => ('?') x @ch)); 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute(@ch)
        or return con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));

    while (my $c = $sth->fetchrow_hashref()) {

        if(ref $console and $console->{TYP} eq 'CONSOLE') {
            $console->table({
              gettext('Position')              => $c->{pos},
              gettext('Name')                  => $c->{name},
              gettext('Video disk recorder')   => $c->{vid},
            });
            my $confirm = $console->confirm({
                typ   => 'confirm',
                def   => 'y',
                msg   => gettext('Would you like to delete this channel?'),
            }, $answer);
            next if(!$answer eq 'y');
        }

        debug sprintf('Delete channel with name "%s"%s',
            $c->{name},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );

        $self->{svdrp}->queue_add(sprintf("delc %d", $c->{pos}), $c->{vid});

        # remove channel from request, if found inside database
        my $i = 0;
        for my $x (@ch) {
          if ( $x eq $c->{hash} ) { # Remove known MD5 from user request
            splice @ch, $i, 1;
          } else {
            $i++;
          }
        }
    }

    con_err($console,
      sprintf(gettext("Channel '%s' does not exist in the database!"), 
      join('\',\'',@ch))) 
          if(scalar @ch);

    if($self->{svdrp}->queue_count()) {
        my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos
        $console->msg($erg, $error)
            if(ref $console);

        sleep(1);

        if($self->_readData($console)) {
          $console->redirect({url => '?cmd=clist', wait => 1})
            if(ref $console and $console->typ eq 'HTML');
        }
    } else {
        $console->err(gettext("Found no channel to delete!"));
    }

    return 1;
}

# ------------------
sub _brandNewChannels {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $attr = shift || return;

    my @lines;
    foreach my $id (keys %$attr) {
        my $c = $attr->{$id};
        push(@lines, sprintf(gettext('New %s channel: %s on position: %d %s'),
            ($c->{VPID}
                ? gettext('TV')
                : gettext('Radio')),
            $c->{name},
            $c->{pos},
            (($c->{CA} && (!is_numeric($c->{CA}) || $c->{CA} > 16)) ? gettext('(encrypted)') : ''),
        ));
        last if(25 < scalar @lines );
    }

    my $rm = main::getModule('EVENTS');
    $rm->news(
        sprintf(gettext('Found %d new channels!'), scalar keys %$attr),
        join("\r\n",@lines),
        'clist',
        undef,
        'veryinteresting',
    );
    return 1;
}

# ------------------
sub buildSourceList {
# ------------------
    my $self  = shift || return error('No object defined!');
    my $vid  = shift || return undef;

    my @DVBCardsTyp;

    my $sql = qq|
select 
    Source from CHANNELS
where 
    vid = ?
group by 
    Source
ORDER BY
    Source asc
|;
    my $sth = $self->{dbh}->prepare($sql);
       $sth->execute($vid)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);

    my $result = $sth->fetchall_arrayref();
    foreach my $source (@$result ) {
      push(@DVBCardsTyp,$source->[0]);
    }
    my $cards = join(',',@DVBCardsTyp);
    lg sprintf("Founded sources of channels : %s", $cards ? $cards : 'none');
    return $cards;
}

1;

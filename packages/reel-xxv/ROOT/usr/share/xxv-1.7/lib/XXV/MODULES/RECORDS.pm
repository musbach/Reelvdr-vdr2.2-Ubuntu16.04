package XXV::MODULES::RECORDS;

use strict;

use Tools;
use File::Find;
use File::Copy;
use File::Path;
use File::Basename;
use File::stat;
use Linux::Inotify2;
use Image::Magick;

$SIG{CHLD} = 'IGNORE';

use constant INDEXTRUCTSIZE => 8;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');

    my $args = {
        Name => 'RECORDS',
        Prereq => {
            'Time::Local' => 'efficiently compute time from local and GMT time ',
            'Digest::MD5 qw(md5_hex)' => 'Perl interface to the MD5 Algorithm',
            'Linux::Inotify2' => 'scalable directory/file change notification'
        },
        Description => gettext('This module manages recordings.'),
        Status => sub{ $self->status(@_) },
        Preferences => {
            commandfile => {
                description => sprintf(gettext("Path of file '%s'"),'reccmds.conf'),
                default     => '/var/lib/vdr/reccmds.conf',
                type        => 'file',
                required    => gettext("This is required!"),
            },
            reading => {
                description => gettext('How often recordings are to be updated (in minutes)'),
                default     => 180,
                type        => 'integer',
                required    => gettext("This is required!"),
            },
            fullreading => {
                description => gettext('How often recordings are to be completely read in (in hours)'),
                default     => 24,
                type        => 'integer',
                required    => gettext("This is required!"),
            },
            seriesorder => {
                description => gettext('Default order for series'),
                type        => 'list',
                choices     => [
                    [gettext('By date'), 'date'],
                    [gettext('By title'), 'title']
                ],
                default     => 'date',
                level       => 'guest'
            },
            previewbinary => {
                description => gettext('Location of used program to produce thumbnails on your system.'),
                default     => '/usr/bin/mplayer',
                type        => 'file',
                required    => gettext("This is required!"),
            },
            previewcommand => {
                description => gettext('The program used to create thumbnails'),
                type        => 'list',
                choices     => [
                    [gettext('None'), 'Nothing'],
                    ['MPlayer1.0pre5', 'MPlayer1.0pre5'],
                    ['MPlayer1.0pre6', 'MPlayer1.0pre6'],
                    ['vdr2jpeg',       'vdr2jpeg'],
                ],
                default     => 'Nothing',
                required    => gettext("This is required!"),
            },
            previewcount => {
                description => gettext('Produce how many thumbnails'),
                default     => 3,
                type        => 'integer',
            },
            previewlistthumbs => {
                description => gettext('Display recording list with thumbnails?'),
                default     => 'n',
                type        => 'confirm',
                level       => 'guest'
            },
            previewimages => {
                description => gettext('Common directory for preview images'),
                default     => '/var/cache/xxv/preview',
                type        => 'dir',
                required    => gettext('This is required!'),
            },
            vfat => {
                description => gettext('VDR compiled for VFAT system (VFAT=1)'),
                default     => 'y',
                type        => 'confirm',
            },
            xsize => {
                description => gettext('Preview image width'),
                default     => 180,
                type        => 'integer',
                required    => gettext('This is required!'),
                check   => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 8 and $value < 4096) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
            },
        },
        Commands => {
            rdisplay => {
                description => gettext("Display recording 'rid'"),
                short       => 'rd',
                callback    => sub{ $self->display(@_) },
                DenyClass   => 'rlist',
            },
            rlist => {
                description => gettext('List of recordings'),
                short       => 'rl',
                callback    => sub{ $self->list(@_) },
                DenyClass   => 'rlist',
            },
            rsearch => {
                description => gettext("Search recordings 'text'"),
                short       => 'rs',
                callback    => sub{ $self->search(@_) },
                DenyClass   => 'rlist',
            },
            rupdate => {
                description => gettext('Update recordings'),
                short       => 'ru',
                callback    => sub{ $self->refresh(@_) },
                Level       => 'user',
                DenyClass   => 'redit',
            },
            rdelete => {
                description => gettext("Delete recording 'rid'"),
                short       => 'rr',
                callback    => sub{ $self->delete(@_) },
                Level       => 'user',
                DenyClass   => 'redit',
            },
            rrecover => {
                description => gettext("Recover deleted recordings"),
                short       => 'rru',
                callback    => sub{ $self->recover(@_) },
                Level       => 'user',
                DenyClass   => 'redit',
            },
            redit => {
                description => gettext("Edit recording 'rid'"),
                short       => 're',
                callback    => sub{ $self->redit(@_) },
                Level       => 'user',
                DenyClass   => 'redit',
            },
            rconvert => {
                description => gettext("Convert recording 'rid'"),
                short       => 'rc',
                callback    => sub{ $self->reccmds(@_) },
                Level       => 'user',
                DenyClass   => 'redit',
            },
            rplay => {
                description => gettext("Play recording 'rid' in the VDR."),
                short       => 'rpv',
                callback    => sub{ $self->play(@_) },
                Level       => 'user',
                DenyClass   => 'remote',
            },
            rcut => {
                description => gettext("Cut recording 'rid' in vdr"),
                short       => 'rcu',
                callback    => sub{ $self->cut(@_) },
                Level       => 'user',
                DenyClass   => 'remote',
            },
            rsuggest => {
                hidden      => 'yes',
                callback    => sub{ $self->suggest(@_) },
                DenyClass   => 'rlist',
            },
            rimage => {
                hidden      => 'yes',
                short       => 'ri',
                callback    => sub{ $self->image(@_) },
                binary      => 'cache'
            }
        },
        RegEvent    => {
            'deleteRecord' => {
                Descr => gettext('Create event entries if a recording has been deleted.'),

                # You have this choices (harmless is default):
                # 'harmless', 'interesting', 'veryinteresting', 'important', 'veryimportant'
                Level => 'important',

                # Search for a spezial Event.
                # I.e.: Search for an LogEvent with match
                # "Sub=>text" = subroutine =~ /text/
                # "Msg=>text" = logmessage =~ /text/
                # "Mod=>text" = modname =~ /text/
                SearchForEvent => {
                    Msg => 'delr',
                },
                # Search for a Match and extract the information
                # of the id
                # ...
                Match => {
                    id => qr/delr\s+(\d+)/s,
                },
                Actions => [
                    q|sub{  my $args = shift;
                            my $event = shift;
                            my $record  = getDataById($args->{id}, 'RECORDS', 'id');
                            my $epg = main::getModule('EPG')->getId($record->{eventid}, 'title, subtitle, description');
                            my $t = [$epg->{title}];
                            push(@$t,$epg->{subtitle}) if($epg->{subtitle});

                            my $topic = sprintf(gettext("Recording deleted: %s"),join('~',@$t));

                            my $description = '';
                            if($epg->{description}) {
                               $description .= $epg->{description};
                               # $description .= "\r\n";
                            }

                            main::getModule('EVENTS')->news($topic, $description, "display", $record->{eventid}, $event->{Level});
                        }
                    |,
                ],

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

    my $version = 34; # Must be increment if rows of table changed
    # this tables hasen't handmade user data,
    # therefore old table could dropped if updated rows
    if(!tableUpdated($self->{dbh},'RECORDS',$version,1)) {
        return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS RECORDS (
          eventid int unsigned NOT NULL,
          id int unsigned NOT NULL,
          hash varchar(32) NOT NULL,
          path text NOT NULL,
          track text NOT NULL,
          priority tinyint default '1', 
          lifetime tinyint default '99', 
          status set('new', 'cutted'),
          size int unsigned default '0', 
          cutlength int unsigned default '0',
          filever int unsigned default '0', 
          framerate int unsigned default '25', 
          marks text,
          type enum('TV', 'RADIO', 'UNKNOWN') default 'TV',
          preview text NOT NULL,
          aux text,
          addtime timestamp,
          PRIMARY KEY (eventid),
          UNIQUE KEY (eventid)
        ) COMMENT = '$version'
    |);

    $self->{JOBS} = [];
    $self->{after_updated} = [];
    $self->{countReading} = 0;
    $self->{inotify} = undef;
    $self->{lastupdate} = 0;

    main::after(sub{
        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           return 0;
        }
        $self->{svdrp}->updated(  sub{
            return $self->_watch_changerecorder(@_);
        });

        $self->{timers} = main::getModule('TIMERS');
        unless($self->{timers}) {
           return 0;
        }
        $self->{keywords} = main::getModule('KEYWORDS');
        unless($self->{keywords}) {
           return 0;
        }

        $self->_watch_recorder();

        # Interval to read recordings and put to DB
        Event->timer(
            interval => $self->{reading} * 60,
            prio => 6,  # -1 very hard ... 6 very low
            cb => sub {
                my $forceUpdate = ($self->{countReading} % ( $self->{fullreading} * 60 / $self->{reading} ) == 0);
                if($forceUpdate || (time - $self->{lastupdate}) > ($self->{reading}/2) ) {
                  $self->_readData(undef,undef,$forceUpdate);
                  $self->{lastupdate} = time;
                }
                $self->{countReading} += 1;
            },
        );
        $self->_readData(undef,undef,undef);
        $self->{countReading} += 1;
        $self->{lastupdate} = time;
        return 1;
    }, "RECORDS: Store recordings in database ...", 20);

    1;
}

# ------------------
sub status {
# ------------------
    my $self = shift || return error('No object defined!');
    my $lastReportTime = shift;

    my $total = 0;
    my $unseen = 0;
    {
      my $sth = $self->{dbh}->prepare("SELECT SQL_CACHE count(*) as count,SUM(FIND_IN_SET('new',status)) as unseen from RECORDS");
      if(!$sth->execute())
      {
          error sprintf("Couldn't execute query: %s.",$sth->errstr);
      } else {
          my $erg = $sth->fetchrow_hashref();
          $total = $erg->{count} if($erg && $erg->{count});
          $unseen = $erg->{unseen} if($erg && $erg->{unseen});
      }
    }
    my $sql = qq|
SELECT SQL_CACHE 
    r.hash as __Id,
    r.eventid as __EventId,
    e.title,
    e.subtitle,
    FROM_UNIXTIME(e.duration,'%h:%i:%s') as Duration,
    e.starttime as __RecordStart
FROM
    RECORDS as r,
    OLDEPG as e
WHERE
    e.eventid = r.eventid
    and UNIX_TIMESTAMP(e.starttime) > ?
ORDER BY
    e.starttime asc
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($lastReportTime)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();
    unshift(@$erg, $fields);
    return {
        message => sprintf(gettext('%d new recordings since last report time %s'),
                             (scalar @$erg -1), datum($lastReportTime))
        ,table   => $erg
        ,complete => $total
        ,unseen => $unseen
    };
}

sub _watch_recorder {
    my $self = shift || return error('No object defined!');

    my $hostlist = $self->{svdrp}->list_hosts(); # Query active hosts;
    foreach my $vid (@$hostlist) {
      $self->_watch_addrecorder($vid);
    }
}

sub _watch_filename {
    my $self = shift || return error('No object defined!');
    my $vid = shift;

    my $videodirectory = $self->{svdrp}->videodirectory($vid);
      unless($videodirectory && -d $videodirectory) {
        my $hostname = $self->{svdrp}->hostname($vid);
        error(sprintf("Missing video directory on %s!",$hostname));
        return;
    }
    my $updatefile = sprintf("%s/.update",$videodirectory);
    if( -r $updatefile) {
       return resolv_symlink($updatefile);
    } 
    error(sprintf("Missing state file %s!",$updatefile));
    return undef;
}

sub _watch_addrecorder {
    my $self = shift || return error('No object defined!');
    my $vid = shift;

    my $updatefile = $self->_watch_filename($vid);
    if($updatefile) {

      if(exists $self->{inotify} 
         && exists $self->{inotify}->{$updatefile}) {
          $self->{inotify}->{$updatefile}->{count} += 1;
          return;
        }
      $self->{inotify}->{$updatefile}->{handle} = new Linux::Inotify2
        or panic sprintf("Unable to create new inotify object %s: %s",$updatefile, $!);

      if($self->{inotify}->{$updatefile}->{handle}) {
        $self->{inotify}->{$updatefile}->{count} = 1;
        # Bind watch to event::io
        $self->{inotify}->{$updatefile}->{event} = Event->io( 
          fd => $self->{inotify}->{$updatefile}->{handle}->fileno, 
          poll => 'r', 
          cb => sub { $self->{inotify}->{$updatefile}->{handle}->poll }
        );
        # watch update file
        $self->{inotify}->{$updatefile}->{watch} =
          $self->{inotify}->{$updatefile}->{handle}->watch(
            $updatefile, 
            IN_ALL_EVENTS, 
            sub {
                   my $e = shift; 
                   $self->_notify_updatefile($e, $vid); 
                }
            );
          lg(sprintf("Monitor file '%s'",$updatefile));
        } else {
          delete $self->{inotify}->{$updatefile};
        }
    }
}

sub _watch_removerecorder {
    my $self = shift || return error('No object defined!');
    my $vid = shift;
    my $force = shift;

    unless(exists $self->{inotify}) {
      return;
    }

    my $updatefile = $self->_watch_filename($vid);
    if($updatefile 
        && exists $self->{inotify}->{$updatefile}) {
        unless($force) {
          if($self->{inotify}->{$updatefile}->{count} > 1) {
            $self->{inotify}->{$updatefile}->{count} -= 1;
            return;
          }
        }
        lg(sprintf("Remove watching file '%s'",$updatefile));
        $self->{inotify}->{$updatefile}->{watch}->cancel()
          if($self->{inotify}->{$updatefile}->{watch});

        delete $self->{inotify}->{$updatefile}->{watch};
        delete $self->{inotify}->{$updatefile}->{event};
        delete $self->{inotify}->{$updatefile}->{handle};
        delete $self->{inotify}->{$updatefile};
    }
}

sub _watch_changerecorder {
    my $self = shift || return error('No object defined!');
    my $vid = shift;
    my $state = shift;
    if($state && $state eq 'y') {
      $self->_watch_addrecorder($vid);
    } else {
      $self->_watch_removerecorder($vid);
    }
}
# ------------------
# Callback to reread data if /video/.update changed by VDR 
# trigged by file notifcation from inotify
sub _notify_updatefile {
# ------------------
  my $self = shift || return error('No object defined!');
  my $e = shift;
  my $vid = shift;

  if($e->{mask} & (IN_UNMOUNT|IN_Q_OVERFLOW|IN_IGNORED)) {
      error(sprintf("Can't monitor events, '%s' is no longer mounted",$e->{w}{name})) if($e->{mask} & IN_UNMOUNT);
      error(sprintf("Monitor events for '%s' have been lost",$e->{w}{name})) if($e->{mask} & IN_Q_OVERFLOW);
      $self->_watch_removerecorder($vid,'force'); 
      $e->w->cancel;
  }

  lg sprintf("New recordings, on recorder '%s' notify events for %s received event: %x", 
            $self->{svdrp}->hostname($vid),
            $e->fullname, $e->mask);

  if((time - $self->{lastupdate}) > 3  # Only if last update prior 3 seconds (avoid callback chill)
     && $self->_readData()) {

        $self->{lastupdate} = time;

        # Update preview images after five minutes
        my $after = ($self->{timers}->{prevminutes}) * 60 * 2;
        $after = 300 if($after <= 300);

        Event->timer(
        interval => 60,
        after => $after, 
        cb => sub {
          if((time - $self->{lastupdate}) >= ($after - 30)) {
              if($self->_readData(undef, undef, undef, $vid)) {
                $self->{lastupdate} = time;
              }
              $_[0]->w->cancel;
            }
          }
        );
    }
}

# ------------------
sub dot1000 {
# ------------------
    my $t = reverse shift;
    $t =~ s/(\d{3})(?=\d)(?!\d*\.)/$1./g;
    return scalar reverse $t;
}

# ------------------
sub parseData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $vid = shift || return error('No vid defined!'); 
    my $vdata = shift || return error('No data defined!');
    my ($event, $idx, $id, $date, $hour, $minute, $new, $duration, $title, $day, $month, $year);
    my $data = {};

    my $version = $self->{svdrp}->vdr_version($vid);

    foreach my $record (@{$vdata}) {
        if($version >= 10721) { 
            # 250-1 24.04.11 22:12 2:06* Discovery~Die Rose von Kerrymore Spielfilm D/2000
          ($id, $date, $hour, $minute, $duration, $new, $title)
            = $record =~ /^250[\-|\s](\d+)\s+([\d|\.]+)\s+(\d+)\:(\d+)\s+([\d+|\:]+)(.?).*?\s+(.+)/si;

           my ($dh,$dm) = $duration =~ /^(\d+)\:(\d+)$/;
           $duration = ($dh * 3600) + ($dm * 60);
        } else { # older VDR < 10721
          # 250-1  01.11 15:14* Discovery~Die Rose von Kerrymore Spielfilm D/2000
          ($id, $date, $hour, $minute, $new, $title)
            = $record =~ /^250[\-|\s](\d+)\s+([\d|\.]+)\s+(\d+)\:(\d+)(.?).*?\s+(.+)/si;
        }

        unless($id) {
          error sprintf("Couldn't parse data from video disk recorder : '%s'",$record);
          next;
        }

        # Split date
        ($day,$month,$year) = $date =~ /^(\d+)\.(\d+)\.(\d+)$/;

        $year += 100
            if($year < 70); # Adjust year, 0-69 => 100-169 (2000-2069)
        $year += 1900
            if($year < 1900); # Adjust year, 70-99 => 1977-1999 ... 2000-2069

        $event->{id} = $id;
        
        my @status;
        push(@status,'new') 
          if($new && $new eq '*');
        my @t = split(/~/,$title);
        if($t[-1] =~ /^%/) {
          push(@status,'cutted');
          $t[-1] =~ s/^%//g;
        }

        $event->{status} = join(',',@status);
        $event->{track} = join('~',@t);

        $event->{starttime} = timelocal(0,$minute,$hour,$day,$month-1, $year);
        $event->{title} = $title;

        if($duration) {
            $event->{duration} = $duration;
        }

        $idx = sprintf("%s~%s",$title,$event->{starttime});
        %{$data->{$idx}} = %{$event};
    }
    return ($data);
}

# ------------------
sub scandirectory {
# ------------------
    my $self = shift || return error('No object defined!');
    my $directory = shift;
    my $typ = shift;

    my $files = (); # Hash with md5 and path to recording
    find(
            {
                wanted => sub{
                    if($File::Find::name =~ /\.$typ\/(\d{3}.vdr)|(\d{5}.ts)$/sig) {  # Lookup for *.rec/001.vdr or *.rec/001.ts
                      if(-r $File::Find::name) {
                          my $filename = $File::Find::name;
                          my $path = $File::Find::dir;
                          if($path =~ /\.$typ$/) {
		                        my $hash = md5_hex($path);
		                        unless(exists $files->{$hash}) {
		                          my $rec;
		                          $rec->{path} = $path;

		                          if($filename =~ /\.vdr$/) {
		                            # Splitt 2005-01-16.04:35.88.99.rec
		                            my ($year, $month, $day, $hour, $minute, $priority, $lifetime)
		                               = (basename($path)) =~ /^(\d+)\-(\d+)\-(\d+)\.(\d+)[\:|\.](\d+)\.(\d+)\.(\d+)\./s;
		                            $rec->{year} = int($year);
		                            $rec->{month} = int($month);
		                            $rec->{day} = int($day);
		                            $rec->{hour} = int($hour);
		                            $rec->{minute} = int($minute);
		                            $rec->{priority} = int($priority);
		                            $rec->{lifetime} = int($lifetime);
		                            $rec->{filever} = 1;
		                          } else {
		                            # Splitt 2009-10-24.19.30.10-0.rec
		                            my ($year, $month, $day, $hour, $minute, $channel, $counter)
		                               = (basename($path)) =~ /^(\d+)\-(\d+)\-(\d+)\.(\d+)[\:|\.](\d+)\.(\d+)\-(\d+)\./s;
		                            $rec->{year} = int($year);
		                            $rec->{month} = int($month);
		                            $rec->{day} = int($day);
		                            $rec->{hour} = int($hour);
		                            $rec->{minute} = int($minute);
		                            # $rec->{channel} = $channel;
		                            # $rec->{counter} = $counter;
		                            $rec->{filever} = 2;
		                          }
		                          # convert path to title
		                          my $title = dirname($path);
		                          $title =~ s/^$directory//g;
		                          $title =~ s/^\///g;
		                          $rec->{title} = $self->converttitle($title);

		                          # add file
		                          push(@{$rec->{files}},$filename);
		                          $files->{$hash} = $rec;

		                        } else {
		                          push(@{$files->{$hash}->{files}},$filename);
		                        }
													}
                        } else {
                            lg "Permissions deny, couldn't read : $File::Find::name";
                        }
                    }
                },
                follow_skip => 2,
                follow_fast => 1
            },
        $directory
    );
    return $files;
}

# ------------------
sub _readData {
# ------------------
  my $self = shift || return error('No object defined!');
  my $console = shift;
  my $waiter = shift;
  my $forceUpdate = shift; # Read manual or Once at day, make full scan
  my $onlyvid = shift;

  my $outdatedRecordings;
  if($onlyvid) {
      my $sth = $self->{dbh}->prepare('SELECT hash,CONCAT_WS("~",e.title,e.subtitle,UNIX_TIMESTAMP(e.starttime)) as idx FROM RECORDS as r,OLDEPG as e where r.eventid = e.eventid and vid = ?');
      if(!$sth->execute($onlyvid)) {
          con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));
      }
      $outdatedRecordings = $sth->fetchall_hashref('idx');
  } else  {
      my $sth = $self->{dbh}->prepare('SELECT hash,CONCAT_WS("~",e.title,e.subtitle,UNIX_TIMESTAMP(e.starttime)) as idx FROM RECORDS as r,OLDEPG as e where r.eventid = e.eventid');
      if(!$sth->execute()) {
          con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));
      }
      $outdatedRecordings = $sth->fetchall_hashref('idx');
  }

  if($forceUpdate) {
      $self->{dbh}->do('DELETE FROM RECORDS');
      $self->{keywords}->removesource('recording');
  }
  my $err = [];
  my $insertedData = 0;
  my $updatedState = 0;
  my $removedData = 0;
  my @todel;

  my $hostlist; 
  $hostlist = [ $onlyvid ] if($onlyvid);
  $hostlist = $self->{svdrp}->list_unique_recording_hosts() unless($hostlist);
  # Read recording over SVDRP
  foreach my $vid (@$hostlist) {
    my ($lstr,$error) = $self->{svdrp}->command('lstr',$vid);
    my $hostname = $self->{svdrp}->hostname($vid);
    if($error || !(defined $lstr)) {
      if($console) {
        my $msg = [
          sprintf(gettext("Can't read recordings from %s !"),$hostname), 
          $error 
        ];
        $console->err($msg);
      }
			# ignore data from offline host
			if($self->{svdrp}->is_host_online($vid) ne 'yes') {
		    my $osth = $self->{dbh}->prepare('SELECT CONCAT_WS("~",e.title,e.subtitle,UNIX_TIMESTAMP(e.starttime)) as idx FROM RECORDS as r,OLDEPG as e where r.eventid = e.eventid and vid = ?');
		    if(!$osth->execute($vid)) {
		        con_err($console, sprintf("Couldn't execute query: %s.",$osth->errstr));
		    }
		    my $ignoreRecordings = $osth->fetchall_hashref('idx');
		  	foreach my $k (keys %{$ignoreRecordings}) {
		    	delete $outdatedRecordings->{$k};
				}
			}
      next;
    }

    # Get state from used harddrive (/video)
    my ($disk,$error2) = $self->{svdrp}->command('stat disk',$vid);
    if(!$error2 and $disk->[1] and $disk->[1] =~ /^250/s) {
        #250 473807MB 98028MB 79%
        my ($total, $totalUnit, $free, $freeUnit, $percent)
            = $disk->[1] =~ /^250[\-|\s](\d+)(\S+)\s+(\d+)(\S+)\s+(\S+)/s;
        error sprintf("Unsupported unit '%s' to calc free capacity",$freeUnit) unless($freeUnit eq 'MB');

        $self->{Capacity}->{$vid}->{Message} = sprintf(gettext("Used %s, total %s%s, free %s%s on '%s'"),$percent, dot1000($total), $totalUnit,  dot1000($free), $freeUnit, $hostname);
        $self->{Capacity}->{$vid}->{Free}    = $free;
        $self->{Capacity}->{$vid}->{duration} = 0;
        $self->{Capacity}->{$vid}->{size} = 0;
    } else {
        error(sprintf("Couldn't get disc state from %s\n%s", $hostname, join("\n", @$disk)));
        $self->{Capacity}->{$vid}->{Message} = sprintf(gettext("Unknown disc capacity on '%s'!"),$hostname);
        $self->{Capacity}->{$vid}->{Free}     = 0;
        $self->{Capacity}->{$vid}->{duration} = 0;
        $self->{Capacity}->{$vid}->{size} = 0;
    }

    my $vdata = [ grep(/^250/, @$lstr) ];
    # There none recordings present
    unless(scalar @$vdata) {
        unless($forceUpdate) {
          # then delete old recordings
          my $sth = $self->{dbh}->prepare('DELETE FROM RECORDS as r,OLDEPG as e where e.vid = ? and r.eventid = e.eventid');
          if(!$sth->execute($vid)) {
              con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));
              next;
          }
        }
        next;
    }



    my $l = 0;

    my $vdrData = $self->parseData($vid, $vdata);

    # Adjust waiter max value now.
    $waiter->max(scalar keys %$vdrData)
        if(ref $console && ref $waiter);

    my $db_data;
    unless($forceUpdate) {
        # read database for compare with vdr data
        my $sql = qq|SELECT SQL_CACHE r.eventid as eventid, r.id as id, 
                        UNIX_TIMESTAMP(e.starttime) as starttime, 
                        e.duration, r.status, 
                        CONCAT_WS("~",e.title,e.subtitle) as title, 
                        CONCAT_WS("~",e.title,e.subtitle,UNIX_TIMESTAMP(e.starttime)) as idx,
                        UNIX_TIMESTAMP(e.addtime) as addtime,
                        r.path,
                        r.type,
                        r.size,
                        r.filever,
                        r.framerate,
                        r.marks,
                        r.hash
                 from RECORDS as r,OLDEPG as e 
                 where e.vid = ? and r.eventid = e.eventid |;
       my $sth = $self->{dbh}->prepare($sql);
       if(!$sth->execute($vid)) {
             error sprintf("Couldn't execute query: %s.",$sth->errstr);
             $console->err(sprintf(gettext("Couldn't query recordings from database!")))
               if($console);
             next;
       }
       $db_data = $sth->fetchall_hashref('idx');
       debug sprintf( 'Compare recording database with data from %s : %d / %d', 
                    $hostname,
                    scalar keys %$db_data,scalar keys %$vdrData );
    }

    my $files; # Hash with md5 and path to recording

    # Compare this Hashes
    foreach my $h (keys %{$vdrData}) {
        my $event = $vdrData->{$h};

        # Exists in DB ... update
        if($db_data && exists $db_data->{$h}) {

          $waiter->next(++$l,undef, sprintf(gettext("Update recording '%s'"), 
                                            $db_data->{$h}->{title}))
              if(ref $waiter);

          # Compare fields
          foreach my $field (qw/id status/) {
            if($db_data->{$h}->{$field} ne $event->{$field}) {

              $self->_updateState($db_data->{$h}, $event);

              $updatedState++;
              last;
            }
          }

          # Update Duration and maybe preview images, if recordings added during timer run 
          if(($db_data->{$h}->{starttime} + $db_data->{$h}->{duration} + 7200) > $db_data->{$h}->{addtime}) {
              my $duration = $self->_recordinglength($db_data->{$h}->{path},$db_data->{$h}->{filever},$db_data->{$h}->{framerate} );
              if($duration != $db_data->{$h}->{duration}) {

                  # Update duration at database entry
                  $db_data->{$h}->{duration} = $duration;
                  $db_data->{$h}->{size} = $self->_recordingsize(
                                                        $db_data->{$h}->{path},
                                                        $db_data->{$h}->{filever},
                                                        ($duration * INDEXTRUCTSIZE * $db_data->{$h}->{framerate}));

                  # set addtime only if called from EVENT::TIMER
                  # avoid generating preview image during user actions
                  # it's should speedup reading recordings
                  unless($console) {
                      $db_data->{$h}->{addtime} = time;
                      # Make preview and remove older Preview images
                      my $job = $self->videoPreview( $db_data->{$h}, 1);
                      if($job) {
                        push(@{$self->{JOBS}}, $job);
                        $self->_updatePreview($self->{dbh}, $job->{hash}, $db_data->{$h}->{preview});
                      }
                  }
                  $self->_updateEvent($db_data->{$h});
                  $self->_updateFileSize($db_data->{$h});

                  $updatedState++;
              }
          }
          
          
          $self->{Capacity}->{$vid}->{duration} += $db_data->{$h}->{duration};
          $self->{Capacity}->{$vid}->{size} += $db_data->{$h}->{size};
          
          delete $outdatedRecordings->{$h};

          # delete updated rows from hash
          delete $db_data->{$h};

        } else {
              $waiter->next(++$l,undef, sprintf(gettext("Analyze recording '%s'"), 
                                                     $event->{title}))
              if(ref $waiter);

          # Read VideoDir only at first call
          unless($files) {
            my $videodirectory = $self->{svdrp}->videodirectory($vid);
            unless($videodirectory && -d $videodirectory) {
              $console->err(sprintf(gettext("Missing video directory on %s!"),$hostname))
                if($console);
              last;
            }
            $files = $self->scandirectory( $videodirectory, 'rec');
          }
          unless($files && keys %{$files}) {
            last;
          }

          my $info = $self->analyze($vid,$files,$event,$forceUpdate);
          if(ref $info eq 'HASH') {
              $self->{Capacity}->{$vid}->{duration} += $info->{duration};
              $self->{Capacity}->{$vid}->{size} += $info->{size};

              if($self->insert($info)) {
                  delete $outdatedRecordings->{$h};
                  $insertedData++;

                  $self->{keywords}->insert('recording',$info->{hash},$info->{keywords});

              } else {
                  push(@{$err},sprintf(gettext("Can't add recording '%s' into database!"),$info->{title}));
              }
          } else {
              push(@{$err},sprintf(gettext("Can't assign recording '%s' to file!"),$event->{title}));
          }
        }
      }

      if($forceUpdate) {
        foreach my $idx (keys %{$files}) {
           push(@{$err},sprintf(gettext("Recording '%s' without id or unique title and date from '%s'!"),$files->{$idx}->{title},$hostname));
        }
      }

      if($db_data && scalar keys %$db_data > 0) {
        foreach my $t (keys %{$db_data}) {
            delete $outdatedRecordings->{$t};
            push(@todel,$db_data->{$t}->{hash});
        }
      }

      $removedData += $db_data ? scalar keys %$db_data : 0;
    }

    debug sprintf 'Finish .. %d new recordings inserted, %d recordings updated, %d recordings removed',
           $insertedData, $updatedState, $removedData;

    map { push(@todel,$outdatedRecordings->{$_}->{hash}); } keys %{$outdatedRecordings};
    if(!$forceUpdate && scalar @todel) {
      my $sql = sprintf('DELETE FROM RECORDS WHERE hash IN (%s)', join(',' => ('?') x @todel)); 
      my $sth = $self->{dbh}->prepare($sql);
      $sth->execute(@todel)
          or return con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));

      $self->{keywords}->remove('recording',\@todel);
    }

    # use store capacity and recordings length to calc free capacity
    my $totalDuration = 0;
    my $totalSpace = 0;
    my $totalFree = 0;
    my $Message = [];

    foreach my $vid (keys %{$self->{Capacity}}) {
      push(@$Message,$self->{Capacity}->{$vid}->{Message});
      $totalDuration += $self->{Capacity}->{$vid}->{duration};
      $totalSpace += $self->{Capacity}->{$vid}->{size};
      $totalFree += $self->{Capacity}->{$vid}->{Free};
    }

    $self->{CapacityMessage} = join("\n",@$Message);
    $self->{CapacityTotal} = $totalDuration;
    if($totalSpace > 1) {
      $self->{CapacityFree} = int(($totalFree * $totalDuration) / $totalSpace);
    } else {
      $self->{CapacityFree} = int($totalFree * 3600 / 2000); # use 2GB at one hour as base
    }
    if(($totalFree + $totalSpace) > 1) {
      $self->{CapacityPercent}  = ($totalSpace * 100 / ($totalFree + $totalSpace));
    } else {
      $self->{CapacityPercent}  = 0;
    }



    # alte PreviewDirs loeschen
    foreach my $hash (@todel) {
        my $dir = sprintf('%s/%s_shot', $self->{previewimages} , $hash);
        lg sprintf("Remove old preview files : '%s'",$dir);
        deleteDir($dir);
    }

    # Previews im fork erzeugen
    if(scalar @{$self->{JOBS}}) {
        #Changes made after the fork() won't be visible in the parent process
        my @jobs = @{$self->{JOBS}};
        $self->{JOBS} = [];

        my $child = fork(); 
        if ($child < 0) {
          con_err($console, sprintf("Couldn't fork : %s",$!));
        } elsif ($child > 0) {

        } elsif ($child == 0) {
            my $modM = main::getModule('MUSIC');
            if($modM->{mdbh}) {
              $modM->{mdbh}->{InactiveDestroy} = 1;
            }
            $self->{dbh}->{InactiveDestroy} = 1;
            my $dbh = $self->{dbh}->clone();
            error(sprintf("Couldn't clone database handle : %s",$!)) unless($dbh);
            while($dbh && scalar @jobs > 0) {
                my $job = shift (@jobs);

                my $preview = [];
                debug sprintf('Call command "%s"', $job->{command});
                my $erg = system(sprintf('nice -n 19 %s', $job->{command}));

		#schlue: enter copy of preview
		keeppreview( $job->{previewdir}, $job->{command} );

                my @images = glob(sprintf('%s/[0-9]*.jpg', $job->{previewdir}));
                foreach(@images) {
                  my $frame = basename($_);
                  $frame =~ s/\.jpg$//ig;
                  push(@{$preview},$frame)
                    if(scalar @{$preview} < $self->{previewcount});
                }
                $self->_updatePreview($dbh, $job->{hash},$preview);
            }
            undef $dbh;
            exit 0;
        }
    }

    # Delete all old EPG entrys
    if($forceUpdate || $removedData) {
        my $sqldeleteEvents = qq|
DELETE FROM OLDEPG 
  WHERE 
  (UNIX_TIMESTAMP(starttime) + duration) < (UNIX_TIMESTAMP() - 86400) 
  and eventid not in 
      ( SELECT eventid FROM RECORDS )
|;
      $self->{dbh}->do($sqldeleteEvents)
        or error sprintf("Couldn't execute query: %s, %s.",$sqldeleteEvents, $DBI::errstr);
   }

   $self->updated() if($insertedData);

   # last call of waiter
   $waiter->end() if(ref $waiter);

    $console->start() if(ref $waiter && ref $console);
    if(scalar @{$err} == 0) {
        $console->message(sprintf(gettext("Write %d recordings to the database."), ($insertedData + $updatedState))) if(ref $console);
    } else {
        unshift(@{$err}, sprintf(gettext("Write %d recordings to the database. Couldn't assign %d recordings."), ($insertedData + $updatedState) , scalar @{$err}));
        con_err($console,$err);
    }
    return (scalar @{$err} == 0);
}

# Routine um Callbacks zu registrieren und
# diese nach dem Aktualisieren der Aufnahmen zu starten
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
sub refresh {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;

    my $waiter;
    if(ref $console && $console->typ eq 'HTML') {
      $waiter = $console->wait(gettext("Get information on recordings ..."),0,1000,'no');
    } else {
      con_msg($console,gettext("Get information on recordings ..."));
    }

    if($self->_readData($console,$waiter,'force')) {

      $console->redirect({url => '?cmd=rlist', wait => 1})
          if(ref $console and $console->typ eq 'HTML');

      return 1;
    }
    return 0;
}

# ------------------
sub insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $attr = shift || return 0;

    my $sth = $self->{dbh}->prepare(
    qq|
     REPLACE INTO RECORDS
        (eventid, track, id, hash, path, priority, lifetime, status, size, cutlength, framerate, filever, marks, type, preview, aux, addtime )
     VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,NOW())
    |);

    $attr->{marks} = ""
        if(not $attr->{marks});

    return $sth->execute(
        $attr->{eventid},
        $attr->{track},
        $attr->{id},
        $attr->{hash},
        $attr->{path},
        $attr->{priority},
        $attr->{lifetime},
        $attr->{status},
        $attr->{size},
        $attr->{cutlength},
        $attr->{framerate},
        $attr->{filever},
        $attr->{marks},
        $attr->{type},
        $attr->{preview},
        $attr->{aux}
    );
}

# ------------------
sub _updateEvent {
# ------------------
    my $self = shift || return error('No object defined!');
    my $event = shift || return undef;
    
    my $sth = $self->{dbh}->prepare('UPDATE OLDEPG SET duration=?, starttime=FROM_UNIXTIME(?), addtime=FROM_UNIXTIME(?) where eventid=?');
    if(!$sth->execute($event->{duration},$event->{starttime},$event->{addtime},$event->{eventid})) {
        error sprintf("Couldn't update event!: '%s' !",$event->{eventid});
        return undef;
    }
    return $event;
}

# ------------------
sub _updateState {
# ------------------
    my $self = shift || return error('No object defined!');
    my $oldattr = shift || return error ('No data defined!');
    my $attr = shift || return error ('No data to replace!');

    my $sth = $self->{dbh}->prepare('UPDATE RECORDS SET id=?, status=?, addtime=NOW() where hash=?');
    return $sth->execute($attr->{id},$attr->{status},$oldattr->{hash});
}

# ------------------
sub _updatePreview {
# ------------------
    my $self = shift || return error('No object defined!');
    my $dbh = shift || return error ('No dbh defined!');
    my $hash = shift || return error ('No data defined!');
    my $preview = shift || return error ('No data to replace!');
    my $images = join(',',@{$preview});
    my $sth = $dbh->prepare('UPDATE RECORDS SET preview=?, addtime=NOW() where hash=?');
    return $sth->execute($images,$hash);
}
# ------------------
sub _updateFileSize {
# ------------------
    my $self = shift || return error('No object defined!');
    my $attr = shift || return error ('No data to replace!');

    my $sth = $self->{dbh}->prepare('UPDATE RECORDS SET size=?, addtime=NOW() where hash=?');
    return $sth->execute($attr->{size},$attr->{hash});
}

# ------------------
sub analyze {
# ------------------
    my $self = shift || return error('No object defined!');
    my $vid = shift; # ID of Video disk recorder
    my $files = shift; # Hash with md5 and path to recording
    my $vdrdata = shift;
    my $forceUpdate = shift; # Read manual or Once at day, make full scan

    lg sprintf('Analyze recording "%s"', $vdrdata->{title} );

    my $info = $self->videoInfo($files,$vdrdata->{title}, $vdrdata->{starttime});
    unless($info && ref $info eq 'HASH') {
      error sprintf("Couldn't find recording '%s' with id : '%s' !",$vdrdata->{title}, $vdrdata->{id});
      return 0;
    }

    my $event = $self->SearchEpgId( $vid, $vdrdata->{starttime}, $info->{duration}, $vdrdata->{title}, $info->{channel} );
    if($event) {
        my $id = $event->{eventid};
        $event->{addtime} = time;
        $event->{duration} = int($info->{duration});
        $event->{starttime} = $vdrdata->{starttime};
        $event = $self->_updateEvent($event);
        unless($event) {
          return 0;
        }
    } else {
        # Sollte kein Event gefunden werden so muss dieser in OLDEPG mit
        # den vorhandenen Daten (lstr nummer) eingetragen werden und eine PseudoEventId (min(eventid)-1)
        # erfunden werden ;)
        my @t = split('~', $vdrdata->{title});
        my $title = $vdrdata->{title};
        my $subtitle;
        if(scalar @t > 1) { # Splitt genre~title | subtitle
            $subtitle = delete $t[-1];
            $title = join('~',@t);
        }

        $event = $self->createOldEventId($vid, $vdrdata->{id}, $vdrdata->{starttime}, $title, $subtitle, $info);
        unless($event) {
          error sprintf("Couldn't create event!: '%s' !",$vdrdata->{id});
          return 0;
        }
    }

    # Make Preview
    my $job = $self->videoPreview( $info, 0, $forceUpdate );
    push(@{$self->{JOBS}}, $job) if($job);

    my $ret = {
        hash => $info->{hash},
        title => $vdrdata->{title},
        track => $vdrdata->{track},
        id => $vdrdata->{id},
        duration => $info->{duration},
        Start => $vdrdata->{starttime},
        path  => $info->{path},
        priority  => $info->{priority},
        lifetime  => $info->{lifetime},
        eventid => $event->{eventid},
        type  => $info->{type} || 'UNKNOWN',
        status => $vdrdata->{status},
        size => $info->{size},
        cutlength => $info->{cutlength},
        framerate => $info->{framerate},
        filever => $info->{filever},
        aux => $info->{aux},
        keywords => $info->{keywords}
    };
    $ret->{marks} = join(',', @{$info->{marks}})
        if(ref $info->{marks} eq 'ARRAY');
    $ret->{preview} = join(',', @{$info->{preview}})
        if(ref $info->{preview} eq 'ARRAY');

    return $ret;
}

# ------------------
sub videoInfo {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $files   = shift; # Hash with md5 and path to recording
    my $title   = shift; # title from VDR
    my $starttime   = shift; # time from VDR

    my @ltime = localtime($starttime);
    my $month=$ltime[4]+1;
    my $day=$ltime[3];
    my $hour=$ltime[2];
    my $minute=$ltime[1];

    foreach my $hash (keys %{$files}) {
        my $rec = $files->{$hash};
        if($rec->{title} eq $title
#          && $rec->{year} == $year
           && $rec->{month} == $month
           && $rec->{day} == $day
           && $rec->{hour} == $hour
           && $rec->{minute} == $minute) {

              my $info = $self->readinfo($rec->{path},$rec->{filever});    

              $info->{hash} = $hash;
              $info->{path} = $rec->{path};
              $info->{filever} = $rec->{filever};
              if($rec->{filever} != 2) {
                $info->{priority} = $rec->{priority};
                $info->{lifetime} = $rec->{lifetime};
              }
              $info->{duration} = $self->_recordinglength($rec->{path}, $rec->{filever}, $info->{framerate});
              $info->{size} = $self->_recordingCapacity($rec->{files},
                                 ($info->{duration} * INDEXTRUCTSIZE * $info->{framerate}));

              my $marks = $self->_readmarks($rec->{path}, $rec->{filever});
              map { $info->{$_} = $marks->{$_}; } keys %{$marks}; 
              $info->{cutlength} = $self->_calcmarks($info->{marks} , $info->{duration}, $info->{framerate});

              delete $files->{$hash}; # remove from hash, avoid double lookup
              return $info;
        }
    }

    error sprintf("Couldn't assign recording with title: '%s' (%s/%s %s:%s)", $title,$month,$day,$hour,$minute);
    return 0;
}

#-------------------------------------------------------------------------------
# get cut marks from marks.vdr
sub _readmarks {
    my $self     = shift || return error('No object defined!');
    my $path    = shift || return error ('No recording path defined!');
    my $filever    = shift;

    my $status;
    # Schnittmarken ermitteln
    my $marks = $self->_marksfile($path, $filever);
    if(-r $marks) {
        my $data = load_file($marks)
            or error sprintf("Couldn't read file '%s'",$marks);
        if($data) {
            foreach my $zeile (split("\n", $data)) {
                # 0:35:07.09 moved from [0:35:13.24 Logo start] by checkBlackFrameOnMark
                my ($mark) = $zeile =~ /^(\d+\:\d+\:\d+\.\d+)/sg;
                push(@{$status->{marks}}, $mark)
                    if(defined $mark);
            }
        }
    }
    return $status;
}

sub _marksfile {
    my $self     = shift || return error('No object defined!');
    my $path    = shift || return error ('No recording path defined!');
    my $filever    = shift;

    my $f;
    if($filever == 2) {
      $f = "marks";
    } else {
      $f = "marks.vdr";
    }

    return sprintf("%s/%s", $path, $f);
}

sub _calcmarks {
    my $self = shift;
    my $marks = shift;
    my $duration = shift;
    my $framerate = shift;

    unless ($marks) {
      return $duration;
    }
    unless ($framerate) {
      return $duration;
    }
    
    my $frames = 0;
    for (my $i = 0; $i < (scalar(@$marks)); $i += 2) {
        my ($h,$m,$s,$f) = split /[:.]/,$marks->[$i];
        my $startframe = ($h * 3600 + $m * 60 + $s)* ($framerate) + $f;

        if ($marks->[$i+1]) {
            my ($h,$m,$s,$f) = split /[:.]/,$marks->[$i + 1];
            my $endframe = ($h * 3600 + $m * 60 + $s)* ($framerate) + $f;
            $frames += $endframe - $startframe;
        } else {
            $frames += ($duration * ($framerate)) - $startframe;
            last;
        }
    }
    return $frames / $framerate;
}

sub _infofile {
    my $self     = shift || return error('No object defined!');
    my $path    = shift || return error ('No recording path defined!');
    my $filever    = shift;

    my $f;
    if($filever && $filever == 2) {
      $f = "info.txt";
    } else {
      $f = "info.vdr";
    }
    return sprintf("%s/%s", $path, $f);
}
#-------------------------------------------------------------------------------
# get information about recording from info.vdr
sub readinfo {
    my $self     = shift || return error('No object defined!');
    my $path    = shift || return error ('No recording path defined!');
    my $filever    = shift;

    my $info;
    $info->{type} = 'UNKNOWN'; #TV / RADIO
    # define framerate PAL 25, NTSC 30
    $info->{framerate} = Tools->FRAMESPERSECOND;

    # get description
    my $file = $self->_infofile($path,$filever);
    if(-r $file) {
        my $text = load_file($file);
        if($text) {
          my $modC = main::getModule('CHANNELS');
          foreach my $zeile (split(/[\r\n]/, $text)) {
              if($zeile =~ /^D\s+(.+)/s) {
                  $info->{description} = $1;
                  $info->{description} =~ s/\|/\r\n/g;            # pipe used from vdr as linebreak
                  $info->{description} =~ s/^\s+//;               # no leading white space
                  $info->{description} =~ s/\s+$//;               # no trailing white space
              }
              elsif($zeile =~ /^C\s+(\S+)/s) {
                  $info->{channel} = $1;
                  $info->{type} = $modC->getChannelType($info->{channel});
              }
              elsif($zeile =~ /^T\s+(.+)$/s) {
                  $info->{title} = $1;
              }
              elsif($zeile =~ /^S\s+(.+)$/s) {
                  $info->{subtitle} = $1;
              }
              elsif($zeile =~ /^V\s+(.+)$/s) {
                  $info->{vpstime} = $1;
              }
              elsif($zeile =~ /^F\s+(.+)$/s) {
                  my $rate = int($1);
                  if($rate > 0) {
                    $info->{framerate} = $rate;
                  }
              }
              elsif($zeile =~ /^L\s+(.+)$/s) {
                  $info->{lifetime} = int($1);
              }
              elsif($zeile =~ /^P\s+(.+)$/s) {
                  $info->{priority} = int($1);
              }
              elsif($zeile =~ /^G\s+(.+)$/s) {
                  $info->{content} = $1;
              }
              elsif($zeile =~ /^R\s+(.+)$/s) {
                  $info->{rating} = int($1);
              }
              elsif($zeile =~ /^X\s+1\s+(.+)$/s) {
                  $info->{video} = $1;
              }
              elsif($zeile =~ /^X\s+2\s+(.+)$/s) {
                  $info->{audio} .= "\n" if($info->{audio});
                  $info->{audio} .= $1;
              }
              elsif($zeile =~ /^@\s+(.+)$/s) {
                  $info->{aux} = $1;
                  $info->{aux} =~ s/\|/\r\n/g;            # pipe used from vdr as linebreak
                  $info->{aux} =~ s/^\s+//;               # no leading white space
                  $info->{aux} =~ s/\s+$//;               # no trailing white space

                  my $xml = $self->{keywords}->parsexml($info->{aux});
          #       $info->{keywords} = $xml->{'autotimer'}
          #         if($xml && defined $xml->{'autotimer'} );
                  $info->{keywords} = $xml->{'keywords'}
                    if($xml && defined $xml->{'keywords'} );
              }
          }
        }
    } else {
      error sprintf("Can't read file %s", $file);
    }
    return $info;
}
#-------------------------------------------------------------------------------
# store information about recording into info.vdr
sub saveinfo {
    my $self     = shift || return error('No object defined!');
    my $path    = shift || return error ('No recording path defined!');
    my $info    = shift || return error ('No information defined!');

    my $out = "";
    foreach my $h (keys %{$info}) {
      $info->{$h} =~ s/\r\n/\|/g;            # pipe used from vdr as linebreak
      $info->{$h} =~ s/\n/\|/g;              # pipe used from vdr as linebreak
      $info->{$h} =~ s/^\s+//;               # no leading white space
      $info->{$h} =~ s/\s+$//;               # no trailing white space
    }

    my $file = $self->_infofile($path,$info->{filever});
    my $status = $self->readinfo($path,$info->{filever});
    foreach my $h (keys %{$info}) {
      $info->{$h} =~ s/\r\n/\|/g;            # pipe used from vdr as linebreak
      $info->{$h} =~ s/\n/\|/g;              # pipe used from vdr as linebreak
      $info->{$h} =~ s/^\s+//;               # no leading white space
      $info->{$h} =~ s/\s+$//;               # no trailing white space
      $status->{$h} = $info->{$h};
    }

    if(defined $status->{title} && $status->{title}) {
      $out .= "T ".  $status->{title} . "\n";
    }
    if(defined $status->{subtitle} && $status->{subtitle}) {
      $out .= "S ".  $status->{subtitle} . "\n";
    }
    if(defined $status->{channel} && $status->{channel}) {
      $out .= "C ".  $status->{channel} . "\n";
    }
    if(defined $status->{description} && $status->{description}) {
      $out .= "D ".  $status->{description} . "\n";
    }
    if(defined $status->{vpstime} && $status->{vpstime}) {
      $out .= "V ".  $status->{vpstime} . "\n";
    }
    if(defined $status->{video} && $status->{video}) {
      $out .= "X 1 ".  $status->{video} . "\n";
    }
    if(defined $status->{audio} && $status->{audio}) {
      foreach my $line (split(/\|/, $status->{audio})) {
        $line =~ s/^\s+//;               
        $line =~ s/\s+$//;               
        $out .= "X 2 ". $line  . "\n" if($line);
      }
    }
    if(defined $status->{aux} && $status->{aux}) {
      $out .= "@ ".  $status->{aux} . "\n";
    }
    if($info->{filever} == 2) {
      if(defined $status->{framerate} && $status->{framerate}) {
        $out .= "F ".  $status->{framerate} . "\n";
      }
      if(defined $status->{content} && $status->{content}) {
        $out .= "G ".  $status->{content} . "\n";
      }
      if(defined $status->{rating} && $status->{rating}) {
        $out .= "R ".  $status->{rating} . "\n";
      }
      if(defined $status->{lifetime} && $status->{lifetime}) {
        $out .= "L ".  $status->{lifetime} . "\n";
      }
      if(defined $status->{priority} && $status->{priority}) {
        $out .= "P ".  $status->{priority} . "\n";
      }
    }

    return save_file($file, $out);
}


#-------------------------------------------------------------------------------
sub qquote {
    my $str = shift;
    $str =~ s/(\')/\'\\\'\'/g;

#    $metas = '!$`' unless($metas);
#    $metas =~ s/\]/\\]/g;
#    $str =~ s/([$metas])/\\$1/g;

    return "'$str'";
}

# ------------------
sub videoPreview {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $info    = shift || return error ('No information defined!');
    my $rebuild = shift || 0;
    my $forceUpdate = shift || 0; # Read manual or Once at day, make full scan

    $info->{preview} = [];

    if ($self->{previewcommand} eq 'Nothing') {
        return 0;
    }
    if($info->{type} and $info->{type} eq 'RADIO') {
        return 0;
    }
    # Mplayer
    unless(-x $self->{previewbinary}) {
      error("Couldn't find executable file as usable preview command!");
      return 0;
    }

    # Videodir
    if(! -d $info->{path} ) {
        error sprintf("Missing path '%s'! %s",$info->{path}, $!);
        return 0;
    }

    my $outdir = sprintf('%s/%s_shot', $self->{previewimages}, $info->{hash});

    my $count = $self->{previewcount};
    # Stop here if enough files present
    my @images = glob("$outdir/[0-9]*.jpg");
    if(scalar @images >= $count && !$rebuild) {
      my $loop = 0;
      foreach(@images) {
        my $frame = basename($_);
        $frame =~ s/\.jpg$//ig;
        push(@{$info->{preview}},$frame);
        shift(@{$info->{preview}}) if(scalar @{$info->{preview}} >= $self->{previewcount});
        last if($loop++ > $self->{previewcount});
      }
      return 0;
    }
    # add some reserved images (if recordings frames has incorrect data ) 
    $count += (($count / 2)+1);

    my $startseconds = ($self->{timers}->{prevminutes} * 60) * 2;
    my $endseconds = ($self->{timers}->{afterminutes} * 60) * 2;
    my $stepseconds = ($info->{duration} - ($startseconds + $endseconds)) / $count;
    # reduced interval on short movies
    if($stepseconds <= 0 or ($startseconds + ($count * $stepseconds)) > $info->{duration}) {
        $stepseconds = $info->{duration} / ( $count + 2 ) ;
        $startseconds = $stepseconds;
    }

    if($info->{duration} <= $count or $stepseconds <= 1) {  # dont' create to early ?
        lg sprintf("Recording just started, create images for '%s' later.", $info->{title});
        return 0;
    }

    deleteDir($outdir) if(scalar @images && $rebuild);

    # or stop if log's present
    my $log = sprintf('%s/preview.log', $outdir);
    if(-e $log && !$forceUpdate) {
        return 0;
    }

    unless(-d $outdir) {
      if(!mkpath($outdir)) {
        error sprintf("Couldn't make path '%s' : %s",$outdir,$!);
        return 0;
      }
    }

    my @files;
    my @frames;
    if ($self->{previewcommand} eq 'vdr2jpeg') {

        my $m = ref $info->{marks} eq 'ARRAY' ? scalar(@{$info->{marks}}) : 0;
        if($m > 1 && $info->{duration}) {
            my $total = $info->{duration} * $info->{framerate};
            my $limit = $count * 4;
            my $x = 2;
            my $y = 1;
            while (scalar @frames < $count && $x < $limit) {
                my $f = int($total / $x * $y); # 1/2, 1/3, 2/3, 1/4, 2/4, 3/4, 1/5, 2/5, 3/5 ...
                for (my $n = 0;$n < $m; $n += 2 ) {
                    my $fin = $self->_mark2frames(@{$info->{marks}}[$n],$info->{framerate});
                    my $fout = $total;
                    $fout = $self->_mark2frames(@{$info->{marks}}[$n+1],$info->{framerate}) if($n+1 < $m);

                    if ($f >= $fin && $f <= $fout 
                        && 0 == (grep {$f == $_;} @frames) 
                        ) {
                        push(@frames, $f);
                        last;
                    }
                }
                ++$y;
                if($y >= $x) { $x += 2; $y = 1; }
            }
        }

        my $s = int($startseconds * $info->{framerate});
        while (scalar @frames < $count) {
            push(@frames, $s);
            $s += int( $stepseconds * $info->{framerate} );
        }
    } else {
        if($info->{filever} == 2) {
          @files = glob(sprintf("%s/[0-9]*.ts",$info->{path}));
        } else {
          @files = glob(sprintf("%s/[0-9]*.vdr",$info->{path}));
        }
        foreach (@files) { $_ = qquote($_); }
    }

    my $scalex = $self->{xsize} || 180;
    my $mversions = {
      'MPlayer1.0pre5' => sprintf("%s -noautosub -noconsolecontrols -nosound -nolirc -nojoystick -quiet -vo jpeg -jpeg outdir=%s -ni -ss %d -sstep %d -vf scale -zoom -xy %d -frames %d %s >> %s 2>&1",
                              $self->{previewbinary}, qquote($outdir), 
                              $startseconds / 5, $stepseconds / 5, $scalex, 
                              $count, join(' ',@files), qquote($log)),
      'MPlayer1.0pre6' => sprintf("%s -noautosub -noconsolecontrols -nosound -nolirc -nojoystick -quiet -vo jpeg:outdir=%s -ni -ss %d -sstep %d -vf scale -zoom -xy %d -frames %d %s >> %s 2>&1",
                              $self->{previewbinary}, qquote($outdir), 
                              $startseconds / 5, $stepseconds / 5, $scalex, 
                              $count, join(' ',@files), qquote($log)),
      'vdr2jpeg'       => sprintf("%s -r %s -f %s -x %d -o %s >> %s 2>&1",
                              $self->{previewbinary}, qquote($info->{path}), 
                              join(' -f ', @frames), $scalex, qquote($outdir), 
                              qquote($log)),
    };
    return {
      command    => $mversions->{$self->{previewcommand}},
      previewdir => $outdir,
      hash  => $info->{hash}
    }
}


sub _mark2frames{
   my $self = shift;
   my $mark = shift;
   my $framerate = shift;

   my($h, $m, $s, $f) = split /[:.]/, $mark;
   my $frame = (3600 * $h + 60 * $m + $s) * $framerate + $f ;
   return $frame;
};

# ------------------
sub SearchEpgId {
# ------------------
    my $self = shift || return error('No object defined!');
    my $vid = shift; # ID of Video disk recorder
    my $start = shift || return error('No start time defined!');
    my $dur = shift || return 0;
    my $title = shift || return error('No title defined!');
    my $channel = shift;    

    my $sth;
    my $bis = int($start + $dur);
    if($channel && $channel ne "") {
        $sth = $self->{dbh}->prepare(
qq|SELECT SQL_CACHE * FROM OLDEPG WHERE 
        vid = ?
    AND UNIX_TIMESTAMP(starttime) >= ? 
    AND UNIX_TIMESTAMP(starttime)+duration <= ? 
    AND CONCAT_WS("~",title,subtitle) = ?
    AND channel_id = ?|);
        $sth->execute($vid,$start,$bis,$title,$channel)
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    } else {
        $sth = $self->{dbh}->prepare(
qq|SELECT SQL_CACHE * FROM OLDEPG WHERE 
        vid = ?
    AND UNIX_TIMESTAMP(starttime) >= ? 
    AND UNIX_TIMESTAMP(starttime)+duration <= ? 
    AND CONCAT_WS("~",title,subtitle) = ?|);
        $sth->execute($vid,$start,$bis,$title)
            or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    }
    return 0 if(!$sth);

    my $erg = $sth->fetchrow_hashref();
    return $erg;
}

# ------------------
sub createOldEventId {
# ------------------
    my $self = shift || return error('No object defined!');
    my $vid = shift; # ID of Video disk recorder
    my $id = shift || return error('No eventid defined!');
    my $start = shift || return error('No start time defined!');
    my $title = shift || return error('No title defined!');
    my $subtitle = shift;
    my $info = shift;

    my $attr = {
        title => $title,
        subtitle => $subtitle,
        description => $info->{description} || "",
        channel => $info->{channel} || "<undef>",
        duration => $info->{duration},
        starttime => $start,
        vpstime => $info->{vpstime} || 0,
        video => $info->{video} || "",
        audio => $info->{audio} || "",
        content => $info->{content} || "",
        rating => $info->{rating} || "",
    };

    $attr->{eventid} = $self->{dbh}->selectrow_arrayref('SELECT SQL_CACHE max(eventid)+1 from OLDEPG')->[0];
    $attr->{eventid} = 0x70000000 if(not defined $attr->{eventid} or $attr->{eventid} < 0x6FFFFFFF );

    lg sprintf('Create event "%s" into OLDEPG', $subtitle ? $title .'~'. $subtitle : $title);

    my $sth = $self->{dbh}->prepare(
q|REPLACE INTO OLDEPG(vid, eventid, title, subtitle, description, channel_id, 
                      duration, starttime, vpstime, video, audio, content, rating, addtime) 
  VALUES (?,?,?,?,?,?,?,FROM_UNIXTIME(?),FROM_UNIXTIME(?),?,?,?,?,NOW())|);

    $sth->execute(
        $vid,
        $attr->{eventid},
        $attr->{title},
        $attr->{subtitle},
        $attr->{description},
        $attr->{channel},
        int($attr->{duration}),
        $attr->{starttime},
        $attr->{vpstime},
        $attr->{video},
        $attr->{audio},
        $attr->{content},
        $attr->{rating}
    );

    return $attr;
}

# ------------------
sub display {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift;

    unless($id) {
        con_err($console,gettext("No recording defined for display! Please use rdisplay 'rid'"));
        return;
    }

    my $sql = qq|
SELECT SQL_CACHE 
    r.hash as RecordId,
    r.eventid,
    e.duration as Duration,
    r.marks as Marks,
    r.priority,
    r.lifetime,
    UNIX_TIMESTAMP(e.starttime) as StartTime,
    UNIX_TIMESTAMP(e.starttime) + e.duration as StopTime,
    e.title as Title,
    e.subtitle as SubTitle,
    e.description as Description,
    r.status as New,
    r.type as Type,
    (SELECT Name
      FROM CHANNELS as c
      WHERE e.channel_id = c.Id
      LIMIT 1) as Channel,
    preview,
    cutlength
from
    RECORDS as r,OLDEPG as e
where
    r.eventid = e.eventid
    and hash = ?
|;

    my $erg;
#   my $fields;
    my $sth = $self->{dbh}->prepare($sql);
    if(!$sth->execute($id)
#     || !($fields = $sth->{'NAME'})
      || !($erg = $sth->fetchrow_hashref())) {
        con_err($console,gettext("This recording does not exist in the database!"));
        return undef;
    }

    if($console->{TYP} ne 'HTML') {
      $erg->{StartTime} = datum($erg->{StartTime},'voll');
      $erg->{StopTime} = datum($erg->{StopTime},'voll');
    }

    $self->_loadreccmds;
    my @reccmds = @{$self->{reccmds}};
    map { 
      $_ =~ s/\s*\:.*$//;
    } @reccmds;

    if($self->{keywords} && $self->{keywords}->{active} eq 'y') {
      my ($keywords,$keywordmax,$keywordmin) = $self->{keywords}->list('recording',[ $id ]);
      $erg->{'keywords'} = $keywords;
    }

    my $param = {
        reccmds => \@reccmds
    };
    $console->table($erg,$param);
}

# ------------------
sub play {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || return con_err($console,gettext("No recording defined for playback! Please use rplay 'rid'."));
    my $params  = shift;

    my $sql = qq|SELECT SQL_CACHE vid, id, hash, duration, framerate 
    FROM RECORDS as r, OLDEPG as e 
    WHERE e.eventid = r.eventid and hash = ?|;
    my $sth = $self->{dbh}->prepare($sql);
    my $rec;
    if(!$sth->execute($id)
      || !($rec = $sth->fetchrow_hashref())) {
        con_err($console,gettext("This recording does not exist in the database!"));
        return undef;
    }

    my $start = 0;
    if($params && exists $params->{start}) {
      $start = &text2frame($params->{start});
    }
    if($start) {
      if($start < 0 or 
        ($rec->{framerate} <= 0) or
        ($start / $rec->{framerate}) >= ($rec->{duration})) {
        $start = 'begin';
      } else {
        $start = &frame2hms($start);
      }
    } else {
      $start = 'begin';
    }

    my $vdr = $rec->{vid};
    if($params && exists $params->{vdr}) {
      $vdr = $params->{vdr};
    }

    my $cmd = sprintf('PLAY %d %s', $rec->{id}, $start);

    # call playback command via svdrp
    my ($erg,$error) = $self->{svdrp}->command($cmd,$vdr);

    $console->msg($erg, $error)
        if(ref $console);
    return undef if($error);

    $console->redirect({url => sprintf('?cmd=rdisplay&data=%s',$rec->{hash}), wait => 1})
      if(ref $console and $console->typ eq 'HTML');

    my ($ret) = $erg->[1] =~ /^\d{3}\s*(.+)/s;
    return $ret;
}

# ------------------
sub cut {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id = shift || return con_err($console,gettext("No recording defined for playback! Please use rplay 'rid'."));
    my $params  = shift;

    my $sql = qq|SELECT SQL_CACHE vid, id, hash 
    FROM RECORDS as r, OLDEPG as e 
    WHERE e.eventid = r.eventid and r.hash = ?|;
    my $sth = $self->{dbh}->prepare($sql);
    my $rec;
    if(!$sth->execute($id)
      || !($rec = $sth->fetchrow_hashref())) {
        con_err($console,gettext("This recording does not exist in the database!"));
        return undef;
    }

    my $vdr = $rec->{vid};
    if($params && exists $params->{vdr}) {
      $vdr = $params->{vdr};
    }

    my $cmd = sprintf('EDIT %d', $rec->{id});
    if($self->{svdrp}->scommand($console, $config, $cmd, $vdr)) {

      $console->redirect({url => sprintf('?cmd=rdisplay&data=%s',$rec->{hash}), wait => 1})
          if(ref $console and $console->typ eq 'HTML');

      return 1;
    }
    return 0;
}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text    = shift || "";
    my $params  = shift;

    my $deep = 1;
    my $term;

    my $where = "";
    if($text) {
        $deep   += scalar (my @c = split('~',$text));

        $text =~ s/\'/\\\'/sg;
        $text =~ s/%/\\%/sg;
        $where .= qq|
AND (
      SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle), '~', $deep) LIKE ?
      OR
      SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle), '~', $deep) LIKE ?
)
|;
      push(@{$term},$text);
      push(@{$term},$text . '~%');
    }

    my %f = (
        'hash' => gettext('Index'),
        'Title' => gettext('Title'),
        'Subtitle' => gettext('Subtitle'),
        'Duration' => gettext('Duration'),
        'starttime' => gettext('Start time')
    );

    my $sql = qq|
SELECT SQL_CACHE 
    r.hash as \'$f{'hash'}\',
    r.eventid as __EventId,
    e.title as \'$f{'Title'}\',
    e.subtitle as \'$f{'Subtitle'}\',
    SUM(e.duration) as \'$f{'Duration'}\',
    UNIX_TIMESTAMP(e.starttime) as \'$f{'starttime'}\',
    SUM(FIND_IN_SET('new',status)) as __New,
    r.type as __Type,
    COUNT(*) as __Group,
    SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle), '~', $deep) as __fulltitle,
    IF(COUNT(*)>1,0,1) as __IsRecording,
    IF(CHAR_LENGTH(e.description)>77,RPAD(LEFT(e.description,77),80,'.'),e.description) as __description,
    preview as __preview,
    SUM(cutlength) as __cutlength
FROM
    RECORDS as r,
    OLDEPG as e
WHERE
    e.eventid = r.eventid
    $where 
GROUP BY
    SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle,hash), '~', $deep)
ORDER BY __IsRecording asc,
|;


    my $sortby = "track";
    $sortby = "starttime"
      if($text && $config->{seriesorder} eq 'date');

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
      my $hash;
      map {
        push(@$hash,$_->[0]);
        $_->[5] = datum($_->[5],'short');
      } @$erg;

      ($keywords,$keywordmax,$keywordmin) = $self->{keywords}->list('recording',$hash);

      unshift(@$erg, $fields);
    }

    my $param = {
        sortable => 1,
        usage => $self->{CapacityMessage},
        used => $self->{CapacityPercent},
        total => $self->{CapacityTotal},
        free => $self->{CapacityFree},
        previewcommand => $config->{previewlistthumbs},
        keywords => $keywords,
        keywordsmax => $keywordmax,        
        keywordsmin => $keywordmin,
        rows => $rows
    };
    return $console->table($erg, $param);
}

# ------------------
sub search {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text    = shift || return $self->list($console,$config);
    my $params  = shift;

    my $query = buildsearch("e.title,e.subtitle,e.description",$text);
    return $self->_search($console,$config,$query->{query},$query->{term},$params);
}

# ------------------
sub _search {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
    my $search = shift; 
    my $term = shift; 
    my $params  = shift;
    my $tables  = shift || '';



    my %f = (
        'hash' => gettext('Index'),
        'Title' => gettext('Title'),
        'Subtitle' => gettext('Subtitle'),
        'Duration' => gettext('Duration'),
        'starttime' => gettext('Start time')
    );

    my $sql = qq|
SELECT SQL_CACHE 
    r.hash as \'$f{'hash'}\',
    r.eventid as __EventId,
    e.title as \'$f{'Title'}\',
    e.subtitle as \'$f{'Subtitle'}\',
    e.duration as \'$f{'Duration'}\',
    UNIX_TIMESTAMP(e.starttime) as \'$f{'starttime'}\',
    FIND_IN_SET('new',r.status) as __New,
    r.type as __Type,
    0 as __Group,
    CONCAT_WS('~',e.title,e.subtitle) as __fulltitle,
    1 as __IsRecording,
    IF(CHAR_LENGTH(e.description)>77,RPAD(LEFT(e.description,77),80,'.'),e.description) as __description,
    preview as __preview,
    cutlength as __cutlength
FROM
    RECORDS as r,
    OLDEPG as e
    $tables
WHERE
    e.eventid = r.eventid
    AND ( $search )
ORDER BY 
|;

    my $sortby = "starttime";
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
      my $hash;
      map {
        push(@$hash,$_->[0]);
        $_->[5] = datum($_->[5],'short');
      } @$erg;

      ($keywords,$keywordmax,$keywordmin) = $self->{keywords}->list('recording',$hash);

      unshift(@$erg, $fields);
    }

    my $param = {
        sortable => 1,
        usage => $self->{CapacityMessage},
        used => $self->{CapacityPercent},
        total => $self->{CapacityTotal},
        free => $self->{CapacityFree},
        previewcommand => $config->{previewlistthumbs},
        keywords => $keywords,
        keywordsmax => $keywordmax,        
        keywordsmin => $keywordmin,
        rows => $rows
    };

    $console->setCall('rlist');
    return $console->table($erg, $param);
}

# ------------------
sub delete {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $record  = shift || return con_err($console,gettext("No recording defined for deletion! Please use rdelete 'id'."));
    my $answer  = shift || 0;

    my @rcs  = split(/[^0-9a-fl\:]/, $record);
    my $todelete;
    my $hashdelete;
    my %rec;
        
    foreach my $item (@rcs) {
        if($item =~ /^all\:(\w+)/i) {
            my $ids = $self->getGroupIds($1);
            for(@$ids) {
                $rec{$_} = 1;
            }
        } else {
                $rec{$item} = 1;
        }   
    }
    my @recordings = keys %rec;
    
    my $sql = sprintf(
qq|SELECT SQL_CACHE e.vid, r.id,CONCAT_WS('~',e.title,e.subtitle) as title,r.hash 
   FROM RECORDS as r,OLDEPG as e 
   WHERE e.eventid = r.eventid and r.hash IN (%s) 
   ORDER BY e.vid, r.id desc|, join(',' => ('?') x @recordings)); 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute(@recordings)
        or return con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));

    while (my $r = $sth->fetchrow_hashref()) {

        if(ref $console and $console->{TYP} eq 'CONSOLE') {
            $console->table({
              gettext('Title')                 => $r->{title}
            });
            my $confirm = $console->confirm({
                typ   => 'confirm',
                def   => 'y',
                msg   => gettext('Would you like to delete this recording?'),
            }, $answer);
            next if(! $answer eq 'y');
        }

        debug sprintf('Call delete recording with title "%s", id: %d%s',
            $r->{title},
            $r->{id},
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );


        $self->{svdrp}->queue_add(sprintf("delr %s",$r->{id}), $r->{vid});
        push(@{$todelete},$r->{title}); # Remember title
        push(@{$hashdelete},$r->{hash}); # Remember hash

        # Delete recordings from request, if found in database
        my $i = 0;
        for my $x (@recordings) {
          if ( $x eq $r->{hash} ) { # Remove known hash from user request
            splice @recordings, $i, 1;
          } else {
          $i++;
          }
        }
    }
    
    con_err($console,gettext("This recording does not exist in the database!"))
      if(scalar @recordings);

    if($self->{svdrp}->queue_count()) {

        my $msg = sprintf(gettext("Recording '%s' to delete"),join('\',\'',@{$todelete}));

        my ($erg,$error) = $self->{svdrp}->queue_flush(); # Aufrufen der Kommandos

        my $waiter;
        if($error) {
          $console->err([$msg, $error]) if($console);
        } else {

          if(ref $console && $console->typ eq 'HTML' && !$self->{inotify}) {
            $waiter = $console->wait($msg,0,1000,'no');
          }else {
            con_msg($console,$msg);
          }

          my $dsql = sprintf("DELETE FROM RECORDS WHERE hash IN (%s)", join(',' => ('?') x @{$hashdelete})); 
          my $dsth = $self->{dbh}->prepare($dsql);
            $sth->execute(@{$hashdelete})
              or return con_err($console, sprintf("Couldn't execute query: %s.",$sth->errstr));

          $self->{keywords}->remove('recording',$hashdelete);
        }

        $self->_readData($console,$waiter)
          unless($self->{inotify});

        if(ref $console && $console->typ eq 'HTML') {
          my @t = split('~', $todelete->[0]);
          if(scalar @t > 1) { # Remove subtitle
            delete $t[-1];
            $console->redirect({url => sprintf('?cmd=rlist&data=%s',url(join('~',@t))), wait => 1});
          } else {
            $console->redirect({url => '?cmd=rlist', wait => 1});
          }
        }
    } else {
        con_err($console,gettext("No recording to delete!"));
    }

    return 1;
}


sub is_empty_dir {
    my $dir    = shift;
    local (*DIR);
    return unless opendir DIR, $dir;
    while (defined($_ = readdir DIR)) {
        next if /^\.\.?$/;
        closedir DIR;
        return 0;
    }
    closedir DIR;
    return 1;
}

# ------------------
sub redit {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id  = shift || return con_err($console,gettext("No recording defined for editing!"));
    my $data    = shift || 0;

    my $rec;
    if($id) {
        my $sql = qq|
SELECT SQL_CACHE
    e.vid,
    CONCAT_WS('~',e.title,e.subtitle) as title,
    e.eventid,
    r.path,
    r.lifetime,
    r.filever
FROM
    RECORDS as r,
    OLDEPG as e
WHERE
    e.eventid = r.eventid
    AND ( r.hash = ? )
|;
        my $sth = $self->{dbh}->prepare($sql);
        if(!$sth->execute($id)
          || !($rec = $sth->fetchrow_hashref())) {
            con_err($console,gettext("This recording does not exist in the database!"));
            return undef;
        }
    }

    my $status = $self->readinfo($rec->{path},$rec->{filever});

    my $marksfile = $self->_marksfile($rec->{path},$rec->{filever});
    my $marks = (-r $marksfile ? load_file($marksfile) : '');

    $rec->{title} =~s#~+#~#g;
    $rec->{title} =~s#^~##g;
    $rec->{title} =~s#~$##g;

    my $modC = main::getModule('CHANNELS');

    my $questions = [
        'title' => {
            msg     => gettext('Title of recording'),
            def     => $rec->{title},
            req     => gettext("This is required!"),
        },
        'lifetime' => {
            typ     => 'integer',
            msg     => sprintf(gettext('Lifetime (%d ... %d)'),0,99),
            def     => int($rec->{lifetime}),
            check   => sub{
                my $value = shift || 0;
                if($value >= 0 and $value < 100) {
                    return int($value);
                } else {
                    return undef, gettext('Value incorrect!');
                }
            },
            req     => gettext("This is required!"),
        },
        'channel' => {
            typ     => 'list',
            def     => $status->{channel},
            choices => sub {
                my $erg = $modC->ChannelWithGroup('c.name,c.id');
                unshift(@$erg, [gettext("Undefined"),undef,undef]);                          
                return $erg;
            },
            msg   => gettext('Channel'),
            check   => sub{
                my $value = shift || return;

                if( my $chid = $modC->ToCID($value)) {
                    return $chid;
                } else {
                    return undef, sprintf(gettext("This channel '%s' does not exist!"),$value);
                }
            },
        },
        'description' => {
            typ   => 'textfield',
            msg   => gettext("Description"),
            def   => $status->{description} || '',
        },
        'aux' => {
            typ   => 'hidden',
            def   => $status->{aux},
        },
        'keywords' => {
            typ   => $self->{keywords}->{active} eq 'y' ? 'string' : 'hidden',
            msg   => gettext('Keywords'),
            def   => $status->{keywords},
        },
        'video' => {
            typ   => 'textfield',
            msg   => gettext('Video'),
            def   => $status->{video},
        },
        'audio' => {
            typ   => 'textfield',
            msg   => gettext('Audio'),
            def   => $status->{audio},
        },
        'marks' => {
            typ   => 'textfield',
            msg   => gettext("Cut marks"),
            def   => $marks || '',
        },
    ];

    $data = $console->question(gettext("Edit recording"), $questions, $data);

    if(ref $data eq 'HASH') {
        my $dropEPGEntry = 0;
        my $ChangeRecordingData = 0;

        my $videodirectory = $self->{svdrp}->videodirectory($rec->{vid});
          unless($videodirectory && -d $videodirectory) {
            my $hostname = $self->{svdrp}->hostname($rec->{vid});
            $console->err(sprintf(gettext("Missing video directory on %s!"),$hostname))
              if($console);
          return;
        }

        $data->{title} =~s#~+#~#g;
        $data->{title} =~s#^~##g;
        $data->{title} =~s#~$##g;

        # Keep PDC Time
        $data->{vpstime} = $status->{vpstime} if($status->{vpstime});

        if($data->{title} ne $rec->{title}
          or $data->{description} ne $status->{description} 
          or $data->{channel} ne $status->{channel} 
          or $data->{keywords} ne $status->{keywords}
          or $data->{video} ne $status->{video}
          or $data->{audio} ne $status->{audio}
          or ($rec->{filever} == 2 && $data->{lifetime} ne $status->{lifetime})  
            ) {

            my $info;
            foreach my $h (keys %{$data}) { $info->{$h} = $data->{$h}; }
            my @t = split('~', $info->{title});
            if(scalar @t > 1) { # Splitt genre~title | subtitle
                $info->{subtitle} = delete $t[-1];
                $info->{title} = join('~',@t);
            }

            $info->{aux} = $self->{keywords}->mergexml($info->{aux},'keywords',$info->{keywords});
            $info->{filever} = $rec->{filever};
            $self->saveinfo($rec->{path},$info)
               or return con_err($console,sprintf(gettext("Couldn't write file '%s' : %s"),
                         $self->_infofile($rec->{path},$rec->{filever}),$!));
            $ChangeRecordingData = 1 if($info->{aux} ne $status->{aux});
            $dropEPGEntry = 1;
        }

        if($data->{marks} ne $marks) {
            save_file($marksfile, $data->{marks})
               or return con_err($console,sprintf(gettext("Couldn't write file '%s' : %s"),$marksfile,$!));
            $ChangeRecordingData = 1;
        }


        if($rec->{filever} == 1 
            && $data->{lifetime} ne $rec->{lifetime}) {

            my @options = split('\.', $rec->{path});

            $options[-2] = sprintf("%02d",$data->{lifetime})
                if($data->{lifetime} ne $rec->{lifetime});

            my $newPath = join('.', @options);

            move($rec->{path}, $newPath)
                 or return con_err($console,sprintf(gettext("Recording: '%s', couldn't move to '%s' : %s"),$rec->{title},$newPath,$!));

            $rec->{path} = $newPath;
            $ChangeRecordingData = 1;
        }

        if($data->{title} ne $rec->{title}) {

            # Rename auf der Platte
            my $newPath = sprintf('%s/%s/%s', $videodirectory, $self->translate($data->{title}),basename($rec->{path}));

            my $parentnew = dirname($newPath);
            unless( -d $parentnew) {
                mkpath($parentnew)
                    or return con_err($console,sprintf(gettext("Recording: '%s', couldn't mkpath: '%s' : %s"),$rec->{title},$parentnew,$!));
            }

            move($rec->{path},$newPath)
                    or return con_err($console,sprintf(gettext("Recording: '%s', couldn't move to '%s' : %s"),$rec->{title},$data->{title},$!));

            my $parentold = dirname($rec->{path});
            if($videodirectory ne $parentold
                and -d $parentold
                and is_empty_dir($parentold)) {
                rmdir($parentold)
                    or return con_err($console,sprintf(gettext("Recording: '%s', couldn't remove '%s' : %s"),$rec->{title},$parentold,$!));
            }

            $ChangeRecordingData = 1;
            $dropEPGEntry = 1;
            $rec->{path} = $newPath;
        }


        if($dropEPGEntry) { # Delete EpgOld Entrys
            my $sth = $self->{dbh}->prepare('DELETE FROM OLDEPG WHERE eventid = ?');
            $sth->execute($rec->{eventid})
                or return con_err($console,sprintf("Couldn't execute query: %s.",$sth->errstr));
        }

        if($ChangeRecordingData) { 
            my $sth = $self->{dbh}->prepare('DELETE FROM RECORDS WHERE hash = ?');
            $sth->execute($id)
                or return con_err($console,sprintf("Couldn't execute query: %s.",$sth->errstr));
            my $todel;
            push(@$todel,$id);
            $self->{keywords}->remove('recording',$todel);
        }
        if($dropEPGEntry || $ChangeRecordingData) {
            $self->{lastupdate} = 0;
            my $updatefilename = $self->_watch_filename($rec->{vid});
            if($updatefilename) {
              touch($updatefilename) 
                or con_err($console,sprintf(gettext("Sorry! Couldn't touch '%s'! %s"), $updatefilename, $!));
            }
        }
        if($dropEPGEntry || $ChangeRecordingData) {
          my $waiter;

          if(ref $console && $console->typ eq 'HTML' && !($self->{inotify})) {
            $waiter = $console->wait(gettext('Recording edited!'),0,1000,'no');
          }else {
            con_msg($console,gettext('Recording edited!'));
          }
          sleep(1);
  
          $self->_readData($console,$waiter)
            unless($self->{inotify});

        } else {
          con_msg($console,gettext("Recording was'nt changed!"));
        }
 
        $console->redirect({url => sprintf('?cmd=rdisplay&data=%s',md5_hex($rec->{path})), wait => 1})
            if(ref $console and $console->typ eq 'HTML');
    }

    return 1;
}

# ------------------
# Load Reccmds's
sub _loadreccmds {
# ------------------
    my $self = shift || return error('No object defined!');

    unless($self->{reccmds}) {
        $self->{reccmds} = [];
        if(-r $self->{commandfile} and my $text = load_file($self->{commandfile})) {
            foreach my $zeile (split(/\n/, $text)) {
                if($zeile !~ /^\#/ and $zeile !~ /^$/ and $zeile !~ /true/) {
                    push(@{$self->{reccmds}}, $zeile);
                }
            }
        }
    }
}

# ------------------
sub reccmds {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id  = shift || return con_err($console,gettext("No recording defined for converting!"));
    my $data    = shift || 0;

    $self->_loadreccmds();
    unless(scalar @{$self->{reccmds}}) {
        con_err($console,gettext('No reccmds.conf on your system!'));
        return undef;
    }

    my $rec;
    if($id) {
        my $sql = qq|
SELECT SQL_CACHE
    r.hash,
    e.vid,
    CONCAT_WS('~',e.title,e.subtitle) as title,
    e.eventid,
    r.path
FROM
    RECORDS as r,
    OLDEPG as e
WHERE
    e.eventid = r.eventid
    AND ( r.hash = ? )
|;
        my $sth = $self->{dbh}->prepare($sql);
        if(!$sth->execute($id)
          || !($rec = $sth->fetchrow_hashref())) {
            con_err($console,gettext("This recording does not exist in the database!"));
            return undef;
        }
    }

    my $choices = [];
    my $n = 1;
    foreach my $v (@{$self->{reccmds}}) {
      my $cmd = (split(':', $v))[0];
      push(@$choices,[$cmd,$n]);
      $n ++;
    }

    my $questions = [
      'cmd' => {
        msg     => gettext('Command'),
        req     => gettext("This is required!"),
        typ     => 'list',
        choices => $choices,
        check   => sub{
            my $value = shift || return undef, gettext("This is required!");
            my @ret = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
            return $ret[0];
          }
      },
    ];

    $data = $console->question(gettext("Choose a command to edit this recording ..."), $questions, $data);
    if(ref $data eq 'HASH') {

      my $cmdid = $data->{cmd};
      my $cmd = (split(':', $self->{reccmds}->[$cmdid-1]))[-1] 
                || return con_err($console,gettext("Couldn't find this command ID!"));
      my $path = $rec->{path};
      unless(-e $path) {
          con_err($console,sprintf(gettext("Couldn't find recording: '%s'"),$path));
          return undef;
      }

      my $command = sprintf("%s %s",$cmd,qquote($path));
      debug sprintf('Call command %s%s',
          $command,
          ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
          );

      my $output;
      if(open P, $command .' |') { # execute command and read result from stdout
        @$output = <P>;
        close P;
        if( $? >> 8 > 0) {
            unshift(@$output,sprintf(gettext("Call %s '%s', standard error output :"), $cmd, $path));
            $console->message($output);
        } else {
            unshift(@$output,sprintf(gettext("Call %s '%s', standard output :"), $cmd, $path));
            $console->message($output);
        }
      } else {
            con_err($console,sprintf(gettext("Sorry! Couldn't call %s '%s'! %s"), $cmd, $path, $!));
      }

      $console->link({
          text => gettext("Back to recording list"),
          url => "?cmd=rdisplay&data=" . $rec->{hash},
      }) if($console->typ eq 'HTML');
      return 1;
    }
}

# ------------------
sub IdToData {
# ------------------
    my $self = shift || return error('No object defined!');
    my $id = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE * from RECORDS as r, OLDEPG as e where e.eventid = r.eventid and hash = ?');
    $sth->execute($id)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg;
}
  
# ------------------
sub IdToPath {
# ------------------
    my $self = shift || return error('No object defined!');
    my $id = shift || return undef;

    my $sth = $self->{dbh}->prepare('SELECT SQL_CACHE path from RECORDS where hash = ?');
    $sth->execute($id)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchrow_hashref();
    return $erg ? $erg->{path} : undef;
}

# ------------------
sub getGroupIds {
# ------------------
    my $self = shift || return error('No object defined!');
    my $hash = shift || return error ('No recording defined!');
    
    my $data = $self->IdToData($hash);
    unless($data) {
      error sprintf("Couldn't find recording '%s'!", $hash);
      return;
    }
    my  $text    = $data->{title};

    my $deep   = ( scalar (my @c = split('~',$text)) ) + 1;

    $text =~ s/\'/\\\'/sg;
    $text =~ s/%/\\%/sg;

    my $sql = qq|
SELECT SQL_CACHE 
    r.hash
FROM
    RECORDS as r,
    OLDEPG as e
WHERE
    e.eventid = r.eventid
AND (
      SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle), '~', $deep) LIKE ?
      OR
      SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle), '~', $deep) LIKE ?
    )
GROUP BY
    SUBSTRING_INDEX(CONCAT_WS('~',e.title,e.subtitle,hash), '~', $deep)
|;

    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($text,$text .'~%')
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $erg = $sth->fetchall_arrayref();

    my $ret = [];
    for(@{$erg}) {
        push(@$ret, $_->[0]);
    }
    return $ret;
}


# ------------------
# title to path
sub translate {
# ------------------
    my $self = shift || return error('No object defined!');
    my $title = shift || return error ('No title in translate!');
    my $vfat = shift || $self->{vfat};

    if($vfat eq 'y')
    {
        $title =~ s/([^\xDC\xC4\xD6\xFC\xE4\xF6\xDFa-z0-9\&\!\-\s\.\@\~\,\(\)\%\+])/sprintf('#%X', ord($1))/seig;
        $title =~  s/[^\xDC\xC4\xD6\xFC\xE4\xF6\xDFa-z0-9\!\&\-\#\.\@\~\,\(\)\%\+]/_/sig;
        # Windows couldn't handle '.' at the end of directory names
        $title =~ s/(\.$)/\#2E/sig;
        $title =~ s/(\.~)/\#2E~/sig;
    } else {
        $title =~ tr# \'\/#_\x01\x02#;
    }

    $title =~ tr#\/~#~\/#;
    return $title;
}

# ------------------
# path to title
sub converttitle {
# ------------------
    my $self = shift || return error('No object defined!');
    my $title = shift || return error ('No title in translate!');
    my $vfat = shift || $self->{vfat};

    $title =~ s/_/ /g;
    $title =~ tr#\/~\x01\x02#~\/\'\/#;

    if($vfat eq 'y') {
        $title =~ s/\#([a-fA-F0-9][a-fA-F0-9])/pack("C", hex($1))/eg;
        $title =~ s/\x03/:/g; # See backward compat.. at recordings.c
    }

    return $title;
}

# ------------------
# Length of recording in seconds,
# return value as integer 
sub _recordinglength {
# ------------------
    my $self = shift || return error('No object defined!');
    my $path = shift || return error ('Missing path from recording!' );
    my $filever = shift;
    my $framerate = shift;

    my $f;
    my $c;
    if($filever == 2) {
      $f = "index";
      $c = "00001.ts";
    } else {
      $f = "index.vdr";
      $c = "001.vdr";
    }
    my $index = sprintf("%s/%s", $path, $f);
    my $video = sprintf("%s/%s", $path, $c);

    my $fst = stat($index);
    my $rst = stat($video);
    # Pseudo Recording (DIR)
    return 0 unless($fst and $rst);

    if($fst->mode & 00400) { # mode & S_IRUSR
        unless(int($framerate)>0) {
            error sprintf("Unknown framerate : '%s'", $index);
            return 0;
        }
        return int(($fst->size / 8) / $framerate);
    } else {
        error sprintf("Couldn't read : '%s'", $index);
    }
    return 0;
}

# ------------------
# Size of recording in MB,
# return value as integer 
sub _recordingsize {
# ------------------
    my $self = shift || return error('No object defined!');
    my $path = shift || return error('Missing path from recording!');
    my $filever = shift;
    my $size = shift || 0; # Filesize offset e.g. from index.vdr

    my @files;
    if($filever == 2) {
      @files = glob(sprintf("%s/[0-9]*.ts",$path));
    } else {
      @files = glob(sprintf("%s/[0-9]*.vdr",$path));
    }
    return $self->_recordingCapacity(\@files,$size);
}

# ------------------
# Size of recording in MB,
# return value as integer 
sub _recordingCapacity {
# ------------------
    my $self = shift || return error('No object defined!');
    my $files = shift || return error('Missing files from recording!');
    my $size = shift || 0; # Filesize offset e.g. from index.vdr

    # Calc used disc space (MB)
    my $sizeMB;
    my $mb = (1024 * 1024);
    my $FileSize = 0; 

    # Incl. length of each xxx.vdr
    foreach my $f (@{$files}) {
      if($size > $mb) {
        $sizeMB = int($size / $mb);
        $size -= $sizeMB * $mb;
        $FileSize += $sizeMB;
      }
      my $stat = stat($f);
      $size += $stat->size if($stat);
    }
    if($size > 0) {
      $sizeMB = int($size / $mb);
      $FileSize += $sizeMB;
    }

    return $FileSize;
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
        e.title as title
    FROM
        RECORDS as r,
        OLDEPG as e
    WHERE
        e.eventid = r.eventid
        AND ( e.title LIKE ? )
    GROUP BY
        title
UNION
    SELECT SQL_CACHE 
        e.subtitle as title
    FROM
        RECORDS as r,
        OLDEPG as e
    WHERE
        e.eventid = r.eventid
        AND ( e.subtitle LIKE ? )
    GROUP BY
        title
ORDER BY
    title
LIMIT 25
        |;
        my $sth = $self->{dbh}->prepare($sql);
        $sth->execute('%'.$search.'%','%'.$search.'%')
            or return error "Couldn't execute query: $sth->errstr.";
        my $result = $sth->fetchall_arrayref();
        $console->table($result)
            if(ref $console && $result);
    }
}

# ------------------
sub recover {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id  = shift || 0;
    my $data    = shift || 0;

    my $files;
    my $vids;

    my $hostlist = $self->{svdrp}->list_unique_recording_hosts();
    foreach my $vid (@$hostlist) {
        my $videodirectory = $self->{svdrp}->videodirectory($vid);
        unless($videodirectory && -d $videodirectory) {
          my $hostname = $self->{svdrp}->hostname($vid);
          $console->err(sprintf(gettext("Missing video directory on %s!"),$hostname))
            if($console);
          next;
        }
      my $f = $self->scandirectory($videodirectory, 'del');
      if($f) {
        map { $files->{$_} = $f->{$_}; } keys %{$f};
        $vids->{$vid} = $videodirectory;
      }
    }

    return con_msg($console,gettext("There none recoverable recordings!"))
      unless($files and keys %{$files});

    my $choices = [];
    foreach my $v (keys %{$files}) {
      push(@$choices,[$files->{$v}->{title},$v]);
    }

    my $questions = [
      'restore' => {
        msg     => gettext('Title of recording'),
        req     => gettext("This is required!"),
        typ     => 'list',
        options => 'multi',
        def   => sub {
            my $ret;
            foreach my $v (keys %{$files}) {
              push(@{$ret},$v);
            }
            return $ret;
          },
        choices => $choices,
        check   => sub{
            my $value = shift || return undef, gettext("This is required!");
            my @ret = (ref $value eq 'ARRAY') ? @$value : split(/\s*,\s*/, $value);
            return join(',', @ret);
          }
      },
    ];

    $data = $console->question(gettext("Recover recording"), $questions, $data);
    if(ref $data eq 'HASH') {
        my $ChangeRecordingData = 0;

        foreach my $hash (split(/\s*,\s*/, $data->{restore})) {
          unless(exists $files->{$hash}) {
            con_err($console,gettext("Can't recover recording, maybe was this in the meantime deleted!"));
            next;
          }

          my $path = $files->{$hash}->{path};
          my $newPath = $path;
          $newPath =~ s/\.del$/\.rec/g;
          debug sprintf("Recover recording, rename '%s' to %s",$path,$newPath);
          if(!move($path,$newPath)) {
            con_err($console,sprintf(gettext("Recover recording, couldn't rename '%s' to %s : %s"),$path,$newPath,$!));
            next;
          }
          $ChangeRecordingData = 1;
        }

        if($ChangeRecordingData) {
          my $waiter;

          $self->{lastupdate} = 0;
          foreach my $v (keys %{$vids}) {
            my $updatefilename = $self->_watch_filename($v);
            if($updatefilename) {
              touch($updatefilename) 
                or con_err($console,sprintf(gettext("Sorry! Couldn't touch '%s'! %s"), $updatefilename, $!));
            }
          }

          if(ref $console && $console->typ eq 'HTML' && !($self->{inotify})) {
            $waiter = $console->wait(gettext('Recording recovered!'),0,1000,'no');
          }else {
            con_msg($console,gettext('Recording recovered!'));
          }
          sleep(1);
  
          $self->_readData($console,$waiter)
            unless($self->{inotify});

        } else {
          con_msg($console,gettext("None recording was'nt recovered!"));
        }
 
        $console->redirect({url => '?cmd=rlist', wait => 1})
            if(ref $console and $console->typ eq 'HTML');
    }

    return 1;
}

################################################################################
# find file and offset from frame
sub frametofile {
    my $self = shift || return error('No object defined!');
    my $path = shift || return error ('Missing path from recording!' );
    my $frame = int (shift);
    my $filever = shift;

    my $f;
    if($filever == 2) {
      $f = "index";
    } else {
      $f = "index.vdr";
    }
    my $file = sprintf("%s/%s", $path, $f);
    unless(open FH,$file) {
      error(sprintf("Can't open file '%s': %s",$file,$!));
      return (undef,undef);
    }
    binmode FH;

    my $offset = INDEXTRUCTSIZE * $frame;
    if($offset != sysseek(FH,$offset,0)) { #SEEK_SET
      error(sprintf("Can't seek file '%s': %s",$file,$!));
      close FH;
      return (undef,undef);
    }

    do {
      my $buffer;
      my $bytesread = sysread (FH, $buffer, INDEXTRUCTSIZE);
      if($bytesread != INDEXTRUCTSIZE) {
        error(sprintf("Can't read file '%s': %s",$file,$!));
        return (undef,undef);
      }
      if($filever == 2) {
        my ($q, $n) = unpack ("Q S", $buffer); # 40, 7, 1, 16
        if(($q & 1) == 1) { # I-Frame
          my $c = $q >> 8; 
          close FH;
          return ($n,$c); # Filenumber, Offset from file begin
        }
      } else {
        my ($c, $t, $n, $r) = unpack ("I C C S", $buffer);
        if($t == 1) { # I-Frame
          close FH;
          return ($n,$c); # Filenumber, Offset from file begin
        }  
      }
      $offset -= INDEXTRUCTSIZE;
      if($offset != sysseek(FH,-(INDEXTRUCTSIZE*2), 1)) { #SEEK_CUR
        error(sprintf("Can't seek file '%s': %s",$file,$!));
        close FH;
        return (undef,undef);
      }
      $frame -= 1;
    } while($frame >= 0 && $offset >= 0);

    close FH;
    return (undef,undef);
}


# ------------------
sub image {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift;

    return $console->err(gettext("Sorry, get image is'nt supported"))
      if ($console->{TYP} ne 'HTML');

    return $console->status404('NULL','Wrong image parameter') 
      unless($data);

    my ($id, $frame)
            = $data =~ /^([0-9a-f]{32}).(.*)$/si;

    return $console->status404('NULL','Wrong image parameter') 
      unless($id && $frame);
    if(length($frame) < 8) {
      $frame = sprintf("%08d",$frame);
    }
    return $console->datei(sprintf('%s/%s_shot/%s.jpg', $self->{previewimages}, $id, $frame));
}

#schlue
# ------------------
sub keeppreview {
# ------------------
	my ( $previewdir, $recordingdir ) = @_;
	#error sprintf("preview command '%s'",$recordingdir );

	$recordingdir =~ s!^.* -r '!!;
	$recordingdir =~ s!' -f .*!!;

	my $shot	= '00000000.jpg';
	my $file	= $recordingdir . '/preview_vdr.png';

	#error sprintf("preview file '%s'",$file );

	if ( -f $file )
	{
		#error sprintf("preview file '%s' exists",$file );

		my $scale	= ();

		my $preview = Image::Magick->new;
		$preview->read( $file );

		#get preview dimension
		my $width = $preview->Get('width');
		my $height= $preview->Get('height');

		#check for longest side
		if ( $height >= $width )
		{
			# recalc dimensons based on height
			$scale = $height / 96;
			$height= 96;
			$width = sprintf( "%s", int( $width / $scale ));
		}
		else
		{
			# recalc dimensons based on width
			$scale = $width / 128;
			$width= 128;
			$height = sprintf( "%s", int( $height / $scale ));
		}

		$preview->Set( Gravity => 'Center' );
		$preview->Resize( geometry => $width .'x'. $height, background => 'black' );
		$preview->Extent( geometry => $width .'x'. $height, background => 'black' );

		$preview->Write( $previewdir . '/' . $shot );
		#error sprintf("XXV preview file '%s'", $previewdir . '/' . $shot );
	}
}

1;

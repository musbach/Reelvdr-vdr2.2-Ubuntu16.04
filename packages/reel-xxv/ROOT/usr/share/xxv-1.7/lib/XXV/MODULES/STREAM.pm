package XXV::MODULES::STREAM;
use strict;

use Tools;
use File::stat;
use File::Glob ':glob';

$SIG{CHLD} = 'IGNORE';

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'STREAM',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module generate streams from recordings.'),
        Preferences => {
            host => {
                description => gettext('Used host of referred link inside playlist.'),
                default     => 'localhost',
                type        => 'host',
                required    => gettext('This is required!'),
            },
            method => {
                description => gettext('Typ of stream recordings'),
                default     => 'http',
                type        => 'list',
                choices     => [
                    [ gettext('HTTP Streaming'),      'http' ],
                    [ gettext('Remote SMB/NFS share'),'smb' ]
                ],
                required    => gettext('This is required!'),
            },
            mimetyp => {
                description => gettext('Used mime type of delivered playlist video streams'),
                default     => 'video/x-mpegurl',
                type        => 'string',
            },
            netvideo => {
                description => gettext('Base directory of remote SMB/NFS share.'),
                default     => '\\\\vdr\\video',
                type        => 'string',
            },
            widget => {
                description => gettext('Used stream widget'),
                type        => 'list',
                default     => 'vlc',
                choices     => [
                    [gettext("Other external player"), 'external'],
                    [gettext('Embed media player'),    'media'],
                    [gettext('Embed vlc player'),      'vlc'],
                ],
                required    => gettext("This is required!"),
            },
            LiveAccessMethod => {
                description => gettext('Method of connect live-tv stream from recorder.'),
                default     => 'playlist',
                type        => 'list',
                required    => gettext('This is required!'),
                choices     => [
                    [ gettext('Send playlist'),'playlist'],
                    [ gettext('Redirect HTTP request'),'redirect'],
                    [ gettext('Relay stream as proxy'), 'proxy']
                ],
            },
            streamtype => {
                description => gettext('Used live stream type'),
                type        => 'list',
                default     => 'PES',
                choices     => [
                    [gettext("TS - Transport Stream"),  'TS'],
                    [gettext('PS - Program Stream'),    'PS'],
                    [gettext('PES - Packetized Elementary Stream'),      'PES'],
                    [gettext('ES - Elementary Stream'),  'ES'],
                    [gettext('External stream type'),    'Extern'],
                ],
                required    => gettext("This is required!"),
            },
            width => {
                description => gettext('Stream widget width'),
                default     => 720,
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
            height => {
                description => gettext('Stream widget height'),
                default     => 576,
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
            playrecord => {
                description => gettext("Stream a recordings."),
                short       => 'pre',
                callback    => sub{ $self->playrecord(@_) },
                DenyClass   => 'stream',
                binary      => 'nocache'
            },
            livestream => {
                description => gettext("Stream a channel 'cid'. This required the streamdev plugin!"),
                short       => 'lst',
                callback    => sub{ $self->livestream(@_) },
                DenyClass   => 'stream',
                binary      => 'nocache'
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

    # The Initprocess
    my $erg = $self->init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift || return error('No object defined!');

    main::after(sub{
        $self->{svdrp} = main::getModule('SVDRP');
        unless($self->{svdrp}) {
           return 0;
        }
    }, "STREAM: Prepare streaming ...");

    1;
}


# ------------------
sub livestream {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $cid = shift || return con_err($console,gettext("No channel defined for streaming!"));
    my $params  = shift;

    return $console->err(gettext("Can't stream files!"))
      unless($console->can('datei'));

    my $vdr = $self->{svdrp}->primary_hosts();
    if($params && $params->{vdr}) {
      $vdr = $params->{vdr};
    }

    my $cmod = main::getModule('CHANNELS');
    my $hash = $cmod->ToHash($cid, $vdr);
    return con_err($console, sprintf(gettext("Channel '%s' does not exist in the database!"),$cid))
      unless($hash);
    my $channel = $cmod->GetChannel($hash, $vdr);

    if($self->{widget} ne 'external' && (!$params || !(exists $params->{player}))) {
      my $data = sprintf("?cmd=livestream&__player=1&data=%s",$channel->{hash});

      my $param = {
          title => $channel->{name},
          widget => $self->{widget},
          width  => $self->{width},
          height => $self->{height},
      };
      return $console->player($data, $param);
    }

    debug sprintf('Live stream with channel "%s"%s',
        $channel->{name},
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    $console->{nopack} = 1;

    # query hostname from video disk recorder
    my $livehost = main::getModule('SVDRP')->hostname($channel->{vid});
    if($self->{LiveAccessMethod} ne 'proxy' and 
       ($livehost eq 'localhost' or $livehost eq '127.0.0.1')) {
       $livehost = $self->{host};
    }

    my $liveport = 3000;

    my $request = sprintf("/%s/%s", $self->{streamtype}, $channel->{id});
    my $url = sprintf("http://%s:%d%s",$livehost,$liveport,$request);

    if($self->{LiveAccessMethod} eq 'redirect') {
      debug(sprintf("Redirect to %s",$url));
      $console->statusmsg(301,$url); 
      return;
    } elsif($self->{LiveAccessMethod} eq 'playlist') {
      debug(sprintf("Send playlist with %s",$url));
      my $data;
      $data = "#EXTM3U\r\n";
      $data .= "#EXTINF:86400," . $channel->{name} . "\r\n";
      $data .= $url . "\r\n";

      my $arg;
      $arg->{'attachment'} = sprintf("livestream-%s.m3u", $channel->{id});
      $arg->{'Content-Length'} = length($data);

      return $console->out($data, $self->{mimetyp}, %{$arg} );
    } elsif($self->{LiveAccessMethod} eq 'proxy') {
      $console->proxy($livehost,$liveport,$request,$self->{mimetyp}); 
      return;
    } else {
      $console->err(gettext('Unknown access method!')); 
    }
}

# ------------------
sub playrecord {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $recid   = shift || return $console->err(gettext("No recording defined for streaming!"));
    my $params  = shift;

    return $console->err(gettext("Can't stream files!"))
      unless($console->can('stream'));

    my $rmod = main::getModule('RECORDS');
    my $rec = $rmod->IdToData($recid)
        or return $console->err(sprintf(gettext("Couldn't find recording: '%s'"), $recid));

    my $start = 0;
    my $offset = 0;
    if($params && exists $params->{start}) {
      $start = &text2frame($params->{start});
    }

    if($self->{widget} ne 'external' && (!$params || !(exists $params->{player}))) {
      my $data = sprintf("?cmd=playrecord&__player=1&data=%s",$recid);
      $data .= sprintf("&__start=%d", $start) if($start);

      my $param = {
          title => $rec->{title},
          widget => $self->{widget},
          width  => $self->{width},
          height => $self->{height},
      };
      $param->{title} .= '~' . $rec->{subtitle} if($rec->{subtitle});

      return $console->player($data, $param);
    }

    return $console->err(sprintf(gettext("Couldn't find recording: '%s'"), $recid))
      unless $rec->{path};

    my @files;
    if($rec->{filever} == 2) {
      @files = glob(sprintf("%s/[0-9]*.ts",$rec->{path}));
    } else {
      @files = glob(sprintf("%s/[0-9]*.vdr",$rec->{path}));
    }

    return $console->err(sprintf(gettext("Couldn't find recording: '%s'"), $recid))
      unless scalar(@files);

    if($start) {
      my ($filenumber,$fileoffset) = $rmod->frametofile($rec->{path},$start,$rec->{filever});
      splice(@files, 0, $filenumber-1) if($filenumber && ($filenumber - 1) > 0);
      $offset = $fileoffset if($fileoffset && ($fileoffset - 1) > 0);
    }

    debug sprintf('Play recording "%s"%s',
        $rec->{path},
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    if($self->{method} eq 'http') {
      return $console->stream(\@files, $self->{mimetyp}, $offset);
    } else {

      my $videodirectory = $self->{svdrp}->videodirectory($rec->{vid});
        unless($videodirectory && -d $videodirectory) {
          my $hostname = $self->{svdrp}->hostname($rec->{vid});
          $console->err(sprintf(gettext("Missing video directory on %s!"),$hostname))
            if($console);
        return;
      }

      my $data;
      $data  = "#EXTM3U\r\n";

      foreach my $file (@files) {
        my $fstat = stat($file);

        $file =~ s/^$videodirectory//si;
        $file =~ s/^[\/|\\]//si;
        my $URL = sprintf("%s/%s\r\n", $self->{netvideo}, $file);
        $URL =~s/\//\\/g
        if($URL =~ /^\\\\/sig              # Samba \\host/xxx/yyy => \\host\xxx\yyy
        || $URL =~ /^[a-z]\:[\/|\\]/sig);  # Samba x:/xxx/yyy => x:\xxx\yyy


        if($fstat && $rec->{size}) {
          # estimate duration of file in seconds ( filesize * totaltime / totalsize )
          my $duration = CORE::int($fstat->size * $rec->{duration} / ($rec->{size} * 1024 * 1024));
          # add duration and title as extended infomations
          $data .= "#EXTINF:". $duration ."," . $rec->{title};
          $data .= "~" . $rec->{subtitle} if($rec->{subtitle});
          $data .= "\r\n";
        }
        $data .= $URL;
      }

      $console->{nopack} = 1;

      my $arg;
      $arg->{'attachment'} = sprintf("%s.m3u", $recid);
      $arg->{'Content-Length'} = length($data);

      return $console->out($data, $self->{mimetyp}, %{$arg} );
    }
}

1;

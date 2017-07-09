package XXV::MODULES::STATUS;
use strict;

use Tools;
use Socket;
use Sys::Hostname;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'STATUS',
        Prereq => {
            'Font::TTF::Font' => 'String table for a TTF font'
        },
        Description => gettext('This module analyzes your system and displays the result.'),
        Level => 'user',
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            whoBinary => {
                description => sprintf(gettext("Path of command '%s'"),'who'),
                default     => "/usr/bin/who",
                type        => "file",
                required    => gettext('This is required!'),
            },
            dfBinary => {
                description => sprintf(gettext("Path of command '%s'"),'df'),
                default     => "/bin/df",
                required    => gettext('This is required!'),
                type        => "file",
            },
            interval => {
                description => gettext('Interval in seconds to save data'),
                default     => 60,
                type        => "integer",
            },
            history => {
                description => gettext('Save historical data, in hours'),
                default     => 3,
                type        => "integer",
            },
            font => {
                description => gettext('TrueType font to draw overlay text'),
                default     => 'Vera.ttf',
                type        => 'list',
                choices     => Tools::findttf($self->{paths}->{FONTPATH})
            },
            graphic => {
                description => gettext('Show collected data as diagram?'),
                default     => 'y',
                type        => 'confirm',
            },
            warnlevel => {
                description => gettext('Warning level, if volume filled more then this level'),
                default     => 90,
                type        => "integer",
            },
        },
        Commands => {
            all => {
                description => gettext('Display all relevant informations about this system'),
                short       => 'sa',
                callback    => sub{
                    my $console = shift || return error('No console defined!');
                    my $config = shift || return error('No config defined!');

                    $console->setCall('vitals');
                    $self->vitals($console,$config);

                    $console->setCall('filesys');
                    $self->filesys($console,$config);

                    $console->setCall('memory');
                    $self->memory($console,$config);

                    $console->setCall('network');
                    $self->network($console,$config);

                    $console->setCall('hardware');
                    $self->hardware($console,$config);
                },
            },
            vitals => {
                description => gettext('Display the vitals informations'),
                short       => 'sv',
                callback    => sub{ $self->vitals(@_) },
            },
            network => {
                description => gettext('Displays network information'),
                short       => 'sn',
                callback    => sub{ $self->network(@_) },
            },
            hardware => {
                description => gettext('Displays hardware information'),
                short       => 'sh',
                callback    => sub{ $self->hardware(@_) },
            },
            memory => {
                description => gettext('Displays memory information'),
                short       => 'sm',
                callback    => sub{ $self->memory(@_) },
            },
            filesys => {
                description => gettext('Display the file system informations'),
                short       => 'sf',
                callback    => sub{ $self->filesys(@_) },
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

    # Interval to read timers and put to DB
    Event->timer(
        interval => $self->{interval},
        prio => 6,  # -1 very hard ... 6 very low
        cb => sub{
            $self->remember() if($self->{active} eq 'y');
        },
    );

    $self->{LastWarning} = 0;

	return $self;
}

# ------------------
sub remember {
# ------------------
    my $self = shift  || return error('No object defined!');

    my $longsteps = int(($self->{history} * 60 * 60) / $self->{interval});

    $self->watchDog($self->mounts(undef,'rawdata'));

    my $data = {
        timestamp  => time,
        load        => $self->load('clear'),
        util        => $self->util('clear'),
        users       => $self->users('clear'),
        usage       => $self->mounts('clear'),
        memory      => $self->_memory('clear'),
        network     => $self->_network('clear'),

    };
    push(@{$self->{rememberstack}}, $data);

    if(scalar @{$self->{rememberstack}} >= $longsteps) {
        shift @{$self->{rememberstack}};
    }
}


# ------------------
sub vitals {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my $output = {
        name    => $self->name(),
        IP      => $self->IP(),
        kernel  => $self->kernel(),
        uptime  => $self->uptime(),
        users   => $self->users(),
        load    => $self->load(),
        util    => $self->util(),
    };

    my $param = {
        headingText => gettext('Vitals'),
        stack => $self->{rememberstack},
        history => $self->{history} * 60 * 60,
        interval => $self->{interval},
    };
    $param->{font} = sprintf("%s/%s",$self->{paths}->{FONTPATH},$self->{font})
      if($console->typ eq 'HTML');
    return $console->table($output,$param);
}

# ------------------
sub network {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my $ret = [];
    push(@$ret,
      [
        gettext("Interface"),
        gettext("RxBytes"),
        gettext("RxPackets"),
        gettext("TxBytes"),
        gettext("TxPackets"),
        gettext("Time")
      ])
    if($console->typ ne 'AJAX');

    my $raw = ($console->typ eq 'AJAX' or $console->typ eq 'HTML') ? 1 : 0;
    if($raw) {
      foreach(@{$self->{rememberstack}}) {
        my $t = $_->{timestamp};
        foreach(@{$_->{network}}) {
        my @v = [ @{$_} ];
        $v[0]->[5] = $t;
        push(@$ret, @v);
        }
      }
    }

    my $t = time;
    my $n = $self->_network($raw);
    foreach(@{$n}) {
    my @v = [ @{$_} ];
      $v[0]->[5] = $t;
      push(@$ret, @v);
    }

    my $param = {
        headingText => gettext('Network'),
    };
    $param->{font} = sprintf("%s/%s",$self->{paths}->{FONTPATH},$self->{font})
      if($console->typ eq 'HTML');
    return $console->table($ret,$param);
}

# ------------------
sub hardware {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my ($number, $model, $speed, $cache, $bogomips) = $self->CPU();
    my $pci = $self->pci();
    my $ide = $self->ide();
    my $scsi = $self->scsi();

    my $output = {
        Processors  => $number,
        Model       => $model,
        ChipSpeed   => $speed,
        CacheSize   => $cache,
        SystemBogomips  => $bogomips,
    };
    $console->table($output, {headingText => gettext('CPU'), hide_HeadRow => 1});
    $console->table($pci, {headingText => gettext('PCI'), drawRowLine => 1, hide_HeadRow => 1})
      if($pci);
    $console->table($ide, {headingText => gettext('IDE')})
      if($ide && scalar @{$ide} > 1);
    $console->table($scsi, {headingText => gettext('SCSI')})
      if($scsi && scalar @{$scsi} > 1);
}

# ------------------
sub memory {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my $ret = [];
    push(@$ret,
      [
        gettext("Total memory"),
        gettext("Free memory"),
        gettext("Active used memory"),
        gettext("Inactive memory"),
        gettext("Cached pages"),
        gettext("Swap cache"),
        gettext("Time")
      ])
    if($console->typ ne 'AJAX');

    my $raw = ($console->typ eq 'AJAX' or $console->typ eq 'HTML') ? 1 : 0;
    if($raw) {
      foreach(@{$self->{rememberstack}}) {
        my @v = $_->{memory};
        $v[0]->[6] = $_->{timestamp};
        push(@$ret, @v);
      }
    }
    my @n = $self->_memory(undef,$raw);
    $n[0]->[6] = time;
    push(@$ret,@n);

    my $param = {
        headingText => gettext('Memory'),
    };
    $param->{font} = sprintf("%s/%s",$self->{paths}->{FONTPATH},$self->{font})
      if($console->typ eq 'HTML');

    return $console->table($ret,$param);
}

# ------------------
sub filesys {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');

    my $ret = $self->mounts(undef,$self->{graphic} eq 'y' && $console->typ eq 'HTML');
    my $param = {
        headingText => gettext('Filesystems'),
        usage => $ret,
        graphic => ($self->{graphic} eq 'y' ? 1 : 0),
    };
    $param->{font} = sprintf("%s/%s",$self->{paths}->{FONTPATH},$self->{font})
      if($console->typ eq 'HTML');

    return $console->table($ret,$param);
}


#############################################################################
#                           Helper Functions
#############################################################################

# Get the system's name
sub name {
    my $self = shift || return error('No object defined!');

    my $result = hostname();
    return $result;

}

# Get the system's IP address

sub IP {
    my $self = shift || return error('No object defined!');

    my $result = inet_ntoa(scalar(gethostbyname($self->name())) || scalar(gethostbyname('localhost')));
    return $result;

}

# Get the system's kernel version

sub kernel {
    my $self = shift || return error('No object defined!');

    my $result = load_file("/proc/sys/kernel/osrelease");
    $result =~ s/\n//sig;
    return $result;

}

# Get the system's uptime

sub uptime {
    my $self = shift || return error('No object defined!');

    my $buffer = load_file('/proc/uptime');

    my @list = split / /, $buffer;
    my $ticks = sprintf("%.0u", $list[0]);
    my $mins  = $ticks / 60;
    $mins  = sprintf("%.0u", $mins);
    my $hours = $mins / 60;
    $hours = sprintf("%.0u", $hours);
    my $days  = ($hours / 24);
    $days  = sprintf("%.0u", $days);
    $hours = $hours - ($days * 24);
    $hours = sprintf("%.0u", $hours);
    $mins  = $mins - ($days * 60 * 24) - ($hours * 60);

    my $result = '';
    if ( $days == 1 ) {
        $result .= "${days} ".gettext("day");
    }
    elsif ( $days == 0 ) {
        $result .= '';
    }
    else {
        $result .= "${days} ".gettext("days");
    }

    if ( $days > 0 && ( $hours > 0 || $mins > 0 )) {
        $result .= ", ";
    }

    if ( $hours == 1 ) {
        $result .= "${hours} ".gettext("hour");
    }
    elsif ( $hours == 0) {
        $result .= '';
    }
    else {
        $result .= "${hours} ".gettext("hours");
    }

    if ( $hours > 0 && $mins > 0 ) {
        $result .= ", ";
    }

    if ( $mins == 1 ) {
        $result .= "${mins} ".gettext("minute");
    }
    elsif ($mins == 0 ) {
        $result .= '';
    }
    else {
        $result .= "${mins} ".gettext("minutes");
    }

    return $result;

}

# Get information on network devices in the system
sub _network {
    my $self = shift || return error('No object defined!');
    my $clr = shift || 0;
    my $buffer = load_file('/proc/net/dev');

    my $interfaces = [];

    foreach my $line (split(/\n/, $buffer)) {
        my @data = split(/[:|\s]+/, $line);
        next unless($data[2] =~ /^\d+$/);
        unless($clr) {
            $data[2] = convert($data[2]);
            $data[10] = convert($data[10]);
        }
        push(@$interfaces, [@data[1..3], @data[10..11]]);
    }

    return $interfaces;
}

# Get the current memory info
sub _memory {
    my $self = shift || return error('No object defined!');
    my $clr = shift || 0;
    my $rawdata = shift || 0;
    my @ret;

    my $mem = {};
    my $buffer = load_file "/proc/meminfo";
    foreach my $zeile (split('\n', $buffer)) {
        next unless($zeile =~ /kB/);
        my ($name, $value) = split(':\s+', $zeile);
        $value =~ s/ kB//sig;

        $value = convert($value * 1024)
            unless($clr || $rawdata);

        $mem->{$name} = $value;
    }
    push(@ret,$mem->{MemTotal},$mem->{MemFree},$mem->{Active},$mem->{Inactive},$mem->{Cached},$mem->{SwapCached});
    return \@ret;
}

# Get current cpu info

sub CPU {
    my $self = shift || return error('No object defined!');

    my $buffer = load_file('/proc/cpuinfo');

    my @rows = split /\n/, $buffer;
    my $number = scalar grep /processor\s+:/, @rows;
    my @modelList = grep /model name\s+:/, @rows;
    my @speedList = grep /cpu MHz\s+:/, @rows;
    my @cacheList = grep /cache size\s+:/, @rows;
    my @bogomipsList = grep /bogomips\s+:/, @rows;

    my ($crap, $model) = split /:/, $modelList[0], 2;
    $model =~ s/\s+//;

    ($crap, my $speed) = split /:/, $speedList[0], 2;
    $speed = sprintf("%.0u", $speed);
    $speed .= " MHz";

    ($crap, my $bogomips) = split /:/, $bogomipsList[0], 2;
    $bogomips = sprintf("%.0u", $bogomips);

    my $cache = '';

    ($crap, $cache) = split /:/, $cacheList[0], 2;
    if ($cache eq '') {
        $cache = gettext("No on-chip cache.");
    }

    return ($number, $model, $speed, $cache, $bogomips);

}

# Get CPU usage info and return a percentage

sub util {
    my $self = shift || return error('No object defined!');

    open(STAT, "/proc/stat") or return error "Couldn't open /proc/stat\n";
    my $buffer = <STAT>;
    close(STAT);

    my ($name, $user, $nice, $system, $idle) = split /\s+/, $buffer;
    my $usage = $user + $nice + $system;
    my $total = $user + $nice + $system + $idle;

    #Wait 1 second for cpu time to accumulate for comparison
    #More than 1 second delays the script too much, and sleep won't
    #take an argument < 1
    sleep(1);

    open (STAT, "/proc/stat") or return error "Couldn't open /proc/stat\n";
    $buffer = <STAT>;
    close(STAT);

    my ($newName, $newUser, $newNice, $newSystem, $newIdle) = split /\s+/, $buffer;
    my $newUsage = $newUser + $newNice + $newSystem;
    my $newTotal = $newUser + $newNice + $newSystem + $newIdle;

    my $deltaUsage = $newUsage - $usage;
    my $deltaTotal = $newTotal - $total;

    my $percent = 0;

    $percent = ($deltaUsage / $deltaTotal) * 100
      if($deltaTotal != 0);

    $percent = sprintf("%.1f", $percent);

    return($percent);

}

# Get the number of current users logged in

sub users {
    my $self = shift || return error('No object defined!');

    my $result = `$self->{whoBinary}`
        or return error "Couldn't execute $self->{whoBinary}\n";
    my $lines = ($result =~ tr/\n//);
    return $lines;

}

# Get the list of PCI devices

sub pci {
    my $self = shift || return error('No object defined!');

    return 0
      if(! -r "/proc/pci");

    my $buffer = load_file("/proc/pci");
    my $ret;
    foreach my $zeile (split(/\n/, $buffer)) {
        if($zeile =~ /(bridge|controller|interface)\:\s+(.+)/i) {
            $ret->{ucfirst($1)} .= "$2\n";
        }
    }
    return $ret;
}

# Get the list of IDE devices

sub ide {
    my $self = shift || return error('No object defined!');

    my @ideModelList;
    my @ideCapacityList;
    my $count = 0;

    my @dirList = glob ("/proc/ide/*");
    my $ret = [
      [
        gettext("Device"),
        gettext("Model"),
        gettext("Capacity"),
        gettext("Cache")
      ]
    ];
    foreach my $device (@dirList) {
        next unless($device =~ /ide\/hd/);

        my $model = load_file("${device}/model");
        $model =~ s/\n//g;

        my $cap = 0;
           $cap = load_file("${device}/capacity")
            if(-e "${device}/capacity");
        my $cache = 0;
           $cache = load_file("${device}/cache")
            if(-e "${device}/cache");
        push(@$ret,
            [
                $device,
                $model,
                convert($cap * 512),
                convert($cache * 1024),
            ]
        );
    }

    return $ret;
}

# Get the list of SCSI devices

sub scsi {
    my $self = shift || return error('No object defined!');

    my $ret = [[qw/Device Vendor Model Type/]];
    my $file = "/proc/scsi/scsi";

    if ( -r $file){
        my ( $host, $channel, $id, $lun, $vendor, $model, $type )   ;
        my $dev_no = 'a';
        my $cd_no = '0';
        my $st_no = '0';
        open(F,$file) 
            or return error "Couldn't open $file : $!\n";;
        while(<F>) {
            if(/Host: (\S+) Channel: (\d+) Id: (\d+) Lun: (\d+)/) {
                $host = $1, $channel = $2, $id = $3, $lun = $4;
            }
            if(/Vendor: (.+)\s+Model: (.+)\s+Rev:/) {
                $vendor = $1, $model = $2;
                $vendor =~ s/^\s+//g; 
                $vendor =~ s/\s+$//g; 
                $model =~ s/^\s+//g;
                $model =~ s/\s+$//g;

                $_ = <F>; 
                if(/Type:(.+)\s+ANSI/) {
                    $type = $1;
                    $type =~ s/^\s+//g;
                    $type =~ s/\s+$//g; 
                }

                my $device;
                if($type eq 'Direct-Access') { # Disk
                    $device = "/dev/sd$dev_no";
                    $dev_no++;
                } elsif($type eq 'CD-ROM') {
                    $device = "/dev/scd$cd_no";
                    $cd_no++;
                } elsif($type eq 'Sequential-Access') { # Streamer
                    $device = "/dev/st$st_no";
                    $st_no++;
                } 

                push(@$ret,
                    [
                        "$device (ch: $channel, lun: $lun, scsi: $id)",
                        $vendor,
                        $model,
                        $type,
                    ]
                ) if($device);
             }
        }
        close(F);
    }
    return $ret;
}

# Get the current load averages

sub load {
    my $self = shift || return error('No object defined!');
    my $clr = shift || 0;

    my $buffer = load_file("/proc/loadavg");
    my @list = split(' ', $buffer);

    return \@list if($clr);

    my $c = 5;
    my $ret;

    foreach my $entry (@list[0..2]) {
        $ret .= sprintf("%s last %d min\n", $entry, $c);
        $c += 5;
    }

    return $ret;

}

# Get the status of currently mounted filesystems
sub mounts{
    my $self = shift || return error('No object defined!');
    my $clr = shift || 0;
    my $rawdata = shift || 0;

    my $df = `$self->{dfBinary} -TP -x cdfs -x iso9660 -x udf`
        or return error "Couldn't execute $self->{dfBinary} $!\n";
    my $ret = [
      [
        gettext("Filesystem"),
        gettext("Typ"),
        gettext("Space"),
        gettext("Used"),
        gettext("Free"),
        gettext("Capacity"),
        gettext("Mount")
      ]
    ];

    foreach my $zeile (split('\n', $df)) {
        my @data = split('\s+', $zeile);
        next if($data[2] !~ /^\d+$/);

        $data[0] =~ s/[\-\s]/_/sg;
        $data[5] =~ s/\%//sg if($rawdata);
        if($clr) {
            push(@$ret, $data[5]);
        } else {
            map {$_ = convert($_ * 1024)} @data[2..4];
            push(@$ret, \@data);
        }
    }
    return $ret;
}

# ------------------
sub videoMounts {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $videodir = shift || return error('No video path defined!');
    my $mounts = $self->mounts;

    my $ret = [];

    for (@$mounts) {
        push(@$ret, $_)
            if($_->[0] =~ /^$videodir/i);
    }

    $ret = $mounts unless(scalar @$ret);

    return $ret;
}

# ------------------
sub watchDog {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $mou = shift  || return error('No data defined!');

    # Not all 15 seconds a panic message ;)
    return if($self->{LastWarning}+900 > time);

    foreach my $m (@$mou) {
        next unless($m->[0] =~ /^\//);
        if($self->{warnlevel} && $m->[5] >= $self->{warnlevel} ) {
            my $rm = main::getModule('EVENTS');
            $rm->news(
                sprintf(gettext("PANIC! Only %s%% space left on device %s"),(100 - $m->[5]),$m->[0]),
                sprintf(gettext("Device has space %s from %s used!"), $m->[3], $m->[2]),
                'sa',
                undef,
                'important'
            );
            $self->{LastWarning} = time;
        }
    }
}


1;

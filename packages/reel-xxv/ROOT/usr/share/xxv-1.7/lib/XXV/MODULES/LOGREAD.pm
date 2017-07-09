package XXV::MODULES::LOGREAD;

use strict;

use Tools;
use XXV::OUTPUT::HTML::PUSH;

$|++;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'LOGREAD',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module reads the xxv log file and displays it on the console.'),
        Level => 'admin',
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            tail => {
                description => sprintf(gettext("Path of command '%s'"),'tail'),
                default     => '/usr/bin/tail',
                type        => 'file',
                required    => gettext('This is required!'),
            },
            rows => {
                description => gettext('Lines to display'),
                default     => '100',
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            syslog => {
                description => sprintf(gettext("Path of file '%s'"),'syslog'),
                default     => '/var/log/syslog',
                type        => 'file',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            logger => {
                description => gettext("Display the last log entries"),
                short       => 'lg',
                callback    => sub{ $obj->logger(@_) },
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

	return $self;
}

# ------------------
sub logger {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $logname = shift || 'standard';
    my $params  = shift || {};

    $obj->{logfiles} = {
        main    => {
            # Path to logfile
            logfile => $obj->{paths}->{LOGFILE},
                       #24 (14870) [22:29:08 09/22/05] CHANNELS: Read and register Channels ...
            # Regular expression for every loglines
            regex   => qr/^(\d+)\s+\((\d+)\)\s+\[(\d+\-\d+\-\d+ \d+\:\d+\:\d+)\]\s+(.+?)$/s,
            # Fields List for describe the rows
            fields => [qw/Nr Typ Time Message/],
            # Callback for coloring rows
            display=> sub{
                my $typ = $_[0][1];
                return 'black'  if($typ < 200);
                return 'green'  if($typ < 300);
                return 'blue'   if($typ < 400);
                return 'brown'  if($typ < 500);
                return 'red'    if($typ >= 500);
            },
            # Maximum letters for truncate in template
            maxlet=> 50,
        },
        syslog    => {
            logfile => $obj->{syslog},
                       #Sep 23 00:35:01 vdr /USR/SBIN/CRON[16971]: (root) CMD (/usr/bin/weatherng.sh)
            regex   => qr/^(.+?)\s+(\d+)\s+(\d+\:\d+\:\d+)\s+(.+?)\s+(.+)/s,
            fields => [qw/Month MDay Time Prg Message/],
            display=> sub{
                my $txt = $_[0][-1];
                return 'red' if($txt =~ /ERROR/si);
                return 'blue' if($txt =~ /WARNING/si);
                return 'green' if($txt =~ /INFO/si);
                return 'black';
            },
            maxlet=> 80,
        },
    };

    if( ! ref $obj->{logfiles}->{$logname}) {
        return $console->err(sprintf("The log with the name %s does not exist! Please use '%s'!", $logname, join("' or '", keys %{$obj->{logfiles}})));
    }

    my $logfile = $obj->{logfiles}->{$logname}->{logfile};
    my @out = $obj->tail($logfile);

    return $console->msg(undef, sprintf(gettext("Could not read log file %s!"), $logfile))
        unless(scalar @out);

    my $output = $obj->parseLogOutput($obj->{logfiles}->{$logname}, \@out);

    my ($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,
                          $atime,$mtime,$ctime,$blksize,$blocks)
                              = stat($logfile);

    $console->table($output, {
        type    => $logname,
        logfile => $logfile,
        Size    => convert($size),
        LastChanged => datum($mtime),
        full    => $params->{full},
        color   => $obj->{logfiles}->{$logname}->{display},
        maxlet  => $obj->{logfiles}->{$logname}->{maxlet},
    });
    return 1;
}

# ------------------
sub tail {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $logfile = shift  || return error('No file defined!');
    my $rows = shift  || $obj->{rows};

    my $cmd = sprintf('%s --lines=%d %s', $obj->{tail}, $rows, $logfile);
    my @out = (`$cmd`);
    return @out;
}


# ------------------
sub parseLogOutput {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $log = shift  || return error('No data defined!');
    my $out = shift  || return;

    my $regex = $log->{regex};
    $obj->{logbuf} = undef;

    my $ret = [];
    foreach my $line (@$out) {
        if(my @d = $line =~ $regex) {
            $obj->parseData($ret, \@d) if($d[0]);
        } else {
            $obj->parseData($ret, $line);
        }
    }
    my @r = reverse @$ret;

    unshift(@r, $log->{fields});
    return \@r;
}

# ------------------
sub parseData {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $ret     = shift || return error('No data defined!');
    my $data    = shift || 0;


    if(ref $data eq 'ARRAY') {     # Set Data
        $data->[-1] .= $obj->{logbuf}
            if($obj->{logbuf});
        push(@$ret, $data);
        $obj->{logbuf} = undef;
    } elsif($data) {               # Message (last row, last item) .+ $line
        $obj->{logbuf} .= $data;
    }
    return $ret;
}

1;

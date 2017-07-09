package XXV::MODULES::REPORT;

use strict;

use Tools;


# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'REPORT',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module read and show status information from every module.'),
        Level => 'user',
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            interval => {
                description => gettext('Time in hours to send the report.'),
                default     => 6,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            report => {
                description => gettext("Display the report screen 'modname'"),
                short       => 'rp',
                callback    => sub{ $self->report(@_) },
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

    # the dbh handle
    $self->{dbh} = delete $attr{'-dbh'};

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

    $self->{LastReportTime} = time;

    # Interval to send report
    Event->timer(
        interval => $self->{interval}*3600,
        prio => 6,  # -1 very hard ... 6 very low
        cb => sub{
            $self->report();
            $self->{LastReportTime} = time;
        },
    );

    # The Initprocess
    my $erg = $self->init or return error('Problem to initialize module!');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift  || return error('No object defined!');

    return 1;
}


# ------------------
sub report {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $modulename = shift || '';

    my $mods = main::getModules();
    my $cfg = main::getModule('CONFIG')->{config};

    # Look for status entry in modCfg and call his
    my $result = {};
    foreach my $modName (sort keys %{$mods}) {
        my $modCfg = $mods->{$modName}->{MOD};
        next if($modulename and uc($modulename) ne $modCfg->{Name});
        next if(exists $mods->{$modName}->{active} and $cfg->{$modCfg->{Name}}->{active} eq 'n');
        if(exists $modCfg->{Status} and ref $modCfg->{Status} eq 'CODE') {
            lg sprintf("Collect report data from modul %s",$modCfg->{Name});
            $result->{$modCfg->{Name}} = $modCfg->{Status}($self->{LastReportTime});
        }
    }

    $console->table($result, {hide_HeadLine => 1, hide_HeadRow => 1, maxwidth => 80})
        if(ref $console);

    return 1;
}

1;

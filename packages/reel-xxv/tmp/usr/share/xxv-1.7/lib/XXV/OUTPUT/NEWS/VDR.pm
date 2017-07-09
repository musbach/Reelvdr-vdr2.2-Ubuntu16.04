package XXV::OUTPUT::NEWS::VDR;
use strict;

use Tools;
use POSIX qw(locale_h);

# News Modules have only this methods
# init - for intervall or others
# send - send the informations
# push - push the news and parse it
# req  - read the actual news print this out

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'NEWS::VDR',
        Description => gettext('This NEWS module generates messages for the VDR interface.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'n',
                type        => 'confirm',
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = shift;
                    my $erg = $self->init
                        or return undef, gettext("Can't initialize news module!")
                            if($value eq 'y' and not exists $self->{INITE});
                    if($value eq 'y') {
                      my $emod = main::getModule('EVENTS');
                      if(!$emod or $emod->{active} ne 'y') {
                        return undef, sprintf(gettext("Module can't activated! This module depends module %s."),'EVENTS');
                      }
                    }
                    return $value;
                },
            },
            level => {
                description => gettext('Category of messages that should displayed'),
                default     => 1,
                type        => 'list',
                choices     => sub {
                                    my $emod = main::getModule('EVENTS');
                                    return undef unless($emod);
                                    my $erg = $emod->get_level_as_array();
                                    map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                    return @$erg;
                                 },
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = int(shift) || 0;
                    my $emod = main::getModule('EVENTS');
                    return undef unless($emod);
                    my $erg = $emod->get_level_as_array();
                    unless($value >= $erg->[0]->[0] and $value <= $erg->[-1]->[0]) {
                        return undef, 
                               sprintf(gettext('Sorry, but value must be between %d and %d'),
                                  $erg->[0]->[0],$erg->[-1]->[0]);
                    }
                    return $value;
                },
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

    # paths
    $self->{paths} = delete $attr{'-paths'};

    # host
    $self->{host} = delete $attr{'-host'};

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

    $self->{TYP} = 'text/plain';

    # Initiat after load modules ...
    main::after(sub{
        # The Initprocess
        my $erg = $self->init
            or return error("Can't initialize news module!");
    }, "NEWS::VDR: Start initiate news module ...")
        if($self->{active} eq 'y');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift || return error('No object defined!');

    $self->{INITE} = 1;
    $self->{SVDRP} = main::getModule('SVDRP');

    1;
}

# ------------------
sub send {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vars = shift || return error('No data defined!');

    return lg('This function is deactivated!')
        if($self->{active} ne 'y');

    return lg('Title is not set!')
        unless($vars->{Title});

    return undef unless($vars->{level} >= $self->{level} );

    my $cmd = sprintf('MESG %s', $vars->{Title});

    my $svdrp = $self->{SVDRP} || return error ('No SVDRP!' );
    return $svdrp->command($cmd);
}

# ------------------
sub push {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vars = shift || return error('No data defined!');

    return $self->send($vars);
}

# ------------------
sub req {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $test = shift  || 0;

    return gettext('The module NEWS::VDR is not active!')
        if($self->{active} ne 'y');

    my $vars = {
        AddDate => time,
        Title   => 'This is only a test from xxv news vdr modul!',
        Text    => 'This is only a test from xxv news vdr modul!',
        Cmd     => 'request',
        Id      => 'vdr',
        Level   =>  100,
    };

    if( $self->send($vars) ) {
      return gettext("Message was been sent to your VDR!");
    } else {
      return gettext("Message chould'nt been sent to your VDR!");
    }
}


1;

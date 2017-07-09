package XXV::MODULES::ROBOT;
use strict;

use Tools;

$SIG{CHLD} = 'IGNORE';

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'ROBOT',
        Prereq => {
#            'WWW::Mechanize' => 'Handy web browsing in a Perl object ',
        },
        Description => gettext('This module register and run robots to fetch data from internet.'),
        Status => sub{ $obj->status(@_) },
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
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

    # read the DB Handle
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

	return $self;
}

# ------------------
sub saveRobot {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $rname = shift || return error('No robot name defined!');
    my $rsub = shift || return error('No robot subroutine defined!');

    return error("$rname is not a code reference!'")
        unless(ref $rsub eq 'CODE');

    $obj->clean( $rname );
    $obj->{robots}->{$rname} = $rsub;
    return $obj->{robots}->{$rname};
}

# ------------------
sub register {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $rname = shift || return error('No robot name defined!');
    my @args = @_;

    return error("$rname is not a Robot!'")
        unless(ref $obj->{robots}->{$rname} eq 'CODE');

    push(@{$obj->{jobs}->{$rname}}, [@args]);
}

# ------------------
sub start {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $rname = shift || return error('No robot name defined!');
    my $endcb = shift;

    lg sprintf('Start Robots ....');

    unless(exists $obj->{jobs}->{$rname}) {
        return error("No Robot with name $rname is registered!");
    }

    # fork and forget
    defined(my $child = fork()) or die "Couldn't fork: $!";
    if($child == 0) {
        $obj->{dbh}->{InactiveDestroy} = 1;
        my $modM = main::getModule('MUSIC');
        if($modM->{mdbh}) {
          $modM->{mdbh}->{InactiveDestroy} = 1;
        }
        # create a new browser
        my $count = 0;
        foreach my $args (@{$obj->{jobs}->{$rname}}) {
            my ($result, $error);
            lg sprintf('robot callback %s started (%d)....', $rname, $count);
            eval {
                ($result, $error) = &{$obj->{robots}->{$rname}}(@$args);
            };
            $error = $@ if($@);
            if($result) {
                lg sprintf("robot callback %s successfully ended!", $rname);
            } else {
                error sprintf("robot callback %s failed! : %s ", $rname, $error);
            }
            $count++;
        }
        &$endcb()
            if(ref $endcb eq 'CODE');
        exit(0);
    }
}

# ------------------
sub clean {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $rname = shift || return error('No robot name defined!');
    delete $obj->{jobs}->{$rname};
}


# ------------------
sub result {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $rname = shift || return error('No robot name defined!');

    return $obj->{result}->{$rname};

}

# ------------------
sub status {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $lastReportTime = shift || 0;

    return
      if($obj->{active} eq 'n');

    return {
          message => $obj->{result}
    };
}



1;

package XXV::OUTPUT::Dump;

use strict;

use vars qw($AUTOLOAD);
use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'Dump',
        Prereq => {
        },
        Description => gettext('This receives and sends dump messages.')
    };
    return $args;
}
# ------------------
sub AUTOLOAD {
# ------------------
    my $obj = shift || return error('No object defined!');

    return if($AUTOLOAD =~ /DESTROY$/);
dumper(\@_);
    return @_;
}

# ------------------
sub new {
# ------------------
	my($class, %attr) = @_;
	my $self = {};
	bless($self, $class);

	# who am I
    $self->{MOD} = $self->module;

    # Try to use the Requirments
    map {
        eval "use $_";
        if($@) {
          my $m = (split(/ /, $_))[0];
          return panic("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
        }
    } keys %{$self->{MOD}->{Prereq}};

    $self->{TYP} = 'INTERFACE';

	return $self;
}

# ------------------
sub typ {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->{TYP};
}

1;

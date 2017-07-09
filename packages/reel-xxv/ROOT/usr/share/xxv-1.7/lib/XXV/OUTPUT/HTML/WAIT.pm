package XXV::OUTPUT::HTML::WAIT;

use strict;

use Tools;
use XXV::OUTPUT::HTML::PUSH;

=head1 NAME

XXV::OUTPUT::HTML::WAIT - A Processbar for XXV system

=head1 SYNOPSIS

    use XXV::OUTPUT::HTML::WAIT;

    my $waiter =  XXV::OUTPUT::HTML::WAIT->new(
        -cgi => $obj->{cgi},        # The CGI Object from Lincoln Stein
        -handle => $obj->{handle},  # The handle to printout the http Stuff
        -callback => sub{           # Callback for html output.
                                    # In this case parse the html template wait.tmpl
            my ($min, $max, $cur, $steps) = @_;
            my $out = $obj->parseTemplate(
                'wait',
                {
                    msg     => $msg,
                    minimum => $min,
                    current => $cur,
                    maximum => $max,
                    steps   => $steps
                },
            );
            return $out;
        },
    );

    $waiter->min(0);        # Min Value for process Bar
    $waiter->max(10);       # Max Value for process Bar
    $waiter->screen('yes'); # Every call of next will redraw the process bar

    while($c > 10) {
        $waiter->next($c++);  # Next Event with current value
    }
    $waiter->end;

=cut

# ------------------
sub new {
# ------------------
	my($class, %attr) = @_;
	my $self = {};
	bless($self, $class);

    $self->{handle} = $attr{'-handle'}
        || return error('No handle defined!');

    $self->{cgi} = $attr{'-cgi'}
        || return error('No CGI Object defined!');

    $self->{callback} = $attr{'-callback'}
        || return error('No Callback to print out!');

    $self->{steps} = $attr{'-steps'} || 10;

    $self->{charset} = $attr{'-charset'}
        || 'ISO-8859-1';

    $self->{pusher} =  XXV::OUTPUT::HTML::PUSH->new(
        -cgi => $self->{cgi},        # The CGI Object from Lincoln Stein
        -handle => $self->{handle},  # The handle to printout the http Stuff
        -charset => $self->{charset}
    );

    $self->init();

	return $self;
}

# ------------------
sub init {
# ------------------
    my $obj = shift  || return error('No object defined!');

    $obj->{STEP} = 0;
    $obj->{pusher}->start();
    undef $obj->{FirstRefresh};
}

# ------------------
sub next {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $cur = shift  || $obj->{MAX};
    my $end = shift  || 0;
    my $msg = shift  || 0;


    # Don't show really every step, even is screen defined,
    # avoid high traffic and long duration of waiter progress
    my $t = time;
    return
        if(defined $obj->{SCREEN} && $obj->{SCREEN} eq 'no'
            && $end == 0 
            && $obj->{LastRefreshTime} && $obj->{LastRefreshTime} > ($t - 1));

    # remember time from from first call
    $obj->{FirstRefresh} = $t 
      if(not $obj->{FirstRefresh});

    # calc end time of execution
    my $rest = $end ? 0 : $obj->{MAX} - $cur;
    my $deltaT = $t - $obj->{FirstRefresh};
    my $etaT = ($cur > 0) ? ($deltaT / $cur * $rest) : 0;
    # Format end time of execution from seconds to human readable format
    my $eta = sprintf("%02d:%02d:%02d",$etaT / 3600 % 24 ,($etaT / 60) % 60, $etaT % 60 );

    $obj->{LastRefreshTime} = $t;


    # 2.2 = 22 / 10
    my $step = $obj->{MAX} / $obj->{steps};
    $obj->{STEP} += $step;

    if ($end or $cur > $obj->{MAX}) {
        $obj->{pusher}->stop();
        my $out = $obj->{endcallback}($obj->{MIN}, $obj->{MAX}, $cur, $obj->{steps}, $msg, $eta)
            if(ref $obj->{endcallback} eq 'CODE');
    } else {
        my $out = $obj->{callback}($obj->{MIN}, $obj->{MAX}, $cur, $obj->{steps}, $msg, $eta);
        $obj->{pusher}->print($out);
    }
}

# ------------------
sub end {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $msg = shift  || 0;

    return $obj->next(undef, $obj->{MAX}, 1, $msg);
}


# ------------------
sub endcallback {
# ------------------
    my $obj = shift  || return error('No object defined!');
    $obj->{endcallback} = shift || return $obj->{endcallback};
}

# ------------------
sub max {
# ------------------
    my $obj = shift  || return error('No object defined!');
    $obj->{MAX} = shift || return $obj->{MAX};
}

# ------------------
sub min {
# ------------------
    my $obj = shift  || return error('No object defined!');
    $obj->{MIN} = shift || return $obj->{MIN};
}

# ------------------
sub screen {
# ------------------
    my $obj = shift  || return error('No object defined!');
    $obj->{SCREEN} = shift || return $obj->{SCREEN};
}


1;

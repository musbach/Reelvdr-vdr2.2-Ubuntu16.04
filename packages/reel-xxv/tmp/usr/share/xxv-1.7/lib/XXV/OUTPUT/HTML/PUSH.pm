package XXV::OUTPUT::HTML::PUSH;

use strict;

use Tools;

$| = 1;

=head1 NAME

XXV::OUTPUT::HTML::PUSH - A Push for http system

=head1 SYNOPSIS

    use XXV::OUTPUT::HTML::PUSH;

    my $pusher =  XXV::OUTPUT::HTML::PUSH->new(
        -cgi => $self->{cgi},        # The CGI Object from Lincoln Stein
        -handle => $self->{handle},  # The handle to printout the http Stuff
    );

    $pusher->start();       # Start the Push Process

    while($c > 10) {
        $pusher->print($c++);  # Print out the message
    }

    $pusher->stop();        # Stop the Push


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

    $self->{charset} = $attr{'-charset'}
        || 'ISO-8859-1';

  return $self;
}

# ------------------
sub start {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $out = shift ||  0;
    $self->{handle}->print($self->{cgi}->multipart_init(-boundary=>'----here we go!'));
    $self->print($out) if($out);
}

# ------------------
sub print {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $msg = shift  || return;
    my $type = shift || 'text/html';

    $self->{handle}->print($self->{cgi}->multipart_start(-type=>$type));
    $self->{handle}->print($msg."\n");
    $self->{handle}->print($self->{cgi}->multipart_end);
}

# ------------------
sub follow_print {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $msg = shift  || return;
    my $type = shift || 'text/html';

    unless($self->{header}) {
        $self->{handle}->print($self->{cgi}->multipart_start(-type=>$type));
        $self->{header} = 1;
    }
    $self->{handle}->print($msg."\n");
}

# ------------------
sub stop {
# ------------------
    my $self = shift  || return error('No object defined!');
    $self->{handle}->print($self->{cgi}->multipart_end);
    $self->{handle}->print($self->{cgi}->header(
        -type   =>  'text/html',
        -status  => "200 OK",
        -charset => $self->{charset},
    ));
}

1;

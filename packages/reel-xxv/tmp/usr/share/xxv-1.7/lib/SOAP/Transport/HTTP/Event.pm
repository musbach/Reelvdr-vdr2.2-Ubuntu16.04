package SOAP::Transport::HTTP::Event;

use Carp ();
use vars qw($AUTOLOAD @ISA);
@ISA = qw(SOAP::Transport::HTTP::Server);

sub DESTROY { SOAP::Trace::objects('()') }

#sub new { require HTTP::Daemon;
sub new {
  my $obj = shift;
  unless (ref $obj) {
    my $class = ref($obj) || $obj;

    my(@params, @methods);
    while (@_) { $class->can($_[0]) ? push(@methods, shift() => shift) : push(@params, shift) }
    $obj = $class->SUPER::new;

    # Added in 0.65 - Thanks to Nils Sowen
    # use SSL if there is any parameter with SSL_* in the name
    $obj->SSL(1) if !$obj->SSL && grep /^SSL_/, @params;
    my $http_daemon = $obj->http_daemon_class;
    eval "require $http_daemon" or Carp::croak $@ unless
      UNIVERSAL::can($http_daemon => 'new');
    $obj->{_daemon} = $http_daemon->new(@params) or Carp::croak "Can't create daemon: $!";
    # End SSL patch
    # $obj->{_daemon} = HTTP::Daemon->new(@params) or Carp::croak "Can't create daemon: $!";
    $obj->myuri(URI->new($obj->url)->canonical->as_string);
    while (@methods) { my($method, $params) = splice(@methods,0,2);
      $obj->$method(ref $params eq 'ARRAY' ? @$params : $params)
    }
    SOAP::Trace::objects('()');
  }
  return $obj;
}

sub SSL {
  my $obj = shift->new;
  @_ ? ($obj->{_SSL} = shift, return $obj) : return
  $obj->{_SSL};
}

sub http_daemon_class { shift->SSL ? 'HTTP::Daemon::SSL' : 'HTTP::Daemon' }

sub AUTOLOAD {
  my $method = substr($AUTOLOAD, rindex($AUTOLOAD, '::') + 2);
  return if $method eq 'DESTROY';

  no strict 'refs';
  *$AUTOLOAD = sub { shift->{_daemon}->$method(@_) };
  goto &$AUTOLOAD;
}

sub getDaemon {
    my $obj = shift;
    my $daemon = $obj->new;
    return $daemon->{_daemon};
}

sub handle {
    my $obj = shift;
    my $sock = shift;
    my $httpd = shift;

    my $c = $sock->accept;
    my $r = $c->get_request;
    $obj->request($r);
    $obj->SUPER::handle;
    $c->send_response($obj->response);
    # replaced ->close, thanks to Sean Meisner <Sean.Meisner@VerizonWireless.com>
    # shutdown() doesn't work on AIX. close() is used in this case. Thanks to Jos Clijmans <jos.clijmans@recyfin.be>
    UNIVERSAL::isa($c, 'shutdown') ? $c->shutdown(2) : $c->close();
    $c->close;
}

1;

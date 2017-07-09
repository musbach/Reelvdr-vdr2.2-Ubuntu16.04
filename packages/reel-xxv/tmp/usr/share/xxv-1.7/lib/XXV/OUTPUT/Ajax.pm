package XXV::OUTPUT::Ajax;

use strict;
use Encode;
use vars qw($AUTOLOAD);
use Tools;

$SIG{CHLD} = 'IGNORE';

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'Ajax',
        Prereq => {
            'XML::Simple' => 'Easy API to maintain XML (esp config files)',
            'JSON' => 'Parse and convert to JSON (JavaScript Object Notation)',
        },
        Description => gettext('This receive and send Ajax messages.')
    };
    return $args;
}

# ------------------
sub AUTOLOAD {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || {};
    my $params = shift || 0;

    my $name = (split('::', $AUTOLOAD))[-1];
    return  if($name eq 'DESTROY');

    $self->out( $data, $params, $name );

    #$self->{call} = '';
}

# ------------------
sub new {
# ------------------
    my($class, %attr) = @_;
    my $self = {};
    bless($self, $class);

    $self->{charset} = delete $attr{'-charset'} || 'ISO-8859-1';
    if($self->{charset} eq 'UTF-8'){
      eval 'use utf8';
    }

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

    $self->{handle} = $attr{'-handle'}
        || return error('No handle defined!');

    $self->{cgi} = $attr{'-cgi'}
        || return error('No cgi given!');

    $self->{browser} = $attr{'-browser'}
        || return error('No browser given!');

    $self->{outtype} = $attr{'-output'}
        || return error('No output type given!');

    $self->{debug} = $attr{'-debug'}
        || 0;

    $self->{types} = {
      'xml'  => 'application/xml; charset='. $self->{charset},
      'json' => 'application/json; charset='. $self->{charset},
      'text' => 'text/plain; charset='. $self->{charset},
    };

    # New JSON Object if required
    if($self->{outtype} eq 'json') {
      $self->{json} = JSON->new()
        || return error("Can't create JSON instance!");
    } elsif($self->{outtype} eq 'xml') {
      $self->{xml} = XML::Simple->new( NumericEscape => ($self->{charset} eq 'UTF-8' ? 0 : 1) )
        || return error("Can't create XML instance!");
    } elsif($self->{outtype} eq 'text') {
        # ...
    } else {
       $self->{outtype} = 'text';
#      return error(sprintf("Can't create instance for typ '%s'!"),$self->{outtype});
    }
    $self->{TYP} = 'AJAX';

    # Forward name of Server for CGI::server_software
    $ENV{'SERVER_SOFTWARE'} = sprintf("xxvd %s",main::getVersion());
    $ENV{'SERVER_PROTOCOL'} = 'HTTP/1.1';

    eval "use Compress::Zlib";
    $self->{Zlib} = ($@ ? 0 : 1);

    return $self;
}

# ------------------
sub out {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || 0;
    my $para = shift || 0;
    my $name = shift || 'noName';
    my $type = shift || $self->{types}->{$self->{outtype}} || 'text/plain';
    my %args = @_;

    $self->{nopack} = 1;
    unless(defined $self->{header}) {
        # HTTP Header
        $self->{output_header} = $self->header($type, \%args);
    }

    $self->{sendbytes}+= length($data);

    if($type ne 'application/xml') {
      $self->{output}->{data} = $self->_prepare($data);
      $self->{output}->{param} = $self->_prepare($para)
        if($para);
    } else {
      $self->{output}->{DATA} = $self->_prepare($data);;
      $self->{output}->{$name}->{data} = $self->_prepare($data);
      $self->{output}->{$name}->{params} = $self->_prepare($para)
        if($para);
    }
}

################################################################################
# prepare every element to use same charset 'UTF-8'
sub _prepare {
    my $self = shift  || return error('No object defined!');
    my $data = shift  || return '';
    return $data unless($self->{charset} eq 'UTF-8');

    if(ref $data eq 'HASH') {
        foreach my $name (keys %$data) {
            if(ref $data->{$name}) {
                $self->_prepare($data->{$name});
            } else {
                if($data->{$name} && !utf8::is_utf8($data->{$name})) {
                  utf8::upgrade($data->{$name});
                }
            }
        }
    } elsif (ref $data eq 'ARRAY') {
        foreach (@$data) {
            if(ref $_) {
                $self->_prepare($_);
            } else {
                if($_ && !utf8::is_utf8($_)) {
                  utf8::upgrade($_);
                }
            }
        }
    }
    return $data;
}
# ------------------
sub printout {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $nopack = shift || $self->{nopack} || 0;

    my $content;
    if($self->{browser}->{Method} ne 'HEAD') {
      if( $self->{outtype} eq 'json' ) {
        if($self->{json}->can('encode')) { # Version 2.0 see http://search.cpan.org/~makamaka/JSON-2.04/lib/JSON.pm#Transition_ways_from_1.xx_to_2.xx.
          $content = $self->{json}->encode($self->{output});
        } else { # Version 1.0
          $JSON::UTF8=1 if($self->{charset} eq 'UTF-8');
          $content = $self->{json}->objToJson($self->{output});
        }
      } elsif($self->{outtype} eq 'xml') {
        $content = $self->{xml}->XMLout($self->{output});
      } else {
        if(ref $self->{output}->{data} eq 'ARRAY') {
          $content = "";
          foreach my $l (@{$self->{output}->{data}}) {                
            if(ref $l eq 'ARRAY') {                     
              $content .= join(",",@$l);
            } else {
              $content .= $l;
            }
            $content .= "\r\n";
          }
        } else {
          $content = $self->{output}->{data};
        }
      }

      # compress data
      $content = Compress::Zlib::memGzip($content)
        if(! $nopack and $self->{Zlib} and $self->{browser}->{accept_gzip});
    }

    if($content) {
      $self->{handle}->print($self->{output_header},$content);
      $self->{sendbytes}+= length($self->{output_header});
      $self->{sendbytes}+= length($content);
    } else {
      $self->{handle}->print($self->{output_header});
      $self->{sendbytes}+= length($self->{output_header});
    }

    undef $self->{output};
    undef $self->{output_header};
    undef $self->{nopack};
}


# ------------------
sub header {
# ------------------
    my $self = shift || return error('No object defined!');
    my $typ = shift || return error('No type defined!');
    my $arg = shift || {};

    $arg->{'Content-encoding'} = 'gzip'
        if($self->{browser}->{accept_gzip} && ((!defined $self->{nopack}) || $self->{nopack} == 0) );

    $arg->{'Cache-Control'} = 'no-cache, must-revalidate' if(!defined $arg->{'Cache-Control'});
    $arg->{'Pragma'} = 'no-cache' if(!defined $arg->{'Pragma'});

    if($self->{USER} && $self->{USER}->{sid}) { 
      $arg->{'cookie'} = $self->{cgi}->cookie({
        "name" => "sid",
        "value" => $self->{USER}->{sid},
        "expires" => "+4h"});
    }

    $self->{header} = 200;
    return $self->{cgi}->header(
        -type   =>  $typ,
        -status  => "200 OK",
        -expires => "now",
        -charset => $self->{charset},
        %{$arg},
    );
}

# ------------------
sub statusmsg {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $state = shift || return error('No state defined!');
    my $msg = shift;
    my $title = shift;
    my $typ = shift || $self->{types}->{$self->{outtype}} || 'text/plain';

    unless(defined $self->{header}) {
        $self->{nopack} = 1;

        my $s = {
            200 => '200 OK',
            204 => '204 No Response',
            301 => '301 Moved Permanently',
            302 => '302 Found',
            303 => '303 See Other',
            304 => '304 Not Modified',
            307 => '307 Temporary Redirect',
            400 => '400 Bad Request',
            401 => '401 Unauthorized',
            403 => '403 Forbidden',
            404 => '404 Not Found',
            405 => '405 Not Allowed',
            408 => '408 Request Timed Out',
            500 => '500 Internal Server Error',
            503 => '503 Service Unavailable',
            504 => '504 Gateway Timed Out',
        };
        my $status = $s->{200};
        $status = $s->{$state}
            if(exists $s->{$state});

        my $arg = {};

        $arg->{'Location'} = $msg
            if($state == 301);

        $arg->{'WWW-Authenticate'} = "Basic realm=\"xxvd\""
            if($state == 401);

        $arg->{'expires'} = (($state != 304) || (defined $self->{nocache} && $self->{nocache})) ? "now" : "+7d";

        $self->{header} = $state;
        $self->{output_header} = $self->{cgi}->header(
            -type   =>  $typ,
            -status  => $status,
            -charset => $self->{charset},
            %{$arg},
        );
    }
    if($msg && $title) {
       $self->msg( $msg, ( $self->{header} != 200)  );
    }   
}

# ------------------
# Send HTTP Status 401 (Authorization Required)
sub login {
# ------------------
    my $self = shift || return error('No object defined!');
    my $msg = shift || '';

    # Send 403 insteed 401, deny all ajax logins
    $self->statusmsg(403,$msg,gettext("Authorization required"));
}

# ------------------
# Send HTTP Status 403 (Access Forbidden)
sub status403 {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $msg = shift  || '';

    $self->statusmsg(403,$msg,gettext("Forbidden"));
}


# ------------------
# Send HTTP Status 404 (File not found)
sub status404 {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $file = shift || return error('No file defined!');
    my $why = shift || "";

    $file =~ s/$self->{Skin}\///g; # Don't post html root, avoid spy out

    $self->statusmsg(404,sprintf(gettext("Couldn't open file '%s' : %s!"),$file,$why),
                    gettext("Not found"));
}

# ------------------
sub question {
# ------------------
    my $self         = shift || return error('No object defined!');
    my $titel       = shift || 'undef';
    my $questions   = shift || return error ('No data defined!');
    my $erg         = shift || 0;

    my $quest;

    # Check Data
    if(ref $erg eq 'HASH' and ref $questions eq 'ARRAY' and exists $erg->{action}) {
        my $error;
        @$quest = @$questions;
        while (my ($name, $data) = splice(@$quest, 0, 2)) {

            $data->{typ} = 'string'
              unless($data->{typ});

            # Required value ...
            $error = $data->{req}
                if($data->{req} and not $erg->{$name});

            # Check Callback
            if(exists $data->{check} and ref $data->{check} eq 'CODE' and not $error) {
                ($erg->{$name}, $error) = $data->{check}($erg->{$name}, $data, $erg);
            }

            # Check on directory
            if($data->{typ} eq 'dir' and $data->{required} and not -d $erg->{$name}) {
                ($erg->{$name}, $error) = (undef, sprintf(gettext("Directory '%s' does not exist!"), $erg->{$name}));
            }

            # Check on file
            if($data->{typ} eq 'file' and $data->{required} and not -e $erg->{$name}) {
                ($erg->{$name}, $error) = (undef, sprintf(gettext("File '%s' does not exist!"), $erg->{$name}));
            }

            # Check on password (is not set the take the old password)
            if($data->{typ} eq 'password' and not $erg->{$name}) {
                $erg->{$name} = $data->{def};
            }

            if($error) {
                $self->err(sprintf(gettext("Error '%s' (%s) : %s!"), $data->{msg}, $name, $error));
                return undef;
            }
        }
        unless($error) {
            delete $erg->{action};
            return $erg;
        }
    }

  my $out = [];
  if(ref $questions eq 'ARRAY') {
    @$quest = @$questions;
  } else {
    @$quest = [ $questions ];
  }
    while (my ($name, $data) = splice(@$quest, 0, 2)) {
      my $type = $data->{typ} || 'string';
      my $def ;
      if(ref $data->{def} eq 'CODE') {
        $def = $data->{def}();
      } elsif(ref $data->{def} eq 'ARRAY') {
        $def = join(',',@{$data->{def}});
      } else {
        $def = $data->{def};
      } 
      my $choices ;
      if($data->{choices}) {
        if(ref $data->{choices} eq 'CODE') {
          $choices = $data->{choices}();
        } else {
          $choices = $data->{choices};
        }
        if(ref $choices eq 'ARRAY') {
          #$choices = join(',',@$choices);
        } 
      }

      if($type eq 'list' 
        && $data->{options} 
        && $data->{options} eq 'multi') {
        $type = 'multilist';
      }

      push(@$out,[$name,$data->{msg},$type,$def,$data->{req} ? 1 : 0,$data->{readonly} ? 1 : 0,$choices]);
    }
    $self->out( $out, 0 , 'question' );
    return undef;
}

# ------------------
sub msg {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || 0;
    my $err  = shift || 0;

    my $msg;
    if(ref $data eq 'ARRAY') {
      $msg = join("\r\n",@{$data});
    } else {
      $msg = $data || $err;
    }

    $self->{output}->{success} = $err ? \0 : \1;
    $self->out( $msg, 0, 'msg' );
}

# ------------------
sub message {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || 0;
    return $self->msg($data);
}

# ------------------
sub err {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || 0;
    return $self->msg($data,1);
}


# ------------------
sub typ {
# ------------------
    my $self = shift || return error('No object defined!');
    return $self->{TYP};
}

# ------------------
sub setCall {
# ------------------
    my $self = shift || return error('No object defined!');
    my $name = shift || return error('No name defined!');

    #$self->{call} = $name;
    #return $self->{call};
}

# ------------------
sub browser {
# ------------------
    my $self = shift || return error('No object defined!');
    return $self->{browser};
}

1;

package MediaLibParser::IMDb;

use strict;

use FindBin qw($RealBin);
use lib sprintf("%s", $RealBin);
use lib sprintf("%s/../lib", $RealBin);

use MediaLibParser;

our ( @ISA, @EXPORT, $VERSION );
require Exporter;
use vars qw(@ISA);
@ISA = qw( MediaLibParser Exporter);
$VERSION = "0.01";

sub new {
    my ( $type, %params ) = @_;
    my $class = ref $type || $type;
    
    my $self = $class->SUPER::new();
    bless $self, $class;
    
    foreach my $key ( keys %params ) {
        $self->$key($params{$key});
    }
    
    $self->url_main( 'http://www.imdb.com' );
    $self->url_results( '/find' );
    $self->url_actor( '/find' );
    $self->method_result('post');
    $self->method_media('get');
    $self->method_actor('post');
    $self->param_result(
        {
            's' => 'nm',
            'q' => $self->lookup_result,,
        }
                        );
    $self->param_actor(
        {
            's' => 'nm',
            'q' => $self->lookup_actor,
        }
                       );
    
    return $self;
}

sub lookup_actor { my ( $self, $new ) = @_; if (defined $new) { $new =~ s/^\s+|\s+$//g; $new =~ s/\s/\+/g; $self->{_search_actor} = $new; } return $self->{_search_actor}; }


sub actor_search_map {
    my $self = shift;
    
    my $map = {
        'imgurl' => {
            'look_down' => $self->regex_actor,
            'method' => 'attr',
            'method_params' => 'src',
        },
        'subpage' => {
            'look_down' => $self->regex_actor,
            'method' => 'attr',
            'method_params' => 'href',
            'post_proc' => sub {
                    $_[0] = $self->url_main. $_[0];
                    return $_[0];
                },
        }
              };
}
1;

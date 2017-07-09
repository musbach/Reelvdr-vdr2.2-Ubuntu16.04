package MediaLibParser::DVDPalace;

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
    
    $self->url_main( 'http://www.dvd-palace.de' );
    $self->url_results( '/dvddatabase/dbsearch.php' );
    $self->method_result('post');
    $self->method_media('get');
    $self->param_result(
        {
            'action' => 1,
            'start' => $self->start_result,
            'suchbegriff' => $self->lookup_result,
        }
                       );
    
    return $self;
}

sub media_search_map {
    my $self = shift;
    
    my $map = {
        'table'         => {
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0',
            },
        'title'         => {
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.0.0.3',
            'rel_address' => '.0.0.3',
            'method' => 'as_text',
            'post_proc' => sub {
                    $_[0] =~ s/\s\-\s.*//;
                    return $_[0];
                },
            },
        'subtitle'         => {
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.0.0.3',
            'rel_address' => '.0.0.3',
            'method' => 'as_text',
            'post_proc' => sub {
                    if ( $_[0] =~ s/.*?\s\-\s// ) {
                        return $_[0];
                    } else {
                        return undef;
                    }
                },
            },
        'imgurl'        => {
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.2.0.0',
            'rel_address' => '.2.0.0',
            'method' => 'attr',
            'method_params' => 'src',
            'post_proc' => sub {
                    my $tmp = $self->url_main. $_[0];
                    return $tmp;
                },
            'add' => [
                {
                    'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.2.0.2',
                    'rel_address' => '.2.0.2',
                    'method' => 'attr',
                    'method_params' => 'href',
                    'post_proc' => sub {
                            my $tmp = $self->url_main. $_[0];
                            return $tmp;
                        },
                },
                     ],
            'add_proc' => sub {
                    my ( $thumb, $href ) = @_;
                    if ( defined $href ) {
                        my $ua = LWP::UserAgent->new;
                        $ua->timeout(10);
                        
                        my $response = $ua->get( $href );
                        my $tree= HTML::TreeBuilder->new;
                        if ( $response->is_success ) {
                            $tree->parse($response->content);
                            my $entry = $tree->address('0.1.0.0.0.2.0.2.2.2.0.1.0');
                            if ( ref $entry ) {
                                return $entry->attr('src');
                            }
                        }
                    }
                    return $thumb;
                },
            },
        'plot'        => {
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.2.1.0.0.0',
            'rel_address' => '.2.1.0.0.0',
            'method' => 'content_array_ref',
            'post_proc' => sub {
                    my $tmp = [];
                    map {
                        unless ( ref $_ ) {
                            $_ =~ s/^\s+|\s+$//g;
                            push @$tmp, $_;
                        }
                    } @{$_[0]};
                    my $ret = join "\n", @$tmp;
                    return $ret;
                },
            },

        'country'        => {
            'look_down' => qr/^Originaltitel/,
            'after_look_down_method' => 'right',
            'method' => 'as_text',
            'post_proc' => sub {
                    my $country;
                    if ( $_[0] =~ /\((.*?)\s\d+\)/ ) {
                        $country = $1;
                    }
                    return $country;
                },
            },
        'year'        => {
            'look_down' => qr/^Originaltitel/,
            'after_look_down_method' => 'right',
            'abs_address' => '0.1.0.0.0.2.0.2.7.0.0.0.3.1',
            'rel_address' => '.3.1',
            'method' => 'as_text',
            'post_proc' => sub {
                    my $year;
                    if ( $_[0] =~ /\(.*?\s(\d+)\)/ ) {
                        $year = $1;
                    }
                    return $year;
                },
            },
        'runtime'        => {
            'look_down' => qr/^Laufzeit/,
            'after_look_down_method' => 'right',
            'method' => 'as_text',
            'post_proc' => sub {
                    $_[0] =~ s/\D//g;
                    return $_[0];
                },
            },
        'genres'        => {
            'look_down' => qr/^Genre/,
            'after_look_down_method' => 'right',
            'method' => 'content_array_ref',
            'post_proc' => sub {
                    my $ret = [];
                    map {
                        unless ( ref $_ ) {
                            $_ =~ s/^\W+|\W+$//g;
                            push @$ret, $_;
                        }
                    } @{$_[0]};
                    return $ret;
                },
            },
        'director'        => {
            'look_down' => qr/^Regisseur/,
            'after_look_down_method' => 'right',
            'method' => 'as_text',
            },
        'actors'        => {
            'look_down' => qr/^Darsteller/,
            'after_look_down_method' => 'right',
            'method' => 'clone',
            'post_proc' => sub {
                    my $tree = $_[0];
                    my @tmp;
                    map {
                        my $a = $_->content_array_ref;
                        my $tmp1 = [];
                        foreach my $element ( @$a ) {
                            push @$tmp1, $element unless ref $element;
                        }
                        my $tmp2 = join " ", @$tmp1;
                        $tmp2 =~ s/^\s+|\s+$//g;
                        push @tmp, $tmp2;
                        } ($tree->look_down( '_tag', 'a' ));
                    my $ret = join "\n", @tmp;
                    return $ret;
                },
            },
        'language'       => {
            'look_down' => qr/^Tonformat/,
            'after_look_down_method' => 'right',
            'method' => 'content_array_ref',
            'post_proc' => sub {
                    my $tmp = [];
                    map {
                        unless ( ref $_ ) {
                            $_ =~ s/^\s+|\s+$//g;
                            $_ =~ /(.*?):/;
                            push @$tmp, $1 if $1;
                        }
                    } @{$_[0]};
                    my $ret = join ", ", @$tmp;
                    return $ret;
                },
            },
        'comment'        => {
            'look_down' => qr/^Bildformat/,
            'after_look_down_method' => 'right',
            'method' => 'content_array_ref',
            'post_proc' => sub {
                    my $tmp = [];
                    map {
                        unless ( ref $_ ) {
                            $_ =~ s/^\s+|\s+$//g;
                            push @$tmp, $_ if $_;
                        }
                    } @{$_[0]};
                    my $ret = join "\n", @$tmp;
                    return $ret;
                },
            'add' => [
                {
                    'look_down' => qr/^Tonformat/,
                    'after_look_down_method' => 'right',
                    'method' => 'content_array_ref',
                    'post_proc' => sub {
                            my $tmp = [];
                            map {
                                unless ( ref $_ ) {
                                    $_ =~ s/^\s+|\s+$//g;
                                    push @$tmp, $_ if $_;
                                }
                            } @{$_[0]};
                            my $ret = join "\n", @$tmp;
                            return $ret;
                        },
                },
                {
                    'look_down' => qr/^Altersfreigabe /,
                    'after_look_down_method' => 'right',
                    'method' => 'as_text',
                    'post_proc' => sub {
                            $_[0] =~ s/^\W+|\W+$//g;
                            return "FSK ". $_[0];
                        },
                },
                      ],
            'add_proc' => sub {
                my $tmp = join "\n", @_;
                return $tmp;
            }
            },

    };
    
}



sub result_search_map {
    my $self = shift;
    
    my $map = {
        'resultcount'   => {
            'abs_address' => '0.1.0.0.0.2.0.2.2.0.0.1.0.0.1',
            },
        'table'         => {
            'abs_address' => '0.1.0.0.0.2.0.2.2.0.0.0',
            },
        'entry'         => {
            'search_from' => 1,
            },
        'imgurl'        => {
            'rel_address' => '.0.0.1',
            'post_proc' => sub {
                    $_[0] = $self->url_main. $_[0];
                    return $_[0];
                },
            },
        'title'         => {
            'rel_address' => '.1.2',
            'rel_alternate' => '.1.1.0',
                           },
        'titleurl'         => {
            'rel_address' => '.1.2',
            'post_proc' => sub {
                    $_[0] = $self->url_main. $_[0];
                    $_[0] =~ s/([^A-Za-z0-9])/sprintf("%%%02X", ord($1))/seg;
                    return $_[0];
                },
                           },
        'desc'          => {
            'rel_address' => '.1.4',
            'post_proc' => sub {
                    my $ret;
                    foreach my $ref ($_[0]->content_refs_list) {
                        if ( ref $$ref ) {
                            if ( $$ref->tag eq "br" ) {
                                $ret .= "\n";
                            } else {
                                $ret .= $$ref->as_text;
                            }
                        } else {
                            $ret .= $$ref;
                        }
                    }
                    $ret =~ s/^\s+|\s+$//sig;
                    return $ret;
                },
            },
              };
    return $map;
}
1;

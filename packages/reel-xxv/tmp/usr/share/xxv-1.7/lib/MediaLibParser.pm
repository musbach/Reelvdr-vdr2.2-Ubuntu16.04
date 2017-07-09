package MediaLibParser;

use strict;

use LWP::UserAgent;
use HTML::TreeBuilder;

our ( @ISA, @EXPORT, $VERSION );
@ISA = qw(Exporter);

use FindBin qw($RealBin);
use lib sprintf("%s", $RealBin);
use lib sprintf("%s/../lib", $RealBin);

@EXPORT = qw(&result_search);
$VERSION = "0.01";

sub new {
    my ( $type, %params ) = @_;
    my $class = ref $type || $type;
    
    my $self = {};
    bless $self, $class;
    
    return $self;
}

sub url_main { my ( $self, $new ) = @_; $self->{_url_main} = $new if defined $new; return $self->{_url_main}; }
sub url_results { my ( $self, $new ) = @_; $self->{_url_results} = $new if defined $new; return $self->{_url_main}.$self->{_url_results}; }
sub url_media { my ( $self, $new ) = @_; $self->{_url_media} = $new if defined $new; return $self->{_url_media}; }
sub url_actor { my ( $self, $new ) = @_; $self->{_url_actor} = $new if defined $new; return $self->{_url_main}.$self->{_url_actor}; }
sub method_result { my ( $self, $new ) = @_; $self->{_method_result} = $new if defined $new; return $self->{_method_result}; }
sub method_media { my ( $self, $new ) = @_; $self->{_method_media} = $new if defined $new; return $self->{_method_media}; }
sub method_actor { my ( $self, $new ) = @_; $self->{_method_actor} = $new if defined $new; return $self->{_method_actor}; }
sub lookup_result { my ( $self, $new ) = @_; $self->{_lookup_result} = $new if defined $new; return $self->{_lookup_result}; }
sub lookup_actor { my ( $self, $new ) = @_; $self->{_lookup_actor} = $new if defined $new; return $self->{_lookup_actor}; }
sub param_result { my ( $self, $new ) = @_; $self->{_param_result} = $new if defined $new; return $self->{_param_result}; }
sub param_actor { my ( $self, $new ) = @_; $self->{_param_actor} = $new if defined $new; return $self->{_param_actor}; }
sub start_result { my ( $self, $new ) = @_; $self->{_start_result} = $new if defined $new; return $self->{_start_result}; }
sub regex_actor { my ( $self, $new ) = @_; $self->{_regex_actor} = $new if defined $new; return $self->{_regex_actor}; }

sub actor {
    my $self = shift;
    
    my $tree = $self->actor_fetch;
    my $ret = $self->actor_search($tree, $self->actor_search_map);
}

sub result {
    my $self = shift;
    
    my $tree = $self->result_fetch;
    my @ret = $self->result_search($tree, $self->result_search_map);
    return @ret;
}

sub media {
    my $self = shift;
    
    my $tree = $self->media_fetch;
    my $ret = $self->media_search($tree, $self->media_search_map);
    return $ret;
}

sub actor_fetch {
    my $self = shift;

    return $self->_fetch( $self->method_actor, $self->url_actor, $self->param_actor );
}

sub media_fetch {
    my $self = shift;

    return $self->_fetch( $self->method_media, $self->url_media );
}

sub result_fetch {
    my $self = shift;

    return $self->_fetch( $self->method_result, $self->url_results, $self->param_result )
}

sub _fetch {
    my $self = shift;
    my $method = shift;
    my $url = shift;
    my $params = shift;
    
    my $ua = LWP::UserAgent->new( agent => 'Mozilla/5.0' );
    $ua->timeout(10);

    my $response;
    if ( defined $params ) {
        $response = $ua->$method( $url, $params );
    } else {
        $response = $ua->$method( $url );
    }
    my $tree= HTML::TreeBuilder->new;
    if ( $response->is_success ) {
        $tree->parse($response->content);
    }
    #print $tree->as_HTML();
    return $tree;
}

sub actor_search {
    my $self = shift;
    my $tree = shift;
    my $as_map = shift;
    
    my $url;
    
    if ( defined $as_map->{'subpage'} ) {
        my ( $address, $href);
        if ( defined $as_map->{'subpage'}->{'rel_address'} &&
             ref $tree->address($as_map->{'subpage'}->{'rel_address'}) ) {

            $address = $tree->address($as_map->{'subpage'}->{'rel_address'});
        } elsif ( defined $as_map->{'subpage'}->{'look_down'} ) {
            
            if ( defined $as_map->{'subpage'}->{'after_look_down_method'} ) {
                my $method = $as_map->{'subpage'}->{'after_look_down_method'};
                $address = $tree->look_down(
                    sub { $_[0]->tag eq "a" && $_[0]->as_text =~ $as_map->{'subpage'}->{'look_down'} }
                )->$method;
            } else {
                $address = $tree->look_down(
                    sub { $_[0]->tag eq "a" && $_[0]->as_text =~ $as_map->{'subpage'}->{'look_down'} }
                );
            }
        }
        if ( ref $address ) {
            my $method = $as_map->{'subpage'}->{'method'};
            my $method_params = $as_map->{'subpage'}->{'method_params'} || undef;
            if ( $method_params ) {
                $href = $address->$method($method_params);
            } else {
                $href = $address->$method;
            }
            if ( defined $href && defined $as_map->{'subpage'}->{'post_proc'} ) {
                my $coderef = $as_map->{'subpage'}->{'post_proc'};
                $href = &$coderef( $href );
            }
        }

        if ( $href ) {
            $self->url_media($href);
            $tree = $tree->delete;
            $tree = $self->media_fetch;
        }
    }
    my $address;
    if ( defined $as_map->{'imgurl'}->{'after_look_down_method'} ) {
        my $method = $as_map->{'imgurl'}->{'after_look_down_method'};
        $address = $tree->look_down(
            sub { $_[0]->tag eq "img" && $_[0]->attr('alt') =~ $as_map->{'imgurl'}->{'look_down'} }
        )->$method;
    } else {
        $address = $tree->look_down(
            sub { $_[0]->tag eq "img" && $_[0]->attr('alt') =~ $as_map->{'imgurl'}->{'look_down'} }
        );
    }
    if ( ref $address ) {
        my $method = $as_map->{'imgurl'}->{'method'};
        my $method_params = $as_map->{'imgurl'}->{'method_params'} || undef;
        if ( $method_params ) {
            $url = $address->$method($method_params);
        } else {
            $url = $address->$method;
        }
        if ( defined $url && defined $as_map->{'imgurl'}->{'post_proc'} ) {
            my $coderef = $as_map->{'imgurl'}->{'post_proc'};
            $url = &$coderef( $url );
        }
    }
    return $url;
}

sub media_search {
    my $self = shift;
    my $tree = shift;
    my $ms_map = shift;
    
    my $ret = {};
    if ( ref $tree->address($ms_map->{'table'}->{'abs_address'}) ) {
        my $table = $tree->address($ms_map->{'table'}->{'abs_address'});
        
        foreach my $key ( keys %$ms_map ) {
            next if $key eq 'table';
            
            my $address;
            if ( defined $ms_map->{$key}->{'rel_address'} &&
                 ref $table->address($ms_map->{$key}->{'rel_address'}) ) {

                $address = $table->address($ms_map->{$key}->{'rel_address'});
            } elsif ( defined $ms_map->{$key}->{'look_down'} ) {
                
                my $method = $ms_map->{$key}->{'after_look_down_method'};
                my $look_address = $table->look_down(
                    sub { $_[0]->tag eq "td" && $_[0]->as_text =~ $ms_map->{$key}->{'look_down'} }
                );
                $address = $look_address->$method if ref $look_address
            }
            $ret->{$key} = $self->_media_search_field( $address, $ms_map->{$key} ) if ref $address;
            
            if ( defined $ms_map->{$key}->{'add'} ) {
                my $add;
                foreach my $sub ( @{$ms_map->{$key}->{'add'}} ) {
                    my $sub_address;
                    if ( defined $sub->{'rel_address'} && ref $table->address( $sub->{'rel_address'}) ) {
                        
                        $sub_address = $table->address( $sub->{'rel_address'});
                    } elsif ( defined $sub->{'look_down'} ) {
                        
                        my $method = $sub->{'after_look_down_method'};
                        my $look_sub_address = $table->look_down(
                            sub { $_[0]->tag eq "td" && $_[0]->as_text =~ $sub->{'look_down'} }
                        );
                        $sub_address = $look_sub_address->$method if ref $look_sub_address;
                    }
                    push @$add, $self->_media_search_field( $sub_address, $sub ) if ref $sub_address;
                }
                if ( defined $ms_map->{$key}->{'add_proc'} ) {
                    my $coderef = $ms_map->{$key}->{'add_proc'};
                    $ret->{$key} = &$coderef( $ret->{$key}, @$add );
                }
            }
        }
    }
    return $ret;
}

sub _media_search_field {
    my $self = shift;
    my $address = shift;
    my $ms_sub_map = shift;
    my $ret;

    my $method = $ms_sub_map->{'method'};
    my $method_params = $ms_sub_map->{'method_params'} || undef;
    if ( $method_params ) {
        $ret = $address->$method($method_params);
    } else {
        $ret = $address->$method;
    }
    if ( defined $ret && defined $ms_sub_map->{'post_proc'} ) {
        my $coderef = $ms_sub_map->{'post_proc'};
        $ret = &$coderef( $ret );
    }
    return $ret;
}

sub result_search {
    my $self = shift;
    my $tree = shift;
    my $rs_map = shift;
    
    my $ret = [];
    my $resultcount = 0;
    if ( ref $tree->address($rs_map->{'resultcount'}->{'abs_address'}) ) {
        $resultcount = $tree->address($rs_map->{'resultcount'}->{'abs_address'})->as_text;
    }
    if ( ref $tree->address($rs_map->{'table'}->{'abs_address'}) ) {
        my $table = $tree->address($rs_map->{'table'}->{'abs_address'});
        while ( 1 ) {
            my ($imgurl, $title, $titleurl, $desc);
            my $entry = $table->address('.'.$rs_map->{'entry'}->{'search_from'}++);
            if ( ref $entry ) {
                if ( ref $entry->address($rs_map->{'imgurl'}->{'rel_address'}) ) {
                    $imgurl = $entry->address($rs_map->{'imgurl'}->{'rel_address'})->attr('src');
                    if ( $imgurl && defined $rs_map->{'imgurl'}->{'post_proc'} ) {
                        my $coderef = $rs_map->{'imgurl'}->{'post_proc'};
                        $imgurl = &$coderef( $imgurl );
                    }
                }
                if ( ref $entry->address($rs_map->{'title'}->{'rel_address'}) ) {
                    $title = $entry->address($rs_map->{'title'}->{'rel_address'})->as_text;
                    $titleurl = $entry->address($rs_map->{'title'}->{'rel_address'})->attr('href');
                    unless ( $title ) {
                        if ( ref $entry->address($rs_map->{'title'}->{'rel_alternate'}) ) {
                            $title = $entry->address($rs_map->{'title'}->{'rel_alternate'})->as_text;
                        }
                    }
                    if ( $title && defined $rs_map->{'title'}->{'post_proc'} ) {
                        my $coderef = $rs_map->{'title'}->{'post_proc'};
                        $title = &$coderef( $title );
                    }
                    if ( $titleurl && defined $rs_map->{'titleurl'}->{'post_proc'} ) {
                        my $coderef = $rs_map->{'titleurl'}->{'post_proc'};
                        $titleurl = &$coderef( $titleurl );
                    }
                }
                if ( ref $entry->address($rs_map->{'desc'}->{'rel_address'}) ) {
                    $desc = $entry->address($rs_map->{'desc'}->{'rel_address'})->clone;
                    if ( $desc && defined $rs_map->{'desc'}->{'post_proc'} ) {
                        my $coderef = $rs_map->{'desc'}->{'post_proc'};
                        $desc = &$coderef( $desc );
                    }
                }
                push @$ret, [ $titleurl, $imgurl, $title, $desc ];
            } else {
                last;
            }
        }
    }
    return ($ret, $resultcount);

}
1;

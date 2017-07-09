package XXV::MODULES::MEDIALIB;

use strict;

use Tools;
use File::Path;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');

    my $args = {
        Name => 'MEDIALIB',
        Prereq => {
            'Digest::MD5' => 'Perl interface to the MD5 Algorithm',
            'LWP::Simple' => 'simple procedural interface to LWP',
            'LWP::UserAgent' => 'simple procedural interface to LWP',
        },
        Description => gettext('This module manages media like DVDs, VCD, etc.'),
        Status => sub{ $obj->status(@_) },
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            usecache => {
                description => gettext('Cache images'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            libraryimagedir => {
                description => gettext('Location of coverimages.'),
                default     => '/var/cache/xxv/libraryimages',
                type        => 'dir',
                required    => gettext("This is required!"),
            },
            deflanguage => {
                description => gettext('Default media language'),
                default     => 'german',
                type        => 'string',
            },
            defmediatype => {
                description => gettext('Default mediatype'),
                default     => 1,
                type        => 'list',
                choices     => sub {
                                    my $erg = $obj->_get_mediatype_as_array();
                                    map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                    return @$erg;
                                 },
            },
            defrange => {
                description => gettext('Default range'),
                default     => 'ABC',
                type        => 'list',
                choices     => sub {
                                    my $erg = $obj->_get_ranges_as_array();
                                    map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                    return @$erg;
                                 },
            },        },
        Commands => {
            mllist => {
                description => gettext('List medias'),
                short       => 'mll',
                callback    => sub{ $obj->listMedia(@_) },
                DenyClass   => 'media',
            },
            mldisplay => {
                description => gettext('Display media'),
                short       => 'mld',
                callback    => sub{ $obj->displayMedia(@_) },
                DenyClass   => 'media',
            },
            mlnew => {
                description => gettext('Create new media'),
                short       => 'mln',
                callback    => sub{ $obj->createMedia(@_) },
                DenyClass   => 'media',
            },
            mledit => {
                description => gettext('Edit media'),
                short       => 'mle',
                callback    => sub{ $obj->editMedia(@_) },
                DenyClass   => 'media',
            },
            mlcopy => {
                description => gettext('Copy media'),
                short       => 'mlc',
                callback    => sub{ $obj->copyMedia(@_) },
                DenyClass   => 'media',
            },
            mldelete => {
                description => gettext('Delete media'),
                short       => 'mlt',
                callback    => sub{ $obj->deleteMedia(@_) },
                DenyClass   => 'media',
            },
            mlresearch => {
                description => gettext('Research media'),
                short       => 'mlr',
                callback    => sub{ $obj->researchMedia(@_) },
                DenyClass   => 'media',
            },
            mlcache => {
                description => gettext('Get image from media cache'),
                short       => 'mlca',
                callback    => sub{ $obj->mediacache(@_) },
                DenyClass   => 'media',
                binary      => 'cache'
            },
            mlsave => {
                description => gettext('Save media'),
                short       => 'mls',
                callback    => sub{ $obj->saveMedia(@_) },
                DenyClass   => 'media',
            },
            mlimport => {
                description => gettext('Import media'),
                short       => 'mli',
                callback    => sub{ $obj->importMedia(@_) },
                DenyClass   => 'media',
            },
            mlsearch => {
                description => gettext('Search media'),
                short       => 'mlse',
                callback    => sub{ $obj->searchMedia(@_) },
                DenyClass   => 'media',
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

    # read the DB Handle
    $self->{dbh} = delete $attr{'-dbh'};

    # The Initprocess
    my $erg = $self->_init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub _init {
# ------------------
    my $obj = shift || return error('No object defined!');

    unless($obj->{dbh}) {
      panic("Session to database is'nt connected");
      return 0;
    }

    my $version = main::getDBVersion();
    # don't remove old table, if updated rows => warn only
    if(!tableUpdated($obj->{dbh},'MEDIALIB_ACTORS',$version,0)
       ||!tableUpdated($obj->{dbh},'MEDIALIB_VIDEODATA',$version,0)
       ||!tableUpdated($obj->{dbh},'MEDIALIB_VIDEOGENRE',$version,0)) {
      return 0;
    }

    # Look for tables or create this tables
    $obj->{dbh}->do(qq|
        CREATE TABLE IF NOT EXISTS MEDIALIB_ACTORS (
          name varchar(255) NOT NULL default '',
          actorid varchar(15) NOT NULL default '',
          imgurl varchar(255) NOT NULL default '',
          checked timestamp(14) NOT NULL,
          PRIMARY KEY  (name)
        ) COMMENT = '$version'
    |);

    $obj->{dbh}->do(qq|
        CREATE TABLE IF NOT EXISTS MEDIALIB_VIDEODATA (
          id int(10) unsigned NOT NULL auto_increment,
          md5 varchar(32) default NULL,
          title varchar(255) default NULL,
          subtitle varchar(255) default NULL,
          language varchar(255) default NULL,
          diskid varchar(15) default NULL,
          comment varchar(255) default NULL,
          disklabel varchar(32) default NULL,
          imdbID varchar(15) default NULL,
          year year(4) default NULL,
          imgurl varchar(255) default NULL,
          director varchar(255) default NULL,
          actors text,
          runtime int(10) unsigned default NULL,
          country varchar(255) default NULL,
          plot text,
          filename varchar(255) default NULL,
          filesize int(16) unsigned default NULL,
          filedate datetime default NULL,
          audio_codec varchar(255) default NULL,
          video_codec varchar(255) default NULL,
          video_width int(10) unsigned default NULL,
          video_height int(10) unsigned default NULL,
          istv tinyint(1) unsigned NOT NULL default '0',
          lastupdate timestamp(14) NOT NULL,
          seen tinyint(1) unsigned NOT NULL default '0',
          mediatype int(10) unsigned NOT NULL default '0',
          custom1 varchar(255) default NULL,
          custom2 varchar(255) default NULL,
          custom3 varchar(255) default NULL,
          custom4 varchar(255) default NULL,
          created datetime default NULL,
          owner_id int(11) NOT NULL default '0',
          PRIMARY KEY  (id),
          KEY seen (seen),
          KEY title_idx (title),
          KEY diskid_idx (diskid),
          KEY mediatype (mediatype,istv),
          FULLTEXT KEY actors_idx (actors),
          FULLTEXT KEY comment (comment)
        ) COMMENT = '$version'
    |);

    $obj->{dbh}->do(qq|
        CREATE TABLE IF NOT EXISTS MEDIALIB_VIDEOGENRE (
          video_id int(10) unsigned NOT NULL default '0',
          genre_id int(10) unsigned NOT NULL default '0',
          PRIMARY KEY  (video_id,genre_id)
        ) COMMENT = '$version'
    |);

    unless(-d $obj->{libraryimagedir}) {
        mkpath($obj->{libraryimagedir}) or error "Couldn't mkpath $obj->{libraryimagedir} : $!";
        lg sprintf('mkdir path "%s" ',
                $obj->{coverimages},
            );
    }

    1;
}

# ------------------
# Name:  status
# Descr: Standardsubroutine to report statistical data for Report Plugin.
# Usage: my $report = $obj->status($console);
# ------------------
sub status {
    my $obj = shift || return error('No object defined!');
    
    my $sql = qq|
SELECT SQL_CACHE 
    COUNT(id)
FROM
    MEDIALIB_VIDEODATA
|;

    my $erg = $obj->{dbh}->selectrow_arrayref($sql);
    return {
        message => sprintf(gettext('Media library has stored %d medias'), $erg->[0]),
    };

}

# ------------------
sub researchMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params = shift || {};

    if(ref $params eq 'HASH') {
        
        my $medias;
        if ( $params->{source} eq 'dvdpalace' ) {
            
            eval "use MediaLibParser::DVDPalace";
            return panic("\nCouldn't load perl module: $_\nPlease install this module on your system:\nperl -MCPAN -e 'install $_'") if($@);
            
            my $mlp = MediaLibParser::DVDPalace->new(
                        'lookup_result' => $params->{title},
                        'start_result' => defined $params->{start} ? $params->{start} : 0,
                                                    );
            
            ( $medias, $params->{hitcount} ) = $mlp->result;
        }
        return $console->table($medias, $params);
    }
    
}

# ------------------
sub createMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || 0;

    $obj->editMedia($console, $config, 0, $params);
}

# ------------------
sub copyMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || 0;

    my $sql = qq|
SELECT SQL_CACHE 
    *
FROM
    MEDIALIB_VIDEODATA
WHERE
    id = ?
|;
    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($id)
        or return $console->err(sprintf(gettext("Media with ID '%s' does not exist in the database!"),$id));
    my $erg = $sth->fetchrow_hashref();
    delete $erg->{id};
    $erg->{range} = $params->{range} if($params && $params->{range});

    $obj->editMedia($console, $config, 0, $erg);
}

# ------------------
sub importMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || {};

    $id = delete $params->{id} if defined $params->{id};
    my $range = delete $params->{range} if defined $params->{range};

    if ( ref $params && defined $params->{import} ) {
       
        if ( $params->{source} eq 'dvdpalace' ) {
            eval "use MediaLibParser::DVDPalace";
            return panic("\nCouldn't load perl module: MediaLibParser::DVDPalace") if($@);
            
            my $mlp = MediaLibParser::DVDPalace->new(
                        'url_media' => $params->{import},
                                                    );
            
            $params = $mlp->media;
        }
        
        $params->{id} = $id;
        
        if ( $params->{genres} ) {
            my $gen_hash_1 = $obj->_get_videogenres_as_hash;
            my $gen_hash_2 = {
                'Komödie' => 'Comedy',
                'Musik' => 'Music',
                'Musikfilm' => 'Music',
                'Kriegsfilm' => 'War',
                'Abenteuer' => 'Adventure',
                'Kinderfilm' => 'Childs',
                'Science Fiction' => 'Sci-Fi',
                
                # noch mit Genres auffuellen so wie sie auftauchen.
            };
            my $ret;
            foreach my $key ( @{$params->{genres}} ) {
                if( defined $gen_hash_1->{$key} ) {
                    push (@$ret, $gen_hash_1->{$key}->{id});
                } elsif ( defined $gen_hash_2->{$key} ) {
                    foreach my $name ( keys %$gen_hash_1 ) {
                        push (@$ret, $gen_hash_1->{$name}->{id}) if $gen_hash_2->{$key} eq $gen_hash_1->{$name}->{name};
                    }
                } elsif ( $key =~ /TV-Serie/i ) {
                    $params->{istv} = 1;
                } else {
                    debug ('Unknown genre: '. $key);
                }
            }
            $params->{genres} = $ret;
        }

        foreach my $key ( keys %$params ) {
            $params->{$key} =~ s/\r\n/\n/g;
        }
    }
    
    $params->{mediatype} = $config->{defmediatype} unless defined $params->{mediatype} && $params->{mediatype} != 0;
    $params->{language} = $config->{deflanguage} unless defined $params->{language} && $params->{language} ne '';
    
    $console->table({},
        {
            %$params,
            mediatypes => $obj->_get_mediatype_as_array,
            allgenres => $obj->_get_videogenres_as_array,
            range => $range,
            ranges => $obj->_get_ranges_as_array,
        }
    );
}

# ------------------
sub searchMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || {};

    my $erg = [];
    my $setcount;

    if ( defined $params->{'search'} ) {

        my @wheres;
        my ($where, $join);
        my $like = defined $params->{'searchitem'} && $params->{'searchitem'} ne '' ? '%%'.$params->{'searchitem'}.'%%' : '%%';
        if ( ( defined $params->{'searchitem'} && $params->{'searchitem'} ne '' && defined $params->{'selfields'} ) ||
               defined $params->{'genres'} ) {
            $where .= "WHERE ";
        }
        if ( defined $params->{'searchitem'} && $params->{'searchitem'} ne '' && defined $params->{'searchitem'} ) {
            if ( ref $params->{'selfields'} ) {
                foreach my $field ( @{$params->{'selfields'}} ) {
                    if ( $field eq "mediatype" ) {
                        push @wheres, $field. "=". $obj->_get_mediatype_idbyname($params->{'searchitem'});
                    } else {
                        push @wheres, $field. " LIKE ". '"'. $like. '"';
                    }
                }
                $where .= join " OR ", @wheres;
            } else {
                if ( $params->{'selfields'} eq "mediatype" ) {
                    $where .= $params->{'selfields'}. "=". $obj->_get_mediatype_idbyname($params->{'searchitem'});
                } else {
                    $where .= $params->{'selfields'}. " LIKE ". '"'. $like. '"';
                }
            }
        }
        if ( defined $params->{'searchitem'} && $params->{'searchitem'} ne '' && defined $params->{'selfields'} && defined $params->{'genres'} ) {
            $where .= " AND ";
        }
        if ( defined $params->{'genres'} ) {
            if ( ref $params->{'genres'} ) {
                $where .= 'genre_id IN ('. join (",", @{ $params->{'genres'} } ). ')';
            } else {
                $where .= 'genre_id='. $params->{'genres'};
            }
            $join = qq|
LEFT JOIN
    MEDIALIB_VIDEOGENRE
ON
    id=video_id
|;
        }
    
        my $sql = qq|
SELECT SQL_CACHE 
    id, imgurl, title, subtitle, year, director, SUBSTRING(plot,1,200)
FROM
    MEDIALIB_VIDEODATA
$join
$where
ORDER BY title
|;

        $erg = $obj->{dbh}->selectall_arrayref($sql);
        $setcount = defined $erg ? scalar @$erg : 0;
        map {
            $_->[1] =~ s/([^A-Za-z0-9])/sprintf("%%%02X", ord($1))/seg;
        } @$erg if $config->{usecache} eq "y";
    }

    $console->table($erg,
        {
            %$params,
            fields => $obj->_getsearchsfields_as_array,
            allgenres => $obj->_get_videogenres_as_array,
            setcount => $setcount,
            range => defined $params->{range} && $params->{range} ne '' ? $params->{range} : $config->{defrange},
            ranges => $obj->_get_ranges_as_array,
            usecache => $config->{usecache},
        }
    );
}

# ------------------
sub editMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || {};

    my $range = delete $params->{range} if defined $params->{range};
    if ( $id ) {
        my $sql = qq|
SELECT SQL_CACHE 
    *
FROM
    MEDIALIB_VIDEODATA
WHERE
    id = ?
|;
        my $sth = $obj->{dbh}->prepare($sql);
        $sth->execute($id)
            or return $console->err(sprintf(gettext("Media with ID '%s' does not exist in the database!"),$id));
        $params = $sth->fetchrow_hashref();
        $params->{genres} = $obj->_get_videogenres_byvideoid($id);
        $params->{filedate} = '' if $params->{filedate} eq '0000-00-00 00:00:00';
    }

    if ( ref $params ) {
        foreach my $key ( keys %$params ) {
            $params->{$key} =~ s/\r\n/\n/g if($params->{$key});
        }
    }

    $params->{mediatype} = $config->{defmediatype} unless defined $params->{mediatype} && $params->{mediatype} != 0;
    $params->{language} = $config->{deflanguage} unless defined $params->{language} && $params->{language} ne '';
    
    $console->table({},
        {
            %$params,
            mediatypes => $obj->_get_mediatype_as_array,
            allgenres => $obj->_get_videogenres_as_array,
            range => $range,
            ranges => $obj->_get_ranges_as_array,
        }
    );
}

# ------------------
sub listMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || "";
    my $params  = shift;

    my ($r, $range,$where);
    $r = uc($params->{range})
      if ( $params && defined $params->{range} && $params->{range}=~ /^.+?/ );
    $r = uc($config->{defrange})
      if ( ! $r );
    
    if ( $r eq "SEEN" ) {
        $where = qq| WHERE seen=1 |;
    } elsif ( $r eq "UNSEEN" ) {
        $where = qq| WHERE seen=0 |;
    } elsif ( $r eq "WANTED" ) {
        $where = qq| WHERE mediatype=50 |;
    } elsif( $r ne "ALL" ) {
        if ( $r eq "NUM" ) {
            $range = '"1","2","3","4","5","6","7","8","9","0"';
        } else {
            $range = '"'. join( '","', split( //, $r)). '"';
        }
        $where = qq| WHERE UCASE(SUBSTRING(title,1,1)) IN ($range) |;
    } else {
      $where = "";
    }

    my $sql = qq|
SELECT SQL_CACHE 
    id, imgurl, title, subtitle, year, director, SUBSTRING(plot,1,200)
FROM
    MEDIALIB_VIDEODATA
$where
ORDER BY title
|;

    my $erg = $obj->{dbh}->selectall_arrayref($sql);
    my $setcount = defined $erg ? scalar @$erg : 0;
    
    # Hier darf in Feld 6 \n nicht durch \r\n ersetzt werden
    # da sonst die Formatierung des Listenansicht nicht mehr passt
    map {
        $_->[1] =~ s/([^A-Za-z0-9])/sprintf("%%%02X", ord($1))/seg;
    } @$erg if $config->{usecache} eq "y";
    
    my $param = {
        setcount => $setcount,
        range => $r,
        ranges => $obj->_get_ranges_as_array,
        usecache => $config->{usecache},
    };
    return $console->table($erg, $param);
}

# ------------------
sub displayMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || "";
    my $params  = shift;

    lg("Details for mediaid:". $id);

    my $sql = qq|
SELECT SQL_CACHE 
    *
FROM
    MEDIALIB_VIDEODATA
WHERE id = ?
|;

    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($id)
        or return $console->err(sprintf(gettext("Media with ID '%s' does not exist in the database!"),$id));
    my $erg = $sth->fetchall_arrayref();
    my $actors = $obj->_get_actors( $erg->[0][12] );
    my $actorcount = ref $actors ? scalar @$actors : 0;
    $erg->[0][10] =~ s/([^A-Za-z0-9])/sprintf("%%%02X", ord($1))/seg if $config->{usecache} eq "y";
    $erg->[0][18] = '' if $erg->[0][18] eq '0000-00-00 00:00:00';
    
    #\r\n will be replace with <br/> by output from OUTPUT::HTML    
    $erg->[0][6] =~ s/\n/\r\n/g;
    $erg->[0][15] =~ s/\n/\r\n/g;
    
    my $param = {
        mediatype => $obj->_get_mediatype_namebyid( $erg->[0][26] ),
        actors => $actors,
        actorcount => $actorcount,
        genres_all => $obj->_get_videogenres_as_hash_by_id,
        genres_sel => $obj->_get_videogenres_byvideoid( $id ),
        range => defined $params->{range} && $params->{range} ne '' ? $params->{range} : $config->{defrange},
        ranges => $obj->_get_ranges_as_array,
        usecache => $config->{usecache},
    };
    return $console->table($erg, $param);
}

# ------------------
sub saveMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || "";
    my $params  = shift;

    if ( ref $params && defined $params->{save} ) {
        
        delete $params->{save};
        delete $params->{source};
        my $range = delete $params->{range};
        
        foreach my $key ( keys %$params ) {
            $params->{$key} =~ s/\r\n/\n/g;
        }

        $obj->_saveActors($console, $params->{actors});
        my $genres = delete $params->{genres};
        $obj->_saveMedia($params);

        if(not $params->{id}) {
            lg("Got no id from CGI");
            $params->{id} = $obj->{dbh}->selectrow_arrayref('SELECT SQL_CACHE  max(ID) FROM MEDIALIB_VIDEODATA')->[0];
            lg("ID fetched from DB: ". $params->{id});
        }

        if ( $params->{id} ) {
            $obj->_saveGenres($params->{id}, $genres);
        }

        $console->message(sprintf gettext('Media %s saved!'), $params->{id});
        debug sprintf('%s media is saved%s',
            ($id ? 'Changed' : 'New'),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
            );
        $console->redirect({url => '?cmd=mldisplay&data='. $params->{id}."&__range=". $range, wait => 2})
            if($console->typ eq 'HTML');

    }
}

# ------------------
sub deleteMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || "";
    my $params  = shift;

    my @media  = reverse sort{ $a <=> $b } split(/[^0-9]/, $id);

    {
        my $sql = sprintf('DELETE FROM MEDIALIB_VIDEODATA WHERE id IN (%s)', join(',' => ('?') x @media)); 
        my $sth = $obj->{dbh}->prepare($sql);
        if(!$sth->execute(@media)) {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
            $console->err(sprintf gettext("Media with ID '%s' does not exist in the database!"), join(',', @media));
            return 0;
        }
    }

    {
        my $sql = sprintf('DELETE FROM MEDIALIB_VIDEOGENRE WHERE video_id IN (%s)', join(',' => ('?') x @media)); 
        my $sth = $obj->{dbh}->prepare($sql);
        if(!$sth->execute(@media)) {
            error sprintf("Couldn't execute query: %s.",$sth->errstr);
            $console->err(sprintf gettext("Genres for Media with ID '%s' does not exist in the database!"), join(',', @media));
            return 0;
        }
    }

    $console->message(sprintf gettext("Media %s is deleted."), join(',', @media));
    debug sprintf('media with id "%s" is deleted%s',
                join(',', @media),
                ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
                );
    $console->redirect({url => '?cmd=mllist', wait => 1})
        if($console->typ eq 'HTML');
}

# ------------------
sub _saveActors {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $input = shift || '';
    
    $input =~ s/\r\n/\n/g;
    my @actors = split /\n/, $input;

    my $rob = main::getModule('ROBOT')
        or return error('No ROBOT Module installed!');

    $rob->saveRobot('actorimage', sub{
        my $dbh = shift || return;
        my $name = shift || return;

        lg( sprintf("Looking for image of %s", $name ));

        eval "use MediaLibParser::IMDb";
        return panic("\nCouldn't load perl module: MediaLibParser::DVDPalace") if($@);

        my $mlp = MediaLibParser::IMDb->new(
                    'lookup_actor' => $name,
                    'regex_actor' => qr/$name/,
                                            );
       
        my $image = $mlp->actor || '';
        if ( $image ) {
            lg( sprintf("Found image for %s at %s",($name, $image)));
        } else {
            lg( sprintf("No image found for %s", $name));
        }


        my $sql = sprintf("INSERT INTO MEDIALIB_ACTORS (%s) VALUES (%s)",
            'name, imgurl',
            '?, ?',
        );
        my $sth = $dbh->prepare( $sql );
        $sth->execute( $name, $image );
        $sth->finish;
        return 1;
    }
                   );

    
    my $db_actors = $obj->_get_actors_as_hash_by_name($input);
    
    my $needrobot;
    foreach my $name ( @actors ) {
        
        next if grep /^$name$/i, ( keys %$db_actors );
        $rob->register('actorimage', $obj->{dbh}, $name);
        lg( sprintf("Registered ROBOT for %s", $name));
        $needrobot = 1;
    }

    if ( $needrobot ) {
        $rob->start('actorimage');
        $rob->clean('actorimage');
    }
}

# ------------------
sub _saveGenres {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $videoid = shift || 0;
    my $genres = shift || [];
    
    my $sql = sprintf("REPLACE INTO MEDIALIB_VIDEOGENRE (%s) VALUES (%s)",
            'video_id, genre_id',
            '?, ?',
    );
    my $sth = $obj->{dbh}->prepare( $sql );

    if ( ref $genres ) {
        foreach my $genre ( @$genres ) {
            $sth->execute( $videoid, $genre );
        }
    } else {
        $sth->execute( $videoid, $genres );
    }
    $sth->finish;
}





# ------------------
sub _saveMedia {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    if(ref $data eq 'HASH') {
        my ($names, $vals, $kenn);
        map {
            push(@$names, $_);
            push(@$vals, $data->{$_}),
            push(@$kenn, '?'),
        } sort keys %$data;

        my $sql = sprintf("REPLACE INTO MEDIALIB_VIDEODATA (%s) VALUES (%s)",
                join(', ', @$names),
                join(', ', @$kenn),
        );
        my $sth = $obj->{dbh}->prepare( $sql );
        $sth->execute( @$vals );
        $sth->finish;
    } else {
        #my $sth = $obj->{dbh}->prepare('REPLACE INTO AUTOTIMER VALUES (?,?,?,?,?,?,?,?,?)');
        #$sth->execute( @$data );
    }
}

# ------------------
sub _get_actors {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $input = shift || return '';
    
    $input =~ s/\r\n/\n/g;
    my @actors = split /\n/, $input;
    map {
        $_ = uc($_);
    } @actors;

    my $sql = sprintf(qq|
SELECT SQL_CACHE 
    UPPER(name) as name, imgurl
FROM
    MEDIALIB_ACTORS
WHERE
    UPPER(name) IN (%s)
|, join(',' => ('?') x @actors));
    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute(@actors)
        or return undef;
    my $erg = $sth->fetchall_hashref('name');

    foreach my $actor ( split /\n/, $input ) {
        if ( not defined $erg->{uc($actor)} ) {
            $erg->{$actor} = {
                'name' => $actor,
                'imgurl' => '',
            };
        }
    }
    
    my $ret = [];
    foreach my $actor ( split /\n/, $input ) {
        if($actor) {
          $erg->{uc($actor)}->{imgurl} =~ s/([^A-Za-z0-9])/sprintf("%%%02X", ord($1))/seg
            if($erg->{uc($actor)}->{imgurl});
          push @$ret, [$actor, $erg->{uc($actor)}->{imgurl}];
        }
    }
    
    return $ret;
}

# ------------------
sub _get_actors_as_hash_by_name {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $input = shift || return '';
    
    $input =~ s/\r\n/\n/g;
    my @actors = split /\n/, $input;
  
    my $sql = sprintf(qq|
SELECT SQL_CACHE 
    name, imgurl
FROM
    MEDIALIB_ACTORS
WHERE
    name IN (%s)
|, join(',' => ('?') x @actors));
    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute(@actors)
        or return undef;
    my $erg = $sth->fetchall_hashref('name');
    return $erg;
}

sub _nocover {
    my $obj = shift || return error('No object defined!');
    my $HTTPD  = main::getModule('HTTPD');
    my $nocover = sprintf('%s/%s/images/nocover', $HTTPD->{paths}->{HTMLDIR}, $HTTPD->{HtmlRoot});

    if(-r $nocover . ".png") {
      return ($nocover . ".png");
    } 
    elsif(-r $nocover . ".gif") {
      return ($nocover . ".gif");
    } else {
      $nocover = sprintf('%s/default/images/nocover', $HTTPD->{paths}->{HTMLDIR});

      if(-r $nocover . ".png") {
        return ($nocover . ".png");
      } else {
        return ($nocover . ".gif");
    }
  }
}


# ------------------
sub mediacache {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $id   = shift || 0;
    my $params  = shift || '';
    
    my $image;
    if ( ref $params ) {
        if ( defined $params->{source} && $params->{source} ne '') {
            my $ctx = Digest::MD5->new;
            $ctx->add($params->{source});
            my $digest = $ctx->hexdigest;;
            my $cache_image = $obj->{libraryimagedir}. '/'. $digest. '.jpg';
            my $cache_noimage = $obj->{libraryimagedir}. '/'. $digest. '.missed';
            if ( -e $cache_image ) {
                $image = $cache_image;
            } elsif ( -e $cache_noimage ) {
                $image = $obj->_nocover();
            } else {
                my $ret = getstore( $params->{source}, $cache_image );
                lg( 'Get store return code: '. $ret );
                if ( $ret == 200 ) {
                    $image = $cache_image;
                } else {
                    touch($cache_noimage);
                    $image = $obj->_nocover();
                }
            }
        } else {
            $image = $obj->_nocover();
        }
    } else {
        $image = $obj->_nocover();
    }
    $console->image( $image );
}

# ------------------
sub _get_mediatype_as_array {
# ------------------
    my $obj = shift || return error('No object defined!');

    return [
        [1,'DVD'],
        [2,'SVCD'],
        [3,'VCD'],
        [4,'CD-R'],
        [5,'CD-RW'],
        [6,'VHS'],
        [7,'DVD-R'],
        [8,'DVD-RW'],
        [9,'DVD+R'],
        [10,'DVD+RW'],
        [11,'DVD-DL'],
        [12,'DVD+DL'],
        [13,'Divx'],
        [14,'Xvid'],
        [50,gettext('wanted')],
        ];
}

# ------------------
sub _get_mediatype_as_hash {
# ------------------
    my $obj = shift || return error('No object defined!');

    my $types = $obj->_get_mediatype_as_array;

    my $erg;
    foreach my $set ( @$types ) {
        $erg->{$set->[1]} = {
            'id' => $set->[0],
            'name' => $set->[1],
                            };
    }
    return $erg;
}

# ------------------
sub _get_mediatype_namebyid {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $id = shift || return error ('No media type ID given!');

    my $types = $obj->_get_mediatype_as_array;

    foreach my $set ( @$types ) {
        return $set->[1] if $set->[0] == $id;
    }
    return 0;
}

# ------------------
sub _get_mediatype_idbyname {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $name = shift || return error ('No Mediatype Name given');

    my $types = $obj->_get_mediatype_as_array;

    foreach my $set ( @$types ) {
        return $set->[0] if $set->[1] == $name;
    }
    return '';
}

# ------------------
sub _get_videogenres_byvideoid {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $id = shift || 0;
    
    return [] unless $id;
    
    my $sql = qq|
SELECT SQL_CACHE 
    genre_id
FROM
    MEDIALIB_VIDEOGENRE
WHERE
    video_id = ?
|;
    my $sth = $obj->{dbh}->prepare($sql);
    $sth->execute($id)
        or return undef;
    my $erg = $sth->fetchall_arrayref();
    my $ret;
    map {
        push @$ret, $_->[0];
    } @$erg;
    return $ret;
}

# ------------------
sub _get_videogenres_as_hash_by_id {
# ------------------
    my $obj = shift || return error('No object defined!');
    
    my $genres = $obj->_get_videogenres_as_array;
  
    my $erg;
    foreach my $set ( @$genres ) {
        $erg->{$set->[0]} = {
            'id' => $set->[0],
            'name' => $set->[1],
                            };
    }
    return $erg;
}

# ------------------
sub _get_videogenres_as_hash_by_name {
# ------------------
    my $obj = shift || return error('No object defined!');
    
    my $genres = $obj->_get_videogenres_as_array;
  
    my $erg;
    foreach my $set ( @$genres ) {
        $erg->{$set->[1]} = {
            'id' => $set->[0],
            'name' => $set->[1],
                            };
    }
    return $erg;
}

# ------------------
sub _get_videogenres_as_hash {
# ------------------
    my $obj = shift || return error('No object defined!');

    return {
        gettext('Action') => {
            'id' => 1,
            'name' => 'Action',
                    },
        gettext('Adventure') => {
            'id' => 2,
            'name' => 'Adventure',
                    },
        gettext('Animation') => {
            'id' => 3,
            'name' => 'Animation',
                    },
        gettext('Comedy') => {
            'id' => 4,
            'name' => 'Comedy',
                    },
        gettext('Crime') => {
            'id' => 5,
            'name' => 'Crime',
                    },
        gettext('Documentary') => {
            'id' => 6,
            'name' => 'Documentary',
                    },
        gettext('Drama') => {
            'id' => 7,
            'name' => 'Drama',
                    },
        gettext('Family') => {
            'id' => 8,
            'name' => 'Family',
                    },
        gettext('Fantasy') => {
            'id' => 9,
            'name' => 'Fantasy',
                    },
        gettext('Film-Noir') => {
            'id' => 10,
            'name' => 'Film-Noir',
                    },
        gettext('Horror') => {
            'id' => 11,
            'name' => 'Horror',
                    },
        gettext('Musical') => {
            'id' => 12,
            'name' => 'Musical',
                    },
        gettext('Mystery') => {
            'id' => 13,
            'name' => 'Mystery',
                    },
        gettext('Romance') => {
            'id' => 14,
            'name' => 'Romance',
                    },
        gettext('Sci-Fi') => {
            'id' => 15,
            'name' => 'Sci-Fi',
                    },
        gettext('Short') => {
            'id' => 16,
            'name' => 'Short',
                    },
        gettext('Thriller') => {
            'id' => 17,
            'name' => 'Thriller',
                    },
        gettext('War') => {
            'id' => 18,
            'name' => 'War',
                    },
        gettext('Western') => {
            'id' => 19,
            'name' => 'Western',
                    },
        gettext('Adult') => {
            'id' => 20,
            'name' => 'Adult',
                    },
        gettext('Music') => {
            'id' => 21,
            'name' => 'Music',
                    },
        gettext('Biography') => {
            'id' => 22,
            'name' => 'Biography',
                    },
        gettext('History') => {
            'id' => 23,
            'name' => 'History',
                    },
        gettext('Childs') => {
            'id' => 24,
            'name' => 'Childs',
                    },
        gettext('Splatter') => {
            'id' => 25,
            'name' => 'Splatter',
                    },
           };
    
}

# ------------------
sub _get_videogenres_as_array {
# ------------------
    my $obj = shift || return error('No object defined!');

    my $hashref = $obj->_get_videogenres_as_hash;
    
    my $ret = [];
    foreach my $key ( sort keys %$hashref ) {
        push @$ret, [ $hashref->{$key}->{id}, $key ];
    }
    return $ret;
}

# ------------------
sub _getsearchsfields_as_array {
# ------------------
    my $obj = shift || return error('No object defined!');

    return [
        [ 'title', gettext('Title') ],
        [ 'subtitle', gettext('Subtitle') ],
        [ 'director', gettext('Director') ],
        [ 'actors', gettext('Actors') ],
        [ 'plot', gettext('Plot') ],
        [ 'year', gettext('Year') ],
        [ 'country', gettext('Country') ],
        [ 'diskid', gettext('DiskID') ],
        [ 'mediatype', gettext('Mediatype') ],
        [ 'language', gettext('Language') ],
        [ 'comment', gettext('Comment') ],
           ];
}

# ------------------
sub _get_ranges_as_array {
# ------------------
    my $obj = shift || return error('No object defined!');

    return [
            [ 'NUM', gettext('#') ],
            [ 'ABC', gettext('ABC') ],
            [ 'DEF', gettext('DEF') ],
            [ 'GHI', gettext('GHI') ],
            [ 'JKL', gettext('JKL') ],
            [ 'MNO', gettext('MNO') ],
            [ 'PQRS', gettext('PQRS') ],
            [ 'TUV', gettext('TUV') ],
            [ 'WXYZ', gettext('WXYZ') ],
            [ 'ALL', gettext('All') ],
            [ 'SEEN', gettext('Seen') ],
            [ 'UNSEEN', gettext('Unseen') ],
            [ 'WANTED', gettext('Wanted') ]
          ];
}


1;

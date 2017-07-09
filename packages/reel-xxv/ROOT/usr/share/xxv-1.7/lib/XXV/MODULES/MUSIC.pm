package XXV::MODULES::MUSIC;
use strict;

use Tools;
use File::Basename;
use File::Path;
use File::Find;

$SIG{CHLD} = 'IGNORE';

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'MUSIC',
        Prereq => {
#            'DBI'          => 'Database independent interface for Perl ',
#            'DBD::mysql'   => 'MySQL driver for the Perl5 Database Interface (DBI)',
            'MP3::Icecast' => 'Generate Icecast streams, as well as M3U and PLSv2 playlists',
            'MP3::Info'    => 'Manipulate / fetch info from MP3 audio files ',
            'CGI'          => 'Simple Common Gateway Interface Class',
            'LWP::Simple'  => 'get, head, getprint, getstore, mirror - Procedural LWP interface',
            'Net::Amazon'  => 'Framework for accessing amazon.com via SOAP and XML/HTTP',
            'Net::Amazon::Request::Artist' => 'Class for submitting Artist requests',
        },
        Description => gettext('This module managed music files.'),
        Status => sub{ $self->status(@_) },
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            path => {
                description => gettext('Directory with the music files'),
                default     => '/music',
                type        => 'dir',
                required    => gettext('This is required!'),
            },
            port => {
                description => gettext('Port to listen for icecast clients.'),
                default     => 8100,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            Interface => {
                description => gettext('Local interface to bind service'),
                default     => '0.0.0.0',
                type        => 'host',
                required    => gettext('This is required!'),
            },
            proxy => {
                description => gettext('Proxy URL to music server. e.g. (http://vdr/xxv) Please remember you must write the port to icecast server in your proxy configuration!'),
                default     => '',
                type        => 'string',
            },
            clients => {
                description => gettext('Maximum clients to connect at the same time'),
                default     => 5,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            coverimages => {
                description => gettext('Common directory for cover images'),
                default     => '/var/cache/xxv/cover',
                type        => 'dir',
                required    => gettext('This is required!'),
            },
            muggle => {
                description => gettext('DSN for muggle database'),
                default     => 'DBI:mysql:database=GiantDisc;host=localhost;port=3306',
                type        => 'string',
                check       => sub{
                    my $value = shift;
                    if($value ne $self->{muggle}) {
                      $self->{mdbh}->disconnect() if($self->{mdbh});
                      $self->{mdbh} = &connectDB(
                        $value,
                        main::getGeneralConfig->{USR},
                        main::getGeneralConfig->{PWD},
                        $self->{charset}
                        );
                    }
                    return $value;
                },
            },
            mugglei => {
                description => sprintf(gettext("Path of command '%s'"),'mugglei'),
                default     => 'mugglei',
                type        => 'file',
            },
            AmazonToken => {
                description => gettext('Access Key ID to gathering cover images (a 20-character, alphanumeric sequence). Please sign up at http://aws.amazon.com'),
                default     => '',
                type        => 'string',
            },
            AmazonSecretKey => {
                description => gettext('Secret Access Key to gathering cover images (a 40-character sequence). Please sign up at http://aws.amazon.com'),
                default     => '',
                type        => 'string',
            },
        },
        Commands => {
            mrefresh => {
                description => gettext('Rereading of the music directory.'),
                short       => 'mr',
                callback    => sub{ $self->refresh(@_) },
                Level       => 'admin',
                DenyClass   => 'mlist',
            },
            mcovers => {
                description => gettext('Download album covers.'),
                short       => 'mc',
                callback    => sub{ $self->getcovers(@_) },
                Level       => 'admin',
                DenyClass   => 'mlist',
            },
            mplay => {
                description => gettext("Play music file 'fid'"),
                short       => 'mp',
                callback    => sub{ $self->play(@_) },
                DenyClass   => 'stream',
            },
            mplaylist => {
                description => gettext("Get a m3u playlist for 'fid'"),
                short       => 'm3',
                callback    => sub{ $self->playlist(@_) },
                DenyClass   => 'stream',
                binary      => 'nocache'
            },
            mlist => {
                description => gettext("Shows music 'dir'"),
                short       => 'ml',
                callback    => sub{ $self->list(@_) },
                DenyClass   => 'mlist',
            },
            msearch => {
                description => gettext("Search music 'txt'"),
                short       => 'ms',
                callback    => sub{ $self->search(@_) },
                DenyClass   => 'mlist',
            },
            mcoverimage => {
                description => gettext('Show album covers.'),
                short       => 'mi',
                callback    => sub{ $self->coverimage(@_) },
                DenyClass   => 'mlist',
                binary      => 'cache'
            },
            mgetfile => {
                description => gettext("Get music file 'fid'"),
                short       => 'mg',
                callback    => sub{ $self->getfile(@_) },
                DenyClass   => 'mlist',
                binary      => 'cache'
            },
            msuggest => {
                hidden      => 'yes',
                callback    => sub{ $self->suggest(@_) },
                DenyClass   => 'mlist',
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
    my $self = shift || return error('No object defined!');

    return 1
      if($self->{active} eq 'n');

    #create an instance to find all files below /usr/local/mp3
    $self->{ICE} = MP3::Icecast->new();
#   $self->{ICE}->recursive(1);

#   Use "file::find" & "add_file" instead of use "add_directory" 
#   avoid dead of modul via link-loops like cd /mp3; ln -s foo ../mp3
#   $self->{ICE}->add_directory($self->{path});
    find( {
      wanted => sub{
          if($File::Find::name =~ /\.mp3$/sig) {  # Lookup for *.mp3
            if(-r $File::Find::name) {
              $self->{ICE}->add_file($File::Find::name)
            } else {
              lg "Permissions deny, couldn't read : $File::Find::name";
            }
          }
        },
        follow => 1,
        follow_skip => 2
        },
      $self->{path}
    );

    $self->{SOCK} = IO::Socket::INET->new(
        LocalPort => $self->{port}, #standard Icecast port
        LocalAddr => $self->{Interface},
        Listen    => $self->{clients},
        Proto     => 'tcp',
        Reuse     => 1,
        Timeout   => 3600
    ) or return error("Couldn't create socket: $!");;

    my $channels;

    Event->io(
        fd => $self->{SOCK},
        prio => -1,  # -1 very hard ... 6 very low
        cb => sub {
            # accept client
            my $client = $self->{SOCK}->accept;
            panic "Couldn't connect to new icecast client." and return unless $client;
            $client->autoflush;

            # make "channel" number
            my $channel=++$channels;

            # install a communicator
            Event->io(
                fd => $client,
                prio => -1,  # -1 very hard ... 6 very low
                poll => 'r',
                cb => sub {
                    my $watcher = shift;
                    # report
                    lg(sprintf("Talking on icecast channel %d", $channel));

                    # read new line and report it
                    my $handle=$watcher->w->fd;
                    my $data = $self->parseRequest($handle);
                    my $files = $self->handleInput($data);
                    unless(ref $files eq 'ARRAY') {
                        $watcher->w->cancel;
                        $client->close();
                        undef $watcher;
                        return 1;
                    }

                    $self->stream($files, $client);

                    $watcher->w->cancel;
                    undef $watcher;
                    $client->close;
                },
            );

            # report
            lg(sprintf("Open new icecast channel %d", $channel));
        },
    );

    main::after(sub{

    $self->{mdbh} = &connectDB(
        $self->{muggle},
        main::getGeneralConfig->{USR},
        main::getGeneralConfig->{PWD},
        $self->{charset}
        );
    unless($self->{mdbh}) {
        unless($self->{dbh}) {
          panic("Session to database is'nt connected");
          return 0;
        }
        debug("Database 'GiantDisc' not found! Fallback to own internal music table!");

        my $version = 26; # Must be increment if rows of table changed
        # this tables hasen't handmade user data,
        # therefore old table could dropped if updated rows
        if(!tableUpdated($self->{dbh},'MUSIC',$version,1)) {
          return 0;
        }

        $self->{dbh}->do(qq|
          CREATE TABLE IF NOT EXISTS MUSIC (
              Id int(11) unsigned auto_increment NOT NULL,
              FILE text NOT NULL,
              ARTIST varchar(128) default 'unknown',
              ALBUM varchar(128) default 'unknown',
              TITLE varchar(128) default 'unknown',
              COMMENT varchar(128),
              TRACKNUM varchar(10) default '0',
              YEAR smallint(4) unsigned,
              GENRE varchar(128),
              BITRATE smallint(4) unsigned,
              FREQUENCY varchar(4),
              SECS int (11) NOT NULL,
              PRIMARY KEY  (ID)
            ) COMMENT = '$version'
        |);

        $self->{fields} = fields($self->{dbh}, 'SELECT SQL_CACHE * from MUSIC');

        # Read File to Database, if the DB empty and Musicdir exists
        $self->refresh()
            unless($self->{dbh}->selectrow_arrayref("SELECT SQL_CACHE count(*) from MUSIC")->[0]);
    }
        return 1;
    }, "MUSIC: Connect to database ...");

    1;

}

# ------------------
sub refresh {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    if( ref $console and not -d $self->{path} ) {
        my $errmsg = sprintf(gettext("Directory of the music files '%s' not found"), $self->{path});
        error($errmsg);
        $console->err($errmsg);
        $console->link({
            text => gettext("Back to music list"),
            url => "?cmd=mlist",
        }) if($console->typ eq 'HTML');
        return;
    }

    if($self->{mugglei} and $self->{mdbh}) {
        my $usr = main::getGeneralConfig->{USR};
        my $pwd = main::getGeneralConfig->{PWD};
        my $host = (split(/ /, $dbh->{'mysql_hostinfo'}))[0];
        # /usr/local/bin/mugglei -h 127.0.0.1 -c -u xpix -w xpix97 -t /NAS/Music .
        my $command = sprintf('%s -h %s -z -c -u %s -w %s -t %s . 2>&1',
            $self->{mugglei}, lc($host), $usr, $pwd, $self->{path});
        lg sprintf("Execute: cd '%s';%s",$self->{path},$command);
        chdir($self->{path});
        my @erg = (`$command`);

        if( ref $console) {
            $console->message(gettext("Reread the music files ..."));
            $console->link({
                text => gettext("Back to music list"),
                url => "?cmd=mlist",
            }) if($console->typ eq 'HTML');
        }
        undef $self->{GENRES}; # delete genres cache

        return 1;
    }

    my $waiter;
    # Show waiter, early as is possible
    if(ref $console && $console->typ eq 'HTML') {
        $waiter = $console->wait(gettext("Get information from music files ..."), 0, 1000, 'no');
    }

    lg('Please wait! I search for new Musicfiles!');

    #create an instance to find all files below /usr/local/mp3
    $self->{ICE} = MP3::Icecast->new();
    $self->{ICE}->recursive(1);
    $self->{ICE}->add_directory($self->{path});

    $self->{CACHE} = {};

    my $data = $dbh->selectall_hashref("SELECT SQL_CACHE ID, FILE from MUSIC", 'FILE');
    my @files = $self->{ICE}->files;

    lg sprintf('Found %d music files !', scalar @files);

    return unless(scalar @files);

    if( ref $console and not scalar @files ) {

        # last call of waiter
        $waiter->end() if(ref $waiter);

        $console->start() if(ref $waiter);

        $console->err(gettext("No music files found!"));
        $console->link({
            text => gettext("Back to music list"),
            url => "?cmd=mlist",
        }) if($console->typ eq 'HTML');

        return;
    }

    # Adjust waiter max value now.
    $waiter->max(scalar @files)
        if(ref $waiter);

    my $c = 0;
    my $new = 0;
    foreach my $file (@files) {
        ++$c;
        $waiter->next($c)
            if(ref $waiter);
        next if(delete $data->{$file});
        my $info = MP3::Info->new($file);
        $new++
            if($self->insert($info));
    }

    foreach my $f (sort keys %$data) {
        unless(-e $f) {
            $dbh->do(sprintf('DELETE FROM MUSIC WHERE ID = %lu', $data->{$f}->{ID}));
        }
    }

    # last call of waiter
    $waiter->end() if(ref $waiter);

    if(ref $console) {
        $console->start()
            if(ref $waiter);
        my $msg = sprintf(gettext("%d new music files in database saved and %d non exists entries deleted!"), $new, scalar keys %$data);
        $console->message($msg);
        lg $msg;
        $console->link({
            text => gettext("Back to music list"),
            url => "?cmd=mlist",
        }) if($console->typ eq 'HTML');
    }
}

# ------------------
sub play {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || return error('No data defined!');

    debug sprintf('Call play%s',
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    $console->player("?cmd=mplaylist&data=${data}");
}

# ------------------
sub playlist {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || return error('No data defined!');

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    my $host = main::getModule('STREAM')->{host} || main::getModule('STATUS')->IP;
    my $output;

    foreach my $id (split('_', $data)) {
        my $data;
        if($self->{mdbh}) {
            $data = $dbh->selectrow_hashref("SELECT SQL_CACHE * from tracks where id = '$id'");
        } else {
            $data = $dbh->selectrow_hashref("SELECT SQL_CACHE * from MUSIC where ID = '$id'");
        }
        next unless($data);
  
        $output .= "#EXTM3U\r\n" unless($output);

        my $file;
        my $proxy = $self->{proxy};
        $proxy =~ s/^\s+//;               # no leading white space
        $proxy =~ s/\s+$//;               # no trailing white space
        if(length($proxy)) {
            $file = sprintf('%s/?cmd=play&data=%s&field=id', $proxy, $id);
        } else {
            $file = sprintf('http://%s:%lu/?cmd=play&data=%s&field=%s', $host, $self->{port}, $id, ($self->{mdbh} ? 'id' : 'ID'));
        }
        if($self->{mdbh}) {
            $output .= sprintf("#EXTINF:%d,%s - %s (%s)\r\n",$data->{'length'},$data->{title},$data->{artist},$data->{sourceid});
        } else {
            $output .= sprintf("#EXTINF:%d,%s - %s (%s)\r\n",$data->{SECS},$data->{TITLE},$data->{ARTIST},$data->{ALBUM});
        }
        $output .= sprintf("%s\r\n", $file);
    }

    if($output && $console->typ eq 'HTML') {
        $console->{nopack} = 1;

        my $arg;
        $arg->{'attachment'} = "playlist.m3u";
        $arg->{'Content-Length'} = length($output);

        $console->out($output, "audio/x-mpegurl", %{$arg} );
    } else {
      $console->err(gettext("Sorry, playback is'nt supported"));
    }
}

# ------------------
sub search {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text   = shift;

    unless($text) {
      error("No text to search defined! Please use msearch 'text'");
      return $self->list($console, $config);
    } else {
      return $self->list($console, $config, "search:".$text);
    }
}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $param  = shift;

    my $dbh = $self->{mdbh} ? $self->{mdbh} : $self->{dbh};
    unless($dbh) {
		 	error ("Couldn't connect to database");
		  return $console->err(gettext("Couldn't connect to database"));
		}

		unless($param) {
	    if($self->{mdbh}) {
        my $eg = $dbh->selectrow_arrayref('SELECT cddbid from album order by artist,title limit 1');
			  unless($eg) {
	         	error sprintf("Couldn't execute query: %s.",$dbh->errstr);
            return $console->err($dbh->errstr);
				}
        $param = sprintf('cddbid:%s', $eg->[0]);
	    } else {
        my $eg = $dbh->selectrow_arrayref('SELECT SQL_CACHE ALBUM from MUSIC order by ARTIST,TITLE limit 1');
			  unless($eg) {
	         	error sprintf("Couldn't execute query: %s.",$dbh->errstr);
            return $console->err($dbh->errstr);
				}
        $param = sprintf('album:%s', $eg->[0]);
			}
    }

    my @field = split(':',$param);
    my $typ = $field[0];

    shift @field;
    my $text = join(':',@field);

    my $search = '';
    my $term;
    if($typ eq 'search') {
        if($self->{mdbh}) {
            my $query = buildsearch("album.artist,tracks.artist,album.title,tracks.title,album.covertxt",$text);
            $search = $query->{query};
            foreach(@{$query->{term}}) { push(@{$term},$_); }
            foreach(@{$query->{term}}) { push(@{$term},$_); } #double for UNION
        } else {
            my $query = buildsearch("ALBUM,ARTIST,TITLE,COMMENT",$text);
            $search = $query->{query};
            foreach(@{$query->{term}}) { push(@{$term},$_); }
        }
    } else {
		  # assign xxv tables to giantdisc table name
		  my $translate = {
		      cddbid  => 'cddbid',
		      artist  => 'artist',
		      album   => 'title',
		      genre   => 'genre1',
		      title   => 'title',
		      year    => 'year'
		  };

	    my $t;
		  if($typ eq 'all') {

		  } elsif($typ eq 'genre') {
		      $t = ($self->{mdbh} ? 'tracks.'.$translate->{$typ} : uc($typ));

					# caching genres
					$self->{GENRES} = $dbh->selectall_hashref('SELECT * from genre', 'id')
						  if($self->{mdbh} && !$self->{GENRES});

		      $text = $self->{GENRES}->{$text}->{id} if($self->{mdbh});
		  } elsif($typ eq 'year') {
		      $t = ($self->{mdbh} ? 'tracks.'.$translate->{$typ} : uc($typ));
		  } elsif($typ eq 'album') {
		      $t = ($self->{mdbh} ? 'album.'.$translate->{$typ} : uc($typ));
		  } elsif($typ eq 'cddbid') {
		      $t = ($self->{mdbh} ? 'album.'.$translate->{$typ} : uc($typ));
		  } else {
		      $t = ($self->{mdbh} ? 'tracks.'.$translate->{$typ} : uc($typ));
		  }

			if($typ eq 'all') {
        $search = '1';
			} elsif($typ eq 'genre' && $self->{mdbh}) {
        $search = sprintf("%s LIKE ?", $t);  #?%
        push(@{$term},$text.'%');
	    } else {
        $search = sprintf("%s RLIKE ?", $t); #%?%
        push(@{$term},$text);
        push(@{$term},$text) if($self->{mdbh});
	    }
		}

    my %f = (
        'Id' => gettext('Service'),
        'Artist' => gettext('Artist'),
        'Album' => gettext('Album'),
        'Title' => gettext('Title'),
        'Tracknum' => gettext('Number of track'),
        'Year' => gettext('Year'),
        'Length' => gettext('Length')
    );

    my $sql;
    if($self->{mdbh}) {

        $sql = qq|
        SELECT 
        	tracks.id as \'$f{'Id'}\',
        	tracks.artist as \'$f{'Artist'}\',
        	album.title as \'$f{'Album'}\',
        	tracks.title as \'$f{'Title'}\',
        	tracks.tracknb as \'$f{'Tracknum'}\',
        	tracks.year as \'$f{'Year'}\',
          IF(tracks.length >= 3600,SEC_TO_TIME(tracks.length),DATE_FORMAT(FROM_UNIXTIME(tracks.length), '%i:%s')) as \'$f{'Length'}\',
          genre.genre as __GENRE,
        	album.covertxt as __COMMENT
        FROM
        	tracks, album, genre
        WHERE
            tracks.sourceid = album.cddbid and
            tracks.genre1 = genre.id and
        	  $search
        |;

        $sql .= qq|

     UNION
        SELECT 
        	tracks.id as \'$f{'Id'}\',
        	tracks.artist as \'$f{'Artist'}\',
        	album.title as \'$f{'Album'}\',
        	tracks.title as \'$f{'Title'}\',
        	tracks.tracknb as \'$f{'Tracknum'}\',
        	tracks.year as \'$f{'Year'}\',
          IF(tracks.length >= 3600,SEC_TO_TIME(tracks.length),DATE_FORMAT(FROM_UNIXTIME(tracks.length), '%i:%s')) as \'$f{'Length'}\',
          "" as __GENRE,
        	album.covertxt as __COMMENT
        FROM
        	tracks, album
        WHERE
            tracks.sourceid = album.cddbid and
            tracks.genre1 = 'NULL' and
        	  $search

        | if($typ ne 'genre');


        $sql .= qq|
        ORDER BY
                \'$f{'Album'}\',
                \'$f{'Tracknum'}\'
        |;
    } else {

        $sql = qq|
        SELECT 
       	ID as \'$f{'Id'}\',
        	ARTIST as \'$f{'Artist'}\',
        	ALBUM as \'$f{'Album'}\',
        	TITLE as \'$f{'Title'}\',
        	TRACKNUM as \'$f{'Tracknum'}\',
        	YEAR as \'$f{'Year'}\',
            IF(SECS >= 3600,SEC_TO_TIME(SECS),DATE_FORMAT(FROM_UNIXTIME(SECS), '%i:%s')) as \'$f{'Length'}\',
        	GENRE as __GENRE,
        	COMMENT as __COMMENT
        FROM
        	MUSIC
        WHERE
          1 AND
        	$search
        ORDER BY
        	FILE
        |;
    }

		my $rows;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $dbh->prepare($sql);
         $rsth->execute(@{$term})
          or return error sprintf("Couldn't execute query: %s.",$rsth->errstr);
      $rows = $rsth->rows;
      if($rows <= $limit) {
        $sth = $rsth;
      } else {
        # Add limit query
        if($console->{cgi}->param('start')) {
          $sql .= " LIMIT " . CORE::int($console->{cgi}->param('start'));
          $sql .= "," . $limit;
        } else {
          $sql .= " LIMIT " . $limit;
        }
      }
    }

    unless($sth) {
      $sth = $dbh->prepare($sql);
      $sth->execute(@{$term})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    if($console->typ ne 'AJAX') {
	    unshift(@$erg, $fields);
		}

    my $info = {
      rows => $rows
    };
    if($console->typ eq 'HTML') {
	    $info->{albums} = ($self->{mdbh} ? $self->GroupArray('title', 'album', 'cddbid') : $self->GroupArray('ALBUM'));
			$info->{artists} = ($self->{mdbh} ? $self->GroupArray('artist', 'tracks', 'id'): $self->GroupArray('ARTIST'));
			$info->{genres} = $self->GenreArray();
			$info->{getCover} = sub{ return $self->_findcoverfromcache(@_, 'relative') };
	    $console->setCall('mlist');
		}
  	$console->table($erg, $info);
}

# ------------------
sub handleInput {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $data    = shift || return error('No request defined!');
    my $cgi = CGI->new( $data->{Query} );

    my $ucmd = $cgi->param('cmd')   || 'play';
    my $ufield = $cgi->param('field') || ($self->{mdbh} ? 'id' : 'ID');
    my $udata = $cgi->param('data') || '*';

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    return 0
      if(!$dbh);

    $dbh->{InactiveDestroy} = 1;
    my $ldbh = $dbh->clone();

    my $files;
    if($ucmd eq 'play' and $ufield and my @search = split(',',$udata)) {
        $files = $self->field2path($ldbh, $ufield, \@search);
    } else {
        return error "I don't understand this command '$ucmd'";
    }
    return $files;
}

# ------------------
sub field2path {
# ------------------
    my $self = shift || return error('No object defined!');
    my $dbh = shift || return error('No dbh defined!');
    my $field = shift || return error('No field defined!');
    my $data = shift || return error('No data defined!');
    my $pathfield;
    my $sql;

    map {$_ = $dbh->quote($_)} @$data;

    if($self->{mdbh}) {
      $pathfield = 'mp3file';
      $sql = sprintf "SELECT SQL_CACHE %s, %s from tracks", $pathfield, $field;
    } else {
      $pathfield = 'FILE';
      $sql = sprintf "SELECT SQL_CACHE %s, %s from MUSIC", $pathfield, $field;
    }
    $sql .= sprintf " where %s in (%s)", $field, join(',', @$data)
        if($data->[0] ne '*');

    my $ret = $dbh->selectall_hashref($sql, $pathfield);
    my @files = sort keys %$ret;
    return \@files;
}

# ------------------
sub insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $data = shift || return 0;

    my @setdata;
    foreach my $name (keys %$data) {
        next unless(grep($name eq $_, @{$self->{fields}}));
        push(@setdata, sprintf("%s=%s", $name, $self->{dbh}->quote($data->{$name})));
    }

    # MD5(File) as ID
    my $sql = sprintf('INSERT INTO MUSIC SET %s', join(', ', @setdata));
    $self->{dbh}->do( $sql );
    return 1;
}

# ------------------
sub stream {
# ------------------
    my $self = shift || return error('No object defined!');
    my $files = shift || return error('No file defined!');
    my $client = shift || return error('No client defined!');

    my %seen = ();
    my @uniqu = grep { ! $seen{$_} ++ } @$files;

    defined(my $child = fork()) or die "Couldn't fork: $!";
    if($child == 0) {
        $self->{SOCK}->close;
        $self->{dbh}->{InactiveDestroy} = 1;
        if($self->{mdbh}) {
          $self->{mdbh}->{InactiveDestroy} = 1;
        }

        foreach my $file (@uniqu) {

            $file = $self->{path} . "/" . $file
                if($self->{mdbh});

            debug sprintf('Stream file "%s"',$file);
            my $erg = $self->{ICE}->stream($file,0,$client)
                || last;
        }
        exit 0;
    }
}

# ------------------
sub parseRequest {
# ------------------
    my $self = shift || return error('No object defined!');
    my $hdl = shift || return error('No request defined!');

    my ($Req, $size) = getFromSocket($hdl);

	if(ref $Req eq 'ARRAY' and $Req->[0] =~ /^GET (\/[\w\.\/-\:]*)([\?[\w=&\.\+\%-\:\!]*]*)[\#\d ]+HTTP\/1.\d$/) {
        my $data = {};
		($data->{Request}, $data->{Query}) = ($1, $2 ? substr($2, 1, length($2)) : undef);

    	# parse header
    	foreach my $line (@$Req) {
    		if($line =~ /Referer: (.*)/) {
    			$data->{Referer} = $1;
    		}
    		if($line =~ /Host: (.*)/) {
    			$data->{HOST} = $1;
    		}
    		if($line =~ /Authorization: basic (.*)/i) {
    			($data->{username}, $data->{password}) = split(":", MIME::Base64::decode_base64($1), 2);
    		}
    		if($line =~ /User-Agent: (.*)/i) {
    			$data->{http_useragent} = $1;
    		}
    	}

    # Log like Apache Format ip, resolved hostname, user, method request, status, bytes, referer, useragent
    lg sprintf('%s - %s "%s %s%s" %s %s "%s" "%s"',
          getip($hdl),
          $data->{username} ? $data->{username} : "-",
          "GET", #$data->{Method},
          $data->{Request} ? $data->{Request} : "",
          $data->{Query} ? "?" . $data->{Query} : "",
          "-", #$console->{'header'},
          "-", #$console->{'sendbytes'},
          $data->{Referer} ? $data->{Referer} : "-",
          "-" #$data->{http_useragent} ? $data->{http_useragent} : ""
        );

    return $data;
	} else {
    error sprintf(" Unknown Request : %s", join("\n", @$Req));
    return undef;
	}
}

# ------------------
sub GroupArray {
# ------------------
    my $self = shift || return error('No object defined!');
    my $field = shift || return undef;
    my $table = shift;
    my $idfield = shift;
    my $search = shift;
    my $limitquery = shift;

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    my $where = '';
    $where = sprintf("WHERE %s LIKE '%%%%%s%%%%'",$field, $search)
        if($search);
    my $limit = '';
    $limit = sprintf("LIMIT %s",$limitquery)
        if($limitquery && $limitquery > 0);

    my $sql;
    if($self->{mdbh}) {
        $sql = sprintf('SELECT SQL_CACHE %s, %s from %s %s group by %s order by %s %s', $field, $idfield, $table, $where, $field, $field, $limit);
    } else {
        $sql = sprintf('SELECT SQL_CACHE %s, ID from MUSIC %s group by %s order by %s %s %s ', $field, $where, $field, $field, $limit);
    }
    my $erg = $dbh->selectall_arrayref($sql);

    return $erg;
}

# ------------------
sub GenreArray {
# ------------------
    my $self = shift || return error('No object defined!');

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    my $sql;
    if($self->{mdbh}) {
        $sql = "SELECT SQL_CACHE genre, genre.id as id from genre,tracks where genre.id = tracks.genre1 group by id order by id";
    } else {
        my $field = 'genre';
        $sql = sprintf('SELECT SQL_CACHE %s, %s from MUSIC group by %s order by %s', $field, $field, $field, $field);
    }
    my $erg = $dbh->selectall_arrayref($sql);

    return $erg;
}

# ------------------
sub status {
# ------------------
    my $self = shift || return error('No object defined!');
    my $lastReportTime = shift || 0;

    return
      if($self->{active} eq 'n');

    my $report = {};
    if($self->{mdbh}) {
        $report->{FILE} = $self->{mdbh}->selectrow_arrayref('SELECT SQL_CACHE count(*) from tracks')->[0];
        $report->{ALBUM} = $self->{mdbh}->selectrow_arrayref('SELECT SQL_CACHE count(*) from album')->[0];
        my $d = $self->{mdbh}->selectall_arrayref('SELECT SQL_CACHE artist from tracks group by artist');
        $report->{ARTIST} = scalar @$d;
        $d = $self->{mdbh}->selectall_arrayref('SELECT SQL_CACHE genre1 from tracks group by genre1');
        $report->{GENRE} = scalar @$d;
    } else {
        foreach my $field (qw/FILE ALBUM ARTIST GENRE/) {
            my $data = $self->GroupArray($field);
            $report->{$field} = scalar @$data;
        }
    }


    return {
        message => sprintf(gettext('Music database contains %d entries with %d albums from %d artists in %d genres'),
            $report->{FILE}, $report->{ALBUM},$report->{ARTIST}, $report->{GENRE}),
    };
}

# ------------------
sub _storecover {
# ------------------
    my $self = shift || return error('No object defined!');
    my $image = shift || return 0;
    my $target = shift;

    # Avoid empty hash
    if($image && ref $image eq 'HASH') {
      my $hash = $image;
      $image = undef;
      foreach my $i (keys %$hash) {
        $image = $hash->{$i};
        last;
      }
    }

    if($image) {
      lg sprintf("Try to get cover %s", $image);
      return 1 if(is_success(getstore($image, $target)));
    }
    return 0;
}

# ------------------
sub getcovers {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
    my $force = shift;

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    return $console->error(gettext('No Amazon Web Service (AWS) access key identifiers token exists. Please sign up at http://aws.amazon.com .'))
        unless($self->{AmazonToken} && $self->{AmazonSecretKey});

    $self->{Amazon} = Net::Amazon->new(
        token       => $self->{AmazonToken}
       ,secret_key  => $self->{AmazonSecretKey}
    ) unless($self->{Amazon});

    return error('No valid Amazon token exists. Please sign up at http://aws.amazon.com')
        unless($self->{Amazon});

    debug sprintf('Call getcovers%s',
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    my $waiter = $console->wait(gettext("Please wait, search for new covers ..."),0,1000,'no')
        if(ref $console);

    unless(-d $self->{coverimages}) {
        mkpath($self->{coverimages}) or error "Couldn't mkpath $self->{coverimages} : $!";
        lg sprintf('mkdir path "%s"',
                $self->{coverimages}
            );
    }

    my $rob = main::getModule('ROBOT')
        or return error('No ROBOT Module installed!');

    $rob->saveRobot('coverimage', sub{
        my $artist = shift || return 0, "Missing artist";
        my $album = shift || return 0, "Missing album";
        my $year = shift || 0;
        my $target = shift || return 0, "Missing target";
        my $current = shift || 0;

        my $msg = sprintf(gettext("Lookup for cover from '%s-%s'"), $artist,$album);
        lg $msg;
        # Anzeige der ProcessBar
        $waiter->next($current,undef, $msg) if(ref $waiter);
 
        my $req = Net::Amazon::Request::Artist->new(
            artist  => $artist,
        );
        my $resp = $self->{Amazon}->request($req);
        $album =~ s/[^[:alnum:]]//sig;
        $artist =~ s/[^[:alnum:]]//sig;

        my $image;
        foreach my $item ($resp->properties) {

          next unless($item->can('album'));
          my $ialbum = $item->album();
             $ialbum =~ s/[^[:alnum:]]//sig;

          next unless($item->can('artist'));
          my $iartist = $item->artist();
             $iartist =~ s/[^[:alnum:]]//sig;

          if($ialbum =~ /$album/i
              and $iartist =~ /$artist/i) {

              $image = $item->ImageUrlMedium()
                if($item->can('ImageUrlMedium'));
              last if($image && $self->_storecover($image,$target));

              $image = $item->ImageUrlLarge()
                if($item->can('ImageUrlLarge'));
              last if($image && $self->_storecover($image,$target));

              $image = $item->ImageUrlSmall()
                if($item->can('ImageUrlSmall'));
              last if($image && $self->_storecover($image,$target));
          }
        }

        return 1;
    });

    my $erg;
    if($self->{mdbh}) {
        $erg = $dbh->selectall_hashref('SELECT SQL_CACHE DISTINCT t.id as ID,t.mp3file as FILE, a.artist as ARTIST, a.title as ALBUM, t.year as YEAR from album as a, tracks as t where a.cddbid = t.sourceid group by a.title', 'ID');
    } else {
        $erg = $dbh->selectall_hashref('SELECT SQL_CACHE DISTINCT Id as ID, FILE, ARTIST, ALBUM, YEAR from MUSIC group by ALBUM', 'ID');
    }

    my $current = 0;
    foreach my $id (sort keys %$erg) {
        my $e = $erg->{$id};

        my $file = sprintf('%s/%s', $self->{path}, $e->{FILE});
        my $target = $self->_findcover($file,$e->{ARTIST},$e->{ALBUM});

        next if($target and -e $target and not $force);

        my $dest = $self->_findcoverfromcache($e->{ALBUM},$e->{ARTIST});
        $rob->register('coverimage', $e->{ARTIST}, $e->{ALBUM}, $e->{YEAR}, $dest, ++$current);
    }

    # Adjust waiter max value now.
    $waiter->max($current || 1)
        if(ref $waiter);

    if(ref $waiter and $current) {
        $waiter->endcallback(
            sub{
                if(ref $console) {
                    $console->start();
                    $console->message(my $msg = gettext("New covers search was successfully!"));
                    lg sprintf($msg);

                    $console->link({
                        text => gettext("Back to music list"),
                        url => "?cmd=mlist",
                    }) if($console->typ eq 'HTML');
                    $console->footer();
                }
            }
        );
    }

    if(ref $waiter and not $current) {
        $waiter->endcallback(
            sub{
                if(ref $console) {
                    $console->start();
                    $console->message(gettext("It is not necessary to look for new covers because already all albums possess cover!"));

                    $console->link({
                        text => gettext("Back to music list"),
                        url => "?cmd=mlist",
                    }) if($console->typ eq 'HTML');
                    $console->footer();
                }
            }
        );
        lg sprintf('All covers exists!');
    }

    # Start Robots
    $rob->start( 'coverimage', sub{ $waiter->end if(ref $waiter and $current); } );

    return $erg;
}

# ------------------
sub _findcoverfromcache {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $album = shift || return error('No album defined!');
    my $artist = shift || 0;
    my $typ = shift || 'absolute';

    my $absolute;
    my $relative;

    if($artist) {
        $absolute = sprintf('%s/%s-%s.jpg', $self->{coverimages}, $self->unique($artist), $self->unique($album));
        $relative = sprintf('/coverimages/%s-%s.jpg', $self->unique($artist), $self->unique($album));
    } else {
        $absolute = sprintf('%s/%s.jpg', $self->{coverimages}, $self->unique($album));
        $relative = sprintf('/coverimages/%s.jpg', $self->unique($album));
    }
    return $absolute
        if($typ eq 'absolute');
    return $relative
        if(-r $absolute);

    lg sprintf("Don't find cover for %s - %s, as file %s",$artist,$album,$absolute);
    return undef;
}

# ------------------
sub unique {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $text = shift || return '';

    $text =~ s/[^0-9a-z]//sig;
    return $text;
}

# ------------------
sub _findcover {
# ------------------
    my $self = shift || return error('No object defined!');
    my $file = shift || return error('No file defined!');
    my $artist = shift;
    my $album = shift;

    my $coverimage;
    my $directory = dirname($file);

    if($self->{coverimages} && -d $self->{coverimages}) {
      my $cache = $self->_findcoverfromcache($album,$artist);
      $coverimage = $cache
        if($cache && -r $cache);
    }

    if(!$coverimage && -d $directory) {

      my @images = [];
      find(
              {
                  wanted => sub{
                    if($File::Find::name =~ /\.jpg$|\.jpeg$|\.gif$|\.png/sig) {  # Lookup for images
                      if(-r $File::Find::name) {
                          push(@images,$File::Find::name)
                      } else {
                          lg "Permissions deny, couldn't read : $File::Find::name";
                      }
                    }
                  },
                  follow => 1,
                  follow_skip => 2
              },
          $directory
      );

      #  An image in the same directory as the song, named like the song but with the
      #  song extension replaced with the image format extension
      #  e.g. test.mp3 -> test.jpg
      my $song = basename($file);
      $song =~ s/([\)\(\-\?\+\*\[\]\{\}])/\\$1/g; # Replace regex groupsymbols "),(,-,?,+,*,[,],{,}"
      $song =~ s/([\/])/\./g; # Replace splash
      $song =~ s/(.*)\.mp3$/$1./ig;
      my @f = grep { /$song/i } @images;
      $coverimage = $f[0]
        if(scalar @f > 0 && -r $f[0]);

      if(!$coverimage && $artist) {
        $artist =~ s/([\)\(\-\?\+\*\[\]\{\}])/\\$1/g; # Replace regex groupsymbols "),(,-,?,+,*,[,],{,}"
        $artist =~ s/([\/])/\./g; # Replace splash
        @f = grep { /\/$artist\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }

      if(!$coverimage && $album) {
        $album =~ s/([\)\(\-\?\+\*\[\]\{\}])/\\$1/g; # Replace regex groupsymbols "),(,-,?,+,*,[,],{,}"
        $album =~ s/([\/])/\./g; # Replace splash
        @f = grep { /\/$album\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }

      #  An image named "cover" with the image format extension in the same directory
      #  as the song (album cover).
      #  e.g. cover.gif
      if(!$coverimage) {
        @f = grep { /\/cover\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }

      #  An image named "artist" with the image format extension in the parent
      #  directory of the song (artist image).
      #  e.g. artist.png
      if(!$coverimage) {
        @f = grep { /\/artist\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }
      #  An image named "album" with the image format extension in the parent
      #  directory of the song (album image).
      #  e.g. album.png
      if(!$coverimage) {
        @f = grep { /\/album\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }

      #  An image named "background" with the image format extension in the base
      #  directory of the MP3 source.
      if(!$coverimage) {
        @f = grep { /\/background\./i } @images;
        $coverimage = $f[0]
          if(scalar @f > 0 && -r $f[0]);
      }
    }
  return $coverimage;
}

# ------------------
sub coverimage {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || return error('No data defined!');

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    if($dbh) {
      my $sql;
      my @id = split('_',$data);
      
      my $coverimage;
      map {$_ = $dbh->quote($_)} @id;

      if($self->{mdbh}) {
        $sql = sprintf qq|
                SELECT SQL_CACHE id, mp3file as file, 
                        tracks.artist as artist, 
                        album.title as album 
                from tracks, album 
                where tracks.sourceid = album.cddbid 
                              and id in (%s)|, join(',', @id);
      } else {
        $sql = sprintf qq|
                SELECT SQL_CACHE ID as id,
                        FILE as file, 
                        ARTIST as artist,
                        ALBUM as album 
                from MUSIC 
                where id in (%s)|, join(',', @id);
      }

      my $ret = $dbh->selectrow_hashref($sql);

      if($ret && $ret->{'id'})
      {
        my $file = sprintf('%s/%s', $self->{path}, $ret->{'file'});

        $coverimage = $self->_findcover($file,$ret->{'artist'},$ret->{'album'});
      }

      if($console->typ eq 'HTML') {
        if($coverimage) {
          $console->datei($coverimage);
        } else {
          my $HTTPD  = main::getModule('HTTPD');
          my $nocover = sprintf('%s/%s/images/nocover', $HTTPD->{paths}->{HTMLDIR}, $HTTPD->{HtmlRoot});
          if(-r $nocover . ".png") {
            $console->datei($nocover . ".png");
          } 
          elsif(-r $nocover . ".gif") {
            $console->datei($nocover . ".gif");
          } else {
            $nocover = sprintf('%s/default/images/nocover', $HTTPD->{paths}->{HTMLDIR});
            if(-r $nocover . ".png") {
              $console->datei($nocover . ".png");
            } else {
              $console->datei($nocover . ".gif");
            }
          }
      }
    }
    return 1;
  }
  $console->err(gettext("Sorry, images for cover is'nt supported"));
  return 0;
}

# ------------------
sub getfile {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || return error('No data defined!');

    my $dbh = ($self->{mdbh} ? $self->{mdbh} : $self->{dbh});

    if($dbh) {
      my $sql;
      my @id = split('_',$data);
      
      map {$_ = $dbh->quote($_)} @id;

      if($self->{mdbh}) {
        $sql = sprintf qq|
                SELECT SQL_CACHE id, mp3file as file from tracks
                where id in (%s)|, join(',', @id);
      } else {
        $sql = sprintf qq|
                SELECT SQL_CACHE ID as id, FILE as file from MUSIC 
                where id in (%s)|, join(',', @id);
      }

      my $ret = $dbh->selectrow_hashref($sql);
      if($ret 
          && $ret->{'id'} 
          && $ret->{'file'}
          && $console->typ eq 'HTML') {
            $console->datei(sprintf('%s/%s', $self->{path}, $ret->{'file'}));
            return 1;
        }
    }
    $console->err(gettext("Sorry, couldn't get file."));
    return 0;
}

# ------------------
sub suggest {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $search = shift;
    my $params  = shift;

    if(exists $params->{get}) {
        my $result;
        $result = ($self->{mdbh} ? $self->GroupArray('title', 'album', 'cddbid',$search, 25) : $self->GroupArray('ALBUM',undef,undef,$search, 25))
            if($params->{get} eq 'album');

        $result = ($self->{mdbh} ? $self->GroupArray('artist', 'tracks', 'id',$search, 25): $self->GroupArray('ARTIST',undef,undef,$search, 25))
            if($params->{get} eq 'artist');

        $result = ($self->{mdbh} ? $self->GroupArray('title', 'tracks', 'id',$search, 25): $self->GroupArray('TITLE',undef,undef,$search, 25))
            if($params->{get} eq 'title');

        $console->table($result)
            if(ref $console && $result);
    }

}


1;

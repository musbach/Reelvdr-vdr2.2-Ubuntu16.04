package XXV::OUTPUT::NEWS::RSS;
use strict;

use Tools;
use POSIX qw(locale_h);

# News Modules have only this methods
# init - for intervall or others
# send - send the informations
# push - push the news and parse it
# req  - read the actual news print this out

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'NEWS::RSS',
        Prereq => {
            'XML::RSS' => 'SMTP Protocol module to connect and send emails',
        },
        Description => gettext('This NEWS module generates an RSS news feed for your RSS reader.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = shift;
                    my $erg = $self->init
                        or return undef, gettext("Can't initialize news module!")
                            if($value eq 'y' and not exists $self->{INITE});
                    if($value eq 'y') {
                      my $emod = main::getModule('EVENTS');
                      if(!$emod or $emod->{active} ne 'y') {
                        return undef, sprintf(gettext("Module can't activated! This module depends module %s."),'EVENTS');
                      }
                    }
                    return $value;
                },
            },
            level => {
                description => gettext('Category of messages that should displayed'),
                default     => 1,
                type        => 'list',
                choices     => sub {
                                    my $emod = main::getModule('EVENTS');
                                    return undef unless($emod);
                                    my $erg = $emod->get_level_as_array();
                                    map { my $x = $_->[1]; $_->[1] = $_->[0]; $_->[0] = $x; } @$erg;
                                    return @$erg;
                                 },
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = int(shift) || 0;
                    my $emod = main::getModule('EVENTS');
                    return undef unless($emod);
                    my $erg = $emod->get_level_as_array();
                    unless($value >= $erg->[0]->[0] and $value <= $erg->[-1]->[0]) {
                        return undef, 
                               sprintf(gettext('Sorry, but value must be between %d and %d'),
                                  $erg->[0]->[0],$erg->[-1]->[0]);
                    }
                    return $value;
                },
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

    $self->{charset} = delete $attr{'-charset'} || 'ISO-8859-1';
    if($self->{charset} eq 'UTF-8'){
      eval 'use utf8';
    }

    # read the DB Handle
    $self->{dbh} = delete $attr{'-dbh'};

    # paths
    $self->{paths} = delete $attr{'-paths'};

    # host
    $self->{host} = delete $attr{'-host'};

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

    $self->{TYP} = 'application/xhtml+xml';

    # Initiat after load modules ...
    main::after(sub{
        # The Initprocess
        my $erg = $self->init
            or return error("Can't initialize news module!");
    }, "NEWS::RSS: Start initiate rss feed ...")
        if($self->{active} eq 'y');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift || return error('No object defined!');
    $self->{INITE} = 1;

    1;
}

# ------------------
sub createRSS {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $ver  = shift || 2;
    my $lastaddtime = shift;
    my $url = shift;

    my $account = sprintf("%s@%s", $ENV{USER}, $self->{host});

    my $rss;
    if($ver == 1) {
        $rss = XML::RSS->new(
            version => '1.0',
            'encoding' => $self->{charset},
            'encode_output' => 1
        ) || return error("Can't create rss 1.0 object");


        $rss->channel(
            title        => gettext("XXV RSS 1.0"),
            'link'       => $url,
            description  => gettext("Messages from your VDR/XXV"),
            dc => {
                date       => datum(time,'int'),
                subject    => gettext("XXV messages"),
                creator    => $account,
                language   => setlocale(POSIX::LC_MESSAGES),
            },
            syn => {
                updatePeriod     => "hourly",
                updateFrequency  => "1",
                updateBase       => datum(time, 'int'),
            },
        );

    } elsif($ver == 2) {

        $rss = XML::RSS->new(
            version => '2.0',
            'encoding' => $self->{charset},
            'encode_output' => 1
        ) || return error("Can't create rss 2.0 object");

        $rss->channel(
            title          => gettext("XXV RSS 2.0"),
            'link'         => $url,
            description    => gettext("Messages from your VDR/XXV"),
            language       => setlocale(POSIX::LC_MESSAGES),
            pubDate        => datum($lastaddtime, 'rss'),
            lastBuildDate  => datum(time, 'rss'),
            managingEditor => $account,
        );
    }

    return ($ver, $rss);
}


# ------------------
sub push {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vars = shift || return error('No data defined!');

    return;
}

# ------------------
sub req {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $params = shift || {};

    return gettext('The module NEWS::RSS is not active!')
        if($self->{active} ne 'y');

    my $sql = "SELECT SQL_CACHE id, title, message, cmd, data, level, UNIX_TIMESTAMP(addtime) from EVENTS where level >= ? order by addtime desc LIMIT 0,50"; 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($self->{level})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $data = $sth->fetchall_arrayref();

    my $lastaddtime = ($data && scalar @$data) ? $data->[0]->[6] : time;

    my $url = sprintf("http://%s:%s", $self->{host}, main::getModule('HTTPD')->{Port});
    my ($ver, $rss) = $self->createRSS($params->{version}, $lastaddtime, $url);
    return 0 unless($rss);

    my $emod = main::getModule('EVENTS');
    foreach my $entry (@{$data}) {
        my ($id, $title, $message, $cmd, $data, $level, $addtime) = @{$entry};

        my  $link = ''; 
            $link = sprintf("%s/?cmd=%s&data=%s", $url, $cmd, $data)
              if($cmd && $data);

        my $category = $emod->translate_scala($level);
        if($self->{charset} eq 'UTF-8') {
          utf8::decode( $title ) unless utf8::is_utf8( $title );
          utf8::decode( $message ) unless utf8::is_utf8( $message );
        }
        $message =~ s/\r\n/<br \/>/g; 

        if($ver == 1) {
          $rss->add_item(
              title       => $title,
              link        => $link,
              description => $message,
      	    	dc => {
      				  date    => datum($addtime, 'rss'),
       				  subject => $category,
              },
          );
        } else {
          $rss->add_item(
              title       => $title,
              link        => $link,
              description => $message,
              pubDate     => datum($addtime, 'rss'),
              category    => $category,
              guid        => $id,
          );
        }
    }

    return $rss->as_string;
}


1;

package XXV::MODULES::TELNET;

use strict;

use XXV::OUTPUT::Console;
use Tools;


# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'TELNET',
        Prereq => {
            'IO::Socket::INET'  => 'Object interface for AF_INET domain sockets ',
        },
        Description => gettext('This module is a multisession telnet server.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'n',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            Clients => {
                description => gettext('Maximum number of simultaneous connections'),
                default     => 5,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            Port => {
                description => gettext('Number of port to listen for telnet clients'),
                default     => 8081,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            Interface => {
                description => gettext('Local interface to bind service'),
                default     => '0.0.0.0',
                type        => 'host',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            bye => {
                description => gettext("This will exit the xxv system."),
                short       => 'x',
                callback    => sub{
                my ($console, $config) = @_;
        		    my $answer;
        		    my $questions = [
            		    'really' =>	{
                                    typ => 'confirm',
                                    msg => gettext("Are you sure to exit the xxv system?"),
                                    def => 'n'}
        		    ];
                    $answer = $console->question(gettext("This will exit the xxv system."),$questions,$answer);
                    if($answer->{really} eq 'y') {
                        lg "Closed session and exit.\n";
                        main::quit;
                    }
                },
        		Level   => 'admin'
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
    $self->init or return error('Problem to initialize modul!');

	return $self;
}


# ------------------
sub init {
# ------------------
    my $obj = shift || return error('No object defined!');

    # globals
    my $channels;

    my $prompt = "XXV> ";

    # make socket
	my $socket = IO::Socket::INET->new(
		Listen		=> $obj->{Clients},
		LocalPort	=> $obj->{Port},
    LocalAddr => $obj->{Interface},
		Reuse		=> 1
    ) or return error("Couldn't create socket: $!");

    # install an initial watcher
    Event->io(
        fd => $socket,
        prio => -1,  # -1 very hard ... 6 very low
        cb => sub {
                my $watch = shift;

                # make "channel" number
                my $channel=++$channels;

                # accept client
                my $client=$socket->accept;
                panic "Couldn't connect to new telnet client." and return unless $client;
                $client->autoflush;

                my $console = XXV::OUTPUT::Console->new(
                    -handle => $client,
                    -dbh    => $obj->{dbh},
                    -paths  => $obj->{paths},
                );

                # install a communicator
                Event->io(
                    fd => $client,
                    prio => -1,  # -1 very hard ... 6 very low
                    cb => sub {
                            my $watcher = shift;

                            # read new line and report it
                            my $handle=$watcher->w->fd;

                            my $line=<$handle>;
                            if(!$line or (defined $obj->{LOGOUT} && $obj->{LOGOUT} == 1 )) {
                                undef $obj->{LOGOUT};
                                $watcher->w->cancel;
                                $handle->close();
                                undef $watcher;
                                return 1;
                            }
                            $line =~ s/[\r|\n]//sig
                                if(defined $line);

                            $obj->handleInput($console, $line);
                            if(defined $obj->{LOGOUT} && $obj->{LOGOUT} == 1) {
                                undef $obj->{LOGOUT};
                                $watcher->w->cancel;
                                $handle->close();
                                undef $watcher;
                                return 1;
                            }
   
                            # Prompt
                            $client->print($prompt) if($client->opened);
                        },
                );

                # welcome
                $client->print(sprintf(gettext("Welcome to xxv system version: %s.\r\nThis is session %s.\r\n"),main::getVersion(),$channel));

                my $userMod = main::getModule('USER');
                unless(exists $console->{USER} or $userMod->{active} ne 'y') {
                    # Login
                    my $data;
                    if($userMod->_checkIp($client)) {
                        $console->message(gettext("Welcome to xxv system."));
                        $data->{Name} = 'no';
                        $data->{Password} = 'no';
                    } else {
                        $data = $console->login(gettext("Welcome to xxv system. Please Login:"));
                    }
                    my $user = $userMod->check($client, $data->{Name}, $data->{Password});
                    if(exists $user->{Name}) {
                        $console->{USER} = $user;
                    } else {
                        $console->err(gettext("Sorry, but permission denied!"));
                        $client->close;
                        return 1;
                    }
                }

                $client->print($prompt);

            },
    ) if($obj->{active} eq 'y');

    return 1;

}

# ------------------
sub handleInput {
# ------------------
    my $obj     = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $line    = shift || return;
    my $user    = shift || $console->{USER};

    my ($ucmd, $udata) = ($1, $2) if($line =~ /(\S+)\s*(.*)/sig);

    # Test the command on exists, permissions and so on
    my $u = main::getModule('USER');
    my ($cmdobj, $cmdname, $shorterr, $err) = $u->checkCommand($console, $ucmd);
    $console->{call} = $cmdname;
    if($cmdobj and not $shorterr) {
        $cmdobj->{callback}($console, $udata);
    } elsif($shorterr eq 'noperm' or $shorterr eq 'noactive') {
        return $console->err($err);
    } else {
        return $obj->usage($console, undef, $err);
    }
}

# ------------------
sub usage {
# ------------------
    my $obj = shift || return error('No object defined!');
    return main::getModule('CONFIG')->usage(@_);
}

1;

package XXV::OUTPUT::NEWS::JABBER;
use strict;

use Tools;

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
        Name => 'NEWS::JABBER',
        Prereq => {
            'Net::XMPP' => 'Jabber protocol for connect and send',
        },
        Description => gettext(qq|
This NEWS module generate a Jabber messages for your jabber client.
If come a Message from xxv with a lever >= as Preferences::level then
will this module send this Message to your jabber account
(Preferences::receiveUser).

The Problem xxv need a extra jabber account to allow to send messages in
the jabber network. This is very simple:

=over 4

=item 1 Start your jabber client, may the exodus (http://exodus.jabberstudio.org/)

=item 2 Create a new Profile with the name 'xxv'

=item 3 In the next window input following things:

    - Jabber Id: newsxxv\@jabber.org (in Example!)
    - Password:  lalala (in Example!)
    - save Password:  yes
    - new Account?:   yes

=back

Thats all!

If you want, you can test the connection to send a testmessage with
the following url in the Webinterface:

    http://vdr:8080/?cmd=request&data=jabber

or Telnet Interface:

    XXV> request jabber

Then you must receive a message in your running jabber client.

|),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'n',
                type        => 'confirm',
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = shift;
                    my $erg = $self->init
                        or return undef, gettext("Can't initialize news module!")
                            if($value eq 'y' and not exists $self->{JCON});
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
            receiveUser => {
                description => gettext('User to be notified (as Jabber account to@jabber.server.org)'),
                default     => '',
                type        => 'string',
                required    => gettext('This is required!'),
            },
            user => {
                description => gettext('Jabber account to send message (from@jabber.server.org)'),
                default     => '',
                type        => 'string',
                required    => gettext('This is required!'),
            },
            passwd => {
                description => gettext('Password for Jabber account'),
                default     => '',
                type        => 'password',
                required    => gettext('This is required!'),
                check       => sub{
                    my $value = shift || return;

                    return $value unless(ref $value eq 'ARRAY');

                    # If no password given the
                    # take the old password as default
                    if($value->[0] and $value->[0] ne $value->[1]) {
                        return undef, gettext("The fields with the 1st and the 2nd password must match!");
                    } else {
                        return $value->[0];
                    }
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

    $self->{TYP} = 'text/plain';

    # Initiat after load modules ...
    main::after(sub{
        # The Initprocess
        my $erg = $self->init
            or return error("Can't initialize news module!");
    }, "NEWS::JABBER: Start initiate news module ...")
        if($self->{active} eq 'y');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift || return error('No object defined!');

    1;
}

# ------------------
sub jconnect {
# ------------------
    my $self = shift  || return error('No object defined!');

    my $jcon = Net::XMPP::Client->new(
        debuglevel  =>  0,
    ) || return error("Can't create jabber client");

    my ($user, $server) = split('\@', $self->{user});

    debug sprintf("Connecting to jabber server: %s ...", $server);

    my @res = $jcon->Connect(
        hostname    =>  $server,
    );
    return
        unless($self->xmpp_check_result("Connect",\@res,$jcon));

    debug sprintf("Authentificat with User:%s ...", $user);

    @res = $jcon->AuthSend(
      'hostname'=>$server,
	  'username'=>$user,
	  'password'=>$self->{passwd},
	  'resource'=>'xxv'
    );

    return $jcon
        if($self->xmpp_check_result("Login",\@res,$jcon));
}

# ------------------
sub jdisconnect {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $cnx = shift  || 0;

    $cnx->Disconnect()
        if(ref $cnx);

    1;
}


# ------------------
sub send {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $vars    = shift || return error('No data defined!');

    return undef, lg('This function is deactivated!')
        if($self->{active} ne 'y');

    my $cnx     = $self->jconnect()
        || return error ('No connected JabberClient!' );

    $cnx->MessageSend(
        'to'     => $self->{receiveUser},
        'subject'=> $vars->{Title},
        'body'   => ($vars->{Text} || $vars->{Url}),
    );

    $cnx = $self->jdisconnect($cnx);

    1;
}

# ------------------
sub push {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vars = shift || return error('No data defined!');

    return $self->send($vars);

    1;
}

# ------------------
sub req {
# ------------------
    my $self = shift  || return error('No object defined!');

    return gettext('The module NEWS::JABBER is not active!')
        if($self->{active} ne 'y');

    my $vars = {
        AddDate => time,
        Title   => 'This is a testmessage for NEWS::JABBER ...',
        Text    => "abcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n0123456789\näüöÄÜÖ!@#$%^&*()_+=-':;<>?/\n",
        Level   => 100,
    };

    if($self->send($vars)) {
        return sprintf('Message is send to %s at %s', $self->{receiveUser}, datum($vars->{AddDate}));
    } else {
        return sprintf("Sorry, couldn't send message to %s at %s", $self->{receiveUser}, datum($vars->{AddDate}));
    }
}

# ------------------
sub xmpp_check_result {
# ------------------
    my $self = shift  || return error('No object defined!');
    my ($txt,$res,$cnx)=@_;

    return error("Error '$txt': result undefined")
	    unless($res);

    # result can be true or 'ok'
    if ((@$res == 1 && $$res[0]) || $$res[0] eq 'ok') {
	    return debug sprintf("%s: %s", $txt, $$res[0]);
    # otherwise, there is some error
    } else {
	    my $errmsg = $cnx->GetErrorCode() || '?';
        $cnx->Disconnect();
	    return error sprintf("Error %s: %s [%s]", $txt, join (': ',@$res), $errmsg);
    }
}

1;

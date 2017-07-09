package XXV::OUTPUT::NEWS::MAIL;
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
        Name => 'NEWS::MAIL',
        Prereq => {
            'Mail::SendEasy' => 'Simple platform independent mailer',
        },
        Description => gettext('This NEWS module generate mails for news.'),
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
                            if($value eq 'y' and not exists $self->{INITE});
                    return $value;
                    if($value eq 'y') {
                      my $emod = main::getModule('EVENTS');
                      if(!$emod or $emod->{active} ne 'y') {
                        return undef, sprintf(gettext("Module can't activated! This module depends module %s."),'EVENTS');
                      }
                    }
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
            interval => {
                description => gettext('Time in hours to send the next mail'),
                default     => 12,
                type        => 'integer',
                required    => gettext('This is required!'),
                check       => sub {
                    my $value = int(shift) || 0;
                    if($value and ref $self->{TIMER}) {
                        my $newinterval = $value*3600;
                        $self->{TIMER}->interval($newinterval);
                    }
                    return $value;
                },
            },
            address => {
                description => gettext('One or more mail addresses for sending the messages'),
                default     => 'unknown@example.com, everybody@example.com',
                type        => 'string',
                required    => gettext('This is required!'),
            },
            from_address => {
                description => gettext('Mail address to describe the sender.'),
                default     => 'xxv@example.com',
                type        => 'string',
            },
            smtp => {
                description => gettext('SMTP mail server host name'),
                default     => main::getModule('STATUS')->name,
                type        => 'host',
                required    => gettext('This is required!'),
            },
            susr => {
                description => gettext('User name for mail server access'),
                default     => 'xxv',
                type        => 'string',
            },
            spwd => {
                description => gettext('Password for mail server access'),
                default     => 'xxv',
                type        => 'password',
                check       => sub{
                    my $value = shift || return;

                    return $value unless(ref $value eq 'ARRAY');

                    # If no password given the take the old password as default
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

    # create Template object
    $self->{tt} = Template->new(
      START_TAG    => '\<\?\%',		    # Tagstyle
      END_TAG      => '\%\?\>',		    # Tagstyle
      INTERPOLATE  => 1,                # expand "$var" in plain text
      PRE_CHOMP    => 1,                # cleanup whitespace
      EVAL_PERL    => 1,                # evaluate Perl code blocks
      ABSOLUTE     => 1,
    );

    my @tmplfiles = glob(
        sprintf('%s/%s_*.tmpl',
            $self->{paths}->{NEWSTMPL},
            lc((split('::', $self->{MOD}->{Name}))[-1])
        )
    );
    for (@tmplfiles) {
        my ($order, $typ) = $_ =~ /_(\d+)_(\S+)\.tmpl$/si;
        $self->{TEMPLATES}->{$typ} = $_;
    }

    # The Initprocess
    my $erg = $self->init
        or return error("Can't initialize news module!");

    $self->{TYP} = 'text/plain';

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift || return error('No object defined!');
    $self->{INITE} = 1;

    $self->{LastReportTime} = time;

    # Interval to send the next mail
    $self->{TIMER} = Event->timer(
        interval => $self->{interval}*3600,
        prio => 6,  # -1 very hard ... 6 very low
        cb => sub{
            if($self->{active} eq 'y') {
              $self->send();
            }
        },
    );

    $self->{COUNT} = 1;

    1;
}

# ------------------
sub send {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $content = shift || $self->_req();

    return error('This function is deactivated!')
        if($self->{active} ne 'y');

    use Mail::SendEasy; # Hmm, failed with standard eval { use _$ } ...

    my $mail = new Mail::SendEasy(
        smtp => $self->{smtp},
        user => $self->{susr},
        pass => $self->{spwd},
        timeout => 60,
        port => 25
    );
    unless($mail) {
      error sprintf("Can't create mail instance %s!", $!);
      return undef;
    }

    my @addresses = split(/\s*,\s*/, $self->{address});

    # Send mail
    my $status = $mail->send(
        from    => $self->{from_address},
        from_title => 'XXV MailNewsAgent',
        to      => shift @addresses ,
        cc      => join(',', @addresses),
        subject => gettext("News from your XXV System!"),
        msg     => $content,
        msgid   => $self->{COUNT}
    ) || return error sprintf("Can't send mail: %s", $mail->error);

    lg sprintf('Mail %d. send successfully', $self->{COUNT}++);

    1;
}

# ------------------
sub parseHeader {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $newscnt = shift || 0;

    my $output = '';

    my $vars = {
        msgnr => $self->{COUNT},
        date  => datum(),
        anzahl=> $newscnt,
    };

    my $template = $self->{TEMPLATES}->{'header'};
    $self->{tt}->process($template, $vars, \$output)
          or return error(sprintf("Can't parse mail template %s : %s", $template, $self->{tt}->error()));

    return $output;
}

# ------------------
sub parseFooter {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $output = '';


    my $vars = {
        usage => main::getModule('RECORDS')->{CapacityMessage},
        uptime  => main::getModule('STATUS')->uptime,
        lastreport => datum($self->{LastReportTime}),
    };

    my $template = $self->{TEMPLATES}->{'footer'};
    $self->{tt}->process($template, $vars, \$output)
          or return error(sprintf("Can't parse mail template %s : %s", $template, $self->{tt}->error()));

    return $output;
}


# ------------------
sub push {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $vars = shift || return error('No data defined!');

    return undef;
}

# ------------------
sub req {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $params = shift  || {};

    if($params->{test}) {
        my $content = $self->_req(1);
        if($self->send($content)) {
            return gettext('A mail with the following content has been sent to your mail account!')
                   . "\n\n"
                   . $content;
        } else {
            return gettext("Mail with the following content could'nt sent to your mail account!")
                   . "\n\n"
                   . $content;
        }
    }
    return $self->_req(1);
}
# ------------------
sub _req {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $test = shift  || 0;

    return gettext('The module NEWS::Mail is not active!')
        if($self->{active} ne 'y');

    my $content = '';

    my $sql = "SELECT SQL_CACHE id, title, message, cmd, data, level, UNIX_TIMESTAMP(addtime) from EVENTS where level >= ? AND UNIX_TIMESTAMP(addtime) >= ? order by addtime desc"; 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute($self->{level}, $self->{LastReportTime})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    my $data = $sth->fetchall_arrayref();

    $content .= $self->parseHeader($data ? scalar @$data : 0);

    my $emod = main::getModule('EVENTS');
    my $hmod = main::getModule('HTTPD');
    my $url = sprintf("http://%s:%s/", $self->{host}, $hmod->{Port});

    foreach my $entry (@{$data}) {
        my ($id, $title, $message, $cmd, $data, $level, $addtime) = @{$entry};

        my $link = $url;
           $link .= sprintf("?cmd=%s&data=%s", $cmd, $data)
                if($cmd && $data);

        my $vars = {
            AddDate => $addtime,
            Title   => $title,
            Text    => $message,
            Cmd     => $cmd,
            Id      => $data,
            Url     => $link,
            Level   => $level,
            category => $emod->translate_scala($level),
            count  => $id,
            host   => $self->{host},
            port   => $hmod->{Port},
        };

        my $output = '';
        my $template = $self->{TEMPLATES}->{'content'};
        $self->{tt}->process($template, $vars, \$output)
              or return error($self->{tt}->error());
        $content .= $output;
    }

    $content .= $self->parseFooter();

    $self->{LastReportTime} = time unless($test);

    return $content;
}


1;

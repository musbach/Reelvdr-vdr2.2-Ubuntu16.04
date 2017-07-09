package XXV::MODULES::REMOTE;

use strict;

use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'REMOTE',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module emulate a remote control.'),
        Level => 'user',
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
            monitor => {
                description => gettext('Show grabbed video framebuffer in addition to remote control.'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
                level       => 'guest'
            },
            commands => {
                description => sprintf(gettext("Path of file '%s'"),'commands.conf'),
                default     => '/var/lib/vdr/commands.conf',
                type        => 'file',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            remote => {
                description => gettext("Display ir remote 'cmd'"),
                short       => 'r',
                callback    => sub{ $self->remote(@_) },
                DenyClass   => 'remote',
            },
            switch => {
                description => gettext("Switch to channel 'cid'"),
                short       => 'sw',
                callback    => sub{ $self->switch(@_) },
                DenyClass   => 'remote',
            },
            command => {
                description => gettext("Call the command 'cid'"),
                short       => 'cmd',
                callback    => sub{ $self->command(@_) },
                DenyClass   => 'remote',
            },
            cmdlist => {
                description => gettext("List the commands"),
                short       => 'cmdl',
                callback    => sub{ $self->list(@_) },
                DenyClass   => 'remote',
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

    $self->init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub init {
# ------------------
    my $self = shift  || return error('No object defined!');

    main::after(sub{
          $self->{svdrp} = main::getModule('SVDRP');
          unless($self->{svdrp}) {
            panic ("Couldn't get modul SVDRP");
            return 0;
          }

          $self->{CMDS} = $self->parse();
          return 1;
        }, "REMOTE: Parse Commandfile ...");

    return 1;
}

# ------------------
sub parse {
# ------------------
    my $self = shift  || return error('No object defined!');

    return 0
        unless (exists $self->{commands});

    if(! -r $self->{commands}) {
        error (sprintf("Could not open file '%s'! : %s",$self->{commands},$!));
        return 0;
    }

    my $cmds = load_file($self->{commands});

    my $c = 0;
    my $ret = {};
    foreach my $zeile (split("\n", $cmds)) {
        next if($zeile =~ /^\#/);
        my ($cmd, $batch) = split('\s*\:\s*', $zeile);

        $ret->{$c++} = {
            cmd => $cmd,
            bat => $batch,
        } if($cmd and $batch);
    }
    return $ret;
}

# ------------------
sub list {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $cmds = $self->parse();

    my @list = (['__Id', 'Name', 'Cmd']);
    foreach my $id (sort {$a <=> $b} keys %$cmds) {
        push(@list, [$id, $cmds->{$id}->{cmd}, $cmds->{$id}->{bat}]);
    }

    return $console->table(\@list);
}

# ------------------
sub command {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $command = shift || return error('No command defined!');
    my $cmds = $self->parse();

    return $console->err(gettext('This cmd id does not exist!'))
        unless(exists $cmds->{$command});

    $console->message(my $msg = sprintf(gettext('Try to start command: %s with cmd: %s'),
        $cmds->{$command}->{cmd}, $cmds->{$command}->{bat}));

    lg $msg;

    my $out;
    open(README, "$cmds->{$command}->{bat} 2>&1 |") or return error("Couldn't run program: $!");
    while(<README>) {
        $out .= $_;
    }
    close(README);
    return $console->message($out,  {
                                        tags => {
                                           first => "<pre>", 
                                           last => "</pre>"
                                        }
                                    } );
}


# ------------------
sub remote {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $command = shift;
    my $params = shift;

    my $vdr = $self->{svdrp}->primary_hosts();
    if($params && $params->{vdr}) {
      $vdr = $params->{vdr};
    }

    unless($command) {
        my $gmod = main::getModule('GRAB');
        my $cmod = main::getModule('CHANNELS');
        my $params = {
            width => $gmod->{xsize},
            height => $gmod->{ysize},
            monitor => $self->{monitor} eq "y" ? 1 : 0,
            channels => $cmod->ChannelWithGroup('c.name,c.id'),
            vdrlist => $self->{svdrp}->enum_onlinehosts(),
            vdr => $vdr,
        };
        return $console->remote(undef, $params);
    } else {

        my $translate = {
            '<' => 'Channel-',
            '>' => 'Channel+',
            '+' => 'Volume+',
            '-' => 'Volume-',
            '>>' => 'FastFwd',
            '<<' => 'FastRew',
            'VolumePlus' => 'Volume+',
            'VolumeMinus' => 'Volume-',
            'Null' => '0',
        };

        $command = $translate->{$command}
            if(exists $translate->{$command});

        lg sprintf('Call remote command "%s" on %s%s',
            $command,
            $self->{svdrp}->hostname($vdr),
            ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

        # fire hit key command via svdrp
        my ($erg,$error) = $self->{svdrp}->command(sprintf('hitk %s', $command), $vdr);

        $console->msg($erg, $error)
            if(ref $console);
    }
    return 1;
}

# ------------------
sub switch {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
    my $cid = shift || '';
    my $params = shift;

    my $vdr = $self->{svdrp}->primary_hosts();
    if($params && $params->{vdr}) {
      $vdr = $params->{vdr};
    }

    my $cmod = main::getModule('CHANNELS');
    my $hash = $cmod->ToHash($cid, $vdr);
    return con_err($console, sprintf(gettext("Channel '%s' does not exist in the database!"),$cid))
      unless($hash);

    my $channel; 
    $channel = $cmod->GetChannel($hash);
    return con_err($console, sprintf(gettext("Channel '%s' does not exist in the database!"),$cid))
      unless($channel);

    lg sprintf('Change channel "%s" on %s%s',
        $channel->{name},
        $self->{svdrp}->hostname($channel->{vid}),
        ( ref $console && $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );

    # fire change channel command via svdrp
    my ($erg,$error) = $self->{svdrp}->command(sprintf('chan %s', $channel->{pos}),$channel->{vid});

    $console->msg($erg, $error)
        if(ref $console);
    return undef if($error);

    $console->redirect({url => sprintf('?cmd=program&amp;data=%s',$channel->{hash}), wait => 1})
        if(ref $console and $console->typ eq 'HTML');

    my ($ret) = $erg->[1] =~ /^\d{3}\s*(.+)/s;

    return $ret;
}

1;

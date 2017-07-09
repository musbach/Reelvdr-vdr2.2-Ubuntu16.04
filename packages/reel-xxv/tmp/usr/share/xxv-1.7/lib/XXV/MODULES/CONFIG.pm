package XXV::MODULES::CONFIG;

use strict;

use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'CONFIG',
        Prereq => {
            'Module::Reload'    => 'Reload %INC files when updated on disk ',
        },
        Description => gettext('This module edits, writes and saves the configuration.'),
        Commands => {
            configedit => {
                description => gettext("Edit configuration 'section'"),
                short       => 'ce',
                callback    => sub{ $obj->edit(@_) },
                Level       => 'admin',
            },
            configget => {
                description => gettext("Get configuration from 'modname'"),
                short       => 'cg',
                callback    => sub{ $obj->get(@_) },
                Level       => 'admin',
            },
            help => {
                description => gettext("This will display all commands or description of module 'name'."),
                short       => 'h',
                callback    => sub{
                    return $obj->usage(@_);
                },
            },
            reload => {
                description => gettext("Restart all modules."),
                short       => 'rel',
                callback    => sub{
                    my ($console, $config, $l) = @_;
                    $Module::Reload::Debug = CORE::int(($Tools::VERBOSE+.5)/2);
#                   my %Status = %Module::Reload->Stat;
                    my $cnt = Module::Reload->check();
#                   my $files;
#                   foreach my $file (keys %Module::Reload::Stat) {
#                     push(@$files, $file) 
#                       if($Module::Reload::Stat{$file} ne $Status{$file});
#                   }
                    if($cnt) {
                      $console->message(sprintf(gettext("Reload %d modules."),$cnt));
                    } else {
                      $console->message(gettext("There none module reloaded."));
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

    # Try to use the Requirments
    map {
        eval "use $_";
        if($@) {
          my $m = (split(/ /, $_))[0];
          return panic("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
        }
    } keys %{$self->{MOD}->{Prereq}};

    # read the Configdata
    $self->{config} = $attr{'-config'};

	return $self;
}

# ------------------
sub _menu {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift;
    my $sector  = shift || 0;

    my $ret = {};
    $ret->{title} = gettext("Global settings");
    $ret->{highlight} = $sector;

    my $mods = main::getModules;
    foreach my $module (sort keys %{$mods}) {
        my $name = $mods->{$module}->{MOD}->{Name};
        error(sprintf("Missing real modul name %s",$module)) unless($name);
        next unless($name && exists $obj->{config}->{$name});

        $ret->{links}->{$name} = {
                text => $name,
                link => "?cmd=configedit&data=$name",
        };
    }

    return $console->littlemenu($ret);
}

# ------------------
sub edit {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift;
    my $sector  = shift || 0;
    my $data    = shift || 0;

    $obj->_menu( $console, $config, $sector )
        if($console->{TYP} eq 'HTML' or ($console->{TYP} ne 'HTML' and not $sector));
    return unless $sector;

    $sector = uc($sector) unless($sector eq 'General');

    my $cfg = $obj->{config}->{$sector}
        or return con_err($console, sprintf(gettext("Sorry, but section %s does not exist in the configuration!"),$sector));

    my $mod = main::getModule($sector);

    my $prefs = $mod->{MOD}->{Preferences}
        or return con_err($console, sprintf(gettext("Sorry, but the settings in module: %s do not exist!"),$sector));

    my $questions = [];
    foreach my $name (sort { lc($a) cmp lc($b) } keys(%{$prefs})) {
        my $def = $prefs->{$name}->{default};
        $def = $cfg->{$name}
            if(defined $cfg->{$name} && $cfg->{$name} ne "");
        push(@$questions, $name,
            {
                typ => $prefs->{$name}->{type} || 'string',
                options => $prefs->{$name}->{options},
                msg => sprintf("%s:\n%s", ucfirst($name), ($prefs->{$name}->{description} || gettext('No description'))),
                def => $def,
                req => $prefs->{$name}->{required},
                choices  => $prefs->{$name}->{choices},
                check  => $prefs->{$name}->{check},
                readonly  => $prefs->{$name}->{readonly} || 0,
            }
        );
    }

    my $desc = $mod->{MOD}->{Description};
    $desc =~ s/[\.\r\n].*$//g; # remove last part

    $console->link({text => $desc . " - " . sprintf(gettext("%s manual") , $sector) . " ..." , url => "?cmd=doc&data=$sector"})
        if($console->typ eq 'HTML');

    $cfg = $console->question(sprintf(gettext('Edit configuration %s'), $sector), $questions, $data);

    if(ref $cfg eq 'HASH') {
        $obj->{config}->{$sector} = $cfg;
        con_msg($console, sprintf(gettext("Section: '%s' saving ... please wait."), $sector));
        my $success = $obj->write($console);

        $console->redirect({url => '?cmd=configedit', wait => 1})
            if($success eq 'ok' 
                && $console->typ eq 'HTML');
    }
}

# ------------------
sub write {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift;

    my $success = $obj->reconfigure($console);
    my $configfile = main::getUsrConfigFile;

    if($success eq 'ok' 
        && !$obj->{config}->write( $configfile )) {
      con_err($console, sprintf ("Couldn't write '%s': %s", $configfile , $! ));
      return 'failed';
    }
    con_msg($console, sprintf(gettext("Configuration written to '%s'."), $configfile));
    return $success;
}

# ------------------
sub get {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift;
    my $config = shift;
    my $modname = shift || 0;

    return con_err($console, gettext('Need a name of the module to display the configuration!'))
        unless($modname);

    $modname = uc($modname) unless($modname eq 'General');

    my $cfg = $obj->{config}->{$modname};

    con_err($console, sprintf(gettext("Sorry, but section %s does not exist in the configuration!"),$modname))
        if(! $cfg);

    if(ref $console) {
        return $console->table($cfg);
    } else {
        return $cfg;
    }
}

# ------------------
sub reconfigure {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift;

    my $success = 'ok';

    my $cfg = $obj->{config};
    foreach my $moduleName (keys %$cfg) {
        if($moduleName eq 'General') {
            main::reconfigure();
        } else {
            my $mod = main::getModule($moduleName)
                or (error("$moduleName does not exist!") && next);
            foreach my $parameter (keys %{$mod->{MOD}->{Preferences}}) {
                if(defined $mod->{$parameter}) {
                    $cfg->{$moduleName}->{$parameter} = $mod->{MOD}->{Preferences}->{$parameter}->{default}
						if(not defined $cfg->{$moduleName}->{$parameter});
                    $mod->{$parameter} = $cfg->{$moduleName}->{$parameter};

                    # Check this input
                    if(my $check = $mod->{MOD}->{Preferences}->{$parameter}->{check}) {
                        if(ref $check eq 'CODE') {
                            my ($ok, $err) = &$check($mod->{$parameter});
                            unless($ok || not $err) {
                              my $message = sprintf("Config -> %s -> %s: %s %s", $moduleName, $parameter, $mod->{$parameter}, $err);
                              con_err($console, $message);
                              $success = 'failed';
                            }
                        }
                    }

                } else {
                    con_err($console, sprintf(gettext("Couldn't find %s in %s!"), $parameter, $moduleName));
                    $success = 'failed';
                }
            }
        }
    }

    con_msg($console, gettext('Edit successful!'))
      if($success eq 'ok');
    return $success;
}

# ------------------
sub realModNames {
# ------------------
    my $obj = shift  || return error('No object defined!');

    my $mods = main::getModules();
    my @realModName;

    # Search for command and display the Description
    foreach my $modName (sort keys %{$mods}) {
        my $modCfg = $mods->{$modName}->{MOD};
        push(@realModName, $mods->{$modName}->{MOD}->{Name})
          if(exists $mods->{$modName}->{MOD}->{Name});
    }

    return sort @realModName;
}

# ------------------
sub usage {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift;
    my $modulename = shift || 0;
    my $hint = shift || '';
    my $user = shift || $console->{USER};

    my $u = main::getModule('USER');
    unless($user) {
        my $loginObj = $obj;
        $loginObj = main::getModule('HTTPD')
                if ($console->{TYP} eq 'HTML') ;
        $loginObj = main::getModule('WAPD')
                if ($console->{TYP} eq 'WML') ;
        $user = $loginObj->{USER};
    }

    my $ret;
    if($console->typ eq 'HTML') {
      push(@$ret, sprintf(gettext("%sThis is the xxv %s server.\nPlease use the following commands:\n"),
          ($hint ? "$hint\n\n" : ''), $console->typ));
    }
    $console->setCall('help');
    my $mods = main::getModules();
    my @realModName;

    # Search for command and display the Description
    foreach my $modName (sort keys %{$mods}) {
        my $modCfg = $mods->{$modName}->{MOD};

        my $name = $modCfg->{Name};
				unless($name) {
	        error(sprintf("Missing real name from modul %s",$modName));
					next;
				}

        next if($modulename and uc($modulename) ne $name);
        push(@realModName, $name);

				my $addcmd = undef;
        foreach my $cmdName (sort keys %{$modCfg->{Commands}}) {

						next if($modCfg->{Commands}->{$cmdName}->{hidden});

						my ($ccmdobj, $ccmdname, $cshorterr, $cerror) = $u->checkCommand($console, $cmdName,"1");
						next unless($ccmdobj);

            push(@$ret,
                [
                    $modCfg->{Commands}->{$cmdName}->{short},
                    $cmdName,
                    $name,
                    $modCfg->{Commands}->{$cmdName}->{description}
                ]
            );
					  $addcmd = 'ok';
        }
				unless($addcmd) {
            push(@$ret,
                [
                    undef,
                    undef,
                    $name,
                    gettext("None active commands")
                ]
            );
				}
    }
    my $info = {
      rows => scalar @$ret
    };
    if($console->typ eq 'HTML') {
      $info->{periods} = $mods->{'XXV::MODULES::EPG'}->{periods};
      $info->{CHANNELS} =  $mods->{'XXV::MODULES::CHANNELS'}->ChannelWithGroup('c.name,c.hash');
      $info->{CONFIGS} = [ sort @realModName ];
    }
    $console->table( $ret, $info );
}

1;

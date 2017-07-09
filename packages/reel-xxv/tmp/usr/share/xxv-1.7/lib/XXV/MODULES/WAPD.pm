package XXV::MODULES::WAPD;

use XXV::OUTPUT::Wml;
use File::Find;
use Tools;

use strict;

my $mime = {
    wml => "text/vnd.wap.wml",                 # WML-Dateien (WAP)
    wmlc => "application/vnd.wap.wmlc",        # WMLC-Dateien (WAP)
    wmls => "text/vnd.wap.wmlscript",          # WML-Scriptdateien (WAP)
    wmlsc => "application/vnd.wap.wmlscriptc", # WML-Script-C-dateien (WAP)
    wbm => "image/vnd.wap.wbmp",              # Bitmap-Dateien (WAP)
    wbmp  => "image/vnd.wap.wbmp"              # Bitmap-Dateien (WAP)
};

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'WAPD',
        Prereq => {
            'IO::Socket::INET'  => 'Object interface for AF_INET domain sockets ',
            'MIME::Base64'      => 'Encoding and decoding of base64 strings',
            'CGI qw/:push -nph -no_xhtml -compile/'
                                => 'Simple Common Gateway Interface Class',
        },
        Description => gettext('This module is a multisession WAPD server.'),
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
                description => gettext('Number of port to listen for wap clients'),
                default     => 8085,
                type        => 'integer',
                required    => gettext('This is required!'),
            },
            Interface => {
                description => gettext('Local interface to bind service'),
                default     => '0.0.0.0',
                type        => 'host',
                required    => gettext('This is required!'),
            },
            WMLRoot => {
                description => gettext('Skin used'),
                default     => 'wml',
                type        => 'list',
                required    => gettext('This is required!'),
                choices     => $self->findskins,
            },
#            StartPage => {
#                description => gettext('Startup screen'),
#                default     => 'now',
#                type        => 'list',
#                required    => gettext('This is required!'),
#                choices     => [
#                    [ gettext('Running now'),     'now'],
#                    [ gettext('Program guide'),   'program'],
#                    [ gettext('Autotimer'),       'alist'],
#                    [ gettext('Timers'),          'tlist'],
#                    [ gettext('Recordings'),      'rlist'],
#                    [ gettext('Music'),           'mlist'],
#                    [ gettext('Remote'),          'remote'],
#                    [ gettext('Teletext'),        'vtxpage'],
#                    [ gettext('Status'),          'sa'],
#                ],
#			},
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
    my $self = shift || return error('No object defined!');

    # globals
    my $channels;

    # make socket
	my $socket = IO::Socket::INET->new(
		Listen		=> $self->{Clients},
		LocalPort	=> $self->{Port},
    LocalAddr => $self->{Interface},
		Reuse		=> 1
    ) or return error("Couldn't create socket: $!");

    # install an initial watcher
    Event->io(
        fd => $socket,
        prio => -1,  # -1 very hard ... 6 very low
        cb => sub {
            # accept client
            my $client=$socket->accept;
            panic "Couldn't connect to new wap client." and return unless $client;
            $client->autoflush;

            # make "channel" number
            my $channel=++$channels;

            # install a communicator
            Event->io(
                fd => $client,
                poll => 'r',
                prio => -1,  # -1 very hard ... 6 very low
                cb => sub {
                    my $watcher = shift;

                    # read new line and report it
                    my $handle=$watcher->w->fd;

                    my $ip = getip($handle);

                    my $data = $self->parseRequest($handle,(defined $self->{LOGOUT} && $self->{LOGOUT} == 1 ));
                    unless($data) {
                        undef $self->{LOGOUT};
                        $watcher->w->cancel;
                        $handle->close();
                        undef $watcher;
                        return 1;
                    }

                    undef $self->{LOGOUT}
                        if(exists $self->{LOGOUT});

                    my $WMLRootDir = sprintf('%s/%s', $self->{paths}->{HTMLDIR}, $self->{WMLRoot});
                    my $cgi = CGI->new( $data->{Query} );

                    my $console = XXV::OUTPUT::Wml->new(
                        -handle => $handle,
                        -dbh    => $self->{dbh},
                        -wmldir => $WMLRootDir,
                        -cgi    => $cgi,
                        -mime   => $mime,
                        -browser=> $data,
                        -paths  => $self->{paths},
                        -charset=> $self->{charset},
#						-start  => $self->{StartPage},
                    );

                    my $userMod = main::getModule('USER');
                    if(ref $userMod and $userMod->{active} eq 'y') {
                        $console->{USER} = $userMod->check($handle, $data->{username}, $data->{password});
                        $console->login(gettext('You are not authorized to use this system!'))
                            unless(exists $console->{USER}->{Level});
                    }

                    if(ref $userMod and
                            ($userMod->{active} ne 'y'
                                or exists $console->{USER}->{Level})) {

                        $console->{call} = 'nothing';
                        if(($data->{Request} eq '/' or $data->{Request} =~ /\.WML$/) and not $data->{Query}) {
                            # Send the first page (wapd.tmpl)
                            my $page = $data->{Request};
                            if($page eq '/') {
                                if(-r sprintf('%s/wapd.tmpl', $WMLRootDir)) {
                                    $console->{call} = 'wapd';
                                    my $output = $console->parseTemplate('wapd','wapd');
                                    $console->out( $output );
                                } else {
                                    $console->datei(sprintf('%s/index.WML', $WMLRootDir));
                                }
                            } else {
                                $console->datei(sprintf('%s/%s', $WMLRootDir, $page));
                            }
                        } elsif(my $typ = $mime->{lc((split('\.', $data->{Request}))[-1])}) {
                            # Send multimedia files (this must registered in $mime!)
                            $console->image(sprintf('%s%s', $WMLRootDir, $data->{Request}), $typ);
                        } elsif( $cgi->param('binary') ) {
                            # Send multimedia files (if param binary)
                            $self->handleInput($console, $cgi);
                        } else {
                            $console->start();
                            $self->handleInput($console, $cgi);
                            $console->footer();
                        }
                    }

                    # make entry more readable
		                $data->{Query} =~ s/%([a-f0-9][a-f0-9])/pack("C", hex($1))/ieg 
                      if($data->{Query});
		                $data->{Referer} =~ s/%([a-f0-9][a-f0-9])/pack("C", hex($1))/ieg
                      if($data->{Referer});
                    # Log like Apache Format ip, resolved hostname, user, method request, status, bytes, referer, useragent
                    lg sprintf('%s - %s "%s %s%s" %s %s "%s" "%s"',
                          $ip,
                          $data->{username} ? $data->{username} : "-",
                          $data->{Method},
                          $data->{Request} ? $data->{Request} : "",
                          $data->{Query} ? "?" . $data->{Query} : "",
                          $console->{'header'},
                          $console->{'sendbytes'},
                          $data->{Referer} ? $data->{Referer} : "-",
                          "-" #$data->{http_useragent} ? $data->{http_useragent} : ""
                        );

                    $watcher->w->cancel;
                    undef $watcher;
                    $handle->close();
                },
            );

        },
    ) if($self->{active} eq 'y');

    return 1;

}

# ------------------
sub _readline {
# ------------------
    my $fh = $_[0];
    my $c='';
    my $line='';
    my $eof=0;

    while ($c ne "\n" && ! $eof) {
    	if (sysread($fh, $c, 1) > 0) {
        $line = $line . $c;
      } else {
        $eof=1;
      }
    }
    return $line;
}
# ------------------
sub parseRequest {
# ------------------
    my $self = shift || return error('No object defined!');
    my $socket = shift || return error('No handle defined!');
    my $logout = shift || 0;

    binmode $socket;
   	my $data = {};
    my $line;
    while (defined($line = &_readline($socket))) {
        if(!$line || $line eq "\r\n") {
    			last;
        } elsif(!$data->{Method} && $line =~ /^(\w+) (\/[\w\.\/\-\:\%]*)([\?[\w=&\.\+\%-\:\!]*]*)[\#\d ]+HTTP\/1.\d/) {
    			($data->{Method}, $data->{Request}, $data->{Query}) = ($1, $2, $3 ? substr($3, 1, length($3)) : undef);
        } elsif($line =~ /Referer: (.*)/) {
    			$data->{Referer} = $1;
    	  	$data->{Referer} =~ s/(\r|\n)//g;
    		} elsif($line =~ /Host: (.*)/) {
    			$data->{HOST} = $1;
    	  	$data->{HOST} =~ s/(\r|\n)//g;
    		} elsif($line =~ /Authorization: basic (.*)/i and not $logout) {
    			($data->{username}, $data->{password}) = split(":", MIME::Base64::decode_base64($1), 2);
    		} elsif($line =~ /User-Agent: (.*)/i) {
    			$data->{http_useragent} = $1;
    	  	$data->{http_useragent} =~ s/(\r|\n)//g;
    		} elsif($line =~ /Accept-Encoding:.+?gzip/i) {
    			$data->{accept_gzip} = 1;
    		} elsif($line =~ /If-None-Match: (\S+)/i) {
    			$data->{Match} = $1;
    		} elsif($line =~ /Cookie: (\S+)=(\S+)/i) {
    			$data->{$1} = $2;
    		} elsif($line =~ /Content-Type: (\S+)/i) {
    			$data->{ContentType} = $1;
    		} elsif($line =~ /Content-Length: (\S+)/i) {
    			$data->{ContentLength} = $1;
    		}
        $self->{STATUS}->{'readbytes'} += length($line);
      }
   
	$data->{Request} =~ s/%([a-f0-9][a-f0-9])/pack("C", hex($1))/ieg
    if($data->{Request});
  if($data->{Method}) {
    if($data->{Method} eq 'GET' 
      or $data->{Method} eq 'HEAD') {
      return $data;
    } elsif($data->{Method} eq 'POST') {
      if(int($data->{ContentLength})>0) {
        my $post;
        my $bytes = sysread($socket,$post,$data->{ContentLength});
        $data->{Post} = $post
          if($bytes && $data->{ContentLength} == $bytes);
        $self->{STATUS}->{'readbytes'} += $bytes;
      }
      return $data;
    } else {
      lg sprintf("Unsupported HTTP Method : %s",$data->{Method});
    }
  }
  return undef;
}

# ------------------
sub ModulNotLoaded {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $module = shift || return error('No module defined!');

    $console->statusmsg(500,
          ,sprintf(gettext("Module '%s' is'nt loaded!"),$module),
          ,gettext("Internal Server Error"));
}

# ------------------
sub handleInput {
# ------------------
    my $self     = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $cgi     = shift || return error('No CGI object defined!');

    my $ucmd    = $cgi->param('cmd')  || '<undef>';
    my $udata   = $cgi->param('data') || '';

    # Set the referer, if come a form with a error
    # then patch the referer
    $console->{browser}->{Referer} = $cgi->param('referer')
        if($cgi->param('referer'));

    # Test on result set (user has save) and
    # get the DataVars in a special Hash
    my $result;
    foreach my $name ($cgi->param) {
        if(my ($n) = $name =~ /^__(.+)/sig) {
            my @vals = $cgi->param($name);
            if(scalar @vals > 1) {
                @{$result->{$n}} = @vals;
            } else {
                $result->{$n} = shift @vals;
            }
        }
    }

    # Test the command on exists, permissions and so on
    my $u = main::getModule('USER');
    if($u) {
      my ($cmdobj, $cmdname, $cmdModule, $shorterr, $err) = $u->checkCommand($console, $ucmd);
      $console->setCall($cmdname);
      if($cmdobj and not $shorterr) {

          if($cmdobj->{binary}) {
            $console->{nocache} = 1 
                if($cmdobj->{binary} eq 'nocache');
          }
          $cmdobj->{callback}($console, $console->{USER}->{config}->{$cmdModule}, $udata, $result );
      } elsif($shorterr eq 'noperm' or $shorterr eq 'noactive') {
          $console->status403($err);
      } else {
          $self->_usage($console, undef, $err);
      } 
    } else {
      $self->ModulNotLoaded($console,'USER');
    }
}

# ------------------
sub _usage {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $modulename = shift;
    my $hint = shift;

    my $m = main::getModule('CONFIG');
    if ($m){
      return $m->usage($console,undef, $modulename,$hint);
    } else {
      $self->ModulNotLoaded($console,'CONFIG');
    }

}


# ------------------
sub usage {
# ------------------
    my $self = shift || return error('No object defined!');
    return main::getModule('CONFIG')->usage(@_);
}

# ------------------
sub findskins
# ------------------
{
    my $self = shift || return error('No object defined!');
    my @skins;

    my $max_depth = $self->{paths}->{HTMLDIR} =~ tr[/][];

    find({ wanted => sub {
              my $l = $_;
              my $depth = $File::Find::dir =~ tr[/][];

              if(-d $File::Find::name
                    and ( $depth <= $max_depth )
                    and ( -r $File::Find::name.'/wapd.tmpl')
              ) {
                    push(@skins,[$l,$l]);
                }
           },
           follow => 1,
           follow_skip => 2,
        },
        $self->{paths}->{HTMLDIR}
    );
    error "Couldn't find useable WML Skin at : $self->{paths}->{HTMLDIR}"
        unless(scalar @skins);
    @skins = sort { lc($a->[0]) cmp lc($b->[0]) } @skins;
    return \@skins;
}

1;

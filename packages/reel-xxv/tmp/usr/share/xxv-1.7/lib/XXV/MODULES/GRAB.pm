package XXV::MODULES::GRAB;
use strict;

use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'GRAB',
        Prereq => {
            'GD'        => 'image manipulation routines'
            ,'Template'  => 'Front-end module to the Template Toolkit '
            ,'MIME::Base64' => 'Encoding and decoding of base64 strings'
            ,'Font::TTF::Font' => 'String table for a TTF font'
        },
        Description => gettext('This module grab a picture from video output.'),
        Preferences => {
            xsize => {
                description => gettext('Image width'),
                default     => 320,
                type        => 'integer',
                required    => gettext('This is required!'),
                check   => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 8 and $value < 4096) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                },
            },
            ysize => {
                description => gettext('Image height'),
                default     => 240,
                type        => 'integer',
                required    => gettext('This is required!'),
                check   => sub{
                    my $value = shift || 0;
                    if($value =~ /^\d+$/sig and $value >= 8 and $value < 4096) {
                        return int($value);
                    } else {
                        return undef, gettext('Value incorrect!');
                    }
                }
            },
            overlay => {
                description => gettext('Text to display in the grabbed picture.'),
                default     => "<< event.POS >>.<< event.Channel >>\|<< event.Title >> << event.Subtitle >>",
                type        => 'string',
                check   => sub{
                    my $value = shift;
                    $value = join('|',(split(/[\r\n]/, $value)));
                    return $value;
                },
            },
            vpos => {
                description => gettext('Vertical position of displayed text, in pixels.'),
                default     => 10,
                type        => 'integer',
                check   => sub{
                  my $value = shift || 0;
                  if($value =~ /^\d+$/sig and $value >= 8 and $value < 4096) {
                    return int($value);
                  } else {
                    return undef, gettext('Value incorrect!');
                  }
               }
            },
            font => {
                description => gettext('TrueType font to draw overlay text'),
                default     => 'VeraIt.ttf',
                type        => 'list',
                choices     => Tools::findttf($self->{paths}->{FONTPATH})
            },
            imgfontsize => {
                description => gettext('Font size to draw image text (only for ttf font!).'),
                default     => 10,
                type        => 'integer',
                check   => sub{
                  my $value = shift || 0;
                  if($value =~ /^\d+$/sig and $value >= 1 and $value < 100) {
                      return int($value);
                  } else {
                      return undef, gettext('Value incorrect!');
                  }
               }
            },
            imgquality => {
                description => gettext('Quality from image in percent.'),
                default     => 80,
                type        => 'integer',
                check   => sub{
                  my $value = shift || 0;
                  if($value =~ /^\d+$/sig and $value >= 1 and $value < 100) {
                    return int($value);
                  } else {
                    return undef, gettext('Value incorrect!');
                  }
               }
            },
        },
        Commands => {
            gdisplay => {
                hidden      => 'yes',
                short       => 'gd',
                callback    => sub{ $self->display(@_) },
                Level       => 'user',
                DenyClass   => 'remote',
                binary      => 'nocache'
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
          if($m eq 'Template')  { 
            error("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
            $self->{DisableTemplate} = 1;
          } elsif($m eq 'GD')  { 
            error("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
            $self->{DisableGD} = 1;
          } else {
            return panic("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
          }
        }
    } keys %{$self->{MOD}->{Prereq}};

    unless($self->{DisableTemplate}) {
      # create Template object
      $self->{tt} = Template->new(
        START_TAG    => '\<\<',		        # Tagstyle
        END_TAG      => '\>\>',		        # Tagstyle
        INTERPOLATE  => 1,                # expand "$var" in plain text
        PRE_CHOMP    => 0,                # cleanup whitespace
        EVAL_PERL    => 0,                # evaluate Perl code blocks
      );
    }
    $self->_init or return error('Problem to initialize modul!');

	return $self;
}

# ------------------
sub _init {
# ------------------
    my $self = shift  || return error('No object defined!');

    main::after(sub{
          $self->{svdrp} = main::getModule('SVDRP');
          unless($self->{svdrp}) {
            panic ("Couldn't get modul SVDRP");
            return 0;
          }
          return 1;
        }, "GRAB: init modul ...");
    return 1;
}

# ------------------
sub _grab {
# ------------------
    my $self = shift || return error('No object defined!');
    my $width = shift || $self->{xsize};
    my $height = shift || $self->{ysize};
    my $vid = shift;

    # command for get inline data (JPEG BASE64 coded)
    my $cmd = sprintf('grab - %d %d %d', $self->{imgquality}, $width, $height);
    my ($data,$error) = $self->{svdrp}->command($cmd, $vid);
    
    my $binary;
    unless($error) {
      foreach my $l (@{$data}) { 
        if($l =~ /^216-/sg) { 
          $l =~ s/^216-//g;
          $binary .= decode_base64($l); 
        } 
      }
    }

    unless($self->{DisableGD}) {
      # create noised image as failback. 
      $binary = $self->_noise($width,$height) 
        unless($binary);
    }
    if(!$self->{DisableGD} && !$self->{DisableTemplate}
       && $self->{overlay} && length($self->{overlay})
       && $data && $binary) {
      # Make overlay on image
      $binary = $self->makeImgText($binary, $self->{overlay}, $height, $vid)
    }
    return $binary;
}

# ------------------
sub display {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift;
    my $params = shift;

    return $console->err(gettext("Sorry, get image is'nt supported"))
      if ($console->{TYP} ne 'HTML');

    my $width = $console->{cgi} && $console->{cgi}->param('width') 
              ? $console->{cgi}->param('width') 
              : $self->{xsize};
    unless($width =~ /^\d+$/sig and $width >= 8 and $width < 4096) {
      error sprintf("Image width incorrect! : %s", $width );
      return $console->err(gettext('Value incorrect!'));
    }

    my $height = $console->{cgi} && $console->{cgi}->param('height') 
              ? $console->{cgi}->param('height') 
              : $self->{ysize};
    unless($height =~ /^\d+$/sig and $height >= 8 and $height < 4096) {
      error sprintf("Image height incorrect! : %s", $height );
      return $console->err(gettext('Value incorrect!'));
    }

    my $binary = $self->_grab($width,$height, $params && $params->{vdr} ? $params->{vdr} : undef);
    if($binary && length($binary)) { 
      $console->{nocache} = 1;
      $console->{nopack} = 1;
      my %args = ();
      $args{'Last-Modified'} = datum(time,'header');
      $args{'attachment'} = 'grab.jpg';
      $args{'Content-Length'} = length($binary);
      return $console->out($binary, 'image/jpeg', %args );
    } else {
      return $console->statusmsg(500,"Couldn't load image data !",gettext("Failed"));
    }
}

# ------------------
sub makeImgText {
# ------------------
    my $self = shift || return error('No object defined!');
    my $binary = shift || return error ('No data to create overlay defined!');
    my $text = shift || return error ('No text to display defined!');
    my $height = shift || $self->{ysize};
    my $vid = shift;

    my $image = GD::Image->newFromJpegData($binary);
    unless($image && $image->width > 8 && $image->height > 8) {
      return error("Data has'nt jpeg data or jpeg data contains errors!");
    }
    my $color   = $image->colorClosest(255,255,255);
    my $shadow  = $image->colorClosest(0,0,0);

    my $event = main::getModule('EPG')->NowOnChannel(undef,undef,undef,$vid);

    # Hier sollten noch mehr Informationen dazu kommen
    my $vars = {
        event => $event,
    };

    my $output = '';
    $self->{tt}->process(\$text, $vars, \$output)
          or return error(sprintf("Can't parse grab overlay template : %s", $self->{tt}->error()));

    my $vpos = CORE::int(($height / $self->{ysize}) * $self->{vpos});
    my $imgfontsize = CORE::int(($height / $self->{ysize}) * $self->{imgfontsize});

    #lg sprintf("height: %d vpos: %d imgfontsize: %d",$height,$vpos,$imgfontsize);

    my $font = sprintf("%s/%s",$self->{paths}->{FONTPATH},$self->{font});
    if($self->{paths}->{FONTPATH} and $self->{font} and -r $font) {
      my $h = ($imgfontsize + 2);
      $h *= -1 if($vpos > ($height / 2));

      my $offset = $imgfontsize/2;
      foreach my $zeile (split(/\|/, $output)) {
        $image->stringFT($shadow,$font,$imgfontsize,0,11,($vpos-1)+$offset,$zeile);
        $image->stringFT($color,$font,$imgfontsize,0,10,($vpos)+$offset,$zeile);
        $offset += $h;
      }
    } else {
      my $h = ($imgfontsize + 2);
      $h *= -1 if($vpos > ($height / 2));

      my $offset = 0;
      foreach my $zeile (split(/\|/, $output)) {
        $image->string(&gdGiantFont,11, ($vpos-1) + $offset,$zeile,$shadow); # Schatten
        $image->string(&gdGiantFont,10, ($vpos) + $offset,$zeile,$color);    # Text
        $offset += $h;
      }
    }

    my $img_data = $image->jpeg($self->{imgquality});
    return $img_data;
}

sub _noise {
    my $self = shift || return error('No object defined!');
    my $width = shift || $self->{xsize};
    my $height = shift || $self->{ysize};

    my $image = GD::Image->new($width, $height,1);
  
    my $colors;
    push( @{$colors}, $image->colorClosest(255,255,255));
    push( @{$colors}, $image->colorClosest(128,128,128));
    push( @{$colors}, $image->colorClosest(0,0,0));

    $self->_noise_rect($image,0,0,$width,$height,$colors);
    my $img_data = $image->jpeg($self->{imgquality});
    return $img_data;
}

sub _noise_rect {
    my $self = shift || return error('No object defined!');
    my $image = shift;
    my $x1 = shift; my $y1 = shift;
    my $x2 = shift; my $y2 = shift;
    my $colors_ref = shift;
    my $colorcount = scalar @{$colors_ref};

    return if $x2 <= $x1;  # refuse to create a zero- or negative-size box
    return if $y2 <= $y1;

    for (my $x = $x1; $x < $x2; ++$x) {
      for (my $y = $y1; $y < $y2; ++$y) {
        $image->setPixel($x, $y,$colors_ref->[CORE::int(rand($colorcount))]);
      }
    }

    return;
}

1;

package XXV::MODULES::VTX;

use strict;

use Tools;
use File::Find;
use FileHandle;

################################################################################
# This module method must exist for XXV
sub module {
    my $self = shift || return error('No object defined!');
    my $args = {
        Name => 'VTX',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module display cached teletext pages from osdteletext-plugin.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
            },
            dir => {
                description => gettext('Directory where the teletext files are be located'),
                default     => '/vtx',
                type        => 'dir',
                required    => gettext('This is required!'),
            },
            cache => {
                description => gettext("Used cache system.\nChoose 'legacy' for the traditional one-file-per-page system.\nDefault is 'packed' for the one-file-for-a-few-pages system.\nVDR-osdteletext-Plugin\n'legacy' <= osdteletext-0.3.2 or 'packed' >= osdteletext-0.4.0"),
                default     => 'packed',
                type        => 'radio',
                required    => gettext('This is required!'),
                choices     => ['legacy','packed']
            },
        },
        Commands => {
            vtxpage => {
                description => gettext("Display the teletext page"),
                short       => 'vt',
                callback    => sub{ $self->page(@_) },
            },
            vtxsearch => {
                description => gettext("Search for text inside teletext pages"),
                short       => 'vs',
                callback    => sub{ $self->search(@_) },
            }
        }
    };
    return $args;
}

################################################################################
# Ctor
sub new {
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

    return $self;
}


################################################################################
# Callback "Channel choice"
sub queryindex {
    my $self = shift || return error('No object defined!');
    my $channel = shift;
    lg sprintf("Query index %s",$channel);
    my $basedir = $self->{dir};
    my $chandir = $channel;

    if ($self->{cache} eq 'legacy') {
        my $modC = main::getModule ('CHANNELS');
        $chandir = $modC->ChannelToPos($channel);
    }
    my $INDEX = [];

    if ($chandir ne ""
        and -d "$basedir/$chandir")  {
        $self->{$channel}->{directory} = $chandir;

        my @index;
        if ($self->{cache} eq 'packed') {
            find(
                sub{
                   if($File::Find::name =~ /\d{3}s.vtx$/sig) {
                        push(@index,GetPackedToc($File::Find::name));
                    }
                },"$basedir/$chandir");
        } elsif ($self->{cache} eq 'legacy') {
            find(
                sub{
                    if($File::Find::name =~ /\d{3}_\d{2}.vtx$/sig) {
                        my ($page, $subpage)
                            = $File::Find::name =~ /^.*(\d{3})_(\d{2}).*/si;
                        if($page and $subpage) {
                            my $found = 0;
                            foreach my $p (@index) {
                                if($p->[0] == $page) {
                                    $found = 1;
                                    push(@{$p->[1]},hex($subpage))
                                        if($subpage != 0);
                                    last;
                                }
                            }
                            if ($found == 0) {
                                push(@index,[hex($page), [$subpage] ]);
                            }
                        }
                    }
                },"$basedir/$chandir");
        }
        if (scalar @index == 0) {
            return undef;
        }
        # Seitenindex sortieren
        @$INDEX = sort { $a->[0] <=> $b->[0] } @index;
        # Subseitenindex sortieren
        foreach my $p (@$INDEX) {
            if (scalar @{$p->[1]} > 1) {
                my @tmp = sort { $a <=> $b } @{$p->[1]};
                @{$p->[1]} = @tmp;
            }
        }
    }
# Dump PageIndex
    #foreach my $p (@$INDEX) {
    #   my $dump = "Pages $p->[0]";
    #   foreach my $s (@{$p->[1]}) {
    #      $dump .= ", $s";
    #   }
    #   warn($dump);
    #}
    return $INDEX;
}

sub queryChannels {
    my $self = shift || return error('No object defined!');
    if(!(defined $self->{CHANNELS}) 
        || !defined($self->{CHANNELSLastUpdate}) 
        || $self->{CHANNELSLastUpdate} < (time() - 300)) 
      {
        my $charray =[];

        my $basedir = $self->{dir};
        my $modC = main::getModule ('CHANNELS');
        my @chan = (@{$modC->ChannelArray ('Name, Id')});
        if ($self->{cache} eq 'legacy') {
            foreach my $ch (@chan) {
                push (@$charray, [$ch->[0], $ch->[2]])
                    if (-d $basedir.'/'.$ch->[2]) ; # Lookup /vtx/25/
            }
        } elsif ($self->{cache} eq 'packed') {
            foreach my $ch (@chan){
                if (-d $basedir.'/'.$ch->[1])  { # Lookup /vtx/S19.2E-1-1101-28108/
                    push (@$charray, [$ch->[0], $ch->[1]]);
                }
            }
        }
        $self->{CHANNELS} = $charray;
        $self->{CHANNELSLastUpdate} = time();
    }
    return $self->{CHANNELS};
}

sub firstChannel {
    my $self = shift || return error('No object defined!');
    $self->queryChannels();
    if($self->{CHANNELS}) {
      return $self->{CHANNELS}->[0]->[1];
    }
    return undef;
}

################################################################################
# Format page
sub formatPage {
    my $self = shift || return error('No object defined!');
    my $result = shift;
    my $channel = shift;
    my $page = shift;
    my $subpage = shift || 0;
    my $mtime = shift || 0;

    my $id = sprintf('%03d%02d',$page,$subpage);
    my $navPages = $self->NavigatePages($channel, $page, $subpage);
    my $lines = $self->InsertPageLink($result, $channel, $page);

    return [
         $id
        ,$page
        ,$subpage
        ,$channel
        ,$navPages->{page_prev}
        ,$navPages->{page_next}
        ,$mtime
        ,join('',@$lines)
    ];
}

################################################################################
# Insert for HTML Pages, Link for other Pages
sub InsertPageLink {

  my $self = shift;
  my $result = shift;
  my $channel = shift;
  my $page = shift;

  my @lines;

  my $index;
  my $pagelist;
  # Colect all page numbers from page
  foreach my $line (split('\n',$result)) {
    my $laenge=length($line);
    for (my $c=0; $c < $laenge; ) {
      my $token=substr($line, $c, 5);
      my ($page1) = $token =~ /\D([1-8]\d{2})\D/s;
      if($page1) {
          push(@$index,hex($page1));
          $c += 4;
        } else {
          $c++;
        }
      }
  }
  if($index && scalar @$index) {
    foreach my $x (@$index) {
      foreach my $p (@{$self->{$channel}->{INDEX}}) {
        if($x eq $p->[0]) {
          push(@$pagelist,$x);
          last;
        }
      }
    }
  }
  my $a;
  # Replace XXX => <a href="?cmd=vt&amp;...
  $a = "<a class='vtx' href='?cmd=vt&amp;channel=" . $channel . "&amp;page=";
  my $b = "'>";
  my $c = "</a>";

  foreach my $line (split('\n',$result)) {
    my $out = "";
    if($pagelist) {
      my $laenge=length($line);
      for (my $n=0; $n < $laenge; ) {
        my $token=substr($line, $n, 5);
        my ($page1) = $token =~ /\D([1-8]\d{2})\D/s;
        if($page1) {
            chop($token) if(length($token) > 4);
            if(grep {$_ == hex($page1);} @$pagelist) {
              $token =~ s/$page1/$a.$page1.$b.$page1.$c/eg;
            }
            $out .= $token;
            $n += 4;
        } else {
            $out .= substr($line, $n, 1);
            $n++;
        }
      }
    } else {
      $out = $line;
    }
    # Make anchor for external URLs
    $out =~ s/((www)\.[a-z0-9\.\/\-]+)/<a target=\"blank\" class=\"vtx\" href=\"http:\/\/$1\">$1<\/a>/gi;
    # /

    push (@lines, $out);
  }
  return \@lines;
}

################################################################################
# Find next and prior Pages, used one HTML View
sub NavigatePages {
    my $self = shift;
    my $channel = shift;
    my $page = shift;
    my $subpage = shift;

    my $result = ();

    my $mFound = 0;

    $result->{page_prev} = 0;
    $result->{page_next} = 0;

    foreach my $p (@{$self->{$channel}->{INDEX}}) {
       if($mFound == 1) {
            $result->{page_next} = sprintf("%3X",$p->[0]);
            last;
       }
       if($p->[0] && $p->[0] == hex($page)) {
            $mFound = 1;
       }
       if($mFound == 0) {
           $result->{page_prev} = sprintf("%3X",$p->[0]);
       }
    }
    if($mFound == 0) {
        $result->{page_prev} = 0;
    }
    return $result;
}

################################################################################
# HighLight searched text
sub HighLight {
    my $self = shift;
    my $result = shift;
    my $search = shift;
    my $lines;

    my $a = "<span class=\"vtx-mark\">";
    my $b = "</span>";

    foreach my $line (split('\n',$result)) {
      foreach my $token (split(/[\-\ \\]/,$search)) {
				if ($line !~ /\<[a-z0-9\" =\/:;&\?]*($token)[a-z0-9\" =\/:;&\?]*\>/i) { 
	        $line =~ s/($token)/\x01$1\x02/ig;
				}
      }
      $line =~ s/\x01/$a/ig;
      $line =~ s/\x02/$b/ig;
      $lines .= $line;
    }
    return $lines;
}

################################################################################
# Our internal real page deliverer
sub realpage {
  my $self    = shift || return error('No object defined!');
  my $channel= shift || return error('No channel defined!');
  my $mainpage= shift || return error('No page defined!');
  my $subpage = shift || 0;
  my $bHTML = shift;

################################################################################
# get filename
  my $filename;
  if ($self->{cache} eq 'packed') {
    # Build name /vtx/S19.2E-1-1101-28108/100s.vtx
    my $group = (int ($mainpage / 16)) * 16;
    $filename = sprintf ("%s/%s/%03Xs.vtx", $self->{dir}, $self->{$channel}->{directory}, $group);
  } else {
    # Build name /vtx/15/100_01.vtx
    $filename = sprintf ("%s/%s/%03X_%02X.vtx", $self->{dir}, $self->{$channel}->{directory}, $mainpage, $subpage);
  }
################################################################################
# Now open and read this file
  my $fh = FileHandle->new;
  if(!$fh->open($filename)) {
      error sprintf("Couldn't find page! (%s)", $filename);
      return undef;
  }

  my $result = $self->readpage($fh, $mainpage, $subpage, $bHTML);
  $fh->close();
  return $result;
}

################################################################################
# Translation table for ASCII
# Source - Bytelayout - vdr-plugin osdteletext-0.4.1/txtfont.c
# Codingrule iso-8859-15
my @tableascii = (
    ' ', # 0x20
    '!', # 0x21
    '"', # 0x22
    '#', # 0x23
    '$', # 0x24
    '%', # 0x25
    '&', # 0x26
    '\'', # 0x27
    '(', # 0x28
    ')', # 0x29
    '*', # 0x2A
    '+', # 0x2B
    ',', # 0x2C
    '-', # 0x2D
    '.', # 0x2E
    '/', # 0x2E
    '0', # 0x30
    '1', # 0x31
    '2', # 0x32
    '3', # 0x33
    '4', # 0x34
    '5', # 0x35
    '6', # 0x36
    '7', # 0x37
    '8', # 0x38
    '9', # 0x39
    ':', # 0x3A
    ';', # 0x3B
    '<', # 0x3C
    '=', # 0x3D
    '>', # 0x3E
    '?', # 0x3F
    '§', # 0x40
    'A', # 0x41
    'B', # 0x42
    'C', # 0x43
    'D', # 0x44
    'E', # 0x45
    'F', # 0x46
    'G', # 0x47
    'H', # 0x48
    'I', # 0x49
    'J', # 0x4A
    'K', # 0x4B
    'L', # 0x4C
    'M', # 0x4D
    'N', # 0x4E
    'O', # 0x4F
    'P', # 0x50
    'Q', # 0x51
    'R', # 0x52
    'S', # 0x53
    'T', # 0x54
    'U', # 0x55
    'V', # 0x56
    'W', # 0x57
    'X', # 0x58
    'Y', # 0x59
    'Z', # 0x5A
    'Ä', # 0x5B
    'Ö', # 0x5C
    'Ü', # 0x5D
    '^', # 0x5E
    '_', # 0x5F
    '°', # 0x60
    'a', # 0x61
    'b', # 0x62
    'c', # 0x63
    'd', # 0x64
    'e', # 0x65
    'f', # 0x66
    'g', # 0x67
    'h', # 0x68
    'i', # 0x69
    'j', # 0x6A
    'k', # 0x6B
    'l', # 0x6C
    'm', # 0x6D
    'n', # 0x6E
    'o', # 0x6F
    'p', # 0x70
    'q', # 0x71
    'r', # 0x72
    's', # 0x73
    't', # 0x74
    'u', # 0x75
    'v', # 0x76
    'w', # 0x77
    'x', # 0x78
    'y', # 0x79
    'z', # 0x7A
    'ä', # 0x7B
    'ö', # 0x7C
    'ü', # 0x7D
    'ß', #/0x7E
    ' ', # Block 0x7F
    '@', # 0x80
    ' ', # 0x81
    ' ', # 0x82
    '£', # 0x83
    '$', # 0x84
    ' ', # 0x85
    ' ', # 0x86
    ' ', # 0x87
    ' ', # 0x88
    ' ', # 0x89
    ' ', # 0x8A
    ' ', # 0x8B
    ' ', # 0x8C
    ' ', # 0x8D
    ' ', # 0x8E
    '#', # 0x8F
    'É', # 0x90
    'é', # 0x91
    'ä', # 0x92
    '#', # 0x93
    ' ', # 0x94
    ' ', # 0x95
    ' ', # 0x96
    ' ', # 0x97
    'ö', # 0x98
    'å', # 0x99
    'ü', # 0x9A
    'Ä', # 0x9B
    'Ö', # 0x9C
    'Å', # 0x9D
    'Ü', # 0x9E
    '_', # 0x9F
    ' ', # 0x20a  0xA0
    ' ', # 0x21a  0xA1
    ' ', # 0x22a  0xA2
    ' ', # 0x23a  0xA3
    ' ', # 0x24a  0xA4
    ' ', # 0x25a  0xA5
    ' ', # 0x26a  0xA6
    ' ', # 0x27a  0xA7
    ' ', # 0x28a  0xA8
    ' ', # 0x29a  0xA9
    ' ', # 0x2Aa  0xAA
    ' ', # 0x2Ba  0xAB
    ' ', # 0x2Ca  0xAC
    ' ', # 0x2Da  0xAD
    ' ', # 0x2Ea  0xAE
    ' ', # 0x2Fa  0xAF
    ' ', # 0x30a  0xB0
    ' ', # 0x31a  0xB1
    ' ', # 0x32a  0xB2
    ' ', # 0x33a  0xB3
    ' ', # 0x34a  0xB4
    ' ', # 0x35a  0xB5
    ' ', # 0x36a  0xB6
    ' ', # 0x37a  0xB7
    ' ', # 0x38a  0xB8
    ' ', # 0x39a  0xB9
    ' ', # 0x3Aa  0xBA
    ' ', # 0x3Ba  0xBB
    ' ', # 0x3Ca  0xBC
    ' ', # 0x3Da  0xBD
    ' ', # 0x3Ea  0xBE
    ' ', # 0x3Fa  0xBF
    'é', # 0xC0
    'ù', # 0xC1
    'à', # 0xC2
    '£', # 0xC3
    '$', # 0xC4
    'ã', # 0xC5
    'õ', # 0xC6
    ' ', # 0xC7
    'ò', # 0xC8
    'è', # 0xC9
    'ì', # 0xCA
    '°', # 0xCB
    'ç', # 0xCC
    ' ', # 0xCD
    ' ', # 0xCE
    '#', # 0xCF
    'à', # 0xD0
    'è', # 0xD1
    'â', # 0xD2
    'é', # 0xD3
    'ï', # 0xD4
    'Ã', # 0xD5
    'Õ', # 0xD6
    'Ç', # 0xD7
    'ô', # 0xD8
    'û', # 0xD9
    'ç', # 0xDA
    'ë', # 0xDB
    'ê', # 0xDC
    'ù', # 0xDD
    'î', # 0xDE
    '#', # 0xDF
    '¡', # 0xE0
    '¿', # 0xE1
    'ü', # 0xE2
    'ç', # 0xE3
    '$', # 0xE4
    ' ', # 0xE5
    ' ', # 0xE6
    ' ', # 0xE7
    'ñ', # 0xE8
    'è', # 0xE9
    'à', # 0xEA
    'á', # 0xEB
    'é', # 0xEC
    'í', # 0xED
    'ó', # 0xEE
    'ú', # 0xEF
    'Á', # 0xF0
    'À', # 0xF1
    'È', # 0xF2
    'Í', # 0xF3
    'Ï', # 0xF4
    'Ó', # 0xF5
    'Ò', # 0xF6
    'Ú', # 0xF7
    'æ', # 0xF8
    'Æ', # 0xF9
    'ð', # 0xFA
    ' ', # 0xFB
    'ø', # 0xFC
    'Ø', # 0xFD
    ' ', # 0xFE
    ' ', # 0xFF
    ' ', # 0x60a
    ' ', # 0x61a
    ' ', # 0x62a
    ' ', # 0x63a
    ' ', # 0x64a
    ' ', # 0x65a
    ' ', # 0x66a
    ' ', # 0x67a
    ' ', # 0x68a
    ' ', # 0x69a
    ' ', # 0x6Aa
    ' ', # 0x6Ba
    ' ', # 0x6Ca
    ' ', # 0x6Da
    ' ', # 0x6Ea
    ' ', # 0x6Fa
    ' ', # 0x70a
    ' ', # 0x71a
    ' ', # 0x72a
    ' ', # 0x73a
    ' ', # 0x74a
    ' ', # 0x75a
    ' ', # 0x76a
    ' ', # 0x77a
    ' ', # 0x78a
    ' ', # 0x79a
    ' ', # 0x7Aa
    ' ', # 0x7Ba
    ' ', # 0x7Ca
    ' ', # 0x7Da
    ' ', # 0x7Ea
    ' '  # 0x7Fa
);

################################################################################
# Translation table for HTML
my @tablehtml = (
    ' ', # 0x20
    '!', # 0x21
    '"', # 0x22
    '#', # 0x23
    '$', # 0x24
    '%', # 0x25
    '&amp;', # 0x26
    '\'', # 0x27
    '(', # 0x28
    ')', # 0x29
    '*', # 0x2A
    '+', # 0x2B
    ',', # 0x2C
    '-', # 0x2D
    '.', # 0x2E
    '/', # 0x2E
    '0', # 0x30
    '1', # 0x31
    '2', # 0x32
    '3', # 0x33
    '4', # 0x34
    '5', # 0x35
    '6', # 0x36
    '7', # 0x37
    '8', # 0x38
    '9', # 0x39
    ':', # 0x3A
    ';', # 0x3B
    '&lt;', # 0x3C
    '=', # 0x3D
    '&gt;', # 0x3E
    '?', # 0x3F
    '&sect;', # 0x40
    'A', # 0x41
    'B', # 0x42
    'C', # 0x43
    'D', # 0x44
    'E', # 0x45
    'F', # 0x46
    'G', # 0x47
    'H', # 0x48
    'I', # 0x49
    'J', # 0x4A
    'K', # 0x4B
    'L', # 0x4C
    'M', # 0x4D
    'N', # 0x4E
    'O', # 0x4F
    'P', # 0x50
    'Q', # 0x51
    'R', # 0x52
    'S', # 0x53
    'T', # 0x54
    'U', # 0x55
    'V', # 0x56
    'W', # 0x57
    'X', # 0x58
    'Y', # 0x59
    'Z', # 0x5A
    '&Auml;', # 0x5B
    '&Ouml;', # 0x5C
    '&Uuml;', # 0x5D
    '^', # 0x5E
    '_', # 0x5F
    '&deg;', # 0x60
    'a', # 0x61
    'b', # 0x62
    'c', # 0x63
    'd', # 0x64
    'e', # 0x65
    'f', # 0x66
    'g', # 0x67
    'h', # 0x68
    'i', # 0x69
    'j', # 0x6A
    'k', # 0x6B
    'l', # 0x6C
    'm', # 0x6D
    'n', # 0x6E
    'o', # 0x6F
    'p', # 0x70
    'q', # 0x71
    'r', # 0x72
    's', # 0x73
    't', # 0x74
    'u', # 0x75
    'v', # 0x76
    'w', # 0x77
    'x', # 0x78
    'y', # 0x79
    'z', # 0x7A
    '&auml;', # 0x7B
    '&ouml;', # 0x7C
    '&uuml;', # 0x7D
    '&szlig;', # 0x7E
    'image-7F', # Block 0x7F
    '@', # 0x80
    '&ndash;', # 0x81
    '&frac14;', # 0x82 1/4
    '&pound;', # 0x83
    '$', # 0x84
    ' ', # 0x85 Taste Teletext (a)
    ' ', # 0x86 Taste Small
    ' ', # 0x87 Taste Hide
    ' ', # 0x88 ||
    '&frac34;', # 0x89 3/4
    '&divide;', # 0x8A
    '&larr;', # 0x8B  <-
    '&frac12;', # 0x8C 1/2
    '&rarr;', # 0x8D ->
    '&uarr;', # 0x8E
    '#', # 0x8F
    '&Eacute;', # 0x90
    '&eacute;', # 0x91
    '&auml;', # 0x92
    '#', # 0x93
    '&curren;', # 0x94
    ' ', # 0x95 Taste Teletext (b)
    ' ', # 0x96 Taste
    ' ', # 0x97 Taste Big
    '&ouml;', # 0x98
    '&aring;', # 0x99
    '&uuml;', # 0x9A
    '&Auml;', # 0x9B
    '&Ouml;', # 0x9C
    '&Aring;', # 0x9D
    '&Uuml;', # 0x9E
    '_', # 0x9F
    'image-20', # 0x20a  0xA0 # image-20 == whitespace
    'image-21', # 0x21a  0xA1
    'image-22', # 0x22a  0xA2
    'image-23', # 0x23a  0xA3
    'image-24', # 0x24a  0xA4
    'image-25', # 0x25a  0xA5
    'image-26', # 0x26a  0xA6
    'image-27', # 0x27a  0xA7
    'image-28', # 0x28a  0xA8
    'image-29', # 0x29a  0xA9
    'image-2A', # 0x2Aa  0xAA
    'image-2B', # 0x2Ba  0xAB
    'image-2C', # 0x2Ca  0xAC
    'image-2D', # 0x2Da  0xAD
    'image-2E', # 0x2Ea  0xAE
    'image-2F', # 0x2Fa  0xAF
    'image-30', # 0x30a  0xB0
    'image-31', # 0x31a  0xB1
    'image-32', # 0x32a  0xB2
    'image-33', # 0x33a  0xB3
    'image-34', # 0x34a  0xB4
    'image-35', # 0x35a  0xB5
    'image-36', # 0x36a  0xB6
    'image-37', # 0x37a  0xB7
    'image-38', # 0x38a  0xB8
    'image-39', # 0x39a  0xB9
    'image-3A', # 0x3Aa  0xBA
    'image-3B', # 0x3Ba  0xBB
    'image-3C', # 0x3Ca  0xBC
    'image-3D', # 0x3Da  0xBD
    'image-3E', # 0x3Ea  0xBE
    'image-3F', # 0x3Fa  0xBF
    '&eacute;', # 0xC0
    '&ugrave;', # 0xC1
    '&agrave;', # 0xC2
    '&pound;', # 0xC3
    '$', # 0xC4
    '&atilde;', # 0xC5
    '&otilde;', # 0xC6
    '&bull;', # 0xC7
    '&ograve;', # 0xC8
    '&egrave;', # 0xC9
    '&igrave;', # 0xCA
    '&deg;', # 0xCB
    '&ccedil;', # 0xCC
    '&rarr;', # 0xCD
    '&uarr;', # 0xCE
    '#', # 0xCF
    '&agrave;', # 0xD0
    '&egrave;', # 0xD1
    '&acirc;', # 0xD2
    '&eacute;', # 0xD3
    '&iuml;', # 0xD4
    '&Atilde;', # 0xD5
    '&Otilde;', # 0xD6
    '&Ccedil;', # 0xD7
    '&ocirc;', # 0xD8
    '&ucirc;', # 0xD9
    '&ccedil;', # 0xDA
    '&euml;', # 0xDB
    '&ecirc;', # 0xDC
    '&ugrave;', # 0xDD
    '&icirc;', # 0xDE
    '#', # 0xDF
    '&iexcl;', # 0xE0
    '&iquest;', # 0xE1
    '&uuml;', # 0xE2
    '&ccedil;', # 0xE3
    '$', # 0xE4
    ' ', # 0xE5 a mit unterstrich
    ' ', # 0xE6 o mit unterstrich
    '&Ntilde;', # 0xE7
    '&ntilde;', # 0xE8
    '&egrave;', # 0xE9
    '&agrave;', # 0xEA
    '&aacute;', # 0xEB
    '&eacute;', # 0xEC
    '&iacute;', # 0xED
    '&oacute;', # 0xEE
    '&uacute;', # 0xEF
    '&Aacute;', # 0xF0
    '&Agrave;', # 0xF1
    '&Egrave;', # 0xF2
    '&Iacute;', # 0xF3
    '&Iuml;', # 0xF4
    '&Oacute;', # 0xF5
    '&Ograve;', # 0xF6
    '&Uacute;', # 0xF7
    '&aelig;', # 0xF8
    '&AElig;', # 0xF9
    '&eth;', # 0xFA
    '&ETH;', # 0xFB
    '&oslash;', # 0xFC
    '&Oslash;', # 0xFD
    '&thorn;', # 0xFE
    '&THORN;', # 0xFF
    'image-60', # 0x60a
    'image-61', # 0x61a
    'image-62', # 0x62a
    'image-63', # 0x63a
    'image-64', # 0x64a
    'image-65', # 0x65a
    'image-66', # 0x66a
    'image-67', # 0x67a
    'image-68', # 0x68a
    'image-69', # 0x69a
    'image-6A', # 0x6Aa
    'image-6B', # 0x6Ba
    'image-6C', # 0x6Ca
    'image-6D', # 0x6Da
    'image-6E', # 0x6Ea
    'image-6F', # 0x6Fa
    'image-70', # 0x70a
    'image-71', # 0x71a
    'image-72', # 0x72a
    'image-73', # 0x73a
    'image-74', # 0x74a
    'image-75', # 0x75a
    'image-76', # 0x76a
    'image-77', # 0x77a
    'image-78', # 0x78a
    'image-79', # 0x79a
    'image-7A', # 0x7Aa
    'image-7B', # 0x7Ba
    'image-7C', # 0x7Ca
    'image-7D', # 0x7Da
    'image-7E', # 0x7Ea
    'image-7F'  # 0x7Fa
);

################################################################################
# Color table
my @colors = (
    "black", "red", "green", "yellow",
    "blue", "magenta", "cyan", "white"
);

################################################################################
# Translation unpacked bytes to text
sub translate {

    my $self=shift;
    my $bHTML=shift;
    my $c=shift;
    my $graph=shift;
    my $double=shift;
    my $sepgraph=shift;
    my $fg=shift;
    my $bg=shift;
    $c = int($c);
    if ($graph == 1) {
        if (($c>=0x20) and ($c<=0x3F)) { $c += 0x80; }
        elsif (($c>=0x60) and ($c<=0x7F)) { $c += 0xA0; }
    }
    $c -= 0x20;
    if($bHTML == 1) {
        my $result;

        if ($fg != $self->{ofg} or $bg != $self->{obg}) {
            if ($self->{ofg} != -1 or $self->{obg} != -1) {
                $result .= "</font>";
            }
            $result .= sprintf("<font style=\"color:%s;background-color:%s;\">",$colors[$fg],$colors[$bg]);

            $self->{ofg} = $fg;
            $self->{obg} = $bg;
        }
        if($c < 0 or $c > 256) {
            $result .= '&nbsp;';
        } else {
            my $h .= $tablehtml[$c];
            $h =~ s/ /"&nbsp;"/eg;
            $result .= $h;
            if ($graph == 1 || $c == 0x5f) #Block 0x5f = 0x7f - 0x20
            {
                my $pre = "<span class=\"vtgfx ";
                my $color = $colors[$fg];
                my $post = "\"/>&nbsp;</span>";
                # set <span class="vtgfx white20"/>&nbsp;</span>
                # vtx-image are locate inside skin folder
                $result =~ s/image\-(.+)/$pre.$color.$1.$post/eg;
            }
        }
        return $result;
    } else {
        return ' ' if($c < 0 or $c > 256);
        return $tableascii[$c];
    }
}
################################################################################
# close text line
sub endline {
    my $self=shift;
    my $bHTML=shift;
    my $result = "";
    $result .= "</font><br />" if($bHTML);
    $result .= "\n";
    return $result;
}

################################################################################
# Read page which open from filehandle
sub readpage {
    my $self=shift;
    my $fh=shift;
    my $mainpage=shift;
    my $subpage=shift;
    my $bHTML = shift;

# Seek inside packed file
    if ($self->{cache} eq 'packed') {
        # Parse TOC
        #
        # 8x[MAIN,SUB a 2x4byte],
        # 8x[PAGE a 972byte],
        # 8x[MAIN,SUB a 2x4byte],
        # 8x[PAGE a 972byte]
        #
        my $tocbuf;
        my $notfound = 1;
        while($notfound == 1) {
            if($fh->read($tocbuf, 4*2*8) ne 64) {
                error sprintf("Couldn't read toc of page! (%d/%d)",$mainpage,$subpage);
                return undef;
            }
            my @toc = unpack( "i*", $tocbuf);
            my $n = 0;
            for (;$n < 8 and $notfound == 1; ++$n ) {
                my $mpage = int(@toc[$n*2]);
                my $spage = int(@toc[($n*2)+1]);
                # Check for last toc entry 0/0
                if($mpage == 0 and $spage == 0) {
                    error sprintf("Couldn't find page! (%d/%d)",$mainpage,$subpage);
                    return undef;
                }
                # Look for toc entry same wanted page
                if($mpage == $mainpage) {
                    if(($spage == $subpage )
                      or ($subpage <= 1 and $spage <= 1))  {
                      $notfound = 0;
                    }
                }
            }
            --$n if($notfound == 0);
            # Skip unwanted Pages
            if(0 == $fh->seek((972*$n), 1)) {
                error sprintf("Couldn't seek page! (%d/%d)",$mainpage,$subpage);
                return undef;
            }
        }
    }

# Read page now
    my $packed;
    if($fh->read($packed, 972) ne 972) {
        error sprintf("Couldn't read page! (%d/%d)",$mainpage,$subpage);
        return undef;
    }
    my $result = "";
    $result .= "<p class=\"vtx\">\n" if($bHTML);

    my @buf = unpack( "C*", $packed);

    my $n = 9 + 1 + 2; #Index, skip irgendwas davor, Language, irgendwas wieder
    my $flash=0;
    my $double=0;
    my $hidden=0; #hidden = verdeckt!!!
    my $sepgraph=0;
    my $hold=0;
    my $graph=0;
    my $skipnextline=0;
    my $lc=0x20;

    my $fg = 7;
    my $bg = 0;
    for (my $y=0;$y<24;$y++) {

         $flash=0;
         $double=0;
         $hidden=0; #hidden = verdeckt!!!
         $sepgraph=0;
         $hold=0;
         $graph=0;
         $skipnextline=0;
         $lc=0x20;

         $fg = 7;
         $bg = 0;
         $self->{ofg} = -1;
         $self->{obg} = -1;

         for (my $x=0;$x<40;++$x,++$n)
         {
#            $result .= sprintf("<!-- %2x -->",$buf[$n])
#              if($bHTML);

            my $c=int($buf[$n] & 0x7F); #Parity Bit ist uninteressant!

            if (($y==0)&&($x<8)) { # Die Daten sind uninteressant zur Anzeige!
               $c = 0x20;
            }

            if( $c >= 0x00 and $c <=  0x07 ) {
                        $lc=0x20
                          if($graph);
                        $hidden= 0;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);
                        $graph= 0;
                        $fg = int($c);

            } elsif( $c == 0x08 ) { # Blinken einschalten (flashing)
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);
                        $flash= 1;

            } elsif( $c == 0x09 ) { # Blinken ausschalten (steady)
                        $flash= 0;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);
            } elsif( $c == 0x0A ) { # end box (nicht benutzt)
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x0B ) { # start box (nicht benutzt)
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x0C ) { # normal high
                        $double= 0;
                        $lc=0x20;
                        $result .= $self->translate($bHTML, 0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x0D ) { # double high
#                     for (my $frei=1;$frei<40;$frei++)
#                          $result .= $self->translate($bHTML, $frei,$y+1,0x20,$graph,$double,$sepgraph,$fg,$bg);
#                       $result .= $self->endline($bHTML);

                        $result .= $self->translate($bHTML, 0x20,$graph,$double,$sepgraph,$fg,$bg);
                        $double= 1;
#                      $skipnextline= 1;

            } elsif( $c >= 0x0E and $c <=  0x0F ) { # keine Funktion

            } elsif( $c >= 0x10 and $c <=  0x17 ) { #
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);
                        $hidden= 0;
                        $graph= 1;
                        $fg = $c-0x10;

            } elsif( $c == 0x18 ) { # verborgen
                        $hidden= 1;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x19 ) { # contigouous graphics
                        $sepgraph= 0;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x1A ) { # separated grphics
                        $sepgraph= 1;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x1B ) { # ESC

            } elsif( $c == 0x1C ) { # black background
                        $bg = (0);
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x1D ) { # new background
                        my $tmp = $fg; # ExchangeColor
                        $fg = $bg;
                        $bg = $tmp;

                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x1E ) { # hold graphics
                        $hold= 1;
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);

            } elsif( $c == 0x1F ) { # release graphics
                        $result .= $self->translate($bHTML, ($hold == 1)?$lc:0x20,$graph,$double,$sepgraph,$fg,$bg);
                        $hold= 0;

            } else { #
                  if ($graph == 1) {
                      $lc = $c;
                  }
                  $result .= $self->translate($bHTML, $c,$graph,$double,$sepgraph,$fg,$bg);
            }
         }
         $result .= $self->endline($bHTML);
         if ($skipnextline==1) {
               $y++;
         }
    }
    $result .= "</p>\n" if($bHTML);
    return $result;
}

################################################################################
# Read TOC from packed file for index
sub GetPackedToc {

    my $filename = shift;
    my @index;
    my $fh = FileHandle->new;
    if(!$fh->open($filename)) {
        error ("Couldn't find page! : $filename");
    } else {
        # Parse TOC
        #
        # 8x[MAIN,SUB a 2x4byte],
        # 8x[PAGE a 972byte],
        # 8x[MAIN,SUB a 2x4byte],
        # 8x[PAGE a 972byte]
        #
        my $tocbuf;
        my $bEnd = 0;
        while(!$fh->eof() and    $bEnd == 0) {
            if($fh->read($tocbuf, 4*2*8) ne 64) {
                $bEnd = 1;
                last;
            }
            my @toc = unpack( "i*", $tocbuf);
            my $n = 0;
            for (;$n < 8; ++$n ) {
                my $m = (@toc[$n*2]);

                next # Skip nonregular pages like 80F
                    if($m =~ /\D/sig);

                my $mpage = int($m);
                my $spage = int(@toc[($n*2)+1]);

                # Check for last toc entry 0/0
                if($mpage == 0 and $spage == 0) {
                    $bEnd = 1;
                    last;
                }
                my $found = 0;
                foreach my $p (@index) {
                    if($p->[0] == $mpage) {
                        $found = 1;
                        push(@{$p->[1]},$spage)
                            if($spage != 0);
                        last;
                    }
                }
                if ($found == 0) {
                    push(@index,[$mpage, [$spage] ]);
                }
            }
            # Skip Pages
            if(0 == $fh->seek((972*8), 1)) {
                $bEnd = 1;
                last;
            }
        }

        $fh->close();
    }
    return @index;
}

################################################################################
# Callback "Teletextpage choice"
sub page {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift || "";


    my $channel;
    my $modC = main::getModule ('CHANNELS');
    $channel = $console->{cgi} && defined $console->{cgi}->param('channel') ? $modC->ToCID($console->{cgi}->param('channel')) : undef;
    my $page = $console->{cgi} && defined $console->{cgi}->param('page') ? $console->{cgi}->param('page') : undef;
    #my $subpage = $console->{cgi} && defined $console->{cgi}->param('subpage') ? $console->{cgi}->param('subpage') : undef;

    unless($channel) {
        $channel = $self->firstChannel();
    }
    unless($channel) {
        con_err($console,gettext("No channel defined!"));
        return;
    }

    if(!(defined $self->{$channel}) 
        || !defined($self->{$channel}->{INDEX}) 
        || !scalar @{$self->{$channel}->{INDEX}}
        || $self->{$channel}->{updated} < (time() - 300)) {
      $self->{$channel}->{INDEX} = $self->queryindex($channel);
      $self->{$channel}->{updated} = time();
    }
    unless($self->{$channel}->{INDEX} and scalar @{$self->{$channel}->{INDEX}}) {
      con_err($console,sprintf(gettext("No data found for \'%s\'!"), $modC->ChannelToName($channel)));
      return;
    }

    if (!$page) {
       # First Page on Index
       $page    = sprintf("%3X",@{$self->{$channel}->{INDEX}}[0]->[0]);
    }

    my $sum;
    my $bHTML = ($console->typ eq 'HTML' || $console->typ eq 'AJAX')?1:0;

    foreach my $fpage (@{$self->{$channel}->{INDEX}}) {
        if($fpage->[0] == hex($page)) {
            foreach my $subpage (@{$fpage->[1]}) {
              my $result = $self->realpage($channel, hex($page), hex($subpage) ,$bHTML);
              if($result) {
                my $row = $self->formatPage($result,$channel, $page, $subpage, 0);
                push(@$sum, $row);
              }
            }
            last;
        }
    }

    unless($sum and scalar @$sum) {
      con_err($console,gettext("Couldn't find page!"));
      return;
    }

    my $info = {
      rows => scalar @$sum
    };
    unless($console->typ eq 'AJAX') {
      $console->{dontparsedData} = 1;
      $info->{channels} = $self->queryChannels();
    }
    $console->table($sum, $info);
}

################################################################################
# Callback "Teletext search"
sub search {
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $search = shift;

    my $channel;
    my $modC = main::getModule ('CHANNELS');
    $channel = $console->{cgi} && defined $console->{cgi}->param('channel') ? $modC->ToCID($console->{cgi}->param('channel')) : undef;

    unless($channel) {
        $console->setCall('message');
        con_err($console,gettext("No channel defined!"));
        return;
    }

    chomp($search);
    unless($search) {
        con_err($console,gettext("No data to search given!"));
        return;
    }

    if(!(defined $self->{$channel}) 
        || !defined($self->{$channel}->{INDEX}) 
        || !scalar @{$self->{$channel}->{INDEX}}
        || $self->{$channel}->{updated} < (time() - 300)) {
      $self->{$channel}->{INDEX} = $self->queryindex($channel);
      $self->{$channel}->{updated} = time();
    }
    unless($self->{$channel}->{INDEX} and scalar @{$self->{$channel}->{INDEX}}) {
      con_err($console,sprintf(gettext("No data found for \'%s\'!"),$channel));
      return;
    }

    my @foundlist;
    my $searchlimit = 25;
    foreach my $p (@{$self->{$channel}->{INDEX}}) {
        foreach my $s (@{$p->[1]}) {
            my $lookup = $self->realpage($channel, $p->[0], $s ,0);
            my @found = grep(/$search/,$lookup);
            if(scalar @found > 0) {
                push(@foundlist,[sprintf("%3X",$p->[0]),sprintf("%02X",$s)]);
                $searchlimit--;
                last if($searchlimit <= 0);
            }
         }
         last if($searchlimit <= 0);
    }

    if(scalar @foundlist < 1) {
        con_err($console,sprintf(gettext("No page with \'%s\' found!"),$search));
        return 0;
    }

    my $sum;
    my $bHTML = ($console->typ eq 'HTML' || $console->typ eq 'AJAX')?1:0;
    my $result;
    foreach my $pp (@foundlist) {
      if($bHTML) {
        $result = $self->HighLight($self->realpage($channel, hex($pp->[0]), hex($pp->[1]) ,$bHTML),$search);
      } else {
        $result = $self->realpage($channel, hex($pp->[0]), hex($pp->[1]) ,$bHTML);
      }
      if($result) {
        my $row = $self->formatPage($result,$channel, $pp->[0], $pp->[1], 0);
        push(@$sum, $row);
      }
    }

    unless($sum and scalar @$sum) {
      con_err($console,gettext("Couldn't find page!"));
      return;
    }

    my $info = {
      rows => scalar @$sum
    };
    unless($console->typ eq 'AJAX') {
      $console->{dontparsedData} = 1;
      $info->{channels} = $self->queryChannels();
    }
    $console->setCall('vtxpage');
    $console->table($sum, $info);

    return 1;
}
1;

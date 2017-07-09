package XXV::MODULES::KEYWORDS;

use strict;
use Encode;
use Tools;

# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');

    my $args = {
        Name => 'KEYWORDS',
        Prereq => {
            'XML::Simple' => 'Easy API to maintain XML (esp config files)'
        },
        Description => gettext('This module manages keywords and tag within timer and recordings.'),
#       Status => sub{ $self->status(@_) },
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            tkeywords => {
                description => gettext("Search timers 'keywords'"),
                short       => 'tk',
                callback    => sub{ $self->timer_keywords(@_) },
                DenyClass   => 'tlist',
            },
            tsuggestkeywords => {
                hidden      => 'yes',
                callback    => sub{ $self->suggest('timer',@_) },
                DenyClass   => 'tlist',
            },
            rkeywords => {
                description => gettext("Search recordings 'keywords'"),
                short       => 'rk',
                callback    => sub{ $self->recording_keywords(@_) },
                DenyClass   => 'rlist',
            },
            rsuggestkeywords => {
                hidden      => 'yes',
                callback    => sub{ $self->suggest('recording',@_) },
                DenyClass   => 'rlist',
            }
        }
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

    $self->{xml} = XML::Simple->new( NumericEscape => 2 )
        || return error("Can't create XML instance!");

    # The Initprocess
    my $erg = $self->_init or return error('Problem to initialize modul!');

    return $self;
}

# ------------------
sub _init {
# ------------------
    my $self = shift || return error('No object defined!');

    unless($self->{dbh}) {
      panic("Session to database is'nt connected");
      return 0;
    }

    my $version = 30; # Must be increment if rows of table changed
    # this tables hasen't handmade user data,
    # therefore old table could dropped if updated rows
    if(!tableUpdated($self->{dbh},'KEYWORDS',$version,1)) {
        return 0;
    }

    # Look for table or create this table
    $self->{dbh}->do(qq|
      CREATE TABLE IF NOT EXISTS KEYWORDS (
          id int(11) NOT NULL auto_increment,
          hash varchar(32) NOT NULL,
          keyword varchar(128) NOT NULL,
          rank tinyint NOT NULL,
          total tinyint NOT NULL,
          source enum('recording', 'timer'),
          PRIMARY KEY  (id),
          UNIQUE KEY  (hash,keyword)
        ) COMMENT = '$version'
    |);



    1;
}

# ------------------
sub insert {
# ------------------
    my $self = shift || return error('No object defined!');
    my $type = shift || return error('No type defined!');
    my $id = shift || return undef;
    my $keywords = shift || return undef;

    return unless($self->{active} eq 'y');

    my $sth = $self->{dbh}->prepare(qq|REPLACE INTO KEYWORDS(hash, keyword, rank, total, source ) VALUES (?,?,?,?,?)|);
    my @words = split(/[,;\r\n]/, $keywords);
    my $total = scalar @words;
    my $rank = $total + 1;
    foreach my $w (@words) {
      $rank --;
      $w =~ s/^\s+//;  # no leading white space
      $w =~ s/\s+$//;  # no trailing white space
      next unless($w);
      if(!$sth->execute($id,$w,$rank,$total,$type)) {
        error sprintf("Couldn't insert keyword!: '%s' !",$w);
        return undef;
      }
    }
   return 1;
}

# ------------------
sub remove {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $type = shift || return error('No type defined!');
    my $hash = shift || return undef;

    return unless($self->{active} eq 'y');

    my $sql = sprintf('DELETE FROM KEYWORDS WHERE hash IN (%s)', join(',' => ('?') x @$hash)); 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute(@$hash)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return 1;
}

# ------------------
sub removesource {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $type = shift || return error('No type defined!');

    return unless($self->{active} eq 'y');

    my $sth = $self->{dbh}->prepare('DELETE FROM KEYWORDS WHERE source = ?');
    $sth->execute($type)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return 1;
}

# ------------------
sub suggest {
# ------------------
    my $self = shift  || return error('No object defined!');
    my $type = shift || return error('No type defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $search = shift;
    my $params  = shift;

    if($search) {
      my $sth = $self->{dbh}->prepare(
qq|SELECT SQL_CACHE keyword from KEYWORDS 
    WHERE source = ?
      AND keyword LIKE ? 
 GROUP BY keyword 
 LIMIT 25|);
      if(!$sth->execute($type, '%'.$search.'%')) {
        error sprintf("Couldn't execute query: %s.",$sth->errstr);
      } else {
        my $result = $sth->fetchall_arrayref();
        $console->table($result)
            if(ref $console && $result);
      }
    }

}

# ------------------
sub list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $type = shift || return error('No type defined!');
    my $hash = shift;

    return (undef,0,0) unless($self->{active} eq 'y');

    # Get keywords with highest ranking
    my $list = $self->_list($type,$hash);
    return (undef,0,0) unless($list and scalar @$list);
    # Remember highest and lowest ranking for scaling
    my $keywordmax = $list->[0]->[1];
    my $keywordmin = $list->[-1]->[1];
    # sort keyworks by name
    my $keywords;
    @{$keywords} = sort {$a->[0] cmp $b->[0]} @$list;

    return ($keywords,$keywordmax,$keywordmin);
}

# ------------------
sub _list {
# ------------------
    my $self = shift || return error('No object defined!');
    my $type = shift || return error('No type defined!');
    my $hash = shift;
    my $sth;
    if($hash and ref $hash eq 'ARRAY') {
      my $sql = sprintf(qq|SELECT SQL_CACHE keyword,sum(100/total*rank) as pos 
 FROM KEYWORDS 
 WHERE source = ? AND hash IN (%s) 
 GROUP BY keyword 
 ORDER BY pos desc 
 LIMIT 20|, join(',' => ('?') x @$hash)); 
      unshift(@$hash,$type);
      $sth = $self->{dbh}->prepare($sql);
      $sth->execute(@$hash)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    } else {
      my $sql = qq|SELECT SQL_CACHE keyword,sum(100/total*rank) as pos
 FROM KEYWORDS 
 WHERE source = ?
 GROUP BY keyword 
 ORDER BY pos desc 
 LIMIT 20|; 
      $sth = $self->{dbh}->prepare($sql);
      $sth->execute($type)
          or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    }
    my $result = $sth->fetchall_arrayref();
    return $result;
}

# ------------------
sub timer_keywords {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text    = shift; 
    my $params  = shift;

    my $tmod = main::getModule('TIMERS');
    unless($text) {
      return $tmod->list($console,$config);
    }

	  my $term;
	  my $search;
    my $query = buildsearch("k.keyword",$text);
    $search = sprintf('AND ( %s ) AND ( t.id = k.hash )', $query->{query});
    foreach(@{$query->{term}}) { push(@{$term},$_); }

    return $tmod->_list($console,$config,$search,$term,$params,', KEYWORDS as k');
}

# ------------------
sub recording_keywords {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text    = shift; 
    my $params  = shift;

    my $rmod = main::getModule('RECORDS');
    unless($text) {
      return $rmod->list($console);
    }

    my $query = buildsearch("k.keyword",$text);
    return $rmod->_search($console,$config,$query->{query}.' ) AND ( r.hash = k.hash ',$query->{term},$params,', KEYWORDS as k');
}

# ------------------
sub parsexml {
# ------------------
    my $self = shift || return error('No object defined!');
    my $aux = shift;

    $aux  =~ s/(\r|\n)//sg;
    if($aux && $aux =~ /^<.*/ ) {
      my $args = eval {  $self->{xml}->XMLin($aux, KeepRoot => 1 ) } ;
      if ($@) {
        if($Tools::VERBOSE >= 4) {
          error sprintf("Can't parse xml data : %s - %s", $@, $aux);
        } elsif($Tools::VERBOSE >= 2) {
          error ("Can't parse xml data");
        }
        return  undef;
      } 
      if(defined $args 
        && defined $args->{'xxv'} ) {
          if($self->{charset} eq 'UTF-8'){
            foreach my $k (keys %{$args->{'xxv'}}) {
              utf8::downgrade($args->{'xxv'}->{$k});
            }
          } else {
            foreach my $k (keys %{$args->{'xxv'}}) {
              $args->{'xxv'}->{$k} = encode($self->{charset},$args->{'xxv'}->{$k});
            }
          }
          return $args->{'xxv'};
      }
    }
    return  undef;
}

# ------------------
sub createxml {
# ------------------
    my $self = shift || return error('No object defined!');
    my $xml = shift;

    my $aux = '';
    if($xml && keys %$xml) {
      $aux = $self->{xml}->XMLout($xml, RootName => 'xxv');
    }
    return $aux; 
}

# ------------------
sub mergexml {
# ------------------
    my $self = shift || return error('No object defined!');
    my $aux = shift;
    my $topic = shift;
    my $value = shift;

    my $xml = $self->parsexml($aux);
    if($value) {
#     utf8::upgrade($value) if(!utf8::is_utf8($value));
      $xml->{$topic} = $value;
    } elsif($xml->{$topic}) {
      delete $xml->{$topic};
    }
    return $self->createxml($xml);
}
1;

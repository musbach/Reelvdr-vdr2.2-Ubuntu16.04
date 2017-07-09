package Tools;

@ISA = qw(Exporter);

use FindBin qw($RealBin);
use lib sprintf("%s", $RealBin);
use lib sprintf("%s/../lib", $RealBin);
use Locale::gettext qw/!gettext/;
use Encode;

use Data::Dumper;
$Data::Dumper::Indent = 1;
#$Data::Dumper::Maxdepth = 2;

use IO::File;
use File::Basename;
use File::Find;
use Socket;
use Time::HiRes qw( gettimeofday );
use POSIX qw(strftime);

our $DUMPSTACK  = 0;
our $VERBOSE    = 3;
our $LOG        = sub{ warn @_ };
our $BENCH      = {};
our $LOGCALLB   = sub{ };
our $DBH        = {};
our $LOCALE;
our $CHARSET;
our $LANGUAGE   = "C";

# PAL use 25, NTFS use 30 frames per seconds
use constant FRAMESPERSECOND => 25; 

@EXPORT = qw(&datum &stackTrace &lg &event &debug &error &panic &rep2str &dumper 
 &getFromSocket &fields &load_file &save_file &tableUpdated &buildsearch 
 &deleteDir &getip &convert &int &entities &reentities &bench &fmttime 
 &getDataByTable &getDataById &getDataBySearch &getDataByFields &touch &url
 &con_err &con_msg &text2frame &frame2hms &gettext &setcharset &resolv_symlink
 &connectDB &findttf
);


# ------------------
sub fmttime {
# ------------------
    my $tim = shift  || 0;
    return $tim if(index($tim, ':') > -1);

    my $value = sprintf('%04d',$tim);
    my $ret = sprintf('%02d:%02d', substr($value, 0, 2), substr($value, 2, 2));
    return $ret;
}

use constant MONTHS => qw/Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec/;
use constant WEEKDAYS => qw/Sun Mon Tue Wed Thu Fri Sat/;
# ------------------
sub datum {
# ------------------
    my $zeit = shift  || time;
    my $typ  = lc(shift)  || 'voll';

    if($typ eq 'voll') {
        # full date depends locale e.g. 24.12.2007 12:00:00 or 12/24/2007 ...
        return strftime("%x %X", localtime($zeit)); 
    } elsif($typ eq 'short') {
        # short date depends locale e.g. 24.12.2007 12:00 or 12/24/2007 ...
        return strftime("%x %H:%M", localtime($zeit)); 
    } elsif($typ eq 'tag') {
        # day depends locale e.g. 24.12.2007 or 12/24/2007
        return strftime("%x", localtime($zeit));   
    } elsif($typ eq 'weekday') {
        # day depends locale e.g. Fryday ,24.12.2007
        return strftime("%A, %x", localtime($zeit));   
    } elsif ($typ eq 'int') {
        # 1901-01-01T00:00+00:00
        return strftime("%Y-%m-%dT%H:%M:%S%z", localtime($zeit));
    } elsif ($typ eq 'rss') {
        # 23 Aug 1999 07:00:00 GMT
        my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = gmtime($zeit);
        return sprintf('%02d %s %04d %02d:%02d:%02d GMT',
            $mday, (MONTHS)[$mon], $year+1900, $hour, $min, $sec );
    } elsif ($typ eq 'header') {
        my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = gmtime($zeit);
        return sprintf("%s, %02d %s %04d %02d:%02d:%02d GMT",
            (WEEKDAYS)[$wday],$mday,(MONTHS)[$mon],$year + 1900,$hour,$min,$sec);
    } else {
        # time depends locale, most 07:00:00
        return strftime("%X", localtime($zeit));   
    }
}

#returns a string containg the stacktrace
# ------------------
sub stackTrace {
# ------------------
    my $result;
    my $s;
    my $n = 0;
    my @res;
    do {
        my ($package, $filename, $line, $subroutine) = caller($n++);
        if($filename) {
            $s = sprintf("%s:%s (%s)", $filename||"", $line||"", $subroutine||"");
            push(@res, $s);
        } else {
            $s = 0;
        }
    } while ($s);

    my $evalon = 0;
    $evalon = 1
        if(scalar @res > 4
            and $res[4] =~ /\(eval\)/si
            and $res[4] !~ /XXV/si);

    $result .= "\n=========== top of stack =========\n";
    $result .= join("\n   ", @res);
    $result .= "\n=========== end of stack =========\n\n";
    return ($result, $evalon);
}

# ------------------
sub _msg {
# ------------------
    my $errcode = shift;
    my $msg = shift;
    my $lev = shift || 5;

    return if($VERBOSE < $lev);

    if($VERBOSE > 5 or $DUMPSTACK) {
        my ($stack, $evalon) = &stackTrace;
        $msg .= $stack if($evalon != 1);
    }

    my ($package, $filename, $line, $subroutine) = caller(2);

    my  $module = '';
        $module = (split('::', $package))[-1]
            if($package);

    &{$LOG}($errcode, $module . ': ' . $msg);
}

# ------------------
sub lg {
# ------------------
    my $msg = shift;
    &_msg(200,$msg, 5);
    return undef;
}

# ------------------
sub debug {
# ------------------
    my $msg = shift;
    &_msg(250,$msg, 4);
    return undef;
}

# ------------------
sub event {
# ------------------
    my $msg = shift;

    my ($package, $filename, $line, $subroutine) = caller(1);
    my  $module = '';
        $module = (split('::', $package))[-1]
            if($package);
    &{$LOGCALLB}($module, $subroutine, $msg);

    &_msg(270,$msg, 3);
    return undef;
}

# ------------------
sub error {
# ------------------
    my $msg = shift;

    &_msg(501,$msg, 2);

    return undef;
}

# ------------------
sub panic {
# ------------------
    my $msg = shift;

    &_msg(550,$msg, 1);

    return undef;
}

# ------------------
sub con_err {
# ------------------
    my $console = shift;
    my $msg = shift;

    if(ref $console) {
      $console->setCall('message'); #reset default widget, avoid own widget
      $console->err($msg);
    }

    if(ref $msg eq 'ARRAY') {
      $msg = join("\n", @$msg);
    }

    &_msg(501,$msg, 2);


    return undef;
}

# ------------------
sub con_msg {
# ------------------
    my $console = shift;
    my $msg = shift;

    if(ref $console) {
      $console->setCall('message'); #reset default widget, avoid own widget
      $console->msg($msg);
    }

    if(ref $msg eq 'ARRAY') {
      $msg = join("\n", @$msg);
    }

    &_msg(250,$msg, 4);

    return undef;
}

# ------------------
sub getFromSocket {
# ------------------
    my $sock = shift or return undef;

    my (@Data, $Line);
    my $len = 0;

  	do {
	  	$Line = <$sock> || 0;
          $len += length($Line);
	  	$Line =~ s/\r\n//g;
	  	push(@Data, $Line);
	  } while($Line);

    return (\@Data, $len);
}


# ------------------
sub rep2str {
# ------------------
    my %args = @_;
    my $text = $args{-text};
    $text =~ s/\<(.+?)\>/$args{"-$1"}/sig;
    return $text;
}

# ------------------
sub dumper {
# ------------------
    my $var = shift || '<undef>';
    my $args = @_;

    $Data::Dumper::Maxdepth = $args->{d}
        if($args->{d});
    $Data::Dumper::Indent = $args->{i}
        if($args->{d});

    debug Dumper( $var );
}

# ------------------
sub fields {
# ------------------
    my $dbh = shift || return error('No database handle defined!');
    my $str = shift || return error('No sql query defined!');

    $str =~ s/order\s+by.+//sig;
    my $sql = sprintf('%s %s 0 = 1', $str, ($str =~ /where/i ? 'AND' : 'WHERE'));
		my $sth = $dbh->prepare($sql) or return error("$DBI::errstr - $sql");
		$sth->execute or return error("$DBI::errstr - $sql");
		my $fields = $sth->{'NAME'};
    return $fields;
}

# ------------------
sub tableExists {
# ------------------
    my $dbh = shift || return error('No database handle defined!');
    my $name = shift || return error('No table defined!');

    my $erg = $dbh->selectall_arrayref("show tables LIKE '$name'");
    for(@$erg) {
        return 1 if($name eq $_->[0]);
    }
    return 0;
}

# ------------------
sub tableStatus {
# ------------------
    my $dbh = shift || return error('No database handle defined!');
    my $table = shift || return error('No table defined!');
    my $row = shift || return error('No row defined!');

    my $erg = $dbh->selectrow_hashref("SHOW TABLE STATUS LIKE '$table'");
    if($erg and exists $erg->{$row}) {
			return $erg->{$row};
    }
		return 0;
}

# ------------------
sub tableUpdated {
# ------------------
    my $dbh = shift || return error('No database handle defined!');
    my $table = shift || return error('No table defined!');
    my $dbversion = shift || return error('No version of database defined!');
    my $drop = shift || 0;

    # remove old Version, if updated
    if(tableExists($dbh, $table)) {
        my $tableversion = tableStatus($dbh, $table,'Comment');
        if(!$tableversion || $tableversion ne $dbversion) {
            if($drop) {
              lg sprintf('Remove old version from database table %s',$table);
              $dbh->do(sprintf('drop table %s',$table))
                  or return panic sprintf("Couldn't drop table %s - %s",$table, $DBI::errstr);
            } else {
              panic sprintf(
q|------- !PROBLEM! ----------
Upps, you have a incompatible or corrupted database.
Table %s has version '%s'. It's expected version '%s'.
Please check database e.g. with mysqlcheck --all-databases --fast --silent
or use the script contrib/update-xxv to upgrade the database!
----------------------------|#'
                    ,$table
                    ,$tableversion ? $tableversion : 0
                    ,$dbversion);
              return 0;
            }
        }
    }
    return 1;
}

#--------------------------------------------------------
sub load_file {
#--------------------------------------------------------
	my $file = shift || return error('No file defined!');
	my $binmode = shift || 'text';

  lg sprintf('Load file "%s" (%s)',$file, $binmode);

  my $mode = '<';
  #if($binmode ne 'binary') {
  #  $mode .= ':encoding(utf8)' if($CHARSET && $CHARSET eq 'UTF-8');
  #}

  my $fh = IO::File->new($file,$mode) 
	    or return error(sprintf("Couldn't open %s : %s!",$file,$!));
	my $data;
	while ( defined (my $l = <$fh>) ) {
	        $data .= $l;
	}
	$fh->close;
	return $data;
}

#--------------------------------------------------------
sub save_file {
#--------------------------------------------------------
	my $file = shift || return error('No file defined!');
	my $data = shift || '';
	my $binmode = shift || 'text';

  return unless($file);

  lg sprintf('Save file %s(%s)',$file,convert(length($data)));
  my $mode = '>';

  if($binmode ne 'binary') {
    $data =~ s/\r\n/\n/sig;
  #  $mode .= ':encoding(utf8)' if($CHARSET && $CHARSET eq 'UTF-8');
  }

  my $fh = IO::File->new($file,$mode) 
    or return error(sprintf("Couldn't write %s : %s!",$file,$!));

  print $fh $data;
  $fh->close;

  return $file
}


#--------------------------------------------------------
sub _buildsearchcomma {
#--------------------------------------------------------
    my ($queryField, $Search) = @_;

    my $term;
    my $out;
    foreach my $su (split(/\s*,\s*/, $Search)) {
    $su =~ s/\./\\\./sg;
#   $su =~ s/\*/\\\*/sg;
    $su =~ s/\+/\\\+/sg;
    $su =~ s/\?/\\\?/sg;
    $su =~ s/\(/\\\(/sg;
    $su =~ s/\)/\\\)/sg;

    $su =~ s/\*/\.*/sg;
    # Search strings to paragraphs like Cast:ABC  => 'Cast:[^:]*ABC';
    if($queryField =~ /description/) {
      $su =~ s/\:/\:\[\^\:\]\*/;
    }

    $out .= ' AND ' if($out);
    if($su =~ s/^\-+//) {
        $out .= qq| ($queryField NOT RLIKE ?)|;
        push(@$term,$su);
    } else {
        $su =~ s/^\&+//; #remove for backward compatibility
        $out .= qq| ($queryField RLIKE ?)|;
        push(@$term,$su);
    }
  }

  return {
    query => $out,
    term => $term    
  };
}

#--------------------------------------------------------
sub _buildsearchlogical {
#--------------------------------------------------------
  my ($queryField, $Search) = @_;

  my $out;
  my $term;
  my $op = 1;
  $out = " (";
  foreach my $su (split(/( AND NOT | OR | AND )/, $Search)) {
   
      if($su eq " AND ") {
        $out .= " AND" unless($op);
        $op = 1;
      } elsif($su eq " OR ") {
        $out .= " OR" unless($op);
        $op = 1;
      } elsif($su eq " AND NOT ") {
        $out .= " AND NOT" unless($op);
        $op = 1;
      } else {
        $out .= " AND" unless($op);
      
        $su =~ s/\./\\\./sg;
#       $su =~ s/\*/\\\*/sg;
        $su =~ s/\+/\\\+/sg;
        $su =~ s/\?/\\\?/sg;
        $su =~ s/\(/\\\(/sg;
        $su =~ s/\)/\\\)/sg;

        $su =~ s/\*/\.*/sg;
        # Search strings to paragraphs like Cast:ABC  => 'Cast:[^:]*ABC';
        if($queryField =~ /description/) {
          $su =~ s/\:/\:\[\^\:\]\*/;
        }

        $out .= qq| ($queryField RLIKE ?)|;
        push(@$term,$su);
        $op = 0;
      }
  }
  $out .= " )";

  return {
    query => $out,
    term => $term    
  };
}


#--------------------------------------------------------
sub buildsearch {
#--------------------------------------------------------
    my ($InFields, $Search) = @_;
    my @fields = split(/\s*,\s*/, $InFields);
    my $queryField = scalar(@fields) > 1 ? qq|CONCAT_WS(" ",$InFields)| : qq|$InFields|;

    if( grep(/ AND /, $Search) 
        or grep(/ OR /, $Search) 
        or grep(/ NOT /, $Search)) {
    return _buildsearchlogical($queryField, $Search);
  } else {
    return _buildsearchcomma($queryField, $Search);
  }
}
# ------------------
sub deleteDir {
# ------------------
    my $dir = shift || return;

    lg sprintf('Delete directory "%s" in the system',
            $dir,
        );

    foreach my $file (glob(sprintf('%s/*', $dir))) {
        deleteDir($file)
            if(-d $file);
        unlink $file;
    }
    rmdir $dir;
    return 1;
}

# ------------------
sub getip {
# ------------------
    my $handle = shift  || return error('No handle defined!');
    my $p = getpeername($handle)
        or return;
    my($port, $iaddr) = unpack_sockaddr_in($p);
    my $ip = inet_ntoa($iaddr);

    return $ip;
}

# ------------------
# Name:  getDataByTable
# Descr: universal routine to get data by table
# Usage: my $hash = $obj->getDataByTable('TABLE', ['ID']);
# ------------------
sub getDataByTable {
    my $table = shift || return error('No table defined!');
    my $key = shift;
    unless($key) {
      my $erg = &fields($DBH, 'select * from '.$table)
          or return error sprintf("Couldn't execute query: %s.",$DBI::errstr);
      $key = $erg->[0];
    } 

    my $sth = $DBH->prepare(sprintf('select * from %s',$table));
    $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return $sth->fetchall_hashref($key);
}


# ------------------
# Name:  getDataById
# Descr: universal routine to get data by id from table
# Usage: my $hashrow = $obj->getDataById(123, 'TABLE', ['ID']);
# ------------------
sub getDataById {
    my $id = shift  || return error('No id defined!');
    my $table = shift || return error('No table defined!');
    my $key = shift  || &fields($DBH, 'select * from '.$table)->[0];

    my $sth = $DBH->prepare(sprintf('select * from %s where %s = ?',$table, $key));
    $sth->execute($id)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return $sth->fetchrow_hashref();
}

# ------------------
# Name:  getDataBySearch
# Descr: universal routine to get data by search from table
# Usage: my $arref = $obj->getDataBySearch('TABLE', 'ID = ?', 'ID');
# ------------------
sub getDataBySearch {
    my $table = shift || return error('No table defined!');
    my $search = shift || return error('No sql query defined!');
    my $data = shift || return error('No sql data defined!');

    my $sth = $DBH->prepare(sprintf('select * from %s where %s',$table, $search));
    $sth->execute($data)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
    return $sth->fetchall_arrayref();
}

# ------------------
# Name:  getDataByFields
# Descr: universal routine to get data by fields from table
# Usage: my $arref = $obj->getDataBySearch('TABLE', 'ID', ['WHERE']);
# ------------------
sub getDataByFields {
    my $table = shift || return error('No table defined!');
    my $field = shift || '*';
    my $where = shift || '';

    my $sql = sprintf('select %s from %s %s',
                $field, $table, ($where ? 'where '.$where : '')
                );
    my $erg = $DBH->selectcol_arrayref($sql);
    return $erg;
}


# Takes kilobytes and formats for MB and GB if necessary
sub convert {
    my $kbytes = $_[0] / 1024;
    my $result = 0;

    if ( $kbytes > 1048576 ) {
        $result = sprintf("%.2f", $kbytes / 1048576);
        $result .= " GiB";
    } elsif ( $kbytes > 1024 ) {
        $result = sprintf("%.2f", $kbytes / 1024);
        $result .= " MiB";
    } else {
        $result = sprintf("%.2f", $kbytes);
        $result .= " kiB";
    }

    return $result;
}

# ------------------
sub int {
# ------------------
    my $var = shift  || return 0;
    $var =~ s/[^0-9\.\,\-\+]//sig;
    return CORE::int($var);
}

# ------------------
sub entities {
# ------------------
    my $s = shift || return '';

    $s =~ s/&/&amp;/g;
    $s =~ s/>/&gt;/g;
    $s =~ s/</&lt;/g;
    $s =~ s/\"/&quot;/g;
    if($CHARSET eq 'UTF-8') {
      $s =~ s/(\~)/sprintf("&#x%02x;",ord($1))/eg;
    } else {
      $s =~ s/([^a-zA-Z0-9&%;:,\.\!\?\(\)\_\|\'\r\n ])/sprintf("&#x%02x;",ord($1))/eg;
    }
    $s =~ s/\r\n/<br \/>/g;

    return $s;
}

# ------------------
sub reentities {
# ------------------
    my $s = shift || return '';

    $s =~ s/\&\#x([a-fA-F0-9][a-fA-F0-9])\;/pack("C", hex($1))/eg;
    $s =~ s/&amp;/&/g;
    $s =~ s/&gt;/>/g;
    $s =~ s/&lt;/</g;
    $s =~ s/&quot;/\"/g;
    $s =~ s/<br \/>/\r\n/g;
    return $s;
}



# ------------------
sub bench {
# ------------------
    my $tag = shift || return $BENCH;

    return $BENCH = {}
        if($tag eq 'CLEAR');

    if(! $BENCH->{$tag} or $BENCH->{$tag} < 1000) {
        $BENCH->{$tag} = scalar gettimeofday;
    } else {
        $BENCH->{$tag} = scalar gettimeofday - $BENCH->{$tag};
    }
}

# ------------------
sub touch {
# ------------------
    my $file    = shift;
    my $now     = time;
    local (*TMP);

    lg sprintf("Call touch file '%s'", $file );
    utime ($now, $now, $file)
        || open (TMP, ">>$file")
        || error sprintf("Couldn't touch '%s' : %s",$file,$!);
}

# ------------------
sub url{
# ------------------
  	my $s = shift; # string
    $s  =~ s/([^a-z0-9A-Z])/sprintf('%%%X', ord($1))/seg;
    return $s;
}

################################################################################
# Convert text to frame number
# in => frame / HH:MM:SS.FF / HH:MM:SS / MM:SS.FF / MM:SS
# out => frame
sub text2frame() {
    my $s = shift;

    my $start = 0;
    if($s =~ /^\d+$/sig) {
      $start = $s;
    } elsif($s =~ /^\d+\:\d+\:\d+\.\d+$/sg) {
      my ($hour,$minute,$seconds,$frames) = $s =~ /(\d+)\:(\d+)\:(\d+)\.(\d+)/s;
      $start = ($hour * 3600) + ($minute * 60) + $seconds;
      $start *= FRAMESPERSECOND;
      $start += $frames;
    } elsif($s =~ /^\d+\:\d+\:\d+$/sg) {
      my ($hour,$minute,$seconds) = $s =~ /(\d+)\:(\d+)\:(\d+)/s;
      $start = ($hour * 3600) + ($minute * 60) + $seconds;
      $start *= FRAMESPERSECOND;
    } elsif($s =~ /^\d+\:\d+\.\d+$/sg) {
      my ($minute,$seconds,$frames) = $s =~ /(\d+)\:(\d+)\.(\d+)/s;
      $start = ($minute * 60) + $seconds;
      $start *= FRAMESPERSECOND;
      $start += $frames;
    } elsif($s =~ /^\d+\:\d+$/sg) {
      my ($minute,$seconds) = $s =~ /(\d+)\:(\d+)/s;
      $start = ($minute * 60) + $seconds;
      $start *= FRAMESPERSECOND;
    }
    return $start;
}

################################################################################
# Convert frame number to HMS Text
# in => frame
# out => HH:MM:SS.FF
sub frame2hms() {
    my $frames = shift;

    my $frame = $frames % FRAMESPERSECOND;
    my $time = $frames / FRAMESPERSECOND;
    my $sec  = $time % 60;
    my $min  = ($time / 60) % 60;
    my $hour = CORE::int($time/3600);

    return sprintf('%d:%02d:%02d.%02d', $hour, $min, $sec, $frame); 
}

sub setcharset {
    $CHARSET = shift;
    $LANGUAGE = shift;
}

################################################################################
# Translate text 
sub gettext($) {
    my $text = shift;

    unless($LOCALE) {
        $LOCALE = Locale::gettext->domain_raw("xxv");
        $LOCALE->codeset($CHARSET);
    }
    if($CHARSET eq 'UTF-8') {
      return $LOCALE->get($text);
    } else {
      $text = $LOCALE->get($text);
      return encode($CHARSET,$text);
    }
}
################################################################################
# dereference symbolic link to real filename 
sub resolv_symlink($) {
  my $file = shift;

  my @f = split (m|/|, $file); #split file by path /
  my $deep = 0;
  for(my $n = 0; $n <= $#f; ++$n) {
      my $k = join ("/", @f[0 .. $n]);
      my $orig = $k;
      while(my $l = readlink ($k)) {
          $k = $l;
          if ($deep++ == 64) {
              error sprintf ("File %s has too many levels of symbolic links" , $file);
              return undef;
            }
      }
      next if($k eq $orig);
      if(substr ($k, 0, 1) eq "/") {
          splice(@f, 0, $n + 1, split (m|/|, $k));
          $n = -1;
      } else {
          splice(@f, $n, 1, split(m|/|, $k));
          $n--;
      }
    }
  return join("/", @f);
}

# ------------------
sub connectDB {
# ------------------
    my $dsn = shift || return error('No database parameter defined!');
    my $usr = shift || return error('No user defined!');
    my $pwd = shift || '';
    my $charset = shift || return error('No charset defined!');

    $dsn =~ s/^\s+//;
    $dsn =~ s/\s+$//;

    my $dbh = DBI->connect($dsn, $usr, $pwd,{
                      PrintError => 1,
                      AutoCommit => 1,
#                     mysql_enable_utf8 => (($charset =~ m/UTF-8/) ? 1 : 0),
                      mysql_auto_reconnect => 1
            });

    if($dbh) {
      debug sprintf('Connect to database: %s successful.', $dsn);

	    my $NAMES = {
	      'UTF-8' => 'utf8',
	      'ISO-8859-1' => 'latin1',
	      'ISO-8859-2' => 'latin2',
	      'ISO-8859-5' => 'latin5',
	      'ISO-8859-7' => 'latin7',
	      'ISO-8859-15' => 'latin1',
  		};
      my $n = $NAMES->{$charset} || 'latin1';
      if (!($dbh->do("set character set '" . $n . "'"))) {
          error sprintf("Could not set charset: %s : %s", $n, $DBI::errstr);
      }
    } else {
        panic sprintf("Could not connect to database: %s :", $dsn, $DBI::errstr);
        return 0;
    }

    return $dbh;
}

# ------------------
# Find usable fonts for graphical outputs
sub findttf
{
  my $directory = shift || return error('No fonts directory defined!');
  my $found;
  my $font;
  eval 'use Font::TTF::Font';
  unless($@)  {
    $font = 1;
  }
  find({ wanted => sub{
        if($File::Find::name =~ /\.ttf$/sig) {
          my $f = $_; # keep name of file without path
          my $fontname = $f;
          if($font) {
            $fontname = Font::TTF::Font->open($File::Find::name) || $f;
            $fontname = $fontname->{name} || $f if ref $fontname;
            $fontname = $fontname->read->find_name(4) || $f if ref $fontname;
          }
          push(@{$found},[$fontname,$f]);
        }
      }
    },
  $directory
  );
  error "Couldn't find useful font at : $directory"
    if(scalar $found == 0);
  return $found;
}

1;

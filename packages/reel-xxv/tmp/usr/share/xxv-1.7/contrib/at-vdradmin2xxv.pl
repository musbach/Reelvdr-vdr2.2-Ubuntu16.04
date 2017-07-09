#!/usr/bin/perl -w
use strict;
use warnings;
use DBI; #Database independent interface for Perl
use DBD::mysql; #MySQL driver for the Perl5 Database Interface (DBI)
use Getopt::Std;

my $db = "xxv";
my $host = "localhost";
my $port = "3306";
my $usr = "root";
my $pwd = "";


my $Usage = qq{
Import or Export Autotimer from XXV to or from a VDRAdmin file
Usage: $0 [options] file

Options:
          -H <hostname>  : Host name of the MySQL server (default: '$host')
          -P <port>      : Port number of MySQL server (default: '$port')
          -d <database>  : XXV database name (default: '$db')
          -u <user>      : Username (default: '$usr')
          -p <password>  : Password (default: '$pwd')
          -e             : Export to file (default: Import from file)
          -h             : Help

};

use vars qw/ %opt /;
my $dbh;

die $Usage if (!$ARGV[0] || !getopts("d:H:P:u:p:eh", \%opt) || $opt{h} );


$db   = $opt{d} if($opt{d});
$host = $opt{H} if($opt{H});
$port = $opt{P} if($opt{P});
$usr =  $opt{u} if($opt{u});
$pwd =  $opt{p} if($opt{p});

my $filename  = "@ARGV";

# ------------------
sub ChannelArray {
# ------------------
    my $field = shift || return undef;
    my $sql = sprintf('select %s, POS from CHANNELS order by POS', $field);
    my $erg = $dbh->selectall_arrayref($sql);
    return $erg;
}

# ------------------
sub PosToChannel {
# ------------------
    my $pos = shift || return undef;
    my $sql = sprintf('select Id from CHANNELS where POS = "%lu"', $pos);
    my $erg = $dbh->selectall_arrayref($sql);
    return $erg->[0][0];
}

# ------------------
sub _insert {
# ------------------
    my $data = shift || return;

    if(ref $data eq 'HASH') {
        my ($names, $vals, $kenn);
        map {
            push(@$names, $_);
            push(@$vals, $data->{$_}),
            push(@$kenn, '?'),
        } sort keys %$data;

        my $sql = sprintf("REPLACE INTO AUTOTIMER (%s) VALUES (%s)",
                join(', ', @$names),
                join(', ', @$kenn),
        );
        my $sth = $dbh->prepare( $sql );
        $sth->execute( @$vals );
    } else {
        my $sth = $dbh->prepare('REPLACE INTO AUTOTIMER VALUES (?,?,?,?,?,?,?,?,?)');
        $sth->execute( @$data );
    }
}

# ------------------
# Name:  autotimerimport
# Descr: Read a file for import autotimer export list.
# Usage: autotimerimport($filename);
# ------------------
sub autotimerimport {
    my $AT_FILENAME = shift || die("No filename to import! Use $0 'vdradmind.at'\n");

    my $cnt = "0";
    open(AT_FILE, "$AT_FILENAME") || return die sprintf("Can't open file '%s' : %s\n",$AT_FILENAME,$!);
    while(<AT_FILE>) {
        chomp;
        next if ($_ eq "");

        my($active, $pattern, $section, $start, $stop, $episode, $prio,
            $lft, $channel, $directoy) = split(/\:/, $_);

        my $data;
        $data->{Id} = 0;
        if($active eq "1") { $data->{Activ} = 'y'; }
	      else               { $data->{Activ} = 'n'; }

        my @vals;
        $data->{Done} = 'timer';
        $data->{Search} = $pattern;
        push(@vals, "title")
            if($section & 1);
        push(@vals, "subtitle")
            if($section & 2);
        push(@vals, "description")
            if($section & 4);
        $data->{InFields} = join(',', @vals);
        if( $channel ne "") {
            if (my $chid = &PosToChannel($channel)) {
                $data->{Channels} = $chid;
            }
        }
        $data->{Priority} = $prio;
        $data->{Lifetime} = $lft;
        $data->{Dir} = $directoy;
        $data->{Start} = $start;
        $data->{Stop} = $stop;
        # autotimerimport don't support episode, i belief "1" means File = title~subtitle / "0" means File = title
        # $data->{Episode} = $episode; 

        &_insert($data);
        ++$cnt;
    }
    close (AT_FILE);
    print STDERR sprintf("%d Autotimer read from file %s.\n",$cnt,$AT_FILENAME);

    return 0;
}

# ------------------
# Name:  autotimerexport
# Descr: Read autotimer from database and save this to a export file.
# Usage: autotimerexport($filename);
# ------------------
sub autotimerexport {
    my $AT_FILENAME = shift || die("No filename to export! Use $0 -e 'vdradmind.at'\n");

    die sprintf("File to store autotimer '%s' already exist! The file can't be overwritten. Please remove the file manually.\n",$AT_FILENAME)
        if(-e $AT_FILENAME);

    my $sql = "select Activ, Search, InFields, Channels, Dir, Start, Stop, Priority, Lifetime from AUTOTIMER order by Id";
    my $atlist = $dbh->selectall_arrayref($sql);

    die "No autotimer data are to export available!\n"
        if((!$atlist) || (scalar $atlist <= 0));

    my $cnt = "0";
    open(AT_FILE, ">$AT_FILENAME") || die sprintf("Can't open file '%s' : %s\n",$AT_FILENAME,$!);
    foreach my $data (@$atlist) {
        if($data->[1] ne "" and $data->[2] ne "") {

        my $active = "0";
        my $pattern = $data->[1];
        my $section = "0";
        my $start = "";
        my $stop = "";
        my $episode = "0"; # autotimerexport don't support episode, i belief "1" means File = title~subtitle / "0" means File = title
        my $prio = "";
        my $lft = "";
        my $channel = "";
        my $directoy = "";

        $active = "1" if($data->[0] eq "y");

        $section |= 1 if ($data->[2]=~/^.*title.*$/);
        $section |= 2 if ($data->[2]=~/^.*subtitle.*$/);
        $section |= 4 if ($data->[2]=~/^.*description.*$/);

        if( $data->[3]) {
            foreach my $ch (@{&ChannelArray('Id')}) {
                if ($data->[3] eq $ch->[0]) { # vdradmin suppport only one Channel
                    $channel = $ch->[1];
                    last;
                }
            }
        }

        $directoy = $data->[4] if($data->[4]);
        $start = $data->[5] if($data->[5] and $data->[5] ne $data->[6]); # Exclude if start and stop if same value e.g. 0000
        $stop = $data->[6] if($data->[6] and $data->[5] ne $data->[6]);
        $prio = $data->[7] if($data->[7]);
        $lft = $data->[8] if($data->[8]);

        print AT_FILE sprintf("%s:%s:%s:%s:%s:%s:%s:%s:%s:%s\n",
            $active,$pattern,$section,$start,$stop,$episode,$prio,$lft,$channel,$directoy)
            || die sprintf("Can't write file '%s' : %s\n",$AT_FILENAME,$!);
        ++$cnt;
        }
    }
    close (AT_FILE);
    
    print STDERR sprintf("%d Autotimer write to file %s\n",$cnt,$AT_FILENAME);

    return 0;
}
    

$dbh = DBI->connect("DBI:mysql:database=$db;host=$host;port=$port", $usr, $pwd,{ 
  PrintError => 1,
  AutoCommit => 1,
}) || die $DBI::errstr;

exit 1
  unless($dbh);

exit &autotimerexport($filename)
    if($opt{e});
exit &autotimerimport($filename)
    if(!$opt{e});



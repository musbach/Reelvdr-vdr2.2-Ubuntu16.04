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
this script search and remove duplicates from CHRONICLE.
Duplicates should never occurrence, but it's some time possible.
e.g. after migration from mysql 4.0 to 5.0.

Usage: $0 [options]

Options:
          -H <hostname>  : Host name of the MySQL server (default: '$host')
          -P <port>      : Port number of MySQL server (default: '$port')
          -d <database>  : XXV database name (default: '$db')
          -u <user>      : Username (default: '$usr')
          -p <password>  : Password (default: '$pwd')
          -q             : Be quiet
          -h             : Help

};

use vars qw/ %opt /;
my $dbh;

die $Usage if (!getopts("d:H:P:u:p:hq", \%opt) || $opt{h} );


$db   = $opt{d} if($opt{d});
$host = $opt{H} if($opt{H});
$port = $opt{P} if($opt{P});
$usr =  $opt{u} if($opt{u});
$pwd =  $opt{p} if($opt{p});

# ------------------
# dump_duplicates
# ------------------
sub dump_duplicates {

#  my $sth = $dbh->prepare('select id,title,channel_id FROM CHRONICLE')
  my $sth = $dbh->prepare('select id,title,channel_id FROM CHRONICLE WHERE id IN (SELECT id FROM TMPCHRONICLE)')
    or die "Couldn't prepare dump statement: " . $dbh->errstr;
  my @data;

  $sth->execute()
    or die "Couldn't execute dump statement: " . $sth->errstr;

  while (@data = $sth->fetchrow_array()) {
    print sprintf("%3d: %20s   %s\n",$data[0],$data[2] || '',$data[1]);
  }

  if ($sth->rows == 0) {
    print "There none duplicates found.\n";
  }
}
# ------------------
# search and remove duplicates from CHRONICLE
# ------------------
sub remove_duplicates {

  $dbh->do(qq|DROP TABLE IF EXISTS TMPCHRONICLE|) 
    || die "Couldn't drop temporary table: ". $dbh->errstr;
  $dbh->do(qq|
        CREATE TEMPORARY TABLE TMPCHRONICLE
          SELECT min(id) id
          FROM CHRONICLE
          GROUP BY title,channel_id,starttime,duration
          HAVING count(*) > 1
  |) || die "Couldn't create temporary table: ". $dbh->errstr;

  &dump_duplicates() if(! $opt{q});

  $dbh->do(qq|DELETE FROM CHRONICLE WHERE id IN (SELECT id FROM TMPCHRONICLE)|) 
    || die "Couldn't delete duplicates from temporary table: ". $dbh->errstr;

  $dbh->do(qq|DROP TABLE IF EXISTS TMPCHRONICLE|) 
    || die "Couldn't drop temporary table: ". $dbh->errstr;

  $dbh->disconnect;

  return 0;
}

$dbh = DBI->connect("DBI:mysql:database=$db;host=$host;port=$port", $usr, $pwd,{ 
  PrintError => 1,
  AutoCommit => 1,
}) || die $DBI::errstr;

exit 1
  unless($dbh);

exit &remove_duplicates();




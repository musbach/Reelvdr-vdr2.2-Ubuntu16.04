#!/usr/bin/perl
use strict;

# this program is a HACK

sub item {
	my ($f, $r);
	($r, $f) = @_;
	return $1 if ( $r =~ /^$f: (.+?)$/gsmi );
	return "nil";
}

my $depsep = ", \t()=<>|+.\-";
my $in;
$in .= $_ while (<STDIN>);
my @records = split /\n\n/, $in;
my %name;
for (@records) {
	$name{item($_, "package")} = $_;
}

my %set;

for (@ARGV) {
	$set{$_} = 1;
}

my $changed = 1;
while ( $changed == 1 ) {
	$changed = 0;
	for ( keys %set ) {
		for my $dep (item( $name{$_}, "depends" ),
					 item( $name{$_}, "suggests" ), item( $name{$_}, "recommends" ) ) {
			my @d = split /[$depsep]+[0-9$depsep]*/, $dep;
			for ( @d ) {
				next if ( $set{$_} );
				print STDERR "adding: $_\n";
				$changed = 1;
				$set{$_} = 1;
			}
		}
	}
}

for ( keys %set ) {
	print "$name{$_}\n\n" if ( $name{$_} );
}

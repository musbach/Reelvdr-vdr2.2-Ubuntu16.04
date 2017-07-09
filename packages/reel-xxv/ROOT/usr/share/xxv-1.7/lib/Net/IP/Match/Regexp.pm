package Net::IP::Match::Regexp;

require 5.006;
use strict;
use warnings;

use base 'Exporter';
our @EXPORT = qw();
our @EXPORT_OK = qw( create_iprange_regexp match_ip );
our $VERSION = '0.91';

=head1 NAME

Net::IP::Match::Regexp - Efficiently match IPv4 addresses against IPv4 ranges via regexp

=head1 LICENSE

Copyright 2005 Clotho Advanced Media, Inc., <cpan@clotho.com>

This library is free software; you can redistribute it and/or modify it
under the same terms as Perl itself.

=head1 SYNOPSIS

    use Net::IP::Match::Regexp qw( create_iprange_regexp match_ip );
    
    my $regexp = create_iprange_regexp(
       qw( 10.0.0.0/8 87.134.66.128 87.134.87.0/24 145.97.0.0/16 )
    );
    if (match_ip("209.249.163.62", $regexp)) {
       ...
    }

=head1 DESCRIPTION

This module allows you to check an IP address against one or more IP
ranges.  It employs Perl's highly optimized regular expression engine
to do the hard work, so it is very fast.  It is optimized for speed by
doing the match against a pre-computed regexp, which implicitly checks
the broadest IP ranges first.  An advantage is that the regexp can be
comuted and stored in advance (in source code, in a database table,
etc) and reused, saving much time if the IP ranges don't change too
often.  The match can optionally report a value instead of just a
boolean, which makes module useful for mapping IP ranges to names or
codes or anything else.

=head1 SEE ALSO

There are several other CPAN modules that perform a similar function.
This one is faster than the other ones that I've found and tried.
Here is a synopsis of those others:

=head2 Net::IP::Match

Optimized for speed by taking a "source filter" approach.  That is, it
modifies your source code at run time, kind of like a C preprocessor.
A huge limitation is that the IP ranges must be hard-coded into your
program.

=head2 Net::IP::Match::XS

(Also released as Net::IP::CMatch)

Optimized for speed by doing the match in C instead of in Perl.  This
module loses efficiency, however, because the IP ranges must be
re-parsed every invokation.

=head2 Net::IP::Match::Resolver

Uses Net::IP::Match::XS to implement a range-to-name map.


=head1 PERFORMANCE

I ran a test on my Mac G5 to compare this module to
Net::IP::Match::XS.  The test was intended to be a realistic net
filter case: 100,000 random IPs tested against 300 semi-random IP
ranges.  Times are in seconds.

    Module                 | Setup time | Run time
    -----------------------+------------+----------
    Net::IP::Match::Regexp |    0.057   |  1.663
    Net::IP::Match::XS     |      n/a   |  4.238

=head1 IMPLEMENTATION

The speed of this module comes from the short-circuit nature of
regular expressions.  The setup function turns all of the IP ranges
into binary strings, and mixes them into a regexp with C<|> choices
between ones and zeros.  This regexp can then be passed to the match
function.  When an unambiguous match is found, the regexp sets a
variable (via the regexp $^R feature) and terminates.  That variable
becomes the return value for the match, typically a true value.

Here's an example of the regexp for a single range, that of my company's subnet:

    print create_iprange_regexp("209.249.163.0/25")'
    # ^1101000111111001101000110(?{'1'})

If I add another range, say a NAT LAN, I get:

    print create_iprange_regexp("209.249.163.0/25", "192.168.0.0/16")'
    # ^110(?:0000010101000(?{'1'})|1000111111001101000110(?{'1'}))

Note that for a 192.168.x.x address, the regexp checks at most the
first 16 bits (1100000010101000) whereas for a 209.249.163.x address,
it goes out to 15 bits (1101000111111001101000110).  The cool part is
that for an IP address that starts in the lower half (say 127.0.0.1)
only needs to check the first bit (0) to see that the regexp won't
match.

If mapped return values are specified for the ranges, they get embedded
into the regexp like so:

    print create_iprange_regexp({"209.249.163.0/25" => "clotho.com",
                                 "192.168.0.0/16" => "localhost"})'
    # ^110(?:0000010101000(?{'localhost'})|1000111111001101000110(?{'clotho.com'}))

This could be implemented in C to be even faster.  In C, it would
probably be better to use a binary tree instead of a regexp.  However,
a goal of this module is to create a serializable representation of
the range data, and the regexp is perfect for that.  So, we'll
probably never do a C version.

=head1 COMPATIBILITY

Because this module relies on the C<(?{ code })> feature of regexps,
it won't work on old Perl versions.  I've successfully tested this
module on Perl 5.6.0, 5.8.1 and 5.8.6.  In theory, the code regexp
feature should work in 5.005, but I've used "our" and the like, so it
won't work there.  I don't have a 5.005 to test anyway...

=head1 FUNCTIONS

=over

=cut


=item create_iprange_regexp IPRANGE | MAP, ...

This function digests IP ranges into a regular expression that can
subsequently be used to efficiently test single IP addresses.  It
returns a regular expression string that can be passed to match_ip().

The simple way to use this is to pass a list of IP ranges as
C<aaa.bbb.ccc.ddd/n>.  When used this way, the return value of the
match_ip() function will be simply C<1> or C<undef>.

The more complex way is to pass a hash reference of IP range => return
value pairs.  When used this way, the return value of the match_ip()
function will be the specified return value or C<undef> for no match.

For example:

    my $re1 = create_iprange_regexp("209.249.163.0/25", "127.0.0.1/32");
    print match_ip("209.249.163.62", $re1); # prints "1"
    
    my $re2 = create_iprange_regexp({"209.249.163.0/25" => "clotho.com",
                                     "127.0.0.1/32" => "localhost"});
    print match_ip("209.249.163.62", $re2); # prints "clotho.com"

Note that these two styles can be mixed (a rarely used feature).
These two examples are equivalent:

    create_iprange_regexp("127.0.0.1/32",
                          {"209.249.163.0/25" => "clotho.com"},
                          "10.0.0.0/8",
                          {"192.168.0.0/16" => "LAN"});

    create_iprange_regexp({"127.0.0.1/32" => 1,
                           "209.249.163.0/25" => "clotho.com",
                           "10.0.0.0/8" => 1,
                           "192.168.0.0/16" => "LAN"});

Special note: the value string will be wrapped in single-quotes in the
regexp.  Therefore, you must double-escape any single quotes in that value.
For example:

    create_iprange_regexp({"208.201.239.36/31" => "O\\'Reilly publishing"});

Warning: This function does no checking for validity of IP ranges.  It
happily accepts C<1000.0.0.0/-38>.  Hopefully a future version will
validate the ranges, perhaps via Net::CIDR or Net::IP.

=cut

sub create_iprange_regexp
{
   # If an argument is a hash ref, flatten it
   # If an argument is a scalar, make it a key and give it a value of 1
   my %map = map {ref $_ ? %$_ : ($_ => 1)} @_;
   
   # The tree is a temporary construct.  It has three possible
   # properties: 0, 1, and code.  The code is the return value for a
   # match.
   my %tree;

   for my $range (keys %map)
   {
      my ($ip,$mask) = split /\//, $range;
      
      my $tree = \%tree;
      my @bits = split //, unpack("B32", pack("C4", split(/\./, $ip)));
      for my $val (@bits[0..$mask-1])
      {
         # If this case is hit, it means that our IP range is a subset
         # of some other range.
         last if ($tree->{code});

         $tree->{$val} ||= {};
         $tree = $tree->{$val};
      }
      # If the code is already set, it's a non-fatal error (bad data)
      $tree->{code} ||= $map{$range};

      # prune redundant branches
      # this is only important if the range data is poor
      delete $tree->{0};
      delete $tree->{1};
   }

   # Recurse into the tree making it into a regexp
   my $re = "^".tree2re(\%tree);
   return $re;
}

=item match_ip IP_ADDR, REGEXP

Given a single IP address as a string of the form C<aaa.bbb.ccc.ddd>
and a regular expression string (typically the output of
create_iprange_regexp()), this function returns a pre-specified value
(typically C<1>) if the IP is in one of the ranges, or C<undef> if no
ranges match.

See create_ipranges_regexp() for more details about the return value
of this function.

Warning: This function does no checking for validity of the IP address.

=cut

sub match_ip
{
   my ($ip,$re) = @_;

   local $^R;
   use re 'eval';
   unpack("B32", pack("C4", split(/\./, $ip))) =~ /$re/;
   return $^R;
}

# Helper function.  This recurses to build the regular expression
# string from a tree of IP ranges constructed by
# create_iprange_regexp().

sub tree2re
{
   my $tree = shift;
   
   if ($tree->{code})
   {
      return "(?{'$$tree{code}'})";
   }
   elsif ($tree->{0} && $tree->{1})
   {
      return "(?:0".tree2re($tree->{0})."|1".tree2re($tree->{1}).")";
   }
   elsif ($tree->{0})
   {
      return "0".tree2re($tree->{0});
   }
   elsif ($tree->{1})
   {
      return "1".tree2re($tree->{1});
   }
   else
   {
      die "Internal error";
   }
}

1;

__END__

=back

=head1 AUTHOR

Clotho Advanced Media, Inc. I<cpan@clotho.com>

Primary developer: Chris Dolan

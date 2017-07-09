package Bundle::Xxv;
use strict;
use warnings;

$VERSION = '1.0'.((split(/ /, '$Revision'))[1]);

1;

__END__

=head1 NAME

Bundle::Xxv - A bundle to install various xxv related modules

=head1 SYNOPSIS

    mkdir -p ~/.cpan/Bundle
    cp Bundle/Xxv.pm ~/.cpan/Bundle
    perl -MCPAN -e 'install Bundle::Xxv'

=head1 CONTENTS

CGI
Compress::Zlib
Config::Tiny
Data::Dumper
Date::Manip
DBD::mysql
DBI
Digest::MD5
Digest::HMAC_MD5
Encode
Event
GD
Getopt::Long
HTML::TextToHTML
HTML::TreeBuilder
JSON
Linux::Inotify2
Locale::gettext
LWP::Simple
LWP::UserAgent
MIME::Base64
MP3::Info
Net::Amazon
Net::Amazon::Request::Artist
Net::XMPP
Proc::Killfam
Proc::ProcessTable 
SOAP::Lite
SOAP::Transport::HTTP
Template
Time::Local
Time::HiRes
URI::Escape
XML::RSS
XML::Simple

=head1 DESCRIPTION

This is a bundle of xxv related modules.

=head1 AUTHOR

Frank Herrmann E<lt>xpix at xpix dot deE<gt>

=cut

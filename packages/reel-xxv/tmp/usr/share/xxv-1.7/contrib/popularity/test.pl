#!/usr/bin/perl -w

use SOAP::Lite +trace => qw( debug );
use Data::Dumper;

my $client = SOAP::Lite->new;
$client->schema->useragent->agent("xxv 1.0");
my $service = $client->service('http://localhost/t10.php?wsdl');

print "## getUsrKey ##########################################################\n";
my $myuserkey = $service->getUsrKey('myuserkey');
print Dumper($myuserkey);

my $result;
print "## getServerTime ######################################################\n";
$result = $service->getServerTime($myuserkey);
print Dumper($result);


print "## setEventLevel ######################################################\n";
$result = $service->setEventLevel($myuserkey,1253535,5,time+3600);
print Dumper($result);

print "## setEventLevel ######################################################\n";
$result = $service->setEventLevel($myuserkey,1253535,3,time+3600);
print Dumper($result);

print "## setEventLevel ######################################################\n";
$result = $service->setEventLevel($myuserkey,1253535,3,time+3600);
print Dumper($result);

print "## setEventLevel ######################################################\n";
$result = $service->setEventLevel($myuserkey,1253532,3,time+3600);
print Dumper($result);

my @array = [
  [1253535,5,time+3600],
  [1253535,3,time+3600],
  [1253535,3,time+3600],
  [1253535,3,time+3600],
  [1253535,5,time+3600]
];
print "## setEventArray ######################################################\n";

$result = $service->setEventArray($myuserkey, @array);
print Dumper($result);

print "## getEventLevel ######################################################\n";
$result = $service->getEventLevel($myuserkey,1253535);
print Dumper($result);

print "## getEventLevels #####################################################\n";
$result = $service->getEventLevels($myuserkey,10);
print Dumper($result);

print "## getTopTen ##########################################################\n";
$result = $service->getTopTen($myuserkey,20);
print Dumper($result);

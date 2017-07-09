<?php
/**
* @version $Id$
* @package Xtreme eXtension for VDR
* @copyright Copyright (C) 2007 xxv team. All rights reserved.
* @license http://www.gnu.org/copyleft/gpl.html GNU/GPL, see LICENSE.php
* xxv is free software. This version may have been modified pursuant
* to the GNU General Public License, and as distributed it includes or
* is derivative of works licensed under the GNU General Public License or
* other free or open source software licenses.
* See COPYRIGHT.php for copyright notices and details.
*/

// Set flag that this is a parent file
define( '_VALID_MOS', 1 );

ini_set("memory_limit", "16M") ; 

// Pull in the NuSOAP code
require_once('popularity/nusoap.php');

// Create the server instance
$server = new soap_server();
// Initialize WSDL support
$server->configureWSDL('t10', 'urn:t10');


function opendatabase() {

  require( 'globals.php' );
  require_once( 'configuration.php' );
  require_once( $mosConfig_absolute_path . '/includes/database.php' );

  $database = new database( $mosConfig_host, $mosConfig_user, $mosConfig_password, $mosConfig_db, $mosConfig_dbprefix );
  if ($database->getErrorNum()) {
  	$mosSystemError = $database->getErrorNum();
  	$basePath = dirname( __FILE__ );
  	include $basePath . '/configuration.php';
  	include $basePath . '/offline.php';
  	exit();
  }
  $database->debug( $mosConfig_debug );

  return $database;
}

////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('getUsrKey',                // method name
  array('k'    => 'xsd:string'),            // user key
  array('return' => 'xsd:string'),          // output parameters
  'urn:t10',                                // namespace
  'urn:t10#getUsrKey',                      // soapaction
  'rpc',                                    // style
  'encoded',                                // use
  'A connection test for clients.'          // documentation
);
// A connection test for clients.
function getUsrKey($k) {
  $usrkey = $k;
  return $usrkey;
}


////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('getServerTime',         // method name
  array('k'    => 'xsd:string'),           // user key
  array('return' => 'xsd:int'),            // output parameters
  'urn:t10',                               // namespace
  'urn:t10#getServerTime',                 // soapaction
  'rpc',                                   // style
  'encoded',                               // use
  'Return the time from server.'           // documentation
);
// Return the time from server
function getServerTime($k) {

  $database = opendatabase();

  $query = "SELECT UNIX_TIMESTAMP(NOW())";
	$database->setQuery( $query );
	$servertime = $database->loadResult();

  return $servertime;
}

////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('getEventLevel',         // method name
  array('k' => 'xsd:string',               // user key 
        'e' => 'xsd:int'),                 // eventid
  array('return' => 'xsd:float'),          // output parameters
  'urn:t10',                               // namespace
  'urn:t10#getEventLevel',                 // soapaction
  'rpc',                                   // style
  'encoded',                               // use
  'Return the average level from event.'   // documentation
);
// Return the average level from Event
function getEventLevel($k,$e) {

  $database = opendatabase();

  $query = "SELECT AVG(level)"
		. " FROM #__popularity"
		. " WHERE id = " . $database->Quote( (int) $e ) 
		;
	$database->setQuery( $query );
	$average = $database->loadResult();

  return $average;
}

////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('setEventLevel',           // method name
  array('k' => 'xsd:string',               // user key
        'e' => 'xsd:int',                  // eventid    
        'l' => 'xsd:int',                  // level 
        's' => 'xsd:int'),                 // stoptime
  array('return' => 'xsd:int'),            // output parameters
  'urn:t10',                               // namespace
  'urn:t10#setEventLevel',                 // soapaction
  'rpc',                                   // style
  'encoded',                               // use
  'Set a level to event.'                  // documentation
);
// Set a level to event.
function setEventLevel($k,$e,$l,$s) {

  if((int)$l <= 0) {
    $l = 0;
  } else {
    if((int)$l >= 10) {
      $l = 10;
    }
  }

  $database = opendatabase();

	$query = "REPLACE INTO #__popularity"
	. " (user, id, level, stoptime)"
	. " VALUES ( " . $database->Quote( $k ) . ", "
	                     . (int)$e . ", "
	                     . (int)$l . ", "
	. " FROM_UNIXTIME( " . (int)$s . " )"
  . " )"
	;
	$database->setQuery( $query );
  if (!$database->query()) {
	  die($database->stderr(true));
    return 0;
	}
  return 1;
}



////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('setEventArray',         // method name
  array('k' => 'xsd:string',               // user key
//      'u' => 'tns:u'
  ),
  array('return' => 'xsd:int'),             // output parameters
  'urn:t10',                               // namespace
  'urn:t10#setEventArray',                 // soapaction
  'rpc',                                   // style
  'encoded',                               // use
  'Set a level to event.'                  // documentation
);
// Set a level to event.
function setEventArray($k,$u) {

  $c = count($u);
  if($c <= 0 || $c > 25) {
    return -1;
  }
  
  $database = opendatabase();
  for ( $i = 0; $i < $c; $i += 1) {
    if( count($u[$i]) != 3) {
      return -2;
    }
    $e = (int)$u[$i][0];
    $l = (int)$u[$i][1];
    $s = (int)$u[$i][2];

    if($e <= 0) {
      return -3;
    }

    if($l <= 0) {
      return -4;
    } else {
      if($l >= 10) {
        return -5;
      }
    }

    if($s <= 0) {
      return -6;
    }

    $query = "REPLACE INTO #__popularity"
	  . " (user, id, level, stoptime)"
	  . " VALUES ( " . $database->Quote( $k ) . ", "
	                       . $e . ", "
	                       . $l . ", "
	  . " FROM_UNIXTIME( " . $s . " )"
    . " )"
	  ;
	  $database->setQuery( $query );
    if (!$database->query()) {
	    die($database->stderr(true));
      return 0;
	  }
  }
  return 1;
}
////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('deleteEvent',         // method name
  array('k' => 'xsd:string',             // user key 
        'e' => 'xsd:int'),               // eventid    
  array('return' => 'xsd:int'),          // output parameters
  'urn:t10',                             // namespace
  'urn:t10#deleteEvent',                 // soapaction
  'rpc',                                 // style
  'encoded',                             // use
  'Delete an event from database.'       // documentation
);
// Delete an event from database.
function deleteEvent($k,$e) {

  $database = opendatabase();

  $query = "DELETE"
		. " FROM #__popularity"
		. " WHERE id = " . $database->Quote( (int) $e )
		. " AND user = " . $database->Quote( $k )
		;
	$database->setQuery( $query );
  if (!$database->query()) {
	  die($database->stderr(true));
    return 0;
	}

  return 1;
}

// Delete expired events from selected database.
function expired($database) {

  $query = "DELETE"
	  . " FROM #__popularity"
	  . " WHERE stoptime < NOW()"
	  ;
  $database->setQuery( $query );
  if (!$database->query()) {
    die($database->stderr(true));
    return 0;
  }

  return 1;
}

/*////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
$server->register('clear',                 // method name
    array('k'    => 'xsd:string'),         // user key
    array('return' => 'xsd:int'),          // output parameters
    'urn:t10',                             // namespace
    'urn:t10#clear',                       // soapaction
    'rpc',                                 // style
    'encoded',                             // use
    'Delete old events from database.'     // documentation
);
// Delete old events from database.
function clear($k) {

    $database = opendatabase();
    return expired($database);
}*/


////////////////////////////////////////////////////////////////////////////////

$server->wsdl->addComplexType(
  'v', //EventLevel
  'complexType',
  'struct',
  'all',
  '',
  array(
    'e' => array('name'=>'e','type'=>'xsd:int'),  // eventid
    'l' => array('name'=>'l','type'=>'xsd:float') // level
  )
);

$server->wsdl->addComplexType(
  'a', //EventLevelArray
  'complexType',
  'array',
  '',
  'SOAP-ENC:Array',
  array(),
  array(
    array('ref'=>'SOAP-ENC:arrayType','wsdl:arrayType'=>'tns:v[]')
  ),
  'tns:v'
);

// Register the method to expose
$server->register('getEventLevels',        // method name
    array('k'    => 'xsd:string'),         // user key
    array('return' => 'tns:a'),            //EventLevelArray
    'urn:t10',                             // namespace
    'urn:t10#getEventLevels',              // soapaction
    'rpc',                                 // style
    'encoded',                             // use
    'Return the average levels from events.'// documentation
);
// Return the average Levels from Events.
function getEventLevels($k) {

  $database = opendatabase();

  if(!expired($database)) {
    return 0;
  }

  $result = array();
  $query = "SELECT id, AVG(level) as level"
  . " FROM #__popularity"
  . " GROUP BY id"
  ;
  $database->setQuery( $query );
  $rows = $database->loadObjectList();
  if(!empty($rows)) {
    foreach ($rows as $row) {
      $result[] = array(
      'e' => $row->id,
      'l' => $row->level
      );
    }
  }
  return $result;
}


////////////////////////////////////////////////////////////////////////////////

$server->wsdl->addComplexType(
  't', //topten
  'complexType',
  'struct',
  'all',
  '',
  array(
    'e' => array('name'=>'e','type'=>'xsd:int'),    // eventid
    'l' => array('name'=>'l','type'=>'xsd:float'),  // level
    'c' => array('name'=>'c','type'=>'xsd:int'),    // count
    'r' => array('name'=>'r','type'=>'xsd:float')   // rank
  )
);

$server->wsdl->addComplexType(
  'b',
  'complexType',
  'array',
  '',
  'SOAP-ENC:Array',
  array(),
  array(
    array('ref'=>'SOAP-ENC:arrayType','wsdl:arrayType'=>'tns:t[]')
  ),
  'tns:t'
);

// Register the method to expose
$server->register('getTopTen',             // method name
  array('k' => 'xsd:string',             // user key
        'l' => 'xsd:int'),               // level
  array('return' => 'tns:b'),            // output parameters
  'urn:t10',                             // namespace
  'urn:t10#getTopTen',                   // soapaction
  'rpc',                                 // style
  'encoded',                             // use
  'Return the topten list.'              // documentation
);
// Return the topten list.
function getTopTen($k,$l) {

  $database = opendatabase();

  if(!expired($database)) {
    return 0;
  }

  if((int)$l <= 1) {
    $l = 1;
  }
  if((int)$l >= 1000) {
    $l = 1000;
  }

  $result = array();
  $query = "SELECT id as i, AVG(level) as l, COUNT(*) as c, AVG(level)*COUNT(*) as r"
  . " FROM #__popularity"
  . " GROUP BY id ORDER by r DESC" 
  ;

  $database->setQuery( $query, 0 , (int) $l);
  $rows = $database->loadObjectList();
  if(!empty($rows)) {
    foreach ($rows as $row) {
    $result[] = array(
      'e' => $row->i,
      'l' => $row->l,
      'c' => $row->c,
      'r' => $row->r
      );
    }
  }
  return $result;
}


////////////////////////////////////////////////////////////////////////////////
// Register the method to expose
/*
$server->register('createtable',           // method name
  array('k'    => 'xsd:string'),         // user key
  array('return' => 'xsd:int'),          // output parameters
  'urn:t10',                             // namespace
  'urn:t10#createtable',                 // soapaction
  'rpc',                                 // style
  'encoded',                             // use
  'create table into database.'          // documentation
);
// Delete an event from database.
function createtable($k) {

  $database = opendatabase();

  $query = "CREATE TABLE IF NOT EXISTS #__popularity ("
		. " user varchar(16) NOT NULL default '',"
		. " id int unsigned NOT NULL default '0',"
		. " level tinyint unsigned default NULL,"
		. " stoptime datetime NOT NULL,"
		. " UNIQUE KEY `event` (`user`,`id`)"
		. " )"
  ;
	$database->setQuery( $query );
  if (!$database->query()) {
	  die($database->stderr(true));
    return 0;
	}

  return 1;
}
*/
////////////////////////////////////////////////////////////////////////////////
// Use the request to (try to) invoke the service
$HTTP_RAW_POST_DATA = isset($HTTP_RAW_POST_DATA) ? $HTTP_RAW_POST_DATA : '';
$server->service($HTTP_RAW_POST_DATA);
?>


package XXV::MODULES::CHRONICLE;

use strict;
use Tools;

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $self = shift || return error('No object defined!');

    my $args = {
        Name => 'CHRONICLE',
        Prereq => {
            # 'Perl::Module' => 'Description',
        },
        Description => gettext('This module saves recordings in a chronicle.'),
        Preferences => {
            active => {
                description => gettext('Activate this service'),
                default     => 'y',
                type        => 'confirm',
                required    => gettext('This is required!'),
            },
        },
        Commands => {
            chrlist => {
                description => gettext('List recording chronicle'),
                short       => 'chrl',
                callback    => sub{ $self->list(@_) },
                DenyClass   => 'rlist',
            },
            chrsearch => {
                description => gettext("Search chronicle for 'text'."),
                short       => 'chrs',
                callback    => sub{ $self->search(@_) },
                DenyClass   => 'rlist',
            },
            chrdelete => {
                description => gettext("Delete within chronicle with 'ID'"),
                short       => 'chrd',
                callback    => sub{ $self->delete(@_) },
                DenyClass   => 'redit',
            },
        },
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

    # The Initprocess
    my $erg = $self->_init or return error('Problem to initialize modul!');

    return $self;
}

# ------------------
sub _init {
# ------------------
    my $self = shift || return error('No object defined!');

    if($self->{active} eq 'y') {

      unless($self->{dbh}) {
        panic("Session to database is'nt connected");
        return 0;
      }

      my $version = main::getDBVersion();
      # don't remove old table, if updated rows => warn only
      if(!tableUpdated($self->{dbh},'CHRONICLE',$version,0)) {
        return 0;
      }

      # Look for table or create this table
      $self->{dbh}->do(qq|
        CREATE TABLE IF NOT EXISTS CHRONICLE (
            id int unsigned auto_increment not NULL,
            hash varchar(32) NOT NULL default '',
            title text NOT NULL default '',
            channel_id varchar(32) default '',
            starttime datetime NOT NULL default '0000-00-00 00:00:00',
            duration int NOT NULL default '0',
            description text,
            PRIMARY KEY (id),
            UNIQUE KEY (hash) 
          ) COMMENT = '$version'
      |);

      main::after(sub{
          my $m = main::getModule('RECORDS');
          $m->updated(sub{
            return 0 if($self->{active} ne 'y');

            lg 'Start chronicle callback to store recordings!';
            return $self->_insertData();

          });
          return 1;
      }, "CHRONICLE: Install callback at update recordings ...", 15);
    }
    1;
}

# ------------------
sub _insertData {
# ------------------
    my $self = shift || return error('No object defined!');

    my $sql = qq|
INSERT IGNORE INTO CHRONICLE 
  SELECT SQL_CACHE  
    0, MD5(CONCAT(e.channel_id,FLOOR(UNIX_TIMESTAMP(e.starttime) / 900),REPLACE(IF(ISNULL(e.subtitle) OR Length(e.subtitle)<=0, IF(left(e.title,1) = "%",SUBSTR(e.title FROM 2),e.title), CONCAT_WS("~",e.title,e.subtitle)),"~%","~"))),
    REPLACE(IF(ISNULL(e.subtitle) OR Length(e.subtitle)<=0, IF(left(e.title,1) = "%",SUBSTR(e.title FROM 2),e.title), CONCAT_WS("~",e.title,e.subtitle)),"~%","~") as title,
    IF(e.channel_id <> "<undef>",e.channel_id , NULL),
    e.starttime,
    e.duration,
    e.description
  FROM OLDEPG as e,RECORDS as r
  WHERE r.eventid = e.eventid
|;
    $self->{dbh}->do($sql);

    return 1;
}

# ------------------
sub list {
# ------------------
    my $self = shift;
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $data = shift;
    my $params = shift;

    my %f = (
        'id' => gettext('Service'),
        'title' => gettext('Title'),
        'channel' => gettext('Channel'),
        'day' => gettext('Day'),
        'start' => gettext('Start'),
        'stop' => gettext('Stop')
    );

    my $sql = qq|
SELECT SQL_CACHE 
  id as \'$f{'id'}\',
  title as \'$f{'title'}\',
  (SELECT Name
      FROM CHANNELS as c
      WHERE channel_id = c.Id
      LIMIT 1) as \'$f{'channel'}\',
  UNIX_TIMESTAMP(starttime) as \'$f{'day'}\',
  DATE_FORMAT(starttime, '%H:%i') as \'$f{'start'}\',
  DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(starttime) + duration), '%H:%i') as \'$f{'stop'}\'
 ,description as _description
FROM CHRONICLE
ORDER BY starttime
|;

    my $rows = 0;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $self->{dbh}->prepare($sql);
         $rsth->execute()
          or return error sprintf("Couldn't execute query: %s.",$rsth->errstr);
      $rows = $rsth->rows;
      if($rows <= $limit) {
        $sth = $rsth;
      } else {
        # Add limit query
        if($console->{cgi}->param('start')) {
          $sql .= " LIMIT " . CORE::int($console->{cgi}->param('start'));
          $sql .= "," . $limit;
        } else {
          $sql .= " LIMIT " . $limit;
        }
      }
    }

    unless($sth) {
      $sth = $self->{dbh}->prepare($sql);
      $sth->execute()
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    unless($console->typ eq 'AJAX') {
      map {
	$_->[3] = datum($_->[3],'weekday');
      } @$erg;
      unshift(@$erg, $fields);
    }
    my $info = {
      rows => $rows
    };
    $console->table($erg,$info);

    return 1;
}

# ------------------
sub search {
# ------------------
    my $self = shift;
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $text  = shift || return $console->err(gettext("No 'string' to search defined! Please use chrsearch 'text'."));
    my $params = shift;

    my $query = buildsearch("title,description",$text);

    my %f = (
        'id' => gettext('Service'),
        'title' => gettext('Title'),
        'channel' => gettext('Channel'),
        'day' => gettext('Day'),
        'start' => gettext('Start'),
        'stop' => gettext('Stop')
    );

    my $sql = qq|
SELECT SQL_CACHE 
  id as \'$f{'id'}\',
  title as \'$f{'title'}\',
  (SELECT Name
      FROM CHANNELS as c
      WHERE channel_id = c.Id
      LIMIT 1) as \'$f{'channel'}\',
  UNIX_TIMESTAMP(starttime) as \'$f{'day'}\',
  DATE_FORMAT(starttime, '%H:%i') as \'$f{'start'}\',
  DATE_FORMAT(FROM_UNIXTIME(UNIX_TIMESTAMP(starttime) + duration), '%H:%i') as \'$f{'stop'}\'
 ,description as _description
FROM CHRONICLE
|;
    $sql .= sprintf("WHERE %s ORDER BY starttime",$query->{query});



    my $rows = 0;
    my $sth;
    my $limit = $console->{cgi} && $console->{cgi}->param('limit') ? CORE::int($console->{cgi}->param('limit')) : 0;
    if($limit > 0) {
      # Query total count of rows
      my $rsth = $self->{dbh}->prepare($sql);
         $rsth->execute(@{$query->{term}})
          or return error sprintf("Couldn't execute query: %s.",$rsth->errstr);
      $rows = $rsth->rows;
      if($rows <= $limit) {
        $sth = $rsth;
      } else {
        # Add limit query
        if($console->{cgi}->param('start')) {
          $sql .= " LIMIT " . CORE::int($console->{cgi}->param('start'));
          $sql .= "," . $limit;
        } else {
          $sql .= " LIMIT " . $limit;
        }
      }
    }

    unless($sth) {
      $sth = $self->{dbh}->prepare($sql);
      $sth->execute(@{$query->{term}})
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);
      $rows = $sth->rows unless($rows);
    }

    my $fields = $sth->{'NAME'};
    my $erg = $sth->fetchall_arrayref();

    unless($console->typ eq 'AJAX') {
      map {
	$_->[3] = datum($_->[3],'weekday');
      } @$erg;
      unshift(@$erg, $fields);
    }
    my $info = {
      rows => $rows
    };
    $console->table($erg,$info);

    return 1;
}

# ------------------
sub delete {
# ------------------
    my $self = shift || return error('No object defined!');
    my $console = shift || return error('No console defined!');
    my $config = shift || return error('No config defined!');
    my $items  = shift || return $console->err(gettext("No ID to delete! Please use chrdelete 'id'"));

    my @ids  = reverse sort{ $a <=> $b } split(/[^0-9]/, $items);

    my $sql = sprintf('DELETE FROM CHRONICLE WHERE id in (%s)', join(',' => ('?') x @ids)); 
    my $sth = $self->{dbh}->prepare($sql);
    $sth->execute(@ids)
        or return error sprintf("Couldn't execute query: %s.",$sth->errstr);

    $console->message(sprintf gettext("Chronicle entry %s deleted."), join(',', @ids));
    debug sprintf('Chronicle entry "%s" is deleted%s',
        join(',', @ids),
        ( $console->{USER} && $console->{USER}->{Name} ? sprintf(' from user: %s', $console->{USER}->{Name}) : "" )
        );
    $console->redirect({url => '?cmd=chrlist', wait => 1})
        if($console->typ eq 'HTML');
}

1;

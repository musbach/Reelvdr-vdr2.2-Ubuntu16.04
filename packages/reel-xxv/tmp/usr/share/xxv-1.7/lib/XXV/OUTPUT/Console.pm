package XXV::OUTPUT::Console;

BEGIN{
    $ENV{PERL_RL} = 'Perl'
};

use strict;

use Term::ReadLine;
use Tools;
use vars qw($AUTOLOAD);

# This module method must exist for XXV
# ------------------
sub module {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $args = {
        Name => 'Telnet',
        Prereq => {
            'Pod::Text' => 'Convert POD data to formatted ASCII text ',
            'Text::ASCIITable' => 'Create a nice formatted table using ASCII characters.',
#           'Term::ReadLine' => 'Perl interface to various readline packages.',
            'Term::ReadLine::Perl' => 'a quick implementation of the minimal interface to Readline',
        },
        Description => gettext('This receives and sends ASCII messages')
    };
    return $args;
}

# ------------------
sub AUTOLOAD {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || {};
    my $params = shift || 0;

    my $name = (split('::', $AUTOLOAD))[-1];
    return  if($name eq 'DESTROY');

    $obj->message(gettext("Sorry, but this command is not available in this interface!"));
}

# ------------------
sub new {
# ------------------
	my($class, %attr) = @_;
	my $self = {};
	bless($self, $class);

	# who am I
    $self->{MOD} = $self->module;

    # Try to use the Requirments
    map {
        eval "use $_";
        if($@) {
          my $m = (split(/ /, $_))[0];
          return panic("\nCouldn't load perl module: $m\nPlease install this module on your system:\nperl -MCPAN -e 'install $m'");
        }
    } keys %{$self->{MOD}->{Prereq}};

    $self->{handle} = $attr{'-handle'}
        || return error('No handle defined!');

    $self->{dbh} = $attr{'-dbh'}
        || return error('No DBH defined!');

    $self->{paths} = $attr{'-paths'}
        || return error('No Paths given!');

    $self->{term} = Term::ReadLine->new('xxv', $self->{handle}, $self->{handle})
        || return error('No Term given!');

    $self->{TYP} = 'CONSOLE';

    $self->{maxwidth} = 20;

    $self->{TableDefaults} = {
        allowANSI   => 1,
        allowHTML   => 1,
        drawRowLine => 1,
        reportErrors=> 1,
        cb_count    => sub{ $self->_myallowansi_cb(@_) },
    };

	return $self;
}

# ------------------
sub printout {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    $data =~ s/[^\r]\n/\r\n/sig;

    my $h = $obj->{handle};
    print $h $data."\r\n";
}

# ------------------
sub message {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $t = Text::ASCIITable->new();
    $t->setOptions( $obj->{TableDefaults} );

    $t->setCols(gettext('Message'));
    if(ref $data eq 'ARRAY') {
        map { $t->addRow($_) } @$data;
    } else {
        $t->addRow($data);
    }
    $obj->printout($t->draw());
}

# ------------------
sub push {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    $obj->printout($data);
}
# ------------------
sub msg {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $err = shift || return $obj->message($data);

    $obj->err($data) if($err);
}

# ------------------
sub err {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $t = Text::ASCIITable->new;
    $t->setOptions( $obj->{TableDefaults} );

    $t->setCols(gettext('ERROR'));
    if(ref $data eq 'ARRAY') {
        map { $t->addRow($_) } @$data;
    } else {
        $t->addRow($data);
    }
    $obj->printout($t->draw());
}

# ------------------
sub menu {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $t = Text::ASCIITable->new;
    $t->setOptions( $obj->{TableDefaults} );
    $t->setCols(gettext('Module'),
                gettext("Abbreviation"),
                gettext('Name'),
                gettext('Description'));

    foreach my $line (@$data) {
        if(ref $line eq 'ARRAY') {
            $t->addRow(@$line);
        } else {
            $obj->printout($line);
        }
    }

    $obj->printout($t->draw());
}

# ------------------
sub littlemenu {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $text = $data->{title}."\n";
    $text .= gettext("Please use the command and one of the following sectors:\n");
    $text .= join(', ', sort keys %{$data->{links}});

    $obj->message($text);
}

# ------------------
sub login {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    my $questions = [
        'Name' => {
            typ     => 'string',
            msg     => gettext("Username?"),
        },
        'Password' => {
            typ     => 'string',
            msg     => gettext("Password?"),
        },
    ];

    my $answer = $obj->question($data."\r\n", $questions);
    return $answer;
}


# ------------------
sub table {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $param = shift || {};
    my $noPrint = shift || 0;

    my $out = '';
    my $UserMaxWidth = (delete $param->{maxwidth} || $obj->{maxwidth});

    my $fields = (ref $data eq 'ARRAY') ?
            shift @$data :
        [
            gettext('Name'),
            gettext('Value')
        ];

    my $t = Text::ASCIITable->new;
    $t->setOptions( $obj->{TableDefaults} );
    $t->setOptions($param) if($param);

    my ($displayFields, $displayData) = $obj->_parseData($fields, $data);
    $t->setCols(@$displayFields);
    map { $t->setColWidth($_, $UserMaxWidth) } @$displayFields;

    if(ref $displayData eq 'ARRAY') {
        foreach my $line (@$displayData) {
            if(ref $line eq 'ARRAY') {
                $t->addRow(@$line);
            } else {
                $out .= $line;
            }
        }
    } else {
        foreach my $name (sort keys %$data) {
            my $dspl = '';
            if(ref $data->{$name} eq 'HASH') {
                foreach (sort keys %{$data->{$name}}) {
                    if(ref $data->{$name}->{$_}) {
                        $dspl .= $obj->table($data->{$name}->{$_}, $param, 'noPrint');
                    } else {
                        $dspl .= sprintf("%s: %s\n", $_, $data->{$name}->{$_});
                    }
                }
            } else {
                $dspl = $data->{$name};
            }
            $t->addRow($name, $dspl);
        }
    }

    $out .= $t->draw();

    unless($noPrint) {
        $obj->printout($out);
    } else {
        return $out;
    }
}

# ------------------
sub question {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $title = shift || 0;
    my $questions = shift || return error('No data defined!');
    my $erg = shift || {};

    my $quest;

    # Check Data
    if(ref $erg eq 'HASH' and ref $questions eq 'ARRAY' and exists $erg->{action}) {
        my $error;
        @$quest = @$questions;
        while (my ($name, $data) = splice(@$quest, 0, 2)) {
            # Required value ...
            $error = $data->{req}
                if($data->{req} and not $erg->{$name});

            # Check Callback
            if(exists $data->{check} and ref $data->{check} eq 'CODE' and not $error) {
                ($erg->{$name}, $error) = $data->{check}($erg->{$name}, $data, $erg);
            }

            # Check on directory
            if($data->{typ} eq 'dir' and $data->{required} and not -d $erg->{$name}) {
                ($erg->{$name}, $error) = (undef, sprintf(gettext("Directory '%s' does not exist!"), $erg->{$name}));
            }

            # Check on file
            if($data->{typ} eq 'file' and $data->{required} and not -e $erg->{$name}) {
                ($erg->{$name}, $error) = (undef, sprintf(gettext("File '%s' does not exist!"), $erg->{$name}));
            }

            if($error) {
                $obj->err(sprintf(gettext("Error '%s' (%s) : %s!"), $data->{msg}, $name, $error));
                last;
            }
        }
        unless($error) {
            delete $erg->{action};
            return $erg;
        }
    }

    $obj->printout("$title\n") if($title);
    if(ref $questions eq 'ARRAY') {
        while (my ($name, $data) = splice(@$questions, 0, 2)) {
            my $type = delete $data->{typ};
            $type ||= 'string';
            $erg->{$name} = $obj->$type($data);
        }
    } else {
        my $type = delete $questions->{typ};
        $type ||= 'string';
        $erg = $obj->$type($questions);
    }
    return $erg;
}

# ------------------
sub list {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;
    my $def;

    if(defined $data->{def}) {
    if(ref $data->{def} eq 'CODE') {
	$def = $data->{def}();
    } elsif(ref $data->{def} eq 'ARRAY') {
	$def = join(', ', @{$data->{def}});
    } else {
	$def = $data->{def};
    }}

    my $message = (defined $def) ? sprintf('%s [%s]: ', $data->{msg}, $def) : $data->{msg}.': ';

    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;

        # Default value ...
        $answer = $data->{def}
            if(defined $data->{def} and not $answer);

        # List ...
        $error = sprintf(gettext("\nPlease use one of this list items:\n %s"), join(",\n", @{$data->{choices}}))
            unless(grep($_ eq $answer, @{$data->{choices}}));

        # Required value ...
        $error = $data->{req}
            if($data->{req} and not $answer);

        # Check Callback ...
        ($answer, $error) = $data->{check}($answer)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        # Display Error Message ....
        if($error) {
            $message = (defined $data->{def}) ? sprintf('%s [%s]', $error, $def) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}


# ------------------
sub string {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;

    my $def;
    if(defined $data->{def}) {
    if(ref $data->{def} eq 'CODE') {
	$def = $data->{def}();
    } else {
	$def = $data->{def};
    }}

    my $message = (defined $def) ? sprintf('%s [%s]: ', $data->{msg}, $def) : $data->{msg}.': ';
    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;
        # Default value ...
        $answer = $def
            if($def and not $answer);

        # Required value ...
        $error = $data->{req}
            if($data->{req} and not $answer);

        # Check Callback ...
        ($answer, $error) = $data->{check}($answer)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        # Display Error Message ....
        if($error) {
            $message = ($def) ? sprintf('%s [%s]', $error, $def) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}

# ------------------
sub file {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->string(@_);
}

# ------------------
sub dir {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->string(@_);
}

# ------------------
sub password {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->string(@_);
}

# ------------------
sub date {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->string(@_);
}

# ------------------
sub integer {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;

    my $message = (defined $data->{def} ) ? sprintf('%s [%s]: ', $data->{msg}, $data->{def}) : $data->{msg}.': ';
    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;

        # Default value ...
        $answer = $data->{def}
            if($data->{def} and ! $answer);

        # Interger?
        $error = sprintf(gettext("'%s' is not an integer!"),$answer)
            if($answer and not int($answer));

        # Required?
        $error = $data->{req}
            if(defined $data->{req} and not $answer);

        # Check Callback
        ($answer, $error) = $data->{check}($answer)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        if($error) {
            $message = (defined $data->{def}) ? sprintf('%s [%s]', $error, $data->{def}) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}

# ------------------
sub confirm {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;

    my $message = (defined $data->{def} ) ? sprintf('%s [%s]: ', $data->{msg}, $data->{def}) : $data->{msg}.': ';
    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;

        # Default value ...
        $answer = $data->{def}
            if($data->{def} and ! $answer);

        # Only yes or no ...
        $error = gettext("Please answer 'y'es or 'n'o: ")
            if($answer !~ /^[y|n]$/);

        # Required value ...
        $error = $data->{req}
            if($data->{req} and not $answer);

        # Check Callback ...
        ($answer, $error) = $data->{check}($answer)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        # Display Error Message ....
        if($error) {
            $message = (defined $data->{def}) ? sprintf('%s [%s]', $error, $data->{def}) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}

# ------------------
sub hidden {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    return error('No <def> in hidden Variable!')
        unless(defined $data->{def});
    return $data->{def};
}

# ------------------
sub datei {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    return $obj->message(gettext("Sorry, couldn't send files in this interface."));
}

# ------------------
sub image {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');

    return $obj->message(gettext("Sorry, couldn't display images in this interface."));
}

# ------------------
sub checkbox {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;

    my $message = (defined $data->{def}) ? sprintf('%s [%s]: ', $data->{msg}, join(', ', @{$data->{def}})) : $data->{msg}.': ';
    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;
        # Default value ...
        $answer = $data->{def}
            if(defined $data->{def} and not $answer);

        # Required value ...
        $error = $data->{req}
            if($data->{req} and not $answer);

        # Check Callback ...
        ($answer, $error) = $data->{check}($answer, $data)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        # Display Error Message ....
        if($error) {
            $message = (defined $data->{def}) ? sprintf('%s [%s]', $error, join(', ', @{$data->{def}})) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}

# ------------------
sub radio {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $data = shift || return error('No data defined!');
    my $t = $obj->{term};
    my $error;

    my $message = (defined $data->{def}) ? sprintf('%s [%s]: ', $data->{msg}, $data->{def}) : $data->{msg}.': ';
    while (defined (my $answer = $t->readline($message))) {
        $answer =~ s/[\r|\n]//sig;
        # Default value ...
        $answer = $data->{def}
            if(defined $data->{def} and not $answer);

        # Required value ...
        $error = $data->{req}
            if($data->{req} and not $answer);

        # only one of all ...
        $error = sprintf(gettext("You can only use one of these elements: %s"), join(',', @{$data->{choices}}))
            unless(grep( $answer eq $_, @{$data->{choices}}));


        # Check Callback ...
        ($answer, $error) = $data->{check}($answer, $data)
            if(defined $data->{check} and ref $data->{check} eq 'CODE');

        # Display Error Message ....
        if($error) {
            $message = (defined $data->{def}) ? sprintf('%s [%s]', $error, $data->{def}) : $error.': ';
            undef $error;
        } else {
            return $answer;
        }
    }
}

# ------------------
sub pod {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $modname = uc(shift) || return error('No modul name defined!');
    $modname = ucfirst($modname) if($modname eq 'GENERAL');

    my $podfile = sprintf('%s/%s.pod', $obj->{paths}->{PODPATH}, $modname);
    return $obj->err(sprintf(gettext('Module %s not found!'), $modname))
        unless(-r $podfile);
    my $tmpdir = main::getModule('USER')->userTmp($obj->{USER}->{Name});
    my $outfile = sprintf('%s/%s_%d.pod', $tmpdir, $modname, time);

    my $parser = Pod::Text->new (sentence => 0, width => 78);

    # Read POD from file.pod and write to file.txt.
    $parser->parse_from_file (
        $podfile,
        $outfile
    );
    return error('Problem to convert pod2txt')
        unless(-r $outfile);
    my $txt = load_file($outfile);

    $obj->message($txt);
}

# ------------------
sub txtfile {
# ------------------
    my $obj = shift || return error('No object defined!');
    my $filename = shift || return error('No file defined!');
    my $param = shift || {};

    my $txtfile = sprintf('%s/%s', $obj->{paths}->{DOCPATH}, $filename);
    if(! -r $txtfile) {
      $txtfile = sprintf('%s/%s.txt', $obj->{paths}->{DOCPATH}, $filename);
      if(! -r $txtfile) {
        my $gzfile  = sprintf('%s/%s.gz', $obj->{paths}->{DOCPATH}, $filename);
        if(! -r $gzfile) {
          $gzfile  = sprintf('%s/%s.txt.gz', $obj->{paths}->{DOCPATH}, $filename);
          if(! -r $gzfile) {
            my $e = $!;
            error sprintf("Could not open file '%s/%s[.txt .gz txt.gz]! : %s", $obj->{paths}->{DOCPATH}, $filename, $e);
            return $obj->err(sprintf(gettext("Could not open file '%s'! : %s"), $filename, $e));
          }
        }
        $txtfile = main::getModule('HTTPD')->unzip($obj,$gzfile);
      }
    }
    my $txt = load_file($txtfile);
    return $obj->message($txt, {tags => {first => "File: $filename"}});
}

# ------------------
sub remote {
# ------------------
    my $obj = shift || return error('No object defined!');

    my $text = qq!
.-----------------------.
| 1     | 2     | 3     |
|-----------------------|
| 4     | 5     | 6     |
|-----------------------|
| 7     | 8     | 9     |
|-----------------------|
| Menu  | 0     | Back  |
|-----------------------|
|       | Up    |       |
|-----------------------|
| Left  | Ok    | Right |
|-----------------------|
|       | Down  | Blue  |
|-----------------------|
| Red   | Green | Yellow|
|-----------------------|
| Vol:+/-   | Chan: <>  |
|-----------------------|
| <<        | >>        |
|-----------------------|
!;
    $obj->printout($text);
}

# ------------------
sub _myallowansi_cb {
# ------------------
    my $obj = shift  || return error('No object defined!');
    $_      = shift;
    s/\33\[(\d+(;\d+)?)?[musfwhojBCDHRJK]//g;
    return length($_);
}

# ------------------
sub _parseData {
# ------------------
    my $obj = shift  || return error('No object defined!');
    my $fields  = shift || return error('No field defined!');
    my $data    = shift || return error('No data defined!');

    my $displayFields = [];
    @$displayFields = grep(!/^__/, @$fields);

    if(ref $data eq 'ARRAY') {
        foreach my $d (@$data) {
            my $c = -1; my @newData;
            foreach my $r (@$d) {
                $c++;
                CORE::push(@newData, $r)
                    if($fields->[$c] !~ /^__/);
            }
            @$d = @newData;
        }
        return ($displayFields, $data);
    } else {
        return ($fields, $data);
    }
}


# ------------------
sub typ {
# ------------------
    my $obj = shift || return error('No object defined!');
    return $obj->{TYP};
}

1;

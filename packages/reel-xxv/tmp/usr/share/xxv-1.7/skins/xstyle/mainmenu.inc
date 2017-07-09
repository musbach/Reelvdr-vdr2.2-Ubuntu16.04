<script type="text/javascript">

webfxMenuImagePath = "images/"


webfxMenuUseHover = true;
webfxMenuHideTime = 500;
webfxMenuShowTime = 200;
WebFXMenu.prototype.width = 175;
<?% cuttext = 20 %?>

var myBar = new WebFXMenuBar;


<?% IF allow('now') %?>
        var runnow = new WebFXMenu;
    <?% groupnames = getModule('CHANNELS').ChannelGroupsArray('Name') %?>
    <?% IF groupnames.size %?>
        var runnowGrp = new WebFXMenu;
    <?% FOREACH group IN groupnames%?>
        runnowGrp.add(new WebFXMenuItem('<?% group.first %?>',  "?cmd=now&data=&__cgrp=<?% group.last %?>"));
    <?% END %?>
        runnow.add(new WebFXMenuItem("<?% gettext("Running now",cuttext ) %?>",null,null,runnowGrp));
    <?% END %?>

    <?% IF groupnames.size %?>
        var runnextGrp = new WebFXMenu;
    <?% FOREACH group IN groupnames %?>
        runnextGrp.add(new WebFXMenuItem('<?% group.first %?>',  "?cmd=next&data=&__cgrp=<?% group.last %?>"));
    <?% END %?>
        runnow.add(new WebFXMenuItem("<?% gettext("Next",cuttext ) %?>",null,null,runnextGrp));
        runnow.add(new WebFXMenuSeparator());
    <?% END %?>

    <?% USE date %?>
    <?% periods = getModule('EPG').periods %?>
    <?% FOREACH zeit IN periods.split(','); %?>
        <?% runningnext = 0 %?>
        <?% tom = 0 %?>
        <?% PERL %?>
            use Date::Manip;
            my $z;
            $z   = UnixDate(ParseDate($stash->{zeit}),"%s") || 0;
            if($z and $z < time) {
                $z += 86400;
                $stash->set('tom', 1);
            }
            $stash->set('z', $z);
        <?% END %?>
        <?% NEXT UNLESS z %?>

        <?% IF tom %?>
        runnow.add(new WebFXMenuItem("<?% date.format(z, "%H:%M (%a)", locale) %?>",  "?cmd=now&amp;data=<?% z %?>&amp;__cgrp=<?% cgi.param('__cgrp') %?>"));
        <?% ELSE %?>
        runnow.add(new WebFXMenuItem("<?% date.format(z, "%H:%M", locale) %?>",  "?cmd=now&amp;data=<?% z %?>&amp;__cgrp=<?% cgi.param('__cgrp') %?>"));
        <?% END %?>
    <?% END %?>
    myBar.add(new WebFXMenuButton("<?% gettext("Running now") %?>",null,null,runnow));
<?% END %?>


// -----

<?% IF allow('schema') %?>
    var program = new WebFXMenu;
    program.add(new WebFXMenuItem("<?% gettext("Schema") %?>",  "?cmd=schema"));
    <?% IF allow('topten') %?>program.add(new WebFXMenuItem("<?% gettext("Top ten entry") %?>",  "?cmd=t10"));<?% END %?>
    program.add(new WebFXMenuItem("<?% gettext("Search") %?>",  "?cmd=search"));

    <?% groups = getModule('CHANNELS').ChannelWithGroup('c.name,c.hash') %?>
    <?% IF groups.size %?>
    program.add(new WebFXMenuSeparator());

    <?% FOREACH ch=groups %?>
        <?% IF ch.2 != lastgroup %?>
          <?% LAST IF global.cfgMaxChannelMenuEntrys && loop.count > global.cfgMaxChannelMenuEntrys %?>
          <?% IF lastgroup %?>
    program.add(new WebFXMenuItem('<?% chop(lastgroup,cuttext) %?>',null,null,programGrp<?% z %?>));
          <?% END %?>
        <?% lastgroup = ch.2 %?>
        <?% z = z + 1 %?>
    var programGrp<?% z %?> = new WebFXMenu;
        <?% END %?>
        programGrp<?% z %?>.add(new WebFXMenuItem('<?% escape(chop(ch.0,cuttext)) %?>',  '?cmd=program&data=<?% ch.1 %?>'));
    <?% END %?>
    program.add(new WebFXMenuItem('<?% chop(lastgroup,cuttext) %?>',null,null,programGrp<?% z %?>));
    <?% END %?>

    <?% IF allow('erestart') %?>
      program.add(new WebFXMenuSeparator());
      program.add(new WebFXMenuItem("<?% gettext("Update EPG data",cuttext ) %?>","?cmd=erestart"));
    <?% END %?>

    myBar.add(new WebFXMenuButton("<?% gettext("Program guide") %?>",null,null,program));
<?% END %?>

// -----
    var control = new WebFXMenu;
    <?% IF allow('alist') %?>control.add(new WebFXMenuItem("<?% gettext("Autotimer",cuttext ) %?>",     "?cmd=alist"));<?% END %?>
    <?% IF allow('tlist') %?>control.add(new WebFXMenuItem("<?% gettext("Timers",cuttext ) %?>",        "?cmd=tlist"));<?% END %?>
    <?% IF allow('movetimerlist') %?>control.add(new WebFXMenuItem("<?% gettext("Rules to move timer",cuttext ) %?>","?cmd=movetimerlist"));<?% END %?>
    myBar.add(new WebFXMenuButton("<?% gettext("Programming") %?>",null,null,control));

    var media = new WebFXMenu;
    <?% IF allow('rlist') %?>media.add(new WebFXMenuItem("<?% gettext("Recordings",cuttext ) %?>",    "?cmd=rlist"));<?% END %?>
    <?% IF allow('mlist') %?>media.add(new WebFXMenuItem("<?% gettext("Music",cuttext ) %?>",         "?cmd=mlist"));<?% END %?>
    <?% IF allow('mllist') %?>media.add(new WebFXMenuItem("<?% gettext("Media library",cuttext ) %?>","?cmd=mllist"));<?% END %?>
    myBar.add(new WebFXMenuButton("<?% gettext("Media content") %?>",null,null,media));


    var tools = new WebFXMenu;
    <?% IF allow('remote') %?>tools.add(new WebFXMenuItem("<?% gettext("Remote",cuttext ) %?>",        "?cmd=remote"));<?% END %?>
    <?% IF allow('vtxpage') %?>tools.add(new WebFXMenuItem("<?% gettext("Teletext",cuttext ) %?>",     "?cmd=vtxpage"));<?% END %?>
    <?% IF allow('cmdlist') %?>tools.add(new WebFXMenuItem("<?% gettext("Commands",cuttext ) %?>",     "?cmd=cmdlist"));<?% END %?>
    <?% IF allow('report') %?>tools.add(new WebFXMenuItem("<?% gettext("Report",cuttext ) %?>","?cmd=report"));<?% END %?>

    myBar.add(new WebFXMenuButton("<?% gettext("Tools") %?>",null,null,tools));

// -----

    var admin = new WebFXMenu;
    <?% IF allow('vl') %?>admin.add(new WebFXMenuItem("<?% gettext("Video disk recorder",cuttext ) %?>","?cmd=vl"));<?% END %?>
    <?% IF allow('cl') %?>admin.add(new WebFXMenuItem("<?% gettext("Channels",cuttext ) %?>",  "?cmd=cl"));<?% END %?>
    <?% IF allow('ul') %?>admin.add(new WebFXMenuItem("<?% gettext("User",cuttext ) %?>","?cmd=ul"));<?% END %?>
    <?% IF allow('uprefs') %?>admin.add(new WebFXMenuItem("<?% gettext("Own settings",cuttext ) %?>","?cmd=uprefs"));<?% END %?>
    <?% IF allow('rel') %?>admin.add(new WebFXMenuItem("<?% gettext("Reload",cuttext ) %?>","?cmd=rel"));<?% END %?>
    <?% IF allow('logout') %?>admin.add(new WebFXMenuItem("<?% gettext("Logout",cuttext ) %?>","?cmd=logout"));<?% END %?>

    myBar.add(new WebFXMenuButton("<?% gettext("Administration") %?>",null,null,admin));

// -----

<?% IF allow('configedit') %?>
    var prefs = new WebFXMenu;
    <?% FOREACH co IN getModule('CONFIG').realModNames %?>
      <?% IF co != "CONFIG" %?>
        prefs.add(new WebFXMenuItem("<?% chop(co,cuttext ) %?>",  "?cmd=configedit&amp;data=<?% co %?>"));
      <?% END %?>
    <?% END %?>
    myBar.add(new WebFXMenuButton("<?% gettext("Preferences") %?>",null,null,prefs));
<?% END %?>

// -----

<?% IF allow('sa') %?>
    var status = new WebFXMenu;
    status.add(new WebFXMenuItem("<?% gettext("Status") %?>",      "?cmd=sa"));
    status.add(new WebFXMenuSeparator());
    status.add(new WebFXMenuItem("<?% gettext("Vitals") %?>",      "?cmd=sv"));
    status.add(new WebFXMenuItem("<?% gettext("Memory") %?>",      "?cmd=sm"));
    status.add(new WebFXMenuItem("<?% gettext("Filesystem") %?>",  "?cmd=sf"));
    status.add(new WebFXMenuItem("<?% gettext("Network") %?>",     "?cmd=sn"));
    status.add(new WebFXMenuItem("<?% gettext("Hardware") %?>",    "?cmd=sh"));
    <?% IF allow('logger') %?>
    var logger = new WebFXMenu;
    logger.add(new WebFXMenuItem("<?% gettext("Standard") %?>",  "?cmd=logger&data=main"));
    logger.add(new WebFXMenuItem("<?% gettext("Syslog") %?>",    "?cmd=logger&data=syslog"));
    status.add(new WebFXMenuItem("<?% gettext("Log files") %?>",null,null,logger));
    <?% END %?>
    myBar.add(new WebFXMenuButton("<?% gettext("Status") %?>",null,null,status));
<?% END %?>

// -----

<?% IF allow('more') %?>
    var info = new WebFXMenu;
    info.add(new WebFXMenuItem("<?% gettext("History") %?>",   "?cmd=more&data=CHANGELOG"));
    info.add(new WebFXMenuItem("<?% gettext("License") %?>",   "?cmd=more&data=COPYING"));
    info.add(new WebFXMenuItem("<?% gettext("Readme") %?>",   "?cmd=more&data=README"));
    myBar.add(new WebFXMenuButton("<?% gettext("Documentation") %?>",null,null,info));
<?% END %?>

document.write(myBar);

</script>

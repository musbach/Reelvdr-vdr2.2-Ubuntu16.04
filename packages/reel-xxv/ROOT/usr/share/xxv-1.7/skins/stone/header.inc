<!-- ###### Kopfzeile ###### -->
<?% IF ! global.headerinc.defined;global.headerinc = 1 %?>
<div id="header">
  <div id="logo">
     <?% IF allow( 'help' ) %?>
        <a href="http://projects.vdr-developer.org/projects/xxv">
            <img src="images/logo.<?% global.imagetyp %?>" alt="" />
        </a>
     <?% ELSE %?>
        <img src="images/logo.<?% global.imagetyp %?>" alt="" />
     <?% END %?>
  </div>
  <div id="headerNav">
      &middot; 
      <?% IF allow( 'n' ) %?>        <a accesskey="n" href="?cmd=n"><?% gettext("Running now") %?></a> &middot; <?% END %?>
      <?% IF allow( 'p' ) %?>        <a accesskey="p" href="?cmd=p"><?% gettext("Program guide") %?></a> &middot; <?% END %?>
      <?% IF allow( 'al' ) %?>       <a accesskey="a" href="?cmd=al"><?% gettext("Autotimer") %?></a> &middot; <?% END %?>
      <?% IF allow( 'tl' ) %?>       <a accesskey="t" href="?cmd=tl"><?% gettext("Timers") %?></a> &middot; <?% END %?>
      <?% IF allow( 'rl' ) %?>       <a accesskey="r" href="?cmd=rl"><?% gettext("Recordings") %?></a> &middot; <?% END %?>
      <?% IF allow( 'vt' ) %?>       <a accesskey="v" href="?cmd=vt"><?% gettext("Teletext") %?></a> &middot; <?% END %?>
      <?% IF allow( 'ml' ) %?>       <a accesskey="m" href="?cmd=ml"><?% gettext("Music") %?></a> &middot; <?% END %?>
      <?% IF allow( 'mll' ) %?>      <a accesskey="l" href="?cmd=mll"><?% gettext("Media list") %?></a> &middot; <?% END %?>
      <?% IF allow( 'r' ) %?>        <a accesskey="f" href="javascript:popupcmd('r',640,450,0)"><?% gettext("Remote") %?></a> &middot; <?% END %?>
      <?% IF allow( 'sa' ) %?>       <a accesskey="s" href="?cmd=sa"><?% gettext("Status") %?></a> &middot; <?% END %?>
      <?% IF allow( 'rp' ) %?>       <a accesskey="b" href="?cmd=rp"><?% gettext("Report") %?></a> &middot;
      <?% ELSIF allow( 'lg' ) %?>    <a accesskey="b" href="?cmd=lg&data=main"><?% gettext("Log files") %?></a> &middot;<?% END %?>
      <?% IF allow( 'ce' ) %?>       <a accesskey="c" href="?cmd=ce"><?% gettext("Preferences") %?></a> &middot;
      <?% ELSIF allow( 'uprefs' ) %?><a accesskey="u" href="javascript:popupcmd('uprefs',620,450,0)"><?% gettext("Own settings") %?></a> &middot; 
      <?% END %?>
      <?% IF allow( 'logout' ) %?>   <a accesskey="q" href="javascript:popupcmd('logout',620,450,1)"><?% gettext("Logout") %?></a> &middot; <?% END %?>
      <?% IF allow( 'help' ) %?>     <a accesskey="h" href="?cmd=help">?</a> &middot; <?% END %?>
  </div>
</div>
<!-- ###### Hilfsframe ###### -->
<div id="hilfsframe" 
    style="display:none">
    <div id="hilfsframecontent">
        <iframe<?% IF info.http_useragent.match('.*MSIE.*') %?> allowtransparency="true"<?% END %?> frameborder="0" id="cframe" src="" width="100%" height="100%">
        </iframe>
    </div>
</div>
<!-- ###### Tooltips ###### -->
<div id="TOOLTIP"></div>
<?% END %?>

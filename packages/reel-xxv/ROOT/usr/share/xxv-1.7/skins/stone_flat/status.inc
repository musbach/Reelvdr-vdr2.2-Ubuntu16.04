<!-- ###### status ###### -->
<?% IF ! global.statusinc.defined;global.statusinc = 1 %?>
</div>

<div id="sidebar">
  <table summary="">
    <tr><td class="sidehead"><?% gettext("Status",20) %?></td></tr>
    <tr>
    <td class="sidetext">
        <?% IF allow( 'sv' ) %?><a href="?cmd=sv"><?% gettext("Vitals",20) %?></a><br /><?% END %?>
        <?% IF allow( 'sf' ) %?><a href="?cmd=sf"><?% gettext("Filesystems",20) %?></a><br /><?% END %?>
        <?% IF allow( 'sm' ) %?><a href="?cmd=sm"><?% gettext("Memory",20) %?></a><br /><?% END %?>
        <?% IF allow( 'sn' ) %?><a href="?cmd=sn"><?% gettext("Network",20) %?></a><br /><?% END %?>
        <?% IF allow( 'sa' ) %?><!--<a href="?cmd=sa">Alle Informationen</a><br />--><?% END %?>
    </td>
    </tr>
    <tr><td class="sidebottom"></td></tr>
  </table>
  <p id="sidefooter">&nbsp;</p>
</div>
<?% END %?>

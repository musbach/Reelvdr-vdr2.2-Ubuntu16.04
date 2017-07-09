        <?% head = abbr | replace ('<br />',' ') %?>
        <?% short = chop(head,32) %?>
        <?% IF short != head %?>
    <td style="vertical-align: top;" onMouseover="ttp(this,'<?% escape(short) %?>','<?% escape(abbr) %?>');">
        <?% short %?>
        <?% ELSE %?>
    <td style="vertical-align: top;">
        <?% head %?>
        <?% END %?>
    </td>

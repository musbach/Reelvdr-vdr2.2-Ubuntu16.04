  <?% IF cmd && linkid;
      link="?cmd=${cmd}&amp;data=${linkid}";
      END;
      IF !ttp_offset;
          ttp_offset = 0;
      END;
      IF !ttp_offset;ttp_offset = 0;END %?>
                    <a href="<?% IF link;link;ELSE;"#";END %?>"<?% IF eventid %?> 
                       onmouseover="ttpreq(this, '<?% escape(title) %?>
                                                   <?% IF subtitle.length > 0 %?>~<?% escape(subtitle) %?>
                                                   <?% END %?>',<?% eventid %?>, <?% ttp_offset %?>);"
                      <?% END %?> >
                      <img src="images/info.<?% global.imagetyp %?>" alt="" title="" />
                    </a>

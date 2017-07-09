#!/bin/bash
#set -x

DVD_CONF_DIR="$(yac_choosedir conf/dvd/$DVD_MENU)/conf/dvd"

if [ "$DVD_MENU" != "" ] && [ -d ${DVD_CONF_DIR}/${DVD_MENU} ] ; then
   if [ -f "${DVD_CONF_DIR}/${DVD_MENU}/menu.conf" ] ; then
      source "${DVD_CONF_DIR}/${DVD_MENU}/menu.conf"
   fi
fi
source "${DVD_CONF_DIR}/menu.conf"

CONVERT_VDR_INFO="${YAC_DIR}/yac_format_info.sh"
TEMP_DIR=${TEMP_DIR:=/tmp/dvd_menu}

[ ! -d "$TEMP_DIR" ] && mkdir "$TEMP_DIR"

[ "$MENU_AUDIO" = "" ] && MENU_AUDIO="$TEMP_DIR/tst.mp2"

# Names of Menu images
MM_BUTTON_IMAGE="${DVD_CONF_DIR}/${DVD_MENU}/mm-button.png"
MM_BACKGROUND_IMAGE="${DVD_CONF_DIR}/${DVD_MENU}/mm-background.png"

TM_BUTTON_IMAGE="${DVD_CONF_DIR}/${DVD_MENU}/tm-button.png"
TM_BACKGROUND_IMAGE="${DVD_CONF_DIR}/${DVD_MENU}/tm-background.png"

# Names of temp images
EMPTY_PAGE=${TEMP_DIR}/empty_page.png
TM_IMG_BACKGROUND=${TEMP_DIR}/tm_background.png
TM_IMG_TITLE_BG=${TEMP_DIR}/tm_title_bg.png
TM_IMG_TEXT_BG=${TEMP_DIR}/tm_text_bg.png
TM_IMG_BUTTON_TXT_BG=${TEMP_DIR}/tm_button_txt_bg.png
TM_IMG_BUTTON_TXT_MIN=${TEMP_DIR}/tm_button_txt_min.png
TM_IMG_BUTTON_TXT_UP=${TEMP_DIR}/tm_button_txt_up.png
TM_IMG_BUTTON_TXT_DOWN=${TEMP_DIR}/tm_button_txt_down.png
TM_IMG_BUTTON_TXT_ALL=${TEMP_DIR}/tm_button_txt_all.png
TM_IMG_BUTTON_PLAY=${TEMP_DIR}/tm_button_play.png
TM_IMG_BUTTON_MENU=${TEMP_DIR}/tm_button_menu.png
TM_IMG_BUTTON_UP=${TEMP_DIR}/tm_button_up.png
TM_IMG_BUTTON_DOWN=${TEMP_DIR}/tm_button_down.png
TM_IMG_BUTTON_BG_MIN=${TEMP_DIR}/tm_button_bg_min.png
TM_IMG_BUTTON_BG_UP=${TEMP_DIR}/tm_button_bg_up.png
TM_IMG_BUTTON_BG_DOWN=${TEMP_DIR}/tm_button_bg_down.png
TM_IMG_BUTTON_BG_ALL=${TEMP_DIR}/tm_button_bg_all.png
TM_IMG_BG_MIN=${TEMP_DIR}/tm_bg_min.png
TM_IMG_BG_UP=${TEMP_DIR}/tm_bg_up.png
TM_IMG_BG_DOWN=${TEMP_DIR}/tm_bg_down.png
TM_IMG_BG_ALL=${TEMP_DIR}/tm_bg_all.png

function create_menu_mpeg() {
   bg_image=$1
   button_image=$2
   target=$3
   aud_len=0
   if [ -s $MENU_AUDIO ] ; then
      al="$(mplayer -quiet -identify -frames 0 -vo null -ao null $MENU_AUDIO 2>/dev/null | grep '^ID_LENGTH' | cut -f 2 -d "=" |cut -f 1 -d ".")" 
      if [ $al -gt 0 ] ; then
         aud_len=$al
      fi
      if [ "$aud_len" = "0" ] ; then
         log "$MENU_AUDIO kann nicht identifiziert werden - default audio wird genommen"
         MENU_AUDIO=$TEMP_DIR/tst.mp2
         if [ -s $MENU_AUDIO ] ; then
            al="$(mplayer -quiet -identify -frames 0 -vo null -ao null $MENU_AUDIO 2>/dev/null | grep '^ID_LENGTH' | cut -f 2 -d "=" |cut -f 1 -d ".")" 
            if [ $al -gt 0 ] ; then
               aud_len=$al
            fi
         fi
      fi
   fi
   if [ "$aud_len" = "0" ] ; then
      acodec=${MENU_AUDIO##*.}
      aud_len=4
      #ffmpeg -f s16le -i /dev/zero -ac 2 -ar 48000 -ab 224k -t 4 -acodec $acodec -y $MENU_AUDIO
      cp ${DVD_CONF_DIR}/dvd_menu_background.$acodec $MENU_AUDIO
   fi
   video_file=${target%.*}.m2v
   png2yuv -j ${bg_image}  -f 25 -n 1 -I t -L 1 | mpeg2enc -f 8 -F 3 -a 2 -n p -o ${video_file}
   menu_xml=${target%.*}.xml
   echo "<?xml version=\"1.0\" encoding=\"iso8859-15\"?>" > $menu_xml
   echo "  <subpictures>" >> $menu_xml
   echo "    <stream>" >> $menu_xml
   echo "      <spu force=\"yes\" start=\"00:00:00.00\"" >> $menu_xml
   echo "           image=\"${EMPTY_PAGE}\"" >> $menu_xml
   echo "           select=\"${EMPTY_PAGE}\"" >> $menu_xml
   echo "           highlight=\"${button_image}\"" >> $menu_xml
   echo "           autooutline=\"infer\" outlinewidth=\"5\" autoorder=\"columns\">" >> $menu_xml
   echo "      </spu>" >> $menu_xml
   echo "    </stream>" >> $menu_xml
   echo "  </subpictures>" >> $menu_xml

   FIFO=${TEMP_DIR}/mplex.fifo
   if [ ! -p $FIFO ] ; then
      rm -f $FIFO
      mkfifo $FIFO
   fi
   mplex -f 8 -o $FIFO ${video_file} $MENU_AUDIO | \
                spumux -v 2 "$menu_xml" < $FIFO > ${target}
   rm -f $FIFO
}

function dvd_make_menu() {
   dvd_title=$1
   dvd_dir=$2
   shift; shift
   num_videos="$#"

   make_title_default_images $num_videos
   dvd_author_xml=${TEMP_DIR}/dvd.xml

   echo "<dvdauthor dest=\"${dvd_dir}\">" > $dvd_author_xml
   echo "<vmgm>" >> $dvd_author_xml
   if [ $num_videos -gt 1 ] ; then
      make_main_menu "$dvd_title" $num_videos "$dvd_author_xml"
   fi
   echo "</vmgm>" >> $dvd_author_xml

   idx=0
   for i in "$@" ; do
      idx=$(($idx + 1))
      xml_file="${TEMP_DIR}/title-${idx}.xml"
      make_title_menu $idx "$i" "$xml_file" $num_videos
      cat $xml_file >> $dvd_author_xml
   done

   echo "</dvdauthor>" >> $dvd_author_xml
   execute "dvdauthor -x $dvd_author_xml"
}

function make_main_menu() {
   dvd_title=$1
   num_videos=$2
   xml_out=$3

   MM_IMG_TITLE_BG=${TEMP_DIR}/mm_title_bg.png
   MM_IMG_TITLE=${TEMP_DIR}/mm_title.png
   MM_IMG_BUTTON=${TEMP_DIR}/mm_button.png
   MM_MENU_MPG=${TEMP_DIR}/mainmenu.mpg
   MM_MENU_IMG=${TEMP_DIR}/mainmenu.png
   MM_MENU_TXT=${TEMP_DIR}/mainmenu_txt
   [ -f $MM_MENU_TXT ] && rm -f $MM_MENU_TXT

   execute "convert \"$MM_BACKGROUND_IMAGE\" -resize ${PAGE_WIDTH}x${PAGE_HEIGHT}! -matte ${MM_MENU_IMG}"
   execute "convert -size $MM_TITLE_SIZE xc:none ${MM_IMG_TITLE_BG}"

   idx=0
   while [ $idx -lt $num_videos ] ; do
      idx=$(($idx + 1))
      execute "convert -background none -font $MM_TEXT_FONT -fill $MM_TEXT_COLOR" \
                  " -size 960x70 xc:none -pointsize $MM_TEXT_FONTSIZE" \
                  " -annotate +20+20 \"${REC_TITLE[$idx]}\" -trim +repage ${TEMP_DIR}/mm_text_$idx.png"
   done

   # Calculate button_size and position
   bt_dim=$(identify "${TEMP_DIR}/mm_text_1.png" | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   bt_text_width=${bt_dim%x*}
   bt_text_height=${bt_dim#*x}

   # Button and Button text for play
   button_size=$(identify ${MM_BUTTON_IMAGE} | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   button_width=${button_size%x*}
   button_height=${button_size#*x}

   mm_text_height=${MM_TEXT_SIZE#*x}
   mt_y=${MM_TEXT_POS##*+}

   bt_diff=$(($button_height - $bt_text_height))
   if [ $bt_diff -gt 0 ] ; then
       mm_text_height=$(($mm_text_height - $bt_diff))
       mt_y=$(($mt_y + ($bt_diff / 2)))
   else
       bt_diff=0
   fi

   mb_x=${MM_TEXT_POS%+*}
   mb_x=${mb_x#+}
   mt_x=$((${mb_x} + $button_width + 5))

   # By default leave on line space between two lines
   mm_tot_text_height=$((($num_videos * 2 - 1) * $bt_text_height))

   if [ $mm_tot_text_height -le $mm_text_height ] ; then
      mt_y=$((${mt_y} + (($mm_text_height - $mm_tot_text_height) / 2)))
      line_height=$(($bt_text_height * 2))
   else
      line_height=$(($mm_text_height / $num_videos))
   fi

   mb_y=$(($mt_y - ($bt_diff / 2)))

   # Create Title and write it into Background
   execute "convert -background none -font $MM_TITLE_FONT -fill $MM_TITLE_COLOR" \
               " -size 960x70 xc:none -pointsize $MM_TITLE_FONTSIZE" \
               " -annotate +20+20 \"${dvd_title}\" -trim +repage ${MM_IMG_TITLE}"
   execute "composite -compose Over -gravity west ${MM_IMG_TITLE} ${MM_IMG_TITLE_BG}" \
               "  ${MM_IMG_TITLE}"

   execute "composite -compose Over -geometry ${MM_TITLE_POS} ${MM_IMG_TITLE}" \
               " ${MM_MENU_IMG} ${MM_MENU_IMG}"

   cp ${EMPTY_PAGE} ${MM_IMG_BUTTON}
   echo "  <menus>" >> $xml_out
   echo "    <video format=\"pal\"></video>" >> $xml_out
   echo "    <pgc entry=\"title\">" >> $xml_out
   echo "      <vob file=\"${MM_MENU_MPG}\"></vob>" >> $xml_out
   idx=0
   while [ $idx -lt $num_videos ] ; do
      idx=$(($idx + 1))
      echo "        <button>jump titleset $idx menu;</button>" >> $xml_out
      # Write Button into Button-Background
      execute "composite -compose Over -geometry +${mb_x}+${mb_y} ${MM_BUTTON_IMAGE}" \
                  " ${MM_IMG_BUTTON} ${MM_IMG_BUTTON}"
      # Write text it intoText- Background
      execute "composite -compose Over -geometry +${mt_x}+${mt_y} ${TEMP_DIR}/mm_text_$idx.png" \
                  " ${MM_MENU_IMG} ${MM_MENU_IMG}"

      mb_y=$(($mb_y + $line_height))
      mt_y=$(($mt_y + $line_height))
   done
   create_menu_mpeg ${MM_MENU_IMG} ${MM_IMG_BUTTON} ${MM_MENU_MPG}
   echo "    </pgc>" >> $xml_out
   echo "  </menus>" >> $xml_out
}


function make_title_menu() {
   idx=$1
   rec_dir=${REC_DIR[$idx]}
   rec_len=$((${REC_LEN[$idx]} / 60))
   title=${REC_TITLE[$idx]}
   video_mpeg="$2"
   xml_out="$3"
   num_videos=$4

   TMP_IMG=${TEMP_DIR}/tmp_${idx}.png
   TMP_INFO=${TEMP_DIR}/vdr_info_${idx}

   # Calculate possible text len
   text_width=${TM_TEXT_SIZE%x*}
   text_height=${TM_TEXT_SIZE#*x}
   ln_chars=$(($text_width * 2 / $TM_TEXT_FONTSIZE))
   [ -f ${TMP_IMG} ] && rm ${TMP_IMG}
   $CONVERT_VDR_INFO "$(resolve_recfile ${rec_dir}/info)" $ln_chars >${TMP_INFO}
   [ ! -s ${TMP_INFO} ] && echo "No Text" > ${TMP_INFO}
   convert -background none -font $TM_TEXT_FONT -fill white -size 960x5760 xc:none -pointsize $TM_TEXT_FONTSIZE \
           -annotate +20+20 @${TMP_INFO} -trim +repage ${TMP_IMG}
   size=$(identify ${TMP_IMG} | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   while [ ${size%x*} -gt $text_width ] ; do
      rm ${TMP_IMG}
      ln_chars=$(($ln_chars * $text_width / ${size%x*}))
      $CONVERT_VDR_INFO "$(resolve_recfile ${rec_dir}/info)" $ln_chars >${TMP_INFO}
      convert -background none -font $TM_TEXT_FONT -fill white -size 960x5760 xc:none -pointsize $TM_TEXT_FONTSIZE \
              -annotate +20+20 @${TMP_INFO} -trim +repage ${TMP_IMG}
      size=$(identify ${TMP_IMG} | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   done
   tot_lines=$(cat ${TMP_INFO}|wc -l)   
   max_pg_lines=$(($text_height * $tot_lines / ${size#*x}))
   pages=$(((($tot_lines - 1) / $max_pg_lines) + 1))
   pg_lines=$(((($tot_lines - 1) / $pages) + 1))
   if [ $pg_lines -lt $max_pg_lines ] ; then
      view_lines=$(($pg_lines + 1))
   else
      view_lines=$pg_lines
   fi

   # Create Title and write it into Background
   TITLE_IMAGE=${TEMP_DIR}/tm_title_${idx}.png
   TITLE_BG_IMAGE=${TEMP_DIR}/tm_background_${idx}.png
   execute "convert -background none -font $TM_TITLE_FONT -fill $TM_TITLE_COLOR" \
               " -size 960x70 xc:none -pointsize $TM_TITLE_FONTSIZE" \
               " -annotate +20+20 \"$title\" -trim +repage ${TITLE_IMAGE}"
   execute "composite -compose Over -gravity west ${TITLE_IMAGE} ${TM_IMG_TITLE_BG}" \
               "  ${TITLE_IMAGE}"

   echo "  <titleset>" > $xml_out
   echo "    <menus>" >> $xml_out
#   echo "      <video aspect=\"4:3\"/>" >> $xml_out
   act_page=0
   rest_lines=$tot_lines
   while [ $rest_lines -gt 0 ] ; do
      act_page=$(($act_page + 1))
      MENU_MPG=${TEMP_DIR}/menu_${idx}_${act_page}.mpg
      PG_INFO=${TEMP_DIR}/text_${idx}_${act_page}
      tail -n $rest_lines ${TMP_INFO} | head -n $view_lines > ${PG_INFO}
      rest_lines=$(($rest_lines - $pg_lines))
      execute "convert -background none -font $TM_TEXT_FONT -fill white -size 960x5760 xc:none -pointsize $TM_TEXT_FONTSIZE" \
                 " -annotate +20+20 @${PG_INFO} -trim +repage ${PG_INFO}.png"
      execute "composite -compose Over -gravity west ${PG_INFO}.png" \
                  " ${TM_IMG_TEXT_BG} ${PG_INFO}.png"
      if [ $act_page -eq 1 ] ; then
         echo "      <pgc entry=\"root\">" >> $xml_out
         echo "        <pre>button=1024;</pre>" >> $xml_out
         echo "        <vob file=\"${MENU_MPG}\" pause=\"inf\"/>" >> $xml_out
         echo "        <button>jump title 1 chapter 1;</button>" >> $xml_out
         if [ $pages -gt 1 ] ; then
            echo "        <button>g3=1;jump menu 2;</button>" >> $xml_out
            BG_IMG="${TM_IMG_BG_DOWN}"
            BUT_IMG="${TM_IMG_BUTTON_BG_DOWN}"
         else
            BG_IMG="${TM_IMG_BG_MIN}"
            BUT_IMG="${TM_IMG_BUTTON_BG_MIN}"
         fi
      elif [ $rest_lines -gt 0 ] ; then
         lp=$(($act_page - 1))
         np=$(($act_page + 1))
         echo "      <pgc>" >> $xml_out
         echo "        <pre>if (g3 eq ${lp}){button=3072;}" >> $xml_out
         echo "             if (g3 eq ${np}){button=1024;}" >> $xml_out
         echo "        </pre>" >> $xml_out
         echo "        <vob file=\"${MENU_MPG}\" pause=\"inf\"/>" >> $xml_out
         echo "        <button>g3=${act_page};jump menu ${lp};</button>" >> $xml_out
         echo "        <button>jump title 1 chapter 1;</button>" >> $xml_out
         echo "        <button>g3=${act_page};jump menu ${np};</button>" >> $xml_out
         BG_IMG="${TM_IMG_BG_ALL}"
         BUT_IMG="${TM_IMG_BUTTON_BG_ALL}"
      else
         lp=$(($act_page - 1))
         echo "      <pgc>" >> $xml_out
         echo "        <pre>button=2048;</pre>" >> $xml_out
         echo "        <vob file=\"${MENU_MPG}\" pause=\"inf\"/>" >> $xml_out
         echo "        <button>g3=${act_page};jump menu ${lp};</button>" >> $xml_out
         echo "        <button>jump title 1 chapter 1;</button>" >> $xml_out
         if [ $pages -gt 1 ] ; then
            BG_IMG="${TM_IMG_BG_UP}"
            BUT_IMG="${TM_IMG_BUTTON_BG_UP}"
         else
            BG_IMG="${TM_IMG_BG_MIN}"
            BUT_IMG="${TM_IMG_BUTTON_BG_MIN}"
         fi
      fi
      [ $num_videos -gt 1 ] && echo "        <button>jump vmgm menu;</button>" >> $xml_out
      execute "composite -compose Over -geometry $TM_TEXT_POS ${PG_INFO}.png" \
                  " ${BG_IMG} ${TITLE_BG_IMAGE}"
      execute "composite -compose Over -geometry $TM_TITLE_POS ${TITLE_IMAGE}" \
                  " ${TITLE_BG_IMAGE} ${TITLE_BG_IMAGE}"
      create_menu_mpeg ${TITLE_BG_IMAGE} ${BUT_IMG} ${MENU_MPG}
      echo "      </pgc>" >> $xml_out
   done
   echo "    </menus>" >> $xml_out

   dvd_get_chapters "$rec_dir" $rec_len
   echo "    <titles>" >> $xml_out
#   echo "      <video aspect=\"4:3\"/>" >> $xml_out
   echo "      <pgc>" >> $xml_out
   echo "        <vob file=\"${video_mpeg}\" chapters=\"$CHAPTERS\"/>" >> $xml_out
   echo "        <post>call menu;</post>" >> $xml_out
   echo "      </pgc>" >> $xml_out
   echo "    </titles>" >> $xml_out
   echo "  </titleset>" >> $xml_out
}


function make_title_default_images() {
   num_titles=$1
   execute "convert \"$TM_BACKGROUND_IMAGE\" -resize ${PAGE_WIDTH}x${PAGE_HEIGHT}! -matte ${TM_IMG_BACKGROUND}"
   execute "convert -size $TM_TITLE_SIZE xc:none ${TM_IMG_TITLE_BG}"
   execute "convert -size $TM_TEXT_SIZE xc:none ${TM_IMG_TEXT_BG}"
   execute "convert -size $TM_BUTTON_SIZE xc:none ${TM_IMG_BUTTON_TXT_BG}"
   execute "convert -size ${PAGE_WIDTH}x${PAGE_HEIGHT} xc:none ${EMPTY_PAGE}"

   # Button and Button text for play
   execute "convert -background none -font $TM_BUTTON_FONT -fill $TM_BUTTON_COLOR" \
               " -size 960x50 xc:none -pointsize $TM_BUTTON_FONTSIZE" \
               " -annotate +20+20 $TM_BUTTON_PLAY -trim +repage ${TM_IMG_BUTTON_PLAY}"
   execute "composite -compose Over -gravity southwest ${TM_IMG_BUTTON_PLAY}" \
               " ${TM_IMG_BUTTON_TXT_BG} ${TM_IMG_BUTTON_TXT_MIN}"

   # Calculate button_size and position
   bt_dim=$(identify ${TM_IMG_BUTTON_PLAY} | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   bt_text_width=${bt_dim%x*}
   bt_text_height=${bt_dim#*x}
   button_size=$(identify ${TM_BUTTON_IMAGE} | grep -o -e " [0-9]\{1,\}x[0-9]\{1,\} ")
   button_width=${button_size%x*}
   button_height=${button_size#*x}
   bth_diff=$((($button_height-$bt_text_height)/2))
   B1X=${TM_BUTTON_POS%+*}
   B1X=${B1X#+}
   B1Y=${TM_BUTTON_POS##*+}
   B4X=$(($B1X + ${TM_BUTTON_SIZE%x*}))
   B4Y=$(($B1Y + ${TM_BUTTON_SIZE#*x}))

   b1x=$(($B1X - $button_width - 5))
   b1y=$(($B1Y - $bth_diff))
   b2x=$(($B4X + 5))
   b2y=$b1y
   b3x=$b1x
   b3y=$(($B4Y + $bth_diff - $button_height))
   b4x=$b2x
   b4y=$b3y

   execute "composite -compose Over -geometry +${b3x}+${b3y} ${TM_BUTTON_IMAGE}" \
               " ${EMPTY_PAGE} ${TM_IMG_BUTTON_BG_MIN}"

   if [ $num_titles -gt 1 ] ; then
      # Button and Button text for menu
      execute "convert -background none -font $TM_BUTTON_FONT -fill $TM_BUTTON_COLOR" \
                 " -size 960x50 xc:none -pointsize $TM_BUTTON_FONTSIZE" \
                 " -annotate +20+20 $TM_BUTTON_MENU -trim +repage ${TM_IMG_BUTTON_MENU}"
      execute "composite -compose Over -gravity southeast ${TM_IMG_BUTTON_MENU}" \
                 " ${TM_IMG_BUTTON_TXT_MIN} ${TM_IMG_BUTTON_TXT_MIN}"
      execute "composite -compose Over -geometry +${b4x}+${b4y} ${TM_BUTTON_IMAGE}" \
                 " ${TM_IMG_BUTTON_BG_MIN} ${TM_IMG_BUTTON_BG_MIN}"
   fi

   # Buttons and Button text for page up and down
   execute "convert -background none -font $TM_BUTTON_FONT -fill $TM_BUTTON_COLOR" \
              " -size 960x50 xc:none -pointsize $TM_BUTTON_FONTSIZE" \
              " -annotate +20+20 $TM_BUTTON_DOWN -trim +repage ${TM_IMG_BUTTON_DOWN}"
   execute "convert -background none -font $TM_BUTTON_FONT -fill $TM_BUTTON_COLOR" \
              " -size 960x50 xc:none -pointsize $TM_BUTTON_FONTSIZE" \
              " -annotate +20+20 $TM_BUTTON_UP -trim +repage ${TM_IMG_BUTTON_UP}"
   execute "composite -compose Over -gravity northeast ${TM_IMG_BUTTON_DOWN}" \
               " ${TM_IMG_BUTTON_TXT_MIN} ${TM_IMG_BUTTON_TXT_DOWN}"
   execute "composite -compose Over -gravity northwest ${TM_IMG_BUTTON_UP}" \
               " ${TM_IMG_BUTTON_TXT_MIN} ${TM_IMG_BUTTON_TXT_UP}"
   execute "composite -compose Over -gravity northwest ${TM_IMG_BUTTON_UP}" \
               " ${TM_IMG_BUTTON_TXT_DOWN} ${TM_IMG_BUTTON_TXT_ALL}"

   # Background Image for Page_up / Page_down / All
   execute "composite -compose Over -geometry $TM_BUTTON_POS ${TM_IMG_BUTTON_TXT_DOWN}" \
               " ${TM_IMG_BACKGROUND} ${TM_IMG_BG_DOWN}"
   execute "composite -compose Over -geometry $TM_BUTTON_POS ${TM_IMG_BUTTON_TXT_UP}" \
               " ${TM_IMG_BACKGROUND} ${TM_IMG_BG_UP}"
   execute "composite -compose Over -geometry $TM_BUTTON_POS ${TM_IMG_BUTTON_TXT_ALL}" \
               " ${TM_IMG_BACKGROUND} ${TM_IMG_BG_ALL}"
   execute "composite -compose Over -geometry $TM_BUTTON_POS ${TM_IMG_BUTTON_TXT_MIN}" \
               " ${TM_IMG_BACKGROUND} ${TM_IMG_BG_MIN}"
   execute "composite -compose Over -geometry +${b2x}+${b2y} ${TM_BUTTON_IMAGE}" \
               " ${TM_IMG_BUTTON_BG_MIN} ${TM_IMG_BUTTON_BG_DOWN}"
   execute "composite -compose Over -geometry +${b1x}+${b1y} ${TM_BUTTON_IMAGE}" \
               " ${TM_IMG_BUTTON_BG_MIN} ${TM_IMG_BUTTON_BG_UP}"
   execute "composite -compose Over -geometry +${b1x}+${b1y} ${TM_BUTTON_IMAGE}" \
               " ${TM_IMG_BUTTON_BG_DOWN} ${TM_IMG_BUTTON_BG_ALL}"
}


function dvd_get_chapters {
   vid_dir=$1
   vid_len=$2
   CHAPTERS=""
   if [ "$CHAPTER_MARKS" != "" -a -s $(resolve_recfile ${vid_dir}/marks) ] ; then
      marks=$(cat $(resolve_recfile ${vid_dir}/marks) | cut -f 1 -d " ")
      CHAPTERS="0"
      for i in $marks ; do
         if [ "${i#0:00_00}" = "$i" ] ; then
            CHAPTERS="${CHAPTERS},${i%% *}"
         fi
      done
   elif [ $CHAPTER_MIN -gt 0 ] ; then
      CHAPTERS="0"
      next_chap=$CHAPTER_MIN 
      while [ $next_chap -lt $vid_len ] ; do
         sh=$(($next_chap/60))
         sm=$(($next_chap%60))
         CHAPTERS="$(printf "%s,%d:%02d:00" "${CHAPTERS}" $sh $sm)"
         next_chap=$(($next_chap + $CHAPTER_MIN))
      done
   fi
}


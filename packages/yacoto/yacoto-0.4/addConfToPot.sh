#!/bin/sh
TARGET="$(pwd)/$2"
cd $1

sh ./yac_setplgconf.sh
cd ..
grep "~" yacoto/yacadmin.conf | cut -f 7 -d "~" |sort -u | while read i ; do
   if [ "$(grep "msgid \"$i\"" $TARGET)" = "" ] ; then
      echo "" >> $TARGET
      echo "msgid \"$i\"" >> $TARGET
      echo "msgstr \"\"" >> $TARGET
   fi      
done

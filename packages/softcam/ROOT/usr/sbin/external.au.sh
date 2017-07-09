#! /bin/sh

SOFTCAMDIR=/etc/vdr/plugins/sc
TPSBINDIR=/etc/vdr/plugins/sc/viaccess

SOFTCAMURL=http://www.freecardsharing.com/SoftCam.Key
TPSBINURL=http://digitv.di.funpic.de/tps.bin
TMP=/tmp


start_update () {


if [ -e $TMP/SoftCam.Key ]; then
 echo "Datei existiert, loesche..."
 rm -f $TMP/SoftCam.Key
fi

if [ -e $TMP/tps.bin ]; then
 echo "Datei existiert, loesche..."
 rm -f $TMP/tps.bin
fi


cd $TMP
wget --directory-prefix=$TMP $SOFTCAMURL
cp /tmp/SoftCam.Key $SOFTCAMDIR

cd $TMP
wget --directory-prefix=$TMP $TPSBINURL
cp /tmp/tps.bin $TPSBINDIR

svdrpsend.sh mesg 'Key Update erfolgreich'
svdrpsend.sh PLUG sc reload

}
start_update >/dev/null 2>&1 &


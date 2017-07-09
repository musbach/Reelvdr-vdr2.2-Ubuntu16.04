#!/bin/bash
YAC_CONF_DIR="${YAC_CONF_DIR:=/etc/vdr/plugins/yacoto}"
YAC_CONF="${YAC_CONF_DIR}/yacoto.conf"
YAC_DIR="${YAC_DIR:=/usr/share/vdr/yacoto}"

cd "${YAC_DIR}"

if [ ! -f $YAC_CONF ] ; then
   logger -s "Yac config <$CONFIG> nicht vorhanden"
   exit
fi
source $YAC_CONF
if [ ! -f "${YAC_CONF_DIR}/conf/$CONFIG.conf" ] ; then
   logger -s "Yac config <${YAC_CONF_DIR}/conf/$CONFIG.conf> nicht vorhanden"
   exit
fi
logger -s "$0"

NICE_LEVEL=${NICE_LEVEL:=10}

[ ! -d "queue" ] && mkdir "queue"

dt=$(date +%s)
tmpFile="queue/yac_queue_$dt.sh"

while [ -f $tmpFile ] ; do
   dt=$(($dt + 1))
   tmpFile="queue/yac_queue_$dt.sh"
done

echo "#!/bin/bash" >$tmpFile

cat $YAC_CONF >> $tmpFile
echo ""  >> $tmpFile
cat ${YAC_CONF_DIR}/conf/$CONFIG.conf  >> $tmpFile

parms=""
for i in "$@" ; do
   touch "${i%%~*}/yacoto.log"
   parms="$parms \"$i\""
done   
echo "PATH=$PATH:/usr/local/bin"  >> $tmpFile
echo ". ./yac_exec.sh $parms" >> $tmpFile
chmod +x $tmpFile
if [ "$(pidof -x $YAC_DIR/yac_manager.sh)" = "" ] ; then
   screen -dm sh -c "nice -n $NICE_LEVEL $YAC_DIR/yac_manager.sh"
   sleep 2
fi

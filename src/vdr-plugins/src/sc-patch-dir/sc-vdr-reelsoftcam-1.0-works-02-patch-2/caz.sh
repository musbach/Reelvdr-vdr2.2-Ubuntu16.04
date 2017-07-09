#!/bin/sh
ENABLED_PLUGINS="cardclient conax constcw cryptoworks irdeto nagra nds sc-conax sc-cryptoworks sc-irdeto sc-nagra sc-seca sc-viaccess sc-videoguard2 seca shl viaccess"
for plugin in $ENABLED_PLUGINS; do
rm systems/$plugin/libsc-*.so 
rm systems/$plugin/libsc-*.so*
rm systems/$plugin/*.o
rm systems/$plugin/.dependencies
done
rm libvdr*
rm .dependencies

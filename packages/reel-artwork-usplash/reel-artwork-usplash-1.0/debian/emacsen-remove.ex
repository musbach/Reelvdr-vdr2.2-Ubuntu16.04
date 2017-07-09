#!/bin/sh -e
# /usr/lib/emacsen-common/packages/remove/reel-artwork-usplash

FLAVOR=$1
PACKAGE=reel-artwork-usplash

if [ ${FLAVOR} != emacs ]; then
    if test -x /usr/sbin/install-info-altdir; then
        echo remove/${PACKAGE}: removing Info links for ${FLAVOR}
        install-info-altdir --quiet --remove --dirname=${FLAVOR} /usr/info/reel-artwork-usplash.info.gz
    fi

    echo remove/${PACKAGE}: purging byte-compiled files for ${FLAVOR}
    rm -rf /usr/share/${FLAVOR}/site-lisp/${PACKAGE}
fi

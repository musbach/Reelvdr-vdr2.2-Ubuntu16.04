#!/bin/bash

if [ -x /usr/sbin/915resolution ]; then
    . /etc/default/915resolution
    if [ "$MODE" = auto ] || [ -n "$MODE" -a -n "$XRESO" -a -n "$YRESO" ] ; then
	/etc/init.d/915resolution start;
    fi
fi

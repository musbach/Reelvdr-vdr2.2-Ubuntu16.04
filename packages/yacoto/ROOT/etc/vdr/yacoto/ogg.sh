#!/bin/sh
lame --decode --mp2input "$1" - | oggenc - -o "$2"

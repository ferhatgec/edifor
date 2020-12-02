#!/bin/sh

gcc -I./include/ -I./libraries/ \
./src/CFunctions.c              \
./src/Tools.c                   \
./src/Edifor.c -o     /bin/edifor

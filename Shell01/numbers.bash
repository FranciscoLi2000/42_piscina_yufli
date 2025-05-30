#!/bin/bash

echo $FT_NBR1 + $FT_NBR2 \
| tr "'\\\"?!mrdoc" "01234 01234" \
| awk '{print "ibase=5;" $1 "+ " $3}' \
| bc \
| tr '0123456789ABC' 'gtaio luSnemf'

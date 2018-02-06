#!/bin/sh
cd ~
mkdir -p public_html/lab9
chmod 755 public_html
chmod 755 public_html/lab9
chmod 711 ~
cp -r /comp/15/files/lab09/* public_html/lab9/
cd public_html/lab9
chmod a+r *
chmod a+x *.cgi



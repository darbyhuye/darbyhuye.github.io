#!/bin/sh
#
# Build a trie executable on the web server
# Results in a page containing all the output of make
# both from stdout and stderr.

#
# Tell browser we're just giving it plain text
#
printf "Content-Type:  text/plain\r\n\r\n"

#
# Send standard error output to standard out so
# web page sees everything
#
exec 2>&1

printf "Compiling on web server\n"

#
# Build an executable here on the web server
#
make trie_web

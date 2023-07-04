#!/bin/bash

if [ $# -ne 0 ]
then
	echo Usage: $0 Alicia
else
	wget -O /tmp/alicia.txt "https://www.gutenberg.org/files/11/11-0.txt"
	sed -n '11, 20p' /tmp/alicia.txt | sort
fi
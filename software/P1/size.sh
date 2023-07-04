#!/bin/bash

if [ $# -ne 0 ]
then
	for i in $@
	do 
		echo Fichero $i
		du -s $i
		echo Contenido $i
		cat $i
		echo ""
		echo "******************"
	done
else
	echo Usage: $0 arguments required 
fi
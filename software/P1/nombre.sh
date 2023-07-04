#!/bin/bash

if [ $# -ne 1 ]
then
	echo " Usage: $0 <nombre>"
	exit 1
else
	echo hola $1
fi
exit 0
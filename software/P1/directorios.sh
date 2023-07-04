#!/bin/bash


if [ $# -ne 0 ]
then
	echo " Usage: $0 no arguments required"
	exit 1
else
	cd /etc/ 
	ls -lt | grep ^d
fi
exit 0
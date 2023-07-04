#!/bin/bash

if [ $# -ne 0 ]
then
	echo Usage: $0 host.txt
else
	wget -O /tmp/host.txt "https://labs.etsit.urjc.es/fingerprints.txt"
	list=`grep Host: /tmp/host.txt | cut -c 6-40`
	for host in $list
	do
		if ping -c1 $host
		then
			echo "$host ==> UP"
		else
			echo "$host ==> DOWN"
		fi
	done
fi
exit 0
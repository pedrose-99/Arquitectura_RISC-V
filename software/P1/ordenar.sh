#!/bin/bash

if [ $# -ne 0 ]
then
	echo Usage: $0 ordenar
else
	cd /etc/
	ls -lt | sed -n "11, 11p"
#Se selecciona la linea 11 porque al hacer ls -lt aparece en la 1 linea el total de archivos
fi
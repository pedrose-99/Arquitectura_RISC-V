#!/bin/bash

if [ $# -ne 0 ]
then
	echo " Usage: $0 no arguments required"
	exit 1
else
	echo Nombre: ; hostname
	echo "Directorio de mi cuenta: " $HOME
	echo "Directorio actual:"; pwd
	echo "Fecha"; date
	echo "*******************"
	echo Variables de entorno:
	echo '$HOME' $HOME
	echo '$PATH' $PATH
	echo '$SHELL' $SHELL
	echo '$USERNAME' $USERNAME
	echo "*******************"
	echo Ficheros en mi cuenta
	cd
	ls -p | grep -v /
	echo "*******************"
	echo Directorios en mi cuenta
	cd
	ls -d */

fi
exit 0
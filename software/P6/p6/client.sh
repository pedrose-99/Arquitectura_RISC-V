#!/bin/bash

cat godos.txt | while read linea
do
		./cliente $1 $linea &
done
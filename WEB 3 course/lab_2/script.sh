#!/bin/bash
mkdir group9
for line in $(grep '$' group9.txt)
do
	mkdir $line
	mv "$line" "group9"
done
mkdir group2
for line2 in $(grep '$' group2.txt)
do
	mkdir $line2
	mv "$line2" "group2"
done
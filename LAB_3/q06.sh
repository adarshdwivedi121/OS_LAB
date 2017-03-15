#!/bin/bash

var=` ls $(pwd) `
for i in $var
do
	if [ -d $i ]
	then 	continue
	else
		sed -e 's/^eg:/Example:/' -i $i
		sed -e 's/.eg/Example:/g' -i $i
		cat $i
	fi
done


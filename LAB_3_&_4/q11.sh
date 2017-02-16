#!/bin/bash

c=0

echo 'Enter the file name'
read f

until [ $c == 3 ]
do
	echo 'Enter your Option'
	echo '1. To search for the patterns in a file'
	echo '2. To delete all the occurances of the pattern in the file'
	echo '3. Exit'
	read c

	if [ $c == 1 ]
	then
		for i in $@
		do
			echo ` grep -n $@ $f `
		done
	
	elif [ $c == 2 ]
	then
		for i in $@
		do
			sed -e "s/$i//" -i $f
			cat $f
		done
	fi
done

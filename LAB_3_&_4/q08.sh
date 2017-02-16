#!/bin/bash

echo "Enter file name or 'no' to exit"
read i

LIST=()

while [ $i != no ]
do
	$(touch $i)
	LIST+=($i)
	echo "Enter file name or 'no' to exit"
	read i
done

for i in ${LIST[@]}
do
	echo "$i"
	echo "Enter 'Y' to delete and 'N' to continue."
	read x
	if [ $x == "Y" -o $x == "y" ]
	then	$(rm $(pwd)/$i)
	fi
done

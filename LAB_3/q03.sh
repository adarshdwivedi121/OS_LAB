#!/bin/bash

t=` ls -R $1 | grep 'txt' `

for i in $t
do
	mv $1/$i $1/${i/%txt/text}
done

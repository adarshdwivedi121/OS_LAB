#!/bin/bash

t=` ls $1 | grep $2 `
for i in $t
do
	echo $i
done

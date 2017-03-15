#!/bin/bash

cur=` pwd `
t=` ls $cur | grep $1 `

for i in $t
do
	cp $cur/$i $2$i
done

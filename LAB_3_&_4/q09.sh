#!/bin/bash

sort () {
    for ((i=0; i < ${#arr[@]}; i++))
    do
        for ((j=0; j < $((${#arr[@]} - 1)); j++))
        do
            if [ ${arr[i]} \< ${arr[j]} ]
            then
                tmp=${arr[i]}
                arr[i]=${arr[j]}
                arr[j]=$tmp
            fi
        done
    done
}


var=` echo $@ | fmt -1 `
arr=()
for i in $var
do
	arr+=($i)
done

sort ${arr[@]}
echo ${arr[@]}

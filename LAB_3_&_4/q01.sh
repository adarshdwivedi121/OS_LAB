#!/bin/bash

if [ -f $1 ]
then echo "Its an Ordinary File."
elif [ -d $1 ]
then echo "Its a directory."
fi

#!/bin/bash

case $1 in
	'linecount')	echo ` wc -l $2 `;;
	'wordcount')	echo ` wc -w $2 `;;
	'charcount')	echo ` wc -m $2 `;;
		  *)	echo "Not a valid combination";;
esac


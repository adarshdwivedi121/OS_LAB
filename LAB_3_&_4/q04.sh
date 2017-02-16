#!/bin/bash

GS=$(bc <<< $1+$2+0.1*$1)
echo $GS

#!/bin/bash

if [ ${#} -ne 1 ]
then
    echo "Usage: ./2.sh <train ID>"
    exit 0
fi

log=$(ls | grep -E "Trains_.")
f=./$1.txt

exist=0
for file in $(echo $log | tr ' ' '\n')
do
    echo "$file:" >> $f
    data=$(cat $file | cut -d',' -f2 | grep -E "^$1$")
    if [ ! -z "$data" ]
    then
        exist=1
        cat $file | grep -E ",$1," >> $f
    fi
done

if [ $exist -ne 1 ]
then 
    echo "No records found for train $1"
    rm $f
fi
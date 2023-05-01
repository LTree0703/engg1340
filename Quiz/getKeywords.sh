#!/bin/bash

if [ ${#} -lt 1 ]
then
    exit 0
fi

list=$(cat $1 | tr ' ' '\n' | tr ' ' '\n')
ans=""
occurrence=0
for word in $list
do
    count=$(echo $list | tr ' ' '\n' | grep -w $word | wc -l)
    if [ $count -gt $occurrence ]
    then
        ans=$word
        occurrence=$count
    elif [ $count -eq $occurrence ]
    then
        ans+=" $word"
    fi
done

for word in $(echo $ans | tr ' ' '\n' | sort -u) 
do
    echo $word $occurrence
done

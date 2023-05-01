#!/bin/bash

if [ ${#} -lt 1 ]
then
    exit 0
fi

list=$(cat $1 | tr ' ' '\n' | tr '  ' '\n')

duplicate=""

for word in $list
do
    if [ $(echo $duplicate | tr ' ' '\n' | grep -w $word | uniq | wc -l) -eq 1 ]
    then
        continue
    fi

    if [ $(echo $list | tr ' ' '\n' | grep -w $word | wc -l) -gt 1 ]
    then 
        duplicate+=" $word"
    fi

    echo $word
    
done

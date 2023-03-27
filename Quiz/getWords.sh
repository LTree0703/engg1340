#!/bin/bash
words=()
if [ $# -lt 1 ]
then
    exit 0
fi
for w in $(cat $1)
do 
    if [[ ! "${words[*]}" =~ "${w}" ]]
    then
        words+=("$w")
    fi
done
for w in $(echo "${words[*]}")
do 
    echo $w
done

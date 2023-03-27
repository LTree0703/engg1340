#!/bin/bash
if [ $# -lt 1 ]
then
    exit 0
fi

words=()
for word in $(cat $1)
do 
    words+=("$word")
done

most_occurring_words=()
freq=0
for w1 in ${words[*]}
do
    tmp=0
    for w2 in ${words[*]}
    do 
        if [ $w1 == $w2 ]
        then
            tmp=$((tmp+1))
        fi
    done
    if [ $tmp -gt $freq ]
    then
        freq=$tmp
        most_occurring_words=($w1)
    elif [ $tmp -eq $freq ]
    then
        most_occurring_words+=($w1)
    fi
done

for word in $(echo ${most_occurring_words[*]} | tr ' ' '\n' | sort -ru)
do 
    echo $word $freq
done


            
    


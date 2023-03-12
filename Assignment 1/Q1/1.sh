#!/bin/bash
files=$(ls | grep -E '.*.log')
data=$(cat $files | grep "$1" || echo "1")
if [ "$data" == "1" ]
then
    echo "No records found"
    exit 0
else
    IFS=$'\n'
    data=$(echo "$data" | cut -d',' -f2,3 | sort -t, -k2 | uniq )
    max=0
    most_popular_gateway=""
    for gate in $(echo "$data" | cut -d',' -f2 | uniq )
    do
        tmp=$(echo "$data" | grep $gate | wc -l | tr -d ' ')
        if [ $tmp -gt $max ]
        then
            max=$tmp
            most_popular_gateway=$(echo "$gate")
        elif [ $tmp -eq $max ]
        then
            most_popular_gateway+=$(echo -e "\n$gate")
        fi
    done
    for gate in $(echo "$most_popular_gateway" | sort -r )
    do
        echo "$max" "$gate"
    done
fi
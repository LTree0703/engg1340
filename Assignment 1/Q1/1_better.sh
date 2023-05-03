#!/bin/bash
IFS=$'\n' # internal field separator

data=$(cat *.log | grep -E "$1.*,.*,.*,.*" | cut -d',' -f2,3 | sort -k1 | uniq | cut -d',' -f2 | sort | uniq -c | sort -k1r)

if [ -z "$data" ]
then
    echo "No records found"
    exit 0
fi

highest=${data:3:1}
for i in $data
do
    if [ ${i:3:1} != $highest ]
    then
        break
    fi
    echo ${i:3}
done






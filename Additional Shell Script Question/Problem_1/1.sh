#!/bin/bash

log=$(ls | grep -E "Trains_.*")

for file in $(echo $log | tr ' ' '\n')
do
    echo $file:
    cat $file | grep -E 'E[0-9]' | cut -d',' -f3 | sort | uniq -c | sort -k1rn | head -3
done

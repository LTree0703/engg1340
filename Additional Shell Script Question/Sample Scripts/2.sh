#!/bin/bash
if [ $# -ne 1 ]
then
   echo "Usage: ./Train_trace.sh <train ID>"
   exit
else
#    rm "$1.txt"
	for file in Trains_*.txt
	do
        echo $file >> "$1.txt" 
	    grep -E ".*,$1,.*,.*" "$file" >> "$1.txt"
	    grep -E ".*,$1,.*,.*" "$file" >> "temp.temp"
	done
        #sort "temp.log" >> "$1.txt"
        #rm "temp.log" 
fi
if [ ! -s "temp.temp" ]
then
    echo "No records found for "$1
    rm "$1.txt"
fi
rm "temp.temp" 
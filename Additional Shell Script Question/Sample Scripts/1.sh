#!/bin/bash
allLog=`ls Trains*.txt`
for Log in $allLog
do
echo "$Log:"
	grep -E ".*,E.*,.*,.*" $Log | cut -d ',' -f 3 | sort | uniq -c | sort -k1,1r -k2,2 | head -3
done
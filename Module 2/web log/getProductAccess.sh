#!/bin/bash
cut -d$'\t' -f 1,4 $1 | grep -E "/products/" | sort | uniq
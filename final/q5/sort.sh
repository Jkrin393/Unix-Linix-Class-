#!/bin/bash

#array of files to sort

files=()

for file in *; do
	if [ -f "$file" ];
		then files+=("$file")
	fi
done

sorted=($(printf '%s\n' "${files[@]}" | sort))

for sfile in ${sorted[@]}; do
	echo $sfile
done










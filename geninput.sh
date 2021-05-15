#!/bin/sh

if [ $# -ne 1 ]; then
	printf "Usage: ./geninput.sh <nb>\n"
	exit 1
fi

nb=$1
seen=()

# Generate *nb* random numbers 

while [ $nb -gt 0 ]; do
	seen_flag=0
	random_nb=$RANDOM
	for nb_seen in ${seen[@]}; do
		[ $nb_seen -eq $random_nb ] && seen_flag=1 && break
	done
	[ $seen_flag -eq 1 ] && continue
	printf "%d " $random_nb
	nb=$(($nb-1))
	seen+=($random_nb)
done

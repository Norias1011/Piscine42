#!/bin/sh
while true
do
./map_gen.pl $((RANDOM % 100)) $((RANDOM % 30)) 3 > test.txt
cat test.txt
echo
./bsq test.txt
echo
echo "------------------------------------------"
echo
sleep 1
done

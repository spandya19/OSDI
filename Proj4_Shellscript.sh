#!/usr/pkg/bin/bash
//Reading ten times the output of /dev/time
for (( i = 0; i <= 10; i++ ))
do
cat /dev/time
done

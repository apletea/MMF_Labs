#!/bin/bash
b=666
echo "$b in 10 = $(echo "ibase=10; obase=2; $b" | bc) in 2"
echo "$b in 10 = $(echo "ibase=10; obase=16; $b" | bc) in 16"
echo "$b in 10 = $(echo "ibase=10; obase=3; $b" | bc) in 3"
echo "$b in 10 = $(echo "ibase=10; obase=7; $b" | bc) in 7"
echo "$b in 10 = $(echo "ibase=10; obase=5; $b" | bc) in 5"

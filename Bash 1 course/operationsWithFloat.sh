#!/bin/bash
a=6.5
b=5.3
echo "$a + $b = $(echo "scale=2; $a+$b" | bc)"
echo "$a - $b = $(echo "scale=2; $a-$b" | bc)"
echo "$a * $b = $(echo "scale=2; $a*$b" | bc)"
echo "$a / $b = $(echo "scale=2; $a/$b" | bc)"

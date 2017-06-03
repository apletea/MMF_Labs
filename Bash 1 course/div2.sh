#!/bin/bash

read a

if [ $(($a%2)) -eq 0 ]
then echo "$a - четное"
else echo "$a - нечетное"
fi

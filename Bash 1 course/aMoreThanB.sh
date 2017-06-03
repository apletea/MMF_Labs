#!/bin/bash

read a
read b

if [ "$a" -lt "$b" ]
then
  tmp=$b
  b=$a
  a=$tmp
fi

echo "$a > $b"

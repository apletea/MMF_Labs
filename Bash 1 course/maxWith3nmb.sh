#!/bin/bash

read a
read b
read c

if [ "$a" -lt "$b" ]
then
  if [ "$b" -lt "$c" ]
  then
    echo "$c > $b >$a"
  else echo "$b > $c >$a" 
  fi 
else if [ "$b" -lt "$c" ]
     then
       echo "$a > $c >$b"
     else echo "$a > $b >$c" 
     fi 
fi

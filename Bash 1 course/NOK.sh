#!/bin/bash

echo "введите a"
read a

echo "введите b"
read b

nod () 
{
   n=1 a=$1 b=$2
   if [ "$a" -ne 0 ]
   then
      nod $(( $b % $a )) $a
      n=$?
   else
      n=$b
   fi
   return $n
}
 
nod $a $b
nod=$?
echo "НОК(a,b)= $(($(($a/$nod))*$b))"

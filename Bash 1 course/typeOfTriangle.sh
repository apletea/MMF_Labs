#!/bin/bash

echo a
read a

echo b
read b

echo c
read c

if [ "$a" -lt "$b" ]
then
  if [ "$b" -lt "$c" ]
  then if [ "$(($a*$a+$b*$b))" -eq "$(($c*$c))" ]
       then echo "прямоугольный"
       fi
       else if [ "$(($a*$a+$c*$c))" -eq "$(($b*$b))" ]
	    then echo "прямоугольный"
	    fi
       fi
else if [ "$a" -lt "$c" ]
     then if [ "$(($a*$a+$b*$b))" -eq "$(($c*$c))" ]
          then echo "прямоугольный"
	  fi
          else if [ "$(($b*$b+$c*$c))" -eq "$(($a*$a))" ]
	       then echo "прямоугольный"
	       fi
	  fi
fi

if [ "$a" -eq "$b" ]
then if [ "$b" -eq "$c" ]
     then
       echo "равносторонний"
       exit 0
     fi
fi

if [ "$a" -eq "$b" ]
then echo "равнобедренный"
elif [ "$a" -eq "$c" ]
then echo "равнобедренный"
elif [ "$b" -eq "$c" ]
then echo "равнобедренный"
fi

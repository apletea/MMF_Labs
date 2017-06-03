#!/bin/bash

for file in *; 
do
  if [ -d "&file" ] 
  then echo "$file - папка."
  else echo "$file - файл."
  chmod u+x $file 
fi
done


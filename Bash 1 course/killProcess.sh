#!/bin/bash

echo введите имя процесса

read process

tmp=`pidof $process`

if [ -z "$tmp" ]
then
  echo "Процесс $process не найден."
  exit 1
fi

kill $tmp

exit 0

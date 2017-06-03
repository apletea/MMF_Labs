#!/bin/bash

read n

echo "среднее $(echo "scale=2; $((n+1))/2" | bc)"

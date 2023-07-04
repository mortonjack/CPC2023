#!/bin/bash
echo "1" > big_input
echo "200000 1 10" >> big_input

for i in {1..200000}
do
  echo -n "0 " >> big_input
done
#!/bin/bash
while true; do
	./maker > test.in
   	./a < input > a_out.txt
	./b < input > b_out.txt
	diff a_out.txt b_out.txt 
	if [$? -ne 0] ; then break; fi
done

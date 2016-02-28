#!/bin/bash
while true; do
	./maker > test.txt
	./a < test.txt > a_out.txt
	./NOA < test.txt > b_out.txt
	diff a_out.txt b_out.txt
	if [ $? -ne 0 ] ; then break; fi
done

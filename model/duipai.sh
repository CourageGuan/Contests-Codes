#!/bin/bash
while true; do
	./maker > test.in
   	./a < input > output.a
	./b < input > output.b
	diff output.a output.b
	if [$? -ne 0] ; then break; fi
done

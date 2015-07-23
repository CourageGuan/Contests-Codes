@echo off
:again
make > input
a < input > a_out.txt
b < input > b_out.txt
fc a_out.txt b_out.txt > nul
if not errorlevel 1 goto again	

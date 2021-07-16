#!/bin/sh

gcc -std=c89 -o main main.c -lm -Wall

cat data.in | ./main > data.out

if diff -Z data.out expected.out; then
	echo "Accepted"
else 
	echo "Wrong Answer" 
fi

rm main

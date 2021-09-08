#!/bin/sh

gcc -std=c89 -o main main.c -lm -Wall

./main < data.in > data.out

if diff -qZ data.out expected.out; then
	if [ -f "data.out" ]; then
		rm data.out
	fi
	if [ -f "diff.out" ]; then
		rm diff.out
	fi
	echo "Accepted"
else 
	diff data.out expected.out > diff.out
	echo "Wrong Answer" 
fi

rm main

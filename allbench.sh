#!/bin/bash

for i in 0 1 2 4 6 8 16 32 64 128; do
	CXX=clang++-mp-18 ./bench.sh "lang-cpp-mcd$i" -lang cpp -mcd $i
done

for i in 0 1 2 4 6 8 16 32 64 128; do
	CXX=clang++-mp-18 ./bench.sh "lang-ocpp-mcd$i" -lang ocpp -mcd $i
done

for i in 0 1 2 4 6 8 16 32 64 128; do
	CXX=clang++-mp-18 ./bench.sh "lang-ocpp-fir-mcd$i" -lang ocpp -fir -mcd $i
done
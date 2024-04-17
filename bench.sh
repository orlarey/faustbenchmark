#!/bin/bash

bindir="./$1"
mkdir -p "$bindir"
shift

echo "Compile the .dsp files with faust2bench and options $@"
for f in dsp/*.dsp; do faust2bench "$@" "$f"; mv ./${f%.dsp} "$bindir"; done

echo "Run the binary files in $bindir compiled with options: $@"
for f in "$bindir"/*; do sudo ./$f; done


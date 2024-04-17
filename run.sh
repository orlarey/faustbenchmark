#!/bin/bash

bindir="./$1"

echo "Run the binary files in $bindir "
for f in "$bindir"/*; do sudo ./$f; done


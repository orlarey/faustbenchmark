#!/bin/bash

bindir="./$1"

echo "Run the binary files in $bindir "
for f in "$bindir"/*; do sudo ./$f; done

## Livebox Play - 09 63 68 41 53; RIO: F0 F HEFXAY 836
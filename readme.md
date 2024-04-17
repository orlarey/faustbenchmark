The script `./bench.sh <directory> <options...>` uses `faust2bench` to measure the performances of the .dsp files of the folder `dsp/` according to various compilation options.

For example `./bench.sh test1dir -lang cpp` compiles all the files of `dsp/` using the options `-lang cpp` and places the resulting binaries into the folder `test1dir`. Then it runs all the binaries of `test1dir`.

The binaries can be re-executed (without recompilation) using the command `./run.sh test1dir`.

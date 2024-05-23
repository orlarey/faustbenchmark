
DSP="$1" # the DSP file to compile
CONF1=("$2") # the first set of compilation options
CONF2=("$3") # the second set of compilation options

CXX="clang++-mp-18"

faust2plot $1 "${CONF1[@]}"
mv ${1%.dsp} ${1%.dsp}_1

faust2plot $1 "${CONF2[@]}"
mv ${1%.dsp} ${1%.dsp}_2

./${1%.dsp}_1 -n 100000 > ${1%.dsp}_1.txt
./${1%.dsp}_2 -n 100000 > ${1%.dsp}_2.txt

diff ${1%.dsp}_1.txt ${1%.dsp}_2.txt

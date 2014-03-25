#!bash
echo '*** start set envars *******'

export MAKE=make.exe

export CC='gcc'
export CXX='g++'
export CFLAGS="-pipe -Wall -Zexe -Zmts -O3" 

export PATH="`echo $PATH | sed 's%\\\\%/%g'`"

export SED=sed.exe
export GREP=grep.exe
export LD=ld.exe
export AWK=awk.exe
export PATH_SEPARATOR=';'

echo '***** end set envars *******'

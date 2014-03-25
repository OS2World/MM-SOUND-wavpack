EXTPROC bash 2> /dev/null
:
#!bash
#  All environment variables are here:
. ./env.sh

#  Backup configure before patch
test -f configure.orig || mv configure configure.orig

#  My bash version crash when unset global variables
#  so better not use 'unset'
sed -e 's/as_unset=unset/as_unset=false/g' \
configure.orig > configure

./configure



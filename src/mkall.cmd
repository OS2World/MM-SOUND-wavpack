EXTPROC bash 2> /dev/null
:
#!bash
. ./env.sh

#  Backup libtool before patch
test -f libtool.orig || mv libtool libtool.orig

#  Workaround for my bash misbehaviour with set and $IFS
cat libtool.orig |
sed -e "s/set dummy \$vinfo 0 0 0/set dummy \`echo \$vinfo | sed \"s\/:\/\$IFS\/g\"\` 0 0 0/g" |
sed -e 's/AR="false"/AR="ar"/g' \
> libtool

$MAKE ${1:-all}

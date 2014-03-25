#
#  wvplay.dll makefile for gnu MAKE and g++
#

# build environment
#-----------------------
#  gcc -v
# 
# Reading specs from J:/usr/gcc/3.3.5-csd1/lib/gcc-lib/i386-pc-os2-emx/3.3.5/specs
# Configured with: D:/CODING/LIBC/0.6/src/gcc/configure --enable-clh 
# --enable-threads=os2 --enable-shared=libgcc,bfd,opcodes --enable-nls 
# --without-included-gettext --with-local-prefix=D:/CODING/LIBC/0.6/TOOLS/x86.os2/gcc/staged 
# --prefix=/gcc --with-gnu-as --disable-libgcj --enable-languages=c,c++
# Thread model: os2
# gcc version 3.3.5 (Bird Build 2006-03-18 05:37)
# 
#  make -v
# GNU Make version 3.77, by Richard Stallman and Roland McGrath.
# Copyright (C) 1988, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
# 	Free Software Foundation, Inc.
# This is free software; see the source for copying conditions.
# There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.
# 
# Report bugs to <bug-make@gnu.org>.
# 
#

TARGET = ../wvplay

CC = g++ -c
LD = g++
RM = del

WVLIB = ../wplib


CFLAGS   = -Zmts -O3 -DUNPACK -DUSE_FSTREAMS -DTAGS -DSEEKING -DVER3
INCLUDE  = -I./include -I$(WVLIB)
LIB      =

all: $(TARGET).dll

DEF      = wvplay.def
OBJECTS  = wvplay.o wav.o
LIBS     = $(WVLIB)/.libs/wavpack.a 

$(TARGET).dll : $(OBJECTS) $(DEF)
	$(LD) -Zdll $(CFLAGS) -o $(TARGET).dll $(OBJECTS) $(LIBS) $(DEF)

clean:
	-@$(RM) ..\*.dll $(OBJECTS) *.bak ..\*.bak 2> nul

wvplay.o : wvplay.cpp wav.h
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ wvplay.cpp

wav.o : wav.cpp wav.h
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ wav.cpp


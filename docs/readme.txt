WavPack v4.32 Play 0.00
=======================

Introduction
------------
	This is a WavPack decoder plugin for the PM123. With this plugin, you
	can play WavPack Hybrid Lossless Audio compressed files.

        WavPack is a completely open audio compression format providing 
	lossless, high-quality lossy, and a unique hybrid compression mode.
	(http://www.wavpack.com/)

System requirements
-------------------
	Working relatively modern PM123 1.x, http://glass.os2.spb.ru/software/english/pm123.html
	libc061, ftp://ftp.netlabs.org/pub/gcc/libc-0.6.1-csd1.zip

Installation
------------
	- make it sure that LIBC061.DLL located somewhere in your LIBPATH
	- place the file wvplay.dll into the directory where PM123.EXE located
	- start PM123
	- Right-click on the PM123 window to open the "properties" dialog
	- Choose the page "plugins"
	- Press the "add" button in the "decoder plugin" section
	- Choose "wvplay.dll" in the file dialog.
	  Press Ok.
	- Close "PM123 properties" dialog

	Now you can listen WavPack compressed (.wv) audio files!

De-Installation
---------------
	In case of any trouble with this plugin close PM123 and remove 
	wvplay.dll from the PM123.EXE directory.

License
-------
	wvplay.dll use WavPack v4.32 source, copyrighted by:

               Copyright (c) 1998 - 2005 Conifer Software
                          All rights reserved.
	Please see license.txt for terms of redistribution and use.


	wvplay.dll based on source, copyrighted by:

	 * Copyright 1997-2003 Samuel Audet <guardia@step.polymtl.ca>
	 *                     Taneli Lepp„ <rosmo@sektori.com>

	Please see src/wvplay.cpp for terms of redistribution and use.


	wvplay.dll derived from work of SofiyaCat (Monkey's audio decoder plug-in v0.00)
	Please see src/readme.txt for more license info.


	The author is not responsible for any damage this program may cause.

Sources
-------
	Sources of wvplay.dll located in src/ directory.
	To build from sources you also need OS/2 ported wavpack-4.32 library
	(for creation of wvplay.dll the one located on hobbes was used, 
	http://hobbes.nmsu.edu/cgi-bin/h-search?key=wavpack-4_32-os2bin00.zip&pushbutton=Search).

Contacts
--------
	All questions about this build please send to ntim@softhome.net
	or contact ntim on #os2russian (irc://efnet/os2russian)


June 2006
ntim

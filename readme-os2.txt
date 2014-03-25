wavpack-4.32-os2bin00

What's this?
------------
	This is just an OS/2 build of wavpack-4.32 (.tar.bz2) 
	from "WavPack Hybrid Lossless Audio Compression" project.

What's that?
------------
   "... WavPack is a completely open audio compression format providing 
	lossless, high-quality lossy, and a unique hybrid compression mode."
	(http://www.wavpack.com/)

Content:
--------
	wavpack.exe - command-line encoder, produce WavPack (.wv .wvc) files 
		     ( run with no options for usage)
	wvunpack.exe - command-line decoder, produce wave files from WavPack
		     ( run with no options for usage)
	wvgain.exe   - command-line scanner/tagger
		     ( run with no options for usage)
Warnings:
---------
	Almost untested, use with care!
	Known bugs: wildcards (and probably @) in command line not work...

Requirements:
-------------
	OS/2 4.x, ECs ( or OS/2 3.x - I guess)
	libc061, ftp://ftp.netlabs.org/pub/gcc/libc-0.6.1-csd1.zip

Sources:
--------
	Please find wavpack-4.32.tar.bz2 on WavPack official site 
	(http://www.wavpack.com/wavpack-4.32.tar.bz2)
	
	All modifications located in src/ (can be reproduced with patch.exe)
	Sources were compiled with GCC-3.3.5-CSD1 
	(ftp://ftp.netlabs.org/pub/gcc/gcc-3.3.5-csd1.zip)
	
Licenses, docs, infos:
----------------------
	For licences and original docs please see docs/
	For other info visit http://www.wavpack.com/

Contacts:
---------
	All questions about this build send to ntim@softhome.net
	or find ntim on #os2russian (irc://efnet/os2russian)

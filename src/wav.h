/*
 * Copyright 1997-2003 Samuel Audet <guardia@step.polymtl.ca>
 *                     Taneli Lepp� <rosmo@sektori.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *    3. The name of the author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* AFAIK, all of those also have BitsPerSample as format specific */
#define WAVE_FORMAT_PCM       0x0001
#define WAVE_FORMAT_ADPCM     0x0002
#define WAVE_FORMAT_ALAW      0x0006
#define WAVE_FORMAT_MULAW     0x0007
#define WAVE_FORMAT_OKI_ADPCM 0x0010
#define WAVE_FORMAT_DIGISTD   0x0015
#define WAVE_FORMAT_DIGIFIX   0x0016
#define IBM_FORMAT_MULAW      0x0101
#define IBM_FORMAT_ALAW       0x0102
#define IBM_FORMAT_ADPCM      0x0103

#define NO_WAV_FILE 200

const long int samples_to_unpack=4096L;
class WAV
{
	WavpackContext *wpc;
	int m_nRemain;
	int m_nPos;
	int bps, channels, samplerate, fbps;
	char error[90];

	int32_t *temp_buffer;

   public:

      WAV();
      ~WAV();
      int open(char *filename, int &samplerate,
               int &channels, int &bits, int &format);
      int close();
      int readData(char *buffer, int bytes);
      int filepos();
      int jumpto(long offset);
      int filelength();
};

/*
 * Copyright 1997-2003 Samuel Audet <guardia@step.polymtl.ca>
 *                     Taneli Lepp„ <rosmo@sektori.com>
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

#define INCL_DOS
#include <os2.h>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <sys\types.h>
#include <memory.h>



#include <unistd.h>
#include <glob.h>
#include <sys/time.h>

#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

extern "C" {
#include "wavpack.h"
}
#include "wav.h"

WAV::WAV()
{
	wpc = NULL;
	temp_buffer = 0;
	}

WAV::~WAV()
{
	close();
}

int WAV::open(char *filename, int &samplerate,
              int &channels, int &bits, int &format)
{
    int nRetVal = -1;
    m_nPos = 0;
    m_nRemain = 0;

    wpc = WavpackOpenFileInput (
        filename,
        error,
        OPEN_2CH_MAX |  OPEN_WVC | OPEN_TAGS /*OPEN_WRAPPER |   OPEN_STREAMING |   */,
        0);

    if(wpc) {
        samplerate = this->samplerate = WavpackGetSampleRate(wpc);
        channels = this->channels = WavpackGetReducedChannels(wpc);
        bps = WavpackGetBytesPerSample (wpc);
        fbps = channels*bps;
        bits = WavpackGetBitsPerSample(wpc);
        format = WAVE_FORMAT_PCM;
        if (temp_buffer) {
        	delete [] temp_buffer;
            }
        temp_buffer = new int32_t [samples_to_unpack * channels];
        nRetVal=0;
    	}

    return (nRetVal != 0) ? NO_WAV_FILE : 0;
}

int WAV::close()
{
	if(wpc) {
		WavpackCloseFile(wpc);
		wpc=NULL;
	}
  if(temp_buffer) {
        delete [] temp_buffer;
        temp_buffer = 0;
    }
	return 0;
}

static uchar *format_samples (int bps, uchar *dst, int32_t *src, uint32_t samcnt)
{
    int32_t temp;

    switch (bps) {

    case 1:
        while (samcnt--)
        *dst++ = *src++ + 128;

        break;

    case 2:
        while (samcnt--) {
        *dst++ = (uchar) (temp = *src++);
        *dst++ = (uchar) (temp >> 8);
        }

        break;

    case 3:
        while (samcnt--) {
        *dst++ = (uchar) (temp = *src++);
        *dst++ = (uchar) (temp >> 8);
        *dst++ = (uchar) (temp >> 16);
        }

        break;

    case 4:
        while (samcnt--) {
        *dst++ = (uchar) (temp = *src++);
        *dst++ = (uchar) (temp >> 8);
        *dst++ = (uchar) (temp >> 16);
        *dst++ = (uchar) (temp >> 24);
        }

        break;
    }

    return dst;
}

int WAV::readData(char *buffer, int bytes)
{
	int total = 0;

  if (wpc)
	while(bytes > 0) {
		if (m_nRemain) {
			register int n = ( bytes / fbps< m_nRemain )?(bytes /fbps):m_nRemain;
			format_samples (bps, (uchar *)buffer, temp_buffer+m_nPos, m_nRemain * channels);

			m_nRemain -= n;
			m_nPos    += n;
			n *= fbps;

			bytes     -= n;
			buffer    += n;
			total     += n;
			}
		else {
			m_nPos = 0;
    		if ( 0==(m_nRemain = WavpackUnpackSamples (wpc, temp_buffer, samples_to_unpack))) {
    			break;
    			}
			}
    	}
	return total;
	}

int WAV::filepos()
{
	if(wpc) {
        int samples=WavpackGetSampleIndex(wpc);
        return (samples>0&&samplerate>0)?(uint32_t)((double)samples*1000/samplerate):0;
	}
	return 0;
}

int WAV::filelength()
{
	if(wpc) {
		int samples=WavpackGetNumSamples(wpc);
        return (samples>0&&samplerate>0)?(uint32_t)((double)samples*1000/samplerate):0;
	}
	return 0;
}

int WAV::jumpto(long offset)
{
	if(wpc)
		WavpackSeekSample (wpc,(uint32_t)((double)offset*samplerate/1000));
	return 0;
}


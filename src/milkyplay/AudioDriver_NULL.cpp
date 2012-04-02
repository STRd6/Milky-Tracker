/*
 * Copyright (c) 2009, The MilkyTracker Team.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the <ORGANIZATION> nor the names of its contributors
 *   may be used to endorse or promote products derived from this software
 *   without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  AudioDriver_NULL.cpp
 *  MilkyPlay
 *
 *  Created by Peter Barth on 29.07.05.
 *
 */

#include "AudioDriver_NULL.h"
#include "MasterMixer.h"

AudioDriver_NULL::AudioDriver_NULL() :
	numSamplesWritten(0),
	compensateBuffer(0)
{
}

AudioDriver_NULL::~AudioDriver_NULL() 
{
	delete[] compensateBuffer;
}

mp_sint32 AudioDriver_NULL::initDevice(mp_sint32 bufferSizeInWords, mp_uint32 mixFrequency, MasterMixer* mixer)
{
	mp_sint32 res = AudioDriverBase::initDevice(bufferSizeInWords, mixFrequency, mixer);
	if (res < 0)
		return res;

	numSamplesWritten = 0;
	
	delete[] compensateBuffer;
	compensateBuffer = new mp_sword[bufferSizeInWords];

	return 0;
}

mp_sint32 AudioDriver_NULL::stop()
{
	return 0;
}

mp_sint32 AudioDriver_NULL::closeDevice()
{
	return 0;
}

mp_sint32 AudioDriver_NULL::start()
{
	return 0;
}

mp_sint32 AudioDriver_NULL::pause()
{
	return 0;
}

mp_sint32 AudioDriver_NULL::resume()
{
	return 0;
}

void AudioDriver_NULL::advance()
{
	numSamplesWritten+=bufferSize / MP_NUMCHANNELS;	
	
    if (mixer->isPlaying())
        mixer->mixerHandler(compensateBuffer);	
}


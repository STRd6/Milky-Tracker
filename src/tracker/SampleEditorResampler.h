/*
 *  tracker/SampleEditorResampler.h
 *
 *  Copyright 2009 Peter Barth
 *
 *  This file is part of Milkytracker.
 *
 *  Milkytracker is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Milkytracker is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Milkytracker.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 *  SampleEditorResampler.h
 *  MilkyTracker
 *
 *  Created by Peter Barth on 06.01.08.
 *
 */

#ifndef __SAMPLEEDITORRESAMPLER_H__
#define __SAMPLEEDITORRESAMPLER_H__

#include "BasicTypes.h"

class SampleEditorResampler
{
private:
	class XModule& module;
	struct TXMSample& sample;
	pp_uint32 type;

public:
	SampleEditorResampler(XModule& module, TXMSample& sample, pp_uint32 type);
	virtual ~SampleEditorResampler();

	bool resample(float oldRate, float newRate);
};

#endif

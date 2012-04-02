/*
 *  tracker/TrackerConfig.cpp
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

#include "TrackerConfig.h"

#define MILKYTRACKER_HIVER ((0 << 8) + (0))
#define MILKYTRACKER_LOVER ((0x90 << 8) + (0x85))

const PPString TrackerConfig::stringButtonPlus("+");
const PPString TrackerConfig::stringButtonMinus("-");

const PPString TrackerConfig::stringButtonUp("\xfe");
const PPString TrackerConfig::stringButtonDown("\xfd");

const PPString TrackerConfig::stringButtonExtended("\xf0");
const PPString TrackerConfig::stringButtonCollapsed("=");

const PPPoint TrackerConfig::trackerExitBounds(4,4);

PPColor TrackerConfig::colorThemeMain(64, 96, 128);
PPColor TrackerConfig::colorRecordModeButtonText(255, 0, 0);

PPColor TrackerConfig::colorPatternEditorBackground(0,0,0);
PPColor TrackerConfig::colorPatternEditorCursor(64*2, 64*2, 128*2-1);
PPColor TrackerConfig::colorPatternEditorCursorLine(96, 32, 64);
PPColor TrackerConfig::colorPatternEditorCursorLineHighLight(128+32, 24, 48);
PPColor TrackerConfig::colorPatternEditorSelection(16,48,96);

PPColor TrackerConfig::colorPatternEditorNote(255, 255, 255);
PPColor TrackerConfig::colorPatternEditorInstrument(128, 224, 255);
PPColor TrackerConfig::colorPatternEditorVolume(128, 255, 128);
PPColor TrackerConfig::colorPatternEditorEffect(255, 128, 224);
PPColor TrackerConfig::colorPatternEditorOperand(255, 224, 128);

PPColor TrackerConfig::colorHighLight_1(255, 255, 0);
PPColor TrackerConfig::colorHighLight_2(255, 255, 128);
PPColor TrackerConfig::colorScopes(255, 255, 255);
PPColor TrackerConfig::colorRowHighLight_1(32, 32, 32);
PPColor TrackerConfig::colorRowHighLight_2(16, 16, 16);

// how many open tabs are allowed
#ifndef __LOWRES__
pp_int32 TrackerConfig::numTabs = 32;
#else
pp_int32 TrackerConfig::numTabs = 1;
#endif

// How many channels possible in XM module? We take the standard here => 32 channels
pp_int32 TrackerConfig::numPlayerChannels = 32;
// How many channels allocated for instrument playback only? Doesn't cut notes
pp_int32 TrackerConfig::numVirtualChannels = 32;
// The final amount of channels to be mixed, add two for playing samples on seperate channels without having to cut notes
pp_int32 TrackerConfig::totalPlayerChannels = TrackerConfig::numPlayerChannels + TrackerConfig::numVirtualChannels + 2;
// This can't be changed later, it's the maximum of channels possible
const pp_int32 TrackerConfig::maximumPlayerChannels = 32+99+2;

bool TrackerConfig::useVirtualChannels = false;

const pp_int32 TrackerConfig::numPredefinedEnvelopes = 10;
const pp_int32 TrackerConfig::numPredefinedColorPalettes = 6;

const PPString TrackerConfig::defaultPredefinedVolumeEnvelope("060203050700000000C000040100000800B0000E00200018005800200020");
const PPString TrackerConfig::defaultPredefinedPanningEnvelope("06020305000000000080000A00A0001E006000320080003C008000460080");

const PPString TrackerConfig::defaultProTrackerPanning("0000002000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF00");

const PPString TrackerConfig::defaultColorPalette("2B" // Numkeys 
												  "FFFFFF" // ColorPatternNote
												  "80E0FF" // ColorPatternInstrument
												  "80FF80" // ColorPatternVolume
												  "FF80E0" // ColorPatternEffect
												  "FFE080" // ColorPatternOperand
												  "8080FF" // ColorCursor
												  "602040" // ColorCursorLine
												  "A01830" // ColorCursorLineHighlighted
												  "406080" // ColorTheme
												  "FFFFFF" // ColorForegroundText
												  "C0C0C0" // ColorButtons
												  "000000" // ColorButtonText
												  "8080FF" // ColorSelection
												  "282849" // ColorListBoxBackground
												  "103060" // ColorPatternSelection
												  "FFFF00" // Hilighted text
												  "FFFFFF" // Scopes
												  "FFFF80" // Hilighted rows (secondary)
												  "202020" // Row highlight background (primary)
												  "101010" // Row highlight background (secondary)
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0"
												  "DB00A0");

const char* TrackerConfig::predefinedColorPalettes[TrackerConfig::numPredefinedColorPalettes] =                // Current last color start in the line of this comment marker
{
// default
"2BFFFFFF80E0FF80FF80FF80E0FFE0808080FF602040A01830406080FFFFFFC0C0C00000008080FF202030103060FFFF00FFFFFFFFFF802020201010103B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B0040",
// bluish
"2BFFFFFF7FB5FFA7DDFF00B5FF7FFFFF0000593F5A7F8618C9405DA7FFFFFFC0C0C000000080B5FF18183A103060FFFF00FFFFFFFFFF802020201010105B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B00205B0020",
// nice one
"2BFFFFFFFFD6D6FFFFFFFFD6D6FFFFFF21140D6B5F57C2355D937F8CFFFFFFA6A6A6000000D6C2C92C242C605060FFFF00FFFFFFFFFF802020201010103B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B00403B0040",
// rusty
"2BFFFFFFDDD0DDFFD0DDC9B5D0C2A7C22114217F647F785743403549FFFFFF7F737F000000937F8C202030403040FFFF00FFFFFFFFFF802020201010109B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E0",
// greeny
"2B28D0E480E0FF80FF80FFB50078E080005D35506B2EA01830407843FFFFFFC0C0C000000035B56414281A106030FFFF00FFFFFFFFFF802020201010101B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B00601B0060",
// red one
"2BFFFFFFFF9393E45000FFA786FF5780350000602114A01830570028FFFFFFC0C0C00000007D0000200000500010FFFF00FFFFFFFFFF802020201010109B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E09B00E0"
};


const PPSystemString TrackerConfig::untitledSong("Untitled");

const pp_int32 TrackerConfig::numMixFrequencies = 4;
const pp_int32 TrackerConfig::mixFrequencies[] = {11025, 22050, 44100, 48000};

const pp_uint32 TrackerConfig::version = (MILKYTRACKER_HIVER << 16) + (MILKYTRACKER_LOVER);

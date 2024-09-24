#ifndef SYSTEM_SETTINGS_STORAGE_HPP
#define SYSTEM_SETTINGS_STORAGE_HPP

#include "SpectrumViewSettings.hpp"
#include "configuration.h"

struct SettingsStorage
{
	// SpectrumView settings to save to non-volatile memory
	gui::SpectrumViewSettings<color_t>::Storage SpectrumView;

	// Modulation settings

	// DSP Algorithm settings

	// validation
	uint32_t CRC32;
};

#endif // SYSTEM_SETTINGS_STORAGE_HPP
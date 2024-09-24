#ifndef SYSTEM_SETTINGS_HPP
#define SYSTEM_SETTINGS_HPP

#include "SpectrumViewSettings.hpp"
#include "configuration.h"

struct Settings
{
	// constructor
	// Settings();

	// destyructor
	// ~Settings() = default;

	// fields
	gui::SpectrumViewSettings<color_t> SpectrumView;

};

#endif // SYSTEM_SETTINGS_HPP
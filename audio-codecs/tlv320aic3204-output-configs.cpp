#include "tlv320aic3204-output-configs.h"

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	// IStereoHPOutput class
	void IStereoHPOutput::SetAnalogGain(uint32_t index)
	{

	}

	void IStereoHPOutput::SetVolumeComtrolValue(uint32_t index)
	{

	}

	// IDifferntialLineOutput class
	void IDifferntialLineOutput::SetAnalogGain(uint32_t index)
	{

	}

	void IDifferntialLineOutput::SetVolumeComtrolValue(uint32_t index)
	{

	}

	/*-----------------------------------------------------------------//
	// Left DAC Outputs
	//-----------------------------------------------------------------*/
	// LeftDACSingleEnded_HPLR class
	void LeftDACSingleEnded_HPLR::InitOutput() const
	{

	}

	void LeftDACSingleEnded_HPLR::DeinitOutput() const
	{

	}

	/*-----------------------------------------------------------------//
	// Right DAC Outputs
	//-----------------------------------------------------------------*/
	// RightDACDifferntial_LO class
	void RightDACDifferntial_LO::InitOutput() const
	{

	}

	void RightDACDifferntial_LO::DeinitOutput() const
	{

	}

	// RightMixAmpDifferntial_LO class
	void RightMixAmpDifferntial_LO::InitOutput() const
	{

	}

	void RightMixAmpDifferntial_LO::DeinitOutput() const
	{

	}

	// RightMixAmpSingleEnded_HPLR class
	void RightMixAmpSingleEnded_HPLR::InitOutput() const
	{

	}

	void RightMixAmpSingleEnded_HPLR::DeinitOutput() const
	{

	}
}
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
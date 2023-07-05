#include "tlv320aic3204-output-configs.h"
#include "tlv320aic3204-interface.h"

namespace tlv320aic3204
{
	constexpr float DAC_DIGITA_GAIN_STEP = 0.5f;
	constexpr float DAC_MIN_DIGITA_GAIN = -63.5f;
	constexpr float DAC_MAX_DIGITA_GAIN = 24.f;

	constexpr float MIXER_AMP_GAIN_STEP = 0.5f;
	constexpr float MIXER_AMP_GAIN_MIN_GAIN = -12.f;
	constexpr float MIXER_AMP_GAIN_MAX_GAIN = 20.f;

	constexpr float HP_AMP_GAIN_STEP = 1.f;
	constexpr float HP_AMP_GAIN_MIN_GAIN = -6.f;
	constexpr float HP_AMP_GAIN_MAX_GAIN = 29.f;

	constexpr float LO_AMP_GAIN_STEP = 1.f;
	constexpr float LO_AMP_GAIN_MIN_GAIN = -6.f;
	constexpr float LO_AMP_GAIN_MAX_GAIN = 29.f;
	
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/

	//-----------------------------------------------------------------//
	// StereoPGAForHPOutput class
	StereoPGAForHPOutput::StereoPGAForHPOutput()
		:analogGain_(HP_AMP_GAIN_MIN_GAIN, HP_AMP_GAIN_MAX_GAIN, HP_AMP_GAIN_STEP, 10)
	{}

	void StereoPGAForHPOutput::SetAnalogGain(uint32_t index)
	{
		WriteAnalogGainToCodec(index);
		analogGain_.SetValueByIndex(index);
	}

	inline void StereoPGAForHPOutput::WriteAnalogGainToCodec(uint8_t gain)
	{
		// register page is 1
		SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_HPL_GAIN_SETTING_REG,
			// HPL unmute
			// Set gain
			gain,
			// HPR unmute
			// Set gain
			gain
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));
	}

	//-----------------------------------------------------------------//
	// DifferntialPGAForLineOutput class
	DifferntialPGAForLineOutput::DifferntialPGAForLineOutput()
		:analogGain_(LO_AMP_GAIN_MIN_GAIN, LO_AMP_GAIN_MAX_GAIN, LO_AMP_GAIN_STEP, 10)
	{}

	void DifferntialPGAForLineOutput::SetAnalogGain(uint32_t index)
	{
		WriteAnalogGainToCodec(index);
		analogGain_.SetValueByIndex(index);
	}

	inline void DifferntialPGAForLineOutput::WriteAnalogGainToCodec(uint8_t gain)
	{
		// register page is 1
		SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_LOL_GAIN_SETTING_REG,
			// LOL unmute
			// Set gain
			gain,
			// LOR unmute
			// Set gain
			gain
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));
	}

	//-----------------------------------------------------------------//
	// RightMixerAmpVolumeControl class
	RightMixerAmpVolumeControl::RightMixerAmpVolumeControl()
		:mixerAmpGain_(0, 
			{
				0.f, -0.4f, -0.9f, -1.3f, -1.8f, -2.3f, -2.9f, -3.3f, -3.9f, -4.3f, -4.8f,
				-5.2f, -5.8f, -6.3f, -6.6f, -7.2f, -7.8f, -8.2f, -8.5f, -9.3f, -9.7f, -10.1f,
				-10.6f, -11.0f, -11.5f, -12.0f, -12.6f, -13.2f, -13.8f, -14.5f, -15.3f,
				-16.1f, -17.0f, -18.1f, -19.2f, -20.6f, -22.1f, -24.1f, -26.6f, -30.1f
			}) // Mixer Amplifier gain
	{}

	void RightMixerAmpVolumeControl::SetVolumeComtrolValue(uint32_t index)
	{
		WriteVolumeControlToCodec(index);
		mixerAmpGain_.SetValueByIndex(index);
	}

	inline void RightMixerAmpVolumeControl::WriteVolumeControlToCodec(uint8_t gain)
	{

	}

	//-----------------------------------------------------------------//
	// StereoDACVolumeControl class
	StereoDACVolumeControl::StereoDACVolumeControl()
		:digitalGain_(DAC_MIN_DIGITA_GAIN, DAC_MAX_DIGITA_GAIN, DAC_DIGITA_GAIN_STEP, 10)
	{}

	void StereoDACVolumeControl::SetVolumeComtrolValue(uint32_t index)
	{
		WriteVolumeControlToCodec(index);
		digitalGain_.SetValueByIndex(index);
	}

	inline void StereoDACVolumeControl::WriteVolumeControlToCodec(uint8_t gain)
	{

	}

	//-----------------------------------------------------------------//
	// RighDACVolumeControl class
	RighDACVolumeControl::RighDACVolumeControl()
		:digitalGain_(DAC_MIN_DIGITA_GAIN, DAC_MAX_DIGITA_GAIN, DAC_DIGITA_GAIN_STEP, 10)
	{}

	void RighDACVolumeControl::SetVolumeComtrolValue(uint32_t index)
	{
		WriteVolumeControlToCodec(index);
		digitalGain_.SetValueByIndex(index);
	}

	inline void RighDACVolumeControl::WriteVolumeControlToCodec(uint8_t gain)
	{

	}

	/*-----------------------------------------------------------------//
	// Stereo DAC Outputs
	//-----------------------------------------------------------------*/

	//-----------------------------------------------------------------//
	// StereoDACSingleEnded_HPLR class
	void StereoDACSingleEnded_HPLR::Initialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output config
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG,
			// power on HPL
			// power on HPR
			(1 << 5)|(1 << 4)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// connect DACs to HPL and HPR
		uint8_t cmd3[] =
		{
			P1_HPL_ROUTING_SELECTION_REG,
			// Left DAC to HPL
			(1 << 3),
			// Right DAC to HPR
			(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));

		// Left and Right DAC config

		// TODO
		WriteAnalogGainToCodec(5);
		WriteVolumeControlToCodec(0);
	}

	void StereoDACSingleEnded_HPLR::Deinitialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output reset
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG, 0x00
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// disconnect DACs to HPL and HPR
		uint8_t cmd3[] =
		{
			P1_HPL_ROUTING_SELECTION_REG, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));

		// Left and Right DAC reset
	}

	/*-----------------------------------------------------------------//
	// Right DAC Outputs
	//-----------------------------------------------------------------*/

	//-----------------------------------------------------------------//
	// RightDACDifferntial_LO class
	void RightDACDifferntial_LO::Initialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output config
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG,
			// power on LOL
			// power on LOR
			(1 << 3)|(1 << 2)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// connect Right DAC to LOR and HPR
		uint8_t cmd3[] =
		{
			P1_LOL_ROUTING_SELECTION_REG,
			// LOR to LOL
			(1 << 0),
			// Right DAC to LOR
			(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));

		// Right DAC config

		// TODO
		WriteAnalogGainToCodec(5);
		WriteVolumeControlToCodec(0);
	}

	void RightDACDifferntial_LO::Deinitialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output reset
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG, 0x00
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// disconnect Right DAC from LOR and HPR
		uint8_t cmd3[] =
		{
			P1_LOL_ROUTING_SELECTION_REG, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));

		// Right DAC reset

		// TODO
		WriteAnalogGainToCodec(5);
		WriteVolumeControlToCodec(0);
	}

	/*-----------------------------------------------------------------//
	// Right Mixer Amp Outputs
	//-----------------------------------------------------------------*/

	//-----------------------------------------------------------------//
	// RightMixAmpSingleEnded_HPLR class
	void RightMixAmpSingleEnded_HPLR::Initialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// connect MAR (mixer amp right) to HPL and HPR
		uint8_t cmd0[] =
		{
			P1_HPL_ROUTING_SELECTION_REG,
			// MAR to HPL
			(1 << 0),
			// MAR to HPR
			(1 << 1)
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));
		// output config
		uint8_t cmd1[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG,
			// power on HPL
			// power on HPR
			// power on Right Mixer Amp
			(1 << 5)|(1 << 4)|(1 << 0)
		};
		tlv320aic3204_write_buffer(cmd1, sizeof(cmd1));

		// TODO
		WriteAnalogGainToCodec(5);
		WriteVolumeControlToCodec(0);
	}

	void RightMixAmpSingleEnded_HPLR::Deinitialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output reset
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG, 0x00
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// connect MAR (mixer amp right) to HPL and HPR
		uint8_t cmd3[] =
		{
			P1_HPL_ROUTING_SELECTION_REG, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));
	}

	//-----------------------------------------------------------------//
	// RightMixAmpDifferntial_LO class
	void RightMixAmpDifferntial_LO::Initialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output config
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG,
			// power on LOL
			// power on LOR
			// power on Right Mixer Amp
			(1 << 3)|(1 << 2)|(1 << 0)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// connect MAR (mixer amp right) to HPL and HPR
		uint8_t cmd3[] =
		{
			P1_LOL_ROUTING_SELECTION_REG,
			// LOR to LOL
			(1 << 0),
			// MAR to LOR
			(1 << 1)
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));

		// TODO
		WriteAnalogGainToCodec(5);
		WriteVolumeControlToCodec(0);
	}

	void RightMixAmpDifferntial_LO::Deinitialize()
	{
		AudioCodecDriver::IAudioOutput::SetRegisterPage(1);
		// output reset
		uint8_t cmd2[] =
		{
			P1_OUTPUT_DRIVER_POWER_REG, 0x00
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));

		// connect MAR (mixer amp right) to HPL and HPR
		uint8_t cmd3[] =
		{
			P1_LOL_ROUTING_SELECTION_REG, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd3, sizeof(cmd3));
	}
}
#include "tlv320aic3204-input-configs.h"
#include "tlv320aic3204-interface.h"

/*-----------------------------------------------------------------//
// Dependencies
//-----------------------------------------------------------------*/
//extern tlv320aic3204::AudioCodecDriver AudioDevice;

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// constants
	//-----------------------------------------------------------------*/
	constexpr float APGA_RIN_10K_LOST = 0.f; // dB
	constexpr float APGA_RIN_20K_LOST = -6.f; // dB
	constexpr float APGA_RIN_40K_LOST = -12.f; // dB

	constexpr float APGA_GAIN_STEP = 0.5f;
	constexpr float APGA_SINGLE_ENDED_MIN_GAIN = 0.f;
	constexpr float APGA_SINGLE_ENDED_MAX_GAIN = 47.5f;
	constexpr float APGA_DIFFERENTIAL_MIN_GAIN = 6.f;
	constexpr float APGA_DIFFERENTIAL_MAX_GAIN = 53.5f;

	constexpr float DIGITAL_GAIN_STEP = 0.5f;
	constexpr float DIGITAL_GAIN_MIN_GAIN = -12.f;
	constexpr float DIGITAL_GAIN_MAX_GAIN = 20.f;

	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	
	//-----------------------------------------------------------------//
	// RightPGASinglEndedInput class
	RightPGASinglEndedInput::RightPGASinglEndedInput()
		:analogGain_(APGA_SINGLE_ENDED_MIN_GAIN, APGA_SINGLE_ENDED_MAX_GAIN, APGA_GAIN_STEP, 50) // PGA
	{}

	void RightPGASinglEndedInput::SetAnalogGain(uint32_t index)
	{
		WriteAnalogGainToCodec(index);
		analogGain_.SetValueByIndex(index);
	}

	inline void RightPGASinglEndedInput::WriteAnalogGainToCodec(uint8_t gain)
	{
		SetRegisterPage(1);
		uint8_t buff[] =
		{
			P1_RIGHT_MICPGA_VOL_CONTROL_REG,
			// Right MICPGA Gain Enable D7 = 0
			gain
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
	}

	//-----------------------------------------------------------------//
	// StereoPGADifferntialInput class
	StereoPGADifferntialInput::StereoPGADifferntialInput()
		:analogGain_(APGA_DIFFERENTIAL_MIN_GAIN, APGA_DIFFERENTIAL_MAX_GAIN, APGA_GAIN_STEP, 50) // PGA
	{}

	void StereoPGADifferntialInput::SetAnalogGain(uint32_t index)
	{
		WriteAnalogGainToCodec(index);
		analogGain_.SetValueByIndex(index);
	}

	inline void StereoPGADifferntialInput::WriteAnalogGainToCodec(uint8_t gain)
	{
		SetRegisterPage(1);
		uint8_t buff[] =
		{
			P1_LEFT_MICPGA_VOL_CONTROL_REG,
			// Lett MICPGA Gain Enable D7 = 0
			gain,
			// Right MICPGA Gain Enable D7 = 0
			gain
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
	}

	//-----------------------------------------------------------------//
	// RightADCVolumeConntrol class
	RightADCVolumeConntrol::RightADCVolumeConntrol()
		:digitalGain_(DIGITAL_GAIN_MIN_GAIN, DIGITAL_GAIN_MAX_GAIN, DIGITAL_GAIN_STEP, 24) // Digital Volume Control
	{}
	
	void RightADCVolumeConntrol::SetVolumeComtrolValue(uint32_t index)
	{
		WriteVolumeControlToCodec(index);
		digitalGain_.SetValueByIndex(index);
	}

	inline void RightADCVolumeConntrol::WriteVolumeControlToCodec(uint8_t gain)
	{
		constexpr int32_t offset = DIGITAL_GAIN_MIN_GAIN/DIGITAL_GAIN_STEP;
		SetRegisterPage(0);
		uint8_t buff[] =
		{
			P0_RIGHT_ADC_DIGITAL_GAIN_REG,
			static_cast<uint8_t>((gain + offset) & 0x7f)
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
	}

	//-----------------------------------------------------------------//
	// RightMixerAmpVolumeControlStub class
	RightMixerAmpVolumeControlStub::RightMixerAmpVolumeControlStub(RightMixerAmpVolumeControl & rightOutpur)
		:rightOutpur_{rightOutpur}
 	{}

	void RightMixerAmpVolumeControlStub::SetVolumeComtrolValue(uint32_t index)
	{
		rightOutpur_.SetVolumeComtrolValue(index);
	}

	inline void RightMixerAmpVolumeControlStub::WriteVolumeControlToCodec(uint8_t gain)
	{
		
	}

	//-----------------------------------------------------------------//
	// StereoADCVolumeControl class
	StereoADCVolumeControl::StereoADCVolumeControl()
		:digitalGain_(DIGITAL_GAIN_MIN_GAIN, DIGITAL_GAIN_MAX_GAIN, DIGITAL_GAIN_STEP, 24) // Digital Volume Control
	{}
	
	void StereoADCVolumeControl::SetVolumeComtrolValue(uint32_t index)
	{
		WriteVolumeControlToCodec(index);
		digitalGain_.SetValueByIndex(index);
	}

	inline void StereoADCVolumeControl::WriteVolumeControlToCodec(uint8_t gain)
	{
		constexpr int32_t offset = DIGITAL_GAIN_MIN_GAIN/DIGITAL_GAIN_STEP;
		uint8_t value = static_cast<uint8_t>((gain + offset) & 0x7f);
		SetRegisterPage(0);
		uint8_t buff[] =
		{
			P0_LEFT_ADC_DIGITAL_GAIN_REG,
			value,
			value
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
	}

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	
	//-----------------------------------------------------------------//
	// RightADCSingleEndedInput_IN3R class methods
	void RightADCSingleEndedInput_IN3R::Initialize()
	{
		// input config
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_MICBIAS_CONFIG_REG,
			// MICBIAS powered up
			// MICBIAS = 2.075V
			// MICBIAS from AVDD
			(1 << 6)|(0b10 << 4)|(1 << 3),
			// LEFT MICPGA Positive input by default
			0x00,
			// Reserved. Write only default values
			0x00,
			// LEFT MICPGA Negative input by default
			0x00,
			// RIGHT MICPGA Positive input to IN3R with 10k
			(0b01 << 2),
			// Reserved. Write only default values
			0x00,
			// RIGHT MICPGA Negative input to CM2R with 10k
			(0b01 << 0),
			// IN1L, IN1R, IN2L, IN2R, IN3L inputs are weakly driven to common mode
			(1 << 7)|(1 << 6)|(1 << 5)|(1 << 4)|(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		// TODO after testing take the gain value from analogGain_
		WriteAnalogGainToCodec(5);

		// Right ADC config
		AudioCodecDriver::IAudioInput::SetRegisterPage(0);
		uint8_t cmd2[] =
		{
			P0_ADC_CHANNEL_SETUP_REG,
			// Right ADC Power up
			(1 << 6),
			// Right ADC Unmited Left ADC Muted
			(1 << 7)|(0 << 3)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));
		
		// TODO
		WriteVolumeControlToCodec(0);
	}

	void RightADCSingleEndedInput_IN3R::Deinitialize()
	{
		// input reset
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_MICBIAS_CONFIG_REG, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		uint8_t cmd1[] =
		{
			P1_RIGHT_MICPGA_VOL_CONTROL_REG, (1 << 7)
		};
		tlv320aic3204_write_buffer(cmd1, sizeof(cmd1));

		// Right ADC reset
		AudioCodecDriver::IAudioInput::SetRegisterPage(0);
		uint8_t cmd2[] =
		{
			P0_ADC_CHANNEL_SETUP_REG, 0x00, (1 << 7)|(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));
	}

	//-----------------------------------------------------------------//
	// RightMixAmpSingleEndedInput_IN3R class methods
	RightMixAmpSingleEndedInput_IN3R::RightMixAmpSingleEndedInput_IN3R(RightMixerAmpVolumeControl & rightOutpur)
		:RightMixerAmpVolumeControlStub(rightOutpur)
	{}

	void RightMixAmpSingleEndedInput_IN3R::Initialize()
	{
		// input config
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_MICBIAS_CONFIG_REG,
			// MICBIAS powered up
			// MICBIAS = 2.075V
			// MICBIAS from AVDD
			(1 << 6)|(0b10 << 4)|(1 << 3),
			// LEFT MICPGA Positive input by default
			0x00,
			// Reserved. Write only default values
			0x00,
			// LEFT MICPGA Negative input by default
			0x00,
			// RIGHT MICPGA Positive input to IN3R with 10k
			(0b01 << 2),
			// Reserved. Write only default values
			0x00,
			// RIGHT MICPGA Negative input to CM2R with 10k
			(0b01 << 0),
			// IN1L, IN1R, IN2L, IN2R, IN3L inputs are weakly driven to common mode
			(1 << 7)|(1 << 6)|(1 << 5)|(1 << 4)|(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		// TODO after testing take the gain value from analogGain_
		WriteAnalogGainToCodec(5);
		// WriteVolumeControlToCodec(0); - useless in case of mixer amp.
	}

	void RightMixAmpSingleEndedInput_IN3R::Deinitialize()
	{
		// input reset
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_MICBIAS_CONFIG_REG, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		uint8_t cmd1[] =
		{
			P1_RIGHT_MICPGA_VOL_CONTROL_REG, (1 << 7)
		};
		tlv320aic3204_write_buffer(cmd1, sizeof(cmd1));
	}

	//-----------------------------------------------------------------//
	// StereoADCDifferntialInput_IN1_IN2 class methods
	void StereoADCDifferntialInput_IN1_IN2::Initialize()
	{
		// input config
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_LEFT_MIC_PGA_POSITIVE_INPUT_REG,
			// IN2L is routed to Left MICPGA with 10k resistance
			(0b01 << 4),
			// Reserved. Write only default values
			0x00,
			// IN2R is routed to Left MICPGA with 10k resistance
			(0b01 << 4),
			// IN1R is routed to Right MICPGA with 10k resistance
			(0b01 << 6),
			// Reserved. Write only default values
			0x00,
			// IN1L is routed to Right MICPGA with 10k resistance
			(0b01 << 4),
			// IN3L, IN3R inputs are weakly driven to common mode
			(1 << 3)|(1 << 2)
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		// TODO after testing take the gain value from analogGain_
		WriteAnalogGainToCodec(16);

		// ADCs config
		AudioCodecDriver::IAudioInput::SetRegisterPage(0);
		uint8_t cmd2[] =
		{
			P0_ADC_CHANNEL_SETUP_REG,
			// Left Channel ADC is powered up
			// Right Channel ADC is powered up
			(1 << 7)|(1 << 6),
			// Left ADC Channel Un-muted
			// Right ADC Channel Un-muted
			(0 << 7)|(0 << 3)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));
		
		// TODO
		WriteVolumeControlToCodec(0);
	}

	void StereoADCDifferntialInput_IN1_IN2::Deinitialize()
	{
		// input reset
		AudioCodecDriver::IAudioInput::SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_LEFT_MIC_PGA_POSITIVE_INPUT_REG, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));

		uint8_t cmd1[] =
		{
			P1_RIGHT_MICPGA_VOL_CONTROL_REG, (1 << 7)
		};
		tlv320aic3204_write_buffer(cmd1, sizeof(cmd1));

		// Right ADC reset
		AudioCodecDriver::IAudioInput::SetRegisterPage(0);
		uint8_t cmd2[] =
		{
			P0_ADC_CHANNEL_SETUP_REG, 0x00, (1 << 7)|(1 << 3)
		};
		tlv320aic3204_write_buffer(cmd2, sizeof(cmd2));
	}
}
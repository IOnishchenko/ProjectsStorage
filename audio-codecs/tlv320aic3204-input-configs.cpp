#include "tlv320aic3204-input-configs.h"
#include "tlv320aic3204-interface.h"

/*-----------------------------------------------------------------//
// Dependencies
//-----------------------------------------------------------------*/
extern tlv320aic3204::AudioCodecDriver AudioDevice;

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

	constexpr float MIXER_AMP_GAIN_STEP = 0.5f;
	constexpr float MIXER_AMP_GAIN_MIN_GAIN = -12.f;
	constexpr float MIXER_AMP_GAIN_MAX_GAIN = 20.f;

	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	
	//-----------------------------------------------------------------//
	// IRightSinglEndedInput class
	IRightSinglEndedInput::IRightSinglEndedInput()
		:analogGain_(APGA_SINGLE_ENDED_MIN_GAIN, APGA_SINGLE_ENDED_MAX_GAIN, APGA_GAIN_STEP, 50) // PGA
	{}

	void IRightSinglEndedInput::SetAnalogGain(uint32_t index)
	{
		AudioDevice.SetRegisterPage(1);
		uint8_t buff[] =
		{
			P1_RIGHT_MICPGA_VOL_CONTROL_REG,
			// Right MICPGA Gain Enable D7 = 0
			static_cast<uint8_t>(index)
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
		analogGain_.SetCurrentIndex(index);
	}

	//-----------------------------------------------------------------//
	// IRightADCSinglEndedInput class
	IRightADCSinglEndedInput::IRightADCSinglEndedInput()
		:digitalGain_(DIGITAL_GAIN_MIN_GAIN, DIGITAL_GAIN_MAX_GAIN, DIGITAL_GAIN_STEP, 24) // Digital Volume Control
	{}
	
	void IRightADCSinglEndedInput::SetVolumeComtrolValue(uint32_t index)
	{
		constexpr int32_t offset = DIGITAL_GAIN_MIN_GAIN/DIGITAL_GAIN_STEP;
		AudioDevice.SetRegisterPage(0);
		uint8_t buff[] =
		{
			P0_RIGHT_ADC_DIGITAL_GAIN_REG,
			static_cast<uint8_t>((index + offset) & 0x7f)
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
		digitalGain_.SetCurrentIndex(index);
	}

	//-----------------------------------------------------------------//
	// IRightMixerAmpSinglEndedInput class
	IRightMixerAmpSinglEndedInput::IRightMixerAmpSinglEndedInput()
		:mixerAmpGain_(0, 
			{
				0.f, -0.4f, -0.9f, -1.3f, -1.8f, -2.3f, -2.9f, -3.3f, -3.9f, -4.3f, -4.8f,
				-5.2f, -5.8f, -6.3f, -6.6f, -7.2f, -7.8f, -8.2f, -8.5f, -9.3f, -9.7f, -10.1f,
				-10.6f, -11.0f, -11.5f, -12.0f, -12.6f, -13.2f, -13.8f, -14.5f, -15.3f,
				-16.1f, -17.0f, -18.1f, -19.2f, -20.6f, -22.1f, -24.1f, -26.6f, -30.1f
			}) // Mixer Amplifier gain
 	{}

	void IRightMixerAmpSinglEndedInput::SetVolumeComtrolValue(uint32_t index)
	{
		mixerAmpGain_.SetCurrentIndex(index);
	}

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	
	//-----------------------------------------------------------------//
	// RightADCSingleEnded_IN3_R class methods
	void RightADCSingleEnded_IN3_R::InitInput() const
	{

	}

	void RightADCSingleEnded_IN3_R::DeinitInput() const
	{

	}

	//-----------------------------------------------------------------//
	// RightMixAmpSingleEnded_IN3_R class methods
	void RightMixAmpSingleEnded_IN3_R::InitInput() const
	{

	}

	void RightMixAmpSingleEnded_IN3_R::DeinitInput() const
	{

	}
}
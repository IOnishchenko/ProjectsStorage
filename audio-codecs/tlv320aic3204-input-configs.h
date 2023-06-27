#ifndef TLV320AIC3204_IONPUT_CONFIGS_H
#define TLV320AIC3204_IONPUT_CONFIGS_H

#include "tlv320aic3204-driver.h"

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	// class ILeftSinglEndedInput : public AudioCodecDriver::IAudioInput
	// {
	// public:
	// 	void SetAnalogGain(uint32_t index) override;
	// 	void SetAdjLeftGain(uint32_t index) override;
	// 	void SetAdjRightGain(uint32_t index) override;
	// 	void SetDititalGain(uint32_t index) override;
	// };

	// class ILeftDifferentialInput : public AudioCodecDriver::IAudioInput
	// {
	// public:
	// 	void SetAnalogGain(uint32_t index) override;
	// 	void SetAdjLeftGain(uint32_t index) override;
	// 	void SetAdjRightGain(uint32_t index) override;
	// 	void SetDititalGain(uint32_t index) override
	// };

	class IRightSinglEndedInput : public AudioCodecDriver::IAudioInput
	{
	public:
		void SetAnalogGain(uint32_t index) override;
		void SetAdjLeftGain(uint32_t index) override;
		void SetAdjRightGain(uint32_t index) override;
		void SetDititalGain(uint32_t index) override;
	};

	// class IRightDifferentialInput : public AudioCodecDriver::IAudioInput
	// {
	// public:
	// 	void SetAnalogGain(uint32_t index) override;
	// 	void SetAdjLeftGain(uint32_t index) override;
	// 	void SetAdjRightGain(uint32_t index) override;
	// 	void SetDititalGain(uint32_t index) override
	// };

	/*-----------------------------------------------------------------//
	// Left ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	// class LeftADCSingleEnded_IN1_L : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class LeftADCSingleEnded_IN2_L : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class LeftADCSingleEnded_IN3_L : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class LeftADCSingleEnded_IN1_R : public AudioCodecDriver::IAudioInput
	// {
	// };

	/*-----------------------------------------------------------------//
	// Left ADC Differential Inputs
	//-----------------------------------------------------------------*/
	// class LeftADCDifferential_IN2_L_R : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class LeftADCDifferential_IN3_L_R : public AudioCodecDriver::IAudioInput
	// {
	// };

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	// class RightADCSingleEnded_IN1_R : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class RightADCSingleEnded_IN2_R : public AudioCodecDriver::IAudioInput
	// {
	// };

	class RightADCSingleEnded_IN3_R : public IRightSinglEndedInput
	{
	public:
		void InitInput() const override;
		void DeinitInput() const override;
	};

	class RightMixAmpSingleEnded_IN3_R : public IRightSinglEndedInput
	{
	public:
		void InitInput() const override;
		void DeinitInput() const override;
	};

	// class RightADCSingleEnded_IN2_L : public AudioCodecDriver::IAudioInput
	// {
	// };

	/*-----------------------------------------------------------------//
	// Right ADC Differential Inputs
	//-----------------------------------------------------------------*/
	// class RightADCDifferential_IN1_R_L : public AudioCodecDriver::IAudioInput
	// {
	// };

	// class RightADCDifferential_IN3_R_L : public AudioCodecDriver::IAudioInput
	// {
	// };
}

#endif // TLV320AIC3204_IONPUT_CONFIGS_H
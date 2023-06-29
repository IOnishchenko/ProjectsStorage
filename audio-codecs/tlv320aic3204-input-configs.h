#ifndef TLV320AIC3204_IONPUT_CONFIGS_H
#define TLV320AIC3204_IONPUT_CONFIGS_H

#include "tlv320aic3204-driver.h"
#include "Value.h"
#include "ValueTable.h"

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	class IRightSinglEndedInput : public AudioCodecDriver::IAudioInput
	{
	public:
		// constructor
		IRightSinglEndedInput();

		// destructot
		~IRightSinglEndedInput() override = default;

		// methods
		void SetAnalogGain(uint32_t index) override;
		const IValue<float> & GetAnalogGain() const override
		{
			return analogGain_;
		}

	private:
		Value<float> analogGain_;
	};

	//-----------------------------------------------------------------//
	class IRightADCSinglEndedInput : public IRightSinglEndedInput
	{
	public:
		// constructor
		IRightADCSinglEndedInput();

		// destructot
		~IRightADCSinglEndedInput() override = default;

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return digitalGain_;
		}

	private:
		Value<float> digitalGain_;
	};

	//-----------------------------------------------------------------//
	class IRightMixerAmpSinglEndedInput : public IRightSinglEndedInput
	{
	public:
		// constructor
		IRightMixerAmpSinglEndedInput();

		// destructot
		~IRightMixerAmpSinglEndedInput() override = default;

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return mixerAmpGain_;
		}

	private:
		ValueTable<float, 40> mixerAmpGain_;
	};

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	class RightADCSingleEnded_IN3_R : public IRightADCSinglEndedInput
	{
	public:
		void InitInput() const override;
		void DeinitInput() const override;
	};

	class RightMixAmpSingleEnded_IN3_R : public IRightMixerAmpSinglEndedInput
	{
	public:
		void InitInput() const override;
		void DeinitInput() const override;
	};
}

#endif // TLV320AIC3204_IONPUT_CONFIGS_H
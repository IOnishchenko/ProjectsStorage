#ifndef TLV320AIC3204_IONPUT_CONFIGS_H
#define TLV320AIC3204_IONPUT_CONFIGS_H

#include "tlv320aic3204-driver.h"
#include "tlv320aic3204-output-configs.h"
#include "Value.h"
#include "ValueTable.h"

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	class RightPGASinglEndedInput : public virtual AudioCodecDriver::IAudioInputPGA
	{
	public:
		// constructor
		RightPGASinglEndedInput();

		// destructot
		~RightPGASinglEndedInput() override = default;

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
	class RightADCVolumeConntrol : public virtual AudioCodecDriver::IAudioInputVolumeControl
	{
	public:
		// constructor
		RightADCVolumeConntrol();

		// destructot
		~RightADCVolumeConntrol() override = default;

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
	class RightMixerAmpVolumeControlStub : public virtual AudioCodecDriver::IAudioInputVolumeControl
	{
	public:
		// constructor
		RightMixerAmpVolumeControlStub(RightMixerAmpVolumeControl & rightOutpur);

		// destructot
		~RightMixerAmpVolumeControlStub() override = default;

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return rightOutpur_.GetVolumeComtrolValue();
		}

	private:
		RightMixerAmpVolumeControl & rightOutpur_;
	};

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	class RightADCSingleEnded_IN3R
		:public RightPGASinglEndedInput, public RightADCVolumeConntrol,
		 public AudioCodecDriver::IAudioInput
	{
	public:
		// destructor
		~RightADCSingleEnded_IN3R() override = default;

		void Initialize() override;
		void Deinitialize() override;
	};

	class RightMixAmpSingleEnded_IN3R
		:public RightPGASinglEndedInput, public RightMixerAmpVolumeControlStub,
		 public AudioCodecDriver::IAudioInput
	{
	public:
		// constructor
		RightMixAmpSingleEnded_IN3R(RightMixerAmpVolumeControl & rightOutpur);

		// destructor
		~RightMixAmpSingleEnded_IN3R() override = default;

		void Initialize() override;
		void Deinitialize() override;
	};
}
#endif // TLV320AIC3204_IONPUT_CONFIGS_H
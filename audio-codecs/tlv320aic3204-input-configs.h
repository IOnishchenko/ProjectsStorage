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

	protected:
		void WriteAnalogGainToCodec(uint8_t gain) override;

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

	protected:
		void WriteVolumeControlToCodec(uint8_t gain) override;

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

	protected:
		void WriteVolumeControlToCodec(uint8_t gain) override;

	private:
		RightMixerAmpVolumeControl & rightOutpur_;
	};

	/*-----------------------------------------------------------------//
	// Right ADC Single Ended Inputs
	//-----------------------------------------------------------------*/
	class RightADCSingleEndedInput_IN3R
		:public RightPGASinglEndedInput, public RightADCVolumeConntrol,
		 public AudioCodecDriver::IAudioInput
	{
	public:
		// destructor
		~RightADCSingleEndedInput_IN3R() override = default;

		void Initialize() override;
		void Deinitialize() override;
	};

	/*-----------------------------------------------------------------//
	// Mixer Amp Single Ended Inputs
	//-----------------------------------------------------------------*/
	class RightMixAmpSingleEndedInput_IN3R
		:public RightPGASinglEndedInput, public RightMixerAmpVolumeControlStub,
		 public AudioCodecDriver::IAudioInput
	{
	public:
		// constructor
		RightMixAmpSingleEndedInput_IN3R(RightMixerAmpVolumeControl & rightOutpur);

		// destructor
		~RightMixAmpSingleEndedInput_IN3R() override = default;

		void Initialize() override;
		void Deinitialize() override;
	};
}
#endif // TLV320AIC3204_IONPUT_CONFIGS_H
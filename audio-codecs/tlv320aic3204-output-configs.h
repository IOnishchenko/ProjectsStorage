#ifndef TLV320AIC3204_OUTPUT_CONFIGS_H
#define TLV320AIC3204_OUTPUT_CONFIGS_H

#include "tlv320aic3204-driver.h"
#include "Value.h"
#include "ValueTable.h"

namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	// Abstract classes
	//-----------------------------------------------------------------*/
	class StereoPGAForHPOutput : public virtual AudioCodecDriver::IAudioOutputPGA
	{
	public:
		// constructor
		StereoPGAForHPOutput();

		// destructor 
		~StereoPGAForHPOutput() override = default;
		
		// methods
		void SetAnalogGain(uint32_t index) override;
		const IValue<float> & GetAnalogGain() const override
		{
			return analogGain_;
		}

	private:
		Value<float> analogGain_;
	};

	class DifferntialPGAForLineOutput : public virtual AudioCodecDriver::IAudioOutputPGA
	{
	public:
		// constructor
		DifferntialPGAForLineOutput();

		// destructor 
		~DifferntialPGAForLineOutput() override = default;
		
		// methods
		void SetAnalogGain(uint32_t index) override;
		const IValue<float> & GetAnalogGain() const override
		{
			return analogGain_;
		}

	private:
		Value<float> analogGain_;
	};

	class RightMixerAmpVolumeControl : public virtual AudioCodecDriver::IAudioOutputVolumeControl
	{
	public:
		// constructor
		RightMixerAmpVolumeControl();

		// destructor`
		~RightMixerAmpVolumeControl();

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return mixerAmpGain_;
		}
	
	private:
		ValueTable<float, 40> mixerAmpGain_;
	};

	class StereoDACVolumeControl : public virtual AudioCodecDriver::IAudioOutputVolumeControl
	{
	public:
		// constructor
		StereoDACVolumeControl();

		// destructor
		~StereoDACVolumeControl();

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return digitalGain_;
		}
	
	private:
		Value<float> digitalGain_;
	};

	class RighDACVolumeControl : public virtual AudioCodecDriver::IAudioOutputVolumeControl
	{
	public:
		// constructor
		RighDACVolumeControl();

		// destructor
		~RighDACVolumeControl();

		// methods
		void SetVolumeComtrolValue(uint32_t index) override;
		const IValue<float> & GetVolumeComtrolValue() const override
		{
			return digitalGain_;
		}
	
	private:
		Value<float> digitalGain_;
	};

	/*-----------------------------------------------------------------//
	// Stereo DAC Outputs
	//-----------------------------------------------------------------*/
	class StereoDACSingleEnded_HPLR
		:public StereoPGAForHPOutput, public StereoDACVolumeControl,
		 public AudioCodecDriver::IAudioOutput
	{
	public:
		// destructor
		~StereoDACSingleEnded_HPLR() override = default;

		// methods
		void Initialize() override;
		void Deinitialize() override;
	};

	/*-----------------------------------------------------------------//
	// Right DAC Outputs
	//-----------------------------------------------------------------*/
	class RightDACDifferntial_LO
		:public DifferntialPGAForLineOutput, public RighDACVolumeControl,
		 public AudioCodecDriver::IAudioOutput
	{
	public:
		// destructor
		~RightDACDifferntial_LO() override = default;

		// methods
		void Initialize() override;
		void Deinitialize() override;
	};

	/*-----------------------------------------------------------------//
	// Mixer Amp Outputs
	//-----------------------------------------------------------------*/
	class RightMixAmpDifferntial_LO
		:public DifferntialPGAForLineOutput, public RightMixerAmpVolumeControl,
		 public AudioCodecDriver::IAudioOutput
	{
	public:
		// destructor
		~RightMixAmpDifferntial_LO() override = default;

		// methods
		void Initialize() override;
		void Deinitialize() override;
	};

	class RightMixAmpSingleEnded_HPLR
		:public StereoPGAForHPOutput, public RightMixerAmpVolumeControl,
		 public AudioCodecDriver::IAudioOutput
	{
	public:
		// destructor
		~RightMixAmpSingleEnded_HPLR() override = default;

		// methods
		void Initialize() override;
		void Deinitialize() override;
	};
}

#endif // TLV320AIC3204_OUTPUT_CONFIGS_H
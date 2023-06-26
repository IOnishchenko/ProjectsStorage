#ifndef TLV320AIC3204_H
#define TLV320AIC3204_H

#include "stdint.h"
#include <memory>
#include "ValueProvider.h"
#include "ValueCollection.h"

namespace tlv320aic3204
{
/*-----------------------------------------------------------------//
// constants
//-----------------------------------------------------------------*/
// i2c address
constexpr uint8_t I2C_CODEC_ADDRES = 0x18;
// common reg
constexpr uint8_t PX_PAGE_REG = 0x0;

// page 0
constexpr uint8_t P0_SOFT_RESET_REG = 1;

constexpr uint8_t P0_PLL_INPUT_MUX_REG = 4;
constexpr uint8_t P0_PLL_P_R_VALUES_REG = 5;
constexpr uint8_t P0_PLL_J_VALUE_REG = 6;
constexpr uint8_t P0_PLL_D_MSB_VALUE_REG = 7;
constexpr uint8_t P0_PLL_D_LSB_VALUE_REG = 8;

constexpr uint8_t P0_NDAC_REG = 11;
constexpr uint8_t P0_MDAC_REG = 12;
constexpr uint8_t P0_DAC_OSR_MSB_REG = 13;
constexpr uint8_t P0_DAC_OSR_LSB_REG = 14;

constexpr uint8_t P0_NADC_REG = 18;
constexpr uint8_t P0_MADC_REG = 19;
constexpr uint8_t P0_ADC_OSR_REG = 20;

constexpr uint8_t P0_AUDIO_INTERFACE_REG = 27;
constexpr uint8_t P0_LOOPBACK_CONTROL_REG = 29;

constexpr uint8_t P0_DAC_PROCESSING_BLOCK_REG = 60;
constexpr uint8_t P0_ADC_PROCESSING_BLOCK_REG = 61;

// page 1
constexpr uint8_t P1_POWER_CONF_REG = 1;
constexpr uint8_t P1_LDO_CONTROL_REG = 2;
constexpr uint8_t P1_COMMON_MODE_REG = 10;
constexpr uint8_t P1_MICBIAS_CONFIG_REG = 51;
constexpr uint8_t P1_ADC_INPUT_POWER_UP_TIME_REG = 71;
constexpr uint8_t P1_REF_POWER_UP_TIME_REG = 123;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
	class AudioCodecDriver
	{
	public:
		// nested types
		enum class MicBias;
		class IAudioOutput;
		class IAudioInput;
		// conatructor
		AudioCodecDriver();

		// destructor
		virtual ~AudioCodecDriver() = default;

		// methods
		void Initialize();
		uint8_t GetAddress() const
		{
			return I2C_CODEC_ADDRES;
		}

	private:
		// methods
		void SetRegisterPage(uint8_t page);
		void PowerUp();
		void ResetSampleRateSettings();
		void SetSampleRateTo12KHz();
		void SetSampleRateTo24KHz();
		void SetSampleRateTo48KHz();
		void SetSampleRateTo96KHz();
		void SetAudioInterfaceTo32BitsI2S();
		void SetAudioInterfaceTo32BitsRJF();
		void SetMicBias(MicBias value);
		void SwitchOutputToStereoHeadphone();
		void SwitchOutputToMonoDifferLineOut();
		
		// data
		uint8_t currentPage_ = 0;
		std::unique_ptr<AudioOutput> output_;
		std::unique_ptr<AudioInput> input_;
	};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
	enum class AudioCodecDriver::MicBias
	{
		OFF,
		// these values are available when Page 1, Reg 10, D6 = 0, see void PowerUp()
		V1V25, V1V7, V2V5,
		// these values are available when Page 1, Reg 10, D6 = 1, see void PowerUp()
		//V1V0, V1V4, V2V1,
		AVDD,
		LDOIN,  
	};

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioOutput
	{
	public:
		// constructor
		AudioOutput(const ValueProvider & analogGain, const ValueProvider & digitalGain);
		// destructor
		virtual ~AudioOutput() = default;

		// methods
		virtual void InitOutput() const = 0;
		virtual void DeinitOutput() const = 0;
		virtual const ValueProvider & GetAnalogGain() const = 0;
		virtual void SetAnalogGain(uint32_t index) = 0;
		virtual const ValueProvider & GetDititalGain() const = 0;
		virtual void SetDititalGain(uint32_t index) = 0;

	private:
		// data
		ValueProvider analogGain_;
		ValueProvider digitalGain_;
	};
	
/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioInput
	{
	public:
		// constructor
		AudioInput(const ValueProvider & analogGain, const ValueProvider & digitalGain,
			const ValueProvider & gainAdjLeft, const ValueProvider & gainAdjRight_);
		AudioInput(const ValueProvider & analogGain, const ValueProvider & digitalGain);
		// destructor
		virtual ~AudioInput() = default;

		// method
		virtual void InitInput() const = 0;
		virtual void DeinitInput() const = 0;

		virtual const ValueProvider & GetAnalogGain() const = 0;
		virtual void SetAnalogGain(uint32_t index) = 0;

		virtual const ValueProvider & GetAdjLeftGain() const = 0;
		virtual void SetAdjLeftGain(uint32_t index) = 0;
		
		virtual const ValueProvider & GetAdjRightGain() const = 0;
		virtual void SetAdjRightGain(uint32_t index) = 0;
		
		virtual const ValueProvider & GetDigitalGain() const = 0;
		virtual void SetDititalGain(uint32_t index) = 0;

	private:
		// data
		ValueProvider analogGain_;
		ValueProvider gainAdjLeft_;
		ValueProvider gainAdjRight_;
		ValueProvider digitalGain_;
	};

} // namespace audio

#endif // TLV320AIC3204_H
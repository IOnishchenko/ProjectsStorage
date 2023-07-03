#ifndef TLV320AIC3204_H
#define TLV320AIC3204_H

#include "stdint.h"
#include <memory>
#include "IValue.h"

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

constexpr uint8_t P0_DAC_CHANNEL_SETUP_REG1 = 63;
constexpr uint8_t P0_DAC_CHANNEL_SETUP_REG2 = 64;
constexpr uint8_t P0_LEFT_DAC_DIGITAL_GAIN_REG = 65;
constexpr uint8_t P0_RIGHT_DAC_DIGITAL_GAIN_REG = 66;

constexpr uint8_t P0_ADC_CHANNEL_SETUP_REG = 81;
constexpr uint8_t P0_ADC_ADJ_GAIN_REG = 82;
constexpr uint8_t P0_LEFT_ADC_DIGITAL_GAIN_REG = 83;
constexpr uint8_t P0_RIGHT_ADC_DIGITAL_GAIN_REG = 84;

// page 1
constexpr uint8_t P1_POWER_CONF_REG = 1;
constexpr uint8_t P1_LDO_CONTROL_REG = 2;
constexpr uint8_t P1_OUTPUT_DRIVER_POWER_REG = 9;
constexpr uint8_t P1_COMMON_MODE_REG = 10;

constexpr uint8_t P1_HPL_ROUTING_SELECTION_REG = 12;
constexpr uint8_t P1_HPR_ROUTING_SELECTION_REG = 13;
constexpr uint8_t P1_LOL_ROUTING_SELECTION_REG = 14;
constexpr uint8_t P1_LOR_ROUTING_SELECTION_REG = 15;

constexpr uint8_t P1_HPL_GAIN_SETTING_REG = 16;
constexpr uint8_t P1_HPR_GAIN_SETTING_REG = 17;
constexpr uint8_t P1_LOL_GAIN_SETTING_REG = 18;
constexpr uint8_t P1_LOR_GAIN_SETTING_REG = 19;

constexpr uint8_t P1_HP_DRIVER_SETUP_REG = 20;

constexpr uint8_t P1_LEFT_MIXER_AMP_VOLUME_CONTROL_REG = 24;
constexpr uint8_t P1_RIGHT_MIXER_AMP_VOLUME_CONTROL_REG = 25;

constexpr uint8_t P1_MICBIAS_CONFIG_REG = 51;
constexpr uint8_t P1_LEFT_MIC_PGA_POSITIVE_INPUT_REG = 52;
constexpr uint8_t P1_LEFT_MIC_PGA_NEGATIVE_INPUT_REG = 54;
constexpr uint8_t P1_RIGHT_MIC_PGA_POSITIVE_INPUT_REG = 55;
constexpr uint8_t P1_RIGHT_MIC_PGA_NEGATIVE_INPUT_REG = 57;
constexpr uint8_t P1_FLOATING_INPUT_CONF_REG = 58;
constexpr uint8_t P1_LEFT_MICPGA_VOL_CONTROL_REG = 59;
constexpr uint8_t P1_RIGHT_MICPGA_VOL_CONTROL_REG = 60;

constexpr uint8_t P1_ADC_INPUT_POWER_UP_TIME_REG = 71;
constexpr uint8_t P1_REF_POWER_UP_TIME_REG = 123;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
	class AudioCodecDriver
	{
	public:
		// nested types
		enum class MicBias;
		class IAudioInputPGA;
		class IAudioInputVolumeControl;
		class IAudioOutputPGA;
		class IAudioOutputVolumeControl;
		class IAudioInput;
		class IAudioOutput;
		
		// conatructor
		AudioCodecDriver(IAudioInput * audioInput, IAudioOutput * audioOutput);

		// destructor
		virtual ~AudioCodecDriver() = default;

		// methods
		void Initialize();
		uint8_t GetAddress() const
		{
			return I2C_CODEC_ADDRES;
		}

	protected:
		// methods
		void SetRegisterPage(uint8_t page);

	private:
		// methods
		void PowerUp();
		void HeadphoneDriverSetup();
		
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
		uint8_t currentPage_ = 0xff;
		IAudioOutput * output_ = nullptr;
		IAudioInput * input_ = nullptr;

		friend class IAudioInputPGA;
		friend class IAudioInputVolumeControl;
		friend class IAudioOutputPGA;
		friend class IAudioOutputVolumeControl;
		friend class IAudioInput;
		friend class IAudioOutput;
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
	class AudioCodecDriver::IAudioInputPGA
	{
	public:
		// destructor
		virtual ~IAudioInputPGA() = default;
		// methods
		virtual const IValue<float> & GetAnalogGain() const = 0;
		virtual void SetAnalogGain(uint32_t index) = 0;

	protected:
		virtual void WriteAnalogGainToCodec(uint8_t gain) = 0;
		void SetRegisterPage(uint8_t page);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioInputVolumeControl
	{
	public:
		// destructor
		virtual ~IAudioInputVolumeControl() = default;
		// methods
		virtual const IValue<float> & GetVolumeComtrolValue() const = 0;
		virtual void SetVolumeComtrolValue(uint32_t index) = 0;

		// TODO
		// Gain correction can be added to left and right channel
		//virtual const Value<float> & GetAdjLeftGain() const {return gainAdjLeft_;};
		//virtual void SetAdjLeftGain(uint32_t index) {};
		//virtual const Value<float> & GetAdjRightGain() const {return gainAdjRight_;};
		//virtual void SetAdjRightGain(uint32_t index) {};
	protected:
		virtual void WriteVolumeControlToCodec(uint8_t gain) = 0;
		void SetRegisterPage(uint8_t page);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioOutputPGA
	{
	public:
		// destructor
		virtual ~IAudioOutputPGA() = default;
		// methods
		virtual const IValue<float> & GetAnalogGain() const = 0;
		virtual void SetAnalogGain(uint32_t index) = 0;

	protected:
		virtual void WriteAnalogGainToCodec(uint8_t gain) = 0;
		void SetRegisterPage(uint8_t page);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioOutputVolumeControl
	{
	public:
		// destructor
		virtual ~IAudioOutputVolumeControl() = default;
		// methods
		virtual const IValue<float> & GetVolumeComtrolValue() const = 0;
		virtual void SetVolumeComtrolValue(uint32_t index) = 0;

	protected:
		virtual void WriteVolumeControlToCodec(uint8_t gain) = 0;
		void SetRegisterPage(uint8_t page);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioInput
		:public virtual AudioCodecDriver::IAudioInputPGA,
		 public virtual AudioCodecDriver::IAudioInputVolumeControl
	{
	public:
		// destructor
		virtual ~IAudioInput() = default;
		// methods
		virtual void Initialize() = 0;
		virtual void Deinitialize() = 0;
	
	protected:
		void SetRegisterPage(uint8_t page);
	};

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	class AudioCodecDriver::IAudioOutput
		:public virtual AudioCodecDriver::IAudioOutputPGA,
		 public virtual AudioCodecDriver::IAudioOutputVolumeControl
	{
	public:
		// destructor
		virtual ~IAudioOutput() = default;
		// methods
		virtual void Initialize() = 0;
		virtual void Deinitialize() = 0;

	protected:
		void SetRegisterPage(uint8_t page);
	};
	
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/


// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// 	class AudioCodecDriver::IAudioOutput
// 	{
// 	public:
// 		// destructor
// 		virtual ~IAudioOutput() = default;

// 		// methods
// 		virtual void InitOutput() const = 0;
// 		virtual void DeinitOutput() const = 0;
// 		virtual const IValue<float> & GetAnalogGain() const = 0;
// 		virtual void SetAnalogGain(uint32_t index) = 0;
// 		virtual const IValue<float> & GetVolumeComtrolValue() const = 0;
// 		virtual void SetVolumeComtrolValue(uint32_t index) = 0;
// 	};
	
// /*-----------------------------------------------------------------//
// //
// //-----------------------------------------------------------------*/
// 	class AudioCodecDriver::IAudioInput
// 	{
// 	public:
// 		// destructor
// 		virtual ~IAudioInput() = default;

// 		// method
// 		virtual void InitInput() const = 0;
// 		virtual void DeinitInput() const = 0;

// 		virtual const IValue<float> & GetAnalogGain() const = 0;
// 		virtual void SetAnalogGain(uint32_t index) = 0;
// 		virtual const IValue<float> & GetVolumeComtrolValue() const = 0;
// 		virtual void SetVolumeComtrolValue(uint32_t index) = 0;

// 		// TODO
// 		// Gain correction can be added to left and right channel
// 		//virtual const Value<float> & GetAdjLeftGain() const {return gainAdjLeft_;};
// 		//virtual void SetAdjLeftGain(uint32_t index) {};
// 		//virtual const Value<float> & GetAdjRightGain() const {return gainAdjRight_;};
// 		//virtual void SetAdjRightGain(uint32_t index) {};
// 	};

} // namespace audio

#endif // TLV320AIC3204_H
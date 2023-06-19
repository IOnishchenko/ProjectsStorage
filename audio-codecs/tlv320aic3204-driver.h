#ifndef TLV320AIC3204_H
#define TLV320AIC3204_H

#include "stdint.h"

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

constexpr uint8_t P0_INTERFACE_REG = 27;

// page 1
constexpr uint8_t P1_POWER_CONF_REG = 1;
constexpr uint8_t P1_LDO_CONTROL_REG = 2;
constexpr uint8_t P1_COMMON_MODE_REG = 10;
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
		void PowerUp();
		
	};
} // namespace audio

#endif // TLV320AIC3204_H
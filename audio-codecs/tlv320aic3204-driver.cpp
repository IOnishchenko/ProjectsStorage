#include "tlv320aic3204-driver.h"
#include "tlv320aic3204-interface.h"

/*-----------------------------------------------------------------//
// Dependencies
//-----------------------------------------------------------------*/
extern tlv320aic3204::AudioCodecDriver AudioDevice;

/*-----------------------------------------------------------------//
// Output channels instances
//-----------------------------------------------------------------*/

/*-----------------------------------------------------------------//
// Input channels instances
//-----------------------------------------------------------------*/

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
namespace tlv320aic3204
{
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	extern "C" void tlv320aic3204_codec_thread(void * args)
	{
		printf("--== tlv320aic3204_codec_thread has started ==--\n");
		//AudioDevice.Initialize();
		int i = 0;
		for(;;)
		{
			printf("--== tlv320aic3204_codec_thread running ==-- %d\n", i);
			i++;
			vTaskDelay(100);
		}
	}

	// public methods
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	AudioCodecDriver::AudioCodecDriver()
	{
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::Initialize()
	{
		PowerUp();
	}

	// private methods
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	inline void AudioCodecDriver::SetRegisterPage(uint8_t page)
	{
		if(currentPage_ != page)
		{
			currentPage_ = page;
			uint8_t cmd[] = {PX_PAGE_REG, page};
			tlv320aic3204_write_buffer(cmd, sizeof(cmd));
		}
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::PowerUp()
	{
		// set page 1
		SetRegisterPage(1);
		// AVDD LDO power up
		uint8_t buff[] = 
		{
			P1_LDO_CONTROL_REG,
			0x09
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
		// Disable weak AVDD for external
		buff[0] = P1_POWER_CONF_REG;
		buff[1] = 0x08;
		tlv320aic3204_write_buffer(buff, 2);
		// Enable Analog Block Power control
		buff[0] = P1_LDO_CONTROL_REG;
		buff[1] = 0x01;
		tlv320aic3204_write_buffer(buff, 2);
		// Set full chip common mode (CM) to 0.9V
		// Set HPL and HPR CM to 1.65V
		// HPL and HPR is powered with LDOIN
		// Set LOL and LOR CM to 1.65V
		// LOL and LOR is powered by LDOIN
		// LDOIN input range is 1.8V - 3.6V
		buff[0] = P1_COMMON_MODE_REG;
		buff[1] = 0x3b;
		tlv320aic3204_write_buffer(buff, 2);
		// Set analog input power up time to 6.4ms
		buff[0] = P1_ADC_INPUT_POWER_UP_TIME_REG;
		buff[1] = 0x32;
		tlv320aic3204_write_buffer(buff, 2);
		// Set the REF power up time to 40ms
		buff[0] = P1_REF_POWER_UP_TIME_REG;
		buff[1] = 0x01;
		tlv320aic3204_write_buffer(buff, 2);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::ResetSampleRateSettings()
	{
		// set page 0
		SetRegisterPage(0);
		// set PLL
		uint8_t cmd[] = 
		{
			P0_PLL_P_R_VALUES_REG,
			// PLL is powered down
			// PLL divider P = 1
			// PLL divider R = 4
			(0 << 7)|(1 << 4)|(1),
			// PLL divider J = 36
			4
		};
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// set DAC clocks
		uint8_t dac_clck[] =
		{
			P0_NDAC_REG,
			// NDAC power down
			// NDAC = 2
			(0 << 7)|(1),
			// MDAC power down
			// MDAC = 9
			(0 << 7)|(1),
			// DOSR = 128, DOSR MSB = 0
			0x00,
			// DOSR LSB = 128
			0x80
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power down. DAC_CLK is used
			0x01,
			// MADC power down
			// MADC = 18
			0x01,
			// AOSR = 128
			0x80
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetSampleRateTo12KHz()
	{
		// set page 0
		SetRegisterPage(0);
		// set PLL
		uint8_t cmd[] = 
		{
			P0_PLL_INPUT_MUX_REG,
			// High PLL Clock Range
			// BCLK pin is PLL input
			// PLL Clock is CODEC_CLKIN
			0b01000111,
			// PLL is powered up
			// PLL divider P = 1
			// PLL divider R = 4
			(1 << 7)|(1 << 4)|(4),
			// PLL divider J = 36
			36
		};
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// set DAC clocks
		uint8_t dac_clck[] =
		{
			P0_NDAC_REG,
			// NDAC power up
			// NDAC = 2
			(1 << 7)|(2),
			// MDAC power up
			// MDAC = 9
			(1 << 7)|(9),
			// DOSR = 512, DOSR MSB = 2
			0x02,
			// DOSR LSB = 0
			0x00
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power down. DAC_CLK is used
			0x00,
			// MADC power up
			// MADC = 18
			(1 << 7)|(18),
			// AOSR = 256
			0x00
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// set DAC and ADC Processing block
		uint8_t prb[] =
		{
			P0_DAC_PROCESSING_BLOCK_REG,
			// DAC - PRB_P4
			4,
			// ADC - PRB_R4
			4
		};
		tlv320aic3204_write_buffer(prb, sizeof(prb));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetSampleRateTo24KHz()
	{
		// set page 0
		SetRegisterPage(0);
		// set PLL
		uint8_t cmd[] = 
		{
			P0_PLL_INPUT_MUX_REG,
			// High PLL Clock Range
			// BCLK pin is PLL input
			// PLL Clock is CODEC_CLKIN
			0b01000111,
			// PLL is powered up
			// PLL divider P = 2
			// PLL divider R = 4
			(1 << 7)|(2 << 4)|(4),
			// PLL divider J = 36
			36
		};
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// set DAC clocks
		uint8_t dac_clck[] =
		{
			P0_NDAC_REG,
			// NDAC power up
			// NDAC = 2
			(1 << 7)|(2),
			// MDAC power up
			// MDAC = 9
			(1 << 7)|(9),
			// DOSR = 256, DOSR MSB = 1
			0x01,
			// DOSR LSB = 0
			0x00
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power down. DAC_CLK is used
			0x00,
			// MADC power down. DAC_MOD_CLK is used
			0x00,
			// AOSR = 256
			0x00
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// set DAC and ADC Processing block
		uint8_t prb[] =
		{
			P0_DAC_PROCESSING_BLOCK_REG,
			// DAC - PRB_P4
			4,
			// ADC - PRB_R4
			4
		};
		tlv320aic3204_write_buffer(prb, sizeof(prb));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetSampleRateTo48KHz()
	{
		// set page 0
		SetRegisterPage(0);
		// set PLL
		uint8_t cmd[] = 
		{
			P0_PLL_INPUT_MUX_REG,
			// High PLL Clock Range
			// BCLK pin is PLL input
			// PLL Clock is CODEC_CLKIN
			0b01000111,
			// PLL is powered up
			// PLL divider P = 4
			// PLL divider R = 4
			(1 << 7)|(4 << 4)|(4),
			// PLL divider J = 36
			36
		};
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// set DAC clocks
		uint8_t dac_clck[] =
		{
			P0_NDAC_REG,
			// NDAC power up
			// NDAC = 2
			(1 << 7)|(2),
			// MDAC power up
			// MDAC = 9
			(1 << 7)|(9),
			// DOSR = 128, DOSR MSB = 0
			0x00,
			// DOSR LSB = 0x80
			0x80
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power down. DAC_CLK is used
			0x00,
			// MADC power down. DAC_MOD_CLK is used
			0x00,
			// AOSR = 128
			0x80
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// set DAC and ADC Processing block
		uint8_t prb[] =
		{
			P0_DAC_PROCESSING_BLOCK_REG,
			// DAC - PRB_P4
			4,
			// ADC - PRB_R4
			4
		};
		tlv320aic3204_write_buffer(prb, sizeof(prb));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetSampleRateTo96KHz()
	{
		// set page 0
		SetRegisterPage(0);
		// set PLL
		uint8_t cmd[] = 
		{
			P0_PLL_INPUT_MUX_REG,
			// High PLL Clock Range
			// BCLK pin is PLL input
			// PLL Clock is CODEC_CLKIN
			0b01000111,
			// PLL is powered up
			// PLL divider P = 8
			// PLL divider R = 4
			(1 << 7)|(8 << 4)|(4),
			// PLL divider J = 36
			36
		};
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// set DAC clocks
		uint8_t dac_clck[] =
		{
			P0_NDAC_REG,
			// NDAC power up
			// NDAC = 2
			(1 << 7)|(2),
			// MDAC power up
			// MDAC = 9
			(1 << 7)|(9),
			// DOSR = 64, DOSR MSB = 0
			0x00,
			// DOSR LSB = 0x80
			0x40
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power down. DAC_CLK is used
			0x00,
			// MADC power down. DAC_MOD_CLK is used
			0x00,
			// AOSR = 64
			0x40
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// set DAC and ADC Processing block
		uint8_t prb[] =
		{
			P0_DAC_PROCESSING_BLOCK_REG,
			// DAC - PRB_P4
			4,
			// ADC - PRB_R4
			4
		};
		tlv320aic3204_write_buffer(prb, sizeof(prb));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetAudioInterfaceTo32BitsI2S()
	{
		// set page 0
		SetRegisterPage(0);
		// set audio interface
		uint8_t i2s[] =
		{
			P0_AUDIO_INTERFACE_REG,
			// Audio Interface = I2S
			// Audio Data length = 32
			// BCLK as input
			// WCLK as input
			// DOUT will be high impedance after data has been transferred
			(0b00 << 6)|(0b11 << 4)|(0b0 << 3)|(0b0 << 2)|(0b0 << 1)|(0b1),
			// Data offset value = 0 BCLKs
			// 0b00000000
		};
		tlv320aic3204_write_buffer(i2s, sizeof(i2s));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetAudioInterfaceTo32BitsRJF()
	{
		// set page 0
		SetRegisterPage(0);
		// set audio interface
		uint8_t rjf[] =
		{
			P0_AUDIO_INTERFACE_REG,
			// Audio Interface = I2S
			// Audio Data length = 32
			// BCLK as input
			// WCLK as input
			// DOUT will be high impedance after data has been transferred
			(0b00 << 6)|(0b10 << 4)|(0b0 << 3)|(0b0 << 2)|(0b0 << 1)|(0b1),
			// Data offset value = 0 BCLKs
			// 0b00000000
		};
		tlv320aic3204_write_buffer(rjf, sizeof(rjf));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::SetMicBias(MicBias value)
	{
		// set page 1
		SetRegisterPage(1);
		// micbias
		uint8_t cmd[] = {P1_MICBIAS_CONFIG_REG, 0};
		switch (value)
		{
		case MicBias::V1V25:
			cmd[1] = (1 << 6)|(0b00 << 4);
			break;
		case MicBias::V1V7:
			cmd[1] = (1 << 6)|(0b01 << 4);
			break;
		case MicBias::V2V5:
			cmd[1] = (1 << 6)|(0b10 << 4)|(1 << 3);
			break;
		case MicBias::AVDD:
			cmd[1] = (1 << 6)|(0b11 << 4);
			break;
		case MicBias::LDOIN:
			cmd[1] = (1 << 6)|(0b11 << 4)|(1 << 3);
			break;
		case MicBias::OFF:
			cmd[1] = 0;
			break;
		}
		tlv320aic3204_write_buffer(cmd, sizeof(cmd));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
}
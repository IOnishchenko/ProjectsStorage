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
	// public methods
	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	AudioCodecDriver::AudioCodecDriver(IAudioInput * audioInput, IAudioOutput * audioOutput)
		:output_{audioOutput}, input_{audioInput}
	{
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::Initialize()
	{
		// set page 0
		SetRegisterPage(0);
		// reset
		uint8_t cmd0[] =
		{
			P0_SOFT_RESET_REG,
			0x01
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));
		PowerUp();
		HeadphoneDriverSetup();
		SetAudioInterfaceTo32BitsRJF();
		SetSampleRateTo48KHz();
		
		// load ADC filter coefs
		// uint8_t coefs[] =
		// {
		// 	0x03, 0x7F, 0x0C,
		// 	0x03, 0x7F, 0x0C,
		// 	0x03, 0x7F, 0x0C,
		// 	0x34, 0x56, 0x3C,
		// 	0x89, 0x57, 0xD5,
		// };

		// LPF 6 kHz
		// uint8_t coefsN0[] = { /* P = 8, R = 36 */ 36, 0x0C, 0x7F, 0x03};
		// uint8_t coefsN1[] = { /* P = 8, R = 40 */ 40, 0x0C, 0x7F, 0x03};
		// uint8_t coefsN2[] = { /* P = 8, R = 44 */ 44, 0x0C, 0x7F, 0x03};
		// uint8_t coefsD1[] = { /* P = 8, R = 48 */ 48, 0x3C, 0x56, 0x34};
		// uint8_t coefsD2[] = { /* P = 8, R = 52 */ 52, 0xD5, 0x57, 0x89};

		// LPF 500 Hz
		// uint8_t coefsN0[] = { /* P = 8, R = 36 */ 36, 0x00, 0x21, 0x87};
		// uint8_t coefsN1[] = { /* P = 8, R = 40 */ 40, 0x00, 0x21, 0x87};
		// uint8_t coefsN2[] = { /* P = 8, R = 44 */ 44, 0x00, 0x21, 0x87};
		// uint8_t coefsD1[] = { /* P = 8, R = 48 */ 48, 0x7A, 0x14, 0x4B};
		// uint8_t coefsD2[] = { /* P = 8, R = 52 */ 52, 0x8B, 0x51, 0x4C};


		// load to left channel
		// SetRegisterPage(8);
		// for(int i = 0; i < 5; i++)
		// {
		// 	tlv320aic3204_write_buffer(coefsN0, sizeof(coefsN0));
		// 	tlv320aic3204_write_buffer(coefsN1, sizeof(coefsN1));
		// 	tlv320aic3204_write_buffer(coefsN2, sizeof(coefsN2));
		// 	tlv320aic3204_write_buffer(coefsD1, sizeof(coefsD1));
		// 	tlv320aic3204_write_buffer(coefsD2, sizeof(coefsD2));
		// 	// update registers address with ofset
		// 	// slaa557 - Table 2-9. ADC Biquad Filter Coefficients, Table 5-2. ADC Coefficient Buffer-A Map
		// 	coefsN0[0] += 20;
		// 	coefsN1[0] += 20;
		// 	coefsN2[0] += 20;
		// 	coefsD1[0] += 20;
		// 	coefsD2[0] += 20;
		// }

		// // load to the right channel
		// coefsN0[0] = 44;
		// coefsN1[0] = 48;
		// coefsN2[0] = 52;
		// coefsD1[0] = 56;
		// coefsD2[0] = 60;

		// SetRegisterPage(9);
		// for(int i = 0; i < 5; i++)
		// {
		// 	tlv320aic3204_write_buffer(coefsN0, sizeof(coefsN0));
		// 	tlv320aic3204_write_buffer(coefsN1, sizeof(coefsN1));
		// 	tlv320aic3204_write_buffer(coefsN2, sizeof(coefsN2));
		// 	tlv320aic3204_write_buffer(coefsD1, sizeof(coefsD1));
		// 	tlv320aic3204_write_buffer(coefsD2, sizeof(coefsD2));
		// 	// update registers address with ofset
		// 	// slaa557 - Table 2-9. ADC Biquad Filter Coefficients, Table 5-2. ADC Coefficient Buffer-A Map
		// 	coefsN0[0] += 20;
		// 	coefsN1[0] += 20;
		// 	coefsN2[0] += 20;
		// 	coefsD1[0] += 20;
		// 	coefsD2[0] += 20;
		// }

		output_->Initialize();
		input_->Initialize();
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
			// Analog block disabled - by default D3 = 1
			// AVDD LDO Powered up
			(1 << 3)|(1 << 0)
		};
		tlv320aic3204_write_buffer(buff, sizeof(buff));
		// Disable weak AVDD for external
		buff[0] = P1_POWER_CONF_REG;
		// Disabled weak connection of AVDD with DVDD
		buff[1] = (1 << 3);
		tlv320aic3204_write_buffer(buff, 2);
		// Enable Analog Block Power control
		buff[0] = P1_LDO_CONTROL_REG;
		// Analog block enabled D3 = 0
		// AVDD LDO Powered up
		buff[1] = (0 << 3)|(1 << 0);
		tlv320aic3204_write_buffer(buff, 2);
		// Set full chip common mode (CM) to 0.9V
		// Set HPL and HPR CM to 1.65V
		// HPL and HPR is powered with LDOIN
		// Set LOL and LOR CM to 1.65V
		// LOL and LOR is powered by LDOIN
		// LDOIN input range is 1.8V - 3.6V
		buff[0] = P1_COMMON_MODE_REG;
		buff[1] = (0 << 6)|(0b11 << 4)|(1 << 3)|(1 << 1)|(1 << 0);
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
	void AudioCodecDriver::HeadphoneDriverSetup()
	{
		// set page 1
		SetRegisterPage(1);
		uint8_t cmd0[] =
		{
			P1_HP_DRIVER_SETUP_REG,
			// Headphone ramps power up slowly in 5.0 time constants
			// Headphone ramps power up time is determined with 6k resistance
			(0b1001 << 2)|(0b01 << 0)
		};
		tlv320aic3204_write_buffer(cmd0, sizeof(cmd0));
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::ResetSampleRateSettings()
	{
		/*	slaa557.pdf
			When the ADC channel is powered down, the device internally initiates a powerdown sequence for proper shut-down.
			During this shut-down sequence, the NADC and MADC dividers
			must not be powered down, or else a proper low power shut-down may not take place. The user can read
			the power-status flag in Page 0, Register 36, D(6) and Page 0, Register 36, D(2). When both flags
			indicate power-down, the MADC divider may be powered down, followed by NADC divider.
		*/
		
		// // set page 0
		// SetRegisterPage(0);
		// // set PLL
		// uint8_t cmd[] = 
		// {
		// 	P0_PLL_P_R_VALUES_REG,
		// 	// PLL is powered down
		// 	// PLL divider P = 1
		// 	// PLL divider R = 4
		// 	(0 << 7)|(1 << 4)|(1),
		// 	// PLL divider J = 36
		// 	4
		// };
		// tlv320aic3204_write_buffer(cmd, sizeof(cmd));

		// // set DAC clocks
		// uint8_t dac_clck[] =
		// {
		// 	P0_NDAC_REG,
		// 	// NDAC power down
		// 	// NDAC = 2
		// 	(0 << 7)|(1),
		// 	// MDAC power down
		// 	// MDAC = 9
		// 	(0 << 7)|(1),
		// 	// DOSR = 128, DOSR MSB = 0
		// 	0x00,
		// 	// DOSR LSB = 128
		// 	0x80
		// };
		// tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		// //set ADC clock
		// uint8_t adc_clck[] =
		// {
		// 	P0_NADC_REG,
		// 	// NADC power down. DAC_CLK is used
		// 	0x01,
		// 	// MADC power down
		// 	// MADC = 18
		// 	0x01,
		// 	// AOSR = 128
		// 	0x80
		// };
		// tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
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
			// NADC power up. DAC_CLK is used
			// NDAC = 2
			(1 << 7)|(4),
			// MADC power up
			// MADC = 18
			(1 << 7)|(18),
			// AOSR = 128
			0x80
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// // set DAC and ADC Processing block
		// uint8_t prb[] =
		// {
		// 	P0_DAC_PROCESSING_BLOCK_REG,
		// 	// DAC - PRB_P4
		// 	4,
		// 	// ADC - PRB_R4
		// 	4
		// };
		// tlv320aic3204_write_buffer(prb, sizeof(prb));
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
			// PLL divider P = 1
			// PLL divider R = 4
			(1 << 7)|(1 << 4)|(4),
			// PLL divider J = 18
			18
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
			// NADC power up
			// NADC = 2
			(1 << 7)|(2),
			// MADC power up
			// MADC = 9
			(1 << 7)|(9),
			// AOSR = 256
			0x00
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// // set DAC and ADC Processing block
		// uint8_t prb[] =
		// {
		// 	P0_DAC_PROCESSING_BLOCK_REG,
		// 	// DAC - PRB_P4
		// 	4,
		// 	// ADC - PRB_R4
		// 	4
		// };
		// tlv320aic3204_write_buffer(prb, sizeof(prb));
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
			(1 << 6)|(0b01 << 2)|(0b11),
			// PLL is powered up
			// PLL divider P = 1
			// PLL divider R = 4
			(1 << 7)|(1 << 4)|(4),
			// PLL divider J = 8
			8
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
			// MDAC = 8
			(1 << 7)|(8),
			// DOSR = 128, DOSR MSB = 0
			0,
			// DOSR LSB = 0x80
			128
		};
		tlv320aic3204_write_buffer(dac_clck, sizeof(dac_clck));

		//set ADC clock
		uint8_t adc_clck[] =
		{
			P0_NADC_REG,
			// NADC power up
			// NADC = 2
			(1 << 7)|(2),
			// MADC power up
			// MADC = 8
			(1 << 7)|(8),
			// AOSR = 128
			128
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// set DAC and ADC Processing block
		uint8_t prb[] =
		{
			P0_DAC_PROCESSING_BLOCK_REG,
			// DAC - PRB_P1
			1,
			// ADC - PRB_R2
			2
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
			// PLL divider P = 1
			// PLL divider R = 2
			(1 << 7)|(8 << 4)|(2),
			// PLL divider J = 36
			9
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
			// NADC power up
			// NADC = 2
			(1 << 7)|(2),
			// MADC power up
			// MADC = 9
			(1 << 7)|(9),
			// AOSR = 64
			0x40
		};
		tlv320aic3204_write_buffer(adc_clck, sizeof(adc_clck));
		
		// // set DAC and ADC Processing block
		// uint8_t prb[] =
		// {
		// 	P0_DAC_PROCESSING_BLOCK_REG,
		// 	// DAC - PRB_P4
		// 	4,
		// 	// ADC - PRB_R4
		// 	4
		// };
		// tlv320aic3204_write_buffer(prb, sizeof(prb));
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
			(0b00 << 6)|(0b11 << 4)|(0b0 << 3)|(0b0 << 2)|(0b1 << 0),
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
			// Audio Interface = RJF
			// Audio Data length = 32
			// BCLK as input
			// WCLK as input
			// DOUT will be high impedance after data has been transferred
			(0b10 << 6)|(0b11 << 4)|(0b0 << 3)|(0b0 << 2)|(0b1 << 0),
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
	void AudioCodecDriver::IAudioInputPGA::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::IAudioInputVolumeControl::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::IAudioOutputPGA::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::IAudioOutputVolumeControl::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::IAudioInput::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}

	/*-----------------------------------------------------------------//
	//
	//-----------------------------------------------------------------*/
	void AudioCodecDriver::IAudioOutput::SetRegisterPage(uint8_t page) 
	{
		AudioDevice.SetRegisterPage(page);
	}
}
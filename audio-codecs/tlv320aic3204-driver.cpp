#include "tlv320aic3204-driver.h"
#include "tlv320aic3204-interface.h"

/*-----------------------------------------------------------------//
// Dependencies
//-----------------------------------------------------------------*/
extern tlv320aic3204::AudioCodecDriver AudioDevice;

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
		AudioDevice.Initialize();
		for(;;)
		{
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
	void AudioCodecDriver::PowerUp()
	{
		// set page 1
		uint8_t buff[] = {PX_PAGE_REG, 1};
		tlv320aic3204_write_buffer(buff, 2);
		// AVDD LDO power up
		buff[0] = P1_LDO_CONTROL_REG;
		buff[1] = 0x09;
		tlv320aic3204_write_buffer(buff, 2);
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

		// printf("AudioCodecDriver::PowerUp. Started\n");
		// uint8_t txdata[] = {12};
		// tlv320aic3204_write_buffer(txdata, 1);
		
		// uint8_t rxdata[4] = {0xaa};
		// tlv320aic3204_read_buffer(rxdata, 4);

		// printf("AudioCodecDriver::PowerUp. 0x%X, 0x%X, 0x%X, 0x%X\n",
		// 	rxdata[0], rxdata[1], rxdata[2], rxdata[3]);

		// printf("AudioCodecDriver::PowerUp. Finished.\n");
	}
}
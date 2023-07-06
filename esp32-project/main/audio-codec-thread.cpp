#include "tlv320aic3204-driver.h"
#include "tlv320aic3204-input-configs.h"
#include "tlv320aic3204-output-configs.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void audio_data_flow_thread(void * args);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
tlv320aic3204::RightMixAmpDifferntial_LO AudioOutputMixerAmpToLO;
tlv320aic3204::RightMixAmpSingleEnded_HPLR AudioOutputMixerAmpToHP;
tlv320aic3204::RightDACDifferntial_LO AudioOutputRDACToLO;
tlv320aic3204::StereoDACSingleEnded_HPLR AudioOutputDACToHP;

tlv320aic3204::RightMixAmpSingleEndedInput_IN3R AudioInputIN3RToMixerAmpLO(AudioOutputMixerAmpToLO); 
tlv320aic3204::RightMixAmpSingleEndedInput_IN3R AudioInputIN3RToMixerAmpHP(AudioOutputMixerAmpToHP); 
tlv320aic3204::RightADCSingleEndedInput_IN3R AudioInputIN3RToRADC;

tlv320aic3204::AudioCodecDriver AudioDevice(&AudioInputIN3RToRADC, &AudioOutputRDACToLO);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void tlv320aic3204_codec_thread(void * args)
{
	printf("--== tlv320aic3204_codec_thread has started ==--\n");
	AudioDevice.Initialize();

	xTaskCreate(audio_data_flow_thread, "audio-data-flow", 1024 * 2, (void *)0, 10, NULL);

	int i = 0;
	for(;;)
	{
		//printf("--== tlv320aic3204_codec_thread running ==-- %d\n", i);
		i++;
		//printf("--== initialize ==--\n");
		//AudioDevice.Initialize();
		vTaskDelay(300);
	}
}
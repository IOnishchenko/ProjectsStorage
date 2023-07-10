#include "tlv320aic3204-driver.h"
#include "tlv320aic3204-input-configs.h"
#include "tlv320aic3204-output-configs.h"

#include "si5351.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configuration.h"

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern void audio_data_flow_thread(void * args);

/*-----------------------------------------------------------------//
// Audio codec class instances
//-----------------------------------------------------------------*/
tlv320aic3204::RightMixAmpDifferntial_LO AudioOutputMixerAmpToLO;
tlv320aic3204::RightMixAmpSingleEnded_HPLR AudioOutputMixerAmpToHP;
tlv320aic3204::RightDACDifferntial_LO AudioOutputRDACToLO;
tlv320aic3204::StereoDACSingleEnded_HPLR AudioOutputDACToHP;

tlv320aic3204::RightMixAmpSingleEndedInput_IN3R AudioInputIN3RToMixerAmpLO(AudioOutputMixerAmpToLO); 
tlv320aic3204::RightMixAmpSingleEndedInput_IN3R AudioInputIN3RToMixerAmpHP(AudioOutputMixerAmpToHP); 
tlv320aic3204::RightADCSingleEndedInput_IN3R AudioInputIN3RToRADC;
tlv320aic3204::StereoADCDifferntialInput_IN1_IN2 AudioInputDiffIN2IN1;

tlv320aic3204::AudioCodecDriver AudioDevice(&AudioInputDiffIN2IN1, &AudioOutputRDACToLO);

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
Si5351 Synthesizer;

/*-----------------------------------------------------------------//
//
//-----------------------------------------------------------------*/
extern "C" void tlv320aic3204_codec_thread(void * args)
{
	printf("--== tlv320aic3204_codec_thread has started ==--\n");

	AudioDevice.Initialize();
	xTaskCreate(audio_data_flow_thread, "audio-data-flow", 1024 * 2, (void *)0, 10, NULL);

	if(Synthesizer.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0))
	{
		// We will output 14.1 MHz on CLK0 and CLK1.
		// A PLLA frequency of 705 MHz was chosen to give an even
		// divisor by 14.1 MHz.
		unsigned long long freq = 13'760'000'00ULL;
		unsigned long long pll_freq = 825'600'000'00ULL;

		// Set CLK0 and CLK1 to use PLLA as the MS source.
		// This is not explicitly necessary in v2 of this library,
		// as these are already the default assignments.
		Synthesizer.set_ms_source(SI5351_CLK0, SI5351_PLLA);
		Synthesizer.set_ms_source(SI5351_CLK1, SI5351_PLLA);

		// Set CLK0 and CLK1 to output 14.1 MHz with a fixed PLL frequency
		Synthesizer.set_freq_manual(freq, pll_freq, SI5351_CLK0);
		Synthesizer.set_freq_manual(freq, pll_freq, SI5351_CLK1);

		// Now we can set CLK1 to have a 90 deg phase shift by entering
		// 50 in the CLK1 phase register, since the ratio of the PLL to
		// the clock frequency is 50.
		Synthesizer.set_phase(SI5351_CLK0, 0);
		Synthesizer.set_phase(SI5351_CLK1, 60);

		// We need to reset the PLL before they will be in phase alignment
		Synthesizer.pll_reset(SI5351_PLLA);

		// Query a status update and wait a bit to let the Si5351 populate the
		// status flags correctly.
		Synthesizer.update_status();
	}

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
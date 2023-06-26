#ifndef TLV320AIC3204_OUTPUT_CONFIGS_H
#define TLV320AIC3204_OUTPUT_CONFIGS_H

#include "tlv320aic3204-driver.h"

namespace tlv320aic3204
{
  /*-----------------------------------------------------------------//
  // Abstract classes
  //-----------------------------------------------------------------*/
  class IStereoHPOutput : public AudioCodecDriver::IAudioOutput
  {
  public:
    const ValueProvider & GetAnalogGain() const override;
		void SetAnalogGain(uint32_t index) override;
		const ValueProvider & GetDititalGain() const override;
		void SetDititalGain(uint32_t index) override;
  }

  class IDifferntialLineOutput : public AudioCodecDriver::IAudioOutput
  {
  public:
    const ValueProvider & GetAnalogGain() const override;
		void SetAnalogGain(uint32_t index) override;
		const ValueProvider & GetDititalGain() const override;
		void SetDititalGain(uint32_t index) override;
  }

  /*-----------------------------------------------------------------//
  // Left DAC Outputs
  //-----------------------------------------------------------------*/
  class RightDACDifferntial_LO : public IDifferntialLineOutput
  {
  public:
    void InitOutput() const override;
		void DeinitOutput() const override;
  };

  class LeftDACSingleEnded_HPLR : public IStereoHPOutput
  {
  public:
    void InitOutput() const override;
		void DeinitOutput() const override;
  };

  class RightMixAmpDifferntial_LO : public IDifferntialLineOutput
  {
  public:
    void InitOutput() const override;
		void DeinitOutput() const override;
  };

  class RightMixAmpSingleEnded_HPLR : public IStereoHPOutput
  {
  public:
    void InitOutput() const override;
		void DeinitOutput() const override;
  };
}

#endif // TLV320AIC3204_OUTPUT_CONFIGS_H
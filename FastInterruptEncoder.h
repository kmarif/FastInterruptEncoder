#ifndef __FASTINTERRUPTENCODER_H__
#define __FASTINTERRUPTENCODER_H__

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include "Arduino.h"

typedef enum {
  SINGLE = 0,
  HALFQUAD = 1,
  FULLQUAD = 2,
} encoder_mode_t;

class Encoder
{
  public:
    Encoder(int pinA, int pinB, int counts_per_rev, encoder_mode_t mode = SINGLE, uint8_t filter = 0);
	bool init();
	void loop();
	int32_t getTicks();
	void resetTicks();	
	int getRPM();
	
	
  private:
	int _pinA;
	int _pinB;
	encoder_mode_t _mode = SINGLE;
	int32_t _ticks = 0;
	int32_t _prevTicks = 0;
	uint8_t _filter = 0;
	
	int counts_per_rev_;
	unsigned long prev_update_time_;
    	long prev_encoder_ticks_;
};

#endif // __FASTINTERRUPTENCODER_H__

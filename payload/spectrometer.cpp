//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

#include "spectrometer.h"

Spectrometer::Spectrometer(int clock, int st, int gain, int video) {
	_clock = clock;
	_st = st;
	_gain = gain;
	_video = video;

	//pinMode(SPEC_EOS, INPUT);
	pinMode(_clock, OUTPUT);
	pinMode(_st, OUTPUT);
	pinMode(_gain, OUTPUT);
	pinMode(_video, INPUT);

	digitalWrite(_clock, HIGH);
	digitalWrite(_st, HIGH);

	//LOW _gain
	digitalWrite(_gain, HIGH);
	//High _gain
	//digitalWrite(_gain, LOW);

	clear();
}

void Spectrometer::clear() {
	digitalWrite(_video, LOW);
	for (int i = 0; i < SPEC_CHANNELS; i++) {
		data[i] = 0;
	}
}

void Spectrometer::readSpectrometer() {
	//int delay_time = 35;      // delay per half clock (in microseconds).  This ultimately conrols the integration time.
	int delay_time = 1;	 // delay per half clock (in microseconds).  This ultimately conrols the integration time.
	int read_time = 35;	 // Amount of time that the analogRead() procedure takes (in microseconds) (different micros will have different times)
	int intTime = 100;
	int accumulateMode = false;

	// Step 1: start leading clock pulses
	for (int i = 0; i < SPEC_CHANNELS; i++) {
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
	}

	// Step 2: Send start pulse to signal start of integration/light collection
	digitalWrite(_clock, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, HIGH);
	digitalWrite(_st, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, HIGH);
	digitalWrite(_st, HIGH);
	delayMicroseconds(delay_time);

	// Step 3: Integration time -- sample for a period of time determined by the intTime parameter
	int blockTime = delay_time * 8;
	long int numIntegrationBlocks = ((long)intTime * (long)1000) / (long)blockTime;
	for (int i = 0; i < numIntegrationBlocks; i++) {
		// Four clocks per pixel
		// First block of 2 clocks -- measurement
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);

		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
	}

	// Step 4: Send start pulse to signal end of integration/light collection
	digitalWrite(_clock, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, HIGH);
	digitalWrite(_st, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, LOW);
	delayMicroseconds(delay_time);
	digitalWrite(_clock, HIGH);
	digitalWrite(_st, HIGH);
	delayMicroseconds(delay_time);

	// Step 5: Read Data 2 (this is the actual read, since the spectrometer has now sampled data)
	for (int i = 0; i < SPEC_CHANNELS; i++) {
		// Four clocks per pixel
		// First block of 2 clocks -- measurement
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, LOW);

		// Analog value is valid on low transition
		if (accumulateMode == false) {
			data[i] = analogRead(_video);
		} else {
			data[i] += analogRead(_video);
		}
		if (delay_time > read_time) delayMicroseconds(delay_time - read_time);	// Read takes about 135uSec

		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);

		// Second block of 2 clocks -- idle
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
	}

	// Step 6: trailing clock pulses
	for (int i = 0; i < SPEC_CHANNELS; i++) {
		digitalWrite(_clock, LOW);
		delayMicroseconds(delay_time);
		digitalWrite(_clock, HIGH);
		delayMicroseconds(delay_time);
	}
}
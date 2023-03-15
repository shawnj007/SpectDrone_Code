//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <Arduino.h>

#define SPEC_CHANNELS 256

using namespace std;

class Spectrometer {
  private:
	int _clock = -1;
	int _st = -1;
	int _gain = -1;
	int _video = -1;

  public:
	uint16_t data[SPEC_CHANNELS] = { 0 };

	Spectrometer(int clock, int st, int gain, int video);
	void clear();
	void readSpectrometer();
};
#endif
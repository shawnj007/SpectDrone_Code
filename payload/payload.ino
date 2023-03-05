//SpectDronePayload
//Developer:ShawnL.Jaker
//NationalRenewableEnergyLaboratory
//SolarRadiationResearchLaboratory

#include "pin_assignments.h"

#include <SoftwareSerial.h>
SoftwareSerial* radio;

int setup_radio(int rx, int tx) {
	// Setup Radio pins
	// Returns 0 on sucess, 1 on failure.
	radio = new SoftwareSerial(rx, tx);
	if (radio != NULL) return 0; else return 1;
}

int setup_gps(int rx, int tx) {
	// Setup Global Positioning System pins
	// Returns 0 on sucess, 1 on failure.

	if (gps != NULL) return 0; else return 1;
}

int setup_camera(int rx, int tx) {
	// Setup Camera pins
	// Returns 0 on sucess, 1 on failure.

	return 1;
}

int setup_imu(int sda, int scl) {
	// Setup Camera pins
	// Returns 0 on sucess, 1 on failure.

	return 1;
}

int setup_thp(int sda, int scl) {
	// Setup Temperature, Humidity, Pressure Sensor pins
	// Returns 0 on sucess, 1 on failure.

	return 1;
}

int setup_infrared(int sda, int scl) {
	// Setup Infrared Thermal Sensor pins
	// Returns 0 on sucess, 1 on failure.

	return 1;
}

int setup_spect(int clock, int st, int gain, int video) {
	// Setup Spectroradiometer pins
	// Returns 0 on sucess, 1 on failure.

	return 1;
}

void fail_on(char* failed) {
	if (SERIAL) {
		Serial.print("Failed on ");
		Serial.print(failed);
	}
	while (true) {};
}

void setup() {
	// Set up RADIO
	if (setup_radio(RADIO_RX, RADIO_TX) != 0) fail_on("RADIO");

	// Set up GPS
	if (setup_gps(GPS_RX, GPS_TX) != 0) fail_on("GPS");

	// Set up CAMERA
	if (setup_camera(CAM_RX, CAM_TX) != 0) fail_on("CAMERA");

	// Set up ORIENTATION
	if (setup_imu(IMU_SDA, IMU_SCL) != 0) fail_on("ORIENTATION");

	// Set up TEMPERATURE, HUMIDITY, PRESSURE SENSOR
	if (setup_thp(THP_SDA, THP_SCL) != 0) fail_on("TEMPERATURE, HUMIDITY, PRESSURE SENSOR");

	// Set up IR
	if (setup_infrared(IR_SDA, IR_SCL) != 0) fail_on("INFRARED");

	// Set up Spectroradiometer 1
	if (setup_spect(SPECT1_CLK, SPECT1_ST, SPECT1_GAIN, SPECT1_VIDEO) != 0) fail_on("SPECTORADIOMETER 1");

	// Set up Spectroradiometer 2
	if (setup_spect(SPECT2_CLK, SPECT2_ST, SPECT2_GAIN, SPECT2_VIDEO) != 0) fail_on("SPECTORADIOMETER 2");
}

void loop() {
	// put your main code here, to run repeatedly:
}
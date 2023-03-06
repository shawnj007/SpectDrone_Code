//SpectDronePayload
//Developer:ShawnL.Jaker
//NationalRenewableEnergyLaboratory
//SolarRadiationResearchLaboratory

#include "pin_assignments.h"

#include <SoftwareSerial.h>
SoftwareSerial* radio = NULL;
SoftwareSerial* gps_ss = NULL;
SoftwareSerial* camera = NULL;

#include <TinyGPS++.h>
TinyGPSPlus* gps = NULL;

#include <Adafruit_BNO055.h>
Adafruit_BNO055* orien = NULL;

#include <Adafruit_BME280.h>
Adafruit_BME280* thp = NULL;

#include <Adafruit_MLX90614.h>
Adafruit_MLX90614* ir = NULL;

int setup_radio(int rx, int tx) {
	// Setup Radio pins
	// Returns 0 on sucess, 1 on failure.
	radio = new SoftwareSerial(rx, tx);
	if (radio == NULL) return 1;
	else return 0;
}

int setup_gps(int rx, int tx) {
	// Setup Global Positioning System pins
	// Returns 0 on sucess, 1 on failure.
	gps_ss = new SoftwareSerial(rx, tx);
	gps = new TinyGPSPlus();
	if (gps_ss == NULL || gps == NULL) return 1;
	else return 0;
}

int setup_camera(int rx, int tx) {
	// Setup Camera pins
	// Returns 0 on sucess, 1 on failure.
	camera = new SoftwareSerial(rx, tx);
	if (camera == NULL) return 1;
	else return 0;
}

int setup_imu(int sda, int scl) {
	// Setup Orientation pins
	// Returns 0 on sucess, 1 on failure.
	orien = new Adafruit_BNO055(55);
	if (orien == NULL || !orien->begin()) return 1;
	else return 0;
}

int setup_thp(int sda, int scl) {
	// Setup Temperature, Humidity, Pressure Sensor pins
	// Returns 0 on sucess, 1 on failure.
	thp = new Adafruit_BME280();
	if (thp == NULL || !thp->begin()) return 1;
	else return 0;
	return 1;
}

int setup_infrared(int sda, int scl) {
	// Setup Infrared Thermal Sensor pins
	// Returns 0 on sucess, 1 on failure.
	ir = new Adafruit_MLX90614();
	if (ir == NULL || !ir->begin()) return 1;
	return 0;
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
	if (setup_radio(RADIO_RX, RADIO_TX) != 0) fail_on("RADIO");
	if (setup_gps(GPS_RX, GPS_TX) != 0) fail_on("GPS");
	if (setup_camera(CAM_RX, CAM_TX) != 0) fail_on("CAMERA");
	if (setup_imu(IMU_SDA, IMU_SCL) != 0) fail_on("ORIENTATION");
	if (setup_thp(THP_SDA, THP_SCL) != 0) fail_on("TEMPERATURE, HUMIDITY, PRESSURE SENSOR");
	if (setup_infrared(IR_SDA, IR_SCL) != 0) fail_on("INFRARED");
	if (setup_spect(SPECT1_CLK, SPECT1_ST, SPECT1_GAIN, SPECT1_VIDEO) != 0) fail_on("SPECTORADIOMETER 1");
	if (setup_spect(SPECT2_CLK, SPECT2_ST, SPECT2_GAIN, SPECT2_VIDEO) != 0) fail_on("SPECTORADIOMETER 2");
}

void read_commands() {
	// Read commands from base station
}

void exec_commands() {
	// Execute commands from base station
}

void read_telemetry() {
	// Read sensor data and telemetry
}

void send_telemetry() {
	// Send sensor data and telemetry
}

void loop() {
	// put your main code here, to run repeatedly:
	read_commands();
	exec_commands();
	read_telemetry();
	send_telemetry();
}
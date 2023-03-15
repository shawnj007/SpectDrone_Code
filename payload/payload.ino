//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

#define PAYLOAD_SERIAL (0)

#include "pin_assignments.h"

#include <SoftwareSerial.h>
SoftwareSerial* radio = NULL;

#include <Adafruit_VC0706.h>
SoftwareSerial* camera_ss = NULL;
Adafruit_VC0706* camera = NULL;
static const long CAMERA_BAUD = 115200;
static const long IMAGE_SIZE = long(640 * 480);

#include <TinyGPS++.h>
SoftwareSerial* gps_ss = NULL;
TinyGPSPlus* gps = NULL;
static const long GPS_BAUD = 4800;

#include <Adafruit_BNO055.h>
Adafruit_BNO055* orien = NULL;

#include <Adafruit_BME280.h>
Adafruit_BME280* thp = NULL;

#include <Adafruit_MLX90614.h>
Adafruit_MLX90614* ir = NULL;

#include "spectrometer.h"
Spectrometer* spec1 = NULL;
Spectrometer* spec2 = NULL;

enum command_type { GET,
					SET,
					RECORD };

enum device_type { ALL,
				   GPS,
				   CAMERA,
				   IMU,
				   IR,
				   THP,
				   SPEC };

typedef struct command_struct {
	command_type command = NULL;
	device_type device = NULL;
	char param[8] = { 0 };
	command_struct* next = NULL;
} Command;

Command* root_command = NULL;

typedef struct telemetry_struct {
	device_type device = NULL;
	char param[8] = { 0 };
	void* output = NULL;
	telemetry_struct* next = NULL;
} Telemetry;

Telemetry* root_telemetry = NULL;
Telemetry* leaf_telemetry = NULL;

int setup_radio(int rx, int tx) {
	// Setup Radio pins
	// Returns 0 on success, 1 on failure.

	radio = new SoftwareSerial(rx, tx);
	if (radio == NULL) return 1;
	else return 0;
}

int setup_gps(int rx, int tx) {
	// Setup Global Positioning System pins
	// Returns 0 on success, 1 on failure.

	gps_ss = new SoftwareSerial(rx, tx);
	if (gps_ss == NULL) return 1;
	else gps_ss->begin(GPS_BAUD);

	gps = new TinyGPSPlus();
	if (gps == NULL) return 1;

	return 0;
}

int setup_camera(int rx, int tx) {
	// Setup Camera pins
	// Returns 0 on success, 1 on failure.

	camera_ss = new SoftwareSerial(rx, tx);
	if (camera_ss == NULL) return 1;
	else camera_ss->begin(CAMERA_BAUD);

	camera = new Adafruit_VC0706(camera_ss);
	if (camera == NULL) return 1;
	else camera->begin(CAMERA_BAUD);

	return 0;
}

int setup_imu(int sda, int scl) {
	// Setup Orientation Sensor pins
	// Returns 0 on success, 1 on failure.

	orien = new Adafruit_BNO055(55);
	if (orien == NULL || !orien->begin()) return 1;
	else return 0;
}

int setup_thp(int sda, int scl) {
	// Setup Temperature, Humidity, Pressure Sensor pins
	// Returns 0 on success, 1 on failure.

	thp = new Adafruit_BME280();
	if (thp == NULL || !thp->begin()) return 1;
	else return 0;
}

int setup_infrared(int sda, int scl) {
	// Setup Infrared Thermal Sensor pins
	// Returns 0 on success, 1 on failure.

	ir = new Adafruit_MLX90614();
	if (ir == NULL || !ir->begin()) return 1;
	return 0;
}

int setup_spect(Spectrometer* spec, int clock, int st, int gain, int video) {
	// Setup Spectroradiometer pins
	// Returns 0 on success, 1 on failure.

	spec = new Spectrometer(clock, st, gain, video);
	if (spec == NULL) return 1;
	return 0;
}

void fail_on(const __FlashStringHelper* failed) {
	if (PAYLOAD_SERIAL) {
		Serial.print(F("Failed on "));
		Serial.print(failed);
	}
	while (true) {};
}

void setup() {
	if (PAYLOAD_SERIAL) Serial.begin(9600);
	if (setup_radio(RADIO_RX, RADIO_TX) != 0) fail_on(F("RADIO"));
	if (setup_gps(GPS_RX, GPS_TX) != 0) fail_on(F("GPS"));
	if (setup_camera(CAM_RX, CAM_TX) != 0) fail_on(F("CAMERA"));
	if (setup_imu(IMU_SDA, IMU_SCL) != 0) fail_on(F("ORIENTATION"));
	if (setup_thp(THP_SDA, THP_SCL) != 0) fail_on(F("TEMPERATURE, HUMIDITY, PRESSURE SENSOR"));
	if (setup_infrared(IR_SDA, IR_SCL) != 0) fail_on(F("INFRARED"));
	if (setup_spect(spec1, SPECT1_CLK, SPECT1_ST, SPECT1_GAIN, SPECT1_VIDEO) != 0) fail_on(F("SPECTORADIOMETER 1"));
	if (setup_spect(spec2, SPECT2_CLK, SPECT2_ST, SPECT2_GAIN, SPECT2_VIDEO) != 0) fail_on(F("SPECTORADIOMETER 2"));
}

Command* read_commands() {
	// Read commands from base station
	// FIXME

	// For now, make a fake command
	root_command = new Command;
	root_command->command = GET;
	root_command->device = ALL;
	root_command->next = NULL;
	return root_command;
}

Telemetry* read_gps() {
	// Check status of GPS
	// If fix is valid, report position, altitude, and movement
	Telemetry* t = new Telemetry;
	t->device = GPS;
	if (gps->location.isValid()) {
		t->output = (char*)malloc(53 * sizeof(char));
		// "-lat.lattt -lon.lonnn elev.meter yyyy mm dd hh mm ss"
		// FIXME

	} else {
		t->output = (char*)malloc(8 * sizeof(char));
		strcpy((char*)t->output, "INVALID");
	}
	return t;
}

Telemetry* read_camera() {
	// Read Camera image
	Telemetry* t = new Telemetry;
	t->device = CAMERA;
	//t->output = (char)malloc(IMAGE_SIZE * sizeof(uint8_t));


	// FIXME
	return t;
}

Telemetry* read_imu() {
	Telemetry* t = new Telemetry;
	t->device = IMU;
	// FIXME
	return t;
}

Telemetry* read_ir() {
	Telemetry* t = new Telemetry;
	t->device = IR;
	// FIXME
	return t;
}

Telemetry* read_thp() {
	Telemetry* t = new Telemetry;
	t->device = THP;
	// FIXME
	return t;
}

Telemetry* read_spec(char* param) {
	Telemetry* t = new Telemetry;
	t->device = SPEC;
	// FIXME
	return t;
}

Telemetry* get(device_type d, char* param) {
	Telemetry* t = NULL;
	switch (d) {
		case ALL:  // Ignore param field
			{
				Telemetry* t_gps = get(GPS, NULL);
				Telemetry* t_cam = get(CAMERA, NULL);
				Telemetry* t_imu = get(IMU, NULL);
				Telemetry* t_irt = get(IR, NULL);
				Telemetry* t_thp = get(THP, NULL);
				char param[2] = { 0 };
				strcpy(param, "1");
				Telemetry* t_sp1 = get(SPEC, param);
				strcpy(param, "2");
				Telemetry* t_sp2 = get(SPEC, param);
				t_gps->next = t_cam;
				t_cam->next = t_imu;
				t_imu->next = t_irt;
				t_irt->next = t_thp;
				t_thp->next = t_sp1;
				t_sp1->next = t_sp2;
				t_sp2->next = NULL;
				root_telemetry = t_gps;
				leaf_telemetry = t_sp2;
				return root_telemetry;
				break;
			}
		case GPS:
			{
				t = read_gps();
				break;
			}
		case CAMERA:
			{
				t = read_camera();
				break;
			}
		case IMU:
			{
				t = read_imu();
				break;
			}
		case IR:
			{
				t = read_ir();
				break;
			}
		case THP:
			{
				t = read_thp();
				break;
			}
		case SPEC:
			{
				t = read_spec(param);
				break;
			}
	}
	return t;
}

void exec_commands(Command* command) {
	// Execute commands from base station

	Command* c = command;
	while (c != NULL) {

		switch (c->command) {
			case GET:
				{
					Telemetry* t = get(c->device, c->param);
					if (root_telemetry == NULL) {
						root_telemetry = t;
						leaf_telemetry = root_telemetry;
					} else {
						leaf_telemetry->next = t;
						leaf_telemetry = leaf_telemetry->next;
					}
					break;
				}
			case SET:
				{
					//set(c->device, c->param);
					break;
				}
			case RECORD:
				{
					//record(c->device, c->param);
					break;
				}
		}
	}

	Command* next = c->next;
	delete c;
	c = next;
}

Telemetry* read_telemetry() {
	// Read sensor data and telemetry
	return NULL;
}

void send_telemetry(Telemetry* telemetry) {
	// Send sensor data and telemetry
}

void loop() {
	// put your main code here, to run repeatedly:
	exec_commands(read_commands());
}
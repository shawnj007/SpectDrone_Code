//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

/*
 *	PIN ASSIGNMENTS
 */

#ifdef PAYLOAD_IS_2560EMBED
 #include "pin_headers_2560embed.h"
#endif

#ifdef PAYLOAD_IS_TEENSY4_0
 #include "pin_headers_teensy4_0.h"
#endif

#ifdef PAYLOAD_IS_TEENSY4_1
 #include "pin_headers_teensy4_1.h"
#endif
/*	--Radio (APC220)
 *		RX			JAPC-RX			D49
 *		TX			JAPC-TX			D48
 */

const int RADIO_RX = JAPC_RX;
const int RADIO_TX = JAPC_TX;

/*	--GPS
 *		RX			JGPS-GPS_RX		D16
 *		TX			JGPS-GPS_TX		D17
 */

//const int GPS_RX = JGPS_TX2;
//const int GPS_TX = JGPS_RX2;

/*	--Camera 1
 *		RX			JAUX-TX1		D14
 *		TX			JAUX-RX1		D15
 */

//const int CAM1_RX = JAUX_TX1;
//const int CAM1_TX = JAUX_RX1;

/*	--Camera 2
 *		RX			JAUX-TX2		D18
 *		TX			JAUX-RX2		D19
 */

//const int CAM2_RX = JAUX_TX2;
//const int CAM2_TX = JAUX_RX2;

/*	--Orientation (Inertial Movement Unit)
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 */

const int IMU_SDA = JAUX_SDA;
const int IMU_SCL = JAUX_SCL;

/*	--TempHumPress
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 */

const int THP_SDA = JAUX_SDA;
const int THP_SCL = JAUX_SCL;

/*	--Infrared
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 */

const int IR_SDA = JAUX_SDA;
const int IR_SCL = JAUX_SCL;

/*	--Spectroradiometer 1
 *		CLK1		JAUX-PIN11		D13
 *		ST			JAUX-PIN9		D14
 *		GAIN		JADC-PIN3		D38
 *		VIDEO		JADC-PIN1		A12
 */

const int SPECT1_CLK = JAUX_PIN11;
const int SPECT1_ST = JAUX_PIN9;
const int SPECT1_GAIN = JAUX_PIN3;
const int SPECT1_VIDEO = JAUX_PIN1;

/*	--Spectroradiometer 2
 *		CLK1		JAUX-PIN10		D12
 *		ST			JAUX-PIN9		D14
 *		GAIN		JADC-PIN3		D38
 *		VIDEO		JADC-PIN2		A13
 */

const int SPECT2_CLK = JAUX_PIN10;
const int SPECT2_ST = JAUX_PIN9;
const int SPECT2_GAIN = JAUX_PIN3;
const int SPECT2_VIDEO = JAUX_PIN1;
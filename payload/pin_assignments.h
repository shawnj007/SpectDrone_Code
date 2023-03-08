//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

/*
 *	PIN ASSIGNMENTS
 */
 
#include "pin_headers.h"

/*	--Radio (APC220)
 *		RX			JAPC-RX			D49
 *		TX			JAPC-TX			D48
 */

const int RADIO_RX = JAPC_RX;
const int RADIO_TX = JAPC_TX;

/*	--GPS
 *		RX			JGPS-GPS_RX		D17
 *		TX			JGPS-GPS_TX		D19
 */

const int GPS_RX = JGPS_RX;
const int GPS_TX = JGPS_TX;

/*	--Camera
 *		RX			JAUX-SS_AUX		D22
 *		TX			JAUX-XCL		D16
 */

const int CAM_RX = JAUX_SS_AUX;
const int CAM_TX = JAUX_XCL;

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

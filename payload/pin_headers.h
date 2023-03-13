//SpectDrone Payload
//Developer: Shawn L. Jaker
//National Renewable Energy Laboratory
//Solar Radiation Research Laboratory

/*
 *	PIN HEADER ASSIGNMENTS
 */

/*	--Radio(APC220)
 *		RX			JAPC-RX			D49
 *		TX			JAPC-TX			D48
 */

const int JAPC_RX = 49;
const int JAPC_TX = 48;

/*	--GPS
 *		RX			JGPS-GPS_RX		D17
 *		TX			JGPS-GPS_TX		D19
 */

const int JGPS_RX = 17;
const int JGPS_TX = 19;

/*	--Camera
 *		RX			JAUX-SS_AUX		D22
 *		TX			JAUX-XCL		D16
 */

const int JAUX_SS_AUX = 22;
const int JAUX_XCL = 16;

/*	I2C components
 *
 *	--Orientation (Inertial Movement Unit)
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 *	
 *	--Infrared
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 *
 *	--TempHumPress
 *		SDA			JAUX-SDA		D20
 *		SCL			JAUX-SCL		D21
 *
 */

const int JAUX_SDA = 20;
const int JAUX_SCL = 21;

/*	--Spectroradiometer Common
 *		ST			JAUX-PIN9		D14
 *		GAIN		JADC-PIN3		D38
 */

const int JAUX_PIN9 = 14;
const int JAUX_PIN3 = 38;

/*	--Spectroradiometer 1
 *		CLK1		JAUX-PIN11		D13
 *		VIDEO		JADC-PIN1		A12
 */

const int JAUX_PIN11 = 13;
const int JAUX_PIN1 = A12;

/*	--Spectroradiometer 2
 *		CLK1		JAUX-PIN10		D12
 *		VIDEO		JADC-PIN2		A13
 */

const int JAUX_PIN10 = 12;
const int JAUX_PIN2 = A13;
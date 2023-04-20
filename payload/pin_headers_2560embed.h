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
 *		TX			JGPS-GPS_TX		D16
 *		RX			JGPS-GPS_RX		D17
 */

//const int JGPS_TX = 16;
//const int JGPS_RX = 17;

/*	--Camera 1
 *		RX			JAUX-TX1		D18
 *		TX			JAUX-RX1		D19
 */

//const int JAUX_TX1 = 18;
//const int JAUX_RX1 = 19;

/*	--Camera 2
 *		RX			JAUX-TX3		D14
 *		TX			JAUX-RX3		D15
 */

//const int JAUX_TX2 = 14;
//const int JAUX_RX2 = 15;

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
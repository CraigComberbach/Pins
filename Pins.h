#ifndef PINS_H
#define	PINS_H
/*
Instructions for adding to a new project:
*/

/***********Add to config file header************/
/*
enum PIN_DEFINITIONS
{
	PIN_RA0,	//RA0
	PIN_RA1,	//RA1
	PIN_RA2,	//RA2
	PIN_RA3,	//RA3
	PIN_RA4,	//RA4
	PIN_RA5,	//RA5
	PIN_RA6,	//RA6
	PIN_RA7,	//RA7
	PIN_RA8,	//RA8
	PIN_RA9,	//RA9
	PIN_RA10,	//RA10
	PIN_RA11,	//RA11
	PIN_RA12,	//RA12
	PIN_RA13,	//RA13
	PIN_RA14,	//RA14
	PIN_RA15,	//RA15
//	ETC...
	NUMBER_OF_PINS
};

//Pins Library
#define PINS_MAJOR	2
#define PINS_MINOR	0
#define PINS_PATCH	0
*/

/***************Add to config file***************/
/*
#ifndef PINS_LIBRARY
	#error "You need to include the Pins library for this code to compile"
#endif
 */

/************* Semantic Versioning***************/
#define PINS_LIBRARY

/*************   Magic  Numbers   ***************/
#define LOW			0
#define HIGH		1
#define OUTPUT		0
#define INPUT		1
#define PUSH_PULL	0
#define OPEN_DRAIN	1

/*************    Enumeration     ***************/
enum
{
	Rx0 = 0x0001,
	Rx1 = 0x0002,
	Rx2 = 0x0004,
	Rx3 = 0x0008,
	Rx4 = 0x0010,
	Rx5 = 0x0020,
	Rx6 = 0x0040,
	Rx7 = 0x0080,
	Rx8 = 0x0100,
	Rx9 = 0x0200,
	Rx10 = 0x0400,
	Rx11 = 0x0800,
	Rx12 = 0x1000,
	Rx13 = 0x2000,
	Rx14 = 0x4000,
	Rx15 = 0x8000
};

/*************Structure Definitions**************/
//Pin structure definition
int
{
	int mask;
	volatile unsigned int *TRISregister;
	volatile unsigned int *ODCregister;
	volatile unsigned int *LATregister;
	volatile unsigned int *PORTregister;
};

/***********State Machine Definitions************/
/*************Function  Prototypes***************/

/**
 * Creates a link between the Pins unique designator and the TRIS/LAT/PORT/ODC/pin registers
 * @param pinID The unique ID that this pin is referred to as
 * @param mask A Rxn number between 0 and 15 that indicates the pin number
 * @param TRISregister Address of Tristate register
 * @param ODCregister Address of Open Drain Control register
 * @param LATregister Address of Latch register
 * @param PORTregister Address of Port register
 */
void Pin_Definition(int pinID, int mask, volatile unsigned int *TRISregister, volatile unsigned int *ODCregister, volatile unsigned int *LATregister, volatile unsigned int *PORTregister);

/**
 * Initializes a pin
 * @param pinID The unique ID that this pin is referred to as
 * @param latch The desired state the LAT should start in (1 = High, 0 = Low)
 * @param odc The desired state the ODC should be in (1 = Open-Drain, 0 = Push-Pull)
 * @param tris The desired state the TRIS should start in (1 = Input, 0 = Output)
 */
void Pin_Initialize(int pinID, int latch, int odc, int tris);

/**
 * Sets the pin low (LAT register)
 * @param pinID The unique ID that this pin is referred to as
 */
void Pin_Low(int pinID);

/**
 * Sets the pin high (LAT register)
 * @param pinID The unique ID that this pin is referred to as
 */
void Pin_High(int pinID);

/**
 * Toggles the pins (LAT register)
 * @param pinID The unique ID that this pin is referred to as
 */
void Pin_Toggle(int pinID);

/**
 * Allows programatically setting of a pin (LAT register)
 * @param pinID The unique ID that this pin is referred to as
 * @param newState (1 = High, 0 = Low)
 */
void Pin_Write(int pinID, int newState);

/**
 * Sets the ODC register
 * @param pinID The unique ID that this pin is referred to as
 * @param newState (1 = Open-Drain, 0 = Push-Pull)
 */
void Pin_Set_ODC(int pinID, int newState);

/**
 * Sets the TRIS register
 * @param pinID The unique ID that this pin is referred to as
 * @param newState (1 = Input, 0 = Output)
 */
void Pin_Set_TRIS(int pinID, int newState);

/**
 * Reads the current pin (PORT register)
 * @param pinID The unique ID that this pin is referred to as
 * @return (1 = High, 0 = Low)
 */
int Pin_Read(int pinID);

/**
 * Reads the current ODC register
 * @param pinID The unique ID that this pin is referred to as
 * @return the current ODC value (1 = Open-Drain, 0 = Push-Pull)
 */
int Pin_Get_ODC(int pinID);

/**
 * Reads the current TRIS register
 * @param pinID The unique ID that this pin is referred to as
 * @return (1 = Input, 0 = Output)
 */
int Pin_Get_TRIS(int pinID);

#endif	/* PINS_H */

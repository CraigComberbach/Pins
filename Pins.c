/**************************************************************************************************
Authours:				Craig Comberbach
Target Hardware:		PIC24F
Chip resources used:	Gives direct access to every single pin
Code assumptions:
Purpose:				Read the Thermistor inputs

Version History:
v0.0.1	2013-07-21  Craig Comberbach
	Compiler: XC16 v1.11	IDE: MPLABx 1.70	Tool: ICD3	Computer: Intel Core2 Quad CPU 2.40 GHz, 5 GB RAM, Windows 7 64 bit Home Premium SP1
	Retooled everything to use existing macro names for each pin/function
	Processor names now either enable or disable pins
		-Disabled pins return a 0 indicating it was an invalid choice
		-Enabled pins are have the Latch then the TriState registers set (Specifically in that order) before returning a 1 indicating the pin was valid
	Added in the Open Drain register to initialization as well
v0.0.0	2013-07-20  Craig Comberbach
	Compiler: XC16 v1.11	IDE: MPLABx 1.70	Tool: ICD3	Computer: Intel Core2 Quad CPU 2.40 GHz, 5 GB RAM, Windows 7 64 bit Home Premium SP1
	First version
**************************************************************************************************/
/*************    Header Files    ***************/
#include "Config.h"
#include "Pins.h"

/************* Semantic Versioning***************/
#ifndef PINS_LIBRARY
	#error "You need to include the Pins library for this code to compile"
#elif PINS_MAJOR != 0
	#warning "Pins.c has had a change that loses some previously supported functionality"
#elif PINS_MINOR != 0
	#warning "Pins.c has new features that this code may benefit from"
#elif PINS_PATCH != 1
	#warning "Pins.c has had a bug fix, you should check to see that we weren't relying on a bug for functionality"
#endif

/************Arbitrary Functionality*************/
/*************   Magic  Numbers   ***************/
/*************    Enumeration     ***************/
enum
{
	PortA,
	PortB,
};

enum
{
	Rx0,
	Rx1,
	Rx2,
	Rx3,
	Rx4,
	Rx5,
	Rx6,
	Rx7,
	Rx8,
	Rx9,
	Rx10,
	Rx11,
	Rx12,
	Rx13,
	Rx14,
	Rx15
};

/***********State Machine Definitions************/
/*************  Global Variables  ***************/
/*************Function  Prototypes***************/
/************* Device Definitions ***************/
/************* Module Definitions ***************/
/************* Other  Definitions ***************/

int Initialize_Pin(enum PIN_NAMES pinName, int latch, int odc, int tris)
{
	int port, pin;

	//Determine pin and port
	port = pinName / 16;
	pin = pinName % 16;

	//Range checking
	if((latch != LOW) && (latch != HIGH))
		return 0;
	if((tris != OUTPUT) && (tris != INPUT))
		return 0;
	if((odc != PUSH_PULL) && (odc != OPEN_DRAIN))
		return 0;

	//Now that we are through the gauntlet, it's time for assignment
	switch(port)
	{
		case PortA:
			switch(pin)
			{
				case Rx0:
					#if defined __PIC24F08KL200__
						LATAbits.LATA0 = latch;
						ODCAbits.ODA0 = odc;
						TRISAbits.TRISA0 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx1:
					#if defined __PIC24F08KL200__
						LATAbits.LATA1 = latch;
						ODCAbits.ODA1 = odc;
						TRISAbits.TRISA1 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx2:
					#if defined __PIC24F08KL200__
						LATAbits.LATA2 = latch;
						ODCAbits.ODA2 = odc;
						TRISAbits.TRISA2 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx3:
					#if defined __PIC24F08KL200__
						LATAbits.LATA3 = latch;
						ODCAbits.ODA3 = odc;
						TRISAbits.TRISA3 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx4:
					#if defined __PIC24F08KL200__
						LATAbits.LATA4 = latch;
						ODCAbits.ODA4 = odc;
						TRISAbits.TRISA4 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx5:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA5 = latch;
						ODCAbits.ODA5 = odc;
						TRISAbits.TRISA5 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx6:
					#if defined __PIC24F08KL200__
						LATAbits.LATA6 = latch;
						ODCAbits.ODA6 = odc;
						TRISAbits.TRISA6 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx7:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA7 = latch;
						ODCAbits.ODA7 = odc;
						TRISAbits.TRISA7 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx8:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA8 = latch;
						ODCAbits.ODA8 = odc;
						TRISAbits.TRISA8 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx9:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA9 = latch;
						ODCAbits.ODA9 = odc;
						TRISAbits.TRISA9 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx10:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA10 = latch;
						ODCAbits.ODA10 = odc;
						TRISAbits.TRISA10 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx11:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA11 = latch;
						ODCAbits.ODA11 = odc;
						TRISAbits.TRISA11 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx12:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA12 = latch;
						ODCAbits.ODA12 = odc;
						TRISAbits.TRISA12 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx13:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA13 = latch;
						ODCAbits.ODA13 = odc;
						TRISAbits.TRISA13 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx14:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA14 = latch;
						ODCAbits.ODA14 = odc;
						TRISAbits.TRISA14 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx15:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATAbits.LATA15 = latch;
						ODCAbits.ODA15 = odc;
						TRISAbits.TRISA15 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				default:
					return 0;//Only a math error can get to here
			}
			return 0;//How did I get here?
		case PortB:
			switch(pin)
			{
				case Rx0:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB0 = latch;
						ODCBbits.ODB0 = odc;
						TRISBbits.TRISB0 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx1:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB1 = latch;
						ODCBbits.ODB1 = odc;
						TRISBbits.TRISB1 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx2:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB2 = latch;
						ODCBbits.ODB2 = odc;
						TRISBbits.TRISB2 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx3:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB3 = latch;
						ODCBbits.ODB3 = odc;
						TRISBbits.TRISB3 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx4:
					#if defined __PIC24F08KL200__
						LATBbits.LATB4 = latch;
						ODCBbits.ODB4 = odc;
						TRISBbits.TRISB4 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx5:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB5 = latch;
						ODCBbits.ODB5 = odc;
						TRISBbits.TRISB5 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx6:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB6 = latch;
						ODCBbits.ODB6 = odc;
						TRISBbits.TRISB6 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx7:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB7 = latch;
						ODCBbits.ODB7 = odc;
						TRISBbits.TRISB7 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx8:
					#if defined __PIC24F08KL200__
						LATBbits.LATB8 = latch;
						ODCBbits.ODB8 = odc;
						TRISBbits.TRISB8 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx9:
					#if defined __PIC24F08KL200__
						LATBbits.LATB9 = latch;
						ODCBbits.ODB9 = odc;
						TRISBbits.TRISB9 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx10:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB10 = latch;
						ODCBbits.ODB10 = odc;
						TRISBbits.TRISB10 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx11:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB11 = latch;
						ODCBbits.ODB11 = odc;
						TRISBbits.TRISB11 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx12:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB12 = latch;
						ODCBbits.ODB12 = odc;
						TRISBbits.TRISB12 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx13:
					#if defined PLACE_MICROCHIP_PART_NAME_HERE
						LATBbits.LATB13 = latch;
						ODCBbits.ODB13 = odc;
						TRISBbits.TRISB13 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx14:
					#if defined __PIC24F08KL200__
						LATBbits.LATB14 = latch;
						ODCBbits.ODB14 = odc;
						TRISBbits.TRISB14 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				case Rx15:
					#if defined __PIC24F08KL200__
						LATBbits.LATB15 = latch;
						ODCBbits.ODB15 = odc;
						TRISBbits.TRISB15 = tris;
						return 1;//This pin exists and the change was successful
					#else
						return 0;//This pin does not exist
					#endif
				default:
					return 0;//Only a math error can get to here
			}
			return 0;//How did I get here?
		default:
			return 0;//Port does not exist
	}

	//We should never get here!
	return 0;//Failure
}

int Write_Pin(enum PIN_NAMES pinName, int newLatch)
{

}

int Read_Pin(enum PIN_NAMES pinName)
{

}

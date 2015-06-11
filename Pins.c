/**************************************************************************************************
Authours:				Craig Comberbach
Target Hardware:		PIC24F
Chip resources used:	Gives direct access to every single pin
Code assumptions:
Purpose:				Read the Thermistor inputs

Version History:
	Retooled entirely. It now uses unique designators instead of passing structures around
	This simplified initialization, as well as passing pins as an argument to functions (Critical for use with the CTMU & A2D libraries)
v1.0.0	2014-02-05	Craig Comberbach	Compiler: C30 v3.31	Optimization: 0	IDE: MPLABx 1.95	Tool: IDC3	Computer: Intel Core i5-2540 CPU 2.6 GHz, 3.95 GB RAM, Windows 7 64 bit Professional SP1
	Added Pin Low, High, and Toggle
	Tested, this is the official release
v0.1.0	2014-02-01	Craig Comberbach	Compiler: C30 v3.31	Optimization: 0	IDE: MPLABx 1.95	Tool: IDC3	Computer: Intel Core i5-2540 CPU 2.6 GHz, 3.95 GB RAM, Windows 7 64 bit Professional SP1
	Rewrote everything from scratch, removing the chip specific case staements and replacing with generic functions that should work on any chip
v0.0.1	2013-07-21  Craig Comberbach	Compiler: XC16 v1.11	IDE: MPLABx 1.70	Tool: ICD3	Computer: Intel Core2 Quad CPU 2.40 GHz, 5 GB RAM, Windows 7 64 bit Home Premium SP1
	Retooled everything to use existing macro names for each pin/function
	Processor names now either enable or disable pins
		-Disabled pins return a 0 indicating it was an invalid choice
		-Enabled pins are have the Latch then the TriState registers set (Specifically in that order) before returning a 1 indicating the pin was valid
	Added in the Open Drain register to initialization as well
v0.0.0	2013-07-20  Craig Comberbach	Compiler: XC16 v1.11	IDE: MPLABx 1.70	Tool: ICD3	Computer: Intel Core2 Quad CPU 2.40 GHz, 5 GB RAM, Windows 7 64 bit Home Premium SP1
	First version
**************************************************************************************************/
/*************    Header Files    ***************/
#include "Config.h"
#include "Pins.h"

/************* Semantic Versioning***************/
#if PINS_MAJOR != 2
	#error "Pins.c has had a change that loses some previously supported functionality"
#elif PINS_MINOR != 0
	#error "Pins.c has new features that this code may benefit from"
#elif PINS_PATCH != 0
	#error "Pins.c has had a bug fix, you should check to see that we weren't relying on a bug for functionality"
#endif

/************Arbitrary Functionality*************/
/*************   Magic  Numbers   ***************/
/*************    Enumeration     ***************/
/***********State Machine Definitions************/
/*************  Global Variables  ***************/
//Pin structure definition
struct PIN
{
	int mask;
	volatile unsigned int *TRISregister;
	volatile unsigned int *ODCregister;
	volatile unsigned int *LATregister;
	volatile unsigned int *PORTregister;
} pin[NUMBER_OF_PINS];

/*************Function  Prototypes***************/
/************* Device Definitions ***************/
/************* Module Definitions ***************/
/************* Other  Definitions ***************/

void Pin_Definition(int pinID, int mask, volatile unsigned int *TRISregister, volatile unsigned int *ODCregister, volatile unsigned int *LATregister, volatile unsigned int *PORTregister)
{
	pin[pinID].mask = mask;
	pin[pinID].LATregister = LATregister;
	pin[pinID].ODCregister = ODCregister;
	pin[pinID].PORTregister = PORTregister;
	pin[pinID].TRISregister = TRISregister;
}

void Pin_Initialize(int pinID, int latch, int odc, int tris)
{
	//Set latch first (Needs to be done before setting TRIS)
	Pin_Write(pinID, latch);

	//Set ODC
	Pin_Set_ODC(pinID, odc);

	//Set TRIS - Needs/should) to be done last
	Pin_Set_TRIS(pinID, tris);

	return;
}

void Pin_Low(int pinID)
{
	*pin[pinID].LATregister &= ~pin[pinID].mask;
//	*pinID.LATregister &= ~pinID.mask;
	return;
}

void Pin_High(int pinID)
{
	*pin[pinID].LATregister |= pin[pinID].mask;
//	*pin.LATregister |= pin.mask;
	return;
}

void Pin_Toggle(int pinID)
{
	*pin[pinID].LATregister ^= pin[pinID].mask;
//	*pin.LATregister ^= pin.mask;
	return;
}

void Pin_Write(int pinID, int newState)
{
	switch(newState)
	{
		case 0:
			*pin[pinID].LATregister &= ~pin[pinID].mask;
//			*pin.LATregister &= ~pin.mask;
			return;
		case 1:
			*pin[pinID].LATregister |= pin[pinID].mask;
//			*pin.LATregister |= pin.mask;
			return;
		default:
			return;
	}
}

int Pin_Read(int pinID)
{
	if(*pin[pinID].PORTregister & pin[pinID].mask)
//	if(*pin.PORTregister & pin.mask)
		return 1;
	else
		return 0;
}

void Pin_Set_ODC(int pinID, int newState)
{
	//Set ODC register
	switch(newState)
	{
		case 0:
			*pin[pinID].ODCregister &= ~pin[pinID].mask;
//			*pin.ODCregister &= ~pin.mask;
			return;
		case 1:
			*pin[pinID].ODCregister |= pin[pinID].mask;
//			*pin.ODCregister |= pin.mask;
			return;
		default:
			return;
	}
}

int Pin_Get_ODC(int pinID)
{
	if(*pin[pinID].ODCregister & pin[pinID].mask)
//	if(*pin.ODCregister & pin.mask)
		return 1;
	else
		return 0;
}

void Pin_Set_TRIS(int pinID, int newState)
{
	switch(newState)
	{
		case 0:
			*pin[pinID].TRISregister &= ~pin[pinID].mask;
//			*pin.TRISregister &= ~pin.mask;
			return;
		case 1:
			*pin[pinID].TRISregister |= pin[pinID].mask;
//			*pin.TRISregister |= pin.mask;
			return;
		default:
			return;
	}
}

int Pin_Get_TRIS(int pinID)
{
	if(*pin[pinID].TRISregister & pin[pinID].mask)
//	if(*pin.TRISregister & pin.mask)
		return 1;
	else
		return 0;
}

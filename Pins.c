/**************************************************************************************************
Version History:
v2.0.0	2015-06-14	Craig Comberbach	Compiler: C30 v3.31
 * Retooled entirely. It now uses unique designators instead of passing structures around
 * This simplified initialization, as well as passing pins as an argument to functions (Critical for use with the CTMU & A2D libraries)
v1.0.0	2014-02-05	Craig Comberbach	Compiler: C30 v3.31
 * Added Pin Low, High, and Toggle
 * Tested, this is the official release
v0.1.0	2014-02-01	Craig Comberbach	Compiler: C30 v3.31
 * Rewrote everything from scratch, removing the chip specific case staements and replacing with generic functions that should work on any chip
v0.0.1	2013-07-21  Craig Comberbach	Compiler: XC16 v1.11
 * Retooled everything to use existing macro names for each pin/function
 * Processor names now either enable or disable pins
 * 	-Disabled pins return a 0 indicating it was an invalid choice
 * 	-Enabled pins are have the Latch then the TriState registers set (Specifically in that order) before returning a 1 indicating the pin was valid
 * Added in the Open Drain register to initialization as well
v0.0.0	2013-07-20  Craig Comberbach	Compiler: XC16 v1.11
 * First version
**************************************************************************************************/
/*************    Header Files    ***************/
#include <stdint.h>
#include "Config.h"
#include "Pins.h"

/*************Semantic  Versioning***************/
#if PINS_MAJOR != 2
	#error "Pins.c has had a change that loses some previously supported functionality"
#elif PINS_MINOR != 1
	#error "Pins.c has new features that this code may benefit from"
#elif PINS_PATCH != 0
	#error "Pins.c has had a bug fix, you should check to see that we weren't relying on a bug for functionality"
#endif

/*************   Magic  Numbers   ***************/
/*************    Enumeration     ***************/
/***********  Structure Definitions  ************/
//Pin structure definition
struct PIN
{
	int16_t mask;
	volatile uint16_t *TRISregister;
	volatile uint16_t *ODCregister;
	volatile uint16_t *LATregister;
	volatile uint16_t *PORTregister;
} pin[NUMBER_OF_PINS];

/***********State Machine Definitions************/
/*************  Global Variables  ***************/
/*************Function  Prototypes***************/
/************* Main Body Of Code  ***************/
void Pin_Definition(int16_t pinID, int16_t mask, volatile uint16_t *TRISregister, volatile uint16_t *ODCregister, volatile uint16_t *LATregister, volatile uint16_t *PORTregister)
{
	pin[pinID].mask = mask;
	pin[pinID].LATregister = LATregister;
	pin[pinID].ODCregister = ODCregister;
	pin[pinID].PORTregister = PORTregister;
	pin[pinID].TRISregister = TRISregister;

	return;
}

void Pin_Initialize(int16_t pinID, int16_t latch, int16_t odc, int16_t tris)
{
	Pin_Set_Latch(pinID, latch);	//Latch needs to be done before setting TRIS
	Pin_Set_ODC(pinID, odc);
	Pin_Set_TRIS(pinID, tris);		//TRIS needs to be done last

	return;
}

void Pin_Low(int16_t pinID)
{
	*pin[pinID].LATregister &= ~pin[pinID].mask;
	return;
}

void Pin_High(int16_t pinID)
{
	*pin[pinID].LATregister |= pin[pinID].mask;
	return;
}

void Pin_Toggle(int16_t pinID)
{
	*pin[pinID].LATregister ^= pin[pinID].mask;
	return;
}

void Pin_Set_Latch(int16_t pinID, int16_t newState)
{
	switch(newState)
	{
		case LOW:
			*pin[pinID].LATregister &= ~pin[pinID].mask;
			return;
		case HIGH:
			*pin[pinID].LATregister |= pin[pinID].mask;
			return;
		default:
			return;
	}
}

int16_t Pin_Get_Latch(int16_t pinID)
{
	if(*pin[pinID].LATregister & pin[pinID].mask)
		return HIGH;
	else
		return LOW;
}

int16_t Pin_Read(int16_t pinID)
{
	if(*pin[pinID].PORTregister & pin[pinID].mask)
		return HIGH;
	else
		return LOW;
}

void Pin_Set_ODC(int16_t pinID, int16_t newState)
{
	switch(newState)
	{
		case PUSH_PULL:
			*pin[pinID].ODCregister &= ~pin[pinID].mask;
			return;
		case OPEN_DRAIN:
			*pin[pinID].ODCregister |= pin[pinID].mask;
			return;
		default:
			return;
	}
}

int16_t Pin_Get_ODC(int16_t pinID)
{
	if(*pin[pinID].ODCregister & pin[pinID].mask)
		return OPEN_DRAIN;
	else
		return PUSH_PULL;
}

void Pin_Set_TRIS(int16_t pinID, int16_t newState)
{
	switch(newState)
	{
		case OUTPUT:
			*pin[pinID].TRISregister &= ~pin[pinID].mask;
			return;
		case INPUT:
			*pin[pinID].TRISregister |= pin[pinID].mask;
			return;
		default:
			return;
	}
}

int16_t Pin_Get_TRIS(int16_t pinID)
{
	if(*pin[pinID].TRISregister & pin[pinID].mask)
		return INPUT;
	else
		return OUTPUT;
}

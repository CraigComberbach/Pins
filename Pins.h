#ifndef PINS_H
#define	PINS_H

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
/*************Structure Definitions**************/
//Pin structure definition
struct PIN_DEFINITION
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
 * Initializes a pin
 * @param pin The structure representing the pin
 * @param latch The desired state the LAT should start in (1 = High, 0 = Low)
 * @param odc The desired state the ODC should be in (1 = Open-Drain, 0 = Push-Pull)
 * @param tris The desired state the TRIS should start in (1 = Input, 0 = Output)
 */
void Pin_Initialize(struct PIN_DEFINITION pin, int latch, int odc, int tris);

/**
 * Sets the pin low (LAT register)
 * @param pin The structure representing the pin
 */
void Pin_Low(struct PIN_DEFINITION pin);

/**
 * Sets the pin high (LAT register)
 * @param pin The structure representing the pin
 */
void Pin_High(struct PIN_DEFINITION pin);

/**
 * Toggles the pins (LAT register)
 * @param pin The structure representing the pin
 */
void Pin_Toggle(struct PIN_DEFINITION pin);

/**
 * Allows programatically setting of a pin (LAT register)
 * @param pin The structure representing the pin
 * @param newState (1 = High, 0 = Low)
 */
void Pin_Write(struct PIN_DEFINITION pin, int newState);

/**
 * Sets the ODC register
 * @param pin The structure representing the pin
 * @param newState (1 = Open-Drain, 0 = Push-Pull)
 */
void Pin_Set_ODC(struct PIN_DEFINITION pin, int newState);

/**
 * Sets the TRIS register
 * @param pin The structure representing the pin
 * @param newState (1 = Input, 0 = Output)
 */
void Pin_Set_TRIS(struct PIN_DEFINITION pin, int newState);

/**
 * Reads the current pin (PORT register)
 * @param pin The structure representing the pin
 * @return (1 = High, 0 = Low)
 */
int Pin_Read(struct PIN_DEFINITION pin);

/**
 * Reads the current ODC register
 * @param pin The structure representing the pin
 * @return the current ODC value (1 = Open-Drain, 0 = Push-Pull)
 */
int Pin_Get_ODC(struct PIN_DEFINITION pin);

/**
 * Reads the current TRIS register
 * @param pin The structure representing the pin
 * @return (1 = Input, 0 = Output)
 */
int Pin_Get_TRIS(struct PIN_DEFINITION pin);

#endif	/* PINS_H */


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
/***/
void Pin_Initialize(struct PIN_DEFINITION pin, int latch, int odc, int tris);

/***/
void Pin_Write(struct PIN_DEFINITION pin, int newState);

/***/
void Pin_Set_ODC(struct PIN_DEFINITION pin, int newState);

/***/
void Pin_Set_TRIS(struct PIN_DEFINITION pin, int newState);

/***/
int Pin_Read(struct PIN_DEFINITION pin);

/***/
int Pin_Get_ODC(struct PIN_DEFINITION pin);

/***/
int Pin_Get_TRIS(struct PIN_DEFINITION pin);

#endif	/* PINS_H */


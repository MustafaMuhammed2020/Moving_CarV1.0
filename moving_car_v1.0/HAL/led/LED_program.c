/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : program file of led                  */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"


/** INCLUDE INTERFACE FILES OF LOWER LAYERS **/
#include "../../MCAL/dio/DIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


/***************************************************/
/** FUNCTION TO INITIALIZE A PIN                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_init(uint8_t u8_a_led_port , uint8_t u8_a_ledpin)
{
	
	DIO_setpindir(u8_a_led_port , u8_a_ledpin , DIO_PIN_OUTPUT); /** SET THE LED PIN AS OUTPUT **/
}


/***************************************************/
/** FUNCTION TO SET A LED AS ON                   **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_on(uint8_t u8_a_led_port , uint8_t u8_a_ledpin)
{
	
	DIO_setpinvalue(u8_a_led_port , u8_a_ledpin , DIO_PIN_HIGH); /** SET THE OUTPUT PIN AS HIGH **/
}

/***************************************************/
/** FUNCTION TO SET A LED AS OFF                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_off(uint8_t u8_a_led_port , uint8_t u8_a_ledpin)
{
	
	DIO_setpinvalue(u8_a_led_port , u8_a_ledpin , DIO_PIN_LOW); /** SET THE OUTPUT PIN AS LOW **/
}


/***************************************************/
/** FUNCTION TO TOGLE A LED                       **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_toggle(uint8_t u8_a_led_port , uint8_t u8_a_ledpin)
{
	
	DIO_togglepin(u8_a_led_port , u8_a_ledpin); /** TOGGLE THE SPECIFIC LED **/
}


/**************************************************/
/* Author  : Team2               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : interface file of led                */
/**************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/***************************************************/
/** FUNCTION TO INITIALIZE A PIN                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_init(uint8_t u8_a_led_port , uint8_t u8_a_ledpin);


/***************************************************/
/** FUNCTION TO SET A LED AS ON                   **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_on(uint8_t u8_a_led_port , uint8_t u8_a_ledpin);

/***************************************************/
/** FUNCTION TO SET A LED AS OFF                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_off(uint8_t u8_a_led_port , uint8_t u8_a_ledpin);


/***************************************************/
/** FUNCTION TO TOGLE A LED                       **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_toggle(uint8_t u8_a_led_port , uint8_t u8_a_ledpin);

#endif

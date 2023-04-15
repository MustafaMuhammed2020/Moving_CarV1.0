/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/
/** Hint    : Application layer                               **/
/***************************************************************/

/** INCLUDE LIBRARIES **/
#include "../SERVICE/common_macros.h"
#include "../SERVICE/standard_types.h"
#include <avr/interrupt.h>

/** INCLUDE HAL DRIVERS **/
#include "../MCAL/dio/DIO_interface.h"
#include "../HAL/led/LED_interface.h"
#include "../../MCAL/timer0/TMR0_interface.h"
#include "../HAL/motor/motor_interface.h"
#include "../../MCAL/timer1/timer1_interface.h"
#include "../../MCAL/timer1/timer1_config.h"
#include "../HAL/motor/motor_config.h"
#include "../../MCAL/timer0/TMR0_config.h"

/** INCLUDE DRIVER FILES **/
#include "APP.h"

uint32_t u32_a_nuovs = 0 ;  /** COUNTER FOR NUMBER OF OVS **/

uint32_t ticks = 0 ;

uint32_t tick = 0 ;

void APP_init(void)
{
	
 	MOTOR_init(MOTOR1_ID);  /** INIALIZE MOTOR 1 **/
 		
	MOTOR_turnoff(MOTOR1_ID); /** MOTOR 1 IS OFF IN THE BEGINNING **/
	
	MOTOR_rotateclkdir(MOTOR1_ID); /** MOTOR 1 ROTATE CLOCKWISE **/
	
	TMR0_init();  /** INITIALIZE TIMER 0 **/
	
	TMR1_init();  /** INITIALIZE TIMER 1 **/
		
}


void APP_start(void)
{
  tick = 0 ;
  
  ticks = TMR1_getovs(3000);
  
  TMR1_start();
  while (tick < ticks )
  {
	  /*MOTOR_applyspeed(MOTOR1_ID , speed_mode_1);*/
	  DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
	  TMR0_delaymicos(64);
	  
	  DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
	  TMR0_delaymicos(64);

  }
  TMR1_stop();
  
  tick = 0 ;
  
  ticks = TMR1_getovs(1000);
  
  TMR1_start();
  while (tick < ticks )
  {
	  
	  MOTOR_turnoff(MOTOR1_ID);
	  
  }
  TMR1_stop();
  
  tick = 0 ;
  
  ticks = TMR1_getovs(3000);
  
  TMR1_start();
  while (tick < ticks )
  {
	  /*MOTOR_applyspeed(MOTOR2_ID , speed_mode_1);*/
	  DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_HIGH);
	  TMR0_delaymicos(192);
	  
	  DIO_setpinvalue(MOTOR1_PORT , MOTOR1_ENABLE_PIN , DIO_PIN_LOW);
	  TMR0_delaymicos(448);

  }
  TMR1_stop();
  
  tick = 0 ;
  
  ticks = TMR1_getovs(1000);
  
  TMR1_start();
  while (tick < ticks )
  {
	  
	  MOTOR_turnoff(MOTOR1_ID);
	  
  }
  TMR1_stop();
	
}

ISR(TIMER1_OVF_vect)
{
	//set_bit(SREG , 7);
	
	tick++ ;
}
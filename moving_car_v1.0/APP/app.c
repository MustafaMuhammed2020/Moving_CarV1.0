/***************************************************************/
/** Author  : Mustafa Mohammed Abdou                          **/
/** Date    : 1 Octobre, 2021                                 **/
/** Version : V01                                             **/
/** Hint    : Application layer                               **/
/***************************************************************/

/** INCLUDE LIBRARIES **/
#include "../SERVICE/common_macros.h"
#include "../SERVICE/standard_types.h"


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



void APP_init(void)
{
	TMR0_init();  /** INITIALIZE TIMER 0 **/
	
	TMR1_init();  /** INITIALIZE TIMER 1 **/
	
	MOTOR_init(MOTOR1_ID);  /** INIALIZE MOTOR 1 **/
	
	MOTOR_init(MOTOR2_ID);  /** INIALIZE MOTOR 1 **/
	
	MOTOR_turnoff(MOTOR1_ID); /** MOTOR 1 IS OFF IN THE BEGINNING **/
	
	MOTOR_turnoff(MOTOR2_ID); /** MOTOR 1 IS OFF IN THE BEGINNING **/
	
	MOTOR_rotateclkdir(MOTOR1_ID); /** MOTOR 1 ROTATE CLOCKWISE **/
	
	MOTOR_rotateclkdir(MOTOR2_ID); /** MOTOR 1 ROTATE CLOCKWISE **/
	
}



void APP_start(void)
{
   
     
		
	MOTOR_applyspeed(MOTOR1_ID , speed_mode_2);
	
	//MOTOR_applyspeed(MOTOR2_ID , speed_mode_1);
	
// 	TMR1_setdelayms(4000);
// 	
// 	MOTOR_applyspeed(MOTOR1_ID , speed_mode_1);
// 	
// 	TMR1_setdelayms(4000);
// 	


	
}
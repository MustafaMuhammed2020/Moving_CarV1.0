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
#include "../HAL/motor/motor_config.h"
#include "../../MCAL/timer0/TMR0_config.h"
#include "../../MCAL/timer2/timer2.h"
/** INCLUDE DRIVER FILES **/
#include "APP.h"
static unsigned int u16_gs_currentCount=0; //counter which increments everytime the ISR is called
static uint8_t u8_gs_start = 0;//u8_gs_start flag
static uint8_t u8_gs_stop  = 0;//u8_gs_stop flag


void APP_init(void)
{
	TMR0_init();  /** INITIALIZE TIMER 0 **/
	
    //Interrupt initialization
    SREG  |= (1<<7);//enable global interrupt
    MCUCR |= (1<<0) | (1<<1); //setting interrupt 0 sense control to rising edge
    MCUCR |= (1<<2) | (1<<3); //setting interrupt 1 sense control to rising edge
    GICR  |= (1<<6) | (1<<7); //enable external interrupt 0 & External Interrupt 1
    TIMSK |= (1<<6); //enable timer 2 interrupt
	TIMER2_normalMode();//Set timer 2 to normal mode
	
	MOTOR_init(MOTOR1_ID);  /** INIALIZE MOTOR 1 **/
	
	MOTOR_init(MOTOR2_ID);  /** INIALIZE MOTOR 1 **/
	
	MOTOR_turnoff(MOTOR1_ID); /** MOTOR 1 IS OFF IN THE BEGINNING **/
	
	MOTOR_turnoff(MOTOR2_ID); /** MOTOR 1 IS OFF IN THE BEGINNING **/
	
	MOTOR_rotateclkdir(MOTOR1_ID); /** MOTOR 1 ROTATE CLOCKWISE **/
	
	MOTOR_rotateclkdir(MOTOR2_ID); /** MOTOR 1 ROTATE CLOCKWISE **/
	
}



void APP_start(void)
{

// 	unsigned int u16_l_ovf;
// 	u16_l_ovf = TIMER2_getInitialValue(3000);
// 	TIMER2_perscalerMode(PRESCALER_MODE);
	
/*	while(u16_gs_currentCount<u16_l_ovf)*/
//	{
		MOTOR_applyspeed(MOTOR1_ID , speed_mode_2);
		MOTOR_applyspeed(MOTOR2_ID , speed_mode_2);		
/*	}*/
		    
// 	TIMER2_perscalerMode(TIMER_OFF_);//close the timer
// 	TCNT2 = 0;//set the timer counter register value to 0
// 	u16_gs_currentCount = 0;//reset the counter
		    
//	MOTOR_turnoff(MOTOR1_ID);
//	MOTOR_turnoff(MOTOR2_ID);
//	MOTOR_applyspeed(MOTOR2_ID , speed_mode_1);	
//	TMR0_delaymicos(3000000);

	
// 	TMR1_setdelayms(4000);
// 	
// 	MOTOR_applyspeed(MOTOR1_ID , speed_mode_1);
// 	
// 	TMR1_setdelayms(4000);
// 		
}

// ISR(TIMER2_OVF)
// {
// 	u16_gs_currentCount++;
/*}*/
/**************************************************************************/
//Name:  main.c																														//
//Purpose:  Skeleton project with configuration for ADC, DAC, MCG and PIT	//
//Author:  Ben Gerber																									//
//Revision:  1.0 18Oct2018 BG DSP Chebyshev Type II									//
//Target:  Freescale K22f																									//
/**************************************************************************/

#include "MK22F51212.h"                 				//Device header
#include "MCG.h"																//Clock header
#include "TimerInt.h"														//Timer Interrupt Header
#include "ADC.h"																//ADC Header
#include "DAC.h"																//DAC Header
#include "math.h"																//Math Header
#include "coef.h"

#define PI 3.14159
#define sw2 !((GPIOB->PDIR >> 1) & 1)
#define sw3 !((GPIOC->PDIR >> 17) &1)

uint16_t valADC;
uint16_t valDAC;
uint16_t K = 1, i, k;

float Yn[Korder + 1] = {0};
float s[Korder][2] = {{0}};

void PIT0_IRQHandler(void){	//This function is called when the timer interrupt expires
	//Place Interrupt Service Routine Here
	valADC = ADC0->R[0];// << 4;
	ADC0->SC1[0]	=	ADC_SC1_ADCH(0x00);
	GPIOA->PSOR = GPIO_PSOR_PTSO(0x0006);		//Turn on Red LED
	GPIOD->PSOR = GPIO_PSOR_PTSO(0x0020);		//Turn Blue On
	
	
	/*if(sw2)
	{
		K++;
	}
	if(sw3)
	{
		K--;
	}*/
	Yn[0] = (float) valADC;

	for(k = 0; k < Korder; k++)
	{
		Yn[k+1] = B[k][0]*Yn[k] + s[k][0];
            	s[k][0] = B[k][1]*Yn[k] - A[k][0]*Yn[k+1] + s[k][1];
        	s[k][1] = B[k][0]*Yn[k] - A[k][1]*Yn[k+1];
	}

	valDAC = (uint16_t) (Yn[Korder]);

	
	DAC0->DAT->DATL = DAC_DATL_DATA0((valDAC))	;		//Set DAC Output
	DAC0->DAT->DATH = DAC_DATH_DATA1((valDAC >> 8)	&0x0F)	;		//Set DAC Output

	

	GPIOA->PCOR = GPIO_PCOR_PTCO(0x0006);		//Turn Red Off
	GPIOD->PCOR = GPIO_PCOR_PTCO(0x0020);		//Turn off Blue LED
	
	NVIC_ClearPendingIRQ(PIT0_IRQn);							//Clears interrupt flag in NVIC Register
	PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK;		//Clears interrupt flag in PIT Register
}

int main(void){
	MCG_Clock120_Init();
	ADC_Init();
	ADC_Calibrate();
	DAC_Init();
	TimerInt_Init();
	
	//Set Port GPIO
	SIM -> SCGC5 = 0x1E00;
	
	//Set LED Mode to AT1
	PORTA->PCR[1] 	= PORT_PCR_MUX(0x01)					;		//Set PTA1 to ALT1
	PORTD->PCR[5] 	= PORT_PCR_MUX(0x01)					;		//Set PTD5 to ALT1
	
	//Set LED to Output
	GPIOA -> PDDR = GPIO_PDDR_PDD(0x0006);
	GPIOD -> PDDR = GPIO_PDDR_PDD(0x0020); 
	
	//Set Switch inputs
	GPIOB -> PDDR = GPIO_PDDR_PDD(0x0000); //Set PORTB (SW3) as input
	GPIOC -> PDDR = GPIO_PDDR_PDD(0x0000); //Set PORTC (SW2) as input

	while(1){
		//Main loop goes here
		
	}
}

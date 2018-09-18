/**************************************************************************/
//Name:  main.c																														//
//Purpose:  Skeleton project with configuration for ADC, DAC, MCG and PIT	//
//Author:  Ethan Hettwer																									//
//Revision:  1.0 15Sept2014 EH Initial Revision														//
//Target:  Freescale K22f																									//
/**************************************************************************/

#include "MK22F51212.h"                 				//Device header
#include "MCG.h"																//Clock header
#include "TimerInt.h"														//Timer Interrupt Header
#include "ADC.h"																//ADC Header
#include "DAC.h"																//DAC Header

uint16_t valADC;
uint16_t valDAC;
int i, swap = 0;


void PIT0_IRQHandler(void){	//This function is called when the timer interrupt expires
	//Place Interrupt Service Routine Here
	valADC = ADC0->R[0];// << 4;
	ADC0->SC1[0]	=	ADC_SC1_ADCH(0x00);
	
	switch(swap)
	{
		case 0: valDAC = 2048; break;
		case 1: valDAC = 4096 - valADC; break;
		case 2: valDAC = 2048; break;
		case 3: valDAC = valADC; swap = 0; break;
	}
	
	if(swap){
		valDAC = 4096 - valADC;
	} else{
		valDAC = 2048;
	}
	
	DAC0->DAT->DATL = DAC_DATL_DATA0((valDAC))	;		//Set DAC Output
	DAC0->DAT->DATH = DAC_DATH_DATA1((valDAC >> 8)	&0x0F)	;		//Set DAC Output
	
	swap = !swap;
	
	NVIC_ClearPendingIRQ(PIT0_IRQn);							//Clears interrupt flag in NVIC Register
	PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK;		//Clears interrupt flag in PIT Register
}

int main(void){
	MCG_Clock120_Init();
	ADC_Init();
	ADC_Calibrate();
	DAC_Init();
	TimerInt_Init();
	while(1){
		//Main loop goes here
	}
}
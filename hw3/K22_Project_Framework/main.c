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
#include "math.h"																//Math Header

#define c3 1000
#define PI 3.14159

uint16_t valADC;
uint16_t valDAC;
int K = 1, i = 1, k;
float w0 = c3*2*PI/40, t, f, sumVal;

float magYk[10] = {
    0.2564,
    0.3836,
    0.0540,
    0.1168,
    0.1276,
    0.0350,
    0.0702,
    0.0757,
    0.0291,
    0.0478
};

float thetaYk[10] = {
		-1.3882,
		 2.8423,
		 0.4013,
    -1.3741,
     2.1551,
    -0.5633,
    -2.0350,
     1.4080,
    -1.3896,
    -2.7280
};

void PIT0_IRQHandler(void){	//This function is called when the timer interrupt expires
	//Place Interrupt Service Routine Here
	//valADC = ADC0->R[0];// << 4;
	//ADC0->SC1[0]	=	ADC_SC1_ADCH(0x00);

	f = c3/40;
	sumVal = .7672;
	
	for(k = 0; k < K; k++)
	{
		sumVal += 2*magYk[k]*cosf((float)((k+1)*w0*t) + thetaYk[k]);
	}
	
	valDAC = (uint16_t)(sumVal*4095/3.3);

	
	DAC0->DAT->DATL = DAC_DATL_DATA0((valDAC))	;		//Set DAC Output
	DAC0->DAT->DATH = DAC_DATH_DATA1((valDAC >> 8)	&0x0F)	;		//Set DAC Output

	//if(t > (1/f)){
	//	i = 0;
	//}
	
	//i++;
	//t = i * .0001f;
	t += .0001f;
	
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
/**************************************************************************/
//Name:  main.c																														//
//Purpose:  Skeleton project with configuration for ADC, DAC, MCG and PIT	//
//Author:  Ben Gerber																											//
//Revision:  1.0 18Oct2018 BG DSP Chebyshev Type II												//
//Target:  Freescale K22f																									//
/**************************************************************************/

#include "MK22F51212.h"                 				//Device header
#include "MCG.h"																//Clock header
#include "TimerInt.h"														//Timer Interrupt Header
#include "ADC.h"																//ADC Header
#include "DAC.h"																//DAC Header
#include "math.h"																//Math Header
#include "coef.h"

#define SW2 !((GPIOC->PDIR >> 1) & 1)
#define SW3 !((GPIOB->PDIR >> 17)& 1)
#define MAXIMUM 1024

uint16_t valADC;
uint16_t valDAC;
uint8_t scroll = 0;
uint16_t integrator1 = 0;
uint16_t integrator2 = 0;  /* Will range from 0 to the specified MAXIMUM */
uint16_t outputBut;      /* Cleaned-up version of the input signal */
uint16_t buff = 0;
uint16_t old = 0;

int Y;//,X;
int X[Korder];
//int s[Korder] = {0};

void PIT0_IRQHandler(void){	//This function is called when the timer interrupt expires
	//Place Interrupt Service Routine Here
	GPIOA->PCOR = GPIO_PCOR_PTCO(0x0006);		//Turn Red Off
	GPIOD->PCOR = GPIO_PCOR_PTCO(0x0020);		//Turn off Blue LED
	
	valADC = ADC0->R[0];
	ADC0->SC1[0]	=	ADC_SC1_ADCH(0x00);
	
	X[old] = valADC - 2048;
	buff = old;
	Y = 0;

	switch(scroll)
	{
		case 0: {
			valDAC = valADC;
			break;
		}
		case 1: {
			for(int i = 0; i < Korder; i++)
			{
					//Y = h[i]*X + s[i];
					//s[i] = h[i]*X + s[i+1];
					Y = h[i]*X[buff] + Y;
					buff++;
					if(buff >= Korder){buff = 0;}
			}
			valDAC = ((Y >> 16) & 0xFFFF) + 1862;
			old++;
			if(old >= Korder){old = 0;}
			break;
		}
	}


	
	DAC0->DAT->DATH = DAC_DATH_DATA1((valDAC >> 8)	&0x0F)	;		//Set DAC Output
	DAC0->DAT->DATL = DAC_DATL_DATA0((valDAC))	;		//Set DAC Output
	
	NVIC_ClearPendingIRQ(PIT0_IRQn);							//Clears interrupt flag in NVIC Register
	PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK;		//Clears interrupt flag in PIT Register

	GPIOA->PSOR = GPIO_PSOR_PTSO(0x0006);		//Turn on Red LED
	GPIOD->PSOR = GPIO_PSOR_PTSO(0x0020);		//Turn Blue On
}

int main(void){
	MCG_Clock120_Init();
	ADC_Init();
	ADC_Calibrate();
	DAC_Init();
	TimerInt_Init();
	
	//Enable clock to ports through SCGC5 (for buttons and LEDs)
	SIM->SCGC5 = SIM_SCGC5_PORTA(1)|SIM_SCGC5_PORTB(1)|SIM_SCGC5_PORTC(1)|SIM_SCGC5_PORTD(1);

	//set the corresponding port Pin Control Register to configure the MUX field so that the pin is configured GPIO
	PORTA->PCR[1] = PORT_PCR_MUX(001);//set PTA1 to ALT1 (Red LED)
	PORTA->PCR[2] = PORT_PCR_MUX(001);//set PTA2 to ALT1 (Green LED)
	PORTD->PCR[5] = PORT_PCR_MUX(001);//set PTD5 to ALT1 (Blue LED)
	PORTC->PCR[1]= PORT_PCR_MUX(001);//set PTC1 to ALT1 (SW2)
	PORTB->PCR[17] = PORT_PCR_MUX(001);//set PTB17 to ALT1 (SW3)
	GPIOB->PDDR=0x0000;//set "port data direction register" to input (SW3)
	GPIOC->PDDR=0x0000;//set "port data direction register" to input (SW2)
	GPIOA->PDDR=0x0006;//set LED at ports A1 and A2 to output(Red & Green LEDs)
	GPIOD->PDDR=0x0020;//set led at port D5 to output(Blue LED)

	//int myVariableThatIsNeverUsed = 0;
	int p = 0;
	while(1){
		//Main loop goes here
		//may need to implement a software debounce to realize reliable pushbutton operation 
		
		//Step 1: Update the integrator based on the input signal.  Note that the
		//integrator follows the input, decreasing or increasing towards the limits as
		//determined by the input state (0 or 1). 
	 
		if (!SW2)
		{
			if (integrator1 > 0)
			{
				integrator1--;
			}
		}
		else if (SW2 && integrator1 < MAXIMUM)
		{
			integrator1++;
		}
		
		if (!SW3)
		{
			if (integrator2 > 0)
			{
				integrator2--;
			}
		}
		else if (SW3 && integrator2 < MAXIMUM)
		{
			integrator2++;
		}
	 
		//Step 2: Update the output state based on the integrator.  Note that the
		//output will only change states if the integrator has reached a limit, either
		//0 or MAXIMUM.
	 
		if (integrator1 >= MAXIMUM && scroll > 1)
		{
			scroll = 0;
		}
		else if (integrator1 >= MAXIMUM && p != 2)
		{
			scroll++;
			integrator1 = MAXIMUM - 25;  //defensive code if integrator got corrupted
			p = 2;
		}
		if (integrator2 >= MAXIMUM && scroll > 0 && p != 3)
		{
			scroll--;
			integrator2 = MAXIMUM - 25;  //defensive code if integrator got corrupted
			p = 3;
		}
		if( integrator1 == 0 && integrator2 == 0)
		{
			p = 0;
		}
		
	}
}



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
#include "string.h"															//String header for memset

#define SW2 !((GPIOC->PDIR >> 1) & 1)
#define SW3 !((GPIOB->PDIR >> 17)& 1)
#define bufferSize 2048
#define halfBuffer 1024
#define threshold .3

uint16_t valADC;
uint16_t buff = 0;
uint16_t old = 0;
uint16_t minTau = 0;
uint16_t a,c;

uint8_t full;


float sum;
int delta;
int x[bufferSize] = {0};
float yinBuffer[bufferSize] = {0};
float f0 = 0, fa, fb, fc, accuTau;
int16_t cents;

void PIT0_IRQHandler(void){	//This function is called when the timer interrupt expires
	//Place Interrupt Service Routine Here
	GPIOA->PCOR = GPIO_PCOR_PTCO(0x0006);		//Turn Red Off
	GPIOD->PCOR = GPIO_PCOR_PTCO(0x0020);		//Turn off Blue LED
	
	if(buff < halfBuffer)
	{
		x[buff] = ADC0->R[0];
		ADC0->SC1[0]	=	ADC_SC1_ADCH(0x00);
		full = 0;
	}else if(buff >= halfBuffer)
	{
		full = 1;
	}
	buff++;
	
	NVIC_ClearPendingIRQ(PIT0_IRQn);							//Clears interrupt flag in NVIC Register
	PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK;		//Clears interrupt flag in PIT Register
	if(full >= 1) {
		//NVIC_DisableIRQ(PIT0_IRQn)											;		//CMSIS Function to enable interrupt via PIT
		PIT->CHANNEL[0].TCTRL &= !PIT_TCTRL_TEN_MASK;		//Timer Enable.  Set to 1 to enable timer.}
	}

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

	while(1)
	{
		//int myVariableThatIsNeverUsed = 0;
		while(full){
			//Main loop goes here
			sum = 0;
			memset(yinBuffer,0,bufferSize);
		
			// Step 2: Difference equation
			for(uint16_t tau = 0; tau < halfBuffer; tau++)
			{
				for(uint16_t i = 0; i < halfBuffer; i++)
				{
					delta = x[i] - x[i + tau];
					yinBuffer[tau] += (float)delta * (float)delta;
				}
			}
			
			
			// Step 3: Normalized mean of difference equation
			yinBuffer[0] = 1;
			for(uint16_t o = 1; o < halfBuffer; o++)
			{
				sum += yinBuffer[o];
				yinBuffer[o] = yinBuffer[o] * (((float)(o))/sum);
			}
			
			// Step 4: Find mimimum Tau of the absolute threshold subset
			
			for(uint16_t tau = 1; tau < halfBuffer; tau++)
			{
				if(yinBuffer[tau] < (float)threshold)
				{
					if(tau + 1 < halfBuffer && yinBuffer[tau] < yinBuffer[tau - 1] && yinBuffer[tau + 1] > yinBuffer[tau] && yinBuffer[tau] < yinBuffer[minTau])
					{
						minTau = tau;
						break;
					}
				}
			}
			
			// Step 5: Interpolate 
			if(minTau > 0)
			{
				if(minTau - 1 < 0)
				{
					a = minTau;
				}else
				{
					a = minTau - 1;
				}
				if(minTau + 1 > bufferSize)
				{
					c = minTau;
				}else
				{
					c = minTau + 1;
				}
				fa = yinBuffer[a];
				fb = yinBuffer[minTau];
				fc = yinBuffer[c];
				
				// Legrange interpolation function
				accuTau = minTau + (fa - fc) / (2 * (fa - 2*fb + fc));
				f0 = (float)16000/accuTau;
				
				// Step 6: Calculate tuning
				
				cents = (int16_t)(1200*log2(f0/440.0f));
				
				//Reset interrupt to collect new data
				
				PIT->CHANNEL[0].TCTRL	=	
												PIT_TCTRL_TIE_MASK		|		//Timer Interupt Enable.  Request interrupt whenever TFLG0[TIF] is set.
												0x00u;
				
				PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK			|		//Sets to 1 at end of timer period.  Writing 1 clears this bit.  If TCTRL[TIE] is set it also triggers an interrupt.
												0x00u;
				
				//NVIC_EnableIRQ(PIT0_IRQn)											;		//CMSIS Function to enable interrupt via PIT
				PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK		;		//Timer Enable.  Set to 1 to enable timer.
				PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK		;		//Timer Enable.  Set to 1 to enable timer.
				//NVIC_EnableIRQ(PIT0_IRQn)											;		//CMSIS Function to enable interrupt via PIT
				full = 0;
				buff = 0;
				
			}else
			{
				f0 = -1;
				//Reset interrupt to collect new data
				PIT->CHANNEL[0].TCTRL	=	
													PIT_TCTRL_TIE_MASK		|		//Timer Interupt Enable.  Request interrupt whenever TFLG0[TIF] is set.
													0x00u;
				
				PIT->CHANNEL[0].TFLG	= PIT_TFLG_TIF_MASK			|		//Sets to 1 at end of timer period.  Writing 1 clears this bit.  If TCTRL[TIE] is set it also triggers an interrupt.
													0x00u;
				
				//NVIC_EnableIRQ(PIT0_IRQn)											;		//CMSIS Function to enable interrupt via PIT
				PIT->CHANNEL[0].TCTRL |= PIT_TCTRL_TEN_MASK		;		//Timer Enable.  Set to 1 to enable timer.
				full = 0;
				buff = 0;
			}
		}
	}
}



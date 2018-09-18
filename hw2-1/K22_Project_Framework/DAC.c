/**************************************************************************/
//Name:  DAC.c																														//
//Purpose:  Allow configuration and use of DAC														//
//Author:  Ethan Hettwer																									//
//Revision:  1.1 15Sept2014	EH Confert to K22f														//
//					 1.0 29Aug2014 EH Initial Revision														//
//Target:  Freescale K22f																									//
/**************************************************************************/

#include "MK22F51212.h"                 				//Device header
#include "DAC.h"																//DAC header

/******************************************************************/
//						Function for Initialization of DAC									//
/******************************************************************/

void DAC_Init(void){
	
	//Configure clock gating and disable while configuring
	SIM->SCGC6 |= SIM_SCGC6_DAC0_MASK					;		//Enable clock to ADC module
	DAC0->C0	 &= ~(DAC_C0_DACEN_MASK)				;		//Disable DAC
	
	//Configure DAC Registers
	
	//Configure DAC_DAT - Data low/high register.  Vout = Vin * (1+DAC_DAT[11:0])/4096
	DAC0->DAT->DATL = DAC_DATL_DATA0(0x00)		;		//Set Output to 0.
	DAC0->DAT->DATH = DAC_DATH_DATA1(0x00)		;		//Set Output to 0.
	
	//Configure DAC0_SR - Status Register, writing 0 clears, writing 1 has no effect.
	DAC0->SR 				=	DAC_SR_DACBFRPTF_MASK		|		//DAC Buffer Read Pointer Top Position Flag, cleared if pointer is not 0, set if pointer is 0.
										//DAC_SR_DACBFRPBF_MASK |		//DAC Buffer Read Pointer Bottom Position Flag, cleared if pointer is not = C2[DACBFUP], set if is equal.
										0x00u;
	
	//Configure DAC0_C0 - Control Register 0, DO NOT USE 32 OR 16 BIT ACCESSES TO THIS REGISTER!!!
	DAC0->C0				=	//DAC_C0_DACEN_MASK			|		//DAC enable bit.
										DAC_C0_DACRFS_MASK			|		//DAC Reference Select.  If cleared use DACREF_1, if set use DACREF_2.
										//DAC_C0_DACTRGSEL_MASK	|		//DAC Trigger Select.  If cleared hardware triggered, if set software triggered.
										//DAC_C0_DACSWTRG_MASK	|		//DAC SW Trigger.  Write only, always reads 0.  If cleared software trigger not valed, if set software trigger valid.
										//DAC_C0_LPEN_MASK			|		//Low Power Control.  If cleared high power mode, if set low power mode.
										//DAC_C0_DACBTIEN_MASK	|		//DAC Buffer read pointer top flag interrupt enable.  If cleared disabled, if set enabled.
										//DAC_C0_DACBBIEN_MASK	|		//DAC Buffer read pointer bottom flag interrupt enable.  If cleared disabled, if set enabled.
										(uint8_t)0x00u;
										
	//Configure DAC0_C1 - Control Register 1, DO NOT USE 32 OR 16 BIT ACCESSES TO THIS REGISTER!!!
	DAC0->C1				= //DAC_C1_DMAEN_MASK			|		//DMA Enable.  If cleared disable, if set enabled.
										//DAC_C1_DACBFMD_MASK		|		//DAC Buffer Work Mode Select.  If cleared normal, if set one-time scan mode.
										//DAC_C1_DACBFEN_MASK		|		//DAC Buffer Enable.  If cleared converted data is always first word of the buffer, if set data is word read pointer points to.
										(uint8_t)0x00u;
										
	//Configure DAC0_C2 - Control Register 2, DO NOT USE 32 OR 16 BIT ACCESSES TO THIS REGISTER!!!
	DAC0->C2				=	//DAC_C2_DACBFRP_MASK		|		//DAC Buffer Read Pointer.  Keeps current value of buffer read pointer.
										//DAC_C2_DACBFUP_MASK		|		//DAC Buffer Upper Limit.  Selects upper limit of DAC buffer.
										(uint8_t)0x00u;
										
	//Enable DAC0 after configuration complete.
	DAC0->C0				|=DAC_C0_DACEN_MASK				|		//Enable DAC.
										(uint8_t)0x00u;
}//End DAC_Init					

/******************************************************************/
//						End Function for Initialization of DAC							//
/******************************************************************/

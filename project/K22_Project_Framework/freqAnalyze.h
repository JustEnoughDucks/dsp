/**************************************************************************/
//Name:  freqAnalyze.h																										//
//Purpose:  Implement function to compare measured to expected frequency  //
//Author:  Ben Gerber																											//
//Revision:  1.0 13Dec2018	Initial creation															//
//Target:  Freescale K22f																									//
/**************************************************************************/
#include "MK22F51212.h"                				 	//Device header


#ifndef __freqAnalyze_H_
#define __freqAnalyze_H_

uint8_t getTunedFrequency(float f0);												// Gets base frequency and compares

#endif

/**************************************************************************/
//Name:  LCD.h																														//
//Purpose:  Implement Glower's PIC LCD Library on K22F									  //
//Author:  Ben Gerber																											//
//Revision:  1.0 13Dec2018	Initial creation															//
//Target:  Freescale K22f																									//
/**************************************************************************/


#ifndef __LCD_H_
#define __LCD_H_

void Wait_ms(unsigned int X);

void LCD_Pause(void);

void LCD_Strobe(void);

void LCD_Inst(unsigned char c);

void LCD_Move(unsigned char Row, unsigned char Col);

void LCD_Write(unsigned char c);

void LCD_Init(void);

#endif

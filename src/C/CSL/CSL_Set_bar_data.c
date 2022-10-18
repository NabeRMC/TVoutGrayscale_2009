/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: A_CSL_Set_bar_data.c
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/10/xx
*****************************************************************************/

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include "common.h"
#include "defCSL.h"
#include "defCRT.h"
#include "defAPP.h"

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : 
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CSL_Set_bar_data( void )
{
	UB i,wr_data;
	
	wr_data = 0;
	
	for( i=96; i<= (16*2 +96); i++ ){
		vram_line[i] = wr_data;
		wr_data++;
		( wr_data = wr_data & 0x0F );
	}
 	
}
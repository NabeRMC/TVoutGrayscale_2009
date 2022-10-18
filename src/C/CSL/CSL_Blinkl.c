/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: CSL_Blink.c
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
#include "defCSL.h"
#include "defSYS.h"
#include "defCRT.h"

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : Console•”‚Ì“_–Å
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CSL_Blink( void )
{
	UB	i,j;
	static UB	isBLINK = 0;
	
	isBLINK = ~isBLINK;
	
	for( i=0,j=0 ; i < CSL_CHAR_MAX; i++,j++ ){
		if( isBLINK ){
			vram_txt[i] = vram_txtbuf[j];
		}
		else{
			vram_txt[i] = 0;
		}
	}

}


/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: CSL_Scroll.c
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
* Function : ConsoleâÊñ ÇÃÉXÉNÉçÅ[Éã
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CSL_Scroll( void )
{
	UB	i;
	static UB	p_txt_buf = 0;
	
	for( i = 0; i < CSL_CHAR_MAX; i++ ){
		if( (p_txt_buf >= CSL_CHAR_BUF_MAX)
		|| (vram_txtbuf[p_txt_buf] == ('~' - CG_OFFSET)) ){ 
			p_txt_buf = 0;
		}		
		vram_txt[i] = vram_txtbuf[p_txt_buf];
		p_txt_buf++;
	}

}


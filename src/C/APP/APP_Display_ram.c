/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Displat_ram.c
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2008 Meow
	History		:2008/09/xx
*****************************************************************************/
/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include "defSYS.h"
#include "defAPP.h"
#include "defPort.h"
#include "defCRT.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/* Program                                                                 	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : 
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 

const prog_char *TEN  = {0,1,2,3,4,5,6,7,8,9};

配列の要素を読む 
char res = pgm_read_byte(&TEN[5]); 			TEN[X]の読み出し
char res = pgm_read_byte(TEN+X); 			TENからXバイト目の読み出し
----------------------------------------------------------------------------*/
void APP_Display_ram(void)
{
	UB i;
	UH	address_mon;
	UB	data_mon;
	UB	*p_data;
	

	for( i = 0; i < AD_DMEM_SIZE; i++ ){

		address_mon = pgm_read_word( &ad_dmem[i] );
		p_data = (UB *)address_mon;
		data_mon = *p_data;

		vram_txt[i*3] = APP_htoa( data_mon/0x10 );
		vram_txt[i*3 +1] = APP_htoa( data_mon%0x10 );
		vram_txt[i*3 +2] = ','-0x20;
		
	}

}
    


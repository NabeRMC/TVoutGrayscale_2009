/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: A_CSL_Set_test_data.c
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
void CSL_Set_test_data( UB mode )
{
	UB	i;
	
	CSL_Clear();
	
	i = 0;
	
	if( mode == SYS_STBY ){
		while( pgm_read_byte(&CSL_STBY_data[i]) != 0 ){
											/* ??? NULLは0か？文字列の終わりにNULLは配置されるか?	*/
			vram_txtbuf[i] = pgm_read_byte(&CSL_STBY_data[i]) - CG_OFFSET;
			vram_txt[i] = vram_txtbuf[i];
			i++;
			if( i >= VRAM_TXT_SIZE ){		/* ??? test	??? */
				break;
			}
		}
		vram_txtbuf[i] = 0xFF;
		vram_txt[i] = vram_txtbuf[i];
	}
	
	else if( mode == SYS_WAICMD ){	
		while( pgm_read_byte(&CSL_WAICMD_data[i]) != 0 ){
											/* ??? NULLは0か？文字列の終わりにNULLは配置されるか?	*/
			vram_txtbuf[i] = pgm_read_byte(&CSL_WAICMD_data[i]) - CG_OFFSET;
			vram_txt[i] = vram_txtbuf[i];
			i++;
			if( i >= VRAM_TXT_SIZE ){		/* ??? test	??? */
				break;
			}
		}
		vram_txtbuf[i] = 0xFF;
		vram_txt[i] = vram_txtbuf[i];
	}
	
	else if( mode == SYS_POLKA ){	
		while( pgm_read_byte(&CSL_NEGIFURI_data[i]) != 0 ){
											/* ??? NULLは0か？文字列の終わりにNULLは配置されるか?	*/
			vram_txtbuf[i] = pgm_read_byte(&CSL_NEGIFURI_data[i]) - CG_OFFSET;
			vram_txt[i] = vram_txtbuf[i];
			i++;
			if( i >= VRAM_TXT_SIZE ){		/* ??? test	??? */
				break;
			}
		}
		vram_txtbuf[i] = 0xFF;
		vram_txt[i] = vram_txtbuf[i];
	}
	
	
}

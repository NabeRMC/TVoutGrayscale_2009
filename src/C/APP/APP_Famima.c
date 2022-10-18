/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Famima.c
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

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	����		:
	����		:
				:
	�߂�l		:
	�������x��	:
*---------------------------------------------------------------------------*/
void APP_Famima( void )
{
	if( num_note <= 0xF0 ){
		if( num_note == 0 ){

			if( p_scl_tbl == 0 ){
				TCCR2A = ON_OC2B;
			}

			UB_TMP_data = pgm_read_byte(&SCL_famima[p_scl_tbl]);
			OCR2A = pgm_read_byte(&SCL_data[UB_TMP_data ]);
			num_note = pgm_read_byte(&SCLT_famima[p_scl_tbl]);

			if( num_note == 0xFF ){
				TCCR2A = CUT_OC2B;
			}

			p_scl_tbl++;
			num_note--;
		}
		else{
			num_note--;
		}
	}

}

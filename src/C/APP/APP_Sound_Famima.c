/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Sound_Famima.c
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
#include "defCSL.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	ê‡ñæ		:
	à¯êî		:
				:
	ñﬂÇËíl		:
	èàóùÉåÉxÉã	:
*---------------------------------------------------------------------------*/
void APP_Sound_Famima( void )
{
	if( UB_FAM_num_n <= 0xF0 ){
		if( UB_FAM_num_n == 0 ){

			TCCR2A = CUT_OC2B;
			f_Sound_on_req = 1;
			UB_TMP_data = pgm_read_byte(&SCL_famima[p_scl_tbl]);
			OCR2A = pgm_read_byte(&SCL_data[UB_TMP_data ]);
			UB_FAM_num_n = pgm_read_byte(&SCLT_famima[p_scl_tbl]);

			if( UB_FAM_num_n == 0xFF ){
				TCCR2A = CUT_OC2B;
				p_scl_tbl = 0;
				f_Sound_on_req = 0;
				UBmodeSYS = SYS_WAICMD;
				f_scroll_req = 0; 
				CSL_Set_test_data( SYS_WAICMD );
				
			}

			p_scl_tbl++;
			UB_FAM_num_n--;
		}
		else{
			UB_FAM_num_n--;
		}
	}

}


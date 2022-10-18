/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Sound_Polka.c
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
	説明		:
	引数		:
				:
	戻り値		:
	処理レベル	:
*---------------------------------------------------------------------------*/
void APP_Sound_Polka( void )
{
	if( UB_PLK_num_n <= 0xF0 ){
		if( UB_PLK_num_n == 0 ){
			
			TCCR2A = CUT_OC2B;
			f_Sound_on_req = 1;
			UB_TMP_data = pgm_read_byte(&SCL_polka[p_scl_tbl]);
			OCR2A = pgm_read_byte(&SCL_data[UB_TMP_data ]);
			UB_PLK_num_n = pgm_read_byte(&SCLT_polka[p_scl_tbl]);

			if( UB_PLK_num_n == 0xFF ){
				TCCR2A = CUT_OC2B;
				p_scl_tbl = 0;
				f_Sound_on_req = 0;
				UBmodeSYS = SYS_STBY;
				CSL_Set_bar_data();	/* ??? */
			}

			p_scl_tbl++;			/* 次のデータへ進める				*/
			UB_PLK_num_n--;

		}
		else{
			UB_PLK_num_n--;			/* 同じデータで時間のばす			*/

		}
	}

}


/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Sound_CETK.c
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
	����		:
	����		:
				:
	�߂�l		:
	�������x��	:
*---------------------------------------------------------------------------*/
void APP_Sound_CETK( void )
{
	if( UB_CETK_num_n <= 0xF0 ){
		if( UB_CETK_num_n == 0 ){
			
			TCCR2A = CUT_OC2B;
			f_Sound_on_req = 1;
			UB_TMP_data = pgm_read_byte(&SCL_CETK[p_scl_tbl]);
			OCR2A = pgm_read_byte(&SCL_data[UB_TMP_data ]);
			UB_CETK_num_n = pgm_read_byte(&SCLT_CETK[p_scl_tbl]);

			if( UB_CETK_num_n == 0xFF ){
				TCCR2A = CUT_OC2B;
				p_scl_tbl = 0;
				f_Sound_on_req = 0;
				UBmodeSYS = SYS_STBY;
			}

			p_scl_tbl++;			/* ���̃f�[�^�֐i�߂�				*/
			UB_CETK_num_n--;

		}
		else{
			UB_CETK_num_n--;		/* �����f�[�^�Ŏ��Ԃ̂΂�			*/

		}
	}

}


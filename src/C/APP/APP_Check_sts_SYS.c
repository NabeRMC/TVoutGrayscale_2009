/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Check_sts_SYS.c
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

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	����		:
	����		:
	�߂�l		:
	�������x��	:
*---------------------------------------------------------------------------*/
void APP_Check_sts_SYS( void )
{
	if( UBT_Change_CSL != 0 ){
		if( UBT_CheckSTBY == 0 ){			/* ��莞��dark�Ȃ�^�C�}0�ɂȂ�	*/
			UBmodeSYS = SYS_RESET_1;
			UBC_Stone = 0;
			UB_p_Stone = 0;
			p_scl_tbl = 0;
			UB_CETK_num_n = 0;				/* ���m�Ƃ̑���						*/
		}
	}
	
}

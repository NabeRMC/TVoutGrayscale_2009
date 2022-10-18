/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Check_sts_CRT.c
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
#include "defCRT.h"
#include "defCSL.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	à–¾		:
	ˆø”		:
	–ß‚è’l		:
	ˆ—ƒŒƒxƒ‹	:
*---------------------------------------------------------------------------*/
void APP_Check_sts_CRT( void )
{
	static	UB isGRP_H = 0;
	static	UB count_stsCRT = 0;
	static	UB UBmodeSYS_n;
	static	UB UBmodeSYS_1;
	
	UBmodeSYS_n = UBmodeSYS;
	
	if( UBmodeSYS_n != UBmodeSYS_1 ){
		switch( UBmodeSYS_n ){

			case SYS_RESET:	
				UBC_stsCRT_limit = CRT_RESET_COUNT;
				break;
			
			case SYS_STBY:	
				UBC_stsCRT_limit = CRT_STBY_COUNT;
				break;
			
			case SYS_WAICMD:	
				UBC_stsCRT_limit = CRT_WAICMD_COUNT;
				break;
			
			case SYS_POLKA:	
				UBC_stsCRT_limit = CRT_POLKA_COUNT;
				CSL_Clear_bar();
				
				break;
			
//			default:
			
		}
	}
	if( UBmodeSYS == SYS_WAICMD_1 ){
		if( f_cds_dark == 1 ){
			UB_grp_num = 1;
		}
		else{
			UB_grp_num = 0;
		}
	}
	else if( UBmodeCRT == CRT_STBY ){
		count_stsCRT++;
		
		if( count_stsCRT >= UBC_stsCRT_limit ){
			count_stsCRT = 0;
			isGRP_H = ~isGRP_H;
		}
		if( isGRP_H ){
			UB_grp_num = 1;
		}
		else{
			UB_grp_num = 0;
		}
	}
	
	UBmodeSYS_1 = UBmodeSYS_n;
	
}


/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: A_APP_ini.c
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
#define	APP_INCLUDE
#include "defSYS.h"
#include "defAPP.h"
#include "defCSL.h"


/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : APPèàóùÇ…î∫Ç§èâä˙âª
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void A_APP_Ini(void)
{
	/*	APP_blinkLED( BLK_LED_SET, BLK_LED_CYC_NOM );	*/
	UBcommand= BLK_LED_SET;
	UHcycleBlink = BLK_LED_CYC_NOM;
	UHcount_blink = 0;
	UHcount_blinkLMT = BLK_LED_CYC_NOM;
	isLED_ON = 0;
	
	UBmodeSYS = SYS_RESET;
	CSLmodeSYS_n = SYS_RESET;
	CSLmodeSYS_1 = SYS_RESET;
	UBmodeCRT = CRT_STBY;


	UBC_stsCRT_limit = CRT_STBY_COUNT;
	
	TCCR2A = CUT_OC2B;
	UB_FAM_num_n = 0xFF;						/* sound stop				*/
	UB_CETK_num_n = 0xFF;
	UB_PLK_num_n = 0xFF;
	p_scl_tbl = 0;
	UBC_wave_negi = 0;
	CSL_Clear_bar();
	
}



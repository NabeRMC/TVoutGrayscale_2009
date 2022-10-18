/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_blinkLED
	Content		: 動作確認用LED点滅処理	
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
#include "common.h"
#include "defAPP.h"
#include "defPort.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	説明		: 動作確認用LED点滅処理	
	引数		: UBcommand	
				: UHcycleBlink
	戻り値		: なし
	処理レベル	:
*---------------------------------------------------------------------------*/
void APP_blinkLED( UB UBcommand, UH UHcycleBlink )
{
 	static UH UHcount_blink = 0;
	static UH UHcount_blinkLMT = BLK_LED_CYC_NOM;
	static UB isLED_ON = 0;

 	if( UBcommand == BLK_LED_SET ){
		UHcount_blink = 0;
		UHcount_blinkLMT = UHcycleBlink;
	}
	else if( UBcommand == BLK_LED_NOM ){
		UHcount_blink++;

		if ( UHcount_blink >= UHcount_blinkLMT ) {
			UHcount_blink = 0;
			isLED_ON = ~isLED_ON;
		}
		if( isLED_ON ){
			P_LED1_ON;
		}
		else {
			P_LED1_OFF;
		}
	}

}


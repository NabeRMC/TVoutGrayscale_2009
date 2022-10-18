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
#include "defSYS.h"
#include "defAPP.h"
#include "defPort.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*--------------------------------------------------------------------------------
* Function : 
* Descr    : 
* Inputs   : 
* Outputs  : 
* Return   : 
			numeric	ASCII	CG1214k_o
			0		0x30	0x10
*-------------------------------------------------------------------------------*/
UB APP_htoa( UB hex )
{
	if( hex <= 0x09 ){
		return( hex + 0x10 );
	}
	else{
		return( hex + 0x17 );
	}
}
	

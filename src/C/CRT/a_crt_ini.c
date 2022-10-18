/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: A_CRT_Ini.c
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#define	CRT_INCLUDE			
#include "defCRT.h"
#include "defSYS.h"
#include "defAPP.h"

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : CRTコントロール処理関連の初期化
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void A_CRT_Ini( void )
{
	TCCR1A = CRT_TCCR1A;
	TCCR1B = CRT_TCCR1B;
	OCR1A  = CRT_OCR1A_HS;
	ICR1   = CRT_ICR1;
	
	UBmodeCRTtbl = MODE_CRT_GRP1;
//	UBmodeCRTtbl = MODE_CRT_DBG;

	UB_grp_num = 0;
	UH_AddressGRPdata = (UH)(&GRP_data);

}

/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: SYS_intCRT_ICF1.c
	Content		: ICF1äÑÇËçûÇ›	
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
#include "defCRT.h"
#include "defPort.h"
#include "defAPP.h"
#include <avr/interrupt.h>

/*	----------------------------------------------------
	-	function pointer								-
	-----------------------------------------------------	*/
void( *const TBL_int_icf1[MODE_CRT_N] )(void) = {
	
	CRT_icf1_DBG,			/* mode0	DEBUG								*/
	CRT_icf1_GRP160_120,	/* mode1	160*120	No.1						*/
	CRT_icf1_GRP160_120,	/* mode2	160*120	No.2						*/
	CRT_icf1_DBG,			/* mode3	Menu								*/
	CRT_icf1_DBG,			/* mode4	DEBUG								*/
};

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : interrupt ICF1
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
ISR (TIMER1_CAPT_vect)
//void SYS_intCRT_icf1( void )
{
//	P_DBG1_ON;
	UH_TCNT1 = TCNT1;
	(*TBL_int_icf1[UBmodeCRTtbl])();

}



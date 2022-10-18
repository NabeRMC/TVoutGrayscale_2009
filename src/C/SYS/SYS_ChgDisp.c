/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: SYS_ChgDisp.c
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
#define	SYS_INCLUDE
#include "defSYS.h"
#include "defPort.h"


/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : GRP��CSL�̃��[�h�؂芷��
* Descr	   : 
* Inputs   : DSP_GRP:GRaPhic , DSP_CSL:ConSoLe
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void SYS_ChgDisp( UB mode )
{
	if( mode == DSP_GRP ){												
		DDRC 	= GRP_DDRC;			/* PC0,1,2,3��out,						*/
		PORTC	= GRP_PORTD;
		DDRD 	= GRP_DDRD;			/* PD1��Hiz								*/
		PORTD	= GRP_PORTD;		/*										*/
	}
	else if( mode == DSP_CSL ){
		DDRC 	= CSL_DDRC;			/* PC0,1,3��out��"L",PC2��Hiz			*/
		PORTC	= CSL_PORTC;
		DDRD	= CSL_DDRD;			/* PD1��TXDout							*/
		PORTD	= CSL_PORTD;
	}
}



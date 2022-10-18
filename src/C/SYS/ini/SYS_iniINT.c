/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: SYS_iniINT.c
	Content		: Arduino Duemilanove
	Version		: 0.0
	CPU board	: 
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include "defSYS.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : initialize interruput
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void SYS_iniINT( void )
{
	TIMSK1 = INI_TIMSK1;

}

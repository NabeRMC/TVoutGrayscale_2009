/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: defCSL.h
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: xxx
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
#ifdef		CSL_INCLUDE
#define		CSL_EXT 
#else
#define		CSL_EXT	extern
#endif

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include	<avr/pgmspace.h>
#ifndef		COMMON_H
#include	"common.h"
#endif

#ifndef		DEFPORT_H
#include	"defPort.h"
#endif

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/
extern void A_CSL_Ini( void );
extern void CSL_Set_test_data( UB );
extern void CSL_Clear( void );
extern void CSL_Scroll( void );
extern void CSL_Blink( void );
extern void CSL_Set_bar_data( void );
extern void CSL_Clear_bar( void );


/*==========================================================================*/
/*	DEFINE																	*/
/*==========================================================================*/
#define	CG_OFFSET		0x20
#define	CSL_CHAR_MAX	8
#define	CSL_CHAR_BUF_MAX	20

/*==========================================================================*/
/*	RAM PUBLIC																*/
/*==========================================================================*/



/*==============================================================================*/
/* DATA public																	*/
/*==============================================================================*/

/* ----- ifdef -------------------------------------------------------------*/
#ifdef	CSL_INCLUDE

const UB CSL_STBY_data[20] PROGMEM 
/*  	 123456789012345678901234567890	*/
	= { "NicoTECH MTM04 ~" };	/* 20•¶Žš‚É–ž‚½‚È‚¢‚Æ‚±‚ë‚Í0x00‚ª“ü‚é	*/
	
const UB CSL_WAICMD_data[20] PROGMEM 
/*  	 123456789012345678901234567890	*/
	= { "Command?~ " };			/* 20•¶Žš‚É–ž‚½‚È‚¢‚Æ‚±‚ë‚Í0x00‚ª“ü‚é	*/

const UB CSL_NEGIFURI_data[20] PROGMEM 
/*  	 123456789012345678901234567890	*/
	= { "Negi-Furi  ~ " };		/* 20•¶Žš‚É–ž‚½‚È‚¢‚Æ‚±‚ë‚Í0x00‚ª“ü‚é	*/


/* ----- else --------------------------------------------------------------*/
#else

extern const UB CSL_STBY_data[20];
extern const UB	CSL_WAICMD_data[20];
extern const UB	CSL_NEGIFURI_data[20];

/* ----- endif -------------------------------------------------------------*/
#endif




/*----------------------------------------------------------------------------

	1/16MHz *2 = 62.5ns*2 = 125ns
	125ns + 8 = 1us/char
	(50us)/(1us/char) = 50char
	


----------------------------------------------------------------------------*/



/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: SYS_asy.c
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
#include "defSYS.h"
#include "defAPP.h"
#include "defCRT.h"
#include "defCSL.h"
#include <avr/interrupt.h>

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/
void SYS_asy( void );

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
* Function : 
* Descr	   : 
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void SYS_asy( void )
{
	static UB	UBCT_16_5ms = 0;
	
	if( f_SYS_16500us_req == 1 ){
		f_SYS_16500us_req = 0;
		UBCT_16_5ms++;
		
//		APP_Check_cds_in();			/* êÇíºìØä˙èàóù(int.ÇÃíÜ)ÇÃÇ∆Ç±ÇÎÇ÷à⁄ìÆ		*/
		
			if( f_Sound_on_req == 1 ){
				TCCR2A = ON_OC2B;
				f_Sound_on_req = 0;
			}
		
		if( ( UBCT_16_5ms %2 ) == 0 ){		/* --- job33ms ---					*/
			APP_Sound_Polka();
		}
	
		if( ( UBCT_16_5ms %12 ) == 0 ){		/* --- job200ms ---					*/
			APP_Check_sts_SYS();
			APP_Check_sts_CRT();
			APP_Sound_Famima();
			APP_Sound_CETK();
		}
	
		if( ( UBCT_16_5ms %30 ) == 0 ){		/* --- job500ms ---					*/
			UH_Tclock++;
			
			APP_Set_CSL();
			
			if( f_sys_mon == 0 ){
				if( f_scroll_req == 1 ){
					CSL_Scroll();
				}	
				else if( f_blink_req == 1 ){
					CSL_Blink();
				}
			}
			if( (f_mon_req == 1)|| (f_sys_mon == 1) ){
				APP_Display_ram();
			}
			
		}
	
		if( UBCT_16_5ms == 60 ){			/* --- job1sec  ---					*/
//			UH_Tclock++;
		}
	}

}


/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Set_CSL.c
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
#include "defCSL.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	ê‡ñæ		:
	à¯êî		:
	ñﬂÇËíl		:
	èàóùÉåÉxÉã	:
*---------------------------------------------------------------------------*/
void APP_Set_CSL( void )
{
	CSLmodeSYS_n = UBmodeSYS;
	
	if( UBT_Change_CSL == 0 ){
		
		if( f_done_CSL == 0 ){
			UB_isCSL_MON = ~UB_isCSL_MON;
		
			if( UB_isCSL_MON ){
				f_sys_mon = 1;
			}
			else {
				f_sys_mon = 0;
			}
		}
		
		A_APP_Ini();
		f_done_CSL = 1;
		
	}
	else if( CSLmodeSYS_n != CSLmodeSYS_1 ){
		switch( CSLmodeSYS_n ){

			case SYS_RESET:	
				CSL_Set_test_data( SYS_STBY );
				f_scroll_req = 0; f_mon_req = 0; f_blink_req = 0;
				break;
			
			case SYS_STBY:	
				CSL_Set_test_data( SYS_STBY );		/*	MTM04 Nico-TECH~	*/
				f_scroll_req = 1; f_mon_req = 0; f_blink_req = 0;
				break;
			
			case SYS_WAICMD:	
				CSL_Set_test_data( SYS_WAICMD );	/*	Command?			*/
				f_scroll_req = 0; f_mon_req = 0; f_blink_req = 1;
				break;
			
			case SYS_POLKA:	
				CSL_Set_test_data( SYS_POLKA );		/*	Negi-Furi			*/
				f_scroll_req = 0; f_mon_req = 0; f_blink_req = 1;
				break;
			
//			default:
			
		}
	}

	CSLmodeSYS_1 = CSLmodeSYS_n;
}


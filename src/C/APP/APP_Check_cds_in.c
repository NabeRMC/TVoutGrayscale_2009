/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: APP_Check_cds_in.c
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
#include "defCRT.h"

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/

/*==========================================================================*/
/*	Program																	*/
/*==========================================================================*/
/*----------------------------------------------------------------------------
	説明		:
	引数		:
	戻り値		:
	処理レベル	:
					スクロール中に割り込むことを考えることを考慮すること
*---------------------------------------------------------------------------*/
void APP_Check_cds_in( void )
{
	static UB f_cds_dark_1;
														/* --- 明るい --- 	*/
	if( (UB_AD_cds_1 < CDSlight) && (UB_AD_cds < CDSlight) ){	
		f_cds_dark = 0;
		UBT_CheckSTBY = T_CHECKSTBY;
		UBT_Change_CSL = T_CHG_CSL;
		f_done_CSL = 0;
		
		if( (UBmodeSYS & 0x0F) != 1 ){
			TCCR2A = CUT_OC2B;
		}
		
		if( UBmodeSYS == SYS_STBY ){

			if( f_CountStone ==1 ){				/* 暗くなって明るくなった	*/
				f_CountStone = 0;
				UB_Mes_Stone[UB_p_Stone] = UBC_Stone;
				UBC_Stone = 0;
				UB_p_Stone++;
				if( UB_p_Stone == 8 ){
					UB_p_Stone = 0;
					UB_FAM_num_n = 0;			/* Famima					*/
					UBmodeSYS = SYS_STBY_1;
				}
			}
		}

		else if( UBmodeSYS == SYS_WAICMD ){
			
			if( f_CountStone ==1 ){				/* 暗くなって明るくなった	*/
				f_CountStone = 0;
				UB_Mes_Stone[UB_p_Stone] = UBC_Stone;
				UBC_Stone = 0;
				UB_p_Stone++;

				if( UB_p_Stone == 4 ){
					UB_p_Stone = 0;
					UB_PLK_num_n = 0;			/* polka					*/
					UBmodeSYS = SYS_WAICMD_1;
					UBC_wave_negi = 0;
					CSL_Clear_bar();
				}

			}
/*--------------------------------------------------------------------------
			else{									連続明るい				
				UBC_separetae++;
				
				if( f_Check_key_done == 1 ){
					if( UBC_separate > SYS_SEP ){
						f_Check_kyein = 1;
						f_Check_key_done = 0;
					}
				}
			}
----------------------------------------------------------------------------*/
		}
		
	}
														/* --- 暗い ---		*/
	else if( (UB_AD_cds_1 > CDSdark) && (UB_AD_cds > CDSdark) ){
		f_cds_dark = 1;
		if( UBT_CheckSTBY != 0 ){
			UBT_CheckSTBY--;
		}
		if( UBT_Change_CSL != 0 ){
			UBT_Change_CSL--;
		}
		
		
		
		if( (UBmodeSYS & 0x0F) != 1 ){
			TCCR2A = ON_OC2B;
		}
		
		if( (UBmodeSYS == SYS_STBY) || (UBmodeSYS == SYS_WAICMD) ){

			f_CountStone = 1;
			UBC_Stone++;			/* 短点 時間測定用						*/
		}
	
	}
	
	
	if( (f_cds_dark_1 == 0)&&(f_cds_dark==1) ){
		UBC_wave_negi++;
		if( UBC_wave_negi > 56 ){
			UBC_wave_negi = 56;
		}
		vram_line[96+UBC_wave_negi] = 0x0F;
	}
	
	UB_AD_cds_1 = UB_AD_cds;
	f_cds_dark_1 = f_cds_dark;
}


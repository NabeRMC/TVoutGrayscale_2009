/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: CRT_Icf1_GRP160_120.c
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/09/xx
*****************************************************************************/

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include "defCRT.h"
#include "defSYS.h"
#include "defPort.h"
#include "defAPP.h"

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
void CRT_icf1_GRP160_120( void )
{								/* 割り込みから関数ポインタで飛ばしている	*/
	UB_DLY_icf1 = ( UB )( UH_TCNT1 & 0xFF );
	CRT_FitDelay( UB_DLY_icf1 );	/* 割り込み遅延ばらつきの合わせ込み		*/
	
	UB_h_line++;

	if( UB_h_line == V_SYNC_START ){	/* 垂直同期パルスタイミング開始		*/
		OCR1A  = CRT_OCR1A_VS;
		TCCR1A = CRT_TCCR1A;
		
		P_DBG1_ON;
		
		f_SYS_16500us_req = 1;			/* 16.5ms処理の要求					*/
		UH_AddressGRPdata =(UH)( &GRP_data);	/* 画像データ先頭アドレス	*/
		UB_csl_line = 0;						/* 文字行カウンタリセット	*/
		UB_AD_cds = ADCH;
		
		APP_Check_cds_in();

	}
	else if( UB_h_line == V_SYNC_END ){	/* 垂直同期パルスタイミング終了		*/
		OCR1A = CRT_OCR1A_HS;
		UB_thin_n++;
		UB_thin_n &= ( 0x01 );
	}
										/* --- 画面表示枠内 ---				*/
	if( (UB_h_line >= V_BLANK) && (UB_h_line <= H_LINE_END_GRP) ){
		
		if( UB_grp_num == 0 ){
			CRT_OutDataL( UH_AddressGRPdata );
		}
		else{
			CRT_OutDataH( UH_AddressGRPdata );
		}
		PORTC = 0x00;
		
		if( UB_h_line % 2 ){
			UH_AddressGRPdata += H_DOT_N;
		}
	}

	
	/* ----- 文字表示 ------------------------------------------------------*/
	
	if( (UB_h_line >= H_LINE_ST_CSL ) && (UB_h_line <= H_LINE_END_CSL) ){

		UB_cg_line = UB_csl_line % 10;		/* 0 -9	 line					*/

		
		if( UB_thin_n == 0 ){
			
			if( UB_cg_line %2 == 0 ){		/* thin_n=0で偶数ライン			*/
//				P_DBG1_ON;
				CRT_Set_VramLine();
//				P_DBG1_OFF;
			}
			else{							/* thin_n=0で奇数ライン			*/
				UH_AddressGRPdata =(UH)( &vram_line );
				CRT_OutDataCLS( UH_AddressGRPdata );		
				PORTC = 0x00;
			}
		}
		
		else{
			if( UB_cg_line %2 == 0 ){		/* thin_n=1で偶数ライン			*/
				UH_AddressGRPdata =(UH)( &vram_line );
				CRT_OutDataCLS( UH_AddressGRPdata );		
				PORTC = 0x00;				
			}
			else{							/* thin_n=1で奇数ライン			*/
				CRT_Set_VramLine();
			}
		}
	
		UB_csl_line++;
	}
//	P_DBG1_OFF;

}


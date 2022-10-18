/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: CRT_Icf1_DBG.c
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
void CRT_icf1_DBG( void )
{								/* 割り込みから関数ポインタで飛ばしている	*/
	UB_DLY_icf1 = ( UB )( UH_TCNT1 & 0xFF );
	CRT_FitDelay( UB_DLY_icf1 );	/* 割り込み遅延ばらつきの合わせ込み		*/

//	if( UH_h_line % 2 == 0 ){			/* !!! for Test						*/
//		asm volatile("nop");			/* ジッタ出る						*/
//		asm volatile("nop");
//		asm volatile("nop");
//	}
	
//	P_SYNC_ON;							/* OC1Aのパルス立下りから3.6us		*/
	
	UH_h_line++;
	if( UH_h_line == H_LINE_END ){
		UH_h_line = 0;
	}
	
	if( UH_h_line == V_SYNC_START ){	/* 垂直同期パルスタイミング開始		*/
		OCR1A  = CRT_OCR1A_VS;
		f_SYS_16500us_req = 1;			/* 16.5ms処理の要求					*/
		TCCR1A = CRT_TCCR1A;
		P_DBG1_OFF;
	}
	else if( UH_h_line == V_SYNC_END ){	/* 垂直同期パルスタイミング終了		*/
		OCR1A = CRT_OCR1A_HS;
//		TCCR1A = CRT_TCCR1A_P;
	}
	
	if( UH_h_line == V_BLANK ){
		UH_AddressGRPdata =(UH)( &TEST_data);	/* 画像データ先頭アドレス	*/
	}

//	if( UH_h_line % 2 == 0 ){			/* !!! for Test						*/
//		asm volatile("nop");			/* ジッタ出る						*/
//		asm volatile("nop");
//		asm volatile("nop");
//	}
										/* --- 画面表示枠内 ---				*/
	if( (UH_h_line >= V_BLANK) && (UH_h_line <= H_LINE_END_GRP) ){
		

		
//		if( UH_h_line % 2 == 0 ){		/* !!! for Test						*/
//			asm volatile("nop");		/* 当然ジッタは出る					*/
//			asm volatile("nop");
//			asm volatile("nop");
//		}
			
			CRT_OutDataL( UH_AddressGRPdata );
			PORTC = 0x00;
	}


}


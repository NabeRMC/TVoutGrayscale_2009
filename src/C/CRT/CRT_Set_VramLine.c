/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: CRT_Set_Vram_line.c
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/10/xx
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
* Descr	   : 16文字 --> 8data/1文字 *16 = 128
*          : 50us/128 /62.5ns = 6.25
* Inputs   : 
* Outputs  : 
* Return   : 
*---------------------------------------------------------------------------*/
void CRT_Set_VramLine(void)
{
				/* p_vram:現在行の左端のvram_txtの位置						*/
				/* cg_code > 20H なのでvram_txt[]はあらかじめ20Hを減算		*/
				/* 72はcg_codeが1文字あたり6×9	!baka! rockは54				*/
	UB	i;
		
	for( i=0; i<=7; i++ ){												/* !!! for文をやめるとか				*/
		UH_cg_ofs_add = (UH)(vram_txt[i]* 54) + (UH)( UB_cg_line *6 );	/* !!! UB_cg_line *6 はforの外へ出せる	*/
		UH_AddressCG = (UH)(&cg_code) + UH_cg_ofs_add; 
		UH_AddressVr = (UH)( &vram_line );
		UH_AddressVr = UH_AddressVr +( 6*i );							/* !!! 上の行と合わせたら				*/
	
		CRT_SetDataVrL( UH_AddressCG, UH_AddressVr );

	}

//		UH_cg_ofs_add = (UH)(vram_txt[0]* 54) + (UH)( UB_cg_line *6 );
//		UH_AddressCG = (UH)(&cg_code) + UH_cg_ofs_add; 
//		UH_AddressVr = (UH)( &vram_line );
//		CRT_SetDataVrL( UH_AddressCG, UH_AddressVr );
//
//		UH_cg_ofs_add = (UH)(vram_txt[1]* 54) + (UH)( UB_cg_line *6 );
//		UH_AddressCG = (UH)(&cg_code) + UH_cg_ofs_add; 
//		UH_AddressVr = (UH)( &vram_line );
//		UH_AddressVr += 6;
//		CRT_SetDataVrL( UH_AddressCG, UH_AddressVr );
//
//		UH_cg_ofs_add = (UH)(vram_txt[2]* 54) + (UH)( UB_cg_line *6 );
//		UH_AddressCG = (UH)(&cg_code) + UH_cg_ofs_add; 
//		UH_AddressVr = (UH)( &vram_line );
//		UH_AddressVr += 12;
//		CRT_SetDataVrL( UH_AddressCG, UH_AddressVr );
			
	
	
}

	

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
{								/* ���荞�݂���֐��|�C���^�Ŕ�΂��Ă���	*/
	UB_DLY_icf1 = ( UB )( UH_TCNT1 & 0xFF );
	CRT_FitDelay( UB_DLY_icf1 );	/* ���荞�ݒx���΂���̍��킹����		*/
	
	UB_h_line++;

	if( UB_h_line == V_SYNC_START ){	/* ���������p���X�^�C�~���O�J�n		*/
		OCR1A  = CRT_OCR1A_VS;
		TCCR1A = CRT_TCCR1A;
		
		P_DBG1_ON;
		
		f_SYS_16500us_req = 1;			/* 16.5ms�����̗v��					*/
		UH_AddressGRPdata =(UH)( &GRP_data);	/* �摜�f�[�^�擪�A�h���X	*/
		UB_csl_line = 0;						/* �����s�J�E���^���Z�b�g	*/
		UB_AD_cds = ADCH;
		
		APP_Check_cds_in();

	}
	else if( UB_h_line == V_SYNC_END ){	/* ���������p���X�^�C�~���O�I��		*/
		OCR1A = CRT_OCR1A_HS;
		UB_thin_n++;
		UB_thin_n &= ( 0x01 );
	}
										/* --- ��ʕ\���g�� ---				*/
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

	
	/* ----- �����\�� ------------------------------------------------------*/
	
	if( (UB_h_line >= H_LINE_ST_CSL ) && (UB_h_line <= H_LINE_END_CSL) ){

		UB_cg_line = UB_csl_line % 10;		/* 0 -9	 line					*/

		
		if( UB_thin_n == 0 ){
			
			if( UB_cg_line %2 == 0 ){		/* thin_n=0�ŋ������C��			*/
//				P_DBG1_ON;
				CRT_Set_VramLine();
//				P_DBG1_OFF;
			}
			else{							/* thin_n=0�Ŋ���C��			*/
				UH_AddressGRPdata =(UH)( &vram_line );
				CRT_OutDataCLS( UH_AddressGRPdata );		
				PORTC = 0x00;
			}
		}
		
		else{
			if( UB_cg_line %2 == 0 ){		/* thin_n=1�ŋ������C��			*/
				UH_AddressGRPdata =(UH)( &vram_line );
				CRT_OutDataCLS( UH_AddressGRPdata );		
				PORTC = 0x00;				
			}
			else{							/* thin_n=1�Ŋ���C��			*/
				CRT_Set_VramLine();
			}
		}
	
		UB_csl_line++;
	}
//	P_DBG1_OFF;

}


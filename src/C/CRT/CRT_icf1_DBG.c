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
{								/* ���荞�݂���֐��|�C���^�Ŕ�΂��Ă���	*/
	UB_DLY_icf1 = ( UB )( UH_TCNT1 & 0xFF );
	CRT_FitDelay( UB_DLY_icf1 );	/* ���荞�ݒx���΂���̍��킹����		*/

//	if( UH_h_line % 2 == 0 ){			/* !!! for Test						*/
//		asm volatile("nop");			/* �W�b�^�o��						*/
//		asm volatile("nop");
//		asm volatile("nop");
//	}
	
//	P_SYNC_ON;							/* OC1A�̃p���X�����肩��3.6us		*/
	
	UH_h_line++;
	if( UH_h_line == H_LINE_END ){
		UH_h_line = 0;
	}
	
	if( UH_h_line == V_SYNC_START ){	/* ���������p���X�^�C�~���O�J�n		*/
		OCR1A  = CRT_OCR1A_VS;
		f_SYS_16500us_req = 1;			/* 16.5ms�����̗v��					*/
		TCCR1A = CRT_TCCR1A;
		P_DBG1_OFF;
	}
	else if( UH_h_line == V_SYNC_END ){	/* ���������p���X�^�C�~���O�I��		*/
		OCR1A = CRT_OCR1A_HS;
//		TCCR1A = CRT_TCCR1A_P;
	}
	
	if( UH_h_line == V_BLANK ){
		UH_AddressGRPdata =(UH)( &TEST_data);	/* �摜�f�[�^�擪�A�h���X	*/
	}

//	if( UH_h_line % 2 == 0 ){			/* !!! for Test						*/
//		asm volatile("nop");			/* �W�b�^�o��						*/
//		asm volatile("nop");
//		asm volatile("nop");
//	}
										/* --- ��ʕ\���g�� ---				*/
	if( (UH_h_line >= V_BLANK) && (UH_h_line <= H_LINE_END_GRP) ){
		

		
//		if( UH_h_line % 2 == 0 ){		/* !!! for Test						*/
//			asm volatile("nop");		/* ���R�W�b�^�͏o��					*/
//			asm volatile("nop");
//			asm volatile("nop");
//		}
			
			CRT_OutDataL( UH_AddressGRPdata );
			PORTC = 0x00;
	}


}


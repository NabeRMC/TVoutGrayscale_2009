/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: SYS_def.h
	Content		: 
	Version		: 0.0
	CPU board	: xxx
	Compiler	: xxx
	OS			: xxx
	Programmer	: Meow
	Copyleft (c)2008 Meow
	History		:2008/09/xx
*****************************************************************************/
#define		SYS_def

#ifdef		SYS_INCLUDE
#define		SYS_EXT 
#else
#define		SYS_EXT	extern
#endif

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#ifndef		COMMON_H
#include	"common.h"
#endif


/*==========================================================================*/
/*	DEFINE																	*/
/*==========================================================================*/
#define	LED_ON			1
#define	LED_OFF			0

#define	LOW				0
#define	HIGH			1

#define	START_TM		1
#define	STOP_TM			0
#define	UP_TM			1
#define DOWN_TM			0



#define	DSP_GRP			1
#define	DSP_CSL			2

/* ----- interrupt ---------------------------------------------------------*/
#define	INI_TIMSK1		0x20	/* enable ICE1					0010_0000B	*/

/* ----- USART -------------------------------------------------------------
	UBRR0 	= fosc/2*BAUD -1 = 16MHz/2*BAUD -1 = 8MHz/BAUD -1
	at BAUD = 2	
	UBRR0 = 8MHz/(2-1) = 8MHz -> 0.125us
	0.125us*9bit*10=11.25us
----------------------------------------------------------------------------*/
#define	INI_UBRR0		2

/* ----- ADC ---------------------------------------------------------------*/
							/* Arduino AREF-OPEN,AVCC=VCC					*/
#define	INI_ADMUX	0x65	/* AVCC, left move, ADC5			0100_0101B	*/
#define	INI_ADCSRB	0x40	/* MPX enable continous conv.		-1--_000B	*/
#define	INI_ADCSRA	0xF5	/* enable, start, Auto ,clear, disable,CK/16	*/
							/*									1111_0101B	*/
#define	INI_DIDR0	0x20	/* Digital Input Disable Register	0010_000B	*/



/* --- Timmer2 -------------------------------------------------------------*/
#define	INI_TCCR2A	0x12	/* OC2A-cut,OC2B-toggle out,CTC 	0001_--10B	*/
#define	ON_OC2B		INI_TCCR2A
#define	CUT_OC2B	0x02	/* OC2A-cut,OC2B-cut,       CTC 	0000_--10B	*/
#define	INI_TCCR2B	0x05	/* CTC, clkT2S/128					00--_0101B	*/
#define	INI_OCR2A	238		/*												*/
#define	INI_OCR2B	0		/*												*/


/* ---------------------------------------------------------------------------
 -- PWM2 --> CTC mode、Sound out -> OC2B  --

	WGM22-0 = 010
	TCNT2 == OCR2AでTCNT2 <- 0
	COM2A1-0 = 01,DDR_OC2A = 1
	交互動作
	focnx = fclk_I/O/( 2*N*(1+OCR2x) )
	
	
	fclk_IO = 16MHz
	focnx = 16MHz/(2N+2OCR2x)
	2N+2OCR2x = 16MHz/focnx
	2OCR2 = 16MHz/focnx - 2N
	OCR2 = 8MHz/focnx -N
	N=1なら
	OCR0 = 8MHz/focnx -1
	261Hz時
	OCR0 = 8000000Hz/261Hz -1 = 30651
	Nは1,8,32,64,128,256,1024から選択できる
	30651/256=119
	N=128とする。
	OCR2 = 8MHz/focnx -N
	OCR2 = 8MHz/focnx -128
	
	
	16MHz/256 = 62500Hz
	62500Hz/523Hz = 119.5
	
	focnx = fclk_I/O/( 2*N*(1+OCR2x) )
	N=128とする
	
	focnx = fclkIO/( 256+256*OCR2x )
	256+256*OCR2x = fclkIO/focnx
	OCR2x 	= (fclkIO/focnx - 256) /256
			= (16MHZ/focnx -256)/256
	
	523Hz : (16MHz/523Hz -256)/256 = 118
	261Hz : (16MHz/261Hz -256)/256 = 238
	
 【実測】
	238 - 260.4Hz
	
	PortとPWMの切り替えはCOM2B1,COM2B0で
	
OCR2x = (16MHz/focnx -256)/256
 	ド		261.62Hz			237.89
	レ		293.66				
	ミ		329.62
	ファ	349.22
	ソ		391.99
	ラ		440
	シ		493.88
	ド		523.25				58.72

----------------------------------------------------------------------------*/

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/
extern void A_SYS_Ini( void );
extern void SYS_iniCPU( void );
extern void SYS_iniPort( void );
extern void SYS_iniWDT( void );
extern void SYS_iniUSART( void );
extern void SYS_iniINT( void );
extern void SYS_asy( void );
extern void SYS_iniADC( void );
extern void SYS_iniPWM2( void );


/*==========================================================================*/
/*	RAM PUBLIC																*/
/*==========================================================================*/
SYS_EXT	UB	f_SYS_16500us_req;
SYS_EXT	UB	UBCT_500ms;
SYS_EXT	UH	UH_TCNT1;
SYS_EXT	UB	UB_DLY_icf1;
SYS_EXT	UB	UB_DLY_icf1_BUF;



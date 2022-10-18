/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: defPort.h
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: xxx
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
#define		DEFPORT_H


/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#ifndef		COMMON_H
#include	"common.h"
#endif

/*==========================================================================*/
/*	DEFINE																	*/
/*==========================================================================*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	・プルアップありにするのには入力モードにしてデータ"1"を書く
				I/O	pullup
	Port B		----------------------------------------
		PB_5	out	w/o			LED			Port
		PB_4	in	
		PB_3	in	
		PB_2	in	
		PB_1	out				Sync_Out	OC1A
		PB_0	out	w/o			//Sync_Out	Port

	Port C		----------------------------------------
		PC_5					Illumi.		ADC5
		PC_4	in		
		PC_3	out/Hz	w/o		CRT_Sig_A3	Port
		PC_2	out/Hz	w/o		CRT_Sig_A2	Port
		PC_1	out/Hz	w/o		CRT_Sig_A1	Port
		PC_0	out/Hz	w/o		CRT_Sig_A0	Port

	Port D		----------------------------------------
		PD_7	HiZ/out	w/o		CRT_Sig_D1	Port
		PD_6	HiZ/out	w/o		CRT_Sig_D0	Port
		PD_5	HiZ/out	w/o		CRT_Sig_C1	Port
		PD_4	HiZ/out	w/o		CRT_Sig_C0	Port
		PD_3	out				Sound_Out	OC2B
		PD_2	out		w/o		Debug Port	Port
		PD_1	Hz/out	w/o		CSL_out		Port/TXD
		PD_0	in	


++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define P_LED1_ON		asm volatile("cbi 0x05,5"::)	/* PORTB.5			*/
#define P_LED1_OFF		asm volatile("sbi 0x05,5"::)
#define	P_SYNC_ON		asm volatile("cbi 0x05,1"::)	/* PORTB.1			*/
#define	P_SYNC_OFF		asm volatile("sbi 0x05,1"::)
//#define	P_SYNC_ON		asm volatile("cbi 0x05,0"::)	/* PORTB.0			*/
//#define	P_SYNC_OFF		asm volatile("sbi 0x05,0"::)
#define P_DBG1_ON		asm volatile("cbi 0x0B,2"::)	/* PORTD.2			*/
#define	P_DBG1_OFF		asm volatile("sbi 0x0B,2"::)


/*	--- pullup -------------------------------------------------------------
	PUD PullUp Disable	initial Value = 0 -> pull up enable
	the PUD bit in the MCUCR Register can be set to disable all pull-ups 
	in all ports.
	------------------------------------------------------------------------*/
/* --- in/out/data ---------------------------------------------------------*/
#define	INI_DDRB	0x23		/*								0010_0011B	*/
#define	INI_PORTB	0x00
#define	INI_DDRC	0x0F		/*								0000_1111B	*/
#define	INI_PORTC	0x00
#define	INI_DDRD	0x0C		/*								0000_1100B	*/
#define	INI_PORTD	0x00

#define	GRP_DDRC	0x0F		/*								0000_1111B	*/
#define	GRP_PORTC	0x00		/*								0000_0000B	*/
#define	GRP_DDRD	0x04		/*	PD1-Hiz						0000_0100B	*/
#define	GRP_PORTD	0x00		/*								0000_0000B	*/
#define	CSL_DDRC	0x0B		/*	0,1,3-out,2-Hiz				0000_1011B	*/
#define	CSL_PORTC	0x00		/*								0000_0000B	*/
#define	CSL_DDRD	0x06		/*	PD1-out						0000_0110B	*/
#define	CSL_PORTD	0x00		/*								0000_0000B	*/


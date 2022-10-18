/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: defCRT.h
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: xxx
	OS			: none
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
#ifdef		CRT_INCLUDE
#define		CRT_EXT 
#else
#define		CRT_EXT	extern
#endif

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
//#include	<avr/pgmspace.h>
#ifndef		COMMON_H
#include	"common.h"
#endif

#ifndef		DEFPORT_H
#include	"defPort.h"
#endif

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/
extern void A_CRT_Ini( void );
extern void CRT_icf1_DBG( void );
extern void CRT_icf1_GRP160_120( void );
extern void CRT_icf1_MNU( void );
extern void CRT_FitDelay( UB );
extern void CRT_OutDataL( UH );
extern void CRT_OutDataH( UH );
extern void CRT_OutDataCLS( UH );
extern void CRT_SetDataVrL( UH, UH );
extern void CRT_Set_VramLine( void );


/*==========================================================================*/
/*	DEFINE																	*/
/*==========================================================================*/
#define	CRT_TCCR1A		0xC2		/* inv.,fast PWM			1100_xx10B	*/
#define	CRT_TCCR1A_P	0x02		/* cut OC1-normal Port out	0000_xx10B	*/
#define	CRT_TCCR1B		0x19		/* non divide 				xx-1_1001B	*/
									/* WGM 13 12 11 10						*/
									/*      1  1  1  0 - 高速PWM			*/
#define	CRT_TCCR1C		0x00		/* initial value			00--_----B	*/
#define	CRT_TCNT1		0x0000		/* initial value  0000_0000_0000_0000B	*/
#define	CRT_OCR1A_HS	75			/* (1/16MHz)×75 = 4.6875us				*/
#define	CRT_OCR1A_VS	(1017- 75)
#define	CRT_OCR1B		0x0000		/* initial value  0000_0000_0000_0000B	*/
#define	CRT_ICR1		1017		/* (1/16MHz) × (1017+1) = 63.625us		*/
#define	CRT_TIMSK1		0x00		/* initial value			--0-_-000B	*/

/* 処理時間が足らない														*/
/*	8bitマイコンのAVRなので「 H_ 」は無理やり255以内にしてしまおう			*/
#define V_SYNC_START	2						/*	  2						*/
#define V_SYNC_END		5						/*	  5						*/
#define V_BLANK			6						/*	  6						*/
#define	H_LINE_END_GRP	( 120*2 +V_BLANK -1 )	/*	246	+ 同じだと処理が	*/
#define	H_LINE_ST_CSL	( H_LINE_END_GRP +1 )	/*  247	+ 間に合わない		*/
#define	H_LINE_END_CSL	( H_LINE_ST_CSL  +9 )	/*	255						*/
#define H_LINE_END		255						/*	255						*/

//#define	H_LINE_END_GRP	( 120*2 +V_BLANK )		/*	248					*/
//#define	H_LINE_ST_CSL	( H_LINE_END_GRP +2 )	/*  250					*/
//#define	H_LINE_END_CSL	( H_LINE_ST_CSL +7 )	/*	257					*/
//#define H_LINE_END		264						/*	264					*/

#define	CLS_LINE_END			1				/* とりあえず文字は1行		*/

#define COLUMN_MAX		14
#define LINE_MAX		16
#define	VRAM_TXT_SIZE	20

#define	H_DOT_N			160


/*==========================================================================*/
/*	RAM PUBLIC																*/
/*==========================================================================*/
CRT_EXT	UB	UB_grp_num;
CRT_EXT UH	UH_AddressGRPdata;
CRT_EXT	UH	UH_AddressCG;
CRT_EXT UH	UH_AddressVr;
CRT_EXT UH	UH_h_line;
CRT_EXT UB	UB_h_line;
CRT_EXT	UB	UB_csl_line;	/* 文字表示用の行数カウント						*/
CRT_EXT	UB	UB_char_line;	/* 0 -	19		縦20行							*/
CRT_EXT	UB	UB_cg_line;		/* 0 -	9		CG (5+3)×7bit	行間 3行		*/

CRT_EXT	UB	UB_thin_n;		/* 垂直同期毎にカウントアップ、画面一回毎処理用	*/

CRT_EXT	UH	UH_cg_ofs_add;
CRT_EXT	UH	p_vram;
//CRT_EXT UB	vram_line[COLUMN_MAX * 8];	/* 1文字 横 8bit					*/
CRT_EXT UB	vram_line[160];	/* 1文字 横 8bit					*/

/* ----- ifdef -------------------------------------------------------------*/
#ifdef CRT_INCLUDE

UB	vram_txt[VRAM_TXT_SIZE];
UB	vram_txtbuf[VRAM_TXT_SIZE];

/* ----- else --------------------------------------------------------------*/
#else
extern UB	vram_txt[VRAM_TXT_SIZE];
extern UB	vram_txtbuf[VRAM_TXT_SIZE];

/* ----- endif -------------------------------------------------------------*/
#endif


/*==========================================================================*/
/* DATA public																*/
/*==========================================================================*/

/* ----- ifdef -------------------------------------------------------------*/
#ifdef	CRT_INCLUDE

const UB	GRP_data[ 160 * 120 ] PROGMEM= {
	#include "hachuE_o.txt"
};

const UB	TEST_data[ 160 ] PROGMEM= {
	#include "TestData0_15_160.txt"
};

								/* 数字とアルファベット大文字20H - 7FH		*/
								/* [16文字×6行(2X～7X)][(5+1)bit*7bit]		*/
								
const UB	cg_code[ (0x7F +1 +1 - 0x20) * (5+1)*9 ] PROGMEM= {
#include	"CG_code.txt"
};


/* ----- else --------------------------------------------------------------*/
#else

extern const UB GRP_data[ 160 *120 ];
extern const UB TEST_data[ 160 ];
extern const UB cg_code[ (0x7F +1 +1 - 0x20)*(5+1)*9 ];


/* ----- endif -------------------------------------------------------------*/
#endif


/*----------------------------------------------------------------------------
■CRT表示

  ●水平同期パルス信号	周期 --> NTSC規格 15.734kHz -> 63.556us
  
						front porch	1.5us	-+-- horizontal blanking 10.9us
						sync pulse	4.7us	-+
						back porch 	4.7us	-+
													63.5us - 10.9us = 52.6us
											

    |                       |			H-cycle	ICF1 int.		63.625us


    1017(03F9H)             1017		ICR1
    0                       0
	|						|			水平同期信号周期		63.625us
										水平同期信号パルス幅	4.6875us
	+	 +------------------+	 +--	
    |    |                  |    |
    +----+                  +----+
         
    0    75                 0    75		OCR1

										周期					63.625us
    +                  +----+			垂直同期時パルス幅		
    |                  |    |
	+------------------+	+-------	

	|
	*ICF1 int.
	x)Port <-- Low 
		!!! ジッタが出る場合はパルスをソフトで生成しデータ送出とタイミングを取る
	1)OCR1 <-- OCR1buf
	2)水平ブランキング時間後からデータ送出
	3)OCR1bufに水平同期パルス時間または垂直同期切り込みパルス時間をセット

  ●高速PWMモード

  	・カウンタ最大値	ICR1を選択 TOP = ICR1
  	・f_pwm = fclk_IO/(N×(1+TOP ) )
  		15.734kHz = 16MHz/x
  		x = 16MHz/15.734kHz = 1016.9
  		ICR1 = TOP = 1017
		f_pwm 	= 16MHz/( 1×(1+1017) ) = 15.717kHz (63.625us)
  	・PWM出力	反転	COM1x1～0ビット	-> '11'
	・パルス幅
		4.7us/(1/16MHz) = 75.2
		OCR1 = 75


  ●画面サイズ
	1/16MHz --> 62.5ns/clock
	映像表示区間 52us
	
	160×120 = 19200
		52us/160/62.5ns = 5.2clock
	192×144 = 27648
		52us/192/62.5ns = 4.3clock
		
	192column * 144line /8bit = 3546byte
	32kB/(3546*2) = 4.6枚
	3546*2[bit] * 4[枚] = 28368byte
	32kB - 28368byte = 32768byte - 28368byte = 4400byte

	SWAPありで144columnだと
		5clock * 62.5ns = 312.5ns
		312.5ns * 144 = 45 < 52us
		144column * 128line /8bit = 2304byte
		2304*2[bit] * 4[枚] = 18432byte	
	
	--------------------------------------
	★SWAPありで160×120
		5clock * 62.5ns = 312.5ns
		312.5ns * 160 = 50 < 52us
		160column * 120line /8bit = 2400byte
		2400*2[bit] * 4[枚] = 19200byte	
	
	175%でとって1/4にする
	640×480でトリミング
	160×120



	--- 2009.09.22 ----------------------
	AVR Memory Usage
	----------------
	Device: atmega328p

	Program:    1872 bytes (5.7% Full)
	(.text + .data + .bootloader)

	Data:         21 bytes (1.0% Full)
	(.data + .bss + .noinit)
	-------------------------------------


	PortC	3 2 1 0 3 2 1 0
	bit		7 6 5 4 3 2 1 0
    		3 3 2 2 1 1 0 0
			1 0 1 0 1 0 1 0
	
	1枚目	PC3,2←HiZ、PC1,0←out  → PC1,0 ← bit1,0
	2枚目	PC3,2←out、PC1,0←HiZ  → PC3,2 ← bit1,0
	3枚目	データをSWAPして
			PC3,2←HiZ、PC1,0←out  → PC1,0 ← bit1,0
	4枚目	データをSWAPして
			PC3,2←out、PC1,0←HiZ  → PC3,2 ← bit1,0
	
  ●グラフィックデータ転送
  	--- [NG]LDは駄目LPMでないと-----
						意味								動作					クロック数
		LD		Rd,X+	事後増加付きXレジスタ間接での取得	Rd←(X),X←X+1			2
		SWAP	Rd		ニブル上位/下位変換					Rd(7～4) ⇔ Rd(3～0)	1
		OUT		A,Rr	I/Oレジスタへの出力					I/O(A)←Rr				1
	-------------------------------------------------------------------------------------------
							意味								動作					クロック数
		LPM		Rd,Z+																3
		OUT		A,Rr	I/Oレジスタへの出力					I/O(A)←Rr				1
	--------------------------------------------------------------------------------------------	
							意味								動作					クロック数
		LPM		Rd,Z+																3
		SWAP	Rd		ニブル上位/下位変換					Rd(7～4) ⇔ Rd(3～0)	1
		OUT		A,Rr	I/Oレジスタへの出力					I/O(A)←Rr				1
		
		
		
		
		
		
		
		
		
		
		
----------------------------------------------------------------------------*/



/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: defAPP.h
	Content		: 
	Version		: 0.0
	CPU board	: Arduino Duemilanove
	Compiler	: 
	OS			: 
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
#ifdef		APP_INCLUDE
#define		APP_EXT 
#else
#define		APP_EXT	extern
#endif

/*==========================================================================*/
/*	Includes																*/
/*==========================================================================*/
#include	<avr/pgmspace.h>
#ifndef		COMMON_H
#include	"common.h"
#endif

/*==========================================================================*/
/*	function prototype														*/
/*==========================================================================*/
extern void A_APP_Ini( void );
extern void APP_blinkLED( UB, UH );
extern void APP_Display_ram( void );
extern void APP_Check_sts_SYS( void );
extern void APP_Check_sts_CRT( void );
extern void APP_Set_CSL( void );
extern void APP_Check_cds_in( void );
extern void	APP_Sound_Famima( void );
extern void APP_Sound_CETK( void );
extern void APP_Sound_Polka( void );
extern UB APP_htoa( UB );

/*==========================================================================*/
/*	DEFINE																	*/
/*==========================================================================*/
#define	BLK_LED_CYC_NOM	0x1000
#define	BLK_LED_SET		1
#define	BLK_LED_NOM		2

#define	AD_DMEM_SIZE	8

#define	MODE_CRT_DBG	0
#define	MODE_CRT_GRP1	1
#define	MODE_CRT_GRP2	2
#define	MODE_CRT_CSL	3
#define	MODE_CRT_4		4
#define	MODE_CRT_N		5

#define	SYS_RESET		0x10
#define	SYS_RESET_1		0x11
#define	SYS_STBY		0x20
#define	SYS_STBY_1		0x21
#define	SYS_WAICMD		0x30
#define	SYS_WAICMD_1	0x31
#define	SYS_POLKA		0x40
#define	SYS_POLKA_1		0x41

#define	SYS_SEP			20

#define	CRT_STBY	1
#define	CRT_RESET_COUNT		10
#define	CRT_STBY_COUNT		5
#define	CRT_WAICMD_COUNT	2
#define	CRT_POLKA_COUNT		1

#define	CLS_STBY	1



#define	SCLdo		0
#define	SCLdoS		1
#define	SCLre		2
#define	SCLreS		3
#define	SCLmi		4
#define SCLfa		5
#define SCLfaS		6
#define SCLso		7
#define	SCLsoS		8
#define SCLra		9
#define SCLraS		10
#define SCLsi		11
#define	SCL2do		12
#define	SCL2doS		13
#define	SCL2re		14
#define	SCL2reS		15
#define	SCL2mi		16
#define SCL2fa		17
#define SCL2faS		18
#define SCL2so		19
#define	SCL2soS		20
#define SCL2ra		21
#define SCL2raS		22
#define SCL2si		23


#define CDSlight	0x60
#define	CDSdark		0xA0

#define	T_CHECKSTBY	60		/* 	60 * 16.5ms = 990ms							*/
#define	T_CHG_CSL	180		/*	180 * 16.5ms								*/

/*==========================================================================*/
/*	RAM PUBLIC																*/
/*==========================================================================*/
APP_EXT	UB	UBmodeSYS;
APP_EXT	UB	CSLmodeSYS_n;
APP_EXT	UB	CSLmodeSYS_1;
APP_EXT	UB	UBmodeCRT;
APP_EXT	UB	UBmodeCRTtbl;

APP_EXT	UB	UBT_CheckSTBY;		/*	MAX 16.5ms * 255 = 4207.5ms				*/
APP_EXT	UB	UBT_Change_CSL;		/*	MAX 16.5ms * 255 = 4207.5ms				*/
APP_EXT	UB	UB_isCSL_MON;

APP_EXT	UB	UBC_wave_negi;

APP_EXT	UB	f_Sound_on_req;
APP_EXT	UB 	p_scl_tbl;
APP_EXT	UB	UB_FAM_num_n;
APP_EXT	UB	UB_CETK_num_n;
APP_EXT	UB	UB_PLK_num_n;

APP_EXT	UB	UBcommand;			/*	= BLK_LED_SET							*/
APP_EXT	UH	UHcycleBlink;		/*	= BLK_LED_CYC_NOM						*/
APP_EXT	UH	UHcount_blink; 		/*	= 0;									*/
APP_EXT	UH	UHcount_blinkLMT;	/*	= BLK_LED_CYC_NOM;						*/
APP_EXT	UB	isLED_ON;			/*	= 0;									*/

APP_EXT	UB	UB_AD_cds;			/* ADC5										*/
APP_EXT	UB	UB_AD_cds_1;
APP_EXT	UH	UH_Tclock;

APP_EXT	UB	f_sys_mon;
APP_EXT	UB	f_mon_req;
APP_EXT	UB	f_scroll_req;
APP_EXT	UB	f_blink_req;
APP_EXT	UB	f_cds_dark;
APP_EXT	UB	f_done_CSL;

APP_EXT	UB	UB_TMP_data;

APP_EXT	UB	UB_Mes_Stone[10];
APP_EXT	UB	UB_p_Stone;
APP_EXT	UB	UBC_Stone;
APP_EXT	UB	f_CountStone;

APP_EXT	UB	UBC_stsCRT_limit;
/*----------------------------------------------------------------------------
  ●Sound
	OCR2x = (16MHz/focnx -256)/256
	
 	ド	C	261.63Hz	237.89
 		C#	277.18		224.48
	レ	D	293.66		211.83
		D#	311.13		199.88
	ミ	E	329.63		188.60
	ファF	349.23		177.96
		F#	369.99		167.92
	ソ	G	392.00		158.43
		G#	415.30		149.49
	ラ	A	440.00		141.04
		A#	466.16		133.07
	シ	H	493.88		125.54
 	ド	C	523.25		118.44
 		C#	554.37		111.74
	レ	D	587.33		105.41
		D#	622.25		 99.44
	ミ	E	659.26		 93.80
	ファF	698.46		 88.48
		F#	739.99		 83.46
	ソ	G	783.99		 78.72
		G#	830.61		 74.24
	ラ	A	880.00		 70.02
		A#	932.33		 66.03
	シ	H	987.77		 62.27
	

左→右へ演奏してください。 
ラの表記は、

“”→低い
‘’→高い です。

（ファは♯)
ファレ“ラ”レミ‘ラ’ー “ラ”ミファミ“ラ”レー





----------------------------------------------------------------------------*/
/*==========================================================================*/
/* DATA public																*/
/*==========================================================================*/

/* ----- ifdef --------------------------------------------------------------*/
#ifdef	APP_INCLUDE

const UH ad_dmem[AD_DMEM_SIZE] PROGMEM=  {
	(UH)(&UB_AD_cds),					/*	1								*/
	(UH)(&UBmodeSYS),					/*	2								*/
	(UH)(&UBC_wave_negi),				/*	3								*/
	(UH)(&UHcount_blink)+1,				/*	4								*/
	(UH)(&UHcount_blink),				/*	5								*/
	(UH)(&UB_AD_cds),					/*	6								*/
	(UH)(&UH_Tclock)+1,					/*	7								*/
	(UH)(&UH_Tclock),					/*	8								*/
};


const UB SCL_data[24] PROGMEM= {		/* 音階 scale						*/
	238,	/*	C	do	0	*/
	224,	/*	C#		1	*/
	212,	/*	D	re	2	*/
	200,	/*	D#		3	*/
	189,	/*	E	mi	4	*/
	178,	/*	F	fa	5	*/
	168,	/*	F#		6	*/
	158,	/*	G	so	7	*/
	149,	/*	G#		8	*/
	141,	/*	A	ra	9	*/
	133,	/*	A#		10	*/
	126,	/*	H	si	11	*/
	
	118,	/*	C	do	12	*/
	112,	/*	C#		13	*/
	105,	/*	D	re	14	*/
	 99,	/*	D#		15	*/
	 94,	/*	E	mi	16	*/
	 88,	/*	F	fa	17	*/
	 83,	/*	F#		18	*/
	 78,	/*	G	so	19	*/
	 73,	/*	G#		20	*/
	 70,	/*	A	ra	21	*/
	 66,	/*	A#		22	*/
	 62,	/*	H	si	23	*/
};

const UB SCL_famima[15] PROGMEM = { 
	SCL2faS,	/*	0	*/
	SCL2re, 	/*	1	*/
	SCLra, 		/*	2	*/
	SCL2re,		/*	3	*/
	SCL2mi,		/*	4	*/
	SCL2ra,		/*	5	*/
	SCL2ra,		/*	6	*/
	SCLra,		/*	7	*/
	SCL2mi,		/*	8	*/
	SCL2fa, 	/*	9	*/
	SCL2mi,		/*	10	*/
	SCLra,		/*	11	*/
	SCL2re,		/*	12	*/
	0xFF		/*	13	*/
};

const UB SCLT_famima[15] PROGMEM = {
	1,		/*	0	*/
	1, 		/*	1	*/
	1, 		/*	2	*/
	1,		/*	3	*/
	1,		/*	4	*/
	1,		/*	5	*/
	1,		/*	6	*/
	1,		/*	7	*/
	1,		/*	8	*/
	1, 		/*	9	*/
	1,		/*	10	*/
	1,		/*	11	*/
	4,		/*	12	*/
	0xFF	/*	13	*/
};	
	
const UB SCL_CETK[6] PROGMEM = {
	SCL2re,
	SCL2mi,
	SCL2do,
	SCL2do,
	SCL2so,
	0xFF
};

const UB SCLT_CETK[6] PROGMEM = {
	2,
	2,
	2,
	2,
	5,
	0xFF
};
	
/*	32分音符:1,	16:2,	8:4,	4:8,	2,16	*/
/* loitumatab1.gif	*/
#include	"SCL_PLK.txt"
#include	"SCLT_PLK.txt"


/* ----- else --------------------------------------------------------------*/
#else

extern const UH ad_dmem[AD_DMEM_SIZE];
extern const UB SCL_data[24];
extern const UB SCL_famima[14];
extern const UB SCLT_famima[14];
extern const UB SCL_CETK[6];
extern const UB SCLT_CETK[6];
extern const UB SCL_polka[79];
extern const UB SCLT_polka[79];


/* ----- endif -------------------------------------------------------------*/
#endif







;/*****************************************************************************
;	System Name	: Arduino 2009
;	File Name	: CRT_Fitdelay.s
;	Content		: 
;	Version		: 0.0
;	CPU board	: Arduino Duemilanove
;	Compiler	: 
;	OS			: none
;	Programmer	: Meow
;	Copyleft (c)2009 Meow
;	History		:2009/09/xx
;*****************************************************************************/
;
;/*==========================================================================*/
;/*	Includes																*/
;/*==========================================================================*/
;
;/*==========================================================================*/
;/*	Program																	*/
;/*==========================================================================*/
;/*----------------------------------------------------------------------------
;* Function : 
;* Descr	   : 
;* Inputs   : 
;* Outputs  : 
;* Return   : 
;
; ●C言語から呼び出されるアセンブラ関数
;	r0/r18-25/X/Z	自由に使用可能
;	r2-17/Y(r1)		変更する時は保存、復帰
;
; ●引数の渡し方
;	r8～r25が使用される。レジスタ2個ずつセットになっていて9セット使える。
;	大きな番号のレジスタペアから順番に使われる。

;	1/16MHz = 62.5ns/clock
;	実測遅れ 2.54us 40.64
;
;---- src\C\SYS\int\SYS_intCRT_ICF1.c --------------------------------------------------------------
;49:       {
;+000026B0:   921F        PUSH      R1             Push register on stack	[1]
;+000026B1:   920F        PUSH      R0             Push register on stack	[1]
;+000026B2:   B60F        IN        R0,0x3F        In from I/O location		[1]
;+000026B3:   920F        PUSH      R0             Push register on stack	[1]
;+000026B4:   2411        CLR       R1             Clear Register			[1]
;+000026B5:   932F        PUSH      R18            Push register on stack	[1]
;+000026B6:   933F        PUSH      R19            Push register on stack	[1]
;+000026B7:   934F        PUSH      R20            Push register on stack	[1]
;+000026B8:   935F        PUSH      R21            Push register on stack	[1]
;+000026B9:   936F        PUSH      R22            Push register on stack	[1]
;+000026BA:   937F        PUSH      R23            Push register on stack	[1]
;+000026BB:   938F        PUSH      R24            Push register on stack	[1]
;+000026BC:   939F        PUSH      R25            Push register on stack	[1]
;+000026BD:   93AF        PUSH      R26            Push register on stack	[1]
;+000026BE:   93BF        PUSH      R27            Push register on stack	[1]
;+000026BF:   93EF        PUSH      R30            Push register on stack	[1]
;+000026C0:   93FF        PUSH      R31            Push register on stack	[1]
;50:       	P_DBG1_ON;
;+000026C1:   985A        CBI       0x0B,2         Clear bit in I/O register[1]
;51:       	UB_DLY_icf1 = TCNT1L;								
;+000026C2:   91800084    LDS       R24,0x0084     Load direct from data space	[2]
;+000026C4:   9380011F    STS       0x011F,R24     Store direct to data space	[2]
																		TOTAL	21
;*---------------------------------------------------------------------------*/

#include <avr/io.h>
.global	CRT_FitDelay	//CRT_OutDataを外部から利用可能にする
.func	CRT_FitDelay	//関数名の宣言。
						//この後の書かれるアセンブラ命令が関数の中身になる。
						//拡張子を.SにすればCプリプロセッサにもかけられるので
						//C++方式のコメントが利用できる
						/* C形式のコメントもしよう可能	*/
						;アセンブラ形式のコメントも使用可能
						
#define	delay r24		//.def命令の代わりにマクロを使う

CRT_FitDelay:			//関数の開始

						;			50		49		48		47
	cpi		delay,50	;[1]		[1/1]	[1/1]	[1/1]	[1/1]
	BREQ	50f			;[1/2]		[2/3]	[1/2]	[1/2]	[1/2]
	cpi		delay,49	;[1]				[1/3]	[1/3]	[1/3]
	BREQ	49f			;[1/2]				[2/5]	[1/4]	[1/4]
	cpi		delay,48	;							[1/5]	[1/5]
	BREQ	48f			;							[2/7]	[1/6]
	cpi		delay,47	;									[1/7]
	BREQ	47f			;									[2/9]
	cpi		delay,46
	BREQ	46f
	cpi		delay,45
	BREQ	45f
	cpi		delay,44
	BREQ	44f
	cpi		delay,43
	BREQ	43f
	cpi		delay,42
	BREQ	42f
	cpi		delay,41
	BREQ	41f
	cpi		delay,40
	BREQ	40f
	cpi		delay,39
	BREQ	39f
	cpi		delay,38
	BREQ	38f
	cpi		delay,37
	BREQ	37f
	cpi		delay,36
	BREQ	36f
	cpi		delay,35
	BREQ	35f
	cpi		delay,34
	BREQ	34f
	cpi		delay,33
	BREQ	33f
	cpi		delay,32
	BREQ	32f
	cpi		delay,31
	BREQ	31f
	cpi		delay,30
	BREQ	30f
	cpi		delay,29
	BREQ	29f
	cpi		delay,28
	BREQ	28f
	cpi		delay,27
	BREQ	27f
	cpi		delay,26
	BREQ	26f
	cpi		delay,25
	BREQ	25f
	cpi		delay,24
	BREQ	24f
	cpi		delay,23
	BREQ	23f	
	cpi		delay,22
	BREQ	22f
	cpi		delay,21
	BREQ	21f
	cpi		delay,20
	BREQ	20f	


50:	nop					;+31	3	34	84	*62.5ns =5.25us
49:	nop					;+30	5	35	84
48:	nop					;+29	7	36	84
47:	nop					;+28	9	37	84
46:	nop					;
45:	nop					;
44:	nop					;
43:	nop					;
42:	nop					;
41:	nop					;
40:	nop					;
39:	nop					;
38:	nop					;
37:	nop					;
36:	nop					;
35:	nop					;
34:	nop					;
33:	nop					;
32:	nop					;
31:	nop					;
30:	nop					;
29:	nop					;
28:	nop					;
27:	nop					;
26:	nop					;
25:	nop					;
24:	nop					;
23:	nop					;
22:	nop					;
21:	nop					;
20:	nop					;

	ret
	
.endfunc


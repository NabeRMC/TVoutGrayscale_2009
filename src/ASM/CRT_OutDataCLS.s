;/*****************************************************************************
;	System Name	: Arduino 2009
;	File Name	: CRT_OutDataCLS.s
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
;	r8〜r25が使用される。レジスタ2個ずつセットになっていて9セット使える。
;	大きな番号のレジスタペアから順番に使われる。

; ●Port
;	$08:PORTC

;*---------------------------------------------------------------------------*/

#include <avr/io.h>
.global	CRT_OutDataCLS	//CRT_OutDataCLSを外部から利用可能にする
.func	CRT_OutDataCLS	//関数名の宣言。
						//この後の書かれるアセンブラ命令が関数の中身になる。
						//拡張子を.SにすればCプリプロセッサにもかけられるので
						//C++方式のコメントが利用できる
						/* C形式のコメントもしよう可能	*/
						;アセンブラ形式のコメントも使用可能
						
#define	dataL r24		//.def命令の代わりにマクロを使う
#define	dataH r25

CRT_OutDataCLS:			//関数の開始
	mov	r30,dataL		;r30=ZL
	mov	r31,dataH		;r31=ZH
	
#include "outdataCLS.txt"

	ret
.endfunc


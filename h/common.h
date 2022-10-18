/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: common.h
	Content		: 共通ヘッダ
	Version		: 0.0
	CPU board	: xxx
	Compiler	: xxx
	OS			: xxx
	Programmer	: Meow
	Copyleft (c)2009 Meow
	History		:2009/08/xx
*****************************************************************************/
#ifndef COMMON_H
#define COMMON_H

#include <avr/io.h>
#include <avr/pgmspace.h>

/*==========================================================================*/
/* typedef																	*/
/*==========================================================================*/
typedef signed   char		SB;				/* 符号付き8ビット整数 			*/
typedef unsigned char		UB;				/* 符号無し8ビット整数 			*/
typedef signed   short		SH;				/* 符号付き16ビット整数 		*/
typedef unsigned short		UH;				/* 符号無し16ビット整数 		*/
typedef signed   long		SW;				/* 符号付き32ビット整数 		*/
typedef unsigned long		UW;				/* 符号無し32ビット整数 		*/
typedef unsigned char		BL;				/* 真偽値 						*/
//typedef bool_t			BL;				/* 真偽値 						*/


/*==========================================================================*/
/* defines																	*/
/*==========================================================================*/
#define	ON		1
#define	OFF		0
#define	ERROR	(-1)

#endif	/* COOMON_H	*/


/*****************************************************************************
	System Name	: Arduino 2009
	File Name	: common.h
	Content		: ���ʃw�b�_
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
typedef signed   char		SB;				/* �����t��8�r�b�g���� 			*/
typedef unsigned char		UB;				/* ��������8�r�b�g���� 			*/
typedef signed   short		SH;				/* �����t��16�r�b�g���� 		*/
typedef unsigned short		UH;				/* ��������16�r�b�g���� 		*/
typedef signed   long		SW;				/* �����t��32�r�b�g���� 		*/
typedef unsigned long		UW;				/* ��������32�r�b�g���� 		*/
typedef unsigned char		BL;				/* �^�U�l 						*/
//typedef bool_t			BL;				/* �^�U�l 						*/


/*==========================================================================*/
/* defines																	*/
/*==========================================================================*/
#define	ON		1
#define	OFF		0
#define	ERROR	(-1)

#endif	/* COOMON_H	*/


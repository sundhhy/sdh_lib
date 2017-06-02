/*
 * marco.h
 *
 *  Created on: 2016-11-4
 *      Author: Administrator
 */
#ifndef __MARCO_H__
#define __MARCO_H__
#include <stdint.h>

#define IN
#define OUT

#define LINE_DIF(line_base) (__LINE__ - line_base)
#define CHECK_BIT( bitmap, num) ( ( (uint8_t *)bitmap)[ num >> 3] & ( 1 << ( num & 0x7)) )
#define SDH_SET_BIT( bitmap, num) ( (uint8_t *)bitmap)[ num >> 3] = ( (uint8_t *)bitmap)[ num/8] | ( 1 << ( num & 0x7))
#define SDH_CLR_BIT( bitmap, num) ( (uint8_t *)bitmap)[ num>> 3] =  ( (uint8_t *)bitmap)[ num/8] & ~( 1 << ( num & 0x7))

#define container_of(ptr, type, member) ({                      \
const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
(type *)( (char *)__mptr - offsetof(type,member) );})

void getCompileDate(uint8_t* pDest,uint8_t dsize);
unsigned char GetCompileMoth( void);
unsigned char GetCompileDay( void);

#endif

/*
 * os_depend.h
 *
 *  Created on: 2017-1-13
 *      Author: Administrator
 */

#ifndef OS_DEPEND_H_
#define OS_DEPEND_H_
#include "sdhlibConf.h"
#ifdef QNX_OS
#include "os/qnx/qnx_depend.h"
#endif

#ifdef NO_OS
#include "os/NoOS_depend.h"
#endif


void RgtWasteMs( void *wms);

void delay_s(int sec);
void delay_ms(int ms);
void delay_ns( unsigned long nsec );

int get_currenttime(os_time_t *nowtime);
void PrintTime(os_time_t *time);
int cal_timediff_ms( os_time_t *ref_time);

int Mutex_init( mutext_t *mutex);
int Mutex_destory( mutext_t *mutex);
int Mutex_lock( mutext_t *mutex);
int Mutex_trylock( mutext_t *mutex);
int Mutex_unlock( mutext_t *mutex);

#endif /* OS_DEPEND_H_ */

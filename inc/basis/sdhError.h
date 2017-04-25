#ifndef __MYERROR_H__
#define __MYERROR_H__

typedef int err_t;

#define RET_OK						0

#define ERR_MEM_UNAVAILABLE			-6					/* ??????			*/
#define ERR_RES_UNAVAILABLE			-7					/* ??????			*/
#define ERR_DEV_TIMEOUT					-8					/* ??????			*/
#define ERR_FAIL								-9					/* 操作失败		*/ 
#define ERR_ADDR_ERROR						-10
#define ERR_DRI_OPTFAIL							-11				/* 驱动执行某项动作失败			*/
#define ERR_DEV_BUSY							-12				/* 驱动执行某项动作失败			*/
#define ERR_BADSTATUS							-12				/*当前状态不支持		*/

#define ERR_OK 									0 					/* No error, everything OK. */
#define ERR_MEM        -1    /* Out of memory error.     */
#define ERR_BUF        -2    /* Buffer error.            */
#define ERR_TIMEOUT    -3    /* Timeout.                 */
#define ERR_RTE        -4    /* Routing problem.         */
#define ERR_INPROGRESS -5    /* Operation in progress    */
#define ERR_VAL        -6    /* Illegal value.           */
#define ERR_WOULDBLOCK -7    /* Operation would block.   */
#define ERR_USE        -8    /* Address in use.          */
#define ERR_ISCONN     -9    /* Already connected.       */

#define ERR_IS_FATAL(e) ((e) < ERR_ISCONN)

#define ERR_ABRT       -10   /* Connection aborted.      */
#define ERR_RST        -11   /* Connection reset.        */
#define ERR_CLSD       -12   /* Connection closed.       */
#define ERR_CONN       -13   /* Not connected.           */

#define ERR_ARG        -14   /* Illegal argument.        */

#define ERR_IF         -15   /* Low-level netif error    */



#define ERR_UNKOWN     			-16    /* 未知错误      */
#define ERR_BAD_PARAMETER    	-17    /* 错误参数      */
#define ERR_ERROR_INDEX     	-18    /* 错误索引      */
#define ERR_UNINITIALIZED     	-19    /* 未初始化的变量或子系统      */
#define ERR_CATASTROPHIC_ERR	-20 /* 灾难性错误			*/
#define ERR_UNAVAILABLE			-21	  /* 不可获取的资源			*/
#define ERR_BUSY     			-23    /*       */
/*
err_t :
MSB  ----------|----------- LSB
1  	|	模块标识  |	错误标识
1bit| 15b				| 16b


*/

#define MODULE_BITS	15
#define ERROR_BITS	16

#define ERROR_BIT		(1<<(MODULE_BITS + ERROR_BITS))
#define ERROR_BEGIN(_module_id)	((_module_id) << ERROR_BITS)
#define	ERROR_T(_module_error)	(ERROR_BIT | _module_error)

//获取错误标识
#define MODULE_ERROR(_error_t) ((_error_t) & ((1 << ERROR_BITS) - 1))
//获取模块标识
#define MODULE_ID(_error_t)		(((_error_t) & ~(ERROR_BIT)) >> ERROR_BITS)

#define INVERSE_ERROR(_error_t) ((_error_t) & ( ~(ERROR_BIT)))

//----------------------------------------------------------------------
//系统中的组件，两层结构
// 高4位表示层级 低四位表示层级中的序号   层级|序号
//----------------------------------------------------------------------
#define	APP_MAIN	0x00
#define HAL_ENC624	0x80
#define DRIVE_GPMC	0x90
#define DRIVE_GPIO	0x91
#define CHECK_ERROR( return_val, msg) { \
	if( return_val != 0) { \
		fprintf( stderr, "%s:%s \n", msg, strerror(return_val)); \
		exit(-1);	\
		}\
	}


#endif

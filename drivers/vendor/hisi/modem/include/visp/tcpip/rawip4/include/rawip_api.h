/*
*                Copyright 2008, Huawei Technologies Co. Ltd.
*                            ALL RIGHTS RESERVED
*
*-------------------------------------------------------------------------------
*
*                              udp_api.h
*
*  Project Code: VISPV1R7
*   Module Name: UDP_API
*  Date Created: 2008-03-07
*        Author: zhengsenhuo(00104483)
*   Description:
*
*-------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  -----------------------------------------------------------------------------
*   2008-03-07  Zheng SenHuo           Creat the first version.
*
*******************************************************************************/


#ifndef        _RAWIP_API_H_
#define        _RAWIP_API_H_

#ifdef    __cplusplus
extern    "C"{
#endif

#define RAWIP_ERR_NULL_POINT 2          /* 获取RAWIP统计信息,输入空指针 */
#define RAWIP_ERR_GETSTAT_INPCB 3       /* 获取RAWIP统计信息,INPCB结构为空 */
#define RAWIP_ERR_GETSTAT_SOCKETCB 4    /* 获取RAWIP统计信息,SOCKETCB结构为空 */


typedef struct tagRIPSTAT
{
    ULONG rips_ulNoProto;
    ULONG rips_ulDelivered;
    ULONG rips_ulRawOut;
    ULONG rips_ulRawOutErr;
}RIPSTAT_S;

/* 基于socket id,task id和四元组获取统计信息输入参数数据结构 */
typedef struct tagRAWIP4CONN_S
{
    ULONG    ulVrfIndex;    /* VRF索引*/
    ULONG    ulLAddr;       /* 本端地址 (主机序)*/
    ULONG    ulFAddr;       /* 对端地址 (主机序)*/
    ULONG    ulProto;       /* 协议号 */
    ULONG    ulSocketID ;   /* Socket ID */
    ULONG    ulTaskID;      /* 任务 ID */
}RAWIP4CONN_S;

/* 基于socket id,task id和四元组获取统计信息数据结构 */
typedef struct tagRAWIP4PERSTAT_S
{
    RAWIP4CONN_S stRawIp4Conn;      /*实际获取的socket id task id 和四元组*/
    ULONG   ulIPackets;             /* 接收到的RAWIP报文包数  */
    ULONG   ulIPacketsByte;         /* 接收到的RAWIP报文字节数 */

    ULONG   ulOPackets;              /* 发送的RAWIP报文包数  */
    ULONG   ulOPacketsByte;          /* 发送的RAWIP报文字节数 */

    /*socket 缓冲区信息*/
    ULONG    ulSndHiWat ;           /*发送缓冲区高水位*/
    ULONG    ulRcvHiWat ;           /*接收缓冲区高水位*/
    ULONG    ulSndCC ;              /*发送缓冲区中实际数据 */
    ULONG    ulRcbCC ;              /*接收缓冲区中实际数据 */
    ULONG    ulDropPackets;         /*由于接收缓冲区满丢弃的报文数*/
    ULONG    ulDropPacketBytes;     /*由于接收缓冲区满丢弃的报文字节数*/
}RAWIP4PERSTAT_S;

/*OSPF RAWIP socket 信息结构, 为支持光网络双OSPF特性而新增此数据结构, 2005-10-31, SWID00024*/
typedef struct tagTargetSOCKET
{
            ULONG ulSockId;        /*socket号*/
            ULONG ulTaskId;        /*任务号*/
}TARGET_SOCKET_S;

typedef ULONG (*LocateTargetSocket_HOOK_FUNC)(ULONG ulIfIndex,ULONG ulDestAddr, TARGET_SOCKET_S *pstTargetSkt);

/*******************************************************************************
*    Func Name: TCPIP_ClrRawIPStat
*  Description: 清空RawIP4组件的统计信息
*        Input: VOID
*       Output:
*       Return: VOID
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
VOID  TCPIP_ClrRawIPStat(VOID);
/*******************************************************************************
*    Func Name: TCPIP_GetRawIPStat
*  Description: 获取RawIP4组件的统计信息
*        Input: RIPSTAT_S *pstRawipStats: 存储统计信息内存
*       Output:
*       Return: VOS_OK  成功
*               VOS_ERR 失败
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
ULONG TCPIP_GetRawIPStat(RIPSTAT_S *pstRawipStats);
/****************************************************************************
*    Func Name: TCPIP_RegFuncLocateTargetSocketHook()
*  Description: 注册获取OSPF报文目的socket信息的函数
*        Input: LocateTargetSocket_HOOK_FUNC pfHookFunc 注册钩子函数的指针
*       Output: 无
*       Return: VOS_OK:成功
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE        NAME             DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-3-9  Zheng Sen Huo (00104483)         Creat the first version.
*
*******************************************************************************/
ULONG TCPIP_RegFuncLocateTargetSocketHook(LocateTargetSocket_HOOK_FUNC pfHookFunc);
/*******************************************************************************
*    Func Name: TCPIP_ShowRipStatistic
*  Description: 显示RawIP4组件的统计信息
*        Input: VOID
*       Output:
*       Return: VOID
*      Caution:
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2008-04-17   Zheng Sen Huo (00104483)  Create
*
*******************************************************************************/
VOID  TCPIP_ShowRipStatistic (VOID);


extern ULONG TCPIP_GetPerRawip4ConnStats(RAWIP4CONN_S *pstConnInfo, RAWIP4PERSTAT_S  *pstRetStats);


extern ULONG TCPIP_ResetPerRawip4ConnStats(RAWIP4CONN_S *pstConnInfo);


typedef ULONG (*RAWIPINPUT_HOOK_FUNC)( MBUF_S* pMbuf );
ULONG TCPIP_RegFuncRAWIPInputHook( RAWIPINPUT_HOOK_FUNC pfFuncHook );
extern RAWIPINPUT_HOOK_FUNC g_RawIP_Input_HookFunc;

#define RAWIP_NOT_PROCESSED_BY_INTERMEDIATE              0
/* intermediate found the packet has Error, Stack will Destroy the Packet */
#define RAWIP_INTER_PROCESS_ERROR                        1
/* Intermediate Processing will continue processing and will own the packet
 * PP do not need to process the packet any more */
#define RAWIP_PROCESSED_BY_INTERMEDIATE                  2


#ifdef    __cplusplus
}
#endif    /* end of __cplusplus */

#endif


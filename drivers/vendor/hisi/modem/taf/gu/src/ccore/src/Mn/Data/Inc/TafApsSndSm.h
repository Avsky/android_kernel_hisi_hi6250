

#ifndef __TAF_APS_SNDSM_H__
#define __TAF_APS_SNDSM_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/
/*****************************************************************************
 结构名   : SMREG_PDP_ACTIVATE_IND_STRU
 结构说明 :
*****************************************************************************/
typedef struct
{
    SM_TAF_MSG_ID_ENUM_UINT32           enMsgId;
    VOS_UINT32                          ulMsgLen;
} APS_SM_MSG_ID_MAP_TO_LEN_STRU;


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
/*****************************************************************************
 函 数 名  : TAF_APS_AllocMsgToSmAndFillMsgHeader
 功能描述  : APS申请发送给SM的消息，并填充消息头，初始化消息头之后的数据
 输入参数  : SM_TAF_MSG_ID_ENUM_UINT32 enMsgId
 输出参数  : MSG_HEADER_STRU* 消息指针
 返 回 值  :
 调用函数  :
 被调函数  :
*****************************************************************************/
MSG_HEADER_STRU*  TAF_APS_AllocMsgToSmAndFillMsgHeader(
    SM_TAF_MSG_ID_ENUM_UINT32           enMsgId
);

/*****************************************************************************
 函 数 名  : TAF_APS_SndSmPdpAbortReq
 功能描述  : 向SM发送ABORT请求, 停止当前PDP操作
 输入参数  : ucPdpId                    - APS实体索引
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_VOID TAF_APS_SndSmPdpAbortReq(
    VOS_UINT8                           ucPdpId
);

/*****************************************************************************
 函 数 名  : TAF_APS_SndSmPdpLocalDeactivateReq
 功能描述  : 向SM发送本地去激活PDP请求, 清除当前PDP信息
 输入参数  : ucPdpId                    - APS实体索引
 输出参数  : 无
 返 回 值  : 无
 调用函数  :
 被调函数  :
*****************************************************************************/
VOS_VOID TAF_APS_SndSmPdpLocalDeactivateReq(
    VOS_UINT8                           ucPdpId
);







#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of TafApsSndSm.h */

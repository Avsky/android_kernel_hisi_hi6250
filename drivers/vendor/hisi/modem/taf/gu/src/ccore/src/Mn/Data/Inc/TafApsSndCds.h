

#ifndef __TAFAPSSNDCDS_H__
#define __TAFAPSSNDCDS_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "ApsCdsInterface.h"
#include  "TafApsCtx.h"

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
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)

VOS_VOID TAF_APS_SndCdsFreeBuffDataInd(
    VOS_UINT8                           ucRabId
);
VOS_VOID TAF_APS_SndCdsSndBuffDataInd(
    VOS_UINT8                           ucRabId
);

VOS_VOID TAF_APS_SndCdsModeChangeInd(
    TAF_APS_RAT_TYPE_ENUM_UINT32        enCurrCdataServiceMode
);

#endif





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

#endif /* end of TafApsSndCds.h */

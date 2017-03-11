

#ifndef _MTCNASINTERFACE_H_
#define _MTCNASINTERFACE_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "vos.h"
#include "PsTypeDef.h"


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

enum MTC_NAS_MSG_ID_ENUM
{
    /* 消息名称 */                         /* 消息ID */                         /* 备注 */
    /* NAS --> MTC */
    ID_NAS_MTC_TC_STATUS_INFO_IND          = 0x0001,                            /* _H2ASN_MsgChoice NAS_MTC_TC_STATUS_INFO_IND_STRU */

    /* MTC --> NAS */

    ID_MTC_NAS_MSG_ID_BUTT
};
typedef VOS_UINT32  MTC_NAS_MSG_ID_ENUM_UINT32;


enum MTC_NAS_TC_STATUS_ENUM
{
    MTC_NAS_TC_STOP                      = 0,                                   /* 环回停止 */
    MTC_NAS_TC_START,                                                           /* 环回启动 */
    MTC_NAS_TC_BUTT
};
typedef VOS_UINT16 MTC_NAS_TC_STATUS_ENUM_UINT16;



enum MTC_NAS_RAT_MODE_ENUM
{
    MTC_NAS_RAT_MODE_GSM                     = 0,                               /* GSM */
    MTC_NAS_RAT_MODE_WCDMA,                                                     /* WCDMA */
    MTC_NAS_RAT_MODE_TDSCDMA,                                                   /* TDSCDMA */
    MTC_NAS_RAT_MODE_LTE,                                                       /* LTE */
    MTC_NAS_RAT_MODE_CDMA,                                                      /* CDMA */
    MTC_NAS_RAT_MODE_BUTT
};
typedef VOS_UINT16 MTC_NAS_RAT_MODE_ENUM_UINT16;

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

typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
    MTC_NAS_TC_STATUS_ENUM_UINT16       enTcStatus;
    MTC_NAS_RAT_MODE_ENUM_UINT16        enRatMode;
}NAS_MTC_TC_STATUS_INFO_IND_STRU;

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/

/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    MTC_NAS_MSG_ID_ENUM_UINT32          enMsgID;                                /*_H2ASN_MsgChoice_Export MTC_NAS_MSG_ID_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MTC_NAS_MSG_ID_ENUM_UINT32
    ****************************************************************************/
} MTC_NAS_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MTC_NAS_MSG_DATA                    stMsgData;
} MtcNasInterface_MSG;

/*****************************************************************************
  10 函数声明
*****************************************************************************/

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MtcNasInterface.h */




#ifndef __OAM_LINUX_NETLINK_H__
#define __OAM_LINUX_NETLINK_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "oal_ext_if.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_OAM_LINUX_NETLINK_H
/*****************************************************************************
  2 宏定义
*****************************************************************************/
#if(_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_WS835DMB)
#define OAM_NETLINK_ID   29         //1151honor835 修改成29，防止和其他产品的ko加载以及业务运行时创建的netlink产生冲突
#else
#define OAM_NETLINK_ID   25
#endif
/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 STRUCT定义
*****************************************************************************/
typedef struct
{
    oal_sock_stru   *pst_nlsk;
    oal_uint32       ul_pid;
}oam_netlink_stru;


typedef struct
{
    oal_uint32 (*p_oam_sdt_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
    oal_uint32 (*p_oam_hut_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
    oal_uint32 (*p_oam_alg_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
    oal_uint32 (*p_oam_daq_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
    oal_uint32 (*p_oam_reg_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
    oal_uint32 (*p_oam_acs_func)(oal_uint8 *puc_data, oal_uint32 ul_len);
}oam_netlink_proto_ops;


/*****************************************************************************
  5 全局变量声明
*****************************************************************************/
extern oam_netlink_stru        g_st_netlink;
extern oam_netlink_proto_ops   g_st_netlink_ops;


/*****************************************************************************
  6 消息头定义
*****************************************************************************/


/*****************************************************************************
  7 消息定义
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
extern oal_uint32  oam_netlink_kernel_create(oal_void);
extern oal_void oam_netlink_kernel_release(oal_void);


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of oam_linux_netlink.h */

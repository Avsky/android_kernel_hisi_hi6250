
#ifndef _IPV6_AM_PUBLIC_H
#define _IPV6_AM_PUBLIC_H

/**************�궨��***************/
#define IPV6_V6_USER       1   
#define IPV6_V4V6_USER     2 

#define IPV6_ADD   0
#define IPV6_SUB   1

#define IPV6_IPV6CP_ATTEMPT  1   
#define IPV6_IPV6CP_SUCC     2 
/**************��������***************/

/*IPV6 FIXED HEADER */
typedef struct tagIpv6hdr {
#if (UGW_BYTE_ORDER == UGW_LITTLE_ENDIAN)
    VOS_UINT32        traffic_class_1:4,
                 version:4,
                 flow_lbl_1:4,
                 traffic_class_2:4,
                 flow_lbl_2:16;
#else
    VOS_UINT32        version:4,
                 traffic_class:8,
                 flow_lbl:20;
#endif    

    VOS_UINT16       payload_len;
    UCHAR        nexthdr;
    UCHAR        hop_limit;

    in6_addr    saddr;
    in6_addr    daddr;
}VOS_PACKED IPV6HDR_S;


VOS_VOID IPV6_PerfActUserStatistic(VOS_UINT32 ulPerfType,VOS_UINT32 ulOper,VOS_UINT32 ulDomainIndex);
VOS_UINT16 IPV6_CalcCheckSum(VOS_UINT8 *ptr, in6_addr *pSrcAddr, in6_addr *pDesAddr, const VOS_UINT8 *msg, 
                                       VOS_UINT32 ulLen, VOS_UINT8 ucPro);
VOS_UINT16 IPV6_CalcCheckSumExten(in6_addr *pSrcAddr, in6_addr *pDesAddr, const VOS_UINT8 *msg, 
                                                    VOS_UINT32 ulLen, VOS_UINT8 ucPro);
VOS_UINT32  IPV6_StopTimer(VOS_UINT32 ulTimerId);
extern VOS_UINT32 Ipv6_A11NotifySendRa(VOS_UINT32 ulPdnIndex);

#endif

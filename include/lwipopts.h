/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/**
 * @file
 *
 * lwIP options configuration
 */

#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

/*
 *  Provides its own errno
 */

#if __ANDROID__
#define LWIP_PROVIDE_ERRNO          0
#define SOCKLEN_T_DEFINED
#elif !defined(_MSC_VER)
#define LWIP_PROVIDE_ERRNO          1
#endif

/*
 * Provides core locking machinery
 */
#define LWIP_TCPIP_CORE_LOCKING     0

/*
 * Provides a macro to spoof the names of the lwip socket functions
 */
#define LWIP_POSIX_SOCKETS_IO_NAMES 0

#define LWIP_NOASSERT               1
/*
 *
 */
#define LWIP_TIMERS                 1

/*
 *
 */
//#define LWIP_COMPAT_MUTEX 1
//#define LWIP_COMPAT_MUTEX_ALLOWED 1

/*
 * Provides network/host byte transformation macros
 */

#if __ANDROID__
#define LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS 1
#endif

/*
 * Include user defined options first. Anything not defined in these files
 * will be set to standard values. Override anything you dont like!
 */
#include "lwip/debug.h"

#define LWIP_IPV6_AUTOCONFIG 1

// #define LWIP_IPV6_MLD 1
// #define LWIP_ICMP6 1
// #define LWIP_IPV6_NUM_ADDRESSES 3
// #define LWIP_ND6_MAX_MULTICAST_SOLICIT 3
// #define LWIP_IPV6_SEND_ROUTER_SOLICIT 0

// IP Protocol version
#define LWIP_NETIF_STATUS_CALLBACK 1
#define LWIP_IPV4 1
#define LWIP_IPV6 1

// --- DEBUG ---


#define LWIP_DEBUG 1

/* flag for LWIP_DEBUGF indicating a tracing message
 * (to follow program flow)
 */
#define LWIP_DBG_TRACE         0x40U
/* flag for LWIP_DEBUGF indicating a state debug message
 * (to follow module states)
 */
#define LWIP_DBG_STATE         0x20U
/* flag for LWIP_DEBUGF indicating newly added code,
 * not thoroughly tested yet
 */
#define LWIP_DBG_FRESH         0x10U
/* flag for LWIP_DEBUGF to halt after printing
 * this debug message
 */
#define LWIP_DBG_HALT          0x08U

//#define LWIP_DBG_TYPES_ON LWIP_DBG_TRACE | LWIP_DBG_STATE | LWIP_DBG_FRESH

#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_ALL
#define LWIP_DBG_TYPES_ON               LWIP_DBG_ON

#define ETHARP_DEBUG                    LWIP_DBG_OFF

// interfaces
#define SLIP_DEBUG                      LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_OFF
// API
#define API_LIB_DEBUG                   LWIP_DBG_OFF
#define API_MSG_DEBUG                   LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
// other
#define ICMP_DEBUG                      LWIP_DBG_OFF
#define IGMP_DEBUG                      LWIP_DBG_OFF
#define INET_DEBUG                      LWIP_DBG_OFF
#define RAW_DEBUG                       LWIP_DBG_OFF
// memory
#define PBUF_DEBUG                      LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
// system
#define SYS_DEBUG                       LWIP_DBG_OFF
#define TIMERS_DEBUG                    LWIP_DBG_OFF
// TCP
#define TCP_DEBUG_TMR					LWIP_DBG_OFF // not standard in lwIP, added for debugging convenience
#define TCP_DEBUG                       LWIP_DBG_OFF
#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
#define TCP_RST_DEBUG                   LWIP_DBG_OFF
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
// IP
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define IP_REASS_DEBUG                  LWIP_DBG_OFF
#define IP6_DEBUG                       LWIP_DBG_OFF
// TCP/IP
#define TCPIP_DEBUG                     LWIP_DBG_OFF
// UDP
#define UDP_DEBUG                       LWIP_DBG_OFF
// services
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define DNS_DEBUG                       LWIP_DBG_OFF


#define LWIP_ETHERNET   1

#define LWIP_CHKSUM_ALGORITHM 2

#undef TCP_MSS
#define TCP_MSS 1460

#define LWIP_NETIF_API 1
/*
The TCP window size can be adjusted by changing the define TCP_WND. However,
do keep in mind that this should be at least twice the size of TCP_MSS (thus
on ethernet, where TCP_MSS is 1460, it should be set to at least 2920). If
memory allows it, set this as high as possible (16-bit, so 0xFFFF is the highest
value), but keep in mind that for every active connection, the full window may
have to be buffered until it is acknowledged by the remote side (although this
buffer size can still be controlled by TCP_SND_BUF and TCP_SND_QUEUELEN). The
reason for "twice" are both the nagle algorithm and delayed ACK from the
remote peer.
*/

#define TCP_WND 0xffff // max = 0xffff, min = TCP_MSS*2

#define LWIP_NOASSERT 1
#define TCP_LISTEN_BACKLOG   0

/*------------------------------------------------------------------------------
---------------------------------- Timers --------------------------------------
------------------------------------------------------------------------------*/
/*
Be careful about setting this too small.  lwIP just counts the number
of times its timer is called and uses this to control time sensitive
operations (such as TCP retransmissions), rather than actually
measuring time using something more accurate.  If you call the timer
functions very frequently you may see things (such as retransmissions)
happening sooner than they should.
*/
/* these are originally defined in tcp_impl.h */
#ifndef TCP_TMR_INTERVAL
/* The TCP timer interval in milliseconds. */
#define TCP_TMR_INTERVAL       250
#endif /* TCP_TMR_INTERVAL */

#ifndef TCP_FAST_INTERVAL
/* the fine grained timeout in milliseconds */
#define TCP_FAST_INTERVAL      TCP_TMR_INTERVAL
#endif /* TCP_FAST_INTERVAL */

#ifndef TCP_SLOW_INTERVALs
/* the coarse grained timeout in milliseconds */
#define TCP_SLOW_INTERVAL      (2*TCP_TMR_INTERVAL)
#endif /* TCP_SLOW_INTERVAL */


/*------------------------------------------------------------------------------
--------------------------- Platform specific locking -------------------------
------------------------------------------------------------------------------*/

/**
 * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
 * critical regions during buffer allocation, deallocation and memory
 * allocation and deallocation.
 */
#define SYS_LIGHTWEIGHT_PROT            1

/**
 * NO_SYS==1: Provides VERY minimal functionality. Otherwise,
 * use lwIP facilities.
 */

/* set to 1 so we have no thread behaviour */
#define NO_SYS                          0

/* set to 1 so we can use our own timers */
#define NO_SYS_NO_TIMERS                0


/*------------------------------------------------------------------------------
-------------------------------- Memory options --------------------------------
------------------------------------------------------------------------------*/

//#define MEM_USE_POOLS 1
//#define MEMP_USE_CUSTOM_POOLS 1

/* Misc */
#define MEM_LIBC_MALLOC 1
#define MEMP_MEM_MALLOC 1

/**
 * MEM_ALIGNMENT: should be set to the alignment of the CPU
 *    4 byte alignment -> #define MEM_ALIGNMENT 4
 *    2 byte alignment -> #define MEM_ALIGNMENT 2
 */
#define MEM_ALIGNMENT                   4

/**
 * MEM_SIZE: the size of the heap memory. If the application will send
 * a lot of data that needs to be copied, this should be set high.
 */
#define MEM_SIZE                        1024 * 1024 * 64
#define TCP_SND_BUF                     1024 * 63
//#define TCP_OVERSIZE                    TCP_MSS

#define TCP_SND_QUEUELEN                1024

/*------------------------------------------------------------------------------
-------------------------------- Pbuf Options ----------------------------------
------------------------------------------------------------------------------*/

/**
 * PBUF_LINK_HLEN: the number of bytes that should be allocated for a
 * link level header. The default is 14, the standard value for
 * Ethernet.
 */
#define PBUF_LINK_HLEN                  16

/**
 * PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. The default is
 * designed to accomodate single full size TCP frame in one pbuf, including
 * TCP_MSS, IP header, and link header.
*
 */
#define PBUF_POOL_BUFSIZE               LWIP_MEM_ALIGN_SIZE(TCP_MSS+40+PBUF_LINK_HLEN)


/*------------------------------------------------------------------------------
-------------------------- Internal Memory Pool Sizes --------------------------
------------------------------------------------------------------------------*/

/**
 * MEMP_NUM_PBUF: the number of memp struct pbufs (used for PBUF_ROM and PBUF_REF).
 * If the application sends a lot of data out of ROM (or other static memory),
 * this should be set high.
 */
#define MEMP_NUM_PBUF                   256

/**
 * MEMP_NUM_RAW_PCB: Number of raw connection PCBs
 * (requires the LWIP_RAW option)
 */
#define MEMP_NUM_RAW_PCB                128

/**
 * MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
 * per active UDP "connection".
 * (requires the LWIP_UDP option)
 */
#define MEMP_NUM_UDP_PCB                128

/**
 * MEMP_NUM_TCP_PCB: the number of simulatenously active TCP connections.
 * (requires the LWIP_TCP option)
 */
#define MEMP_NUM_TCP_PCB                128

/**
 * MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP connections.
 * (requires the LWIP_TCP option)
 */
#define MEMP_NUM_TCP_PCB_LISTEN         128

/**
 * MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP segments.
 * (requires the LWIP_TCP option)
 */
#define MEMP_NUM_TCP_SEG                1024

/**
 * MEMP_NUM_REASSDATA: the number of simultaneously IP packets queued for
 * reassembly (whole packets, not fragments!)
 */
#define MEMP_NUM_REASSDATA              1

/**
 * MEMP_NUM_ARP_QUEUE: the number of simulateously queued outgoing
 * packets (pbufs) that are waiting for an ARP request (to resolve
 * their destination address) to finish.
 * (requires the ARP_QUEUEING option)
 */
#define MEMP_NUM_ARP_QUEUE              2

/**
 * MEMP_NUM_SYS_TIMEOUT: the number of simulateously active timeouts.
 * (requires NO_SYS==0)
 */
#define MEMP_NUM_SYS_TIMEOUT            3

/**
 * MEMP_NUM_NETBUF: the number of struct netbufs.
 * (only needed if you use the sequential API, like api_lib.c)
 */
#define MEMP_NUM_NETBUF                 2

/**
 * MEMP_NUM_NETCONN: the number of struct netconns.
 * (only needed if you use the sequential API, like api_lib.c)
 */
#define MEMP_NUM_NETCONN                32

/**
 * MEMP_NUM_TCPIP_MSG_API: the number of struct tcpip_msg, which are used
 * for callback/timeout API communication.
 * (only needed if you use tcpip.c)
 */
#define MEMP_NUM_TCPIP_MSG_API          64

/**
 * MEMP_NUM_TCPIP_MSG_INPKT: the number of struct tcpip_msg, which are used
 * for incoming packets.
 * (only needed if you use tcpip.c)
 */
#define MEMP_NUM_TCPIP_MSG_INPKT        32

/**
 * PBUF_POOL_SIZE: the number of buffers in the pbuf pool.
 */
#define PBUF_POOL_SIZE                  4092 /* was 32 */


/*------------------------------------------------------------------------------
----------------------------------- ARP options --------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_ARP==1: Enable ARP functionality.
 */
#define LWIP_ARP                        1
#define ARP_TABLE_SIZE                  64
//#define ETHARP_FLAG_TRY_HARD            0

/*------------------------------------------------------------------------------
------------------------------------ IP options---------------------------------
------------------------------------------------------------------------------*/

/**
 * IP_FORWARD==1: Enables the ability to forward IP packets across network
 * interfaces. If you are going to run lwIP on a device with only one network
 * interface, define this to 0.
 */
#define IP_FORWARD                      0

/**
 * IP_OPTIONS: Defines the behavior for IP options.
 *      IP_OPTIONS_ALLOWED==0: All packets with IP options are dropped.
 *      IP_OPTIONS_ALLOWED==1: IP options are allowed (but not parsed).
 */
#define IP_OPTIONS_ALLOWED              1

/**
 * IP_REASSEMBLY==1: Reassemble incoming fragmented IP packets. Note that
 * this option does not affect outgoing packet sizes, which can be controlled
 * via IP_FRAG.
 */
#define IP_REASSEMBLY                   1

/**
 * IP_FRAG==1: Fragment outgoing IP packets if their size exceeds MTU. Note
 * that this option does not affect incoming packet sizes, which can be
 * controlled via IP_REASSEMBLY.
 */
#define IP_FRAG                         1
#define IPV6_FRAG_COPYHEADER            1 // Was 0

/**
 * IP_REASS_MAXAGE: Maximum time (in multiples of IP_TMR_INTERVAL - so seconds, normally)
 * a fragmented IP packet waits for all fragments to arrive. If not all fragments arrived
 * in this time, the whole packet is discarded.
 */
#define IP_REASS_MAXAGE                 3

/**
 * IP_REASS_MAX_PBUFS: Total maximum amount of pbufs waiting to be reassembled.
 * Since the received pbufs are enqueued, be sure to configure
 * PBUF_POOL_SIZE > IP_REASS_MAX_PBUFS so that the stack is still able to receive
 * packets even if the maximum amount of fragments is enqueued for reassembly!
 */
#define IP_REASS_MAX_PBUFS              32

/**
 * IP_FRAG_USES_STATIC_BUF==1: Use a static MTU-sized buffer for IP
 * fragmentation. Otherwise pbufs are allocated and reference the original
	* packet data to be fragmented.
*/
#define IP_FRAG_USES_STATIC_BUF         0

/**
 * IP_DEFAULT_TTL: Default value for Time-To-Live used by transport layers.
 */
#define IP_DEFAULT_TTL                  255


/*------------------------------------------------------------------------------
------------------------------- ICMP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_ICMP==1: Enable ICMP module inside the IP stack.
 * Be careful, disable that make your product non-compliant to RFC1122
 */
#define LWIP_ICMP                       1
#define LWIP_ICMP6                      LWIP_IPV6 && 1 // Was 0

/*------------------------------------------------------------------------------
------------------------------- RAW Options ------------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_RAW==1: Enable application layer to hook into the IP layer itself.
 */
#define LWIP_RAW                        1


/*------------------------------------------------------------------------------
------------------------------- DHCP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_DHCP==1: Enable DHCP module.
 */
#define LWIP_DHCP                       0


/*------------------------------------------------------------------------------
------------------------------ AUTOIP Options ----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_AUTOIP==1: Enable AUTOIP module.
 */
#define LWIP_AUTOIP                     0


/*------------------------------------------------------------------------------
------------------------------- SNMP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_SNMP==1: Turn on SNMP module. UDP must be available for SNMP
 * transport.
 */
#define LWIP_SNMP                       0


/*------------------------------------------------------------------------------
------------------------------- IGMP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_IGMP==1: Turn on IGMP module.
 */
#define LWIP_IGMP                       0


/*------------------------------------------------------------------------------
-------------------------------- DNS Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_DNS==1: Turn on DNS module. UDP must be available for DNS
 * transport.
 */
#define LWIP_DNS                        0
#define LWIP_DNS_API_DECLARE_H_ERRNO    1

/*------------------------------------------------------------------------------
-------------------------------- UDP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_UDP==1: Turn on UDP.
 */
#define LWIP_UDP                        1


/*------------------------------------------------------------------------------
-------------------------------- TCP Options -----------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_TCP==1: Turn on TCP.
 */
#define LWIP_TCP                        1

#define LWIP_LISTEN_BACKLOG             0


/*------------------------------------------------------------------------------
--------------------------------- LOOPIF Options -------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_HAVE_LOOPIF==1: Support loop interface (127.0.0.1) and loopif.c
 */
#define LWIP_HAVE_LOOPIF                0


/*------------------------------------------------------------------------------
---------------------------- Sequential Layer Options --------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_NETCONN==1: Enable Netconn API (require to use api_lib.c)
 */
#define LWIP_NETCONN                    1//(NO_SYS==0)


/*------------------------------------------------------------------------------
--------------------------------- Socket Options -------------------------------
------------------------------------------------------------------------------*/
/**
 * LWIP_SOCKET==1: Enable Socket API (require to use sockets.c)
 */

#define LWIP_SOCKET                     1//(NO_SYS==0)


/*------------------------------------------------------------------------------
------------------------------ Statistics Options ------------------------------
------------------------------------------------------------------------------*/

/**
 * LWIP_STATS==1: Enable statistics collection in lwip_stats.
 */
#define LWIP_STATS                      1

/*------------------------------------------------------------------------------
--------------------------------- PPP Options ----------------------------------
------------------------------------------------------------------------------*/

/**
 * PPP_SUPPORT==1: Enable PPP.
 */
#define PPP_SUPPORT                     0

#endif /* __LWIPOPTS_H__ */

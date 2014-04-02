/****************************************************************************
 *  (c) Copyright 2007 Wi-Fi Alliance.  All Rights Reserved
 *
 *
 *  LICENSE
 *
 *  License is granted only to Wi-Fi Alliance members and designated
 *  contractors ($B!H(BAuthorized Licensees$B!I(B)..AN  Authorized Licensees are granted
 *  the non-exclusive, worldwide, limited right to use, copy, import, export
 *  and distribute this software:
 *  (i) solely for noncommercial applications and solely for testing Wi-Fi
 *  equipment; and
 *  (ii) solely for the purpose of embedding the software into Authorized
 *  Licensee$B!G(Bs proprietary equipment and software products for distribution to
 *  its customers under a license with at least the same restrictions as
 *  contained in this License, including, without limitation, the disclaimer of
 *  warranty and limitation of liability, below..AN  The distribution rights
 *  granted in clause
 *  (ii), above, include distribution to third party companies who will
 *  redistribute the Authorized Licensee$B!G(Bs product to their customers with or
 *  without such third party$B!G(Bs private label. Other than expressly granted
 *  herein, this License is not transferable or sublicensable, and it does not
 *  extend to and may not be used with non-Wi-Fi applications..AN  Wi-Fi Alliance
 *  reserves all rights not expressly granted herein..AN 
 *.AN 
 *  Except as specifically set forth above, commercial derivative works of
 *  this software or applications that use the Wi-Fi scripts generated by this
 *  software are NOT AUTHORIZED without specific prior written permission from
 *  Wi-Fi Alliance.
 *.AN 
 *  Non-Commercial derivative works of this software for internal use are
 *  authorized and are limited by the same restrictions; provided, however,
 *  that the Authorized Licensee shall provide Wi-Fi Alliance with a copy of
 *  such derivative works under a perpetual, payment-free license to use,
 *  modify, and distribute such derivative works for purposes of testing Wi-Fi
 *  equipment.
 *.AN 
 *  Neither the name of the author nor "Wi-Fi Alliance" may be used to endorse
 *  or promote products that are derived from or that use this software without
 *  specific prior written permission from Wi-Fi Alliance.
 *
 *  THIS SOFTWARE IS PROVIDED BY WI-FI ALLIANCE "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A.AN PARTICULAR PURPOSE,
 *  ARE DISCLAIMED. IN NO EVENT SHALL WI-FI ALLIANCE BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, THE COST OF PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE) ARISING IN ANY WAY OUT OF
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ******************************************************************************
 */
 

/*
 * wfa_tg.h:
 *   Definitions used in Traffic Generator Modules
 */
#ifndef _WFA_TG_H
#define _WFA_TG_H

#include <sys/time.h>
#if 1 // by bbelief
#include <pthread.h>
#endif

/* maximum number of streams to support */
#define IPV4_ADDRESS_STRING_LEN    16

#define  MINISECONDS            1000
#define  MICROSECONDS           1000000
#define  NANOSECONDS            1000000000
#define  LINUX_TIMER_RES        20000000      /* 20 MINSECONDS */
#define  CA_RESPONSE_BUF_SIZE   128

/* Profile Key words */
#define KW_PROFILE                 1 
#define KW_DIRECTION               2
#define KW_DIPADDR                 3
#define KW_DPORT                   4
#define KW_SIPADDR                 5
#define KW_SPORT                   6
#define KW_FRATE                   7
#define KW_DURATION                8
#define KW_PLOAD                   9
#define KW_TCLASS                  10
#define KW_STREAMID                11
#define KW_COMPLETE                12
#define KW_ERROR                   13
#define KW_STARTDELAY              14
#define KW_NUMFRAME                15
#define KW_USESYNCCLOCK            16
#define KW_USERPRIORITY            17
#define KW_MAXCNT                  18

/* Profile Types */
#define PROF_FILE_TX               1
#define PROF_MCAST                 2
#define PROF_IPTV                  3
#define PROF_TRANSC                4
#define PROF_START_SYNC            5      /* this will be outdated */
#define PROF_CALI_RTD              5
#define PROF_UAPSD                 6
#define PROF_LAST                  7

/* stream state */
#define WFA_STREAM_INACTIVE        0
#define WFA_STREAM_ACTIVE          1

/* Traffic Directions */
#define DIRECT_SEND                1 
#define DIRECT_RECV                2 

#define TG_PROTO_TCP               0 
#define TG_PROTO_UDP               1

#define TG_WMM_AC_UP0         12     /* User Priority 0 */
#define TG_WMM_AC_UP1         13     /*               1 */
#define TG_WMM_AC_UP2         14     /*               2 */
#define TG_WMM_AC_UP3         15     /*               3 */
#define TG_WMM_AC_UP4         16     /*               4 */
#define TG_WMM_AC_UP5         17     /*               5 */
#define TG_WMM_AC_UP6         18     /*               6 */
#define TG_WMM_AC_UP7         19     /*               7 */

#define TG_WMM_AC_BE          1      /* Best Effort */
#define TG_WMM_AC_BK          2      /* Background  */
#define TG_WMM_AC_VI          3      /* Video       */
#define TG_WMM_AC_VO          4      /* Voice       */
#define TG_WMM_AC_UAPSD       5      /* UAPSD        */

#if 0
/* For wireless station, 802.11 defines 8 priority queues and 2 for each
 *  four catergories
 */
#define TG_WMM_AC_BE2       0x0a
#define TG_WMM_AC_BK2       0x0b
#define TG_WMM_AC_VI2       0x0c
#define TG_WMM_AC_VO2       0x0d
#endif

/* wmm defs */
#define TOS_VO      0xD0         // 110 0  0000 (6)  AC_VO tos/dscp values
//Atheros Madwifi use 0x88 for UPSD/Voice
//#define TOS_VO      0x88       // 110 0  0000 (6)  AC_VO tos/dscp values
#define TOS_VI      0xA0         // 101 0  0000 (5)  AC_VI
#define TOS_BE      0x00         // 000 0  0000 (0)  AC_BE
#define TOS_BK      0x20         // 001 0  0000 (1)  AC_BK

#define WFA_UDP_ECHO_STREAM_ID    0xFFFF
#define WFA_UDP_ECHO_PORT         07

#define WFA_PING_ICMP_ECHO         0
#define WFA_PING_UDP_ECHO          1

#define WFA_UPLOAD_VHSO_RPT        1

#define WFA_MCAST_FRATE            50       /* Multicast test rate is fixed at 50 frames/sec */

#define WFA_G_CODEC_RATE           50       /* G.729 50 pkt per second  = 20 ms interval */

typedef struct _tg_stats
{
    unsigned int txFrames;
    unsigned int rxFrames;
    unsigned long long txPayloadBytes;
    unsigned long long rxPayloadBytes;
    unsigned int outOfSequenceFrames; 
    unsigned int lostPkts;        /* voice over wi-fi */
    unsigned long jitter;         /* voice over wi-fi */
} tgStats_t;

typedef struct _e2e_stats
{
   int seqnum;
   int lsec;
   int lusec;
   int rsec;
   int rusec;
} tgE2EStats_t;

typedef struct _tg_profile
{
    int  profile;                           /* profile id                    */
    int  direction;
    char dipaddr[IPV4_ADDRESS_STRING_LEN];  /* destination/remote ip address */
    int  dport;
    char sipaddr[IPV4_ADDRESS_STRING_LEN];  /* source/local ip address       */
    int  sport;
    int  rate;
    int  duration;
    int  pksize;
    short trafficClass;      /* VO, VI, BK, BE */
    int  startdelay;
    int  maxcnt;
} tgProfile_t;

typedef struct _tg_stream
{
    int id;
    int sockfd;
    int tblidx;
    int lastPktSN;        /* use for Jitter calculation */
    int fmInterval;       
    int rxTimeLast;       /* use for pkLost             */
    int state;            /* indicate if the stream being active */
    tgProfile_t profile;
    tgStats_t stats;
} tgStream_t;

typedef struct _traffic_header
{
   char hdr[20];   /* always wfa */
} tgHeader_t;

//typedef struct _traffic_header
//{
//   char wfaname[8];   /* always wfa */
//   long int  counter; /* incremental counter */
//   long int first4;   /*            */
//   long int second4;  /*            */
//} tgHeader_t;

typedef struct _tg_wmm
{
    int thr_flag;    /* this is used to indicate stream id */
    int stop_flag;    /* this is used to indicate stream id */
#ifndef _WINDOWS
    pthread_t thr;
    int thr_id;
    pthread_cond_t thr_flag_cond;
    pthread_cond_t thr_stop_cond;
    pthread_mutex_t thr_flag_mutex;
    pthread_mutex_t thr_stop_mutex;
#else
	//LPCTSTR lpszMutex;
    HANDLE thr;
    DWORD thr_id;
	int timerid;
    HANDLE thr_flag_mutex;
    HANDLE thr_stop_mutex;
#endif
}tgWMM_t;

typedef int (*StationStateFunctionPtr)( char, int,int *); //PS,sleep period,state

typedef struct station_state_table
{
   StationStateFunctionPtr statefunc;
   char                    pw_offon;
   int                     sleep_period;
} StationProcStatetbl_t;

typedef int (*stationRecvStateFunctionPtr)(unsigned int *, int,int * ); //Recieved message buffer, length,state

typedef struct console_rcv_state_table
{
   stationRecvStateFunctionPtr statefunc;
} StationRecvProcStatetbl_t;

typedef struct _tg_thr_data
{
   int tid;
   StationProcStatetbl_t  *state;
   int state_num;
} tgThrData_t;

extern int wfaTGConfig(int len, BYTE *buf, int *respLen, BYTE *respBuf);
extern int wfaSendLongFile(int fromSockfd, int streamId, BYTE *respBuf, int *respLen);
extern int wfaRecvFile(int mySockfi, int profId, char *buf);
extern int wfaTGRecvStart(int len, BYTE *parms, int *respLen, BYTE *respBuf);
extern int wfaTGRecvStop(int len, BYTE *parms, int *respLen, BYTE *respBuf);
extern int wfaTGSendStart(int len, BYTE *parms, int *respLen, BYTE *respBuf);
extern int wfaTGReset(int len, BYTE *parms, int *respLen, BYTE *respBuf);
extern int wfaSendShortFile(int fromSockfd, int profId, BYTE *buf, int size, BYTE *respBuf, int *respLen);
extern int wfaFlushSockQueue(int profId);
extern int wfaTGSendPing(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf);
extern int wfaTGStopPing(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf);

#endif

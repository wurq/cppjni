//
// Created by wurongqiu on 2018/7/4.
//
/*
*/

/*
    * 简单贴一段介绍：
    * libnet是一个小型的接口函数库，主要用C语言写成，提供了低层网络数据包的构造、处理和发送功能。
    * libnet的开发目的是：建立一个简单统一的网络编程接口以屏蔽不同操作系统底层网络编程的差别，使得程序员将精力集中在解决关键问题上。
    */
//#include <libnet.h>

/* default snap length (maximum bytes per packet to capture) */
/*#define SNAP_LEN 65535

#ifdef COOKED
#define ETHERNET_H_LEN 16
#else
#define ETHERNET_H_LEN 14
#endif

#define SPECIAL_TTL 88
*/
#include <android/log.h>
#include "dnsaddr.h"



//#include <pcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>

#define ARGC_NUM 3

//#include <libnet.h>

#define SNAP_LEN 65535

#ifdef COOKED
#define ETHERNET_H_LEN 16
#else
#define ETHERNET_H_LEN 14
#endif

#define SPECIAL_TTL 88

dnsaddr::dnsaddr()
        : addr(1)
{

}

dnsaddr::~dnsaddr() {

}

void dnsaddr::setValue()  {
    addr = 1;
    __android_log_write(ANDROID_LOG_DEBUG,"dnsaddr","setValue");

}


//void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

//void print_usage(void);


/*
    * 打印帮助你信息，Linux程序的编程习惯了，这里没什么可说的
    */
void dnsaddr::print_usage(void) {
    printf("Usage: %s [interface][\"filter rule\"]\n", "net_speeder");
    printf("\n");
    printf("Options:\n");
    printf("    interface    Listen on <interface> for packets.\n");
    printf("    filter       Rules to filter packets.\n");
    printf("\n");
}


/*
    * 每次捕获到数据包，就会自动调用这个回调函数
    * 函数的参数分别为：
    * 1. 指向用户自定义数据的指针
    * 2. 一个用来描述当前捕获的数据包的pcap自定义结构体；
    * 其中包含了时间戳、已捕获长度、整体长度等信息，可以用于计算数据偏移，不过一般不怎么用
    * 3. 指向当前捕获的数据的指针，当然数据缓冲区是libpcap自己分配并管理的
    * 注意这个指针所指向数据的内容取决于接口的类型，一般情况下是普通的IEEE 802.3 Ethernet数据链路层协议，这个程序也是这样处理的
    * 具体的协议类型以及规范可以参考：http://www.tcpdump.org/linktypes.html
    */ /*
void dnsaddr::got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int count = 1;
    struct libnet_ipv4_hdr *ip;

    // 首先我们取出传递进来的libnet句柄，待会可以用来发包
    libnet_t *libnet_handler = (libnet_t *)args;
    count++;

    // 数据起始地址再加上以太帧头长度，就得到了IP包的头地址
    ip = (struct libnet_ipv4_hdr *)(packet + ETHERNET_H_LEN);

    if (ip->ip_ttl != SPECIAL_TTL) {
        // 为这个包设置特殊的TTL值，这是为了表示区分
        // 因为当我们把这个包重发以后，libpcap会再次抓到这个包
        // 如果不加以区分，就会把任何一个包无限次地重复发送，导致大量的无意义流量
        ip->ip_ttl = SPECIAL_TTL;
        // 调用libnet的函数强行再发一遍，如此暴力！
        int len_written = libnet_adv_write_raw_ipv4(libnet_handler, (u_int8_t *)ip, ntohs(ip->ip_len));
        // 当然发送有可能失败——网络上什么操作都可能有意外发生
        // 因此就把错误信息打印出来
        if (len_written < 0) {
            printf("packet len:[%d] actual write:[%d]\n", ntohs(ip->ip_len), len_written);
            printf("err msg:[%s]\n", libnet_geterror(libnet_handler));
        }
    } else {
        // 如果抓到的包是本程序自己重发的，直接忽略就行了
        //The packet net_speeder sent. nothing todo
    }
    return;
}*/

// 这么短的初始化函数非要单独拆分出来，也是有点画蛇添足
/*
libnet_t * dnsaddr::start_libnet(char *dev) {
    char errbuf[LIBNET_ERRBUF_SIZE];
    libnet_t *libnet_handler = libnet_init(LIBNET_RAW4_ADV, dev, errbuf);

    if (NULL == libnet_handler) {
        printf("libnet_init: error %s\n", errbuf);
    }
    return libnet_handler;
}
*/
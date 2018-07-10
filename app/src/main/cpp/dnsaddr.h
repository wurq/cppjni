//
// Created by wurongqiu on 2018/7/4.
//

#ifndef CPPJNI_DNSADDR_H
#define CPPJNI_DNSADDR_H

#include <sys/types.h>

class dnsaddr {
 public:
     // empty
     dnsaddr();
     // virtual destructor
     virtual ~dnsaddr();

     void setValue();

     //void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

     void print_usage(void);

     //libnet_t *start_libnet(char *dev)

 private:
     int addr;

};


#endif //CPPJNI_DNSADDR_H

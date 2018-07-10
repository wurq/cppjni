//
// Created by wurongqiu on 2018/7/9.
//

#ifndef CPPJNI_TARGET_H
#define CPPJNI_TARGET_H


class target {
public:
    /*
setnonblocking - 设置句柄为非阻塞方式
*/

    int setnonblocking(int sockfd);

/*
handle_message - 处理每个 socket 上的消息收发
*/
    int handle_message(int new_fd);


    void  sig_worker();
};


#endif //CPPJNI_TARGET_H

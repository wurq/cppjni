#include <jni.h>
#include <string>
#include <android/log.h>


#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <unistd.h>
#include <arpa/inet.h>
#include <strings.h>
#include "xhcore.h"
#include "xhook.h"

//#include "xh_core.h"
//#include <string.h>        // for bzero

static void my_thumb(int dummy)
{
//    const char *a="Hello world!";
//    char b[20];
//    __asm
//    {
//    MOV  R0,a
//    MOV  R1,b
//    BL my_strcpy,{R0,R1}
//    }
//}
//
//static int my_strcpy(const char *src,char *dst)
//{

//    __asm
//    {
//    loop:
//#ifndef __thumb
//    LDRB ch,[src],#1
//    STRB ch,[dst],#1
//#else
//    LDRB ch,[src]
//    ADD  src,#1
//    STRB ch,[dst]
//    ADD  dst,#1
//#endif
//    CMP ch,#0
//    BNE loop
//    }
//    __asm__("movw r0, #1001 \t\n"
//            "movw r12, #2020 \t\n"
//            "add r0, r0, r12 \t\n"
//            "bx  lr");

//    asm(".thumb");
//    asm(".syntax unified");

//    asm( "mov    r4,#123"  );
//    asm("sub r0, r0, r1");
//    asm("add r0, r0, #1");  // 为了区分当前用的是AArch32还是AArch64，这里对于AArch32情况下再加1
//    asm("bx lr");

//    asm volatile(
//            "movw r0, #1001 \t\n"
//            "movw r12, #2020 \t\n"
//            "add r0, r0, r12 \t\n"
//            "bx  lr"
//    );
//    return dummy;
}


/**
 * 测试内联汇编，分别根据AArch32架构以及AArch64架构来实现一个简单的减法计算
 * @param a 被减数
 * @param b 减数
 * @return 减法得到的差值
 */
static int __attribute__((naked, pure)) MyASMTest(int a, int b)
{
#ifdef __arm__

    asm(".thumb");
    asm(".syntax unified");

    asm("sub r0, r0, r1");
    asm("add r0, r0, #1");  // 为了区分当前用的是AArch32还是AArch64，这里对于AArch32情况下再加1
    asm("bx lr");

#else

    asm("sub w0, w0, w1");
    asm("ret");

#endif
}

//
extern "C"
JNIEXPORT jstring



JNICALL
//jstring
Java_com_arch_cppjni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

//#if defined(__arm__)
//    #if defined(__ARM_ARCH_7A__)
//    #if defined(__ARM_NEON__)
//      #if defined(__ARM_PCS_VFP)
//        #define ABI "armeabi-v7a/NEON (hard-float)"
//      #else
//        #define ABI "armeabi-v7a/NEON"
//      #endif
//    #else
//      #if defined(__ARM_PCS_VFP)
//        #define ABI "armeabi-v7a (hard-float)"
//      #else
//        #define ABI "armeabi-v7a"
//      #endif
//    #endif
//  #else
//   #define ABI "armeabi"
//  #endif
//#elif defined(__i386__)
//#define ABI "x86"
//#elif defined(__x86_64__)
//#define ABI "x86_64"
//#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
//#define ABI "mips64"
//#elif defined(__mips__)
//#define ABI "mips"
//#elif defined(__aarch64__)
//#define ABI "arm64-v8a"
//#else
//#define ABI "unknown"
//#endif
//    my_thumb(0);
    std::string hello = "Hello from CPP";

    __android_log_write(ANDROID_LOG_DEBUG,"main_join","Messageqq");
    char strBuf[128];

    sprintf(strBuf, "Hello from C! ASM test result: %d", MyASMTest(19, 4));

//    dnsaddr *dnsad = new dnsaddr();
//    dnsad->setValue();
//    delete dnsad;

    return env->NewStringUTF(strBuf/*hello.c_str()*/);
}


//
//static int my_thumb(int dummy)
//{
//    __asm__("movw r0, #1001 \t\n"
//            "movw r12, #2020 \t\n"
//            "add r0, r0, r12 \t\n"
//            "bx  lr");
//
//    return dummy;
//}



#define SERVER_PORT 5000
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

//int main(int argc, char **argv)

int sock()
{
//    if (argc != 2)
//    {
//        printf("Please input the IP address of the server \n", argv[0]);
//        exit(1);
//    }

    //设置一个socket地址结构client_addr,代表客户机internet地址, 端口
    struct sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr)); //把一段内存区的内容全部设置为0
    client_addr.sin_family = AF_INET; //internet协议族
    client_addr.sin_addr.s_addr = htons(INADDR_ANY); //INADDR_ANY表示自动获取本机地址
    client_addr.sin_port = htons(0); //0表示让系统自动分配一个空闲端口
    //创建用于internet的流协议(TCP)socket,用client_socket代表客户机socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        printf("Create Socket Failed!\n");
        exit(1);
    }
    //把客户机的socket和客户机的socket地址结构联系起来
    if (bind(client_socket, (struct sockaddr*) &client_addr,
             sizeof(client_addr)))
    {
        printf("Client Bind Port Failed!\n");
        exit(1);
    }

    //设置一个socket地址结构server_addr,代表服务器的internet地址, 端口
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
//    if (inet_aton(argv[1], &server_addr.sin_addr) == 0) //服务器的IP地址来自程序的参数
//    {
//        printf("Server IP Address Error! \n");
//        exit(1);
//    }

    server_addr.sin_port = htons(SERVER_PORT);
    socklen_t server_addr_length = sizeof(server_addr);
    // 向服务器发起连接,连接成功后client_socket代表了客户机和服务器的一个socket连接
    if (connect(client_socket, (struct sockaddr*) &server_addr,
                server_addr_length) < 0)
    {
//        printf("Can Not Connect To %s!\n", argv[1]);
        exit(1);
    }

    sleep(10);
    close(client_socket);
    return 0;
}


extern "C"
{

#define JNI_API_DEF(f) Java_com_arch_util_NativeHandler_##f


JNIEXPORT jint JNICALL
JNI_API_DEF(refresh)(JNIEnv *env, jobject instance, jboolean async) {

    // TODO
    return xhook_refresh(async);
}


JNIEXPORT void JNICALL
Java_com_arch_util_NativeHandler_clear(JNIEnv *env, jobject instance) {

    // TODO
    return xhook_clear();
}


JNIEXPORT void
JNICALL
Java_com_arch_util_NativeHandler_enableDebug(JNIEnv *env, jobject instance, jboolean flag) {

    return xhook_enable_debug(flag);
// TODO
    __android_log_write(ANDROID_LOG_DEBUG,"NativeHandler","enableDebug");
//    int a;
//    a=2;
}


JNIEXPORT void JNICALL
Java_com_arch_util_NativeHandler_enableSigSegvProtection(JNIEnv *env, jobject instance,
                                                         jboolean flag) {

    // TODO
    return xhook_enable_sigsegv_protection(flag);
}
}
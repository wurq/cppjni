#include <jni.h>
#include <string>
#include <android/log.h>


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

    sprintf(strBuf, "Hello from C! ASM test result: %d", MyASMTest(6, 4));

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
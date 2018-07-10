//
// Created by wurongqiu on 2018/7/10.
//


#include <jni.h>
#include <android/log.h>


extern "C"


JNIEXPORT jint JNICALL
Java_com_arch_util_NativeHandler_refresh(JNIEnv *env, jobject instance, jboolean async) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_arch_util_NativeHandler_clear(JNIEnv *env, jobject instance) {

    // TODO

}

extern "C"
JNIEXPORT void
JNICALL
Java_com_arch_util_NativeHandler_enableDebug(JNIEnv *env, jobject instance, jboolean flag) {

// TODO
    __android_log_write(ANDROID_LOG_DEBUG,"NativeHandler","enableDebug");
    int a;
    a=2;
}

JNIEXPORT void JNICALL
Java_com_arch_util_NativeHandler_enableSigSegvProtection(JNIEnv *env, jobject instance,
                                                         jboolean flag) {

    // TODO

}


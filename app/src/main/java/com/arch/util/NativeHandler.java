package com.arch.util;

/**
 * Created by wurongqiu on 2018/7/10.
 */

public class NativeHandler {

    private static final NativeHandler ourInstance = new NativeHandler();

    public static NativeHandler getInstance() {
        return ourInstance;
    }

    private NativeHandler() {
    }

    public native int refresh(boolean async);

    public native void clear();

    public native void enableDebug(boolean flag);

    public native void enableSigSegvProtection(boolean flag);

//    static {
//        System.loadLibrary("native-lib");
//    }
}

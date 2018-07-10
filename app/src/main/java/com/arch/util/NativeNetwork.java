package com.arch.util;

import android.graphics.Bitmap;

/**
 * Created by wurongqiu on 2018/7/10.
 */

public class NativeNetwork {
    public native boolean Init(byte[] param, byte[] bin, byte[] words);

    public native String Detect(Bitmap bitmap);

    static {
        System.loadLibrary("native-net");
    }
}

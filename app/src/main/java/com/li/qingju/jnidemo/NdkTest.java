package com.li.qingju.jnidemo;

import android.util.Base64;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.List;

/**
 * Created by liqingju on 16/10/12.
 */
public class NdkTest {
    static {
        System.loadLibrary("NdkTest");//加载要使用的so文件
    }

    //生命native方法
    public static native String getString();

    public static native int doAdd(int param1, int param2);

    public static native String base64(String[] strs);
    public static native int getBaseb64Code();


}

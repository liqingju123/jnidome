package com.li.qingju.jnidemo;

import android.util.Base64;
import android.util.Log;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

/**
 * Created by liqingju on 16/10/17.
 */
public class Base64Demo {


    public static String h2(String message){
        byte[] input = message.getBytes();
        MessageDigest sha = null;
        try {
            sha = MessageDigest.getInstance("SHA-256");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        sha.update(input);
        byte[] output = sha.digest();
        String result = Base64.encodeToString(output,32);
        Log.e("result====",result);
        return  result;
    }


}

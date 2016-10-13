package com.li.qingju.jnidemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import com.li.qingju.jni_demo.R;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//       NdkTest ndkTest = new NdkTest();
    int sum =    NdkTest.doAdd(20,30);
        Log.e("====   ",sum+"");
    }


}

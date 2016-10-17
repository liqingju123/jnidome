package com.li.qingju.jnidemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import com.li.qingju.jni_demo.R;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        Base64Demo.h2("222||111111111111111");
        List<String> lists = new ArrayList<String>();
        lists.add("222");
        lists.add("111111111111111");
//        String[] strs =;
        NdkTest.base64(lists.toArray(new String[lists.size()]));
    }

    public void NDK(){
        int sum = NdkTest.doAdd(20, 30);
        Log.e("====   ", sum + "" + "   " + NdkTest.getString());
        ReadTxtFile("/sdcard/我是测试");
    }


    public static String ReadTxtFile(String strFilePath) {
        String path = strFilePath;
        String content = ""; //文件内容字符串
        //打开文件
        File file = new File(path);
        //如果path是传递过来的参数，可以做一个非目录的判断
        if (file.isDirectory())
        {
            Log.d("TestFile", "The File doesn't not exist.");
        }
        else
        {
            try {
                InputStream instream = new FileInputStream(file);
                if (instream != null)
                {
                    InputStreamReader inputreader = new InputStreamReader(instream);
                    BufferedReader buffreader = new BufferedReader(inputreader);
                    String line;
                    //分行读取
                    while (( line = buffreader.readLine()) != null) {
                        content += line + "\n";
                    }
                    instream.close();
                    Log.e("======",content);
                }
            }
            catch (java.io.FileNotFoundException e)
            {
                Log.d("TestFile", "The File doesn't not exist.");
            }
            catch (IOException e)
            {
                Log.d("TestFile", e.getMessage());
            }
        }
        return content;
    }

}

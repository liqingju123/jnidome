#include <jni.h>
#include "com.li.qingju.jnidemo.NdkTest.h"
#include <string.h>
#include <android/log.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define   LOG_TAG    "LOG_TEST"
#define MAXLINE 20
#define   LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define   LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


JNIEXPORT jstring JNICALL Java_com_li_qingju_jnidemo_NdkTest_getString(JNIEnv *env, jclass type) {
    char myStr[19];
    FILE* fp = fopen("/sdcard/我是测试","r");
    if(fp!=NULL)
    {
        fgets(myStr,19,fp);
        fflush(fp);
        fclose(fp);
        return env->NewStringUTF(myStr);
    }
    else
    {
        fclose(fp);
        return env->NewStringUTF("Error opening file!");
    }


//    return env->NewStringUTF("hello world!!!");
}


JNIEXPORT jint  JNICALL Java_com_li_qingju_jnidemo_NdkTest_doAdd(JNIEnv *env, jclass type, jint param1, jint param2) {
    LOGI("我只是打印而已");
//    read_locat_txt();
    return param1 + param2;
}


void read_locat_txt()
{
    char myStr[20];
    FILE* fp = fopen("/sdcard/我是测试","r");
    if(fp!=NULL)
    {
        fgets(myStr,20,fp);
        fflush(fp);
        fclose(fp);
       LOGI("======,%s",myStr);

    }
    else
    {
        fclose(fp);
        LOGI("======错误,%s",myStr);
    }
}
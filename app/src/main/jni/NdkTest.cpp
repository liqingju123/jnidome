#include <jni.h>
#include "com.li.qingju.jnidemo.NdkTest.h"
#include <string.h>
#include <android/log.h>
#define   LOG_TAG    "LOG_TEST"
#define   LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define   LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


JNIEXPORT jstring JNICALL Java_com_li_qingju_jni_demo_NdkTest_getString(JNIEnv *env, jclass type) {

    return env->NewStringUTF("hello world!!!");
}


JNIEXPORT jint  JNICALL Java_com_li_qingju_jnidemo_NdkTest_doAdd(JNIEnv *env, jclass type, jint param1, jint param2) {
    LOGI("我只是打印而已");
    return param1 + param2;
}
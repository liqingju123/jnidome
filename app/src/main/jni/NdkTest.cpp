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


char *join(char *s1, const  char *s2);

JNIEXPORT jstring JNICALL Java_com_li_qingju_jnidemo_NdkTest_getString(JNIEnv *env, jclass type) {
    char myStr[19];
    FILE *fp = fopen("/sdcard/我是测试", "r");
    if (fp != NULL) {
        fgets(myStr, 19, fp);
        fflush(fp);
        fclose(fp);
        return env->NewStringUTF(myStr);
    }
    else {
        fclose(fp);
        return env->NewStringUTF("Error opening file!");
    }


//    return env->NewStringUTF("hello world!!!");
}

JNIEXPORT jstring JNICALL Java_com_li_qingju_jnidemo_NdkTest_base64(JNIEnv *env, jclass type,
                                                                    jobjectArray stringArray) {
    LOGI("======  %s", "我是JNI的需要");
    int size = env->GetArrayLength(stringArray);
    char *chars;
    char *one_char;
    const char *jionType = "__";
    for (int i = 0; i < size; ++i) {
        jstring str = (jstring) env->GetObjectArrayElement(stringArray, i);
        one_char = (char *) env->GetStringUTFChars(str, NULL);
//        one_char = join(one_char,jionType);
//        chars =join(chars,one_char);
    }
    LOGI("======  %s", chars);
    return env->NewStringUTF(chars);

}


JNIEXPORT jint  JNICALL Java_com_li_qingju_jnidemo_NdkTest_doAdd(JNIEnv *env, jclass type,
                                                                 jint param1, jint param2) {
    LOGI("我只是打印而已");
//    read_locat_txt();
    return param1 + param2;
}


void read_locat_txt() {
    char myStr[20];
    FILE *fp = fopen("/sdcard/我是测试", "r");
    if (fp != NULL) {
        fgets(myStr, 20, fp);
        fflush(fp);
        fclose(fp);
        LOGI("======,%s", myStr);

    }
    else {
        fclose(fp);
        LOGI("======错误,%s", myStr);
    }
}

char *join(char *s1, const char *s2) {
   char *result =  (char *)malloc(strlen(s1) + strlen(s2) + 1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
//    if (result == NULL) exit (1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}
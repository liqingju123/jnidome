

#include "com.li.qingju.jnidemo.NdkTest.h"

JNIEXPORT jstring JNICALL Java_com_li_qingju_jni_demo_NdkTest_getString(JNIEnv *env, jclass type) {

    return env->NewStringUTF("hello world!!!");
}


JNIEXPORT jint  JNICALL Java_com_li_qingju_jnidemo_NdkTest_doAdd(JNIEnv *env, jclass type, jint param1, jint param2) {

    return param1 + param1;
}
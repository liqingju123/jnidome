//
// Created by liqingju on 16/10/12.
//


#include <jni.h>


#ifndef _Included_com_li_qingju_jnidemo_NdkTest
#define _Included_com_li_qingju_jnidemo_NdkTest
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_li_qingju_jnidemo_NdkTest_getString(JNIEnv *, jclass);


JNIEXPORT jint JNICALL Java_com_li_qingju_jnidemo_NdkTest_doAdd(JNIEnv *, jclass, jint, jint);
JNIEXPORT jstring JNICALL Java_com_li_qingju_jnidemo_NdkTest_base64(JNIEnv *, jclass, jobjectArray);
void  read_locat_txt();
char* join3(char, char);

#ifdef __cplusplus
}
#endif
#endif
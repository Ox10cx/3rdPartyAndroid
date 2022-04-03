#include <jni.h>
#include <string>

#include "zlib.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_libzlib_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {

    /*原始数据*/
    unsigned char strsrc[] = "这些是测试数据。123456789 abcdefghigklmnopqrstuvwxyz\n\t\0abcdefghijklmnopqrstuvwxyz\n"; //包含\0字符
    unsigned char buf[1024] = {0};
    unsigned char strdst[1024] = {0};
    unsigned long srclen = sizeof(strsrc);
    unsigned long buflen = sizeof(buf);
    unsigned long dstlen = sizeof(strdst);
    int i;
    //    FILE * fp;

    printf("源串:");
    for (i = 0; i < srclen; ++i)
    {
        printf("%c", strsrc[i]);
    }
    printf("原串长度为:%ld\n", srclen);

    printf("字符串预计算长度为:%ld\n", compressBound(srclen));

    std::string hello = "Hello from C++ libzlib";

    return env->NewStringUTF(hello.c_str());
}
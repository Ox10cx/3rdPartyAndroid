#include <jni.h>
#include <string>

#include <jpeglib.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_libjpeg_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {
    struct jpeg_error_mgr jerr;
    jpeg_std_error(&jerr);
    std::string hello = "Hello from C++ libjpeg";
    return env->NewStringUTF(hello.c_str());
}
#include <jni.h>
#include <string>
#include "tiffio.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_libtiff_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {
    TIFF  *tiffFile = TIFFOpen("", "r");
    std::string hello = "Hello from  C++ libtiff";
    return env->NewStringUTF(hello.c_str());
}
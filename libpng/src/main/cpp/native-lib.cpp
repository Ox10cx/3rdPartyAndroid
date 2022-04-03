#include <jni.h>
#include <string>
#include "png.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_libpng_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_create_info_struct(png_ptr);
    std::string hello = "Hello from C++ libpng";
    return env->NewStringUTF(hello.c_str());
}
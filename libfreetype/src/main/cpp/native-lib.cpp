#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_libfreetype_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {
    std::string hello = "Hello from C++ freeType";
    return env->NewStringUTF(hello.c_str());
}
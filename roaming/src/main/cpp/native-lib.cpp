#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_gx_roaming_RoamingNative_stringFromJNI(
        JNIEnv* env,
        jclass /* this */) {
    std::string hello = "Hello from C++ Roaming";
    return env->NewStringUTF(hello.c_str());
}
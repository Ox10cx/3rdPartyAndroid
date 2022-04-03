# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/${ANDROID_ABI})

# Declares and names the project.

#project("ctest")


include_directories(src/main/cpp)



file(GLOB lib_srcs src/main/cpp/*.c)
file(GLOB lib_hdrs src/main/cpp/*.h)



# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


add_library( # Sets the name of the library.
             jpeg

             # Sets the library as a shared library.
#             SHARED
             STATIC

             # Provides a relative path to your source file(s).
             ${lib_srcs}
             ${lib_hdrs}
#             src/main/cpp/native-lib.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        jpeg


       # Links the target library to the log library
       # included in the NDK.
       ${log-lib} )


#cmake ../  -DANDROID_NDK=/Users/gongxi/tools/android-ndk-r19c -DCMAKE_TOOLCHAIN_FILE=/Users/gongxi/tools/android-ndk-r19c/build/cmake/android.toolchain.cmake  -DANDROID_TOOLCHAIN=clang  -DANDROID_PLATFORM=android-21 -DANDROID_ABI=arm64-v8a
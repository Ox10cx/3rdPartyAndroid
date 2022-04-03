# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

# png库名
set( project_name png )
project(${project_name})


include_directories(src/main/cpp)

file(GLOB lib_srcs src/main/cpp/*.c)
file(GLOB lib_hdrs src/main/cpp/*.h)
set(lib_ext_hdrs "src/main/cpp/png.h" "src/main/cpp/pngconf.h")

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W3")
endif()

if(UNIX)
    if(CMAKE_COMPILER_IS_GNUCXX OR CV_ICC)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    endif()
endif()


##C 的编译选项是 CMAKE_C_FLAGS
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -fno-short-enums ")
## 指定编译参数，可选
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -DOSG_LIBRARY_STATIC -frtti -fexceptions ")

#set(CMAKE_SHARED_LINKER_FLAGS "-Wall -v -Wl, --warn-shared-textrel=no")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# 链接系统的zlib库
find_package( zlib REQUIRED )


add_library( # Sets the name of the library.
             png

             # Sets the library as a shared library.
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

target_link_libraries(png PUBLIC ZLIB::ZLIB)
target_include_directories( ${project_name} PUBLIC
        $<BUILD_INTERFACE:${source_dir}>
        $<INSTALL_INTERFACE:include>
        )
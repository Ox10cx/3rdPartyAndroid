# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

#project("ctest")

add_definitions("-DDARWIN_NO_CARBON")
add_definitions("-DFT2_BUILD_LIBRARY")


include_directories(src/main/cpp/builds
        src/main/cpp/include
        src/main/cpp/include/freetype
        src/main/cpp/include/freetype/config
        src/main/cpp/include/freetype/internal
        src/main/cpp/include/freetype/internal/services
        src/main/cpp/src/autofit
        src/main/cpp/src/base
        src/main/cpp/src/cff
        src/main/cpp/src/psaux
        src/main/cpp/src/pshinter
        src/main/cpp/src/psnames
        src/main/cpp/src/raster
        src/main/cpp/src/sfnt
        src/main/cpp/src/smooth
        src/main/cpp/src/truetype)

#src/base/ftbbox.c \
#src/base/ftbitmap.c \
#src/base/ftglyph.c \
#src/base/ftstroke.c \
#src/base/ftxf86.c \
#src/base/ftbase.c \
#src/base/ftsystem.c \
#src/base/ftinit.c \
#src/base/ftgasp.c \
#
#src/raster/raster.c \
#src/sfnt/sfnt.c \
#src/smooth/smooth.c \
#src/autofit/autofit.c \
#src/truetype/truetype.c \
#src/cff/cff.c \
#src/psnames/psnames.c \
#src/pshinter/pshinter.c


#file(GLOB lib_srcs "src/main/cpp/src/autofit/*.c",
#        "src/main/cpp/src/base/*.c",
#        "src/main/cpp/src/cff/*.c",
#        "src/main/cpp/src/psaux/*.c",
#        "src/main/cpp/src/pshinter/*.c",
#        "src/main/cpp/src/psnames/*.c",
#        "src/main/cpp/src/raster/*.c",
#        "src/main/cpp/src/sfnt/*.c",
#        "src/main/cpp/src/smooth/*.c"
#        "src/main/cpp/src/truetype/*.c")

#file(GLOB lib_hdrs src/main/cpp/*.h)


##C 的编译选项是 CMAKE_C_FLAGS
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -W -Wall -fPIC -DPIC -O2")
## 指定编译参数，可选
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -DOSG_LIBRARY_STATIC -frtti -fexceptions ")

#set(CMAKE_SHARED_LINKER_FLAGS "-Wall -v -Wl, --warn-shared-textrel=no")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


add_library( # Sets the name of the library.
             ft2

             # Sets the library as a shared library.
#             SHARED
             STATIC

             # Provides a relative path to your source file(s).
             src/main/cpp/src/base/ftbbox.c
             src/main/cpp/src/base/ftbitmap.c
             src/main/cpp/src/base/ftglyph.c
             src/main/cpp/src/base/ftstroke.c
             src/main/cpp/src/base/ftxf86.c
             src/main/cpp/src/base/ftbase.c
             src/main/cpp/src/base/ftsystem.c
             src/main/cpp/src/base/ftinit.c
             src/main/cpp/src/base/ftgasp.c
             src/main/cpp/src/raster/raster.c
             src/main/cpp/src/sfnt/sfnt.c
             src/main/cpp/src/smooth/smooth.c
             src/main/cpp/src/autofit/autofit.c
             src/main/cpp/src/truetype/truetype.c
             src/main/cpp/src/cff/cff.c
             src/main/cpp/src/psnames/psnames.c
             src/main/cpp/src/pshinter/pshinter.c
#             ${lib_srcs}
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
        ft2


       # Links the target library to the log library
       # included in the NDK.
       ${log-lib} )
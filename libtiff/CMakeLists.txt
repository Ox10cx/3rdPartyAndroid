# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

#project("ctest")

add_definitions(-DHAVE_STRING_H=1)

include_directories(src/main/cpp)


set(lib_srcs
        src/main/cpp/t4.h
        src/main/cpp/tiffio.hxx
        src/main/cpp/tiffiop.h
        src/main/cpp/tif_aux.c
        src/main/cpp/tif_close.c
        src/main/cpp/tif_codec.c
        src/main/cpp/tif_color.c
        src/main/cpp/tif_compress.c
        src/main/cpp/tif_dir.c
        src/main/cpp/tif_dir.h
        src/main/cpp/tif_dirinfo.c
        src/main/cpp/tif_dirread.c
        src/main/cpp/tif_dirwrite.c
        src/main/cpp/tif_dumpmode.c
        src/main/cpp/tif_error.c
        src/main/cpp/tif_extension.c
        src/main/cpp/tif_fax3.c
        src/main/cpp/tif_fax3.h
        src/main/cpp/tif_fax3sm.c
        src/main/cpp/tif_flush.c
        src/main/cpp/tif_getimage.c
        src/main/cpp/tif_jbig.c
        src/main/cpp/tif_jpeg.c
        src/main/cpp/tif_luv.c
        src/main/cpp/tif_lzw.c
        src/main/cpp/tif_next.c
        src/main/cpp/tif_ojpeg.c
        src/main/cpp/tif_open.c
        src/main/cpp/tif_packbits.c
        src/main/cpp/tif_pixarlog.c
        src/main/cpp/tif_predict.c
        src/main/cpp/tif_predict.h
        src/main/cpp/tif_print.c
        src/main/cpp/tif_read.c
        src/main/cpp/tif_stream.cxx
        src/main/cpp/tif_strip.c
        src/main/cpp/tif_swab.c
        src/main/cpp/tif_thunder.c
        src/main/cpp/tif_tile.c
        src/main/cpp/tif_version.c
        src/main/cpp/tif_warning.c
        src/main/cpp/tif_write.c
        src/main/cpp/tif_zip.c
        src/main/cpp/uvcode.h
        )


if(UNIX)
    set(lib_srcs ${lib_srcs} src/main/cpp/tif_unix.c)
endif()

if(WIN32)
    set(lib_srcs ${lib_srcs} src/main/cpp/tif_win32.c)
endif(WIN32)

#if(APPLE)
#    set(lib_srcs ${lib_srcs} tif_apple.c)
#endif(APPLE)

file(GLOB lib_hdrs src/main/cpp/*.h*)

set(lib_ext_hdrs "src/main/cpp/tiff.h" "src/main/cpp/tiffio.h" "src/main/cpp/tiffvers.h" "src/main/cpp/tiffconf.h")

if(MSVC)
    string(REPLACE "/W4" "/W0" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    string(REPLACE "/W4" "/W0" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

if(UNIX)
    if(CMAKE_COMPILER_IS_GNUCXX OR CV_ICC)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    endif()
endif()

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.


add_library( # Sets the name of the library.
             tiff

             # Sets the library as a shared library.
#             SHARED
             STATIC

             # Provides a relative path to your source file(s).
            ${lib_srcs}
            ${lib_hdrs}
            ${lib_ext_hdrs}
#            src/main/cpp/native-lib.cpp
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
        tiff


       # Links the target library to the log library
       # included in the NDK.
       ${log-lib} )
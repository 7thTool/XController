# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


MESSAGE(STATUS "This is coding PROJECT BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is coding CMAKE BINARY dir " ${CMAKE_BINARY_DIR})
MESSAGE(STATUS "This is coding PROJECT SOURCE dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "This is coding CMAKE SOURCE dir " ${CMAKE_SOURCE_DIR})

MESSAGE(STATUS "This is coding current BINARY dir " ${CMAKE_CURRENT_BINARY_DIR})
MESSAGE(STATUS "This is coding current SOURCE dir " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE(STATUS "This is coding current CMAKE SOURCE dir " ${CMAKE_CURRENT_SOURCE_DIR})
MESSAGE(STATUS "This is coding current CMakeList.txt dir " ${CMAKE_CURRENT_LIST_DIR})
MESSAGE(STATUS "This is coding current CMakeList.txt line " ${CMAKE_CURRENT_LIST_LINE})

MESSAGE(STATUS "This is coding library output " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

ADD_DEFINITIONS(-std=c++17)

include_directories(../XUtil)

aux_source_directory(. libSRC_LIST)
set(libSRC_LIST ${libSRC_LIST} 
../XUtil/XApi.cpp
)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        XController

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        ${libSRC_LIST}
        )
add_library( # Sets the name of the library.
        XController

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${libSRC_LIST}
        )
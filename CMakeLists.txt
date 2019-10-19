cmake_minimum_required (VERSION 2.6)

set(RELEASE_VERSION_MAJOR $ENV{RELEASE_VERSION_MAJOR})
IF(RELEASE_VERSION_MAJOR STREQUAL "6")
    set(CMAKE_CXX_COMPILER "/usr/local/gcc/bin/c++")
ENDIF()

project (test)

IF(NOT CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE Release)
ENDIF(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS " -g -pipe -std=c++0x -W -Wall -fPIC -pthread")
#set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++ -g -pipe -std=c++0x -W -Wall -fPIC -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__FILENAME__='\"$(notdir $<)\"'")
message("CMAKE_CXX_FLAGS:" ${CMAKE_CXX_FLAGS})

set(PROJECT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/)

set(SRC_ROOT ${PROJECT_DIR}/src/)

include_directories(
    ${SRC_ROOT}
    )

file(GLOB SOURCE_FILE
    "${SRC_ROOT}/*.cpp"
    )

add_executable(test ${SOURCE_FILE})

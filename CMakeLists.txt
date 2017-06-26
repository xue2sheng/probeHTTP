cmake_minimum_required(VERSION 3.5)

## QtCreator ##
if(QMAKE_CXX)
    set(CMAKE_CXX_COMPILER "${QMAKE_CXX}")
endif(QMAKE_CXX)

project(probeHTTP CXX)

add_subdirectory(src)

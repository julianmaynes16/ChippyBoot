cmake_minimum_required(VERSION 3.0)
project(ChippyBoot)

set(SOURCES src/chippyboot.cpp)

set(HEADERS include/chippyboot.hpp)

add_library(ChippyBoot STATIC ${SOURCES} ${HEADERS})

target_include_directories(ChippyBoot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

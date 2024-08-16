cmake_minimum_required(VERSION 3.0)
project(ChippyBoot)

set(SOURCES src/chippyboot.cpp)

set(HEADERS include/chippyboot.h)

add_library(ChippyBootDll SHARED ${SOURCES})
set_target_properties(ChippyBootDll PROPERTIES OUTPUT_NAME ChippyBoot)

add_library(ChippyBootLib STATIC ${SOURCES} ${HEADERS})
set_target_properties(ChippyBootLib PROPERTIES OUTPUT_NAME ChippyBoot)

target_include_directories(ChippyBootDll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ChippyBootLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

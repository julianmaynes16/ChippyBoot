cmake_minimum_required(VERSION 3.0)
project(ChippyBoot)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/pkg)

set(SOURCES src/chippyboot.cpp)

set(HEADERS include/chippyboot.h)

add_library(ChippyBootDll SHARED ${SOURCES})
set_target_properties(ChippyBootDll PROPERTIES OUTPUT_NAME ChippyBoot)

add_library(ChippyBoota STATIC ${SOURCES} ${HEADERS})
set_target_properties(ChippyBoota PROPERTIES OUTPUT_NAME ChippyBoot)

target_include_directories(ChippyBootDll PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(ChippyBoota PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

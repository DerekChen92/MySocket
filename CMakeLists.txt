cmake_minimum_required(VERSION 3.0)

set(CMAKE_SYSTEM_PROCESSOR "arm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -fPIC -DPIC -D__STDC_CONSTANT_MACROS -O2 -funwind-tables -ffunction-sections -fdata-sections -MMD -mfpu=neon")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fPIC -DPIC -D__STDC_CONSTANT_MACROS -O2 -funwind-tables -ffunction-sections -fdata-sections -MMD -mfpu=neon -Wno-unused-function")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

project(SocketClient)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(MySocketClient
    ${SRC_FILES}
)

target_link_libraries(MySocketClient
    -lpthread 
)

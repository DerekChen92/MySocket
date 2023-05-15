cmake_minimum_required(VERSION 3.0)

set(CMAKE_FIND_ROOT_PATH "/opt/sigmastar/gcc-sigmastar-9.1.0-2020.07-x86_64_arm-linux-gnueabihf/gcc-sigmastar-9.1.0-2020.07-x86_64_arm-linux-gnueabihf")
set(INCLUDE_PATH ${CMAKE_FIND_ROOT_PATH}/arm-linux-gnueabihf/libc/usr/include)

message(STATUS "Root path: ${CMAKE_FIND_ROOT_PATH}")
set(CMAKE_C_COMPILER ${CMAKE_FIND_ROOT_PATH}/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER ${CMAKE_FIND_ROOT_PATH}/bin/arm-linux-gnueabihf-g++)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_SYSTEM_PROCESSOR "arm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -fPIC -DPIC -D__STDC_CONSTANT_MACROS -O2 -funwind-tables -ffunction-sections -fdata-sections -MMD -mfpu=neon")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fPIC -DPIC -D__STDC_CONSTANT_MACROS -O2 -funwind-tables -ffunction-sections -fdata-sections -MMD -mfpu=neon -Wno-unused-function")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
set(OMNI_PROJECT_DIR "${CMAKE_SOURCE_DIR}/../../../../project")
set(CARDV_INC "${CMAKE_SOURCE_DIR}/../cardv/inc")


project(mai_hal)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../common/include
    ${CMAKE_SOURCE_DIR}/../nmealib/include
    ${CMAKE_SOURCE_DIR}/../DCF
    ${CMAKE_SOURCE_DIR}/../cloud_service/include
    ${PROJECT_SOURCE_DIR}/../../../../project/release/include
)

link_directories(
    ${PROJECT_SOURCE_DIR}/../../../../project/release/chip/m6/cardv/common/glibc/9.1.0/mi_libs/dynamic
    ${PROJECT_SOURCE_DIR}/../../../../project/release/chip/m6/cardv/common/glibc/9.1.0/3rd_party_libs/dynamic
    ${PROJECT_SOURCE_DIR}/../../../../project/release/chip/m6/sigma_common_libs/glibc/9.1.0/dynamic
)

file(GLOB MAI_HAL_SOURCE
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
)

file(GLOB MAI_COMMON_SOURCE
    ${CMAKE_SOURCE_DIR}/../common/src/*.cpp
    ${CMAKE_SOURCE_DIR}/../cloud_service/src/mai_device_utils.cpp
)

message(${OMNI_PROJECT_DIR})

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(mai_hal
    ${MAI_HAL_SOURCE}
    ${MAI_COMMON_SOURCE}
)

link_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/../nmealib/glibc-lib
    ${CMAKE_SOURCE_DIR}/../opencv/lib
    ${CMAKE_SOURCE_DIR}/../opencv/lib/3rdparty
)

set(mi_libs
    libmi_sys.so
)

set(sigma_common_libs
    libcam_fs_wrapper.so
    libcam_os_wrapper.so
)

target_link_libraries(mai_hal
    -lpthread -ldl -lrt
    ${CMAKE_SOURCE_DIR}/../nmealib/glibc-lib/libnmea.a
    ${mi_libs}
    ${sigma_common_libs}
    stdc++fs
)
find_package(OpenCV 3.3.1 EXACT REQUIRED PATHS /opt/sigmastar/gcc-sigmastar-9.1.0-2020.07-x86_64_arm-linux-gnueabihf/gcc-sigmastar-9.1.0-2020.07-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf)
set(USED_OPENCV_LIBS
        libopencv_video.so
        libopencv_calib3d.so
        libopencv_objdetect.so
        libopencv_ml.so
        libopencv_videoio.so
        libopencv_imgproc.so
        libopencv_features2d.so
        libopencv_flann.so
        libopencv_imgcodecs.so
        libopencv_highgui.so
        libopencv_dnn.so
        libopencv_shape.so
        libopencv_stitching.so
        libopencv_superres.so
        libopencv_videostab.so
        libopencv_core.so
        libopencv_photo.so
    )
target_link_libraries(mai_hal ${USED_OPENCV_LIBS})
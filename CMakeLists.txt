cmake_minimum_required(VERSION 3.16)

project(emoji2image)

set(CONAN_CMAKE ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${CONAN_CMAKE})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake" ${CONAN_CMAKE})
endif()

include(${CONAN_CMAKE})

conan_cmake_run(
    REQUIRES opencv/4.3.0@conan/stable
    OPTIONS
    opencv:contrib=True
    opencv:eigen=False
    opencv:glog=False
    opencv:gflags=False
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

add_executable(emoji2image
    main.cpp
)

target_link_libraries(emoji2image
    PRIVATE
    CONAN_PKG::opencv
)

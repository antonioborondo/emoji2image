cmake_minimum_required(VERSION 3.17.2)

set(EMOJI_H ${CMAKE_CURRENT_SOURCE_DIR}/include/emojicpp/emoji.h)

if(NOT EXISTS ${EMOJI_H})
    message(STATUS "Downloading emoji.h from https://github.com/99xt/emojicpp")
    file(DOWNLOAD "https://raw.githubusercontent.com/99xt/emojicpp/master/emoji.h" ${EMOJI_H})
endif()

add_library(emojicpp INTERFACE)

target_include_directories(emojicpp
    INTERFACE
    include
)

cmake_minimum_required(VERSION 3.17.2)

add_library(emojicpp INTERFACE)

target_include_directories(emojicpp
    INTERFACE
    include
)

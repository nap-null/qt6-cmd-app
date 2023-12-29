cmake_minimum_required(VERSION 3.20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(qt6-cmd-app LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup(KEEP_RPATHS)

find_package(
    Qt6
        COMPONENTS
            Core
        REQUIRED
)

add_subdirectory(src)

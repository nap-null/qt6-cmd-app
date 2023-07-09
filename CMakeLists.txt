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
)

add_executable(
    ${PROJECT_NAME}
        main.cpp
        src/Application/Application.cpp
        src/Application/Application.h
)

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE
            src
)

target_link_libraries(
    ${PROJECT_NAME}
        Qt6::Core
)

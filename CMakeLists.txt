cmake_minimum_required(VERSION 3.17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

project(qt6-cmd-app LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

find_package(
    Qt6
        COMPONENTS
            Core
)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE
            src
)

target_link_libraries(
    ${PROJECT_NAME}
        Qt::Core
)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework SystemConfiguration")
    target_link_libraries(${PROJECT_NAME} "-framework GSS")
endif()

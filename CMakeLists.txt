cmake_minimum_required(VERSION 3.17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)

project(qt6-cmd-app LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

find_package(
    Qt6
        COMPONENTS
            Core
)

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} Qt6::Core)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework SystemConfiguration")
    target_link_libraries(${PROJECT_NAME} "-framework GSS")
endif()

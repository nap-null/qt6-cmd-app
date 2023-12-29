qt_add_executable(
    ${PROJECT_NAME}
        main.cpp
        Application/Application.cpp
        Application/Application.h
)

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            Qt6::Core
)

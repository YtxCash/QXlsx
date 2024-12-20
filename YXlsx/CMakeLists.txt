cmake_minimum_required(VERSION 3.16)

project(YXlsx
    VERSION 0.1.1
    DESCRIPTION "Qt Excel Library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wno-shorten-64-to-32")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)

qt_standard_project_setup(REQUIRES 6.5)
add_definitions(-DQT_DISABLE_DEPRECATED_UP_TO=0x060500)

file(GLOB_RECURSE SRC_FILES
    "*.h"
    "*.cpp"
)

add_library(YXlsx
    ${SRC_FILES}
)

add_library(YXlsx::YXlsx ALIAS YXlsx)

target_compile_features(YXlsx INTERFACE cxx_std_17)

target_link_libraries(${PROJECT_NAME}
   Qt${QT_VERSION_MAJOR}::Core
   Qt${QT_VERSION_MAJOR}::GuiPrivate
)

target_include_directories(YXlsx
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/header
)

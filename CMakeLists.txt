cmake_minimum_required(VERSION 3.5) # CMake install : https://cmake.org/download/
project(av_player LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "c:/Qt/Qt5.14.2/5.14.2/msvc2017_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # Qt COMPONENTS
aux_source_directory(./src srcs)

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include_directories(
    ${PROJECT_SOURCE_DIR}/QtAV/include
)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    link_directories(${PROJECT_SOURCE_DIR}/QtAV/lib/debug)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    link_directories(${PROJECT_SOURCE_DIR}/QtAV/lib/release)
endif()

message (
    STATUS "CMAKE_BUILD_TYPE, defaulting to " ${CMAKE_BUILD_TYPE}
 )

option(GENDLL "generate dll" OFF)
option(GENEXE "generate exe" OFF)

if (GENDLL)
    ADD_LIBRARY(av_player SHARED src/av_player.cpp)
    SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
    SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
endif()

if (GENEXE)
    add_executable(${PROJECT_NAME}
        WIN32 # If you need a terminal for debug, please comment this statement 
        ${srcs} 
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt5::Widgets    # Qt5 Shared Library
    QtAVd1
    QtAVWidgetsd1
    # QtAV1
    # QtAVWidgets1
) 
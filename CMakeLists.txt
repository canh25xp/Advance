cmake_minimum_required(VERSION 3.10)
project(DSA)

if(MSVC)
    # warning C4996: 'freopen': This function or variable may be unsafe.
    # Consider using fopen_s instead.
    # To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
    # See online help for details.
    add_definitions(/wd4996)
endif()

# Generate Clangd compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Avoid MSBuild putting Debug and Release in seperate folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

include_directories(${CMAKE_SOURCE_DIR}/common/Queue)
include_directories(${CMAKE_SOURCE_DIR}/common/Deque)
include_directories(${CMAKE_SOURCE_DIR}/common/Stack)
include_directories(${CMAKE_SOURCE_DIR}/common/Point)
include_directories(${CMAKE_SOURCE_DIR}/common/Graph)
include_directories(${CMAKE_SOURCE_DIR}/common/Utils)

file(GLOB CMAKE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Problems ${CMAKE_CURRENT_SOURCE_DIR}/Problems/*)
foreach(CMAKE_FILE ${CMAKE_FILES})
    if(EXISTS ${CMAKE_FILE}/CMakeLists.txt)
        get_filename_component(PROJECT_NAME ${CMAKE_FILE} NAME)
        message(${PROJECT_NAME})
        add_subdirectory(Problems/${PROJECT_NAME})
    endif()
endforeach()

# For testing
# add_subdirectory(shared/Stack)
# add_subdirectory(shared/Point)




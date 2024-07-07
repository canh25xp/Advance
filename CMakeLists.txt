cmake_minimum_required(VERSION 3.10)
project(DSA)

# Generate Clangd compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

# include_directories(${CMAKE_SOURCE_DIR}/shared)

# add_subdirectory(Airplane_Game)
add_subdirectory(Village)
add_subdirectory(Well_Project)

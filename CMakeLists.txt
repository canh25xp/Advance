cmake_minimum_required(VERSION 3.10)
project(mini_project)

# Generate Clangd compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

# include_directories(${CMAKE_SOURCE_DIR}/shared)

# add_subdirectory(Airplane_Game)
add_subdirectory(Village)
add_subdirectory(Well_Project)

cmake_minimum_required(VERSION 3.10)
project(DSA)

if(MSVC)
  # warning C4996: 'fopen': This function or variable may be unsafe.
  # Consider using fopen_s instead.
  # To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
  # See online help for details.
  add_definitions(/wd4996)
endif()

# Generate Clangd compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_11)

# include_directories(${CMAKE_SOURCE_DIR}/shared)

add_subdirectory(Village)
add_subdirectory(Well_Project)


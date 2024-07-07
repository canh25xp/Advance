add_executable(Village main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input_small.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(Village PUBLIC compiler_flags)

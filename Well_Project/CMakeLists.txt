add_executable(WellProject main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(WellProject PUBLIC compiler_flags)

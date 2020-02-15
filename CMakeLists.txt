cmake_minimum_required(VERSION 2.8)

project(root)

if ( CMAKE_COMPILER_IS_GNUCC )
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-switch") 
endif ( CMAKE_COMPILER_IS_GNUCC )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

add_compile_options(-std=c++17)
add_compile_options(-g)
add_compile_options(-Wall)
add_compile_options(-Wpedantic)
add_compile_options(--debug)

add_subdirectory(5B)


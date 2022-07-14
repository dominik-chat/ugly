#
# Copyright 2022 Dominik Chat
#
# SPDX-License-Identifier: BSD-3-Clause
#

cmake_minimum_required(VERSION 3.9)
project(ugly_lib)

option(BUILD_SHARED_LIBS "Build shared lib" ON)

# Check for SDL2
find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
	message(ERROR "SLD2 library found")
else()
	message(STATUS "SLD2 found :)")
endif(NOT SDL2_FOUND)

#Sources
FILE(GLOB UglySources src/*.c)
add_library(ugly ${UglySources})

# Inlcudes
target_include_directories(ugly PRIVATE ${SDL2_INCLUDE_DIRS})

target_include_directories(ugly PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
target_include_directories(ugly PRIVATE src)

target_link_libraries(ugly ${SDL2_LIBRARIES})
target_compile_options(ugly PRIVATE -O2 -Wall -Wextra)

set(libs ugly)
install(FILES include/ugly.h DESTINATION include)
install(TARGETS ${libs} DESTINATION lib)


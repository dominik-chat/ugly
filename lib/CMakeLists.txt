# Copyright 2022 Dominik Chat
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
# OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
# OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
# IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

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


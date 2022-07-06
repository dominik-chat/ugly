# Copyright (C) 2022 Dominik Chat
#
# This file is part of Ugly Samples.
#
# Ugly Samples is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
#
# Ugly Samples is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Ugly Samples. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.9)
project(simple)

find_package(GLUT REQUIRED)
if(NOT GLUT_FOUND)
	message(ERROR "No GLUT library found")
else()
	message(STATUS "GLUT found :)")
endif(NOT GLUT_FOUND)

add_executable(simple main.c)

target_link_libraries(simple ${GLUT_LIBRARIES} -lugly)
target_compile_options(simple PRIVATE -O2 -Wall -Wextra)

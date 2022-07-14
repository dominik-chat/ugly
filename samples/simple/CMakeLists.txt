#
# Copyright 2022 Dominik Chat
#
# SPDX-License-Identifier: BSD-3-Clause
#

cmake_minimum_required(VERSION 3.9)
project(simple)

add_executable(simple main.c)

target_link_libraries(simple -lugly)
target_compile_options(simple PRIVATE -O2 -Wall -Wextra)

#
# Copyright 2022 Dominik Chat
#
# SPDX-License-Identifier: BSD-3-Clause
#

cmake_minimum_required(VERSION 3.9)
project(ugly)

option(BUILD_SAMPLES "Build samples" ON)

add_subdirectory(lib)
if(BUILD_SAMPLES)
    add_subdirectory(samples)
endif(BUILD_SAMPLES)

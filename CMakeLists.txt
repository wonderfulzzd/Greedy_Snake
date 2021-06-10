# ---------------------------------------------------------------------
#
# Copyright (C) 2021 - 2021 by the Greedy snake authors
#
# CMakeLists.txt
#
# This file is part of the Greedy snake project.
#
# The Greedy snake is free software; you can use it, redistribute
# it, and/or modify it under the terms of the GNU Lesser General
# Public License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# The full text of the license can be found in the file LICENSE.md at
# the top level directory of LPBF.
#
# Author: Zhidong Brian Zhang
# Created on: Jun.08 2021
# Updated on: xxx.xx xxxx
#
# ---------------------------------------------------------------------

# Minimum CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# Projects
PROJECT(greedy-snake)

############################################################
# Build specifications
############################################################
# Verbose output
SET(CMAKE_VERBOSE_MAKEFILE off)

# Compiler settings
set(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror -g -O0") # debug flags
SET(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -Werror -O3")  # release flags

# Install path
SET(INSTALL_DIR ${PROJECT_SOURCE_DIR}/install)

# Source files
SET(SOURCE_FILES 
   source/main.cc
   source/Snake.cc
   )
  

############################################################
# Set run time path
############################################################
# From official documents:~/wikis/doc/cmake/RPATH-handling
# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

# the RPATH to be used when installing
SET(CMAKE_INSTALL_RPATH "")

# don't add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)


############################################################
# Create exectuables
############################################################
# Create an Executable
ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES})

# Include files
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME}
	PRIVATE
	${PROJECT_SOURCE_DIR}/include
	)

# Output paths of executables
SET_TARGET_PROPERTIES(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
 
# Build type selection   
ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the debug mode.")

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release mode.")
  

############################################################
# Install
############################################################
# Executable
INSTALL(TARGETS ${PROJECT_NAME}
    DESTINATION ${INSTALL_DIR}/bin
    )

# Header files
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include
    DESTINATION ${INSTALL_DIR}
    )

# Config
INSTALL(FILES 
    ${PROJECT_SOURCE_DIR}/README.md
    ${PROJECT_SOURCE_DIR}/lesser.txt
    DESTINATION ${INSTALL_DIR}
    )

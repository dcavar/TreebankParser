# CMakeLists for TreebankParser
#
# Copyright 2016 by Damir Cavar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.4)
set(EXECUTABLE_NAME "treebankparser")
#set(LIBRARY_NAME "treebankparser")
project(pcfg)

# add all .cpp and .h files to source
file(GLOB ALL_MY_SRC
        "*.h"
        "*.cpp")

set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE) # setting two custom configuration types

#set(CMAKE_CXX_IMPLICIT_LINK_LIBRARIES "")
#set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES "")
#set(CMAKE_VERBOSE_MAKEFILE TRUE)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -lstdc++")
#find_library(LIBSTDCXX NAMES stdc++)
#add_compile_options(-stdlib=libstdc++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64 ")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#set(CMAKE_OSX_ARCHITECTURES "x86_64")

# add a target to generate API documentation with Doxygen
# if you use CMake to generate the Makefile, it will create a 'make doc' target
# manually just call: doxygen Doxyfile
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(DOC_DIR     ${CMAKE_CURRENT_SOURCE_DIR})
    set(DOC_SOURCES ${DOC_DIR}/Doxygen.stamp )
    configure_file(${DOC_DIR}/Doxyfile.in ${DOC_DIR}/Doxyfile @ONLY)
    add_custom_command(
            OUTPUT  ${DOC_SOURCES}
            DEPENDS ${DOC_DIR}/Doxyfile
            WORKING_DIRECTORY ${DOC_DIR}
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOC_DIR}/Doxyfile
            COMMAND ${CMAKE_COMMAND} -E touch ${DOC_DIR}/Doxygen.stamp
            COMMENT "Generating documentation with Doxygen"
            VERBATIM )
    add_custom_target(doc DEPENDS ${DOC_SOURCES} )
endif(DOXYGEN_FOUND)

# add Boost libs
# set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#set(Boost_USE_STATIC_LIBS    OFF)
#set(Boost_USE_MULTITHREADED  ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#set(BOOST_ALL_DYN_LINK       ON)
#SET(BOOST_MIN_VERSION        "1.47.0")
find_package(Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS program_options filesystem system)
# filesystem system regex) # date_time system regex)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error: Boost (version >= ${BOOST_MIN_VERSION}) required.\n")
endif (NOT Boost_FOUND)
if (Boost_FOUND)
    include_directories(".")
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${EXECUTABLE_NAME} ${Boost_LIBRARIES} ${ALL_MY_SRC})
    target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES} )
endif()

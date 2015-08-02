cmake_minimum_required (VERSION 2.6)
project (MongoLite)

enable_testing()

# Include findPackage and findHeader
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/.cmake-modules")
include(CheckIncludeFiles)
include(CheckFunctionExists)

# Find Packages
find_package(BSON)

#set include dirs
include_directories(${BSON_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_LIST_DIR}/src)
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${CMAKE_CURRENT_LIST_DIR}")

#source code
add_subdirectory(src)

# tests
add_subdirectory(tests)


#CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cmake-config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)

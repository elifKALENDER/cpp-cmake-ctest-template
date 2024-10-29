# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.12)
project(CE207-midterm)

set(ROOT src)

# Print useful information
message(STATUS "[${ROOT}] CMake version ${CMAKE_VERSION}")
message(STATUS "[${ROOT}] System ${CMAKE_SYSTEM_NAME}")
message(STATUS "[${ROOT}] Processor ${CMAKE_SYSTEM_PROCESSOR}")

# GoogleTest requires at least C++11
if(NOT "${CMAKE_CXX_STANDARD}")
  set(CMAKE_CXX_STANDARD 11)
  message(STATUS "[${ROOT}] Default C++ Standard Selected: ${CMAKE_CXX_STANDARD}")
endif()

message(STATUS "[${ROOT}] C++ standard version: ${CMAKE_CXX_STANDARD}")

# Set the default installation directory
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/install" CACHE PATH "Default installation directory" FORCE)
endif()

message(STATUS "[${ROOT}] Folder is set to : ${CMAKE_INSTALL_PREFIX}")

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Set build configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# Configuration flags for compilers
if(MSVC)
  add_definitions(-DMSVC_ENV)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-DGCC_ENV)
endif()

# Set the output directories for Debug and Release configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/build/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/build/Release)

# Optionally include submodules
option(ENABLE_CE207_MIDTERM_LIB "Enable CE207-midterm-lib Module" ON)
option(ENABLE_CE207_MIDTERM_APP "Enable CE207-midterm-app Application" ON)
option(ENABLE_TESTS "Enable All Tests" ON)

# Include submodules
if(ENABLE_CE207_MIDTERM_LIB)
  add_subdirectory(${ROOT}/CE207-midterm-lib)
endif()

if(ENABLE_CE207_MIDTERM_APP)
  add_subdirectory(${ROOT}/CE207-midterm-app)
endif()

# Include GoogleTest and CE207-midterm-tests if ENABLE_TESTS is on
if(ENABLE_TESTS)
  # Add GoogleTest library from tests/googletest folder
  add_subdirectory(${ROOT}/tests/googletest)

  # Add CE207-midterm-tests directory
  add_subdirectory(${ROOT}/tests/CE207-midterm-tests)
endif()

# Check cmake version
cmake_minimum_required(VERSION 3.20)

# Enable C++20
set(CMAKE_CXX_STANDARD 20)

# Debug dll 'd' postfix
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

# Move executable files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY         ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_BINARY_DIR}/bin)

# Use custom folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
# Use specific folder for cmake projects
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

# Create new project
project(cpp-sort)

file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
						  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c
						  ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc
						  ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

add_executable(my-bubble sample/BubbleAlgorithm.cpp ${headers} ${sources})
target_include_directories(my-bubble PUBLIC include)

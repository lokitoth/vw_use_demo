cmake_minimum_required(VERSION 3.5)
project(vw_use_demo)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL FORCE)
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: Debug, Release" FORCE)

# Devirtualization is an optimization that changes the vtable if the compiler decides a function
# doesn't need to be virtual. This is incompatible with the mocking framework used in testing as it
# makes the vtable structure unpredictable
option(TURN_OFF_DEVIRTUALIZE "Turn off devirtualize which is required for mocking framework" OFF)

include(ProcessorCount)
ProcessorCount(NumProcessors)
message("Number of processors: ${NumProcessors}")
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/nprocs.txt ${NumProcessors})

add_subdirectory(lib)
add_subdirectory(app)
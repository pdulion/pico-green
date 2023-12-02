cmake_minimum_required(VERSION 3.0.0)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(green-pi VERSION 0.1.0 LANGUAGES C CXX)

# Initialize the SDK
pico_sdk_init()

include(CTest)
enable_testing()

add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

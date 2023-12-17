cmake_minimum_required(VERSION 3.12)

set(NAME green)
set(PICO_BOARD pico_w CACHE STRING "Board type")
include(pico_sdk_import.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# include(lwip_import.cmake)

# SET(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/port/FreeRTOS-Kernel" CACHE STRING "Local Config")
# include_directories("S{FREERTOS_CONFIG_FILE_DIRECTORY}")
# include(FreeRTOS_Kernel_import.cmake)

add_subdirectory(src)

#Set up files for the release packages
install(CODE "execute_process(COMMAND ${CMAKE_CURRENT_LIST_DIR}/bin/deploy ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.elf)")

# Set up files for the release packages
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/src/${NAME}.uf2 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)

add_executable(${NAME} main.cpp)

target_link_libraries(${NAME}
	  pico_stdlib
    # FreeRTOS-Kernel-Heap4
    # FREERTOS_PORT
    # LWIP_PORT
    # pico_lwip
    pico_cyw43_arch_none
    # pico_cyw43_arch_lwip_poll
    # pico_cyw43_arch_lwip_sys_freertos
    # hardware_rtc
)

target_include_directories(${NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

if (NOT DEFINED ENV{WIFI_SSID})
	message(FATAL_ERROR "WIFI_SSID Environment variable not defined")
endif()

if (NOT DEFINED ENV{WIFI_PASSWORD})
	message(FATAL_ERROR "WIFI_PASSWORD Environment variable not defined")
endif()

target_compile_definitions(${NAME} PRIVATE
    WIFI_SSID=\"$ENV{WIFI_SSID}\"
    WIFI_PASSWORD=\"$ENV{WIFI_PASSWORD}\"
    CYW43_HOST_NAME=\"${NAME}\"
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})

# enable usb output, disable uart output
pico_enable_stdio_usb(${NAME} 0)
pico_enable_stdio_uart(${NAME} 1)

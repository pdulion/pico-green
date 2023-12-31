add_library(flash flash.cpp)

target_include_directories(flash PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(flash
	  pico_stdlib
    FreeRTOS-Kernel-Heap4
    # FREERTOS_PORT
    # LWIP_PORT
    # pico_lwip
    pico_cyw43_arch_none
    # pico_cyw43_arch_lwip_poll
    # pico_cyw43_arch_lwip_sys_freertos
    # hardware_rtc
)

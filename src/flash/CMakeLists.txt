add_library(flash STATIC)

target_include_directories(flash PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_sources(flash PRIVATE flash.cpp)

target_link_libraries(flash
    freertos_port
    lwip_port
    FreeRTOS-Kernel-Heap4
	  pico_stdlib
    # pico_cyw43_arch_none
    # pico_cyw43_arch_lwip_poll
    pico_cyw43_arch_lwip_sys_freertos
)

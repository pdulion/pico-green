add_library(wifi STATIC)

target_include_directories(wifi PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_sources(wifi PRIVATE wifi.cpp)

target_link_libraries(wifi
  freertos_port
  lwip_port

  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_lwip_sys_freertos
  pico_lwip
  pico_stdlib
)

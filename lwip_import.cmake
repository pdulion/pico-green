add_library(lwip_port STATIC)

target_include_directories(lwip_port PUBLIC ${CMAKE_CURRENT_LIST_DIR}/port/lwip)

target_sources(lwip_port PUBLIC ${PICO_SDK_PATH}/lib/lwip/src/apps/sntp/sntp.c)

# Add the standard library to the build
target_link_libraries(lwip_port PUBLIC
  freertos_port
  pico_lwip

  FreeRTOS-Kernel
  pico_cyw43_arch_lwip_sys_freertos
  pico_stdlib
)

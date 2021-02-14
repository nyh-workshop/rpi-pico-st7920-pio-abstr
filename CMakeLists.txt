# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "E:/pico-sdk")

# Pull in Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pio_st7920_4bp_abstr C CXX ASM)

# Initialise the Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(pio_st7920_4bp_abstr pio_st7920_4bp_abstr.cpp picture.cpp st7920.cpp MicroCtrlSys.cpp pico_st7920_pio_driver.cpp )

pico_generate_pio_header(pio_st7920_4bp_abstr ${CMAKE_CURRENT_LIST_DIR}/st7920_4bp.pio)

pico_set_program_name(pio_st7920_4bp_abstr "pio_st7920_4bp_abstr")
pico_set_program_version(pio_st7920_4bp_abstr "0.1")

pico_enable_stdio_uart(pio_st7920_4bp_abstr 1)
pico_enable_stdio_usb(pio_st7920_4bp_abstr 0)

# Add the standard library to the build
target_link_libraries(pio_st7920_4bp_abstr pico_stdlib)

# Add any user requested libraries
target_link_libraries(pio_st7920_4bp_abstr
        hardware_pio
        )

pico_add_extra_outputs(pio_st7920_4bp_abstr)


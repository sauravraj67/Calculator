
cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(PicoCalcAdvanced)

pico_sdk_init()

add_executable(PicoCalcAdvanced
    src/main.c
    src/keyboard.c
    src/display.c
    src/encoder.c
    src/calculator.c
    src/ui.c
)

target_include_directories(PicoCalcAdvanced PRIVATE include)

target_link_libraries(PicoCalcAdvanced
    pico_stdlib
    hardware_i2c
)

pico_add_extra_outputs(PicoCalcAdvanced)

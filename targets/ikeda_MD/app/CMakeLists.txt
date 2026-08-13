cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(app STATIC
    src/app.cpp
    src/ir2302_gate_driver.cpp
    src/incremental_encoder.cpp
    ${CMAKE_SOURCE_DIR}/external/gn10_can/drivers/stm32_can/driver_stm32_can.cpp
)

target_include_directories(app PUBLIC
    include
    ${CMAKE_SOURCE_DIR}/external/gn10_can
)

target_link_libraries(app PRIVATE
    stm32cubemx
    gn10_can
    gn10_motor
)
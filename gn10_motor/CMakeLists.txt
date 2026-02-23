cmake_minimum_required(VERSION 3.22)

# motor_controller.cpp が追加されたため INTERFACE → STATIC に変更
add_library(gn10_motor STATIC
    src/motor_controller.cpp
)

# テンプレートヘッダ (pid.hpp, acceleration_limiter.hpp 等) も PUBLIC で公開する
target_include_directories(gn10_motor PUBLIC include)
target_compile_features(gn10_motor PUBLIC cxx_std_17)

# gn10_can の MotorDriverServer を使用するため PUBLIC で依存追加
target_link_libraries(gn10_motor PUBLIC gn10_can)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_EXTENSIONS Off)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

add_executable(Pong Main.cpp)

target_compile_features(Pong PRIVATE cxx_std_20)
if (MSVC)
    target_compile_options(Pong PRIVATE /W4 /GR- /Zc:preprocessor)
else ()
    target_compile_options(Pong PRIVATE -Wall -Wextra -Wpedantic -Wconversion
        -fno-rtti -fno-exceptions)
endif()

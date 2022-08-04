cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(toml-edit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(deps/wxWidgets)
add_executable(toml-edit main.cpp gui.h gui.cpp)
target_link_libraries(toml-edit wx::net wx::core wx::base)

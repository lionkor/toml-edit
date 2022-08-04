cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(toml-edit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(wxWidgets)
add_subdirectory(toml11)
add_executable(toml-edit main.cpp gui.h gui.cpp TomlEditFrame.h TomlEditFrame.cpp)
target_link_libraries(toml-edit wx::net wx::core wx::base wx::propgrid toml11)

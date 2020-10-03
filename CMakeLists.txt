cmake_minimum_required(VERSION 3.17)
project(OthelloCLion)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(OthelloCLion main.cpp gameBoard.cpp gameBoard.h cellData.cpp cellData.h gameLogics.h ui.cpp ui.h)
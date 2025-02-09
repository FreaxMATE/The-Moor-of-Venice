cmake_minimum_required(VERSION 3.10)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(include)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(BUILD_SHARED_LIBS OFF)

add_executable(MyGame src/main.cpp src/Game.cpp src/AI.cpp src/Board.cpp)

target_link_libraries(MyGame sfml-system sfml-window sfml-graphics sfml-audio)
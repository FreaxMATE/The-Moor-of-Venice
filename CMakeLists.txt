cmake_minimum_required(VERSION 3.25.2)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SFML_USE_STATIC_STD_LIBS TRUE)
set(BUILD_SHARED_LIBS FALSE)


# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Source files
set(SRC_FILES
    src/main.cpp
    src/Game.cpp
    src/AI.cpp
    src/Board.cpp
    src/ParticleSystem.cpp
)

# Include directories
include_directories(include)

# Create the executable
add_executable(MyGame ${SRC_FILES})

# Link SFML libraries
target_link_libraries(MyGame sfml-graphics sfml-window sfml-system sfml-audio)
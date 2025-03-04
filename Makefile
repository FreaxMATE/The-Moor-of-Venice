# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# SFML library flags
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS = src/AI.cpp src/Board.cpp src/Game.cpp src/main.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = include/AI.h include/Board.h include/Game.h

# Output executable
TARGET = sfml_app

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(SFML_LIBS)

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)
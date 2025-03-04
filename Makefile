CXX = g++
CXXFLAGS = -std=c++17 -I include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC_FILES = src/main.cpp src/Game.cpp src/AI.cpp src/Board.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TARGET = MyGame

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(TARGET)

.PHONY: all clean
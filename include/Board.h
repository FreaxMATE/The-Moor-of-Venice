#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class Board {
public:
    Board(int width = 6, int height = 6); // Default size set to 6x6
    Board(const Board& other); // Copy constructor
    Board& operator=(const Board& other); // Copy assignment operator
    ~Board(); // Destructor
    void draw(sf::RenderWindow &window);
    void reset();
    int getWidth() const;
    int getHeight() const;
    int getCell(int x, int y) const;
    void setColorInvert(bool invertupdate);
    void setCell(int x, int y, int value);
    void setSize(int width, int height);
    float getCellSize() const;
    bool isValidMove(int x, int y, int player) const;
    void applyMove(int x, int y, int player);
    void highlightValidMoves(sf::RenderWindow &window, int player);

private:
    int width, height;
    bool invert = false; // whether to invert color
    float cellSize;
    std::vector<std::vector<int>> board_array;
    sf::RectangleShape cellShape;
    void updateCellSize();
    bool isOnBoard(int x, int y) const;
    std::vector<int> getFlips(int x, int y, int player) const; // Correct declaration
    std::vector<std::pair<int, int>> directions = { // Add directions for 8 possible moves
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
};

#endif // BOARD_H
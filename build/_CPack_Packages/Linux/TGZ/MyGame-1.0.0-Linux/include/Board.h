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
    void setColorInvert(bool invert);
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
    std::vector<std::pair<int, int>> getFlips(int x, int y, int player) const;
};

#endif // BOARD_H
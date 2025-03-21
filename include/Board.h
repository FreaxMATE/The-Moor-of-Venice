#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class Board {
public:
    Board(int width, int height);
    Board(const Board& other);
    Board& operator=(const Board& other);
    ~Board();

    void draw(sf::RenderWindow &window);
    void reset();
    int getWidth() const;
    int getHeight() const;
    int getCell(int x, int y) const;
    void setCell(int x, int y, int value);
    void setColorInvert(bool invertupdate);
    void setSize(int newWidth, int newHeight);
    void updateCellSize();
    float getCellSize() const;
    bool isOnBoard(int x, int y) const;
    std::vector<std::pair<int, int>> getFlips(int x, int y, int player) const;
    bool isValidMove(int x, int y, int player) const;
    void applyMove(int x, int y, int player);
    void highlightValidMoves(sf::RenderWindow &window, int player);

private:
    int width;
    int height;
    float cellSize;
    std::vector<std::vector<int>> board_array;
    sf::RectangleShape cellShape;
    bool invert = false;

    // Animation-related members
    sf::Clock animationClock;
    bool isAnimating = false;
    std::vector<std::pair<int, int>> animatedCells;
    int animationPlayer;
};

#endif // BOARD_H
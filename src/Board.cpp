#include "Board.h"

// Constructor to initialize the board with given width and height
Board::Board(int width, int height) : width(width), height(height), board_array(width, std::vector<int>(height, 0)) {
    updateCellSize();
    cellShape.setOutlineColor(sf::Color::Black); // Set the outline color of the cell shape
    cellShape.setOutlineThickness(1); // Set the outline thickness of the cell shape
}

// Copy constructor
Board::Board(const Board& other)
: width(other.width), height(other.height), cellSize(other.cellSize),
board_array(other.board_array), cellShape(other.cellShape) {}

// Assignment operator
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        cellSize = other.cellSize;
        board_array = other.board_array;
        cellShape = other.cellShape;
    }
    return *this;
}

// Destructor
Board::~Board() {};

// Draw the board on the given window
void Board::draw(sf::RenderWindow &window) {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            cellShape.setPosition(x * cellSize, y * cellSize); // Set the position of the cell shape
            switch (board_array[x][y]) {
                case 1: cellShape.setFillColor(!invert ? sf::Color::White : sf::Color::Black); break; // White for player 1
                case -1: cellShape.setFillColor(!invert ? sf::Color::Black : sf::Color::White); break; // Black for player -1
                default: cellShape.setFillColor(sf::Color(99, 181, 85)); break; // Green for empty cells
            }
            window.draw(cellShape); // Draw the cell shape on the window
        }
    }
}

// Reset the board to the initial state
void Board::reset() {
    for (auto& row : board_array) {
        std::fill(row.begin(), row.end(), 0); // Fill the board array with zeros
    }

    int midX = width / 2;
    int midY = height / 2;
    board_array[midX - 1][midY - 1] = -1; // Set initial positions for player -1
    board_array[midX][midY] = -1;
    board_array[midX - 1][midY] = 1; // Set initial positions for player 1
    board_array[midX][midY - 1] = 1;
}

// Get the width of the board
int Board::getWidth() const { return width; }

// Get the height of the board
int Board::getHeight() const { return height; }

// Get the value of the cell at (x, y)
int Board::getCell(int x, int y) const { return board_array[x][y]; }

// Set the value of the cell at (x, y)
void Board::setCell(int x, int y, int value) { board_array[x][y] = value; }

// Select whether to invert color
void Board::setColorInvert(bool invertupdate) { invert = invertupdate; }

// Set the size of the board and update the cell size
void Board::setSize(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    board_array.resize(width);
    for (auto &row : board_array)
        row.resize(height, 0);
    updateCellSize(); // Update the cell size based on the new dimensions
}

// Update the cell size based on the board dimensions
void Board::updateCellSize() {
    cellSize = 800.0f / std::max(width, height); // Calculate the cell size
    cellShape.setSize(sf::Vector2f(cellSize, cellSize)); // Set the size of the cell shape
}

// Get the size of a cell
float Board::getCellSize() const { return cellSize; }

// Check if the given coordinates are on the board
bool Board::isOnBoard(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

// Get the list of cells that would be flipped if the player makes a move at (x, y)
std::vector<std::pair<int, int>> Board::getFlips(int x, int y, int player) const {
    std::vector<std::pair<int, int>> flips;
    if (!isOnBoard(x, y) || board_array[x][y] != 0)
        return flips; // Return empty if the cell is not empty

        const std::vector<std::pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

    for (const auto& dir : directions) {
        int nx = x + dir.first, ny = y + dir.second;
        std::vector<std::pair<int, int>> potentialFlips;

        while (isOnBoard(nx, ny) && board_array[nx][ny] == -player) {
            potentialFlips.push_back({nx, ny});
            nx += dir.first;
            ny += dir.second;
        }

        if (isOnBoard(nx, ny) && board_array[nx][ny] == player) {
            flips.insert(flips.end(), potentialFlips.begin(), potentialFlips.end());
        }
    }

    return flips;
}

// Check if the move at (x, y) is valid for the player
bool Board::isValidMove(int x, int y, int player) const {
    return !getFlips(x, y, player).empty();
}

// Apply the move at (x, y) for the player and flip the necessary cells
void Board::applyMove(int x, int y, int player) {
    auto flips = getFlips(x, y, player);
    if (flips.empty()) return;

    board_array[x][y] = player;
    for (const auto& flip : flips) {
        board_array[flip.first][flip.second] = player;
    }
}

// Highlight the valid moves for the player on the given window
void Board::highlightValidMoves(sf::RenderWindow &window, int player) {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (isValidMove(x, y, player)) {
                cellShape.setPosition(x * cellSize, y * cellSize);
                cellShape.setFillColor(sf::Color(160, 40, 40, 128)); // Highlight color
                window.draw(cellShape);
            }
        }
    }
}

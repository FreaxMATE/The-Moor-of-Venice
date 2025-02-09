#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

void printHelp() {
    std::cout << "Usage: game [options]\n"
              << "Options:\n"
              << "  --size <n>      Set the board size (4 <= n <= 20)\n"
              << "  --time <ms>     Set the time limit in milliseconds (100 <= ms <= 10000)\n"
              << "  --color <c>     Set the starting color (white or black)\n"
              << "  --help          Display this help message\n";
}

int main(int argc, char* argv[]) {
    int boardSize = 8; // Default board size
    int timeLimit = 200; // Default time limit in milliseconds
    bool startWithWhite = true; // Default to start with white

    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--help") == 0) {
            printHelp();
            return 0;
        } else if (std::strcmp(argv[i], "--size") == 0 && i + 1 < argc) {
            boardSize = std::atoi(argv[++i]);
            if (boardSize < 4 || boardSize > 20) {
                std::cerr << "Invalid board size. Please enter a size between 4 and 20." << std::endl;
                return 1;
            }
        } else if (std::strcmp(argv[i], "--time") == 0 && i + 1 < argc) {
            timeLimit = std::atoi(argv[++i]);
            if (timeLimit < 100 || timeLimit > 10000) {
                std::cerr << "Invalid time limit. Please enter a time between 100 and 10000 milliseconds." << std::endl;
                return 1;
            }
        } else if (std::strcmp(argv[i], "--color") == 0 && i + 1 < argc) {
            std::string color = argv[++i];
            if (color == "white") {
                startWithWhite = true;
            } else if (color == "black") {
                startWithWhite = false;
            } else {
                std::cerr << "Invalid color. Please enter 'white' or 'black'." << std::endl;
                return 1;
            }
        }
    }

    Game game(boardSize, timeLimit, startWithWhite);
    game.run();

    return 0;
}
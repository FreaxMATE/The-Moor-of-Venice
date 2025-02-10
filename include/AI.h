#ifndef AI_H
#define AI_H

#include "Board.h"
#include <chrono>
#include <utility>

class AI {
public:
    void makeMove(Board &board, int timeLimitMs);

private:
    int minimax(Board &board, int depth, bool isMaximizing, int alpha, int beta, std::chrono::high_resolution_clock::time_point startTime, int timeLimitMs);
    void applyMove(Board &board, int x, int y, int player);
    int evaluateBoard(const Board &board);
    std::vector<std::pair<int, int>> getPossibleMoves(const Board &board, int player);
};

#endif // AI_H
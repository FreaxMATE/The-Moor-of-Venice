#include "AI.h"
#include <limits>
#include <chrono>
#include <iostream>

void AI::makeMove(Board &board, int timeLimitMs) {
    auto startTime = std::chrono::high_resolution_clock::now();
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};

    for (const auto &move : getPossibleMoves(board, -1)) {
        if (board.isValidMove(move.first, move.second, -1)) {
            Board tempBoard = board;
            //std::cout << "Created tempBoard in makeMove" << std::endl;
            applyMove(tempBoard, move.first, move.second, -1);
            int moveValue = minimax(tempBoard, 10, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), startTime, timeLimitMs);
            if (moveValue > bestValue) {
                bestValue = moveValue;
                bestMove = move;
            }

            auto currentTime = std::chrono::high_resolution_clock::now();
            int elapsedTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
            if (elapsedTimeMs >= timeLimitMs) {
                break;
            }
        }
    }

    if (bestMove.first != -1 && bestMove.second != -1) {
        board.applyMove(bestMove.first, bestMove.second, -1);
    }
}

int AI::minimax(Board &board, int depth, bool isMaximizing, int alpha, int beta, std::chrono::high_resolution_clock::time_point startTime, int timeLimitMs) {
    // Check if the time limit has been reached
    auto currentTime = std::chrono::high_resolution_clock::now();
    int elapsedTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
    if (elapsedTimeMs >= timeLimitMs) {
        return evaluateBoard(board);
    }

    // If the maximum depth is reached, evaluate the board
    if (depth == 0) {
        return evaluateBoard(board);
    }

    if (isMaximizing) {
        int maxEval = std::numeric_limits<int>::min();
        // Iterate through all possible moves for the maximizing player
        for (const auto &move : getPossibleMoves(board, -1)) {
            if (board.isValidMove(move.first, move.second, -1)) {
                Board tempBoard = board; // Create a copy of the board
                //std::cout << "Created tempBoard in minimax (maximizing)" << std::endl;
                applyMove(tempBoard, move.first, move.second, -1);
                // Recursively call minimax for the minimizing player
                int eval = minimax(tempBoard, depth - 1, false, alpha, beta, startTime, timeLimitMs);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) {
                    break; // Beta cut-off
                }
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        // Iterate through all possible moves for the minimizing player
        for (const auto &move : getPossibleMoves(board, 1)) {
            if (board.isValidMove(move.first, move.second, 1)) {
                Board tempBoard = board; // Create a copy of the board
                //std::cout << "Created tempBoard in minimax (minimizing)" << std::endl;
                applyMove(tempBoard, move.first, move.second, 1);
                // Recursively call minimax for the maximizing player
                int eval = minimax(tempBoard, depth - 1, true, alpha, beta, startTime, timeLimitMs);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alpha) {
                    break; // Alpha cut-off
                }
            }
        }
        return minEval;
    }
}

int AI::evaluateBoard(const Board &board) {
    // Heuristic values for an 8x8 board
    static const int heuristic_8[8][8] = {
        { 410,  23,  13,   8,   8,  13,  23, 410 },
        {  23, -75, -22, -51, -51, -22, -75,  23 },
        {  13, -22,  41,   3,   3,  41, -22,  13 },
        {   8, -51,   3, -87, -87,   3, -51,   8 },
        {   8, -51,   3, -87, -87,   3, -51,   8 },
        {  13, -22,  41,   3,   3,  41, -22,  13 },
        {  23, -75, -22, -51, -51, -22, -75,  23 },
        { 410,  23,  13,   8,   8,  13,  23, 410 }
    };

    int score = 0;
    int width = board.getWidth();
    int height = board.getHeight();

    // Evaluate the board based on the heuristic values if it's an 8x8 board
    if (width == 8 && height == 8) {
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                score += board.getCell(x, y) * heuristic_8[x][y];
            }
        }
    } else {
        // Otherwise, simply sum up the cell values
        for (int x = 0; x < width; ++x) {
            for (int y = 0; y < height; ++y) {
                score += board.getCell(x, y);
            }
        }
    }

    return score;
}

std::vector<std::pair<int, int>> AI::getPossibleMoves(const Board &board, int player) {
    std::vector<std::pair<int, int>> moves;
    for (int x = 0; x < board.getWidth(); ++x) {
        for (int y = 0; y < board.getHeight(); ++y) {
            if (board.getCell(x, y) == 0) {
                moves.emplace_back(x, y);
            }
        }
    }
    return moves;
}

void AI::applyMove(Board &board, int x, int y, int player) {
    board.applyMove(x, y, player);
}

#include "AI.h"
#include <limits>
#include <chrono>

void AI::makeMove(Board &board, int timeLimitMs) {
    auto startTime = std::chrono::high_resolution_clock::now();
    int bestValue = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};

    for (const auto &move : getPossibleMoves(board, -1)) {
        if (board.isValidMove(move.first, move.second, -1)) {
            Board tempBoard = board;
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
    auto currentTime = std::chrono::high_resolution_clock::now();
    int elapsedTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();
    if (elapsedTimeMs >= timeLimitMs) {
        return evaluateBoard(board);
    }

    if (depth == 0) {
        return evaluateBoard(board);
    }

    if (isMaximizing) {
        int maxEval = std::numeric_limits<int>::min();
        for (const auto &move : getPossibleMoves(board, -1)) {
            if (board.isValidMove(move.first, move.second, -1)) {
                Board tempBoard = board;
                applyMove(tempBoard, move.first, move.second, -1);
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
        for (const auto &move : getPossibleMoves(board, 1)) {
            if (board.isValidMove(move.first, move.second, 1)) {
                Board tempBoard = board;
                applyMove(tempBoard, move.first, move.second, 1);
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
    int score = 0;
    for (int x = 0; x < board.getWidth(); ++x) {
        for (int y = 0; y < board.getHeight(); ++y) {
            score += board.getCell(x, y);
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
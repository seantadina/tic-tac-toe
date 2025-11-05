#include "ai.h"

#include <limits>

using namespace std;

TicTacToeAI::TicTacToeAI(Player aiPlayer, Player opponent)
{
    if (aiPlayer == NONE || opponent == NONE) {
        throw TicTacToeBoard::InvalidPlayer();
    }

    this->aiPlayer = aiPlayer;
    this->opponent = opponent;
}

int TicTacToeAI::getBestMove(const TicTacToeBoard& board) const
{
    return minimax(board, true).move;
}

TicTacToeAI::Node TicTacToeAI::minimax(const TicTacToeBoard& board, bool maximize) const
{
    // TODO: If the game is over, return an appropriate score and 0 as the move.

    // TODO: If the game is not over, then for all possible next moves,
    // call minimax recursively to determine which move provides the best
    // score, then return that score and move.
  Node best;
    if (maximize) {
        best.score = numeric_limits<int>::min(); 
    } else {
        best.score = numeric_limits<int>::max();
    }

    if (board.isGameOver()) {
        if (board.hasPlayerWon(aiPlayer)) {
            return {10, 0};
        } else if (board.hasPlayerWon(opponent)) {
            return {-10, 0};
        } else {
            return {0, 0};
        }
    }

    for (int move = 1; move <= TicTacToeBoard::SPACES; ++move) {
        if (board.isValidMove(move)) {
            TicTacToeBoard newBoard = board;
            newBoard.move(maximize ? aiPlayer : opponent, move);
            Node node = minimax(newBoard, !maximize);

            if (maximize && node.score > best.score) {
                best.score = node.score;
                best.move = move;
            } else if (!maximize && node.score < best.score) {
                best.score = node.score;
                best.move = move;
            }
        }
    }

    return best;
}
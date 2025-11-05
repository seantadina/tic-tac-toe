#include "board.h"

#include <iostream>

using namespace std;

char playerToChar(Player p) {
    switch (p) {
        case NONE: return ' ';
        case X: return 'X';
        case O: return 'O';
    }
}

TicTacToeBoard::TicTacToeBoard()
{
    for (int i = 0; i < SPACES; i++) {
        board[i] = NONE;
    }
}

void TicTacToeBoard::print() const
{
    cout << " -------------" << endl;
    for (int i = 0; i < SPACES; i++) {
        cout << " | " << playerToChar(board[i]);
        if ((i + 1) % COLUMNS == 0) {
            cout << " |" << endl;
            cout << " -------------" << endl;
        }
    }
}

bool TicTacToeBoard::isValidMove(int move) const
{
    return move >= 1 && move <= SPACES && board[move - 1] == NONE;
}

void TicTacToeBoard::move(Player player, int move)
{
    if (!isValidMove(move)) {
        throw InvalidMove();
    }

    if (player == NONE) {
        throw InvalidPlayer();
    }

    board[move - 1] = player;
}

bool TicTacToeBoard::isGameOver() const
{
    return hasPlayerWon(X) || hasPlayerWon(O) || isTie();
}

bool TicTacToeBoard::isTie() const
{
    if (hasPlayerWon(X) || hasPlayerWon(O)) {
        return false;
    }
    
    for (int i = 0; i < SPACES; i++) {
        if (board[i] == NONE) {
            return false;
        }
    }

    return true;
}

bool TicTacToeBoard::hasPlayerWon(Player player) const
{
    if (player == NONE) {
        throw InvalidPlayer();
    }

    // Check rows
    for (int i = 0; i < SPACES; i += ROWS) {
        if (board[i] == player &&
            board[i] == board[i + 1] &&
            board[i] == board[i + 2]) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLUMNS; i++) {
        if (board[i] == player && board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0] == player && board[0] == board[4] && board[0] == board[8]) ||
        (board[2] == player && board[2] == board[4] && board[2] == board[6])) {
        return true;
    }

    return false;
}

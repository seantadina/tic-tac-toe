#include "board.h"
#include "ai.h"

#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    TicTacToeBoard board;
    TicTacToeAI ai(O, X);
 
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "You are playing as X. Make your move by entering a number between 1 and 9." << endl;
 
    while (!board.isGameOver()) {
        board.print();
 
        int move;
        cin >> move;
 
        if (board.isValidMove(move)) {
            board.move(X, move);
 
            if (!board.isGameOver()) {
                int aiMove = ai.getBestMove(board);
                board.move(O, aiMove);
            }
        }
        else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
 
    board.print();
 
    if (board.isTie()) {
        cout << "It's a tie." << endl;
    } else if (board.hasPlayerWon(X)) {
        cout << "Congratulations, you won!" << endl;
    } else {
        cout << "Sorry, you lost." << endl;
    }

	return EXIT_SUCCESS;
}

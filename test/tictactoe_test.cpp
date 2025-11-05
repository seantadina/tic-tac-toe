#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "board.h"
#include "ai.h"

using namespace std;

TEST_CASE("AI wins")
{
    TicTacToeBoard board;
    TicTacToeAI ai(X, O);

    board.move(X, ai.getBestMove(board));
    board.move(O, 5);
    board.move(X, ai.getBestMove(board));
    board.move(O, 3);
    board.move(X, ai.getBestMove(board));
    board.move(O, 9);
    board.move(X, ai.getBestMove(board));

    REQUIRE(board.isGameOver());
    REQUIRE_FALSE(board.isTie());
    REQUIRE(board.hasPlayerWon(X));
}

TEST_CASE("Tie")
{
    TicTacToeBoard board;
    TicTacToeAI ai(X, O);

    board.move(O, 1);
    board.move(X, ai.getBestMove(board));
    board.move(O, 3);
    board.move(X, ai.getBestMove(board));
    board.move(O, 8);
    board.move(X, ai.getBestMove(board));
    board.move(O, 6);
    board.move(X, ai.getBestMove(board));
    board.move(O, 7);

    REQUIRE(board.isGameOver());
    REQUIRE(board.isTie());
    REQUIRE_FALSE(board.hasPlayerWon(X));
    REQUIRE_FALSE(board.hasPlayerWon(O));
}

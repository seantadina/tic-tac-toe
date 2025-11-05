# Tic-Tac-Toe

[Tic-tac-toe](https://en.wikipedia.org/wiki/Tic-tac-toe) is a simple, deterministic game for two players. In this project, I implement an artificially intelligent agent that plays tic-tac-toe optimally and cannot be defeated.

For background on minimax and game-tree search, I relied on:

* Wikipedia's entry on [minimax](https://en.wikipedia.org/wiki/Minimax)  
* Justin Skycak's articles on tic-tac-toe [game trees](https://www.justinmath.com/canonical-and-reduced-game-trees-for-tic-tac-toe/) and [minimax strategy](https://www.justinmath.com/minimax-strategy/)  
* Elements of AI's article on [search and games](https://course.elementsofai.com/2/3)

## How It Works

I model tic-tac-toe as a finite game tree:

- Each node represents a **board configuration**.
- The root node is the **initial empty board**.
- Edges correspond to **legal moves** by the current player.
- Nodes at even depth correspond to moves by the maximizing player (the AI), and nodes at odd depth correspond to moves by the minimizing player (the human opponent).
- Terminal nodes are win, loss, or draw positions.

Terminal positions are evaluated with a numerical score:

- `+1` for an AI win,  
- `0` for a draw,  
- `-1` for an AI loss.

The `minimax` algorithm propagates these scores back up the tree:

- At a **max** node (AI’s turn), the node’s score is the maximum of its children’s scores.
- At a **min** node (opponent’s turn), the node’s score is the minimum of its children’s scores.

By exploring all possible continuations from the current state and applying minimax, the AI selects the move that maximizes its guaranteed outcome against a perfect opponent. On a 3×3 board, this produces an optimal strategy: the AI either wins or forces a draw.

## Project Structure

The project is organized into several main components:

- `TicTacToeBoard`  
  Encapsulates the state of the game board and provides operations to:
  - place moves,
  - check legality of moves,
  - detect terminal states (win, loss, draw),
  - determine whose turn it is.

- `TicTacToeAI`  
  Implements the game-playing agent. This class:
  - defines the `TicTacToeAI::minimax` method, which recursively evaluates the game tree,
  - chooses the move associated with the best minimax score for the AI.

- `main`  
  Contains an **interactive game loop** where a human plays against the AI. The loop:
  - initializes a `TicTacToeBoard`,
  - alternates between human and AI moves,
  - updates and prints the board after each turn,
  - reports the final outcome (win, loss, or draw).

- `test/`  
  Holds unit tests that check the correctness of board operations and ensure that the minimax-based AI behaves as expected (for example, it does not lose from standard opening positions).

## Building and Running

This is a C++ project configured with CMake.

### Build

From the project root:

```bash
mkdir build
cd build
cmake ..
make

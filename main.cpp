#include <iostream>
#include "game.h"

int main() {
    Game game(1, true);
    game.printBoard();
    int x, y;
    std::string dest;
    std::cin >> x >> y >> dest;
    game.move(x, y, dest);
    game.printBoard();
    return 0;
}

// TODO:
// - move pieces chess notation
// - test out padding around gameboard
// - valid movies

// TODO:- long term
// - play against yourself
// - chess engine as opponenet (stockfish + own)
// - lichess
// - other users

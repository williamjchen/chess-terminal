#include <iostream>
#include "game.h"

int main() {
    Game game(3);
    game.printBoard();
    return 0;
}

// TODO:
// - game config (have/don't have labels, custom pieces padding)
// - test move and input move pieces
// - test out padding around gameboard
// - valid movies

// TODO:- long term
// - chess engine as opponenet (stockfish + own)
// - lichess
// - other users

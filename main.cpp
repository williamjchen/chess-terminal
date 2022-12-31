#include <iostream>
#include "game.h"

int main() {
    Game game;
    int x, y;
    std::string dest;
    std::cin >> x >> y >> dest;
    return 0;
}

// TODO:
// - restructure as bitboard
// - generate board from FEN
// - valid movies

// TODO:- long term
// - play against yourself
// - chess engine as opponenet (stockfish + own)
// - lichess
// - other users

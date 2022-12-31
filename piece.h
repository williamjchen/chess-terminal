#include <iostream>
#include <map>

class Piece {
private:
    int piece;

    int none = 0;
    int king = 1;
    int pawn = 2;
    int knight = 3;
    int bishop = 4;
    int rook = 5;
    int queen = 6;

    int white = 8;
    int black = 16;

    int typeMask = 0b00111;
    int colorMask = 0b11000;

    std::map<char, int> pieces = {
                                {'k', king},
                                {'p', pawn},
                                {'n', knight},
                                {'b', bishop},
                                {'r', rook},
                                {'q', queen}
                                };

    std::map<int, std::string> unicodePieces = {
                                {rook | black, "♜"}, 
                                {knight | black, "♞"}, 
                                {bishop | black, "♝"}, 
                                {queen | black, "♛"}, 
                                {king | black, "♚"}, 
                                {pawn | black, "♟"}, 
                                {rook | white, "♖"}, 
                                {knight | white, "♘"}, 
                                {bishop | white, "♗"}, 
                                {queen | white, "♕"}, 
                                {king | white, "♔"},
                                {pawn | white, "♙"},
                                };
public:
    Piece(char piece){
        int colour = isupper(piece) ? white : black;
        int type = pieces[tolower(piece)];

        piece = colour | type;
    };

    int pieceType() {
        return piece & typeMask;
    }

    int colour() {
        return piece & colorMask;
    }

    std::string getUnicodePiece() {
        return unicodePieces[piece];
    }
};
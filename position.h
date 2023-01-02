#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include "piece.h"

typedef uint64_t U64;

class Position {
private:
    bool haveLabels = true;
    int padding;    

    U64 WPawns, WKnight, WBishop, WRook, WQueen, WKing;
    U64 BPawns, BKnight, BBishop, BRook, BQueen, BKing;

    U64 typeBB[6];
    U64 colorBB[2];

    enum PieceType {
        PAWN,
        KNIGHT,
        BISHOP,
        ROOK,
        QUEEN,
        KING
    };

    enum color {
        WHITE,
        BLACK
    };

    std::string pieceToChar = " PNBRQK pnbrqk";

    // unicode characters to build border
    std::string upT = "┬";
    std::string cross = "┼";
    std::string botT = "┴";
    std::string leftT = "├";
    std::string rightT = "┤";
    std::string leftBotEnd = "└";
    std::string rightBotEnd = "┘";
    std::string rightUpEnd = "┐";
    std::string leftUpEnd = "┌";
    std::string horiz = "─";
    std::string vert = "│";

public:
    // loads FEN string position into bitboards
    void LoadPosition(std::string fen) {
        std::vector<std::string> sections;
        std::stringstream ss(fen);
        std::string section;

        // split fen string into sections by space
        while (getline(ss, section, ' ')) {
            sections.push_back(section);
        }

        // 1. load piece positions
        int row = 0, col = 0;
        for (char c: sections[0]) {
            if (c == '/'){
                col = 0;
                row++;
                continue;
            }

            if (isdigit(c)) {
                col += c - '0';
            } else {
                col++;
            }
        }

        // 2. load active color
        // 3. load castling availability
        // 4. load en passant target square
    }
};
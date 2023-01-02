#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

typedef uint64_t U64;

class Position {
private:
    U64 typeBB[6];
    U64 colourBB[2];

    // white pawn - 1
    // white knight - 2
    // white bishop - 3
    // white rook - 4
    // white queen - 5
    // white king - 6
    // black pawn - 9
    // black knight  - 10
    // black bishop - 11
    // black rook - 12
    // black queen - 13
    // black king - 14
    std::string pieceToChar = " PNBRQK  pnbrqk";
public:
    Position() {loadPosition("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");};
    Position(std::string fen) {loadPosition(fen);};

    // loads FEN string position into bitboards
    void loadPosition(std::string fen) {
        std::vector<std::string> sections;
        std::stringstream ss(fen);
        std::string section;

        // split fen string into sections by space
        while (getline(ss, section, ' ')) {
            sections.push_back(section);
        }

        // 1. load piece positions
        int row = 0, col = 1;
        for (char c: sections[0]) {
            if (c == '/'){
                col = 1;
                row++;
                continue;
            }

            if (isdigit(c)) {
                col += c - '0';
            } else {
                int piece = pieceToChar.find(c);
                int colour = piece & 0b1000; // or piece >> 3; // colour is int 0-1
                int type = piece & 0b0111; // type is int 1-6

                typeBB[colour] |= (1 << (64 - (row * 8 + col)));
                colourBB[type - 1] |= (1 << (64 - (row * 8 + col)));

                col++;
            }
        }

        // 2. load active color
        // 3. load castling availability
        // 4. load en passant target square
    }

    char pieceAtPosition(int rank, char file) {
        int f = file - 'A';
        int index = (8 - rank) * 8 + f;

        int piece = 0, colour = 0;
        for (int i = 0; i < 6; i++) {
            if (typeBB[i] & (1 << (64 - index + 1))) {
                piece = i + 1;
            }
        }
        colour = colourBB[0] & (1 << (64 - index + 1)) ? 0 : 1;

        if (piece == 0) return ' ';
        return pieceToChar[piece | (colour << 3)];
    }
};
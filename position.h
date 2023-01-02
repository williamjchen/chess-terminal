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
    int active; // 0 = white, 1 = black
    int castleRights = 0; // 0 = no rights, 1 = white king, 2 = white queen, 4 = black king, 8 = black queen, 15 = all
    int halfMoveClock;
    int fullMoveNumber;
    U64 enPassant = 0;
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
                int piece = pieceToChar.find(c);
                int colour = piece >> 3;// colour is int 0-1
                int type = piece & 0b0111; // type is int 1-6

                U64 index = fileRankToIndex(8 - row, col + 1);

                colourBB[colour] |= index;
                typeBB[type - 1] |= index;

                col++;
            }
        }
        // 2. load active color
        active = sections[1] == "w" ? 0 : 1;

        // 3. load castling availability
        for (char c: sections[2]) {
            switch (c) {
                case 'K':
                    castleRights |= 1 << 0;
                    break;
                case 'Q':
                    castleRights |= 1 << 1;
                    break;
                case 'k':
                    castleRights |= 1 << 2;
                    break;
                case 'q':
                    castleRights |= 1 << 3;
                    break;
            }
        }
        
        std::cout << castleRights << std::endl;

        // 4. load en passant target square
        std::string enPassant = sections[3];
        if (enPassant != "-") {
            int rank = 8 - (enPassant[1] - '0');
            int file = enPassant[0] - 'a' + 1;
            enPassant = fileRankToIndex(rank, file); 
        }

        // 5. load halfmove clock
        halfMoveClock = std::stoi(sections[4]);
        // 6. load fullmove number
        fullMoveNumber = std::stoi(sections[5]);
    }

    char pieceAtPosition(int rank, int file) {
        U64 index = fileRankToIndex(rank, file);

        int piece = 0, colour = 0;
        for (int i = 0; i < 6; i++) {
            if (typeBB[i] & index) {
                piece = i + 1;
            }
        }
        colour = colourBB[0] & index ? 0 : 1;

        if (piece == 0) return ' ';
        return pieceToChar[piece | (colour << 3)];
    }

    U64 fileRankToIndex(int rank, int file) {
        return 1ULL << (64 - ((8 - rank) * 8 + (file - 1)) - 1);
    }

    U64 fileRankToIndex(int rank, char file) {
        int fileInt = file - 'A' + 1;
        return 1ULL << (64 - ((8 - rank) * 8 + (fileInt - 1)) - 1);
    }
};
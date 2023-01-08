#include "tables.h"

// maybe have as non-member function

U64 Tables::PAWN_ATTACK[2][64];
U64 Tables::KNIGHT_ATTACK[64];
U64 Tables::KING_ATTACK[64];

void Tables::init() {
    generatePawnAttackTable();
    generateKnightAttackTable();
    generateKingAttackTable();
}

void Tables::generatePawnAttackTable () {
    // White
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        U64 NWAttack = (pawnPos << 9) & CLEAR_FILE[7];
        U64 NEAttack = (pawnPos << 7) & CLEAR_FILE[0];
        PAWN_ATTACK[0][i] = NWAttack | NEAttack;
    }

    // Black
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        U64 SWAttack = (pawnPos >> 9) & CLEAR_FILE[0];
        U64 SEAttack = (pawnPos >> 7) & CLEAR_FILE[7];
        PAWN_ATTACK[1][i] = SWAttack | SEAttack;
    }
};

void Tables::generateKnightAttackTable () {
    for (int i = 0; i < 64; i++) {
        U64 knightPos = 1ULL << i;
        U64 attack = ((knightPos << 17) & CLEAR_FILE[7] ) | // North 2, West 1
                    ((knightPos >> 15) & CLEAR_FILE[7] ) | // South 2, West 1
                    ((knightPos >> 17) & CLEAR_FILE[0] ) | // South 2, East 1
                    ((knightPos << 15) & CLEAR_FILE[0] ) | // North 2, East 1
                    ((knightPos >> 6) & CLEAR_FILE[6] & CLEAR_FILE[7]) | // South 1, West 2
                    ((knightPos << 10) & CLEAR_FILE[6] & CLEAR_FILE[7]) | // North 1, West 2
                    ((knightPos >> 10) & CLEAR_FILE[0] & CLEAR_FILE[1]) | // South 1, East 2
                    ((knightPos << 6) & CLEAR_FILE[0] & CLEAR_FILE[1]); // North 1, East 2
        KNIGHT_ATTACK[i] = attack;
    }
}

void Tables::generateKingAttackTable () {
    for (int i = 0; i < 64; i++) {
        U64 kingPos = 1ULL << i;
        U64 attack = (kingPos << 8)| // North 1
                    (kingPos >> 8)| // South 1
                    ((kingPos << 1) & CLEAR_FILE[7]) | // East 1
                    ((kingPos >> 1) & CLEAR_FILE[0]) | // West 1
                    ((kingPos << 9) & CLEAR_FILE[7]) | // North West 1
                    ((kingPos >> 9) & CLEAR_FILE[0]) | // South East 1
                    ((kingPos << 7) & CLEAR_FILE[0]) | // North East 1
                    ((kingPos >> 7) & CLEAR_FILE[7]); // South West 1
        KING_ATTACK[i] = attack;
    }
}
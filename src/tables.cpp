#include "tables.h"

// maybe have as non-member function

void Tables::init() {
    generatePawnAttackTable();
    generateKnightAttackTable();
    generateKingAttackTable();
}

void Tables::generatePawnAttackTable () {
    // White
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        int NWAttack = (pawnPos << 9) & Tables::CLEAR_FILE[7];
        int NEAttack = (pawnPos << 7) & Tables::CLEAR_FILE[0];
        Tables::PAWN_ATTACK[0][i] = NWAttack | NEAttack;
    }

    // Black
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        int SWAttack = (pawnPos >> 9) & Tables::CLEAR_FILE[0];
        int SEAttack = (pawnPos >> 7) & Tables::CLEAR_FILE[7];
        Tables::PAWN_ATTACK[1][i] = SWAttack | SEAttack;
    }
};

void Tables::generateKnightAttackTable () {
    for (int i = 0; i < 64; i++) {
        U64 knightPos = 1ULL << i;
        U64 attack = ((knightPos << 17) & Tables::CLEAR_FILE[7] ) |
                    ((knightPos >> 15) & Tables::CLEAR_FILE[7] ) |
                    ((knightPos >> 17) & Tables::CLEAR_FILE[0] ) |
                    ((knightPos << 15) & Tables::CLEAR_FILE[0] ) |
                    ((knightPos >> 6) & Tables::CLEAR_FILE[6] & Tables::CLEAR_FILE[7]) |
                    ((knightPos << 10) & Tables::CLEAR_FILE[6] & Tables::CLEAR_FILE[7]) |
                    ((knightPos >> 10) & Tables::CLEAR_FILE[0] & Tables::CLEAR_FILE[1]) |
                    ((knightPos << 6) & Tables::CLEAR_FILE[0] & Tables::CLEAR_FILE[1]);
        Tables::KNIGHT_ATTACK[i] = attack;
    }
}

void Tables::generateKingAttackTable () {
    for (int i = 0; i < 64; i++) {
        U64 kingPos = 1ULL << i;
        U64 attack = (kingPos << 8)|
                    (kingPos >> 8)|
                    ((kingPos << 1) & Tables::CLEAR_FILE[7]) |
                    ((kingPos >> 1) & Tables::CLEAR_FILE[0]) |
                    ((kingPos << 9) & Tables::CLEAR_FILE[7]) |
                    ((kingPos >> 9) & Tables::CLEAR_FILE[0]) |
                    ((kingPos << 7) & Tables::CLEAR_FILE[0]) |
                    ((kingPos >> 7) & Tables::CLEAR_FILE[7]);
        Tables::KING_ATTACK[i] = attack;
    }
}
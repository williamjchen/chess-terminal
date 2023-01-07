#include "tables.h"

// maybe have as non-member function

void Tables::init() {
    generatePawnAttackTable();
}

void Tables::generatePawnAttackTable () {
    // White
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        int NWAttack = (Tables::CLEAR_FILE[0] & pawnPos) << 9;
        int NEAttack = (Tables::CLEAR_FILE[7] & pawnPos) << 7;
        Tables::PAWN_ATTACK[0][i] = NWAttack | NEAttack;
    }

    // Black
    for(int i = 0; i < 64; i++) {
        U64 pawnPos = 1ULL << i;
        int SWAttack = (Tables::CLEAR_FILE[0] & pawnPos) >> 9;
        int SEAttack = (Tables::CLEAR_FILE[7] & pawnPos) >> 7;
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
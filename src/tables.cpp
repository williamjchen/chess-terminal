#include "tables.h"

void Tables::init() {
    generatePawnAttackTable();
}

void generatePawnAttackTable () {
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
        Tables::PAWN_ATTACK[0][i] = SWAttack | SEAttack;
    }
};
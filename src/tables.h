#include <iostream>
typedef uint64_t U64;
namespace Tables
{
    void init();
    void generatePawnAttackTable();
    void generateKnightAttackTable();
    void generateKingAttackTable();

	const U64 ALL = 0xffffffffffffffff;
    
    const U64 CLEAR_FILE[]={0x7F7F7F7F7F7F7F7F,
                            0xBFBFBFBFBFBFBFBF,
                            0xDFDFDFDFDFDFDFDF,
                            0xEFEFEFEFEFEFEFEF,
                            0xF7F7F7F7F7F7F7F7,
                            0xFBFBFBFBFBFBFBFB,
                            0xFDFDFDFDFDFDFDFD,
                            0xFEFEFEFEFEFEFEFE
                            };

    extern U64 PAWN_ATTACK[2][64];

    extern U64 KNIGHT_ATTACK[64];

    extern U64 KING_ATTACK[64];
}
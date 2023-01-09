#include <iostream>
typedef uint64_t U64;
namespace Tables
{
    void init();
    void generatePawnAttackTable();
    void generateKnightAttackTable();
    void generateKingAttackTable();

	const U64 ALL = 0xffffffffffffffff;

    const U64 MASK_RANK[]={0xFF,
                        0xFF00,
                        0xFF0000,
                        0xFF000000,
                        0xFF00000000,
                        0xFF0000000000,
                        0xFF000000000000,
                        0xFF00000000000000
                        };

    const U64 MASK_FILE[]={0x8080808080808080,
                        0x4040404040404040,
                        0x2020202020202020,
                        0x1010101010101010,
                        0x808080808080808,
                        0x404040404040404,
                        0x202020202020202,
                        0x0101010101010101
                        };
    
    const U64 CLEAR_RANK[]={0xFFFFFFFFFFFFFF00,
                            0xFFFFFFFFFFFF00FF,
                            0xFFFFFFFFFF00FFFF,
                            0xFFFFFFFF00FFFFFF,
                            0xFFFFFF00FFFFFFFF,
                            0xFFFF00FFFFFFFFFF,
                            0xFF00FFFFFFFFFFFF,
                            0x00FFFFFFFFFFFFFF
                            };

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
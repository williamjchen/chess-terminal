#include <iostream>
#include <map>
#include "tables.h"

typedef uint64_t U64;

namespace magic {
    U64 Rook(U64 occ, int sq) {
    }

    U64 Bishop(U64 occ, int sq) {
    }

    U64 Queen(U64 occ, int sq) {
        return Rook(occ, sq) | Bishop(occ, sq);
    }
}   
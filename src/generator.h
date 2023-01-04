#include "position.h"
#include "tables.h"
#include <vector>

#define get_lsb(b) __builtin_ctzll(b)
#define pop_lsb(b) b &= b - 1

class Generator {
private:
    Position pos;
public:
    Generator(Position pos):pos(pos) {};

    std::vector<Position> generateLegalMoves() {
        std::vector<Position> moves;

        if (pos.inCheck()) {
            moves = generateEvasions();
        } else {
            moves = generatePseudoLegalMoves();
        }

        return moves;
    }

    std::vector<Position> generateEvasions() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> generatePseudoLegalMoves() {
        std::vector<Position> moves;

        moves = concatenate(moves, PawnPseudoLegalMoves());
        moves = concatenate(moves, KingPseudoLegalMoves());
        moves = concatenate(moves, QueenPseudoLegalMoves());
        moves = concatenate(moves, RookPseudoLegalMoves());
        moves = concatenate(moves, BishopPseudoLegalMoves());
        moves = concatenate(moves, KnightPseudoLegalMoves());

        return moves;
    }

    std::vector<Position> PawnPseudoLegalMoves() {
        std::vector<Position> moves;

        U64 whitePawns = pos.getWhitePawns();

        while (whitePawns) {
            int sq = get_lsb(whitePawns);
            pop_lsb(whitePawns);

            U64 pawnPos = 1ULL << sq;

            U64 oneStep = (pawnPos << 8) & pos.getAllPieces();
            U64 twoStep = ((oneStep & Tables::MASK_RANK[2]) << 8) & pos.getAllPieces();
            U64 attack = Tables::PAWN_ATTACK[0][sq] & pos.getBlackPieces();

            // clear the pawn from original position (white, and pawn)
            // position |= oneStep, twoStep, attack
            
        }
        return moves;
    }

    std::vector<Position> KingPseudoLegalMoves() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> QueenPseudoLegalMoves() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> RookPseudoLegalMoves() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> BishopPseudoLegalMoves() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> KnightPseudoLegalMoves() {
        std::vector<Position> moves;

        return moves;
    }

    std::vector<Position> concatenate(const std::vector<Position> &v1, const std::vector<Position> &v2) {
        std::vector<Position> res;
        res.reserve(v1.size() + v2.size());
        res.insert(res.end(), v1.begin(), v1.end());
        res.insert(res.end(), v2.begin(), v2.end());
        return res;
    }

};
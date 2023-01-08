#include <iostream>
#include "tables.h"

int main () {
    Tables::init();
    std::cout << Tables::PAWN_ATTACK[0][37] << std::endl;
}
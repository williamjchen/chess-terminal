#include <iostream>
#include "tables.h"

int main () {
    Tables::init();
    std::cout << Tables::KNIGHT_ATTACK[27] << std::endl;
}
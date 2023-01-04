#include <map>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include "board.h"

struct Square {
  int file;
  int rank;
};
class Game {
private:
    Board board;

    

public:
    Game() : board() {board.printBoard();};

    Game(int padding) : board(padding) {board.printBoard();};

    Game(bool haveLabels) : board(haveLabels) {board.printBoard();};

    Game(int padding, bool haveLabels) : board(padding, haveLabels) {board.printBoard();};

    void printBoard() {
        board.printBoard();
    }

    // moves chece pieces using chess notation
    void move(int fromX, int fromY, std::string destination) {
        std::string piece = "P";
        int row, col;
        if (destination.length() == 3) {
            piece = destination.substr(0,0);
            col = destination[1] - 'a';
            row = 8 - (destination[2] - '0');
        } else {
            col = destination[0] - 'a';
            row = 8 - (destination[1] - '0');
        }
    }
};
#include <iostream>
#include <map>

class Game {
private:
    std::map<std::string, std::string> pieces = {
                                {"R", "♜"}, 
                                {"N", "♞"}, 
                                {"B", "♝"}, 
                                {"Q", "♛"}, 
                                {"K", "♚"}, 
                                {"P", "♟"}, 
                                {"r", "♖"}, 
                                {"n", "♘"}, 
                                {"b", "♗"}, 
                                {"q", "♕"}, 
                                {"k", "♔"},
                                {"p", "♙"},
                                {" ", " "}
                                };

    std::string board[8][8] = {
        {"R", "N", "B", "Q", "K", "B", "N", "R"},
        {"P", "P", "P", "P", "P", "P", "P", "P"},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {"p", "p", "p", "p", "p", "p", "p", "p"},
        {"r", "n", "b", "q", "k", "b", "n", "r"}};
public:
    void printBoard() {
        std::cout << "\033[2J\033[1;1H"; // Clear the screen
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::cout << pieces[board[i][j]] << " ";
            }
            std::cout << std::endl;
        }
    }

    void move(int fromX, int fromY, int toX, int toY) {
        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = ' ';
    }
};
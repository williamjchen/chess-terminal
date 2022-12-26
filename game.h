#include <iostream>
#include <map>
#include <sstream>

class Game {
private:
    // maps the piece to the unicode character
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

    // current game board
    std::string board[8][8] = {
        {"R", "N", "B", "Q", "K", "B", "N", "R"},
        {"P", "P", "P", "P", "P", "P", "P", "P"},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " ", " ", " ", " "},
        {"p", "p", "p", "p", "p", "p", "p", "p"},
        {"r", "n", "b", "q", "k", "b", "n", "r"}};

    // unicode characters to build border
    std::string upT = "┬";
    std::string cross = "┼";
    std::string botT = "┴";
    std::string leftT = "├";
    std::string rightT = "┤";
    std::string leftBotEnd = "└";
    std::string rightBotEnd = "┘";
    std::string rightUpEnd = "┐";
    std::string leftUpEnd = "┌";
    std::string horiz = "─";
    std::string vert = "│";

public:
    // builds a border row string
    std::string buildBorderRow(int row) {
        std::string leftEdge, middle, rightEdge;

        switch(row) {
            case 0:
                leftEdge = leftUpEnd;
                middle = upT;
                rightEdge = rightUpEnd;
                break;
            case 9:
                leftEdge = leftBotEnd;
                middle = botT;
                rightEdge = rightBotEnd;
                break;
            default:
                leftEdge = leftT;
                middle = cross;
                rightEdge = rightT;
                break;
        }

        std::stringstream ss;
        ss << "  " << leftEdge;
        for (int i = 0; i < 7; i++) {
            ss << horiz << horiz << horiz << middle;
        }
        ss << horiz << horiz << horiz << rightEdge;
        return ss.str();
    }

    // builds a chess row string
    std::string buildChessRow(int row) {
        std::string rowString = "";
        rowString += std::to_string(8 - row);
        rowString += " ";
        rowString += vert;
        for (int i = 0; i < 8; i++) {
            rowString += " ";
            rowString += pieces[board[row][i]];
            rowString += " ";
            rowString += vert;
        }
        return rowString;
    }

    void printBoard() {
        std::cout << "\033[2J\033[1;1H"; // Clear the screen
        for (int i = 0; i < 8; i++) {
            std::cout << buildBorderRow(i) << std::endl;
            std::cout << buildChessRow(i) << std::endl;
        }
        std::cout << buildBorderRow(9) << std::endl;
        std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
    }

    void move(int fromX, int fromY, int toX, int toY) {
        board[toX][toY] = board[fromX][fromY];
        board[fromX][fromY] = ' ';
    }
};
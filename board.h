#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "piece.h"

typedef uint64_t U64;

class Board {
private:
    bool haveLabels = true;
    int padding;    

    U64 WPawns, WKnight, WBishop, WRook, WQueen, WKing;
    U64 BPawns, BKnight, BBishop, BRook, BQueen, BKing;

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
    Board() : padding(1) {};

    Board(int padding) : padding(padding) {};

    Board(bool haveLabels) : haveLabels(haveLabels), padding(1) {};

    Board(int padding, bool haveLabels) : haveLabels(haveLabels), padding(padding) {};


    void LoadPosition(std::string fen) {
        std::vector<std::string> sections;
        std::stringstream ss(fen);
        std::string section;

        while (getline(ss, section, ' ')) {
            sections.push_back(section);
        }

        int row = 0, col = 0;
        for (char c: sections[0]) {
            if (c == '/'){
                col = 0;
                row++;
                continue;
            }

            if (isdigit(c)) {
                col += c - '0';
            } else {
                board[row*8 + col] = Piece(c);
                col++;
            }
        }
    }

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
        if (haveLabels) ss << "  ";
        ss << leftEdge;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < padding*2 + 1; j++) {
                ss << horiz;
            }
            ss << middle;
        }
        for (int j = 0; j < padding*2 + 1; j++) {
                ss << horiz;
        }
        ss << rightEdge;
        return ss.str();
    }

    // builds a chess row string
    std::string buildChessRow(int row) {
        int i = row * 8;

        std::string rowString = "";
        if (haveLabels) {
            rowString += std::to_string(8 - row);
            rowString += " ";
        }
        rowString += vert;
        for (int j = i; j < 8; j++) {
            rowString += std::string(padding, ' ');

            // get piece from bitboards

            rowString += std::string(padding, ' ');
            rowString += vert;
        }
        return rowString;
    }

    std::string buildPaddingRow(int row) {
        if (padding == 1) return "";

        std::string rowString = "";
        if(haveLabels) rowString += "  ";
        rowString += vert;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < padding*2+1; j++) {
                rowString += " ";
            }
            rowString += vert;
        }

        std::string out;
        for (int i = 0; i < padding*0.4; i++) {
            out = out + rowString + "\n";
        }
        return out;
    }

    void printBoard() {
        std::cout << "\033[2J\033[1;1H"; // Clear the screen
        for (int i = 0; i < 8; i++) {
            std::cout << buildBorderRow(i) << std::endl;
            std::cout << buildPaddingRow(i);
            std::cout << buildChessRow(i) << std::endl;
            std::cout << buildPaddingRow(i);
        }
        std::cout << buildBorderRow(9) << std::endl;

        if (!haveLabels) return;
        std::string columnLabel = "  ";
        std::string columnLetters[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
        for(int i = 0; i < 8; i++) {
            columnLabel += std::string(padding+1, ' ');
            columnLabel += columnLetters[i];
            columnLabel += std::string(padding, ' ');
        }
        columnLabel += std::string(padding*2+1, ' ');
        std::cout << columnLabel << std::endl << std::endl;
    }

    void move(int fromRow, int fromCol, int toRow, int toCol) {
    }
};
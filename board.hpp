#pragma once
#include <iostream>

class Board {
    char _cells[3][3];
public:
    Board();
    Board(const Board& other);

    void PlaceSymbol(int row, int col, char symbol);
    bool IsCellEmpty(int row, int col) const;
    char GetCell(int row, int col) const;
    bool IsFull() const;

    Board operator = (const Board& other);
    bool operator == (const Board& other) const;
};

std::istream& operator >> (std::istream& in, Board& board);
std::ostream& operator << (std::ostream& out, const Board& board);
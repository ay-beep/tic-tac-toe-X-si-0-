#include "board.hpp"
#include <algorithm>

Board::Board() : _cells(3, std::vector<char>(3, ' ')) {}

Board::Board(const Board& other) : _cells(other._cells) {}

void Board::PlaceSymbol(int row, int col, char symbol) {
    _cells[row][col] = symbol;
}

bool Board::IsCellEmpty(int row, int col) const {
    return _cells[row][col] == ' ';
}

char Board::GetCell(int row, int col) const {
    return _cells[row][col];
}

bool Board::IsFull() const {
    for (const auto& row : _cells) {
        // Utilizarea algoritmului STL std::find pentru căutare
        if (std::find(row.begin(), row.end(), ' ') != row.end()) {
            return false;
        }
    }
    return true;
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        _cells = other._cells; // Copiere STL sigură
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    return _cells == other._cells;
}

std::istream& operator>>(std::istream& in, Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c;
            in >> c;
            board.PlaceSymbol(i, j, c);
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << board.GetCell(i, j) << " ";
        }
        out << "\n";
    }
    return out;
}
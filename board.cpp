#include "board.hpp"

Board::Board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _cells[i][j] = ' ';
        }
    }
}

Board::Board(const Board &other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _cells[i][j] = other._cells[i][j];
        }
    }
}

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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (_cells[i][j] == ' ')
                return false;
        }
    }
    return true;
}

Board Board::operator=(const Board &other) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _cells[i][j] = other._cells[i][j];
        }
    }
    return *this;
}

bool Board::operator==(const Board &other) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (_cells[i][j] != other._cells[i][j])
                return false;
        }
    }
    return true;
}

std::istream &operator>>(std::istream &in, Board &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            in >> board.GetCell(i, j); // sau citire simplă de 9 caractere
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Board &board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << board.GetCell(i, j) << " ";
        }
        out << "\n";
    }
    return out;
}
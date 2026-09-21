#include "board.hpp"

Board::Board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _cells[i][j] = ' ';
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
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (_cells[i][j] == ' ')
                return false;
    return true;
}
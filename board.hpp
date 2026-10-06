#pragma once

class Board {
   char _cells[3][3];
public:
   Board();
   void PlaceSymbol(int row, int col, char symbol);
   bool IsCellEmpty(int row, int col) const;
   char GetCell(int row, int col) const;
   bool IsFull() const;
};
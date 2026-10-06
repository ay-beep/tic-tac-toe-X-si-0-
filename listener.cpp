#include "listener.hpp"
#include <iostream>

Point Listener::GetMove() {
    Point p;
    std::cout << "Introduceti rand si coloana (0-2 0-2): ";
    std::cin >> p.row >> p.col;
    return p;
}
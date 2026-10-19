#include "listener.hpp"
#include <iostream>

Point Listener::GetMove() {
    Point p;
    std::cout << "Introduceti rand si coloana (0-2 0-2): ";
<<<<<<< HEAD
    std::cin >> p.x >> p.y; 
=======
    std::cin >> p.row >> p.col;
>>>>>>> origin/main
    return p;
}
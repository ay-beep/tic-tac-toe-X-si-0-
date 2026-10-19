#include "renderer.hpp"
#include <iostream>

void Renderer::Render(const Board& board) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board.GetCell(i, j);
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
}
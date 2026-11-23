#include "game_engine.hpp"
#include <iostream>
#include <limits>

namespace {
bool HasWon(const Board& board, char symbol) {
    for (int i = 0; i < 3; ++i) {
        if (board.GetCell(i, 0) == symbol &&
            board.GetCell(i, 1) == symbol &&
            board.GetCell(i, 2) == symbol) {
            return true;
        }
        if (board.GetCell(0, i) == symbol &&
            board.GetCell(1, i) == symbol &&
            board.GetCell(2, i) == symbol) {
            return true;
        }
    }

    if (board.GetCell(0, 0) == symbol &&
        board.GetCell(1, 1) == symbol &&
        board.GetCell(2, 2) == symbol) {
        return true;
    }

    if (board.GetCell(0, 2) == symbol &&
        board.GetCell(1, 1) == symbol &&
        board.GetCell(2, 0) == symbol) {
        return true;
    }

    return false;
}

void PrintBoard(const Board& board) {
    std::cout << "\n";
    for (int r = 0; r < 3; ++r) {
        std::cout << " ";
        for (int c = 0; c < 3; ++c) {
            char cell = board.GetCell(r, c);
            std::cout << (cell == ' ' ? '.' : cell);
            if (c < 2) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
        if (r < 2) {
            std::cout << "---+---+---\n";
        }
    }
    std::cout << "\n";
}
} // namespace

GameEngine::GameEngine() : _state(GameState::IN_PROGRESS) {}

void GameEngine::Init() {
    _players.resize(2);
    _players[0].symbol = 'X';
    _players[1].symbol = 'O';
    _state = GameState::IN_PROGRESS;
}

void GameEngine::Run() {
    std::cout << "Jocul a pornit! Introdu randul si coloana (0, 1 sau 2).\n";

    int currentPlayer = 0;
    char winnerSymbol = ' ';

    while (_state == GameState::IN_PROGRESS) {
        PrintBoard(_board);

        char symbol = _players[currentPlayer].symbol;
        int row = -1;
        int col = -1;

        while (true) {
            std::cout << "Jucatorul " << symbol << " (rand coloana): ";
            if (!(std::cin >> row >> col)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Intrare invalida. Foloseste doua cifre (0-2).\n";
                continue;
            }

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                std::cout << "Coordonate in afara tablei. Alege valori intre 0 si 2.\n";
                continue;
            }

            if (!_board.IsCellEmpty(row, col)) {
                std::cout << "Casuta este deja ocupata. Alege alta.\n";
                continue;
            }

            break;
        }

        _board.PlaceSymbol(row, col, symbol);

        if (HasWon(_board, symbol)) {
            _state = GameState::WIN;
            winnerSymbol = symbol;
        } else if (_board.IsFull()) {
            _state = GameState::DRAW;
        } else {
            currentPlayer = 1 - currentPlayer;
        }
    }

    PrintBoard(_board);

    if (_state == GameState::WIN) {
        std::cout << "Victorie pentru jucatorul " << winnerSymbol << "!\n";
    } else if (_state == GameState::DRAW) {
        std::cout << "Remiza!\n";
    }
}

GameState GameEngine::CheckState() const {
    return _state;
}
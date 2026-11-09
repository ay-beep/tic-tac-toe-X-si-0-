#pragma once
#include "board.hpp"
#include "player.hpp"
#include <vector>
#include <memory>

enum class GameState {
    IN_PROGRESS, WIN, DRAW
};

class GameEngine {
    Board _board;
    std::vector<Player> _players;
    GameState _state;
public:
    GameEngine();
    void Init();
    void Run();
    GameState CheckState() const;
};
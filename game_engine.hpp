#pragma once

#include "board.hpp"
#include "player.hpp"

enum class GameState {
   IN_PROGRESS, WIN, DRAW
};

class GameEngine {
   Board _board;
   Player _players[2];
   GameState _state;
public:
   GameEngine();
   void Init();
   void Run();
   GameState CheckState() const;
};
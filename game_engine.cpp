#include "game_engine.hpp"

GameEngine::GameEngine() {
    _state = GameState::IN_PROGRESS;
}

void GameEngine::Init() {
    _players[0].symbol = 'X';
    _players[1].symbol = 'O';
}

void GameEngine::Run() {
    // logica principala a jocului va fi adaugata ulterior
}

GameState GameEngine::CheckState() const {
    return _state;
}
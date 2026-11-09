#include "game_engine.hpp"
#include <iostream>

GameEngine::GameEngine() : _state(GameState::IN_PROGRESS) {}

void GameEngine::Init() {
    _players.resize(2);
    _players[0].symbol = 'X';
    _players[1].symbol = 'O';
    _state = GameState::IN_PROGRESS;
}

void GameEngine::Run() {
    // Logica principală a jocului va fi adăugată sau adaptată aici
    std::cout << "Jocul a pornit!\n";
}

GameState GameEngine::CheckState() const {
    return _state;
}
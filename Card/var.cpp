#include "var.hpp"

Game& Game::getInstance() {
    static Game g;
    return g;
}
Game::Game() {}
Game::Game(const Game&) {}
Game::~Game() {}

#pragma once
#include "general.hpp"
#include "primitive.hpp"

class Game {
public:
    static Game& getInstance();
    int a;
    int b;
    Vector2D *v;
    Card *c;
private:
    Game();
    Game(const Game&);
    ~Game();
};

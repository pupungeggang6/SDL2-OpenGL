#pragma once
#include "general.hpp"

class Vector2D {
public:
	float x, y;
    Vector2D();
	Vector2D(float px, float py);
    void printVec();
};

class Card {
public:
    int attack, hp;
    std::vector<int> crystal; 
    Card();
    Card(int pattack, int php, std::vector<int> pcrystal);
};

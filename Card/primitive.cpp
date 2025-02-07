#include "primitive.hpp"

Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(float px, float py) {
	x = px;
	y = py;
}

void Vector2D::printVec() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

Card::Card() {
    attack = 0;
    hp = 0;
    crystal = {};
}

Card::Card(int pattack, int php, std::vector<int> pcrystal) {
    attack = pattack;
    hp = php;
    crystal = pcrystal;
}

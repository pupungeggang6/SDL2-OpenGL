#include "primitive.hpp"

Vector3D::Vector3D(float cx, float cy, float cz) {
    this->x = cx;
    this->y = cy;
    this->z = cz;
}

Vector3D Vector3D::add(Vector3D vec) {
    return Vector3D(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

void Vector3D::printVector() {
    std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}

#include "var.hpp"
#include "primitive.hpp"
#include <iostream>

int main() {
    v2.printVector();
    Vector3D v3 = v2.add(Vector3D(2.0, 2.0, 3.0));
    v3.printVector();
    v3.add(v2).printVector();
    return 0;
}

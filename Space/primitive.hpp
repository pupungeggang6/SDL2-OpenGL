#pragma once
#include <iostream>

class Vector3D {
public:
	float x, y, z;
	Vector3D(float cx, float cy, float cz);
    Vector3D add(Vector3D vec);

    void printVector();
};

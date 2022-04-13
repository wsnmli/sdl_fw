#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>
using namespace std;

class Vector3 { public:
    float x, y, z;

    // constructors 
    Vector(float i, float j, float k) {
        x = i; y = j; z = k;
    }
    Vector() {
        x = 0; y = 0; z = 0;
    }
};

#endif
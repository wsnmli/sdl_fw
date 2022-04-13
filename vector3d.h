#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>
#include <cmath>
using namespace std;

class Vector3 { public:
    float x, y, z;

    // constructors 
    Vector3(float i, float j, float k) {
        x = i; y = j; z = k;
    }
    Vector3() {
        x = 0; y = 0; z = 0;
    }
    Vector3 operator* (float c) {
        Vector3 tmp;
        tmp.x = c * x;
        tmp.y = c * y;
        tmp.z = c * z;
        return tmp; 
    }
    Vector3 operator+ (Vector3 a) {
    Vector3 tmp;
    tmp.x = x + a.x;
    tmp.y = y + a.y;
    tmp.z = z + a.z;
    return tmp;
    }

    Vector3 operator- (Vector3 a) {
        Vector3 tmp;
        tmp.x = x - a.x;
        tmp.y = y - a.y;
        tmp.z = z - a.z;
        return tmp;
    }
    void operator-= (Vector3 z) {
        *this = *this - z;
    }

void operator+= (Vector3 z) {
    *this = *this + z;
}
};

int operator==(Vector3 a, Vector3 b) {
    return (a.x == b.x && a.y == b.y && a.z == b.z);
}

Vector3 operator*(float a, Vector3 b) {
    return b*a;
}



#endif
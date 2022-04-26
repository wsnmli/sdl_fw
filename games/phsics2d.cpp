#include "../vector2d.h"
using namespace std;

class Object {
public:
    Vector s, v, a; // displacement, velocity, acceleration
    float r, rs;    // rotaion rate, rotation acceleration
    
    Object(Vector x) {
        s = x;
        r = 0.; rs = 0.;
    }
    Object(float x, float y) {
        s = Vector(x, y);
        r = 0., rs = 0.;
    }

    void update(float t) {
        s += t*v;
        v += t*v;
        a = a;

        r+=rs;
    }
};

class Ball :public Object {
public:
    using Object::Object;
    void draw();
    
};

class Square :public Object {
public:
    using Object::Object;
    void draw();

};

int main() {
    cout << "H";
    Ball ball(400, 500);
    ball.update(0.1);


}
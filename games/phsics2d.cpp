#include "../vector2d.h"
using namespace std;

class Object {
public:
    Vector s, v, a; // displacement, velocity, acceleration
    float r, rs;    // rotaion rate, rotation acceleration
    float m;    // mass

    Object(Vector x) {
        s = x;
        r = 0.; rs = 0.;
        m = 1;
    }
    Object(float x, float y) {
        Object(Vector(x, y));
    };

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
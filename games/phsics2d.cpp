#include "../vector2d.h"
using namespace std;

#define WIDTH (1000)
#define HEIGHT (1000)


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

    void set_mass(float t) {m = t;}
    
    
    void applyTransForce(Vector p) {
        p /= m;
        a += p;
    }

    void applyRotateForce(float F);

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
    float radius;
    
    void draw();
    
};

class Square :public Object {
public:
    using Object::Object;

    float width, height;
    float theta;        //  angle rotated counter clockwise in radians
    
    void draw();

};

int main() {
    cout << "H";
    Ball ball(400, 500);
    ball.update(0.1);

    Square square(WIDTH/2, HEIGHT/2);
    square.set_mass(16);



}
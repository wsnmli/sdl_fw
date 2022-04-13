//  g++ cube.cpp -lSDL2 -lSDL2_ttf  && ./a.out
#include "../../sdl_fw.h"
#include "../../vector3d.h"

#include <vector>
using namespace std;

class Vertex :public Vector3 { public:
    Vertex(float i, float j, float k) {
        x = i; y = j; z = k;
    }
    void draw() {}
};

class Cube { private:
    vector<Vertex> vertices;
public:
    Cube() {
        for (int i=0; i<16; i++) {
            vertices.push_back(Vertex(0,0,0));
        }
    }
};

class Scene {
    Cube cube;
    Vector3 origin();
};

int main() {
    Scene scene;
}
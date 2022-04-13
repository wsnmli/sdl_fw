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

class Cube { public:
    vector<Vertex> vertices;
    Cube() {
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    if (i!=j && j!=k && i!=k) {
                        vertices.push_back(Vertex(i, j, k));
                    }
                }
            }
        }
    }
};

class Scene {
    Framework* fw;

    Cube cube;
    Vector3 origin();
public:
    Scene(Framework& a) {
        fw = &a;
        fw->set_background_colour(0,0,255);
    }
    
    int getinput() {
        // return done = 1 if player wants to quit
        int done = 0;
        while(SDL_PollEvent(&fw->event)) {
        switch(fw->event.type) {
            case SDL_KEYDOWN:
            {
                switch(fw->event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
                    break;
                }
            } return done;
        }
    }
        return done;
    }
    void draw() {
        fw->blank();
        // draw each vertex in cube
        for (int i = 0; i < cube.vertices.size(); i++) {}

        fw->render();
    }
};

int main() { 
    Framework fw("3D Cube", WIDTH, HEIGHT);
    Scene scene(fw);
    int done = 0;
    while(!done) {
        done = scene.getinput();
        scene.draw();
    }
}
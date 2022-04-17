//  g++ node.cpp -lSDL2 -lSDL2_ttf  && ./a.out
#include "../../sdl_fw.h"
#include "../../vector2d.h"

class Node :public Vector{ 
    Framework* fw;
    public:
    int highlighted;    // highlights when mouse is hovering over
    Node(Framework& a, int i, int j) {
        x = i; y = j;
        fw = &a;
    }
    void draw() {
        if(highlighted) { //draw red circle
            fw->draw_circle(Vector(x,y),255,255,0,0);
        }
    }
};

int main() {
    Framework fw("Node_Drawer", WIDTH, HEIGHT);
    while(!(fw.event.type == SDL_QUIT)) {
        SDL_PollEvent(&fw.event);
        fw.blank();

        fw.render();
    }
}
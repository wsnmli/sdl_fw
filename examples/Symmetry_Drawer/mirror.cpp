//  g++ mirror.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"
using namespace std;

#define WIDTH (700)
#define HEIGHT (800)

class Canvas {
    Framework* fw;
public:   
    Canvas(Framework& fw, int i, int j) {
        int a[i/2][j];
    }

    void getInput() {
        SDL_Event event;
        int mltx = 0, mlty = 0;

        SDL_PumpEvents();

        if (SDL_GetMouseState(&mltx, &mlty) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if (mltx * 2 < WIDTH) { // mouse on left half
                a[mltx][mlty];
            }
        }
    }
    void draw() {}
};

int main() {
    // init sdl
    Framework fw("Mirror Draw", WIDTH, HEIGHT);
    SDL_Event event;

    // add canvas
    Canvas canvas(fw, WIDTH, HEIGHT);

    //game loop
    while(!(event.type == SDL_QUIT)) {
        fw.blank();
        canvas.getInput();
        canvas.draw();
        fw.render();
    }
}
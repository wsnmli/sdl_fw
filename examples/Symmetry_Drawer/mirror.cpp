//  g++ mirror.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"
#include <vector>
using namespace std;

#define WIDTH (700)
#define HEIGHT (800)

class Canvas {
    Framework* fw;
public: 
    vector<vector<int>> M;
    //int m = number of rows, n = number of columns;

  
    Canvas(Framework& fw, int i, int j) {
        M.resize(i, vector<int>(j));
    }

    void getInput() {
        SDL_Event event;
        int mltx = 0, mlty = 0;

        SDL_PumpEvents();

        if (SDL_GetMouseState(&mltx, &mlty) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            if (mltx * 2 < WIDTH) { // mouse on left half
                M[mltx][mlty];
            }
        }
    }
    void draw() {}
};

int main() {
    // init sdl
    Framework fw("Mirror Draw", WIDTH, HEIGHT);

    // add canvas
    Canvas canvas(fw, WIDTH, HEIGHT);

    //game loop
    while(!(fw.event.type == SDL_QUIT)) {
        fw.blank();
        canvas.getInput();
        canvas.draw();
        fw.render();
    }
}
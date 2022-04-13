//  g++ mirror.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"
#include <vector>
using namespace std;

class Canvas {
    Framework* fw;
public: 
    vector<vector<int>> M;
    //int m = number of rows, n = number of columns;

  
    Canvas(Framework& fw, int i, int j) {
        M.resize(i, vector<int>(j));
    }

    int getInput() {
        // returns 1 if players wants to exit
        cout << "Get input" << endl;
        SDL_Event event;
        int mltx = 0, mlty = 0;

        SDL_PumpEvents();

        if (SDL_GetMouseState(&mltx, &mlty) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
                M[mltx][mlty] = 1;
        }
        // check if player wants to exit
        while(SDL_PollEvent(&event)) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                return 1;
            }
        }
        return 0;
    }
    void draw() {}
};

int main() {
    // init sdl
    Framework fw("Mirror Draw", WIDTH, HEIGHT);

    // add canvas
    Canvas canvas(fw, WIDTH, HEIGHT);

    //game loop
    int done = 0;
    while(!done) {
        fw.blank();
        done = canvas.getInput();
        canvas.draw();
        fw.render();
    }
}
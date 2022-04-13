//  g++ mirror.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"
#include <vector>
using namespace std;

#define WIDTH (100)
#define HEIGHT (100)

class Canvas {
    Framework* fw;
public: 
    int** M;
    int numCol, numRow;
  
    Canvas(Framework& fw, int i, int j) {
        numCol = i; numRow = j;
        
        M = new int*[numRow];
	    for (int row = 0; row < numRow; row++)
		    M[row] = new int[numCol];
    }

    int getInput() {
        // returns 1 if players wants to exit
        SDL_Event event;
        int mltx = 0, mlty = 0;

        SDL_PumpEvents();

        if (SDL_GetMouseState(&mltx, &mlty) && SDL_BUTTON(SDL_BUTTON_LEFT)) {
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
    void draw() {
        for (int i = 0; i < numCol; i++) {
            for (int j = 0; j < numRow; j++) {
                if (M[i][j] == 1) SDL_RenderDrawPoint(fw->renderer, i, j);
            }
        }
    }
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
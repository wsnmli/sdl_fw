//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
//  g++ -g3 main.cpp -lSDL2 -lSDL2_ttf  && gdb ./a.out 
#include "../../sdl_fw.h"

void cantor(Framework& fw, int iteration, int x, int y, int width) {
    int height = 50;
    
    if (iteration == 0) {
        fw.draw_rectangle(x, y, width, height);
    }
}

int main() {
    Framework fw("Cantor Fractal", WIDTH, HEIGHT);

    int start_height = 50/2;

    while(fw.event.type != SDL_QUIT) {
        SDL_PollEvent(&fw.event);
        fw.blank();
        cantor(fw, 0, WIDTH/2, start_height, WIDTH - 10);
        fw.render();
    }
}
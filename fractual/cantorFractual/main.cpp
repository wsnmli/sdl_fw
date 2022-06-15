//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
//  g++ -g3 main.cpp -lSDL2 -lSDL2_ttf  && gdb ./a.out 
#include "../../sdl_fw.h"

void cantor(Framework& fw, int iteration) {
    fw.draw_circle(Vector(WIDTH/2, HEIGHT/2), 50);
}

int main() {
    Framework fw("Cantor Fractal", WIDTH, HEIGHT);

    while(fw.event.type != SDL_QUIT) {
        SDL_PollEvent(&fw.event);
        fw.blank();
        cantor(fw, 0);
        fw.render();
    }
}
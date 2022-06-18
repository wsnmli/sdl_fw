//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out

#include "../../sdl_fw.h"

void fractual(Framework fw, Vector centre, int iteration, int size) {
    
}

int main() {
    cout << "H" << endl;

    Framework fw("circle_fractual", WIDTH, HEIGHT);

    fw.set_background_colour(255,255,255);
    fw.blank();
    fw.render();
        

   while(fw.event.type != SDL_QUIT) {
        SDL_PollEvent(&fw.event);
        //cout << "j";
        fw.blank();
        fw.circle(Vector(WIDTH/2, HEIGHT/2), 100);
        fw.render();
    }
}
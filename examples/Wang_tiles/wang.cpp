//g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"

#define WIDTH (700)
#define HEIGHT (800)
#define NUMBER (16)   // number of wang tiles

using namespace std;

class wangTile {};


int main() {
    Vector centre(WIDTH/2, HEIGHT/2);
    
    Framework fw("Wang Tiles", WIDTH, HEIGHT);
    SDL_Event event;
    fw.set_offset(0, 0);
    fw.set_background_colour(0, 0, 255);

    // wang tiles

    //game loop
    while(!(event.type == SDL_QUIT)) {      SDL_Delay(20);
        SDL_PollEvent(&event);
        fw.blank();
        fw.draw_line(Vector(0,0), Vector(WIDTH,HEIGHT));
        // reneder Wang tiles
        fw.draw_rotated_rectangle(centre.x, centre.y, 10, 10, 45);

        fw.render();
    }
}

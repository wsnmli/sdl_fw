//  g++ sieve_of_eratosthenes.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../sdl_fw.h"
#include "isprime.h"

#define WIDTH (700)
#define HEIGHT (800)

#define NUMBERS (60)    //  how many

class Square {
    Framework* a;
public:
    int x, y;   //postion
    int width = 20;
    int height = width;

    int value;  // value on square
    int primep; // weather the value is prime or not

    Square(Framework& fw) {
        a = &fw;
        x = 40; y = 110;
    }

    void show() {
        a->draw_black_rectangle(x,y,width,height);
        a->draw_rectangle(x, y, width-2, height-2);
    }
};

int main() {
    Framework fw("Sieve of Eratosthenes", WIDTH, HEIGHT);
    SDL_Event event;
    fw.set_offset(0, 0);
    fw.set_background_colour(0, 0, 255);

    // add squares
    Square* squares = (Square*) malloc(sizeof(Square) * NUMBERS);
    for(int i=0; i<NUMBERS; i++) {
        squares[i] = Square(fw);
        squares[i].value = i+2;

        squares[i].x = (squares[i].width / 2) + i*squares[i].width;
        squares[i].y = (squares[i].width / 2);
    }

    // game loop
    while(!(event.type == SDL_QUIT)) {
        //SDL_Delay(20);
        SDL_PollEvent(&event);
        fw.blank();

        // render squares 
        for (int i = 0; i < NUMBERS; i++) {
            squares[i].show();
        }

        fw.render();
    }
}
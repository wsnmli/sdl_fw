//  g++ sieve_of_eratosthenes.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../sdl_fw.h"
#include "isprime.h"

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
        // convert value to string
        char str[3];
        sprintf(str, "%d", value);
        a->draw_text(str, x, y);
    }
};

int main() {
    Framework fw("Sieve of Eratosthenes", WIDTH, HEIGHT);
    
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
    while(!(fw.event.type == SDL_QUIT)) {
        //SDL_Delay(20);
        SDL_PollEvent(&fw.event);
        fw.blank();

        // render squares 
        for (int i = 0; i < NUMBERS; i++) {
            squares[i].show();
        }

        fw.render();
    }
}
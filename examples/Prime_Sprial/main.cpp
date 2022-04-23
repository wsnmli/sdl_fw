//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
//  g++ -g3 main.cpp -lSDL2 -lSDL2_ttf  && gdb ./a.out 
#include "../../sdl_fw.h"
#include "../isprime.h"

#define NUMBERS (60)    //  how many


using namespace std;

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
    Framework fw("Prime Spiral", WIDTH, HEIGHT);
    
    Square* squares = (Square*) malloc(sizeof(Square) * NUMBERS);

    int integer = -1;
    while(!(fw.event.type == SDL_QUIT)) {      //SDL_Delay(20);
        SDL_PollEvent(&fw.event);
        
        integer++;
        if (integer < NUMBERS) {
            squares[integer] = Square(fw);
            squares[integer].value = integer + 1;
            squares[integer].width = 20;
            squares[integer].height = 20;
            squares[integer].primep = isprime(integer + 1);
            squares[integer].x = WIDTH/2;
            squares[integer].y = HEIGHT/2;
        }
        
        fw.blank();
        //draw squares
        for (int i=0; i<integer; i++) {
            squares[i].show();
        }

        fw.render();
    }
}
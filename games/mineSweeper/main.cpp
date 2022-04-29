//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out 
#include "../../sdl_fw.h"

class Square {
    Framework* a;
public:
    int x, y;   //postion
    int width = 20;
    int height = width;

    int value;  // value on square
    int minep; // is mine?

    Square(Framework& fw) {
        a = &fw;
        x = 40; y = 110;
    }

    void show() {
        a->draw_black_rectangle(x,y,width,height);
        
    }
};

int main() {
    
}
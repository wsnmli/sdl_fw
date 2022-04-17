//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out
#include "../../sdl_fw.h"

class Entity { public:
    Vector p;       //postion
    Vector a;       // accelaration
    Entity(float x, float y) {
        p.x = x; p.y = y;
    }
};

class Bubble :public Entity { public:
    Bubble(float x, float y) {
        p.x = x; p.y = y;
    }
};

class Player{ public:
    Vector p;       //postion
    Vector a;       // accelaration
};

int main() {
    
}
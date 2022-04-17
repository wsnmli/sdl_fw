//  g++ main.cpp -lSDL2 -lSDL2_ttf  && ./a.out
#include "../../sdl_fw.h"

class Entity { public:
    Vector p;       //postion
    Vector a;       // accelaration
    Entity(float x, float y) {
        p.x = x; p.y = y;
        a = Vector(0, 0);
    }
};

class Bubble :public Entity { public:
    using Entity::Entity;
};

class Player :public Entity{ public:
    using Entity::Entity;
};

int main() {
    
}
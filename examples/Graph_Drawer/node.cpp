//  g++ node.cpp -lSDL2 -lSDL2_ttf  && ./a.out
#include "../../sdl_fw.h"
#include "../../vector2d.h"

class Node :public Vector{ 
    public:
    int highlighted;    // highlights when mouse is hovering over
    Node(int i, int j) {
        x = i; y = z;
    }
};

int main() {

}
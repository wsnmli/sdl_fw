//  g++ squares.cpp -g -lSDL2 -lSDL2_ttf  && ./a.out

#include "../../sdl_fw.h"
#undef WIDTH
#undef HEIGHT
#define WIDTH 1000
#define HEIGHT WIDTH

const float q = 0.05; const float p = 1 - q;

const float r_max = (WIDTH/2 < HEIGHT/2 ? WIDTH/2 : HEIGHT/2);
const float r = p * r_max;

Framework fw("squares", WIDTH, HEIGHT);


int main() {
    float xa, xb, ya, yb, xc, yc, xd, yd;
    float xa1, xb1, ya1, yb1, xc1, yc1, xd1, yd1;

    xa = xd = (WIDTH/2) - r;
    xb = xc = (WIDTH/2) + r;
    ya = yb = (HEIGHT/2) - r;
    yc = yd = (HEIGHT/2) + r;
    
    fw.blank();

    for (int i=0; i<200; i++) {
        SDL_PollEvent(&fw.event);
        fw.draw_line(xa, ya, xb, yb);
        fw.draw_line(xb,yb,xc,yc);
        fw.draw_line(xc,yc, xd, yd);
        fw.draw_line(xd,yd, xa,ya);
        xa1 = p*xa + q*xb; ya1 = p*ya + q*yb;
        xb1 = p*xb + q*xc; yb1 = p*yb + q*yc;
        xc1 = p*xc + q*xd; yc1 = p*yc + q*yd;
        xd1 = p*xd + q*xa; yd1 = p*yd + q*ya;
        xa = xa1; xb = xb1; xc = xc1; xd = xd1;
        ya = ya1; yb = yb1; yc = yc1; yd = yd1;
        fw.render();
        SDL_Delay(32);
    } SDL_Delay(10000000);


}
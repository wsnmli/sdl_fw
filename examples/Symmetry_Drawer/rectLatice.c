// cc rectLatice.c `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm && ./a.out

#include<stdio.h>
#include<stdlib.h>
#include "SDL.h"
#include<math.h>

#define WINDOW_WIDTH (2000)
#define WINDOW_HEIGHT (1000)

#define RECTX (200)     //  number of pixels wide for rectangle lattice
#define RECTY (100)     //

#define XRATIO (WINDOW_WIDTH/RECTX)
#define YRATIO (WINDOW_HEIGHT/RECTY)

int processEvents(SDL_Window *window, int rect[RECTX][RECTY]) {
    SDL_Event event;
    int done = 0;
    int mltx = 0, mlty = 0;


    SDL_PumpEvents();

    if (SDL_GetMouseState(&mltx, &mlty) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        rect[mltx%RECTX][mlty%RECTY] = 1;       //  modulo the width and height of the lattice
    }
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_c:
                        for (int i = 0; i < RECTX; i++) {
                            for (int j = 0; j < RECTY; j++ ) {
                                rect[i][j] = 0;
                            }
                        }
                        break;
                }
            } return done;
        }
    } return done;
}

void doRender(SDL_Renderer *renderer, int areana[WINDOW_WIDTH][WINDOW_HEIGHT]) {
    //background colour
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    //draw background
    SDL_RenderClear(renderer);


    //  Change colour
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // draw areana
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        for (int j = 0; j < WINDOW_HEIGHT; j++) {
            if (areana[i][j] != 0) SDL_RenderDrawPoint(renderer, i, j);
        }
    } 
    
    SDL_RenderPresent(renderer);
}



int main(int argc, char *argv[]) {
    if (WINDOW_WIDTH % RECTX != 0 ) {
        printf("Error WINDOW_WIDTH must me integer multiple of lattice width");
        return(1);
    }

    //  variables needed for iterating
    int i, j;

    //  initialize arena and repeated_rect lattice
    int rect[RECTX][RECTY];
    int areana[WINDOW_WIDTH][WINDOW_HEIGHT];
    for (i = 0; i < WINDOW_WIDTH; i++) {
        for (j = 0; j < WINDOW_HEIGHT; j++) {
            areana[i][j] = 0;
            rect[i/XRATIO][j/YRATIO] = 0;
        }
    }
    
    //INIT SDL
    SDL_Window *window;                    // Declare a window
    SDL_Renderer *renderer;                // Declare a renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("rectLatice", SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int done = 0;
    while (!done) {
        done = processEvents(window, rect);
        //  copy rect to arena
        for (i=0; i < WINDOW_WIDTH; i++) {
            for (j=0; j < WINDOW_HEIGHT; j++) {
                areana[i][j] = rect[i%RECTX][j%RECTY];
            }
        } 
    doRender(renderer, areana);
    }
}
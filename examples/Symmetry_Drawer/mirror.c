// cc mirror.c `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2 -lm && ./a.out

#include<stdio.h>
#include<stdlib.h>
#include "SDL.h"
#include<math.h>

#define WINDOW_WIDTH (2000)
#define WINDOW_HEIGHT (1001)

int processEvents(SDL_Window *window, int arena[WINDOW_WIDTH][WINDOW_HEIGHT]) {
    SDL_Event event;
    int done = 0;
    int mltx = 0, mlty = 0;

    SDL_PumpEvents();


    if (SDL_GetMouseState(&mltx, &mlty) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
        arena[mltx][mlty] = 1;
        arena[WINDOW_WIDTH - mltx][mlty] = 1;
    }

    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_KEYDOWN:
            {
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
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
    } SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    //  variables needed for iterating
    int i, j;

    //  initialize arena and repeated_rect lattice
    int areana[WINDOW_WIDTH][WINDOW_HEIGHT];
    for (i = 0; i < WINDOW_WIDTH; i++) {
        for (j = 0; j < WINDOW_HEIGHT; j++) areana[i][j] = 0;
    }
    
    //INIT SDL
    SDL_Window *window;                    // Declare a window
    SDL_Renderer *renderer;                // Declare a renderer
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(argv[0], SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int done = 0;
    while (!done) {
        done = processEvents(window, areana);
        //SDL_PumpEvents();
        //SDL_Log("1");
    doRender(renderer, areana);
    }
}
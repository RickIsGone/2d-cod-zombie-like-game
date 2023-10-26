#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "../hpp files/all.hpp"

const int WIDTH=1920, HEIGHT=1080;

int main(int argc, char *argv[]){
    bool game_state=true;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event WindowEvent;
    MouseState mouseState = {0, 0, false, false};
    SDL_Rect camera={500,300,WIDTH,HEIGHT};

    start_game();
    mouse(renderer,mouseState);

    SDL_Event event;

    while (game_state) {
        

        while (SDL_PollEvent(&event))
            input_events(event, game_state, camera, mouseState);
        
        map(renderer, camera);
        niga(renderer,mouseState);

        if (game_round.zombie_number==0)
            won_round();
        
        SDL_Delay(1000/240);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
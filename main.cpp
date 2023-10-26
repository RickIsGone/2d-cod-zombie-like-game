#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include "hpp files/all.hpp"



const int WIDTH=1920, HEIGHT=1080;

int main(int argc, char *argv[]){
    bool game_state=true;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL==window){
        std::cout<<"error"<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        std::cout<<"error"<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }

    SDL_Event WindowEvent;
    MouseState mouseState = {0, 0, false, false};
    SDL_Rect camera={0,0,WIDTH,HEIGHT};

    Uint32 old_time, current_time;
    float delta_time;

    old_time = SDL_GetTicks();

    start_game();
    mouse(renderer,mouseState);

    SDL_Event event;

    while (game_state) {

        // current_time = SDL_GetTicks();
        // delta_time = (current_time - old_time) / 1000.0f; // Converti in secondi
        // old_time = current_time;

        
        while (SDL_PollEvent(&event))
            input_events(event, game_state, camera, mouseState,delta_time);
        
        map(renderer, camera);

        if (game_round.zombie_number==0)
            won_round();
            
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
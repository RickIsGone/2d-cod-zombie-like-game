#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/all.hpp"

static const int WIDTH=1920, HEIGHT=1080;
bool start=true;

int main(int argc, char *argv[]){
    std::string game_state="pause";
    bool no_clip=false;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    SDL_Event WindowEvent;
    MouseState mouseState = {0, 0, false, false};
    SDL_Rect camera={500,300,WIDTH,HEIGHT};
    
    Mix_Chunk *step,*ak47_fire,*mp5_fire,*glock18_fire,*reload,*empty_mag;
    step = Mix_LoadWAV("../texture/step.wav");
    ak47_fire = Mix_LoadWAV("../texture/ak47_fire.wav");
    mp5_fire= Mix_LoadWAV("../texture/mp5_fire.wav");
    glock18_fire= Mix_LoadWAV("../texture/glock18_fire.wav");
    reload= Mix_LoadWAV("../texture/reload.wav");
    empty_mag= Mix_LoadWAV("../texture/empty_mag.wav");

    while(game_state=="pause"){

        while (SDL_PollEvent(&event)) pause(game_state,event);
        map(renderer, camera);
        menu(renderer);  
        SDL_RenderPresent(renderer);
        
    }

    start=false;


    start_game();
    mouse(renderer,mouseState);
    
    while (game_state=="true") {
        
        while (SDL_PollEvent(&event)) events(event, game_state);

        mnk_events(camera,mouseState,game_state,event,renderer,no_clip,step,reload,ak47_fire,mp5_fire,glock18_fire,empty_mag);
        map(renderer, camera);
        niga(renderer,mouseState);
        health_check();
        hud_display(renderer,camera);

        SDL_RenderPresent(renderer);

        if (game_round.zombie_number==0) won_round();

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
    return EXIT_SUCCESS;

}
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


bool start=true;
int game_state=PAUSED;

int main(int argc, char *argv[]){
    
    bool no_clip=false;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1920,1080,SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    SDL_Event WindowEvent;
    
    SDL_Rect camera={500,300,1920,1080};
    
    game::texturensound_initiation(renderer);
    
    while(game_state==PAUSED) pause_menu(camera,event,renderer);

    start=false;

    mouse(renderer);

    do{
        if(game_state==RESTART) game_state=RUNNING;
        game::start();
        
        while (game_state==RUNNING){
            
            while (SDL_PollEvent(&event)) events(event);

            mnk_events(camera,event,renderer,no_clip);
            SDL_RenderClear(renderer);
            map(renderer, camera);
            niga(renderer);
            game::health_check();
            hud_display(renderer,camera);

            SDL_RenderPresent(renderer);

            if (game_round.zombie_number==0) game::won_round();

            while(((player.health<=0)||(player.x==98&&(player.y==22||player.y==23))) && game_state==RUNNING){
                game::win_death(event,renderer,camera);
                game::save::saveTopRound();
            }
        }
        
    }while (game_state==RESTART);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
    return EXIT_SUCCESS;

}

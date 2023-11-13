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

static const int WIDTH=1920, HEIGHT=1080;
bool start=true;
int game_state=PAUSED;

int main(int argc, char *argv[]){
    
    bool no_clip=false;
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    SDL_Event WindowEvent;
    
    SDL_Rect camera={500,300,WIDTH,HEIGHT};
    
    game::texturensound_initiation(renderer);
    
    while(game_state==PAUSED) pause_menu(camera,event,renderer);

    start=false;

    do{
        if(game_state==RESTART) game_state=RUNNING;
        game::start();
        mouse(renderer);
        
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

            while (player.health<=0){
                // kill zombie
                while (SDL_PollEvent(&event)) death_events(event);
                death_menu(renderer);
                if(game_state==RESTART) game::death(camera);
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

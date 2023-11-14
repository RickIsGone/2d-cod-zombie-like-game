#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void game::win(SDL_Event event,SDL_Renderer* renderer,SDL_Rect &camera){
    // kill zombie
    while (SDL_PollEvent(&event)) death_events(event);
    win_menu(renderer);
    if(game_state==RESTART) game::restart(camera);
}

void game::death(SDL_Event event,SDL_Renderer*renderer,SDL_Rect &camera){
    // kill zombie
    while (SDL_PollEvent(&event)) death_events(event);
    death_menu(renderer);
    if(game_state==RESTART) game::restart(camera);
}
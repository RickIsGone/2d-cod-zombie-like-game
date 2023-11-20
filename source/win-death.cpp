#include <SDL2/SDL.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void game::win_death(SDL_Event event,SDL_Renderer* renderer,SDL_Rect &camera){
    // kill zombie
    while (SDL_PollEvent(&event)) death_events(event);
    win_death_menu(renderer,camera);
    if(game_state==RESTART) game::restart(camera);
}


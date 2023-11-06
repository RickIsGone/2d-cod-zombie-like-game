#include <SDL2/SDL.h>
#include <iostream>
#include "../hpp files/all.hpp"

Uint32 last_hit = 0;
Uint32 heal_delay = 7500;
int last_check;
int last_health = player.health;

void health_check(){
    if(player.health != last_check && player.health < last_health) {
        last_hit = SDL_GetTicks();
        last_health = player.health;
    } 
    else if(SDL_GetTicks() - last_hit >= heal_delay && player.health < player.health_max) player.health = player.health_max;
    
    last_check = player.health;
}
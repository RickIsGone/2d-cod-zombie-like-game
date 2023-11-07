#include <SDL2/SDL.h>
#include <iostream>
#include "../hpp files/all.hpp"

static Uint32 s_last_hit = 0;
static Uint32 s_heal_delay = 7500;
static int s_last_check;
static int s_last_health = player.health;

void health_check(){
    if(player.health != s_last_check && player.health < s_last_health) {
        s_last_hit = SDL_GetTicks();
        s_last_health = player.health;
    } 
    else if(SDL_GetTicks() - s_last_hit >= s_heal_delay && player.health < player.health_max) player.health = player.health_max;
    
    s_last_check = player.health;
}
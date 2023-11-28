#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void game::spawn_zombie(){
    // spawn degli zombie

    for(int i=0;i<game_round.zombie_number;i++){
        zombies zombie={20,20,game_round.zombie_health,game_round.zombie_speed,game_round.zombie_damage};

        zombie.Hitbox.x = zombie.x-20;
        zombie.Hitbox.y = zombie.y-20;
        zombie.Hitbox.w = 80;
        zombie.Hitbox.h = 80;

        zombie_alive.push_back(zombie);
    }
}

void zombie_display(SDL_Renderer* renderer,SDL_Rect camera){ 
    for(auto& current: zombie_alive){
        SDL_Rect destRect = { current.x*101-camera.x, current.y*101-camera.y, current.Hitbox.w, current.Hitbox.h };
        SDL_RenderCopy(renderer, zombie_texture, NULL, &destRect);  
        // if(SDL_HasIntersection(&current.Hitbox, &player.Hitbox)) std::cout<<"hello world";

    }
}

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cmath>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void game::spawn_zombie(){
    
    zombie_alive.clear();

    for(int i=0;i<game_round.zombie_number;i++){
        zombies zombie={47, 18, game_round.zombie_health, game_round.zombie_speed, game_round.zombie_damage};

        zombie.Hitbox.x = zombie.x;
        zombie.Hitbox.y = zombie.y;
        zombie.Hitbox.w = 80;
        zombie.Hitbox.h = 80;

        zombie.isalive=true;

        zombie_alive.push_back(zombie);
    }
}

static int zombie_round;

void zombie_display(SDL_Renderer* renderer,SDL_Rect camera){ 
    zombie_round=game_round.zombie_number;

    for(auto& current: zombie_alive){
        if(current.isalive){
            // pathfind(current);  richiede troppe risorse, da cambiare
            SDL_Rect destRect = { current.Hitbox.x*101-(camera.x+20), current.Hitbox.y*101-(camera.y+20), current.Hitbox.w, current.Hitbox.h };
            SDL_Rect textureRect = { current.x*101-(camera.x+20), current.y*101-(camera.y+20), 140, 140 };
            double angle = atan2(540 - (current.y*101-camera.y), 940 - (current.x*101-camera.x));
            angle = angle * (180.0 / M_PI); 
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
            SDL_RenderDrawRect(renderer,&current.Hitbox);
            SDL_RenderCopyEx(renderer, zombie_texture, NULL, &textureRect, angle, NULL, SDL_FLIP_NONE);  

            // if(SDL_HasIntersection(&player.Hitbox, &current.Hitbox)) player.health-=current.damage;  //da sistemare
        }
        else zombie_round--;
        
        game_round.zombie_left=zombie_round;
        
        for(auto& bullet:bullets_alive) if(bullet.isalive){
            // if (bullet.x*101-camera.x<0||bullet.x*101-camera.x>1920||bullet.y*101-camera.y<0||bullet.y*101-camera.y>1080) bullet.isalive=false; 
            if(SDL_HasIntersection(&current.Hitbox, &bullet.Hitbox)){
                current.health-=bullet.damage;
                if(current.health<=0){
                    player.money+=50;
                    current.isalive=false;
                }
                else player.money+=10;
                bullet.isalive=false;
            }
        }
    }
}

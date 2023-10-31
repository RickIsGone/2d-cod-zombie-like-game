#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "../hpp files/all.hpp"


void events(SDL_Event event, std::string &game_state){
 
    switch(event.type){  
        case SDL_QUIT:
            game_state="false";
            break;
    }
}

Uint32 reloadStartTime = 0;
const Uint32 reloadDelay = 1500;
Uint32 FireRate = 0;


void mnk_events(SDL_Rect &camera, MouseState &mouseState,std::string &game_state,SDL_Event event,SDL_Renderer* renderer){
    int x, y;

    const Uint32 FireRateDelay =player.weapon.fire_rate;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    Mix_Chunk *sound;

    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    if (state[SDL_SCANCODE_W]) camera.y -= player.speed;
    
    if (state[SDL_SCANCODE_A]) camera.x -= player.speed;
    
    if (state[SDL_SCANCODE_S]) camera.y += player.speed;
    
    if (state[SDL_SCANCODE_D]) camera.x += player.speed;
    
    if (state[SDL_SCANCODE_R]&&player.weapon.ammo!=player.weapon.ammo_max){
        sound = Mix_LoadWAV("../texture/reload.wav");
        Mix_PlayChannel(-1, sound, 0);
        reloadStartTime=SDL_GetTicks();
    } 
    
    if(reloadStartTime!=0&&SDL_GetTicks()-reloadStartTime>=reloadDelay){
        player.weapon.ammo=player.weapon.ammo_max;
        reloadStartTime=0;
    }

    if(state[SDL_SCANCODE_ESCAPE]){

        game_state="pause";
        
        while(game_state=="pause"){
            while (SDL_PollEvent(&event)) pause(game_state,event);
            menu(renderer);  
            SDL_RenderPresent(renderer);
        }
        
    }
    
    if (leftButton && reloadStartTime == 0 && player.weapon.name != "glock18" && player.weapon.name != "knife"&&player.weapon.ammo>0) {
        if (FireRate == 0 || SDL_GetTicks() - FireRate >= FireRateDelay) {
            player.weapon.ammo--;
            FireRate = SDL_GetTicks();
            if(player.weapon.name=="ak47"){
                sound = Mix_LoadWAV("../texture/ak47_fire.wav");
                Mix_PlayChannel(-1, sound, 0);
            }
            else{
                sound = Mix_LoadWAV("../texture/mp5_fire.wav");
                Mix_PlayChannel(-1, sound, 0);
            }
        }
    }
    else if (leftButton && !mouseState.leftButton && reloadStartTime==0) {
        if(player.weapon.name=="glock18"&&player.weapon.ammo>0){
            player.weapon.ammo--;
            sound = Mix_LoadWAV("../texture/ak47_fire.wav");
            Mix_PlayChannel(-1, sound, 0);
        }
        else{
            ;
        }
        
    }

    mouseState.x = x;
    mouseState.y = y;
    mouseState.leftButton = leftButton;
    
}

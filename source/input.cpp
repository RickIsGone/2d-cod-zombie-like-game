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

        case SDL_KEYDOWN:       // weapon switch controll
            switch(event.key.keysym.sym) {
                case SDLK_q:
                    std::swap(player.WeaponInHand,player.WeaponInInventory);
            }
            break;
    }
}

void consolle_events(SDL_Event consolle_event, bool &consolle_state){
    switch(consolle_event.type){  
        case SDL_QUIT:
            consolle_state=false;
            break;
    }
}

static Uint32 s_reloadStartTime = 0;
static const Uint32 s_reloadDelay = 1500;
static Uint32 s_lastStepTime = 0;
static Uint32 s_stepDelay = 325;


void mnk_events(SDL_Rect &camera, MouseState &mouseState,std::string &game_state,SDL_Event event,SDL_Renderer* renderer,bool &no_clip,Mix_Chunk *step,Mix_Chunk *reload,Mix_Chunk *ak47_fire,Mix_Chunk *mp5_fire,Mix_Chunk *glock18_fire,Mix_Chunk *empty_mag){
    int x, y;
    bool automatic=false;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    Mix_Chunk *sound;
    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    if (state[SDL_SCANCODE_W]) {
        camera.y -= player.speed;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 2);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_A]){
        camera.x -= player.speed;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 2);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_S]) {
        camera.y += player.speed;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 2);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_D]) {
        camera.x += player.speed;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 2);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_R]&&player.WeaponInHand.ammo!=player.WeaponInHand.ammo_max&&player.WeaponInHand.ammo_left>0&&s_reloadStartTime==0){
        Mix_PlayChannel(-1, reload, 0);
        s_reloadStartTime=SDL_GetTicks();
    } 

    if(s_reloadStartTime!=0&&SDL_GetTicks()-s_reloadStartTime>=s_reloadDelay){ 
        if(player.WeaponInHand.ammo_left<player.WeaponInHand.ammo_max){
            player.WeaponInHand.ammo+=player.WeaponInHand.ammo_left;
            player.WeaponInHand.ammo_left=0;
        }
        else{
            player.WeaponInHand.ammo_left-=player.WeaponInHand.ammo_max-player.WeaponInHand.ammo;
            player.WeaponInHand.ammo=player.WeaponInHand.ammo_max;
        }
        s_reloadStartTime=0;
    }

    if (state[SDL_SCANCODE_P]) consolle(no_clip);
    
    if(state[SDL_SCANCODE_ESCAPE]){

        game_state="pause";
        
        while(game_state=="pause"){
            while (SDL_PollEvent(&event)) pause(game_state,event);
            menu(renderer);  
            SDL_RenderPresent(renderer);
        }
        
    }
    
    if (leftButton && s_reloadStartTime == 0 && player.WeaponInHand.name != "glock18" && player.WeaponInHand.name != "knife"&&player.WeaponInHand.ammo>0) {
        automatic=true;
        player.WeaponInHand.shoot(automatic,ak47_fire,mp5_fire,glock18_fire,empty_mag);
    }
    else if (leftButton && !mouseState.leftButton && s_reloadStartTime==0) player.WeaponInHand.shoot(automatic,ak47_fire,mp5_fire,glock18_fire,empty_mag);

    mouseState.x = x;
    mouseState.y = y;
    mouseState.leftButton = leftButton;
    
}

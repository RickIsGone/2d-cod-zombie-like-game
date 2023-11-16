#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void events(SDL_Event event){
 
    switch(event.type){  
        case SDL_QUIT:
            game_state=CLOSED;
            break;

        case SDL_KEYDOWN:       // weapon switch controll
            if(game_state==RUNNING){
                switch(event.key.keysym.sym) {
                    case SDLK_q:
                        std::swap(player.WeaponInHand,player.WeaponInInventory);
                        break;
                }
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

void death_events(SDL_Event event){
    switch(event.type){
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym) {
                case SDLK_r:
                    game_state=RESTART;
                    break;
                
            }
            break;
        case SDL_QUIT:
            game_state=CLOSED;
            break;
    }
}

static Uint32 s_reloadStartTime = 0;
static const Uint32 s_reloadDelay = 1500;
static Uint32 s_lastStepTime = 0;
static Uint32 s_stepDelay = 325;


void mnk_events(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer,bool &no_clip){
    int x, y;
    bool automatic=false;
    extern Mix_Chunk *step,*reload;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    Mix_Chunk *sound;
    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    if (state[SDL_SCANCODE_W]) {
        camera.y -= player.speed;
        player.x=camera.x/101;
        player.y=camera.y/101;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 4);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_A]){
        camera.x -= player.speed;
        player.x=camera.x/101;
        player.y=camera.y/101;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 4);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_S]) {
        camera.y += player.speed;
        player.x=camera.x/101;
        player.y=camera.y/101;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 4);
            Mix_PlayChannel(-1, step, 0);
            s_lastStepTime = SDL_GetTicks();
        }
    }
    
    if (state[SDL_SCANCODE_D]) {
        camera.x += player.speed;
        player.x=camera.x/101;
        player.y=camera.y/101;
        if (SDL_GetTicks() - s_lastStepTime > s_stepDelay) {
            Mix_VolumeChunk(step, MIX_MAX_VOLUME / 4);
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

    if (state[SDL_SCANCODE_P]) consolle(no_clip,camera,renderer);
    
    if(state[SDL_SCANCODE_E]) interactions(renderer);
    
    if(state[SDL_SCANCODE_ESCAPE]){

        game_state=PAUSED;
        
        while(game_state==PAUSED) pause_menu(camera,event,renderer);
        
    }
    
    if (leftButton && s_reloadStartTime == 0 && player.WeaponInHand.name != "glock18" && player.WeaponInHand.name != "knife"&&player.WeaponInHand.ammo>0) {
        automatic=true;
        player.WeaponInHand.shoot(automatic);
    }
    else if (leftButton && !mouseState.leftButton && s_reloadStartTime==0) player.WeaponInHand.shoot(automatic);

    mouseState.x = x;
    mouseState.y = y;
    mouseState.leftButton = leftButton;
    
}

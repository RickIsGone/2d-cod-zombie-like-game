#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

void mnk_events(SDL_Rect &camera, MouseState &mouseState,std::string &game_state,SDL_Event event,SDL_Renderer* renderer){
    int x, y;

    const Uint8* state = SDL_GetKeyboardState(NULL);
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    

    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    if (state[SDL_SCANCODE_W]) camera.y -= player.speed;
    
    if (state[SDL_SCANCODE_A]) camera.x -= player.speed;
    
    if (state[SDL_SCANCODE_S]) camera.y += player.speed;
    
    if (state[SDL_SCANCODE_D]) camera.x += player.speed;
    
    if (state[SDL_SCANCODE_R]) reloadStartTime=SDL_GetTicks();
    
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
    
    if (leftButton && !mouseState.leftButton) {
        // if(player.weapon.ammo>0) gun::shoot();
        ;
    }

    mouseState.x = x;
    mouseState.y = y;
    mouseState.leftButton = leftButton;

}

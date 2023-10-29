#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "../hpp files/all.hpp"



void events(SDL_Event event, bool &game_state){
 
    switch(event.type){  
        case SDL_QUIT:
            game_state=false;
            break;
    }
}

void mnk_events(SDL_Rect &camera, MouseState &mouseState){
    int x, y;

    const Uint8* state = SDL_GetKeyboardState(NULL);
    Uint32 buttons = SDL_GetMouseState(&x, &y);

    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    if (state[SDL_SCANCODE_W]) camera.y -= player.speed;
    
    if (state[SDL_SCANCODE_A]) camera.x -= player.speed;
    
    if (state[SDL_SCANCODE_S]) camera.y += player.speed;
    
    if (state[SDL_SCANCODE_D]) camera.x += player.speed;
    
    if (state[SDL_SCANCODE_R]) ;
    
    if (leftButton && !mouseState.leftButton) {
        // if(player.weapon.ammo>0) gun::shoot();
        ;
    }

    mouseState.x = x;
    mouseState.y = y;
    mouseState.leftButton = leftButton;

}

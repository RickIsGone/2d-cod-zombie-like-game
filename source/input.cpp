#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "../hpp files/all.hpp"



void input_events(SDL_Event event, bool &game_state, SDL_Rect &camera, MouseState &mouseState){
    
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W]) 
        camera.y -= player.speed;
    
    if (state[SDL_SCANCODE_A]) 
        camera.x -= player.speed;
    
    if (state[SDL_SCANCODE_S]) 
        camera.y += player.speed;
    
    if (state[SDL_SCANCODE_D]) 
        camera.x += player.speed;
    
    if (state[SDL_SCANCODE_R])
        ;
    
    if (mouseState.leftButton) 
        ;

    switch(event.type){  
        case SDL_QUIT:
            game_state=false;
            break;
            
        case SDL_MOUSEMOTION:
            mouseState.x = event.motion.x;
            mouseState.y = event.motion.y;
            break;

        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button){
                case SDL_BUTTON_LEFT:
                    mouseState.leftButton = true;
                    break;
            }
            break;

        case SDL_MOUSEBUTTONUP:
            switch(event.button.button){
                case SDL_BUTTON_LEFT:
                    mouseState.leftButton = false;
                    break;
            }
            break;
            
    }
 
}
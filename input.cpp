#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "hpp files/all.hpp"

bool keyState[SDL_NUM_SCANCODES] = {false};


void input_events(SDL_Event event, bool &game_state, SDL_Rect &camera, MouseState &mouseState, float delta_time){
    
    switch(event.type){  
        case SDL_QUIT:
            game_state=false;
            break;
            
        case SDL_KEYDOWN:
            keyState[event.key.keysym.scancode] = true;
            break;

        case SDL_KEYUP:
            keyState[event.key.keysym.scancode] = false;
            break;

        case SDL_MOUSEMOTION:
            // Registra la posizione del mouse, ma non la usi per aggiornare la posizione della videocamera
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

    if (keyState[SDL_SCANCODE_W]) camera.y -= 30 * delta_time;
    if (keyState[SDL_SCANCODE_A]) camera.x -= 30 * delta_time;
    if (keyState[SDL_SCANCODE_S]) camera.y += 30 * delta_time;
    if (keyState[SDL_SCANCODE_D]) camera.x += 30 * delta_time;
    if (mouseState.leftButton) std::cout<<"a";
    
}
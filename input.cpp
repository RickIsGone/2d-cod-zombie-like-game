#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "hpp files/all.hpp"

bool keyState[SDL_NUM_SCANCODES] = {false};
MouseState mouseState = {0, 0, false, false};

void input_events(SDL_Event event, bool &game_state, SDL_Rect &camera){
    
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
            if (event.button.button == SDL_BUTTON_LEFT)
                mouseState.leftButton = true;
            else if (event.button.button == SDL_BUTTON_RIGHT)
                mouseState.rightButton = true;
            break;

        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                mouseState.leftButton = false;
            else if (event.button.button == SDL_BUTTON_RIGHT)
                mouseState.rightButton = false;
            break;
    }

    if (keyState[SDL_SCANCODE_W]) camera.y -= 10;
    if (keyState[SDL_SCANCODE_A]) camera.x -= 10;
    if (keyState[SDL_SCANCODE_S]) camera.y += 10;
    if (keyState[SDL_SCANCODE_D]) camera.x += 10;

    
}
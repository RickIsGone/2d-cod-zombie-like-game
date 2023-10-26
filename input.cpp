#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "hpp files/all.hpp"



void input_events(SDL_Event event, bool &game_state, SDL_Rect &camera, MouseState &mouseState, float delta_time){
    
    switch(event.type){  
        case SDL_QUIT:
            game_state=false;
            break;
            
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym){
                case SDLK_w:
                    camera.y -= player.speed; //* delta_time;
                    std::cout<<"su";
                    break;

                case SDLK_a:
                    camera.x -= player.speed; //* delta_time;
                    std::cout<<"sinistra";
                    break;

                case SDLK_s:
                    camera.y += player.speed; //* delta_time;
                    std::cout<<"giu";
                    break;

                case SDLK_d:
                    camera.x += player.speed; //* delta_time;
                    std::cout<<"destra";
                    break;
            }
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

    
    if (mouseState.leftButton) std::cout<<"a";
    
}
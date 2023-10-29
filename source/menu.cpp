#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include "../hpp files/all.hpp"

void menu(bool &game_state){
    int x,y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
    if (leftButton) game_state=true;
    
}
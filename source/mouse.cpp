#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

void mouse(SDL_Renderer* renderer){
    
    SDL_Surface* cursorSurface = IMG_Load("../texture/mouse.png");
    int hot_x = cursorSurface->w / 2;
    int hot_y = cursorSurface->h / 2;
    SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, hot_x, hot_y);
    SDL_SetCursor(cursor);
    
    SDL_Rect destrect = { mouseState.x - 64 / 2, mouseState.y - 32 / 2, 64, 32 };
    
}

void mouse_update(){
    int mouse_x, mouse_y;
    Uint32 buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;

    mouseState.x = mouse_x;
    mouseState.y = mouse_y;
    mouseState.leftButton = leftButton;
}
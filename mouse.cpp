#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "hpp files/all.hpp"

void mouse(SDL_Renderer* renderer,MouseState mouseState){
    SDL_Surface* cursorSurface = IMG_Load("texture/mouse.png");
    int hot_x = cursorSurface->w / 2;
    int hot_y = cursorSurface->h / 2;
    SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, hot_x, hot_y);
    SDL_SetCursor(cursor);
    
    SDL_Rect destrect = { mouseState.x - 64 / 2, mouseState.y - 32 / 2, 64, 32 };
    SDL_RenderPresent(renderer);
}
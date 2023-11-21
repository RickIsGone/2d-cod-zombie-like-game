#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void sdl::quick_text(std::string writing,int size, Uint8 r,Uint8 g,Uint8 b,int y,SDL_Renderer* renderer){
    font_f = TTF_OpenFont("../texture/hud_font.otf", size);
            
    SDL_Surface* surface = TTF_RenderText_Solid(font_f, writing.c_str(), {r, g, b}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = {(1920 - text_width) / 2, y, text_width, text_height };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}

void sdl::v_quick_text(std::string writing, int var,int size, Uint8 r,Uint8 g,Uint8 b,int y,SDL_Renderer* renderer){

    font_f = TTF_OpenFont("../texture/hud_font.otf", size);
    std::string text =writing+std::to_string(var);        
    SDL_Surface* surface = TTF_RenderText_Solid(font_f, text.c_str(), {r, g, b}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = {(1920 - text_width) / 2, y, text_width, text_height };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}


void sdl::button(std::string text,int size, int x,int y,int width, int height,Uint8 r,Uint8 g,Uint8 b,Uint8 r_h,Uint8 g_h,Uint8 b_h,SDL_Renderer* renderer,int value){

    mouse_update();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect2;
    rect2.x = x-2; 
    rect2.y = y-2; 
    rect2.w = width+4; 
    rect2.h = height+4; 

    SDL_RenderFillRect(renderer, &rect2);

    if((mouseState.x>=x&&mouseState.x<=x+width)&&(mouseState.y>=y&&mouseState.y<=y+height)){
        if(mouseState.leftButton) game_state=value;
        else SDL_SetRenderDrawColor(renderer, r_h, g_h, b_h, 255);
    }
    else SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    SDL_Rect rect;
    rect.x = x; 
    rect.y = y; 
    rect.w = width; 
    rect.h = height;  
    
    SDL_RenderFillRect(renderer, &rect);

    font_f = TTF_OpenFont("../texture/hud_font.otf", size);
            
    SDL_Surface* surface = TTF_RenderText_Solid(font_f, text.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = {(1920 - text_width) / 2, y+3, text_width, text_height };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
}
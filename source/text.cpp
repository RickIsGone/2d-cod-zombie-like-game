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


// void sdl::v_quick_text(std::string writing,int size, int r,int g,int b,int y, std::string writing2, int var,int size2, int r2,int g2,int b2,int y2,SDL_Renderer* renderer){

//     font_f = TTF_OpenFont("../texture/hud_font.otf", size);

//     SDL_Surface* surface = TTF_RenderText_Solid(font_f, writing.c_str(), {r, g, b}); 
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//     int text_width = surface->w;
//     int text_height = surface->h;
//     SDL_FreeSurface(surface); 

//     SDL_Rect dstrect = {(1920 - text_width) / 2, y, text_width, text_height };

//     SDL_RenderCopy(renderer, texture, NULL, &dstrect);
//     SDL_DestroyTexture(texture);
//     SDL_RenderPresent(renderer);

//     std::string text =writing2+std::to_string(var);        
//     SDL_Surface* surface2 = TTF_RenderText_Solid(font_f, text.c_str(), {r2, g2, b2}); 
//     SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface);
//     int text_width2 = surface->w;
//     int text_height2 = surface->h;
//     SDL_FreeSurface(surface); 

//     SDL_Rect dstrect = {(1920 - text_width2) / 2, y, text_width2, text_height2 };

//     SDL_RenderCopy(renderer, texture2, NULL, &dstrect);
//     SDL_DestroyTexture(texture2);
//     SDL_RenderPresent(renderer);
// }
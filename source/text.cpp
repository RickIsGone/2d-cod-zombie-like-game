#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

TTF_Font* font_f;

void sdl::quick_text(std::string writing,int size, int r,int g,int b,SDL_Renderer* renderer){
    font_f = TTF_OpenFont("../texture/hud_font.otf", size);
            
    SDL_Surface* surface = TTF_RenderText_Solid(font_f, writing.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = {(1920 - text_width) / 2, (1080 - text_height) / 3, text_width, text_height };

    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font_f);
    SDL_RenderPresent(renderer);
}
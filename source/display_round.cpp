#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h> 
#include"../hpp files/all.hpp"



void round_display(SDL_Renderer* renderer) {

    TTF_Font* font = TTF_OpenFont("../texture/round_font.ttf", 24);
    if (font == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    return;
    }
    std::string round_str = std::to_string(game_round.round_number);
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { (1920 - text_width) / 2, 1000, text_width, text_height }; 
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_RenderPresent(renderer);

    SDL_RenderClear(renderer);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}
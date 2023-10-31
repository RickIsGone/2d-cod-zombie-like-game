#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include "../hpp files/all.hpp"

void menu(bool &game_state, SDL_Renderer* renderer){

    int x,y;
    Uint32 buttons = SDL_GetMouseState(&x, &y);
    bool leftButton = (buttons & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;


    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 60);
    
    std::string round_str = "press LMB to start";
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { (1920 - text_width) / 2, (1080 - text_height) / 2.5f, text_width, text_height };
    
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);


    if (leftButton) game_state=true;
    
}
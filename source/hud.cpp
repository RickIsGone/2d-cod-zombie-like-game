#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

void round_display(SDL_Renderer* renderer,SDL_Rect camera) {

    TTF_Font* font = TTF_OpenFont("../texture/round_font.ttf", 60);
    
    std::string round_str = std::to_string(game_round.round_number);
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { 50, 40, text_width, text_height };
    
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

}

void health_display(SDL_Renderer* renderer,SDL_Rect camera){

    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 60);
    
    std::string round_str = std::to_string(player.health)+" HP";
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { 50, 980, text_width, text_height };
    
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

}

void ammo_display(SDL_Renderer* renderer,SDL_Rect camera){

    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 60);
    
    std::string round_str = std::to_string(player.WeaponInHand.ammo)+"/"+std::to_string(player.WeaponInHand.ammo_left);
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { 1735, 980, text_width, text_height };
    
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    
}

void money_display(SDL_Renderer* renderer,SDL_Rect camera){
    
    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 30);
    
    std::string round_str = "$"+std::to_string(player.money);
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { 50, 960, text_width, text_height };
    
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    
}


void hud_display(SDL_Renderer* renderer,SDL_Rect camera){

    round_display(renderer,camera);
    health_display(renderer,camera);
    money_display(renderer,camera);
    ammo_display(renderer,camera);

}
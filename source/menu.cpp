#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include "../hpp files/all.hpp"

extern bool start;
int opacity=255;
bool down=true;

void menu(SDL_Renderer* renderer){

    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 60);
    std::string round_str;

    if(start){
        round_str = "press LMB to start";
    } 
    else round_str = "press LMB to resume";
    
    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { (1920 - text_width) / 2, (1080 - text_height) / 3, text_width, text_height };


    if (opacity==0){
        SDL_SetTextureAlphaMod(texture,opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        down=false;
    }
    if(down==true){
        SDL_SetTextureAlphaMod(texture,opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        opacity-=3;
    }
    else{
        SDL_SetTextureAlphaMod(texture,opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        opacity+=3;
        if(opacity==255) down=true;
    }
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

}

void pause(std::string &game_state,SDL_Event event){
    switch(event.type){
        case SDL_MOUSEBUTTONDOWN: 
            if (event.button.button == SDL_BUTTON_LEFT) 
                game_state = "true";
            break;
        case SDL_QUIT:
            game_state="false";
            break;
    }
}
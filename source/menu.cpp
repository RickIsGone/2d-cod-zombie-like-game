#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h> 
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

extern bool start;
static int s_opacity=255;
static bool s_down=true;

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


    if (s_opacity==0){
        SDL_SetTextureAlphaMod(texture,s_opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        s_down=false;
    }
    if(s_down==true){
        SDL_SetTextureAlphaMod(texture,s_opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        s_opacity-=1;
    }
    else{
        SDL_SetTextureAlphaMod(texture,s_opacity);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        s_opacity+=1;
        if(s_opacity==255) s_down=true;
    }
    

    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);

}

void pause(SDL_Event event){
    switch(event.type){
        case SDL_MOUSEBUTTONDOWN: 
            if (event.button.button == SDL_BUTTON_LEFT) 
                game_state = RUNNING;
            break;
        case SDL_QUIT:
            game_state=CLOSED;
            break;
    }
}

void pause_menu(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer){
    while (SDL_PollEvent(&event)) pause(event);
        SDL_RenderClear(renderer);
        map(renderer, camera);
        menu(renderer);  
        SDL_RenderPresent(renderer);
}

void death_menu(SDL_Renderer*renderer){
    sdl::quick_text("you died, press r to restart",60,0,0,0,345,renderer);
}

void win_menu(SDL_Renderer*renderer){
    sdl::quick_text("you escaped, press r to restart",60,0,0,0,345,renderer);
}
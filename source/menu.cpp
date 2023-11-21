#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


static int s_opacity=255;
static bool s_down=true;

void menu(SDL_Renderer* renderer){

    TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 60);
    std::string round_str;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect2;
    rect2.x = 518; 
    rect2.y = 318; 
    rect2.w = 884; 
    rect2.h = 504; 
    SDL_RenderFillRect(renderer, &rect2);

    SDL_SetRenderDrawColor(renderer, 92, 92, 92, 255);
    SDL_Rect rect;
    rect.x = 520; 
    rect.y = 320; 
    rect.w = 880; 
    rect.h = 500; 
    SDL_RenderFillRect(renderer, &rect);

    if(start){
        round_str = "press LMB to start";
        sdl::v_quick_text("highest round reached    ", game::save::loadTopRound(), 50, 0, 0, 0, 430, renderer);
        sdl::button("start", 30, 900, 555, 120, 40, 92, 92, 92,renderer,RUNNING);
    } 
    else{
        round_str = "game paused";
        sdl::button("resume", 30, 900, 505, 120, 40, 92, 92, 92,renderer,RUNNING);
        sdl::button("restart", 30, 900, 555, 120, 40, 92, 92, 92,renderer,RESTART);
    }

    sdl::button("exit", 30, 900, 605, 120, 40, 92, 92, 92,renderer,CLOSED);

    SDL_Surface* surface = TTF_RenderText_Solid(font, round_str.c_str(), {0, 0, 0}); 
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    int text_width = surface->w;
    int text_height = surface->h;
    SDL_FreeSurface(surface); 

    SDL_Rect dstrect = { (1920 - text_width) / 2, 345, text_width, text_height };


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


void pause_menu(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer){
    while (SDL_PollEvent(&event)) events(event);
    SDL_RenderClear(renderer);
    map(renderer, camera);
    menu(renderer);  
    SDL_RenderPresent(renderer);
    if(game_state==RESTART) game::restart(camera);
}


void win_death_menu(SDL_Renderer*renderer,SDL_Rect camera){
 
    SDL_RenderClear(renderer);
    map(renderer,camera);

    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect2;
    rect2.x = 518; 
    rect2.y = 318; 
    rect2.w = 884; 
    rect2.h = 504; 
    SDL_RenderFillRect(renderer, &rect2);

    SDL_SetRenderDrawColor(renderer, 92, 92, 92, 255);
    SDL_Rect rect;
    rect.x = 520; 
    rect.y = 320; 
    rect.w = 880; 
    rect.h = 500; 
    SDL_RenderFillRect(renderer, &rect);


    sdl::button("restart", 30, 900, 555, 120, 40, 92, 92, 92,renderer,RESTART);
    sdl::button("exit", 30, 900, 605, 120, 40, 92, 92, 92,renderer,CLOSED);

    if(player.health>0){
        sdl::quick_text("you escaped", 60, 0, 0, 0, 345, renderer);
        sdl::v_quick_text("rounds before escaping    ", game_round.round_number, 50, 0, 0, 0, 430, renderer);
    }
    else{
        sdl::quick_text("you died", 60, 0, 0, 0, 345, renderer);
        sdl::v_quick_text("rounds lasted    ", game_round.round_number, 50, 0, 0, 0, 430, renderer);
    }
    SDL_RenderPresent(renderer);

}
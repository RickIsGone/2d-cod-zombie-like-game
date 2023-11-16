#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

Uint32 g_time;

void interactions(SDL_Renderer* renderer){
    // fence
    if((player.x==94||player.x==93)&&(player.y==22||player.y==21||player.y==23)){

        if(player.has_cutters) game::open_fence();

        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=3000){
                TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 50);
                std::string death_str="you need wire cuters to escape";

                SDL_Surface* surface = TTF_RenderText_Solid(font, death_str.c_str(), {0, 0, 0}); 
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                int text_width = surface->w;
                int text_height = surface->h;
                SDL_FreeSurface(surface); 

                SDL_Rect dstrect = { (1920 - text_width) / 2, (1080 - text_height) / 3, text_width, text_height };

                
                SDL_RenderCopy(renderer, texture, NULL, &dstrect);
                SDL_DestroyTexture(texture);
                TTF_CloseFont(font);
                SDL_RenderPresent(renderer);
            }
            
        }
    } 

    // ak
    if((player.x==77||player.x==78)&&player.y==0){

        if(player.WeaponInHand.name=="ak47") {
            if(player.money>=250&&player.WeaponInHand.ammo_left!=240){
                player.WeaponInHand.ammo_left=240;
                player.money-=250;
            } 
        }
        else if(player.WeaponInInventory.name=="ak47"){
            if(player.money>=250&&player.WeaponInInventory.ammo_left!=240){ 
                player.WeaponInInventory.ammo_left=240;
                player.money-=250;
            }
        }
        else if(player.money>=4500){
            player.WeaponInHand=ak47;
            player.money-=4500;
        }
        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=3000){
                TTF_Font* font = TTF_OpenFont("../texture/hud_font.otf", 50);
                std::string death_str="you need 4500$ to buy the ak";

                SDL_Surface* surface = TTF_RenderText_Solid(font, death_str.c_str(), {0, 0, 0}); 
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                int text_width = surface->w;
                int text_height = surface->h;
                SDL_FreeSurface(surface); 

                SDL_Rect dstrect = { (1920 - text_width) / 2, (1080 - text_height) / 3, text_width, text_height };

                
                SDL_RenderCopy(renderer, texture, NULL, &dstrect);
                SDL_DestroyTexture(texture);
                TTF_CloseFont(font);
                SDL_RenderPresent(renderer);
            }
            
        }
    }

    // mp5

    // glock 

    // wire cutters
}
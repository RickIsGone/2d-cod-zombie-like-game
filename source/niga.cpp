#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <cmath> 
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

void niga(SDL_Renderer* renderer,MouseState mouseState){

    SDL_Texture* loaded_texture;
    
    if(player.WeaponInHand.name=="ak47") loaded_texture=IMG_LoadTexture(renderer, "../texture/ak47.png");

    else if(player.WeaponInHand.name=="mp5") loaded_texture=IMG_LoadTexture(renderer, "../texture/mp5.png");

    else if(player.WeaponInHand.name=="glock18") loaded_texture= IMG_LoadTexture(renderer, "../texture/glock.png");

    else loaded_texture=IMG_LoadTexture(renderer, "../texture/knife.png");

    
    int centerX = 1920 / 2; 
    int centerY = 1080 / 2; 
    double angle = atan2(centerY - mouseState.y, centerX - mouseState.x) * 180 / M_PI;
    angle -= 90; 

    
    SDL_Rect spriteRect;
    spriteRect.x = centerX;
    spriteRect.y = centerY;
    SDL_QueryTexture(loaded_texture, NULL, NULL, &spriteRect.w, &spriteRect.h); 
    spriteRect.x -= spriteRect.w / 2; 
    spriteRect.y -= spriteRect.h / 2;

    
    SDL_RenderCopyEx(renderer, loaded_texture, NULL, &spriteRect, angle, NULL, SDL_FLIP_NONE);

    
    
    SDL_DestroyTexture(loaded_texture); 
    
}
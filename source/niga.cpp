#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath> 
#include "../hpp files/all.hpp"

void niga(SDL_Renderer* renderer,MouseState mouseState){

    SDL_Texture* loaded_texture;
    
    if(player.weapon.name=="ak47") loaded_texture=IMG_LoadTexture(renderer, "../texture/ak47.png");

    else if(player.weapon.name=="mp5") loaded_texture=IMG_LoadTexture(renderer, "../texture/mp5.png");

    else if(player.weapon.name=="glock18") loaded_texture= IMG_LoadTexture(renderer, "../texture/glock.png");

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
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/all.hpp"


void texturensound_initiation(SDL_Renderer* renderer){
    extern step = Mix_LoadWAV("../texture/step.wav");
    extern ak47_fire = Mix_LoadWAV("../texture/ak47_fire.wav");
    extern mp5_fire= Mix_LoadWAV("../texture/mp5_fire.wav");
    extern glock18_fire= Mix_LoadWAV("../texture/glock18_fire.wav");
    extern reload= Mix_LoadWAV("../texture/reload.wav");
    extern empty_mag= Mix_LoadWAV("../texture/empty_mag.wav");

    extern wall_texture = IMG_LoadTexture(renderer, "../texture/wall.png");
    extern ground_texture = IMG_LoadTexture(renderer, "../texture/ground.png");
    extern outside_texture=IMG_LoadTexture(renderer,"../texture/outside.png");
    extern glock18_outline_texture=IMG_LoadTexture(renderer,"../texture/glock18_outline.png");
    extern ak_outline_texture=IMG_LoadTexture(renderer,"../texture/ak_outline.png");
    extern mp5_outline_texture=IMG_LoadTexture(renderer,"../texture/mp5_outline.png");
    extern zombie_texture=IMG_LoadTexture(renderer,"../texture/zombie.png");
} 

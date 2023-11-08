#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/all.hpp"


Mix_Chunk *step,*ak47_fire,*mp5_fire,*glock18_fire,*reload,*empty_mag;
SDL_Texture* wall_texture,*ground_texture,*outside_texture,*glock18_outline_texture,*ak_outline_texture,*mp5_outline_texture,*zombie_texture;

void texturensound_initiation(SDL_Renderer* renderer){
    step = Mix_LoadWAV("../texture/step.wav");
    ak47_fire = Mix_LoadWAV("../texture/ak47_fire.wav");
    mp5_fire= Mix_LoadWAV("../texture/mp5_fire.wav");
    glock18_fire= Mix_LoadWAV("../texture/glock18_fire.wav");
    reload= Mix_LoadWAV("../texture/reload.wav");
    empty_mag= Mix_LoadWAV("../texture/empty_mag.wav");

    wall_texture = IMG_LoadTexture(renderer, "../texture/wall.png");
    ground_texture = IMG_LoadTexture(renderer, "../texture/ground.png");
    outside_texture=IMG_LoadTexture(renderer,"../texture/outside.png");
    glock18_outline_texture=IMG_LoadTexture(renderer,"../texture/glock18_outline.png");
    ak_outline_texture=IMG_LoadTexture(renderer,"../texture/ak_outline.png");
    mp5_outline_texture=IMG_LoadTexture(renderer,"../texture/mp5_outline.png");
    zombie_texture=IMG_LoadTexture(renderer,"../texture/zombie.png");
} 
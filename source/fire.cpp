#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/all.hpp"

Uint32 FireRate = 0;

void gun::shoot(bool automatic, Mix_Chunk *sound){
    Uint32 FireRateDelay =player.weapon.fire_rate;
    if(automatic){
        if (FireRate == 0 || SDL_GetTicks() - FireRate >= FireRateDelay) {
            player.weapon.ammo--;
            FireRate = SDL_GetTicks();

            if(player.weapon.name=="ak47") sound = Mix_LoadWAV("../texture/ak47_fire.wav");
            else sound = Mix_LoadWAV("../texture/mp5_fire.wav");   
        }
    }
    else if(player.weapon.name=="glock18"&&player.weapon.ammo>0){
        player.weapon.ammo--;
        sound = Mix_LoadWAV("../texture/glock18_fire.wav");
    }
    else sound = Mix_LoadWAV("../texture/empty_mag.wav");
    Mix_VolumeChunk(sound, MIX_MAX_VOLUME / 2.5);
    Mix_PlayChannel(-1, sound, 0);
}
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/all.hpp"

Uint32 FireRate = 0;

void gun::shoot(bool automatic,Mix_Chunk *ak47_fire,Mix_Chunk *mp5_fire,Mix_Chunk *glock18_fire,Mix_Chunk *empty_mag){
    Uint32 FireRateDelay =player.weapon.fire_rate;
    Mix_Chunk *sound;
    if(automatic){
        if (FireRate == 0 || SDL_GetTicks() - FireRate >= FireRateDelay) {
            player.weapon.ammo--;
            FireRate = SDL_GetTicks();

            if(player.weapon.name=="ak47"){
                Mix_VolumeChunk(ak47_fire, MIX_MAX_VOLUME / 2.5);
                Mix_PlayChannel(-1, ak47_fire, 0);
            }
            else{
                Mix_VolumeChunk(mp5_fire, MIX_MAX_VOLUME / 2.5);
                Mix_PlayChannel(-1, mp5_fire, 0);
            }
        }
    }
    else if(player.weapon.name=="glock18"&&player.weapon.ammo>0){
        player.weapon.ammo--;
        Mix_VolumeChunk(glock18_fire, MIX_MAX_VOLUME / 2.5);
        Mix_PlayChannel(-1, glock18_fire, 0);;
    }
    else if(player.weapon.name!="knife"){
        Mix_VolumeChunk(empty_mag, MIX_MAX_VOLUME / 2.5);
        Mix_PlayChannel(-1, empty_mag, 0);
    }
}
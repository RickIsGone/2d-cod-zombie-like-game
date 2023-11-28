#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void bullet_generation(){
    bullets bullet={player.WeaponInHand.damage,30,player.x,player.y};
    bullet.Hitbox.x=player.x;
    bullet.Hitbox.y=player.y;
    bullet.Hitbox.h=10;
    bullet.Hitbox.w=5;
    bullet.isalive=true;
    bullets_alive.push_back(bullet);
}


static Uint32 s_FireRate = 0;

void gun::shoot(bool automatic){

    Uint32 FireRateDelay =player.WeaponInHand.fire_rate;

    if(automatic){
        if (s_FireRate == 0 || SDL_GetTicks() - s_FireRate >= FireRateDelay) {
            player.WeaponInHand.ammo--;
            s_FireRate = SDL_GetTicks();

            if(player.WeaponInHand.name=="ak47"){
                Mix_VolumeChunk(ak47_fire, MIX_MAX_VOLUME / 2.5);
                Mix_PlayChannel(-1, ak47_fire, 0);
            }
            else{
                Mix_VolumeChunk(mp5_fire, MIX_MAX_VOLUME / 2.5);
                Mix_PlayChannel(-1, mp5_fire, 0);
            }
        }
    }
    else if(player.WeaponInHand.name=="glock18"&&player.WeaponInHand.ammo>0){
        player.WeaponInHand.ammo--;
        Mix_VolumeChunk(glock18_fire, MIX_MAX_VOLUME / 2.5);
        Mix_PlayChannel(-1, glock18_fire, 0);;
    }
    else if(player.WeaponInHand.name=="knife"){
        Mix_VolumeChunk(knife_swoosh, MIX_MAX_VOLUME );
        Mix_PlayChannel(-1, knife_swoosh, 0);;
    }
    else {
        Mix_VolumeChunk(empty_mag, MIX_MAX_VOLUME / 2.5);
        Mix_PlayChannel(-1, empty_mag, 0);
    }
    if(player.WeaponInHand.name!="knife") bullet_generation();
}
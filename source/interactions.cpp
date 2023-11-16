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
            if(SDL_GetTicks() - g_time <=3000) sdl::quick_text("you need wire cuters to escape",50,0,0,0,renderer);            
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
            if(SDL_GetTicks() - g_time <=3000) sdl::quick_text("you need 4500$ to buy the ak47",50,0,0,0,renderer);
        }
    }

    // mp5
    if((player.x==74||player.x==75)&&player.y>=19&&player.y<=21){

        if(player.WeaponInHand.name=="mp5") {
            if(player.money>=250&&player.WeaponInHand.ammo_left!=200){
                player.WeaponInHand.ammo_left=200;
                player.money-=250;
            } 
        }
        else if(player.WeaponInInventory.name=="mp5"){
            if(player.money>=250&&player.WeaponInInventory.ammo_left!=200){ 
                player.WeaponInInventory.ammo_left=200;
                player.money-=250;
            }
        }
        else if(player.money>=3700){
            player.WeaponInHand=mp5;
            player.money-=3700;
        }
        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=3000) sdl::quick_text("you need 3700$ to buy the mp5",50,0,0,0,renderer);
        }
    }
    // glock 

    // wire cutters
}
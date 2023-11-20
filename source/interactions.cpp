#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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
            if(SDL_GetTicks() - g_time <=1500) sdl::quick_text("you need wire cuters to escape",40,0,0,0,670,renderer);            
        }
    }

    // ak
    if((player.x==77||player.x==78)&&player.y==0){

        if(player.WeaponInHand.name=="ak47") {
            if(player.money>=250&&player.WeaponInHand.ammo_left!=240){
                player.WeaponInHand.ammo_left=240;
                player.money-=250;
            } 
            else if(player.money<250) sdl::quick_text("you need $250 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.WeaponInInventory.name=="ak47"){
            if(player.money>=250&&player.WeaponInInventory.ammo_left!=240){ 
                player.WeaponInInventory.ammo_left=240;
                player.money-=250;
            }
            else if(player.money<250) sdl::quick_text("you need $250 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.money>=4500){
            player.WeaponInHand=ak47;
            player.money-=4500;
        }
        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=1500) sdl::quick_text("you need $4500 to buy the ak47",40,0,0,0,670,renderer);
        }
    }

    // mp5
    if((player.x==74||player.x==75)&&player.y>=19&&player.y<=21){

        if(player.WeaponInHand.name=="mp5") {
            if(player.money>=250&&player.WeaponInHand.ammo_left!=200){
                player.WeaponInHand.ammo_left=200;
                player.money-=250;
            } 
            else if(player.money<250) sdl::quick_text("you need $250 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.WeaponInInventory.name=="mp5"){
            if(player.money>=250&&player.WeaponInInventory.ammo_left!=200){ 
                player.WeaponInInventory.ammo_left=200;
                player.money-=250;
            }
            else if(player.money<250) sdl::quick_text("you need $250 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.money>=3700){
            player.WeaponInHand=mp5;
            player.money-=3700;
        }
        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=1500) sdl::quick_text("you need $3700 to buy the mp5",40,0,0,0,670,renderer);
        }
    }

    // glock 
    if((player.x==15||player.x==18)&&(player.y==4||player.y==5)){

        if(player.WeaponInHand.name=="glock18") {
            if(player.money>=150&&player.WeaponInHand.ammo_left!=200){
                player.WeaponInHand.ammo_left=200;
                player.money-=150;
            } 
            else if(player.money<150) sdl::quick_text("you need $150 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.WeaponInInventory.name=="mp5"){
            if(player.money>=250&&player.WeaponInInventory.ammo_left!=200){ 
                player.WeaponInInventory.ammo_left=200;
                player.money-=250;
            }
            else if(player.money<150) sdl::quick_text("you need $150 to buy ammo",40,0,0,0,670,renderer); 
        }
        else if(player.money>=700){
            player.WeaponInHand=glock18;
            player.money-=700;
        }
        else{
            g_time=SDL_GetTicks();
            if(SDL_GetTicks() - g_time <=1500) sdl::quick_text("you need $700 to buy the glock 18",40,0,0,0,670,renderer);
        }
    }

    // wire cutters
    if((player.x==0||player.x==1)&&(player.y==18||player.y==19)){

        if(!player.has_cutters) if(player.money>=10000) player.has_cutters=1;
        else sdl::quick_text("you need $10000 to buy the wire cutters",40,0,0,0,670,renderer);
    }


    SDL_RenderPresent(renderer);
    
}
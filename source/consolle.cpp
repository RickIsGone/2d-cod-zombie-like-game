#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "../hpp files/all.hpp"

using namespace std;
// to use the consolle remove WIN32 from the CmakeLists and always use exit to stop consolle execution

void consolle(bool &no_clip){
    string comand;
    int value;
    
    while(true){
        
        std::cout<<"comands:\nplayer_money (value)\nplayer_health (value)\nplayer_speed (value)\ngun_ammo (value)\nexit\nplayer_weapon (value)\ngun_damage\nfire_rate\nno_clip\n\n";
        std::cin>>comand;
        if(comand=="exit") goto exit;
        else if(comand=="gun_damage") cout<<player.weapon.damage<<"\n";
        else if (comand=="fire_rate") cout<<player.weapon.fire_rate<<"\n";
        else if (comand=="no_clip"){
            if(!no_clip) no_clip=true;
            else no_clip=false;
        }
        else if (comand!="player_money"&&comand!="player_health"&&comand!="player_speed"&&comand!="gun_ammo"&&comand!="player_money"&&comand!="player_weapon")cout<<"syntax error\n\n";
        else{
        
            cin>>value;
            if(comand=="player_money") player.money=value;
            else if(comand=="player_health") player.health=value;
            else if(comand=="player_speed") player.speed=value;
            else if(comand=="gun_ammo") player.weapon.ammo=value;
            else if (comand=="player_weapon")
                switch (value){
                    case 1:
                        player.weapon=ak47;
                        break;
                    case 2:
                        player.weapon=mp5;
                        break;
                    case 3:
                        player.weapon=glock18;
                        break;
                    default:
                        player.weapon=knife;
                }
        }
    }
    exit:
}
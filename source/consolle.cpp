#include <SDL2/SDL.h>
#include <iostream>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"



// to use the consolle remove WIN32 from the CmakeLists and always use exit to stop consolle execution

void consolle(bool &no_clip,SDL_Rect &camera,SDL_Renderer* renderer){
    using std::cin, std::string, std::cout;

    string comand;
    int value;
    bool loop=true;
    
    while(loop){
        
        cout<<"comands:\nplayer_money (value)\nplayer_health (value)\nplayer_speed (value)\ngun_ammo (value)\nexit\nplayer_weapon (value)\ngun_damage\nfire_rate\nno_clip\nammo_left (value)\nrestart\nopen\ncoord\ncutters\ntp (x y)\n\n";
        cin>>comand;
        if(comand=="exit") loop=0;
        else if(comand=="gun_damage") cout<<player.WeaponInHand.damage<<"\n\n";
        else if (comand=="fire_rate") cout<<player.WeaponInHand.fire_rate<<"\n\n";
        else if(comand=="restart") game::restart(camera);
        else if(comand=="open") game::open_fence();
        else if(comand=="coord") cout<<player.x<<";"<<player.y<<"\n\n";
        else if(comand=="cutters")player.has_cutters=1;
        else if (comand=="no_clip"){
            if(!no_clip) no_clip=true;
            else no_clip=false;
        }
        else if (comand!="player_money"&&comand!="player_health"&&comand!="player_speed"&&comand!="gun_ammo"&&comand!="player_money"&&comand!="player_weapon"&&comand!="ammo_left"&&comand!="tp")cout<<"syntax error\n\n";
        else if(comand!="tp"){
        
            cin>>value;
            if(comand=="player_money") player.money=value;
            else if(comand=="player_health") player.health=value;
            else if(comand=="player_speed") player.speed=value;
            else if(comand=="gun_ammo") player.WeaponInHand.ammo=value;
            else if(comand=="ammo_left") player.WeaponInHand.ammo_left=value;
            else if (comand=="player_weapon")
                switch (value){
                    case 1:
                        player.WeaponInHand=ak47;
                        break;
                    case 2:
                        player.WeaponInHand=mp5;
                        break;
                    case 3:
                        player.WeaponInHand=glock18;
                        break;
                    case 4:
                        player.WeaponInHand=knife;
                        break;
                    default:
                        cout<<"non existent weapon\n\n";
                        break;
                }
        }
        else{
            cin>>player.x;
            cin>>player.y;
            camera.x=player.x*101;
            camera.y=player.y*101;
        }
    }
}
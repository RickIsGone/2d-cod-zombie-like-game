#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../hpp files/all.hpp"


gun ak47={"ak47",35,30,30,240,150};
gun mp5={"mp5",25,25,25,200,100};
gun knife{"knife",85,1,1,1,200};
gun glock18{"glock18",20,20,20,160,0};
players player={150,150,4,glock18,knife,0};

void start_game(void){

    game_round.round_number=1;
    game_round.zombie_number=10;

    spawn_zombie();
}

static Uint32 s_RoundWon = 0;
static const Uint32 s_ZombieDelay = 10000;

void won_round(void){
    game_round.round_number++;
    game_round.zombie_number+=2;
    
    s_RoundWon=SDL_GetTicks();
    if(s_RoundWon!=0 && SDL_GetTicks()-s_RoundWon>=s_ZombieDelay) spawn_zombie();
    
}
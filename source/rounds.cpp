#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../hpp files/all.hpp"


void spawn_zombie(){
    // spawn degli zombie
    
}

gun ak47={"ak47",35,30,30,150};
gun mp5={"mp5",25,25,25,100};
gun knife{"knife",85,1,1,200};
gun glock18{"glock18",20,20,20,0};
players player={150,10,glock18,0};

void start_game(void){

    game_round.round_number=1;
    game_round.zombie_number=10;

    spawn_zombie();
}

Uint32 RoundWon = 0;
const Uint32 ZombieDelay = 10000;

void won_round(void){
    game_round.round_number++;
    game_round.zombie_number+=2;
    
    RoundWon=SDL_GetTicks();
    if(RoundWon!=0&&SDL_GetTicks()-RoundWon>=ZombieDelay) spawn_zombie();
    
}
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../hpp files/all.hpp"


void spawn_zombie(){
    // spawn degli zombie
    
}

void start_game(void){

    gun ak47={"ak47",35,30,30,0.35f};
    gun mp5={"mp5",25,25,25,0.2f};
    gun knife{"knife",85,1,1,0.7f};
    gun glock18{"glock18",20,20,20,0.3f};
    player={150,10,ak47,0};

    game_round.round_number=1;
    game_round.zombie_number=10;

    spawn_zombie();
}

void won_round(void){
    game_round.round_number++;
    game_round.zombie_number+=2;
    
    //after(10)
        spawn_zombie();
}
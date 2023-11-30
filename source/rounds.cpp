#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


gun ak47={"ak47",35,30,30,240,150};
gun mp5={"mp5",25,25,25,200,100};
gun knife{"knife",85,1,1,1,200};
gun glock18{"glock18",20,20,20,160,0};
players player={37,14,150,150,4,glock18,knife,0,0};     // hitbox initialization in texturensoundinitialization.cpp
MouseState mouseState = {0, 0, false, false};
rounds game_round;

void game::start(){

    game_round.round_number=1;
    game_round.zombie_number=10; 
    game_round.zombie_health=80;
    game_round.zombie_damage=1;
    game_round.zombie_speed=3;
    
    game::spawn_zombie();
}

static Uint32 s_RoundWon = 0;
static const Uint32 s_ZombieDelay = 10000;

void game::won_round(){
    s_RoundWon=SDL_GetTicks();
    if(s_RoundWon!=0 && SDL_GetTicks()-s_RoundWon>=s_ZombieDelay){
        game_round.round_number++;
        game_round.zombie_number+=2;
        game_round.zombie_health+=0,2;
        game_round.zombie_damage++;
        game::spawn_zombie();
        s_RoundWon=0;
    }
    
}

void game::restart(SDL_Rect &camera){
    
    camera={3737,1414,1920,1080};     
    mouseState = {0, 0, false, false};
    player={37,14,150,150,4,glock18,knife,0,0};
    game_map=   "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "oooooooo*******************************************************************************a*****************oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                 *****      *                          *        *                              *oooooooo\n"
                "oooooooo*                 *   *      ****************      ******        *                              *oooooooo\n"
                "oooooooo*                 g   *                     *      *             *                              *oooooooo\n"
                "oooooooo*                 *   *                     *      *             *                              *oooooooo\n"                  
                "oooooooo*                 *   *                     *      *             **********     *****************oooooooo\n"
                "oooooooo*************     *   ***********           *      *                                            *oooooooo\n"
                "oooooooo*                               *           *      *                                            *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                                                  *         *******     *************          *oooooooo\n"
                "oooooooo*                                                  *                                 *          *oooooooo\n"
                "oooooooo*                                                  *                                 *          *oooooooo\n"
                "oooooooo*      ******************       *           *      *                                 *          *oooooooo\n"
                "oooooooo*                               *           *      *         *                                  *oooooooo\n"
                "oooooooo*                               *           *      *         *                                  *oooooooo\n"
                "oooooooow                               *           *      *         *                                  *oooooooo\n"
                "oooooooo*                       *       ****     ****      *         ***************m*********          *oooooooo\n"
                "oooooooo*                       *                                                                       *********\n"
                "oooooooo*                       *                                                                       l        \n"
                "oooooooo*                       *                                                                       r        \n"
                "oooooooo*********************************************************************************************************\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";


    player.Hitbox.x = player.x-20;
    player.Hitbox.y = player.y-20;
    player.Hitbox.w = 80; 
    player.Hitbox.h = 80;

    game_round.round_number=1;
    game_round.zombie_number=10; 
    game_round.zombie_health=80;
    game_round.zombie_damage=1;
    game_round.zombie_speed=3;

    hitboxes.clear();

    int x = 0;
    int y = 0;

    for (char tile : game_map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

        if (tile != ' '&& tile!='o') {
            SDL_Rect wall;
            wall.x = (x-9)*101; 
            wall.y = (y-5)*101;
            wall.w = 101;
            wall.h = 101;
            hitboxes.push_back(wall);
        }

        x++;
    }


}

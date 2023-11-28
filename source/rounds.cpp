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
    game_round.zombie_number=1; //10
    
    game::spawn_zombie();
}

static Uint32 s_RoundWon = 0;
static const Uint32 s_ZombieDelay = 10000;

void game::won_round(){
    game_round.round_number++;
    game_round.zombie_number+=2;
    game_round.zombie_health+=0,2;
    game_round.zombie_damage++;
    
    s_RoundWon=SDL_GetTicks();
    if(s_RoundWon!=0 && SDL_GetTicks()-s_RoundWon>=s_ZombieDelay) game::spawn_zombie();
    
}

void game::restart(SDL_Rect &camera){
    
    camera={505,303,1920,1080};     
    mouseState = {0, 0, false, false};
    player={15,9,150,150,4,glock18,knife,0,0};
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
            SDL_Rect newHitbox;
            newHitbox.x = (x-9)*101; 
            newHitbox.y = (y-5)*101;
            newHitbox.w = 101;
            newHitbox.h = 101;
            hitboxes.push_back(newHitbox);
        }

        x++;
    }


    game::start();
}

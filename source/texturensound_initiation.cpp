#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"
#include <vector>

Mix_Chunk *step,*ak47_fire,*mp5_fire,*glock18_fire,*knife_swoosh,*reload,*empty_mag;
SDL_Texture* wall_texture,*ground_texture,*outside_texture,*glock18_outline_texture,*ak_outline_texture,*mp5_outline_texture,*zombie_texture,*left_fence_texture,*right_fence_texture,*w_cutters_texture;
std::string game_map;
TTF_Font* font_f;
SDL_Rect playerHitbox;
    

std::vector<SDL_Rect> hitboxes;
std::vector<zombies> zombie_alive;
std::vector<bullets> bullets_alive;

void game::texturensound_initiation(SDL_Renderer* renderer){
    step = Mix_LoadWAV("../texture/step.wav");
    ak47_fire = Mix_LoadWAV("../texture/ak47_fire.wav");
    mp5_fire= Mix_LoadWAV("../texture/mp5_fire.wav");
    glock18_fire= Mix_LoadWAV("../texture/glock18_fire.wav");
    knife_swoosh=Mix_LoadWAV("../texture/knife_swoosh.wav");
    reload= Mix_LoadWAV("../texture/reload.wav");
    empty_mag= Mix_LoadWAV("../texture/empty_mag.wav");

    wall_texture = IMG_LoadTexture(renderer, "../texture/wall.png");
    ground_texture = IMG_LoadTexture(renderer, "../texture/ground.png");
    outside_texture=IMG_LoadTexture(renderer,"../texture/outside.png");
    glock18_outline_texture=IMG_LoadTexture(renderer,"../texture/glock18_outline.png");
    ak_outline_texture=IMG_LoadTexture(renderer,"../texture/ak_outline.png");
    mp5_outline_texture=IMG_LoadTexture(renderer,"../texture/mp5_outline.png");
    zombie_texture=IMG_LoadTexture(renderer,"../texture/zombie.png");
    left_fence_texture=IMG_LoadTexture(renderer,"../texture/l_fence.png");
    right_fence_texture=IMG_LoadTexture(renderer,"../texture/r_fence.png");
    w_cutters_texture=IMG_LoadTexture(renderer,"../texture/w_cutters.png");
    
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

    playerHitbox.x = player.x-20;
    playerHitbox.y = player.y-20;
    playerHitbox.w = 80; 
    playerHitbox.h = 80;

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
} 

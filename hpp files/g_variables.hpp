#ifndef G_VARIABLES
#define G_VARIABLES

#include <iostream>

enum GameState{
    RUNNING=2,
    PAUSED=4,
    RESTART=0,
    CLOSED=7
};

bool start;
const std::string game_map;

Mix_Chunk *step,*ak47_fire,*mp5_fire,*glock18_fire,*reload,*empty_mag;
SDL_Texture* wall_texture,*ground_texture,*outside_texture,*glock18_outline_texture,*ak_outline_texture,*mp5_outline_texture,*zombie_texture;

#endif

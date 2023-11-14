#ifndef G_VARIABLES_HPP
#define G_VARIABLES_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


enum GameState{
    RUNNING=2,
    PAUSED=4,
    RESTART=0,
    CLOSED=7
};

extern bool start;
extern int game_state;

extern Mix_Chunk *step,*ak47_fire,*mp5_fire,*glock18_fire,*reload,*empty_mag;
extern SDL_Texture* wall_texture,*ground_texture,*outside_texture,*glock18_outline_texture,*ak_outline_texture,*mp5_outline_texture,*zombie_texture,*left_fence_texture,*right_fence_texture;

extern std::string game_map;

#endif

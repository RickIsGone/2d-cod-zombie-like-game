#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

void interactions(){
    // fence
    if((player.x==94&&player.y==22)||(player.x==94&&player.y==23)) game::open_fence(); // aggiungere controllo delle tronchesi finita fase test 
}
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"
#include <vector>
#include <utility>

bool game::hitbox::w(SDL_Rect camera){
    for (const auto& coord : hitboxes) if (coord.first == camera.x && coord.second == camera.y-player.speed){
        std::cout<<"hit";
         return false;
    }
    return true; 
}

bool game::hitbox::a(SDL_Rect camera){
    for (const auto& coord : hitboxes) if (coord.first == camera.x-player.speed && coord.second == camera.y) return false;
    return true;    
}

bool game::hitbox::s(SDL_Rect camera){
    for (const auto& coord : hitboxes) if (coord.first == camera.x && coord.second == camera.y+player.speed) return false;
    return true;  
}

bool game::hitbox::d(SDL_Rect camera){
    for (const auto& coord : hitboxes) if (coord.first == camera.x+player.speed && coord.second == camera.y) return false;
    return true;    
}
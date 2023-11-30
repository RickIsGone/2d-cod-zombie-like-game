#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"
#include <vector>

bool game::hitbox::w(SDL_Rect camera){
    for (const SDL_Rect& hitbox : hitboxes) {
        SDL_Rect screenHitbox = hitbox;
        screenHitbox.x -= camera.x;
        screenHitbox.y -= camera.y-player.speed*deltaTime;
        if (SDL_HasIntersection(&player.Hitbox, &screenHitbox)) return false;
    }
    return true;
}

bool game::hitbox::a(SDL_Rect camera){
    for (const SDL_Rect& hitbox : hitboxes) {
        SDL_Rect screenHitbox = hitbox;
        screenHitbox.x -= camera.x-player.speed*deltaTime;
        screenHitbox.y -= camera.y;
        if (SDL_HasIntersection(&player.Hitbox, &screenHitbox)) return false;
    }
    return true;
}

bool game::hitbox::s(SDL_Rect camera){
    for (const SDL_Rect& hitbox : hitboxes) {
        SDL_Rect screenHitbox = hitbox;
        screenHitbox.x -= camera.x;
        screenHitbox.y -= camera.y+player.speed*deltaTime;
        if (SDL_HasIntersection(&player.Hitbox, &screenHitbox)) return false;
    }
    return true;
}

bool game::hitbox::d(SDL_Rect camera){
    for (const SDL_Rect& hitbox : hitboxes) {
        SDL_Rect screenHitbox = hitbox;
        screenHitbox.x -= camera.x+player.speed*deltaTime;
        screenHitbox.y -= camera.y;
        if (SDL_HasIntersection(&player.Hitbox, &screenHitbox)) return false;
    }
    return true;
}
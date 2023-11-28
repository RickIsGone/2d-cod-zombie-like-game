#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

struct MouseState {
    int x, y; 
    bool leftButton, rightButton; 

    MouseState(int x, int y, bool leftButton, bool rightButton) 
        : x(x), y(y), leftButton(leftButton), rightButton(rightButton) {}
};


struct gun {
    std::string name;
    int damage;
    int ammo;
    int ammo_max;
    int ammo_left;
    int fire_rate;
    void shoot(bool automatic);
    
};

struct bullets{
    int damage;
    int speed;
    int x;
    int y;
    SDL_Rect Hitbox;
};

struct players {
    int x;
    int y;
    int health;
    int health_max;
    float speed;
    gun WeaponInHand;
    gun WeaponInInventory;
    int money;
    bool has_cutters;
    SDL_Rect Hitbox;
};

struct zombies{
    int x;
    int y;
    float health;
    int speed;
    float damage;
    SDL_Rect Hitbox;
};

struct rounds {
    int round_number;
    int zombie_number;
    int zombie_left;
    float zombie_health;
    int zombie_speed;
    float zombie_damage;
};

extern gun ak47;
extern gun mp5;
extern gun knife;
extern gun glock18;


extern rounds game_round;
extern players player;
extern MouseState mouseState;

#endif

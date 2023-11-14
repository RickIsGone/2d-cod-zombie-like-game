#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

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
};

struct rounds {
    int round_number;
    int zombie_number;
    int zombie_left;
};

extern gun ak47;
extern gun mp5;
extern gun knife;
extern gun glock18;


extern rounds game_round;
extern players player;
extern MouseState mouseState;

#endif

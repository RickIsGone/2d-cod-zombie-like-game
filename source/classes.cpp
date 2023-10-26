#include <iostream>

struct MouseState {
    int x, y; 
    bool leftButton; 

    MouseState(int x, int y, bool leftButton) 
        : x(x), y(y), leftButton(leftButton) {}

};

struct gun{
    int damage;
    int ammo;
    float fire_rate;

};

struct players{
    float health;
    float speed;
    gun weapon;

};

struct zombies{
    float health;
    float speed;
    float damage;

    zombies(float health, float speed,float damage){
        this->health=health;
        this->speed=speed;
        this->damage=damage;
    }
};

struct rounds{
    int round_number;
    int zombie_number;
    int zombie_left;

};


rounds game_round;
players player;





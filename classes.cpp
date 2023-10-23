#include <iostream>



struct player{
    float health;
    float speed;
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

struct gun{
    int damage;
    int ammo;
};

void boh(void){
    player player;
    rounds round;
    
    
    player.health=150;
    player.speed=10;
    

}
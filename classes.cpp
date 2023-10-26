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

void spawn_zombie(){
    // spawn degli zombie
    std::cout<<game_round.zombie_number;

}

void start_game(void){

    gun ak={35,30,0.3f};
    gun mp5={25,25,0.1f};
    gun knife{85,1,0.7f};

    player={150,10,ak};

    game_round.round_number=1;
    game_round.zombie_number=10;

    spawn_zombie();
}

void won_round(void){
    game_round.round_number++;
    game_round.zombie_number+=3;
    
    //after(10)
        spawn_zombie();
}



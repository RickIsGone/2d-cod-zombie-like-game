#include <string>

#ifndef ALL_HPP
#define ALL_HPP

struct MouseState {
    int x, y; // Posizione del mouse
    bool leftButton, rightButton; // Stato dei pulsanti del mouse

    MouseState(int x, int y, bool leftButton, bool rightButton) 
        : x(x), y(y), leftButton(leftButton), rightButton(rightButton) {}
};


struct gun {
    std::string name;
    int damage;
    int ammo;
    float fire_rate;
};

struct players {
    float health;
    float speed;
    gun weapon;
    int money;
};

struct rounds {
    int round_number;
    int zombie_number;
    int zombie_left;
};

extern gun ak;
extern gun mp5;
extern gun knife;

extern rounds game_round;
extern players player;
#endif // ALL_HPP

void start_game();
void won_round();
void spawn_zombie();

void map(SDL_Renderer* renderer,const SDL_Rect &camera);

void input_events(SDL_Event event, bool &game_state,SDL_Rect &camera, MouseState &mouseState);
void niga(SDL_Renderer* renderer,MouseState mouseState);
void mouse(SDL_Renderer* renderer,MouseState mouseState);


#include <string>

#ifndef ALL_HPP
#define ALL_HPP

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
    int fire_rate;
    static void shoot(){

    };
};

struct players {
    int health;
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
void mnk_events(SDL_Rect &camera, MouseState &mouseState,std::string &game_state,SDL_Event event,SDL_Renderer* renderer);
void events(SDL_Event event, std::string &game_state);
void niga(SDL_Renderer* renderer,MouseState mouseState);
void mouse(SDL_Renderer* renderer,MouseState mouseState);

void menu(SDL_Renderer* renderer);
void pause(std::string &game_state,SDL_Event event);

void round_display(SDL_Renderer* renderer,SDL_Rect camera);
void ammo_display(SDL_Renderer* renderer,SDL_Rect camera);
void health_display(SDL_Renderer* renderer,SDL_Rect camera);
void hud_display(SDL_Renderer* renderer,SDL_Rect camera);

void shoot();
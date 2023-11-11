#include <string>
#include <SDL2/SDL_mixer.h>

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
    int ammo_left;
    int fire_rate;
    void shoot(bool automatic);
    
        gun(std::string name,int damage,int ammo,int ammo_max, int ammo_left,int fire_rate){
            this->name=name;
            this->damage=damage;
            this->ammo=ammo;
            this->ammo_max=ammo_max;
            this->ammo_left=ammo_left;
            this->fire_rate=fire_rate;
        }
};

struct players {
    int health;
    int health_max;
    float speed;
    gun WeaponInHand;
    gun WeaponInInventory;
    int money;
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
#endif // ALL_HPP

enum GameState{
    RUNNING=2,
    PAUSED=4,
    RESTART=0,
    CLOSED=7
};

void start_game();
void won_round();
void spawn_zombie();
void texturensound_initiation(SDL_Renderer* renderer);
void death(int &game_state,SDL_Rect &camera,MouseState &mouseState);

void map(SDL_Renderer* renderer,const SDL_Rect &camera);
void mnk_events(SDL_Rect &camera, MouseState &mouseState, int &game_state,SDL_Event event,SDL_Renderer* renderer,bool &no_clip);
void events(SDL_Event event, int &game_state);
void niga(SDL_Renderer* renderer,MouseState mouseState);
void mouse(SDL_Renderer* renderer,MouseState mouseState);

void menu(SDL_Renderer* renderer);
void pause(int &game_state,SDL_Event event);
void pause_menu(SDL_Rect &camera, int &game_state,SDL_Event event,SDL_Renderer* renderer);

void round_display(SDL_Renderer* renderer,SDL_Rect camera);
void ammo_display(SDL_Renderer* renderer,SDL_Rect camera);
void health_display(SDL_Renderer* renderer,SDL_Rect camera);
void money_display(SDL_Renderer* renderer,SDL_Rect camera);
void health_check();
void hud_display(SDL_Renderer* renderer,SDL_Rect camera);
void death_menu(SDL_Renderer* renderer);

void consolle(bool &no_clip,SDL_Rect &camera,SDL_Renderer* renderer,MouseState mouseState,int &game_state);
void consolle_events(SDL_Event consolle_events, bool &consolle_state);
void death_events(SDL_Event event,int &game_state);

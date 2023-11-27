#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
namespace game{
    void start();
    void won_round();
    void spawn_zombie();
    void texturensound_initiation(SDL_Renderer* renderer);
    void win_death(SDL_Event event,SDL_Renderer*renderer,SDL_Rect &camera);
    void restart(SDL_Rect &camera);
    void health_check();
    void open_fence();
    
    namespace save{
        void saveTopRound();
        int loadTopRound();
        void saveGame();
        bool loadGame();
    }

    namespace hitbox{
        bool w(SDL_Rect camera);
        bool a(SDL_Rect camera);
        bool s(SDL_Rect camera);
        bool d(SDL_Rect camera);
    }
}

namespace sdl{
    void quick_text(std::string writing,int size, Uint8 r,Uint8 g,Uint8 b,int y,SDL_Renderer* renderer);
    void v_quick_text(std::string writing,int var,int size, Uint8 r,Uint8 g,Uint8 b,int y,SDL_Renderer* renderer);
    void button(std::string text,int size, int x,int y,int width, int height,Uint8 r,Uint8 g,Uint8 b,SDL_Renderer* renderer,int value);
    void load_button(std::string text,int size, int x,int y,int width, int height,Uint8 r,Uint8 g,Uint8 b,SDL_Renderer* renderer,SDL_Rect &camera,bool (*function)(),int value);
    void save_button(std::string text,int size, int x,int y,int width, int height,Uint8 r,Uint8 g,Uint8 b,SDL_Renderer* renderer,void (*function)(),int value);
}



void map(SDL_Renderer* renderer,const SDL_Rect &camera);
void mnk_events(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer,bool &no_clip);
void interactions(SDL_Renderer* renderer);
void events(SDL_Event event);
void niga(SDL_Renderer* renderer);
void mouse(SDL_Renderer* renderer);
void mouse_update();

void menu(SDL_Renderer* renderer,SDL_Rect &camera);
void pause_menu(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer);
void win_death_menu(SDL_Renderer*renderer,SDL_Rect camera);

void round_display(SDL_Renderer* renderer,SDL_Rect camera);
void ammo_display(SDL_Renderer* renderer,SDL_Rect camera);
void health_display(SDL_Renderer* renderer,SDL_Rect camera);
void money_display(SDL_Renderer* renderer,SDL_Rect camera);
void hud_display(SDL_Renderer* renderer,SDL_Rect camera);

void consolle(bool &no_clip,SDL_Rect &camera,SDL_Renderer* renderer);
void consolle_events(SDL_Event consolle_events, bool &consolle_state);

#endif

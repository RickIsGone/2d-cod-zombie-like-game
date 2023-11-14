#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace game{
    void start();
    void won_round();
    void spawn_zombie();
    void texturensound_initiation(SDL_Renderer* renderer);
    void restart(SDL_Rect &camera);
    void health_check();
    void open_fence();
    void death(SDL_Event event,SDL_Renderer*renderer,SDL_Rect &camera);
    void win(SDL_Event event,SDL_Renderer*renderer,SDL_Rect &camera);
}

void map(SDL_Renderer* renderer,const SDL_Rect &camera);
void mnk_events(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer,bool &no_clip);
void interactions();
void events(SDL_Event event);
void niga(SDL_Renderer* renderer);
void mouse(SDL_Renderer* renderer);

void menu(SDL_Renderer* renderer);
void pause(SDL_Event event);
void pause_menu(SDL_Rect &camera,SDL_Event event,SDL_Renderer* renderer);
void death_menu(SDL_Renderer* renderer);
void win_menu(SDL_Renderer*renderer);

void round_display(SDL_Renderer* renderer,SDL_Rect camera);
void ammo_display(SDL_Renderer* renderer,SDL_Rect camera);
void health_display(SDL_Renderer* renderer,SDL_Rect camera);
void money_display(SDL_Renderer* renderer,SDL_Rect camera);
void hud_display(SDL_Renderer* renderer,SDL_Rect camera);

void consolle(bool &no_clip,SDL_Rect &camera,SDL_Renderer* renderer);
void consolle_events(SDL_Event consolle_events, bool &consolle_state);
void death_events(SDL_Event event);

#endif

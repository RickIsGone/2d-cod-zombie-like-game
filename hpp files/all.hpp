void map(SDL_Renderer* renderer,const SDL_Rect &camera);

void input_events(SDL_Event event, bool &game_state,SDL_Rect &camera);

#ifndef ALL_HPP
#define ALL_HPP

struct MouseState {
    int x, y; // Posizione del mouse
    bool leftButton, rightButton; // Stato dei pulsanti del mouse

    MouseState(int x, int y, bool leftButton, bool rightButton) 
        : x(x), y(y), leftButton(leftButton), rightButton(rightButton) {}
};

#endif // ALL_HPP
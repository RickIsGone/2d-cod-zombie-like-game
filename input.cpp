#include <SDL.h>
#include <SDL_image.h>

void input_event(SDL_Event event, bool &game_state){
    switch(event.type){  
        case SDL_QUIT:
            game_state=false;
            break;
            
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w:
                    
                    break;
                case SDLK_a:

                    break;
                case SDLK_s:

                    break;
                case SDLK_d:

                    break;
                case SDLK_r:

                    break;
            }

        case SDL_MOUSEBUTTONDOWN:
            switch(event.button.button){
                case SDL_BUTTON_LEFT:

                    break;
                case SDL_BUTTON_RIGHT:
                        
                    break;
            }
    }
}
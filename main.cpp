#include <iostream>
#include <SDL2/SDL.h>


const int WIDTH=1920, HEIGHT=1080;

int main (int argc, char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window=SDL_CreateWindow("2d cod zombie",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL==window){
        std::cout<<"error"<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }

    SDL_Event WindowEvent;
    
    while (true){
        if (SDL_PollEvent(&WindowEvent))
            if (SDL_QUIT==WindowEvent.type)
                break;
        // codice da scrivere 
        
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
#include <sdl2/sdl.h>
#include <iostream>

const int WIDTH=1920, HEIGHT=1080;

int main (int argc, char *argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window=SDL_CreateWindow("hello world",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL==window){
        std::cout<<"error";
        return EXIT_FAILURE;
    }

    SDL_Event WindowEvent;
    
    while (true){
        if (SDL_PollEvent(&WindowEvent))
            if (SDL_QUIT==WindowEvent.type)
                break;
        
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
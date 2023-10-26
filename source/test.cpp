#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <cassert>
#include <iostream>
#include "../hpp files/all.hpp"

int main() {
    // Creare un oggetto camera
    SDL_Rect camera = {0, 0, 800, 600};

    // Muovere la camera
    camera.x += 10;

    // Verificare che la camera si sia mossa
    assert(camera.x == 10);

    // Stampare un messaggio se il test passa
    std::cout << "Test passed!\n";

    return 0;
}
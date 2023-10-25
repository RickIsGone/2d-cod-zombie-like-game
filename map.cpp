#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

void map(SDL_Renderer* renderer){
    string map= "*************************************************************************************************\n"
                "*                            *                                                                  *\n"
                "*                            *                                                                  *\n"
                "*                            *                                                                  *\n"
                "*                 *****      *                          *        *                              *\n"
                "*                 *   *      ****************      ******        *                              *\n"
                "*                 *   *                     *      *             *                              *\n"
                "*                 *   *                     *      *             *                              *\n"                  
                "*                 *   *                     *      *             *********        ***************\n"
                "************      *   ***********           *      *                                            *\n"
                "*                               *           *                                                   *\n"
                "*                               *           *                                                   *\n"
                "*                               *           *                                                   *\n"
                "*                               *           *                                                   *\n"
                "*                                                  *         *****         ***********          *\n"
                "*                                                  *                                 *          *\n"
                "*                                                  *                                 *          *\n"
                "*      ******************       *           *      *                                 *          *\n"
                "*                               *           *      *         *                       *          *\n"
                "*                               *           *      *         *                                  *\n"
                "*                               *           *      *         *                                  *\n"
                "*                       *       ***       ***      *         *************************          *\n"
                "*                       *                                                                       *\n"
                "*                       *                                                                       *\n"
                "*                       *                                                                       *\n"
                "*************************************************************************************************\n";



    SDL_Texture* wall_texture = IMG_LoadTexture(renderer, "texture/wall.png");
    SDL_Texture* ground_texture = IMG_LoadTexture(renderer, "texture/ground.png");
    
    
    int dimensione = 64; // dimensione di ogni tile in pixel
    int x = 0;
    int y = 0;

    for (char tile : map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

        SDL_Rect destRect = { x * dimensione, y * dimensione, dimensione, dimensione };
        switch(tile){
            case '*':
                SDL_RenderCopy(renderer, wall_texture, NULL, &destRect);
                break;
            case ' ':
                SDL_RenderCopy(renderer, ground_texture, NULL, &destRect);
                break;
        }

        x++;
    }
    SDL_RenderPresent(renderer);
}
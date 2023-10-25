#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "hpp files/all.hpp"
using namespace std;

void map(SDL_Renderer* renderer,const SDL_Rect &camera,MouseState mouseState){
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
                "*                               *           *      *                                            *\n"
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
    SDL_Surface* cursorSurface = IMG_Load("texture/mouse.png");
    int hot_x = cursorSurface->w / 2;
    int hot_y = cursorSurface->h / 2;
    SDL_Cursor* cursor = SDL_CreateColorCursor(cursorSurface, hot_x, hot_y);
    SDL_SetCursor(cursor);
    
    int dimensione = 64; // dimensione di ogni tile in pixel

    int startTileX = camera.x / dimensione;
    int startTileY = camera.y / dimensione;
    int endTileX = (camera.x + camera.w) / dimensione;
    int endTileY = (camera.y + camera.h) / dimensione;

    int x = 0;
    int y = 0;

    for (char tile : map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

        if (x >= startTileX && x <= endTileX && y >= startTileY && y <= endTileY) {
            SDL_Rect destRect = { x * dimensione - camera.x, y * dimensione - camera.y, dimensione, dimensione };
            switch(tile){
                case '*':
                    SDL_RenderCopy(renderer, wall_texture, NULL, &destRect);
                    break;
                case ' ':
                    SDL_RenderCopy(renderer, ground_texture, NULL, &destRect);
                    break;
            }
        }

        x++;
    }
    SDL_Rect destrect = { mouseState.x - 64 / 2, mouseState.y - 32 / 2, 64, 32 };
    SDL_RenderPresent(renderer);
    
    SDL_DestroyTexture(wall_texture);
    SDL_DestroyTexture(ground_texture);
    

}
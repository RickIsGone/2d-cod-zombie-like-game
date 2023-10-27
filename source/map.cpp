#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../hpp files/all.hpp"
using namespace std;

void map(SDL_Renderer* renderer,const SDL_Rect &camera){
    string map= "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "oooooooo*************************************************************************************************oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                            *                                                                  *oooooooo\n"
                "oooooooo*                 *****      *                          *        *                              *oooooooo\n"
                "oooooooo*                 *   *      ****************      ******        *                              *oooooooo\n"
                "oooooooo*                 *   *                     *      *             *                              *oooooooo\n"
                "oooooooo*                 *   *                     *      *             *                              *oooooooo\n"                  
                "oooooooo*                 *   *                     *      *             **********     *****************oooooooo\n"
                "oooooooo*************     *   ***********           *      *                                            *oooooooo\n"
                "oooooooo*                               *           *      *                                            *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                               *           *                                                   *oooooooo\n"
                "oooooooo*                                                  *         *******     *************          *oooooooo\n"
                "oooooooo*                                                  *                                 *          *oooooooo\n"
                "oooooooo*                                                  *                                 *          *oooooooo\n"
                "oooooooo*      ******************       *           *      *                                 *          *oooooooo\n"
                "oooooooo*                               *           *      *         *                                  *oooooooo\n"
                "oooooooo*                               *           *      *         *                                  *oooooooo\n"
                "oooooooo*                               *           *      *         *                                  *oooooooo\n"
                "oooooooo*                       *       ****     ****      *         *************************          *oooooooo\n"
                "oooooooo*                       *                                                                       *oooooooo\n"
                "oooooooo*                       *                                                                       *oooooooo\n"
                "oooooooo*                       *                                                                       *oooooooo\n"
                "oooooooo*************************************************************************************************oooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";



    SDL_Texture* wall_texture = IMG_LoadTexture(renderer, "../texture/wall.png");
    SDL_Texture* ground_texture = IMG_LoadTexture(renderer, "../texture/ground.png");
    SDL_Texture* outside_texture=IMG_LoadTexture(renderer,"../texture/outside.png");
    
    int dimensione = 101; // dimensione di ogni tile in pixel

    int startTileX = camera.x / dimensione;
    int startTileY = camera.y / dimensione;
    int endTileX = (camera.x + camera.w) / dimensione;
    int endTileY = (camera.y + camera.h) / dimensione;

    int x = 0;
    int y = 0;

    SDL_RenderClear(renderer);
    
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
                case 'o':
                    SDL_RenderCopy(renderer,outside_texture,NULL,&destRect);
                    break;
            }
        }

        x++;
    }
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(wall_texture);
    SDL_DestroyTexture(ground_texture);
    SDL_DestroyTexture(outside_texture);

}
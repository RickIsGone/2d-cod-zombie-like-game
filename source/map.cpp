#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp files/all.hpp"
using namespace std;

const string game_map=  "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "oooooooo*******************************************************************************a*****************oooooooo\n"
                        "oooooooo*                            *                                                                  *oooooooo\n"
                        "oooooooo*                            *                                                                  *oooooooo\n"
                        "oooooooo*                            *                                                                  *oooooooo\n"
                        "oooooooo*                 *****      *                          *        *                              *oooooooo\n"
                        "oooooooo*                 *   *      ****************      ******        *                              *oooooooo\n"
                        "oooooooo*                 g   *                     *      *             *                              *oooooooo\n"
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
                        "oooooooo*                       *       ****     ****      *         ***************m*********          *oooooooo\n"
                        "oooooooo*                       *                                                                       *oooooooo\n"
                        "oooooooo*                       *                                                                       *oooooooo\n"
                        "oooooooo*                       *                                                                       *oooooooo\n"
                        "oooooooo*************************************************************************************************oooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";



void map(SDL_Renderer* renderer,const SDL_Rect &camera){

    SDL_Texture* wall_texture = IMG_LoadTexture(renderer, "../texture/wall.png");
    SDL_Texture* ground_texture = IMG_LoadTexture(renderer, "../texture/ground.png");
    SDL_Texture* outside_texture=IMG_LoadTexture(renderer,"../texture/outside.png");
    SDL_Texture* glock18_outline_texture=IMG_LoadTexture(renderer,"../texture/glock18_outline.png");
    SDL_Texture* ak_outline_texture=IMG_LoadTexture(renderer,"../texture/ak_outline.png");
    SDL_Texture* mp5_outline_texture=IMG_LoadTexture(renderer,"../texture/mp5_outline.jpg");
    
    int dimensione = 101; // dimensione di ogni tile in pixel

    int x = 0;
    int y = 0;

    SDL_RenderClear(renderer);
    
    for (char tile : game_map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

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
            case 'a':
                SDL_RenderCopy(renderer,ak_outline_texture,NULL,&destRect);
                break;
            case 'm':
                SDL_RenderCopy(renderer,mp5_outline_texture,NULL,&destRect);
                break;
            case 'g':
                SDL_RenderCopy(renderer,glock18_outline_texture,NULL,&destRect);
                break;
        }
        x++;
    }

    

    SDL_DestroyTexture(wall_texture);
    SDL_DestroyTexture(ground_texture);
    SDL_DestroyTexture(outside_texture);
    SDL_DestroyTexture(ak_outline_texture);
    SDL_DestroyTexture(glock18_outline_texture);
    SDL_DestroyTexture(mp5_outline_texture);

}
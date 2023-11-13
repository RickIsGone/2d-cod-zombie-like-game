#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"
using namespace std;

string game_map=        "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
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

extern SDL_Texture * wall_texture,*ground_texture,*outside_texture,*glock18_outline_texture,*ak_outline_texture,*mp5_outline_texture;

void map(SDL_Renderer* renderer,const SDL_Rect &camera){
    
    int dimensione = 101; 

    int x = 0;
    int y = 0;

    
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

    

    

}

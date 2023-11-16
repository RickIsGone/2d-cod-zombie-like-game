#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"


void map(SDL_Renderer* renderer,const SDL_Rect &camera){
    
    int block_size = 101; 

    int x = 0;
    int y = 0;

    
    for (char tile : game_map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

        SDL_Rect destRect = { x * block_size - camera.x, y * block_size - camera.y, block_size, block_size };
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
            case 'l':
                SDL_RenderCopy(renderer,left_fence_texture,NULL,&destRect);
                break;
            case 'r':
                SDL_RenderCopy(renderer,right_fence_texture,NULL,&destRect);
                break;
            case 'w':
                SDL_RenderCopy(renderer,w_cutters_texture,NULL,&destRect);
                break;
        }
        x++;
    }

}

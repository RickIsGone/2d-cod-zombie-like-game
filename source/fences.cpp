#include <SDL2/SDL.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"
#include <vector>

void game::open_fence(){
    game_map=   "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooo*******************************************************************************a*****************ooooooooo\n"
                "ooooooooo*                            *                                                                  *ooooooooo\n"
                "ooooooooo*                            *                                                                  *ooooooooo\n"
                "ooooooooo*                            *                                                                  *ooooooooo\n"
                "ooooooooo*                 *****      *                          *        *                              *ooooooooo\n"
                "ooooooooo*                 *   *      ****************      ******        *                              *ooooooooo\n"
                "ooooooooo*                 g   *                     *      *             *                              *ooooooooo\n"
                "ooooooooo*                 *   *                     *      *             *                              *ooooooooo\n"                  
                "ooooooooo*                 *   *                     *      *             **********     *****************ooooooooo\n"
                "ooooooooo*************     *   ***********           *      *                                            *ooooooooo\n"
                "ooooooooo*                               *           *      *                                            *ooooooooo\n"
                "ooooooooo*                               *           *                                                   *ooooooooo\n"
                "ooooooooo*                               *           *                                                   *ooooooooo\n"
                "ooooooooo*                               *           *                                                   *ooooooooo\n"
                "ooooooooo*                                                  *         *******     *************          *ooooooooo\n"
                "ooooooooo*                                                  *                                 *          *ooooooooo\n"
                "ooooooooo*                                                  *                                 *          *ooooooooo\n"
                "ooooooooo*      ******************       *           *      *                                 *          *ooooooooo\n"
                "ooooooooo*                               *           *      *         *                                  *ooooooooooooo\n"
                "ooooooooo*                               *           *      *         *                                  *ooooooooooooo\n"
                "ooooooooow                               *           *      *         *                                  *ooooooooooooo\n"
                "ooooooooo*                       *       ****     ****      *         ***************m*********          *ooooooooooooo\n"
                "ooooooooo*                       *                                                                       **************\n"
                "ooooooooo*                       *                                                                                     \n" 
                "ooooooooo*                       *                                                                                     \n"
                "ooooooooo**************************************************************************************************************\n"
                "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";
    

    hitboxes.clear();

    int x = 0;
    int y = 0;


    for (char tile : game_map) {
        if (tile == '\n') {
            y++;
            x = 0;
            continue;
        }

        if (tile != ' '&& tile!='o') {
            SDL_Rect wall;
            wall.x = x*101; 
            wall.y = y*101;
            wall.w = 101;
            wall.h = 101;
            hitboxes.push_back(wall);
        }

        x++;
    }
}
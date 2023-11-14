#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../hpp files/classes.hpp"
#include "../hpp files/functions.hpp"
#include "../hpp files/g_variables.hpp"

void game::open_fence(){
    game_map=   "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
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
                "oooooooo*                               *           *      *         *                                  *oooooooo********\n"
                "oooooooo*                       *       ****     ****      *         ***************m*********          *oooooooo*      *\n"
                "oooooooo*                       *                                                                       **********      *\n"
                "oooooooo*                       *                                                                                       *\n"
                "oooooooo*                       *                                                                                       *\n"
                "oooooooo**********************************************************************************************************      *\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*      *\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo********\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n"
                "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n";
}

void game::win(){

}
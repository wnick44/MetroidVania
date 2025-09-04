#include <player.h>
#include <SDL2/SDL.h>
#include <chipmunk/chipmunk.h>

void init_player(player_t* player, char* filename,cpSpace space){
    player->frame_width = 64;
    player->frame_height = 64;
}
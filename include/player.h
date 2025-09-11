#include "chipmunk/chipmunk.h"


#define ABILITY_GRAPPLE 1
#define ABILITY_DASH 2
#define ABILITY_PHASE 4

#define FOLDER_STRUCT "assets/sprites/player"

typedef struct {
    int frame_width, frame_height;
    float dx, dy;
    cpBody *playerBody;
    cpShape *playerShape;
    int health;
    int ability;
} player_t;

void init_player(player_t*, char*, cpSpace*);
void free_player(player_t*);

void update_player(player_t*);
void update_animation(float);
void draw_player(player_t*, SDL_Renderer*, camera_t*);
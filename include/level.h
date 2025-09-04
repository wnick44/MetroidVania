#include <transition.h>

typedef struct{
    SDL_Rect rect;
    char* target_level;
    char* target_spawn;
} door_t;

typedef struct{
    tmx_map* tmx_map;
    int tile_w, tile_h;
    int map_w, map_h;
    
    int static_count;
    cpShape** static_shape;

    struct{ char name[64]; float x, y; } spawn;
    int spawn_count;
    door_t door;

} level_t;

void init_level(level_t*);

void load_level(level_t*, const char*);
void switch_level(level_t*, fade_transition_t*);

const char* check_door_collision();
void draw_level(level_t*, SDL_Renderer*, camera_t*);
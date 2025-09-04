#include <level.h>
#include <tmx.h>

#include <camera.h>

tmx_resource_manager* tmx_res;

void init_level(level_t* level){
    level->tile_w = 0;
    level->tile_h = 0;

    level->map_h = 0;
    level->map_w = 0;

    level->static_count = 0;

    tmx_res = tmx_make_resource_manager();
}

void load_level(level_t* level, const char* filename){
    tmx_map* tmx_map = parse_xml(tmx_res, filename);
    
    level->map_h = tmx_map->height;
    level->map_w = tmx_map->width;

    level->tmx_map = tmx_map;

}

void draw_level(level_t* level, SDL_Renderer* renderer, camera_t* camera){

}
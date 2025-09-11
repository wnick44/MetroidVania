#include <transition.h>
#include <string.h>

void fade_init(fade_transition_t* transition){
    transition->phase = FADE_IDLE;
    transition->t = 0.f;
    
    transition->speed = 1.5f;
    
    transition->next_level = "";
    transition->next_spawn = "";
}

void fade_start(fade_transition_t* transition, char* next_level, char* next_spawn){
    transition->phase = FADE_OUT;
    strncpy(transition->next_level, next_level, sizeof(next_level)-1);
    strncpy(transition->next_spawn, next_spawn?next_spawn:"", sizeof() - 1);
}

int fade_update(fade_transition_t* transition, float dt){
    switch(transition->phase){
        case FADE_IN:
            transition->t += dt * transition->speed;
            if(transition->t>=1.f){
                transition->t=1.f;
                
            }
            return 1;
            break;
        case FADE_OUT:
            transition->t -= dt * transition->speed;
            if(transition->t<=0.f){
                transition->t = 0.f;
                transition->phase = FADE_LOADING;
            }
            return 2;
            break;
        case FADE_LOADING:
            transition->phase=FADE_IN;
            transition->t=1.f;
            break;
        default: break;
    }
    return 0;
}

void fade_draw(SDL_Renderer* renderer, fade_transition_t* transition, int , int){

}
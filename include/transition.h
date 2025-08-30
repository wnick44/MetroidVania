typedef enum{
    FADE_IDLE,
    FADE_OUT,
    FADE_IN,
    FADE_LOADING,
    FADE_IN
} fade_phase_e;

typedef struct{
    fade_phase_e phase;
    float t;
    float speed;

    char* next_level;
    char* next_spawn;
} fade_transition_t;

void fade_init(fade_transition_t*);
void fade_start(fade_transition_t*, char*, char*);

int fade_update(fade_transition_t*, float);
void fade_draw(SDL_Renderer, fade_transition_t*, int, int);
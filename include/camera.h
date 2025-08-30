typedef struct{
    float x, y;
    int w, h;
} camera_t;

typedef struct{
    float pos_x, pos_y;
    int w, h;
} camera_target_t;

void camera_init(camera_t*, int, int);

void camera_update(camera_t*, const camera_target_t*, int, int);

void camera_update_smooth(camera_t, const camera_target_t*, int, int, float);
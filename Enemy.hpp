#include "Character.hpp"
#include "SDL.h"

class Enemy: public Character{

    public:
    Enemy(double health_val, double speed_val) : Character(health_val, speed_val) {}
    void movement();
    SDL_Rect * get_sprite();
    bool moving_forward;

    private:
    SDL_Rect sprite{210, 700, 40, 40};
};
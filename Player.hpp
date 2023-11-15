#include <iostream>
#include <SDL.h>
#include "Character.hpp"


class Player : public Character{

    public:

        Player(double health_val, double speed_val, int no_of_frames) : Character(health_val, speed_val, no_of_frames) {}
        void movement(SDL_Event& key_press);
        SDL_Rect * get_sprite();
        bool moving_forward;
        void jump();

    private:

        SDL_Rect sprite{20, 700, 40, 40}; //currently the sprite is just a rectangle, a proper sprite will be added later on

};

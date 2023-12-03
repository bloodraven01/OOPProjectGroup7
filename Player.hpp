#include <iostream>
#include <SDL.h>
#include "Character.hpp"

class Player : public Character{

    public:

        Player(double health_val, double speed_val) : Character(health_val, speed_val) {}
        void movement(SDL_Event& key_press);
        void movementright(int image);
        void movementleft();
        void movementjump();
        SDL_Rect * get_sprite();
        bool moving_forward;
        void jump();

    private:

        SDL_Rect sprite{20, 700, 40, 40}; //currently the sprite is just a rectangle, a proper sprite will be added later on

};

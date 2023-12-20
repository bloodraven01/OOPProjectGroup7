#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <sdl.h>





class Character {

    public:

        Character(double health_val, double speed_val) : health(health_val), speed(speed_val) {}
        virtual void changeframe(SDL_Texture* frame1, SDL_Texture* frame2, SDL_Texture* frame3, SDL_Texture* frame4) = 0;

    protected:

        double health;
        double speed;
};

#endif /* CHARACTER_H */
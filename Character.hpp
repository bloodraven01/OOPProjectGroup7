#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>





class Character {

    public:

        Character(double health_val, double speed_val) : health(health_val), speed(speed_val) {}


    protected:

        double health;
        double speed;
};

#endif /* CHARACTER_H */
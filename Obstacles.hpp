#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <iostream>
#include <SDL.h>

class Obstacles{
    protected:
    SDL_Rect sprite {};

    public:
    
    Obstacles(int x, int y, int w, int h): sprite{x,y,w,h}{}
    Obstacles(const Obstacles& other):sprite{other.sprite}{}
    SDL_Rect get_sprite(){return sprite;}
    void offsetting(int offset);
    virtual bool check_collision(SDL_Rect * player_rect){return 0;}

};

#endif /* OBSTACLES_H */
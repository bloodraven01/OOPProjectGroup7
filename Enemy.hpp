#ifndef ENEMY_H
#define ENEMY_H

#include "Character.hpp"
#include "SDL.h"
#include "AnimationPlayer.hpp"

class Enemy: public AnimationPlayer{

public:
    Enemy(double health_val, double speed_val, int num1, int num2, int x, int y) 
        : AnimationPlayer(health_val, speed_val), max(num1), min(num2), sprite{x,y,60,60} 
    {}
    
    void movement();
    SDL_Rect * get_sprite();
    bool moving_forward;
    Enemy(const Enemy& other):AnimationPlayer(other.health,other.speed),sprite{other.sprite},max(other.max),min(other.min) {} 
    void changeframe(SDL_Texture* frame1, SDL_Texture* frame2, SDL_Texture* frame3, SDL_Texture* frame4);
    void setcurrent(SDL_Texture* frame){currentframe = frame;}
    int getmin(){return min;}
    int getmax(){return max;} 
    void abstract(){std::cout << "Abs";}

private:
    
    int max;
    int min;
    SDL_Rect sprite{};
};

#endif /* ENEMY_H */
#ifndef PLAYER_H
#define PLAYER_H


#include "Enemy.hpp"
#include <iostream>
#include <SDL.h>
#include "Character.hpp"
#include "Obstacles.hpp"
#include <vector>
#include "AnimationPlayer.hpp"

class Player : public AnimationPlayer {
public:
    
    Player(double health_val, double speed_val, bool j = false, bool d = false, bool f = false)
        : AnimationPlayer(health_val, speed_val), jumping(j), isdead(d), falling(f) {}

    void movement(SDL_Event& key_press);
    void movementright(int image, std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes,int offsetX);
    void movementleft(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes,int offsetX);
    void movementjump();
    bool iscolliding(std::vector<Enemy*>& arr,int arrayLength);
    SDL_Rect* get_sprite();
    bool moving_forward;
    bool moving;
    void jump(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes,int offsetX);
    bool isDead();
    void setisDead();
    void setspeed(int val){speed = val;}
    void set_dead_val(bool val);
    void setfalling() { falling = true; }
    bool isjumping() { return jumping; }
    void abstract(){std::cout << "Abs";}
    void setcurrent(SDL_Texture* frame){}
    bool isCollidingWithObstaclesBelow(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes,int offsetX);
    void reset();
    void changeframe(SDL_Texture* frame1, SDL_Texture* frame2, SDL_Texture* frame3, SDL_Texture* frame4);
    Player& operator+=(int jumpIncrement);


private:
    int jumpval;
    bool jumping;
    bool isdead;
    bool falling;
    SDL_Rect sprite{ 20, 500, 60, 60 }; //currently the sprite is just a rectangle, a proper sprite will be added later on
};


#endif /* Player_H */
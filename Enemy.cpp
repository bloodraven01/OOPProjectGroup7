#include "Enemy.hpp"

void Enemy::movement() {

        if  (sprite.x<=300 and moving_forward == true){
            sprite.x += 2;
        }
        else if (sprite.x>=200){
            sprite.x -= 2;
            moving_forward = false;
        }
        else{
            moving_forward = true;
        }
}

SDL_Rect * Enemy::get_sprite() {return &sprite;}

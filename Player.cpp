#include "Player.hpp"
#include <cmath>

bool jumping = false;
int jumpspeed = 0;


void Player::movementright(int image) {

    if (image > 753 && sprite.x < 1100){
        sprite.x += speed;
    }
        moving_forward = true;
}

void Player::movementleft() {
    if(sprite.x > 20){
        sprite.x -= speed;
    }
        moving_forward = false;

}

void Player::movementjump() {
    if (!jumping) {
        jumpspeed = -sqrt(2 * 9 * speed);
        jumping = true;
    }
}   

void Player::jump(){
    if (jumping){
            sprite.y += jumpspeed;
            jumpspeed += 9; 
        if (sprite.y >= 700){
                sprite.y = 700;
                jumping = false;
                jumpspeed = 0;
            }
        }
}

SDL_Rect * Player::get_sprite() {return &sprite;}

bool Player::iscolliding(Enemy obj, int num){
    SDL_Rect* objsprite = obj.get_sprite();
    double objmaxx = objsprite->w + objsprite->x - num ;
    double objmaxy = objsprite->h + objsprite->y;
    double playermaxx = sprite.w+sprite.x;
    double playermaxy = sprite.h+sprite.y;

    if (playermaxx <= objmaxx && playermaxy <= objmaxy){
        if (sprite.x >= objsprite->x - num && sprite.y >= objsprite->y){
            return true;
        }
    }
    return false;


}

#include "Player.hpp"
#include <cmath>

bool jumping = false;
int jumpspeed = 0;


void Player::movementright(int image) {

    if (image > 753){
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

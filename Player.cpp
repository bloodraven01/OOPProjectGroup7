#include "Player.hpp"
#include <cmath>


bool jumping = false;
int jumpspeed = 0;

void Player::movement(SDL_Event& key_press) {

    if (key_press.key.keysym.sym == SDLK_d) {

        sprite.x += speed;
        moving_forward = true;

    }

    else if (key_press.key.keysym.sym == SDLK_a) {

        sprite.x -= speed;
        moving_forward = false;

    }
    else if (key_press.key.keysym.sym == SDLK_w) {

        if (!jumping) {
                    jumpspeed = -sqrt(2 * 9 * speed);
                    jumping = true;
                }
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

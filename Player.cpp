#include "Player.hpp"

void Player::movement(SDL_Event& key_press) {

    if (key_press.key.keysym.sym == SDLK_d) {

        sprite.x += speed;

    }

    else if (key_press.key.keysym.sym == SDLK_a) {

        sprite.x -= speed;

    }


}

SDL_Rect * Player::get_sprite() {return &sprite;}
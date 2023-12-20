#include "Player.hpp"
#include <cmath>

int jumpspeed = 0;



void Player::movementright(int image, std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes, int offsetX) {
    if ((image >= 2400 && sprite.x < 1100)) {
        // Check for collision with obstacles
        bool obstacleCollision = false;

        for (auto& obstacle : obstacles) {
            SDL_Rect obstacleSprite = obstacle.get_sprite();

            if (sprite.x + sprite.w + speed > obstacleSprite.x &&
                sprite.x < obstacleSprite.x + obstacleSprite.w &&
                sprite.y + sprite.h > obstacleSprite.y &&
                sprite.y < obstacleSprite.y + obstacleSprite.h) {
                obstacleCollision = true;
                for (int i = 0; i < spikes.size(); ++i){
                    if(spikes[i]->check_collision(&sprite))setisDead();
                }
                break;
            }
        }

        // Move only if there is no collision with obstacles
        if (!obstacleCollision) {
            sprite.x += speed;
        }

        
    }
    moving = true;
    moving_forward = true;
}

void Player::movementleft(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes, int offsetX) {
    bool obstacleCollision = false;

    if (sprite.x > 20) {
        // Check for collision with obstacles
        for (auto& obstacle : obstacles) {
            SDL_Rect obstacleSprite = obstacle.get_sprite();

            if (sprite.x - speed < obstacleSprite.x + obstacleSprite.w &&
                sprite.x > obstacleSprite.x &&
                sprite.y + sprite.h > obstacleSprite.y &&
                sprite.y < obstacleSprite.y + obstacleSprite.h) {
                obstacleCollision = true;
                for (int i = 0; i < spikes.size(); ++i){
                    if(spikes[i]->check_collision(&sprite))setisDead();
                }
                break;
            }
        }

        // Move only if there is no collision with obstacles
        if (!obstacleCollision) {
            sprite.x -= speed;
        }
    }
    moving = true;
    moving_forward = false;
}

void Player::movementjump() {
    if (!jumping && !falling) {
        jumpspeed = -sqrt(2 * 9 * jumpval);
        jumping = true;
    }
}

void Player::jump(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes, int offsetX) {
    if (jumping || falling) {
        // Check for collision with obstacles above the player
        for (auto& obstacle : obstacles) {
            SDL_Rect obstacleSprite = obstacle.get_sprite();

            if (sprite.x + sprite.w > obstacleSprite.x &&
                sprite.x < obstacleSprite.x + obstacleSprite.w &&
                sprite.y + jumpspeed < obstacleSprite.y + obstacleSprite.h &&
                sprite.y + sprite.h > obstacleSprite.y) {
                // Adjust the player's position to stay below the obstacle
                for (int i = 0; i < spikes.size(); ++i){
                    if(spikes[i]->check_collision(&sprite))setisDead();
                }
                sprite.y = obstacleSprite.y + obstacleSprite.h;
                jumping = false;
                jumpspeed = 0;
                falling = true; // Start falling
                return;
            }
        }

        // Check for collision with obstacles below the player
        for (auto& obstacle : obstacles) {
            SDL_Rect obstacleSprite = obstacle.get_sprite();

            if (sprite.x + sprite.w > obstacleSprite.x &&
                sprite.x < obstacleSprite.x + obstacleSprite.w &&
                sprite.y < obstacleSprite.y &&
                sprite.y + sprite.h + jumpspeed > obstacleSprite.y) {
                // Adjust the player's position to stay above the obstacle
                for (int i = 0; i < spikes.size(); ++i){
                    if(spikes[i]->check_collision(&sprite))setisDead();
                }
                sprite.y = obstacleSprite.y - sprite.h;
                jumping = false;
                jumpspeed = 0;
                falling = false; // Stop falling
                return;
            }
        }

        // Continue jumping or falling
        sprite.y += jumpspeed;
        jumpspeed += 4;

        // If the player goes below the screen, stop falling
        if (sprite.y > 800) {
            sprite.y = 800;
            jumping = false;
            jumpspeed = 0;
            falling = false;
        }
    }
}

SDL_Rect* Player::get_sprite() {
    return &sprite;
}

bool Player::iscolliding(std::vector<Enemy*>& arr, int num) {
    for (auto& enemy : arr) {
        SDL_Rect* objsprite = enemy->get_sprite();

        double objmaxx = objsprite->x + objsprite->w;
        double objmaxy = objsprite->y + objsprite->h;
        double playermaxx = sprite.x + sprite.w + num;
        double playermaxy = sprite.y + sprite.h;

        // Check if there is a collision
        if (playermaxx > objsprite->x && sprite.x + num < objmaxx &&
            playermaxy > objsprite->y && sprite.y < objmaxy) {
            
            // Debugging statements
            std::cout << "Collision detected!" << std::endl;
            std::cout << "Player X: " << sprite.x << ", Player Y: " << sprite.y << std::endl;
            std::cout << "Enemy X: " << objsprite->x << ", Enemy Y: " << objsprite->y << std::endl;

            return true;
        }
    }
    return false;
}

bool Player::isDead() {
    return isdead;
}

void Player::setisDead() {
    isdead = true;
}

bool Player::isCollidingWithObstaclesBelow(std::vector<Obstacles>& obstacles,std::vector<Obstacles*>& spikes, int offsetX) {
    for (auto& obstacle : obstacles) {
        SDL_Rect obstacleSprite = obstacle.get_sprite();

        if (sprite.x + sprite.w > obstacleSprite.x &&
            sprite.x < obstacleSprite.x + obstacleSprite.w &&
            sprite.y + sprite.h + speed > obstacleSprite.y &&
            sprite.y < obstacleSprite.y + obstacleSprite.h) {
            // Adjust the player's position to stay on top of the obstacle
            for (int i = 0; i < spikes.size(); ++i){
                if(spikes[i]->check_collision(&sprite))setisDead();
            }
                        
            sprite.y = obstacleSprite.y - sprite.h;
            falling = false;  // Set falling to false when the player lands on an obstacle
            return true;
        }
    }

    // If no collision with obstacles below, set falling to true
    falling = true;
    return false;
}

void Player::reset(){
    sprite = { 20, 500, 60, 60 };
}



void Player::changeframe(SDL_Texture* frame1, SDL_Texture* frame2, SDL_Texture* frame3, SDL_Texture* frame4){
    if (moving){
        if (moving_forward) {
            
            if (currentframe == frame1) {
        
                currentframe = frame2;
                
            }

            else {
                
                currentframe = frame1;
            
            }
        }

        else {

            if (currentframe == frame3) {
        
                currentframe = frame4;
                
            }

            else {
                
                currentframe = frame3;
            
            }


        }
    }
    
}


void Player::set_dead_val(bool val) {

    isdead = val;
}

Player& Player::operator+=(int jumpIncrement) {
    
    jumpval = jumpIncrement;
    return *this;
}
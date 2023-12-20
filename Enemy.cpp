#include "Enemy.hpp"

void Enemy::movement() {

        if  (sprite.x<=max and moving_forward == true){
            sprite.x += speed;
        }
        else if (sprite.x>=min){
            sprite.x -= speed;
            moving_forward = false;
        }
        else{
            moving_forward = true;
        }
}

SDL_Rect * Enemy::get_sprite() {return &sprite;}

void Enemy::changeframe(SDL_Texture* frame1, SDL_Texture* frame2, SDL_Texture* frame3, SDL_Texture* frame4){
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
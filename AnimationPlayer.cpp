#include "AnimationPlayer.hpp"

bool operator == (SDL_Rect frame1, SDL_Rect frame2) {

    if (frame1.h == frame2.w && frame1.w == frame2.w && frame1.x == frame2.x && frame1.y == frame2.y) {

        return true;
    }

    return false;
}

void AnimationPlayer::play() {

    
    
}
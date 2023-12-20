#include "Spike.hpp"


bool Spike::check_collision(SDL_Rect * player_rect) {

    SDL_Rect result;
    SDL_Rect spike_rect = Obstacles::sprite;


    return SDL_IntersectRect(player_rect, &spike_rect, &result);

}
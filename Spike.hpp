#include "Obstacles.hpp"


class Spike : public Obstacles {


    public:

        Spike(int x, int y, int h, int w) : Obstacles(x , y, w, h) {}

        bool check_collision(SDL_Rect * player_rect);


};
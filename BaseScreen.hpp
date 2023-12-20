#ifndef BASESCREEN_H
#define BASESCREEN_H

#include <iostream>
#include <SDL.h>
#include <vector>
#include "Player.hpp"
#include "Level.hpp"

class BaseScreen {

public:
    bool virtual display(SDL_Renderer * rend, SDL_Texture * background, bool& running, SDL_Event& e, SDL_Texture ** tex_arr,std::vector<bool> & lock_arr ,Level & level, Player & player ) = 0;
};

#endif /* BASESCREEN_H */
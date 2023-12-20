#include "BaseScreen.hpp"
#include <iostream>

class Screen : public BaseScreen {


    public:

        bool display(SDL_Renderer * rend, SDL_Texture * background, bool& running, SDL_Event& e,SDL_Texture ** tex_arr, std::vector<bool> & lock_arr, Level & level, Player & player);



};
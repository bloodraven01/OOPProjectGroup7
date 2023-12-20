#include <iostream>
#include <fstream>
#include <vector>

class SaveFile {

    public:

        void save_game(std::vector<bool>& lock_arr);
        void load_save(std::vector<bool>& lock_arr);


    private:

        std::fstream file;




};

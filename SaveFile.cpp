#include "SaveFile.hpp"
#include <vector>


void SaveFile::save_game(std::vector<bool>& lock_array) {

    file.open("save_file.txt");
    
    for (int x = 0; x < 10; x++) {

        file << lock_array[x] << ' ';
    }

    file.close();


}

void SaveFile::load_save(std::vector<bool>& lock_array) {
    file.open("save_file.txt");

    char value;
    for (int x = 0; x < 10; x++) {
        file >> value;
        lock_array[x] = (value == '1'); // Convert char to bool
    }

    file.close();
}
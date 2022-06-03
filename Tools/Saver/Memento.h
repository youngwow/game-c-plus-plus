#pragma once
#include <utility>
#include "../Field.h"
#include <fstream>
//#include "../Game.h"

class Memento{
private:
    Field* state_;
    std::string filename_;
    int hash_;
public:
    Memento(Field* state, std::string filename, bool flag = true);
    Field* getState();
    void save_file();
    void load_file();
    void hash();
    int back_hash();
};


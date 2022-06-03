#pragma once
#include <utility>
#include "Memento.h"


class Originator{
private:
    Field* state_;
public:
    Originator(Field* state);
    Memento* save(std::string filename, bool flag = true);
    void restore(Memento* memento);
    Field* getField();
};





#pragma once
#include <utility>

#include "Memento.h"
#include "Originator.h"

class Caretaker{
private:
    Originator *originator_;
    std::vector<Memento*> history_;
public:
    Caretaker(Originator *originator);
    void Backup(std::string filename, bool flag = true);
    void Undo();
};


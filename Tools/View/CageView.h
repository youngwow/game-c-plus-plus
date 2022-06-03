#pragma once
#include "../Cage.h"

class CageView{
private:
    Cage& cell;
public:
    explicit CageView(Cage& obj);
    void printCage() const;
    void printObj() const;
};
#pragma once
#include "Interaction_elements.h"

class Armor: public Interaction_elements{
private:
    int armor;
public:
    Armor();
    explicit Armor(int number);
    void setState(int number) final;
    int getState() final;
};
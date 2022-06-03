#pragma once
#include "Interaction_elements.h"

class Health: public Interaction_elements{
private:
    int health;
public:
    Health();
    explicit Health(int number);
    void setState(int number) final;
    int getState() final;
};
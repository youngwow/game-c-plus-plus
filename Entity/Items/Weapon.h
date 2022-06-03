#pragma once
#include "Interaction_elements.h"
// Должен прибавлять главному герою +20 урона, +40 урона, +100 урона
// патронов бесконечное кол-во

class Weapon: public Interaction_elements{
private:
    int damage;
public:
    Weapon();
    explicit Weapon(int number);
    void setState(int number) final;
    int getState() final;

};
#include "Armor.h"

Armor::Armor() {
    this->armor = 0;
}

Armor::Armor(int number) {
    this->armor = number;
}

void Armor::setState(int number) {
    this->armor = number;
}

int Armor::getState() {
    return this->armor;
}
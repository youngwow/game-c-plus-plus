#include "Weapon.h"

Weapon::Weapon() {
    this->damage = 5;
}

Weapon::Weapon(int number) {
    this->damage = number;
}

void Weapon::setState(int number) {
    this->damage = number;
}

int Weapon::getState() {
    return this->damage;
}
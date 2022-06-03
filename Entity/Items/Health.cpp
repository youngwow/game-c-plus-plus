#include "Health.h"

Health::Health() {
    this->health = 50;
}

Health::Health(int number) {
    this->health = number;
}

void Health::setState(int number) {
    this->health = number;
}

int Health::getState() {
    return this->health;
}
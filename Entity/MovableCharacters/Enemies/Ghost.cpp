#include "Ghost.h"

Ghost::Ghost() {
    this->health = 25;
    this->damage = 10;
}

Ghost::Ghost(int h, int d) {
    this->health = h;
    this->damage = d;
}

void Ghost::setDamage(int number) {
    this->damage = number;
}

void Ghost::setHealth(int number) {
    this->health = number;
}

int Ghost::getDamage() const {
    return this->damage;

}

int Ghost::getHealth() const {
    return this->health;
}

bool Ghost::isAlive() {
    if (this->health > 0){
        return true;
    } else{
        return false;
    }
}

void Ghost::plusHealth(int number) {
    this->health += number;
}

void Ghost::fight(MovableEntity *character) {
    character->plusHealth(-(this->getDamage()));
}

//std::ostream& operator<<(std::ostream& out, const Ghost& ghost) {
//    out << "\nGhost info: \nHealth: " << ghost.getHealth() << "\nDamage: " << ghost.getDamage() << "\n";
//    return out;
//}
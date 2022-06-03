#include "Zombie.h"

Zombie::Zombie() {
    this->health = 15;
    this->damage = 5;
}

Zombie::Zombie(int h, int d) {
    this->health = h;
    this->damage = d;
}

void Zombie::setHealth(int number) {
    this->health = number;
}

void Zombie::setDamage(int number) {
    this->damage = number;
}

int Zombie::getHealth() const {
    return this->health;
}

int Zombie::getDamage() const {
    return this->damage;
}

bool Zombie::isAlive() {
    if (this->health > 0){
        return true;
    } else{
        return false;
    }
}

void Zombie::plusHealth(int number) {
    this->health += number;
}

void Zombie::fight(MovableEntity *character) {
    character->plusHealth(-(this->getDamage()));
}
//
//std::ostream& operator<<(std::ostream& out, const Zombie& zombie) {
//    out << "\nZombie info: \nHealth: " << zombie.getHealth() << "\nDamage: " << zombie.getDamage() << "\n";
//    return out;
//}

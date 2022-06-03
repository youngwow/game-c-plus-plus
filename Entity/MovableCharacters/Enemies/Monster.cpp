#include "Monster.h"

Monster::Monster() {
    this->health = 35;
    this->damage = 50;
}

Monster::Monster(int h, int d) {
    this->health = h;
    this->damage = d;
}

void Monster::setDamage(int number) {
    this->damage = number;
}

void Monster::setHealth(int number) {
    this->health = number;
}

int Monster::getDamage() const {
    return this->damage;
}

int Monster::getHealth() const {
    return this->health;
}

bool Monster::isAlive() {
    if (this->health > 0){
        return true;
    } else{
        return false;
    }
}

void Monster::plusHealth(int number) {
    this->health += number;
}

void Monster::fight(MovableEntity *character) {
    character->plusHealth(-(this->getDamage()));
}

//std::ostream& operator<<(std::ostream& out, const Monster& monster) {
//    out << "\nMonster info: \nHealth: " << monster.getHealth() << "\nDamage: " << monster.getDamage() << "\n";
//    return out;
//}

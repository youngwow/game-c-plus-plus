#include "MainCharacter.h"

MainCharacter::MainCharacter() {
    this->health = 100;
    this->armor = 0;
    this->power = 10;
}

MainCharacter::~MainCharacter() = default;  // поменять потом

void MainCharacter::TakeItem(CageEntity* item) {  // Cage *item
    if (item){
        auto t = typeid(*item).name();  // typeid(*item).name()
        if (typeid(*item).name() == typeid(Weapon).name()){
            // auto& t = dynamic_cast<Weapon&>(*item->entity);
            // std::cout << (dynamic_cast<Weapon&>(*(item->entity))).getState() << "\n";
            this->power = (dynamic_cast<Weapon&>(*item)).getState();
        } else if (typeid(*item).name() == typeid(Health).name()){
            this->health += (dynamic_cast<Health&>(*item)).getState();
        } else if (typeid(*item).name() == typeid(Armor).name()){
            this->armor += (dynamic_cast<Armor&>(*item)).getState();
        }
    }
}

void MainCharacter::setArmor(int number) {
    this->armor = number;
}

int MainCharacter::getArmor() const {
    return this->armor;
}

void MainCharacter::setHealth(int number) {
    this->health = number;
}

int MainCharacter::getHealth() const {
    return this->health;
}

void MainCharacter::setPower(int number) {
    this->power = number;
}

int MainCharacter::getPower() const {
    return this->power;
}

bool MainCharacter::isAlive() {
    if (this->health > 0){
        return true;
    } else{
        return false;
    }
}

void MainCharacter::fight(MovableEntity *character) {
    character->plusHealth(-(this->getPower()));
}

void MainCharacter::plusHealth(int number) {
//    this->health += number;
    int broken_shields = 0;
    if (this->armor > 0){
        broken_shields = this->armor + number;
        this->armor += number;
        if (this->armor < 0){
            this->armor = 0;
            this->health += broken_shields;
        }
    } else{
        this->health += number;
    }
}

std::ostream& operator<<(std::ostream& out, const MainCharacter& MainHero) {
    std::string text = "\nPlayer info: \nHealth: " + std::to_string(MainHero.getHealth()) + "\nDamage: " + std::to_string(MainHero.getPower()) + "\nArmor: " + std::to_string(MainHero.getArmor()) + '\n';
    out << text;
    return out;
}
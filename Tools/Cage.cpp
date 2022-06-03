#include "Cage.h"
#include <iostream>

Cage::Cage() {
    this->x = 0;
    this->y = 0;
    this->typeObj = TypeObj::NOTHING;
    this->typeCage = TypeCage::EMPTY;
    this->entity = nullptr;
}

Cage::Cage(int x, int y) {
    this->x = x; // !!
    this->y = y; // !!
    this->typeObj = TypeObj::NOTHING;
    this->typeCage = TypeCage::EMPTY;
    this->entity = nullptr;
}

Cage::~Cage() = default;

void Cage::setTypeCage(TypeCage typeCage) {
    this->typeCage = typeCage;
}

void Cage::setTypeObj(TypeObj typeObj) {
    this->typeObj = typeObj;
}

void Cage::setEntity(CageEntity *value) {
    //this->entity = value;
    if (value){
        auto t = typeid(*value).name();
        if (t == typeid(Weapon).name() or t == typeid(Health).name() or t == typeid(Armor).name()){
            this->typeObj = TypeObj::NOTHING;  // INTERACTION_ELEMENTS
            this->typeCage = TypeCage::PASSABLE;
        } else if (t == typeid(Zombie).name() or t == typeid(Ghost).name() or t == typeid(Monster).name()){
            this->typeObj = TypeObj::NOTHING;  // ENEMY!!!
            this->typeCage = TypeCage::PASSABLE;
        }
//        this->entity = value;
    }
    this->entity = value;
}

TypeCage Cage::getTypeCage() const{  // prev: int
    return static_cast<TypeCage>(this->typeCage);  // prev: this->typeCage
}

TypeObj Cage::getTypeObj() const {  // prev: int
    return static_cast<TypeObj>(this->typeObj);  // prev: this->typeObj
}

int Cage::getX() const {
    return this->x;
}

int Cage::getY() const {
    return this->y;
}

CageEntity *Cage::getEntity() const {
    return this->entity;
}
#pragma once
#include <iostream>
#include "../Entity/CageEntity.h"
#include "../Entity/Items/Weapon.h"
#include "../Entity/Items/Armor.h"
#include "../Entity/Items/Health.h"
#include "../Entity/MovableCharacters/Enemies/Zombie.h"
#include "../Entity/MovableCharacters/Enemies/Ghost.h"
#include "../Entity/MovableCharacters/Enemies/Monster.h"
#include "../Entity/MovableCharacters/MainCharacter.h"

enum TypeObj{
    NOTHING = 0,
    PLAYER = 1,
    ENEMY = 2,
    INTERACTION_ELEMENTS = 3
};

enum TypeCage{
    START,
    END,
    PASSABLE,
    IMPASSABLE,
    EMPTY
};

enum TypeItems{
    WEAPON,
    HEALTH,
    ARMOR
};

enum TypeEnemy{
    Zombies,
    Ghosts,
    Monsters
};

class Cage{
private:
    int typeCage;
    int typeObj;
    int x, y;
//    CageEntity* entity;
public:
    CageEntity* entity;
    friend class CageView;
//    friend class Field;
    Cage();               // prev: Cage(): x(0), y(0) {}
    Cage(int x, int y);  // prev: Cage(int x, int y): x(x), y(y) {}
    ~Cage();
    void setTypeCage(TypeCage typeCage = TypeCage::EMPTY);
    void setTypeObj(TypeObj typeObj = TypeObj::NOTHING);
    void setEntity(CageEntity* value);
    [[nodiscard]] CageEntity* getEntity() const;
    [[nodiscard]] TypeCage getTypeCage() const;
    [[nodiscard]] TypeObj getTypeObj() const;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    // перегрузить оператор +
    // перегрузить оператор -
};
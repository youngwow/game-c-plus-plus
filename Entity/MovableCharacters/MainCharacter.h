#pragma once
#include "MovableEntity.h"
#include "../../Tools/Cage.h"
#include "../Items/Weapon.h"
#include "../Items/Health.h"
#include "../Items/Armor.h"


class MainCharacter: public MovableEntity{
private:
    int health;
    int armor;
    int power;
public:
    MainCharacter();
    ~MainCharacter() override;  // ?
    void TakeItem(CageEntity* item);
    void setArmor(int number);
    [[nodiscard]] int getArmor() const;
    void setHealth(int number);
    [[nodiscard]] int getHealth() const;
    void setPower(int number);
    [[nodiscard]] int getPower() const;
    void fight(MovableEntity* character) final;
    void plusHealth(int number) final;
    bool isAlive() final;
    friend std::ostream& operator<<(std::ostream& out, const MainCharacter& MainHero);
};